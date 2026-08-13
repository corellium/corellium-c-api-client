/*
 * get_interconnects_response.h
 *
 * 
 */

#ifndef _get_interconnects_response_H_
#define _get_interconnects_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_interconnects_response_t get_interconnects_response_t;

#include "interconnect_response.h"



typedef struct get_interconnects_response_t {
    list_t *results; //nonprimitive container
    double count; //numeric
    double total; //numeric
    double limit; //numeric
    double offset; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} get_interconnects_response_t;

__attribute__((deprecated)) get_interconnects_response_t *get_interconnects_response_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset
);

void get_interconnects_response_free(get_interconnects_response_t *get_interconnects_response);

get_interconnects_response_t *get_interconnects_response_parseFromJSON(cJSON *get_interconnects_responseJSON);

cJSON *get_interconnects_response_convertToJSON(get_interconnects_response_t *get_interconnects_response);

#endif /* _get_interconnects_response_H_ */

