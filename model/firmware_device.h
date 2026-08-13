/*
 * firmware_device.h
 *
 * 
 */

#ifndef _firmware_device_H_
#define _firmware_device_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct firmware_device_t firmware_device_t;




typedef struct firmware_device_t {
    char *type; // string
    char *model; // string
    char *name; // string
    char *platform; // string
    char *hw_model; // string
    char *bdid; // string
    char *cpid; // string
    char *created_at; //date time
    char *updated_at; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} firmware_device_t;

__attribute__((deprecated)) firmware_device_t *firmware_device_create(
    char *type,
    char *model,
    char *name,
    char *platform,
    char *hw_model,
    char *bdid,
    char *cpid,
    char *created_at,
    char *updated_at
);

void firmware_device_free(firmware_device_t *firmware_device);

firmware_device_t *firmware_device_parseFromJSON(cJSON *firmware_deviceJSON);

cJSON *firmware_device_convertToJSON(firmware_device_t *firmware_device);

#endif /* _firmware_device_H_ */

