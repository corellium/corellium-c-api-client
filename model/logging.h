/*
 * logging.h
 *
 * Info for logging.
 */

#ifndef _logging_H_
#define _logging_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct logging_t logging_t;




typedef struct logging_t {
    int development; //boolean
    int throw_warnings; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} logging_t;

__attribute__((deprecated)) logging_t *logging_create(
    int development,
    int throw_warnings
);

void logging_free(logging_t *logging);

logging_t *logging_parseFromJSON(cJSON *loggingJSON);

cJSON *logging_convertToJSON(logging_t *logging);

#endif /* _logging_H_ */

