/*
 * device_auto_shutdown_schema.h
 *
 * 
 */

#ifndef _device_auto_shutdown_schema_H_
#define _device_auto_shutdown_schema_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct device_auto_shutdown_schema_t device_auto_shutdown_schema_t;




typedef struct device_auto_shutdown_schema_t {
    int enabled; //boolean
    double threshold; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} device_auto_shutdown_schema_t;

__attribute__((deprecated)) device_auto_shutdown_schema_t *device_auto_shutdown_schema_create(
    int enabled,
    double threshold
);

void device_auto_shutdown_schema_free(device_auto_shutdown_schema_t *device_auto_shutdown_schema);

device_auto_shutdown_schema_t *device_auto_shutdown_schema_parseFromJSON(cJSON *device_auto_shutdown_schemaJSON);

cJSON *device_auto_shutdown_schema_convertToJSON(device_auto_shutdown_schema_t *device_auto_shutdown_schema);

#endif /* _device_auto_shutdown_schema_H_ */

