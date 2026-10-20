/*
 * api_error_v1.h
 *
 * 
 */

#ifndef _api_error_v1_H_
#define _api_error_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct api_error_v1_t api_error_v1_t;




typedef struct api_error_v1_t {
    char *error; // string
    char *error_id; // string
    char *original_error; // string

    int _library_owned; // Is the library responsible for freeing this object?
} api_error_v1_t;

__attribute__((deprecated)) api_error_v1_t *api_error_v1_create(
    char *error,
    char *error_id,
    char *original_error
);

void api_error_v1_free(api_error_v1_t *api_error_v1);

api_error_v1_t *api_error_v1_parseFromJSON(cJSON *api_error_v1JSON);

cJSON *api_error_v1_convertToJSON(api_error_v1_t *api_error_v1);

#endif /* _api_error_v1_H_ */

