/*
 * storage_eject_already_unmounted_response.h
 *
 * 
 */

#ifndef _storage_eject_already_unmounted_response_H_
#define _storage_eject_already_unmounted_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct storage_eject_already_unmounted_response_t storage_eject_already_unmounted_response_t;




typedef struct storage_eject_already_unmounted_response_t {
    char *message; // string

    int _library_owned; // Is the library responsible for freeing this object?
} storage_eject_already_unmounted_response_t;

__attribute__((deprecated)) storage_eject_already_unmounted_response_t *storage_eject_already_unmounted_response_create(
    char *message
);

void storage_eject_already_unmounted_response_free(storage_eject_already_unmounted_response_t *storage_eject_already_unmounted_response);

storage_eject_already_unmounted_response_t *storage_eject_already_unmounted_response_parseFromJSON(cJSON *storage_eject_already_unmounted_responseJSON);

cJSON *storage_eject_already_unmounted_response_convertToJSON(storage_eject_already_unmounted_response_t *storage_eject_already_unmounted_response);

#endif /* _storage_eject_already_unmounted_response_H_ */

