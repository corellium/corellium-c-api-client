/*
 * firmware_service_config_cache_firmware.h
 *
 * 
 */

#ifndef _firmware_service_config_cache_firmware_H_
#define _firmware_service_config_cache_firmware_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct firmware_service_config_cache_firmware_t firmware_service_config_cache_firmware_t;




typedef struct firmware_service_config_cache_firmware_t {
    int value; //boolean
    char *component; // string
    char *title; // string
    char *description; // string
    char *type; // string

    int _library_owned; // Is the library responsible for freeing this object?
} firmware_service_config_cache_firmware_t;

__attribute__((deprecated)) firmware_service_config_cache_firmware_t *firmware_service_config_cache_firmware_create(
    int value,
    char *component,
    char *title,
    char *description,
    char *type
);

void firmware_service_config_cache_firmware_free(firmware_service_config_cache_firmware_t *firmware_service_config_cache_firmware);

firmware_service_config_cache_firmware_t *firmware_service_config_cache_firmware_parseFromJSON(cJSON *firmware_service_config_cache_firmwareJSON);

cJSON *firmware_service_config_cache_firmware_convertToJSON(firmware_service_config_cache_firmware_t *firmware_service_config_cache_firmware);

#endif /* _firmware_service_config_cache_firmware_H_ */

