/*
 * patch_firmware_service_config_body.h
 *
 * 
 */

#ifndef _patch_firmware_service_config_body_H_
#define _patch_firmware_service_config_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct patch_firmware_service_config_body_t patch_firmware_service_config_body_t;

#include "ipsw_filter_v3.h"



typedef struct patch_firmware_service_config_body_t {
    int cache_firmware; //boolean
    int cluster_firmware_assets; //boolean
    int fallback_original_url; //boolean
    int fetch_firmware_assets; //boolean
    int should_download; //boolean
    list_t *download_ipsw_filters; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} patch_firmware_service_config_body_t;

__attribute__((deprecated)) patch_firmware_service_config_body_t *patch_firmware_service_config_body_create(
    int cache_firmware,
    int cluster_firmware_assets,
    int fallback_original_url,
    int fetch_firmware_assets,
    int should_download,
    list_t *download_ipsw_filters
);

void patch_firmware_service_config_body_free(patch_firmware_service_config_body_t *patch_firmware_service_config_body);

patch_firmware_service_config_body_t *patch_firmware_service_config_body_parseFromJSON(cJSON *patch_firmware_service_config_bodyJSON);

cJSON *patch_firmware_service_config_body_convertToJSON(patch_firmware_service_config_body_t *patch_firmware_service_config_body);

#endif /* _patch_firmware_service_config_body_H_ */

