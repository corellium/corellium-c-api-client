/*
 * firmware.h
 *
 * 
 */

#ifndef _firmware_H_
#define _firmware_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct firmware_t firmware_t;

#include "any_type.h"
#include "object.h"



typedef struct firmware_t {
    list_t *model; //primitive container
    list_t *firmware_assets; //primitive container
    char *filename; // string
    char *type; // string
    double size; //numeric
    char *url; // string
    char *version; // string
    char *build_id; // string
    char *md5sum; // string
    char *sha1sum; // string
    char *sha256sum; // string
    char *corellium_checksum; // string
    char *release_date; // string
    char *upload_date; // string
    object_t *metadata; //object
    char *unique_id; // string
    char *android_flavor; // string
    char *api_version; // string
    int rooted; //boolean
    int installed; //boolean
    char *created_at; //date time
    char *updated_at; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} firmware_t;

__attribute__((deprecated)) firmware_t *firmware_create(
    list_t *model,
    list_t *firmware_assets,
    char *filename,
    char *type,
    double size,
    char *url,
    char *version,
    char *build_id,
    char *md5sum,
    char *sha1sum,
    char *sha256sum,
    char *corellium_checksum,
    char *release_date,
    char *upload_date,
    object_t *metadata,
    char *unique_id,
    char *android_flavor,
    char *api_version,
    int rooted,
    int installed,
    char *created_at,
    char *updated_at
);

void firmware_free(firmware_t *firmware);

firmware_t *firmware_parseFromJSON(cJSON *firmwareJSON);

cJSON *firmware_convertToJSON(firmware_t *firmware);

#endif /* _firmware_H_ */

