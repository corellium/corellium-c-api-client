/*
 * image_extended.h
 *
 * 
 */

#ifndef _image_extended_H_
#define _image_extended_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct image_extended_t image_extended_t;

#include "image_extended_device.h"



typedef struct image_extended_t {
    char *type; // string
    char *version; // string
    char *buildid; // string
    list_t *device_ids; //primitive container
    char *board_config; // string
    struct image_extended_device_t *device; //model

    int _library_owned; // Is the library responsible for freeing this object?
} image_extended_t;

__attribute__((deprecated)) image_extended_t *image_extended_create(
    char *type,
    char *version,
    char *buildid,
    list_t *device_ids,
    char *board_config,
    image_extended_device_t *device
);

void image_extended_free(image_extended_t *image_extended);

image_extended_t *image_extended_parseFromJSON(cJSON *image_extendedJSON);

cJSON *image_extended_convertToJSON(image_extended_t *image_extended);

#endif /* _image_extended_H_ */

