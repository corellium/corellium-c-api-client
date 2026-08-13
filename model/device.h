/*
 * device.h
 *
 * 
 */

#ifndef _device_H_
#define _device_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct device_t device_t;




typedef struct device_t {
    char *type; // string
    char *model; // string
    char *name; // string
    char *platform; // string
    char *hwmodel; // string
    char *bdid; // string
    char *cpid; // string
    char *created_at; // string
    char *updated_at; // string

    int _library_owned; // Is the library responsible for freeing this object?
} device_t;

__attribute__((deprecated)) device_t *device_create(
    char *type,
    char *model,
    char *name,
    char *platform,
    char *hwmodel,
    char *bdid,
    char *cpid,
    char *created_at,
    char *updated_at
);

void device_free(device_t *device);

device_t *device_parseFromJSON(cJSON *deviceJSON);

cJSON *device_convertToJSON(device_t *device);

#endif /* _device_H_ */

