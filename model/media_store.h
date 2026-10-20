/*
 * media_store.h
 *
 * 
 */

#ifndef _media_store_H_
#define _media_store_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct media_store_t media_store_t;


// Enum MOUNTPOLICY for media_store

typedef enum  { corellium_api_media_store_MOUNTPOLICY_NULL = 0, corellium_api_media_store_MOUNTPOLICY_RO, corellium_api_media_store_MOUNTPOLICY_RW } corellium_api_media_store_MOUNTPOLICY_e;

char* media_store_mount_policy_ToString(corellium_api_media_store_MOUNTPOLICY_e mount_policy);

corellium_api_media_store_MOUNTPOLICY_e media_store_mount_policy_FromString(char* mount_policy);

// Enum STATUS for media_store

typedef enum  { corellium_api_media_store_STATUS_NULL = 0, corellium_api_media_store_STATUS_mounted, corellium_api_media_store_STATUS_unmounted } corellium_api_media_store_STATUS_e;

char* media_store_status_ToString(corellium_api_media_store_STATUS_e status);

corellium_api_media_store_STATUS_e media_store_status_FromString(char* status);



typedef struct media_store_t {
    char *identifier; // string
    char *device; // string
    char *fs_type; // string
    char *fs_uuid; // string
    char *label; // string
    char *serial; // string
    char *vendor; // string
    char *model; // string
    corellium_api_media_store_MOUNTPOLICY_e mount_policy; //enum
    corellium_api_media_store_STATUS_e status; //enum
    char *created_at; //date time
    char *updated_at; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} media_store_t;

__attribute__((deprecated)) media_store_t *media_store_create(
    char *identifier,
    char *device,
    char *fs_type,
    char *fs_uuid,
    char *label,
    char *serial,
    char *vendor,
    char *model,
    corellium_api_media_store_MOUNTPOLICY_e mount_policy,
    corellium_api_media_store_STATUS_e status,
    char *created_at,
    char *updated_at
);

void media_store_free(media_store_t *media_store);

media_store_t *media_store_parseFromJSON(cJSON *media_storeJSON);

cJSON *media_store_convertToJSON(media_store_t *media_store);

#endif /* _media_store_H_ */

