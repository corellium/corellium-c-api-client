/*
 * storage_already_mounted_response.h
 *
 * 
 */

#ifndef _storage_already_mounted_response_H_
#define _storage_already_mounted_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct storage_already_mounted_response_t storage_already_mounted_response_t;




typedef struct storage_already_mounted_response_t {
    char *message; // string
    char *mount_point; // string
    char *device; // string

    int _library_owned; // Is the library responsible for freeing this object?
} storage_already_mounted_response_t;

__attribute__((deprecated)) storage_already_mounted_response_t *storage_already_mounted_response_create(
    char *message,
    char *mount_point,
    char *device
);

void storage_already_mounted_response_free(storage_already_mounted_response_t *storage_already_mounted_response);

storage_already_mounted_response_t *storage_already_mounted_response_parseFromJSON(cJSON *storage_already_mounted_responseJSON);

cJSON *storage_already_mounted_response_convertToJSON(storage_already_mounted_response_t *storage_already_mounted_response);

#endif /* _storage_already_mounted_response_H_ */

