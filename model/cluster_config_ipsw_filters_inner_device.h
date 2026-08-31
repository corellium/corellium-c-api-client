/*
 * cluster_config_ipsw_filters_inner_device.h
 *
 * 
 */

#ifndef _cluster_config_ipsw_filters_inner_device_H_
#define _cluster_config_ipsw_filters_inner_device_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cluster_config_ipsw_filters_inner_device_t cluster_config_ipsw_filters_inner_device_t;




typedef struct cluster_config_ipsw_filters_inner_device_t {
    char *product; // string

    int _library_owned; // Is the library responsible for freeing this object?
} cluster_config_ipsw_filters_inner_device_t;

__attribute__((deprecated)) cluster_config_ipsw_filters_inner_device_t *cluster_config_ipsw_filters_inner_device_create(
    char *product
);

void cluster_config_ipsw_filters_inner_device_free(cluster_config_ipsw_filters_inner_device_t *cluster_config_ipsw_filters_inner_device);

cluster_config_ipsw_filters_inner_device_t *cluster_config_ipsw_filters_inner_device_parseFromJSON(cJSON *cluster_config_ipsw_filters_inner_deviceJSON);

cJSON *cluster_config_ipsw_filters_inner_device_convertToJSON(cluster_config_ipsw_filters_inner_device_t *cluster_config_ipsw_filters_inner_device);

#endif /* _cluster_config_ipsw_filters_inner_device_H_ */

