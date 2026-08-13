/*
 * storage_attach_response.h
 *
 * 
 */

#ifndef _storage_attach_response_H_
#define _storage_attach_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct storage_attach_response_t storage_attach_response_t;




typedef struct storage_attach_response_t {
    char *status; // string
    char *message; // string
    char *id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} storage_attach_response_t;

__attribute__((deprecated)) storage_attach_response_t *storage_attach_response_create(
    char *status,
    char *message,
    char *id
);

void storage_attach_response_free(storage_attach_response_t *storage_attach_response);

storage_attach_response_t *storage_attach_response_parseFromJSON(cJSON *storage_attach_responseJSON);

cJSON *storage_attach_response_convertToJSON(storage_attach_response_t *storage_attach_response);

#endif /* _storage_attach_response_H_ */

