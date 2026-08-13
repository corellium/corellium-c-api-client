/*
 * firmware_asset.h
 *
 * 
 */

#ifndef _firmware_asset_H_
#define _firmware_asset_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct firmware_asset_t firmware_asset_t;




typedef struct firmware_asset_t {
    char *domain; // string
    char *url; // string
    char *payload; // string
    double size; //numeric
    char *md5sum; // string
    char *sha1sum; // string
    char *sha256sum; // string
    char *upload_date; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} firmware_asset_t;

__attribute__((deprecated)) firmware_asset_t *firmware_asset_create(
    char *domain,
    char *url,
    char *payload,
    double size,
    char *md5sum,
    char *sha1sum,
    char *sha256sum,
    char *upload_date
);

void firmware_asset_free(firmware_asset_t *firmware_asset);

firmware_asset_t *firmware_asset_parseFromJSON(cJSON *firmware_assetJSON);

cJSON *firmware_asset_convertToJSON(firmware_asset_t *firmware_asset);

#endif /* _firmware_asset_H_ */

