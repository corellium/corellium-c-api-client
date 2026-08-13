/*
 * media_store_v1.h
 *
 * 
 */

#ifndef _media_store_v1_H_
#define _media_store_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct media_store_v1_t media_store_v1_t;




typedef struct media_store_v1_t {
    char *identifier; // string
    char *device; // string
    char *fs_type; // string
    char *fs_uuid; // string
    char *label; // string
    char *serial; // string
    char *vendor; // string
    char *model; // string
    char *mount_policy; // string
    char *created_at; // string
    char *updated_at; // string

    int _library_owned; // Is the library responsible for freeing this object?
} media_store_v1_t;

__attribute__((deprecated)) media_store_v1_t *media_store_v1_create(
    char *identifier,
    char *device,
    char *fs_type,
    char *fs_uuid,
    char *label,
    char *serial,
    char *vendor,
    char *model,
    char *mount_policy,
    char *created_at,
    char *updated_at
);

void media_store_v1_free(media_store_v1_t *media_store_v1);

media_store_v1_t *media_store_v1_parseFromJSON(cJSON *media_store_v1JSON);

cJSON *media_store_v1_convertToJSON(media_store_v1_t *media_store_v1);

#endif /* _media_store_v1_H_ */

