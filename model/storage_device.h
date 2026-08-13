/*
 * storage_device.h
 *
 * 
 */

#ifndef _storage_device_H_
#define _storage_device_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct storage_device_t storage_device_t;


// Enum MOUNTPOLICY for storage_device

typedef enum  { corellium_api_storage_device_MOUNTPOLICY_NULL = 0, corellium_api_storage_device_MOUNTPOLICY_RO, corellium_api_storage_device_MOUNTPOLICY_RW } corellium_api_storage_device_MOUNTPOLICY_e;

char* storage_device_mount_policy_ToString(corellium_api_storage_device_MOUNTPOLICY_e mount_policy);

corellium_api_storage_device_MOUNTPOLICY_e storage_device_mount_policy_FromString(char* mount_policy);

// Enum STATUS for storage_device

typedef enum  { corellium_api_storage_device_STATUS_NULL = 0, corellium_api_storage_device_STATUS_mounted, corellium_api_storage_device_STATUS_unmounted } corellium_api_storage_device_STATUS_e;

char* storage_device_status_ToString(corellium_api_storage_device_STATUS_e status);

corellium_api_storage_device_STATUS_e storage_device_status_FromString(char* status);



typedef struct storage_device_t {
    char *id; // string
    char *device; // string
    char *fs_type; // string
    char *fs_uuid; // string
    char *label; // string
    char *serial; // string
    char *vendor; // string
    char *model; // string
    corellium_api_storage_device_MOUNTPOLICY_e mount_policy; //enum
    corellium_api_storage_device_STATUS_e status; //enum
    char *created_at; //date time
    char *updated_at; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} storage_device_t;

__attribute__((deprecated)) storage_device_t *storage_device_create(
    char *id,
    char *device,
    char *fs_type,
    char *fs_uuid,
    char *label,
    char *serial,
    char *vendor,
    char *model,
    corellium_api_storage_device_MOUNTPOLICY_e mount_policy,
    corellium_api_storage_device_STATUS_e status,
    char *created_at,
    char *updated_at
);

void storage_device_free(storage_device_t *storage_device);

storage_device_t *storage_device_parseFromJSON(cJSON *storage_deviceJSON);

cJSON *storage_device_convertToJSON(storage_device_t *storage_device);

#endif /* _storage_device_H_ */

