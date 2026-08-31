/*
 * cluster_config_firmware_service_config.h
 *
 * 
 */

#ifndef _cluster_config_firmware_service_config_H_
#define _cluster_config_firmware_service_config_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cluster_config_firmware_service_config_t cluster_config_firmware_service_config_t;




typedef struct cluster_config_firmware_service_config_t {
    int fetch_firmware_assets; //boolean
    int cluster_firmware_assets; //boolean
    int cache_firmware; //boolean
    int should_download; //boolean
    int fallback_original_url; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} cluster_config_firmware_service_config_t;

__attribute__((deprecated)) cluster_config_firmware_service_config_t *cluster_config_firmware_service_config_create(
    int fetch_firmware_assets,
    int cluster_firmware_assets,
    int cache_firmware,
    int should_download,
    int fallback_original_url
);

void cluster_config_firmware_service_config_free(cluster_config_firmware_service_config_t *cluster_config_firmware_service_config);

cluster_config_firmware_service_config_t *cluster_config_firmware_service_config_parseFromJSON(cJSON *cluster_config_firmware_service_configJSON);

cJSON *cluster_config_firmware_service_config_convertToJSON(cluster_config_firmware_service_config_t *cluster_config_firmware_service_config);

#endif /* _cluster_config_firmware_service_config_H_ */

