/*
 * matrix_error.h
 *
 * 
 */

#ifndef _matrix_error_H_
#define _matrix_error_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct matrix_error_t matrix_error_t;




typedef struct matrix_error_t {
    char *error; // string

    int _library_owned; // Is the library responsible for freeing this object?
} matrix_error_t;

__attribute__((deprecated)) matrix_error_t *matrix_error_create(
    char *error
);

void matrix_error_free(matrix_error_t *matrix_error);

matrix_error_t *matrix_error_parseFromJSON(cJSON *matrix_errorJSON);

cJSON *matrix_error_convertToJSON(matrix_error_t *matrix_error);

#endif /* _matrix_error_H_ */

