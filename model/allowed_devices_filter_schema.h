/*
 * allowed_devices_filter_schema.h
 *
 * 
 */

#ifndef _allowed_devices_filter_schema_H_
#define _allowed_devices_filter_schema_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct allowed_devices_filter_schema_t allowed_devices_filter_schema_t;

#include "allowed_firmware_schema.h"



typedef struct allowed_devices_filter_schema_t {
    char *device_name; // string
    list_t *allowed_firmwares; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} allowed_devices_filter_schema_t;

__attribute__((deprecated)) allowed_devices_filter_schema_t *allowed_devices_filter_schema_create(
    char *device_name,
    list_t *allowed_firmwares
);

void allowed_devices_filter_schema_free(allowed_devices_filter_schema_t *allowed_devices_filter_schema);

allowed_devices_filter_schema_t *allowed_devices_filter_schema_parseFromJSON(cJSON *allowed_devices_filter_schemaJSON);

cJSON *allowed_devices_filter_schema_convertToJSON(allowed_devices_filter_schema_t *allowed_devices_filter_schema);

#endif /* _allowed_devices_filter_schema_H_ */

