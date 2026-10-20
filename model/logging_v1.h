/*
 * logging_v1.h
 *
 * 
 */

#ifndef _logging_v1_H_
#define _logging_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct logging_v1_t logging_v1_t;




typedef struct logging_v1_t {
    int development; //boolean
    int throw_warnings; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} logging_v1_t;

__attribute__((deprecated)) logging_v1_t *logging_v1_create(
    int development,
    int throw_warnings
);

void logging_v1_free(logging_v1_t *logging_v1);

logging_v1_t *logging_v1_parseFromJSON(cJSON *logging_v1JSON);

cJSON *logging_v1_convertToJSON(logging_v1_t *logging_v1);

#endif /* _logging_v1_H_ */

