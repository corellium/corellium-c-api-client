/*
 * storage_queue_error.h
 *
 * 
 */

#ifndef _storage_queue_error_H_
#define _storage_queue_error_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct storage_queue_error_t storage_queue_error_t;




typedef struct storage_queue_error_t {
    char *error; // string
    char *details; // string
    char *suggestion; // string

    int _library_owned; // Is the library responsible for freeing this object?
} storage_queue_error_t;

__attribute__((deprecated)) storage_queue_error_t *storage_queue_error_create(
    char *error,
    char *details,
    char *suggestion
);

void storage_queue_error_free(storage_queue_error_t *storage_queue_error);

storage_queue_error_t *storage_queue_error_parseFromJSON(cJSON *storage_queue_errorJSON);

cJSON *storage_queue_error_convertToJSON(storage_queue_error_t *storage_queue_error);

#endif /* _storage_queue_error_H_ */

