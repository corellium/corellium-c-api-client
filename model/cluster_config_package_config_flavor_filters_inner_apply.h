/*
 * cluster_config_package_config_flavor_filters_inner_apply.h
 *
 * 
 */

#ifndef _cluster_config_package_config_flavor_filters_inner_apply_H_
#define _cluster_config_package_config_flavor_filters_inner_apply_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cluster_config_package_config_flavor_filters_inner_apply_t cluster_config_package_config_flavor_filters_inner_apply_t;




typedef struct cluster_config_package_config_flavor_filters_inner_apply_t {
    int supports_core_trace; //boolean
    int supports_port_frida; //boolean
    int supports_custom_firmware; //boolean
    int supports_custom_kernel; //boolean
    int supports_gdb; //boolean
    int supports_custom_devicetree; //boolean
    int supports_network_monitor; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} cluster_config_package_config_flavor_filters_inner_apply_t;

__attribute__((deprecated)) cluster_config_package_config_flavor_filters_inner_apply_t *cluster_config_package_config_flavor_filters_inner_apply_create(
    int supports_core_trace,
    int supports_port_frida,
    int supports_custom_firmware,
    int supports_custom_kernel,
    int supports_gdb,
    int supports_custom_devicetree,
    int supports_network_monitor
);

void cluster_config_package_config_flavor_filters_inner_apply_free(cluster_config_package_config_flavor_filters_inner_apply_t *cluster_config_package_config_flavor_filters_inner_apply);

cluster_config_package_config_flavor_filters_inner_apply_t *cluster_config_package_config_flavor_filters_inner_apply_parseFromJSON(cJSON *cluster_config_package_config_flavor_filters_inner_applyJSON);

cJSON *cluster_config_package_config_flavor_filters_inner_apply_convertToJSON(cluster_config_package_config_flavor_filters_inner_apply_t *cluster_config_package_config_flavor_filters_inner_apply);

#endif /* _cluster_config_package_config_flavor_filters_inner_apply_H_ */

