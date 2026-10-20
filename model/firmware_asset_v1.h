/*
 * firmware_asset_v1.h
 *
 * 
 */

#ifndef _firmware_asset_v1_H_
#define _firmware_asset_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct firmware_asset_v1_t firmware_asset_v1_t;




typedef struct firmware_asset_v1_t {
    char *domain; // string
    char *url; // string
    char *payload; // string
    double size; //numeric
    char *md5sum; // string
    char *sha1sum; // string
    char *sha256sum; // string
    char *uploaddate; // string
    char *created_at; // string
    char *updated_at; // string

    int _library_owned; // Is the library responsible for freeing this object?
} firmware_asset_v1_t;

__attribute__((deprecated)) firmware_asset_v1_t *firmware_asset_v1_create(
    char *domain,
    char *url,
    char *payload,
    double size,
    char *md5sum,
    char *sha1sum,
    char *sha256sum,
    char *uploaddate,
    char *created_at,
    char *updated_at
);

void firmware_asset_v1_free(firmware_asset_v1_t *firmware_asset_v1);

firmware_asset_v1_t *firmware_asset_v1_parseFromJSON(cJSON *firmware_asset_v1JSON);

cJSON *firmware_asset_v1_convertToJSON(firmware_asset_v1_t *firmware_asset_v1);

#endif /* _firmware_asset_v1_H_ */

