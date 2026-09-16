/*
 * model_firmware.h
 *
 * 
 */

#ifndef _model_firmware_H_
#define _model_firmware_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct model_firmware_t model_firmware_t;

#include "any_type.h"
#include "object.h"



typedef struct model_firmware_t {
    char *os_version; // string
    char *os_build; // string
    char *android_flavor; // string
    char *api_version; // string
    char *sha256sum; // string
    char *sha1sum; // string
    char *md5sum; // string
    double size; //numeric
    char *unique_id; // string
    object_t *metadata; //object
    char *release_date; //date time
    char *upload_date; // string
    char *url; // string
    char *orig_url; // string
    char *filename; // string
    int rooted; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} model_firmware_t;

__attribute__((deprecated)) model_firmware_t *model_firmware_create(
    char *os_version,
    char *os_build,
    char *android_flavor,
    char *api_version,
    char *sha256sum,
    char *sha1sum,
    char *md5sum,
    double size,
    char *unique_id,
    object_t *metadata,
    char *release_date,
    char *upload_date,
    char *url,
    char *orig_url,
    char *filename,
    int rooted
);

void model_firmware_free(model_firmware_t *model_firmware);

model_firmware_t *model_firmware_parseFromJSON(cJSON *model_firmwareJSON);

cJSON *model_firmware_convertToJSON(model_firmware_t *model_firmware);

#endif /* _model_firmware_H_ */

