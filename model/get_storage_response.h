/*
 * get_storage_response.h
 *
 * 
 */

#ifndef _get_storage_response_H_
#define _get_storage_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_storage_response_t get_storage_response_t;

#include "media_store_v1.h"



typedef struct get_storage_response_t {
    list_t *results; //nonprimitive container
    double count; //numeric
    double total; //numeric
    double limit; //numeric
    double offset; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} get_storage_response_t;

__attribute__((deprecated)) get_storage_response_t *get_storage_response_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset
);

void get_storage_response_free(get_storage_response_t *get_storage_response);

get_storage_response_t *get_storage_response_parseFromJSON(cJSON *get_storage_responseJSON);

cJSON *get_storage_response_convertToJSON(get_storage_response_t *get_storage_response);

#endif /* _get_storage_response_H_ */

