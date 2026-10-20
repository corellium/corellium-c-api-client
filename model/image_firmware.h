/*
 * image_firmware.h
 *
 * 
 */

#ifndef _image_firmware_H_
#define _image_firmware_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct image_firmware_t image_firmware_t;




typedef struct image_firmware_t {
    char *filename; // string
    char *version; // string
    char *buildid; // string
    char *url; // string
    char *orig_url; // string

    int _library_owned; // Is the library responsible for freeing this object?
} image_firmware_t;

__attribute__((deprecated)) image_firmware_t *image_firmware_create(
    char *filename,
    char *version,
    char *buildid,
    char *url,
    char *orig_url
);

void image_firmware_free(image_firmware_t *image_firmware);

image_firmware_t *image_firmware_parseFromJSON(cJSON *image_firmwareJSON);

cJSON *image_firmware_convertToJSON(image_firmware_t *image_firmware);

#endif /* _image_firmware_H_ */

