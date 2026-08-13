/*
 * api_not_found_error_v1.h
 *
 * 
 */

#ifndef _api_not_found_error_v1_H_
#define _api_not_found_error_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct api_not_found_error_v1_t api_not_found_error_v1_t;

#include "any_type.h"
#include "object.h"



typedef struct api_not_found_error_v1_t {
    char *error; // string
    char *error_id; // string
    char *name; // string
    object_t *params; //object

    int _library_owned; // Is the library responsible for freeing this object?
} api_not_found_error_v1_t;

__attribute__((deprecated)) api_not_found_error_v1_t *api_not_found_error_v1_create(
    char *error,
    char *error_id,
    char *name,
    object_t *params
);

void api_not_found_error_v1_free(api_not_found_error_v1_t *api_not_found_error_v1);

api_not_found_error_v1_t *api_not_found_error_v1_parseFromJSON(cJSON *api_not_found_error_v1JSON);

cJSON *api_not_found_error_v1_convertToJSON(api_not_found_error_v1_t *api_not_found_error_v1);

#endif /* _api_not_found_error_v1_H_ */

