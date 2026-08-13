/*
 * firmware_v1.h
 *
 * 
 */

#ifndef _firmware_v1_H_
#define _firmware_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct firmware_v1_t firmware_v1_t;

#include "any_type.h"
#include "object.h"



typedef struct firmware_v1_t {
    char *version; // string
    char *buildid; // string
    char *android_flavor; // string
    char *api_version; // string
    char *sha256sum; // string
    char *sha1sum; // string
    char *md5sum; // string
    double size; //numeric
    char *unique_id; // string
    object_t *metadata; //object
    char *releasedate; //date time
    char *uploaddate; //date time
    char *url; // string
    char *orig_url; // string
    char *filename; // string

    int _library_owned; // Is the library responsible for freeing this object?
} firmware_v1_t;

__attribute__((deprecated)) firmware_v1_t *firmware_v1_create(
    char *version,
    char *buildid,
    char *android_flavor,
    char *api_version,
    char *sha256sum,
    char *sha1sum,
    char *md5sum,
    double size,
    char *unique_id,
    object_t *metadata,
    char *releasedate,
    char *uploaddate,
    char *url,
    char *orig_url,
    char *filename
);

void firmware_v1_free(firmware_v1_t *firmware_v1);

firmware_v1_t *firmware_v1_parseFromJSON(cJSON *firmware_v1JSON);

cJSON *firmware_v1_convertToJSON(firmware_v1_t *firmware_v1);

#endif /* _firmware_v1_H_ */

