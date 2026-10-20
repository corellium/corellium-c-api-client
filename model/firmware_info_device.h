/*
 * firmware_info_device.h
 *
 * Matched supported device; only present when extended info was requested.
 */

#ifndef _firmware_info_device_H_
#define _firmware_info_device_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct firmware_info_device_t firmware_info_device_t;

#include "firmware_info_device_firmwares_inner.h"



typedef struct firmware_info_device_t {
    char *flavor; // string
    list_t *firmwares; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} firmware_info_device_t;

__attribute__((deprecated)) firmware_info_device_t *firmware_info_device_create(
    char *flavor,
    list_t *firmwares
);

void firmware_info_device_free(firmware_info_device_t *firmware_info_device);

firmware_info_device_t *firmware_info_device_parseFromJSON(cJSON *firmware_info_deviceJSON);

cJSON *firmware_info_device_convertToJSON(firmware_info_device_t *firmware_info_device);

#endif /* _firmware_info_device_H_ */

