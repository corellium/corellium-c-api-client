/*
 * firmware_service_config.h
 *
 * 
 */

#ifndef _firmware_service_config_H_
#define _firmware_service_config_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct firmware_service_config_t firmware_service_config_t;

#include "firmware_service_config_cache_firmware.h"
#include "firmware_service_config_download_ipsw_filters.h"



typedef struct firmware_service_config_t {
    struct firmware_service_config_cache_firmware_t *cache_firmware; //model
    struct firmware_service_config_cache_firmware_t *cluster_firmware_assets; //model
    struct firmware_service_config_cache_firmware_t *fallback_original_url; //model
    struct firmware_service_config_cache_firmware_t *fetch_firmware_assets; //model
    struct firmware_service_config_cache_firmware_t *should_download; //model
    struct firmware_service_config_download_ipsw_filters_t *download_ipsw_filters; //model

    int _library_owned; // Is the library responsible for freeing this object?
} firmware_service_config_t;

__attribute__((deprecated)) firmware_service_config_t *firmware_service_config_create(
    firmware_service_config_cache_firmware_t *cache_firmware,
    firmware_service_config_cache_firmware_t *cluster_firmware_assets,
    firmware_service_config_cache_firmware_t *fallback_original_url,
    firmware_service_config_cache_firmware_t *fetch_firmware_assets,
    firmware_service_config_cache_firmware_t *should_download,
    firmware_service_config_download_ipsw_filters_t *download_ipsw_filters
);

void firmware_service_config_free(firmware_service_config_t *firmware_service_config);

firmware_service_config_t *firmware_service_config_parseFromJSON(cJSON *firmware_service_configJSON);

cJSON *firmware_service_config_convertToJSON(firmware_service_config_t *firmware_service_config);

#endif /* _firmware_service_config_H_ */

