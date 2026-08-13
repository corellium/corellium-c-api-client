/*
 * image_extended_device.h
 *
 * 
 */

#ifndef _image_extended_device_H_
#define _image_extended_device_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct image_extended_device_t image_extended_device_t;

#include "image_firmware.h"



typedef struct image_extended_device_t {
    char *flavor; // string
    list_t *firmwares; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} image_extended_device_t;

__attribute__((deprecated)) image_extended_device_t *image_extended_device_create(
    char *flavor,
    list_t *firmwares
);

void image_extended_device_free(image_extended_device_t *image_extended_device);

image_extended_device_t *image_extended_device_parseFromJSON(cJSON *image_extended_deviceJSON);

cJSON *image_extended_device_convertToJSON(image_extended_device_t *image_extended_device);

#endif /* _image_extended_device_H_ */

