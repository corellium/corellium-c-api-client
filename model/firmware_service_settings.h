/*
 * firmware_service_settings.h
 *
 * 
 */

#ifndef _firmware_service_settings_H_
#define _firmware_service_settings_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct firmware_service_settings_t firmware_service_settings_t;

#include "ipsw_filter_v3.h"



typedef struct firmware_service_settings_t {
    int cache_firmware; //boolean
    int cluster_firmware_assets; //boolean
    int fallback_original_url; //boolean
    int fetch_firmware_assets; //boolean
    int should_download; //boolean
    list_t *download_ipsw_filters; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} firmware_service_settings_t;

__attribute__((deprecated)) firmware_service_settings_t *firmware_service_settings_create(
    int cache_firmware,
    int cluster_firmware_assets,
    int fallback_original_url,
    int fetch_firmware_assets,
    int should_download,
    list_t *download_ipsw_filters
);

void firmware_service_settings_free(firmware_service_settings_t *firmware_service_settings);

firmware_service_settings_t *firmware_service_settings_parseFromJSON(cJSON *firmware_service_settingsJSON);

cJSON *firmware_service_settings_convertToJSON(firmware_service_settings_t *firmware_service_settings);

#endif /* _firmware_service_settings_H_ */

