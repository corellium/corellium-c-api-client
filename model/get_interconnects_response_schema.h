/*
 * get_interconnects_response_schema.h
 *
 * 
 */

#ifndef _get_interconnects_response_schema_H_
#define _get_interconnects_response_schema_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_interconnects_response_schema_t get_interconnects_response_schema_t;

#include "get_interconnect_response_schema.h"



typedef struct get_interconnects_response_schema_t {
    list_t *results; //nonprimitive container
    double count; //numeric
    double total; //numeric
    double limit; //numeric
    double offset; //numeric
    int has_more; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} get_interconnects_response_schema_t;

__attribute__((deprecated)) get_interconnects_response_schema_t *get_interconnects_response_schema_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
);

void get_interconnects_response_schema_free(get_interconnects_response_schema_t *get_interconnects_response_schema);

get_interconnects_response_schema_t *get_interconnects_response_schema_parseFromJSON(cJSON *get_interconnects_response_schemaJSON);

cJSON *get_interconnects_response_schema_convertToJSON(get_interconnects_response_schema_t *get_interconnects_response_schema);

#endif /* _get_interconnects_response_schema_H_ */

