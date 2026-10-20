/*
 * invite_result_error.h
 *
 * Error detail, when the invite failed.
 */

#ifndef _invite_result_error_H_
#define _invite_result_error_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct invite_result_error_t invite_result_error_t;




typedef struct invite_result_error_t {
    char *error; // string

    int _library_owned; // Is the library responsible for freeing this object?
} invite_result_error_t;

__attribute__((deprecated)) invite_result_error_t *invite_result_error_create(
    char *error
);

void invite_result_error_free(invite_result_error_t *invite_result_error);

invite_result_error_t *invite_result_error_parseFromJSON(cJSON *invite_result_errorJSON);

cJSON *invite_result_error_convertToJSON(invite_result_error_t *invite_result_error);

#endif /* _invite_result_error_H_ */

