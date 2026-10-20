/*
 * cluster_config_package_config.h
 *
 * 
 */

#ifndef _cluster_config_package_config_H_
#define _cluster_config_package_config_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cluster_config_package_config_t cluster_config_package_config_t;

#include "any_type.h"
#include "cluster_config_package_config_components.h"
#include "cluster_config_package_config_features.h"
#include "cluster_config_package_config_flavor_filters_inner.h"
#include "object.h"

// Enum NETWORKTYPE for cluster_config_package_config

typedef enum  { corellium_api_cluster_config_package_config_NETWORKTYPE_NULL = 0, corellium_api_cluster_config_package_config_NETWORKTYPE_bridged, corellium_api_cluster_config_package_config_NETWORKTYPE_nat, corellium_api_cluster_config_package_config_NETWORKTYPE_routed } corellium_api_cluster_config_package_config_NETWORKTYPE_e;

char* cluster_config_package_config_network_type_ToString(corellium_api_cluster_config_package_config_NETWORKTYPE_e network_type);

corellium_api_cluster_config_package_config_NETWORKTYPE_e cluster_config_package_config_network_type_FromString(char* network_type);



typedef struct cluster_config_package_config_t {
    char *license_type; // string
    char *cluster_id; // string
    corellium_api_cluster_config_package_config_NETWORKTYPE_e network_type; //enum
    object_t *physical_interfaces; //object
    struct cluster_config_package_config_features_t *features; //model
    struct cluster_config_package_config_components_t *components; //model
    char *terms_of_service; // string
    int domain_authentication_providers; //boolean
    char *max_network_monitor_file_size; // string
    int combined; //boolean
    list_t *flavor_filters; //nonprimitive container
    int charm_sdk; //boolean
    int highly_available; //boolean
    char *node_version; // string
    int invalid_build; //boolean
    int sep_sim; //boolean
    int kernel_gdb; //boolean
    int android; //boolean
    int no_ios; //boolean
    int ios_betas; //boolean
    int charm_modules; //boolean
    int btrace; //boolean
    int strace; //boolean
    int game_streaming; //boolean
    char *container_template_generation; // string
    int s3_supported; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} cluster_config_package_config_t;

__attribute__((deprecated)) cluster_config_package_config_t *cluster_config_package_config_create(
    char *license_type,
    char *cluster_id,
    corellium_api_cluster_config_package_config_NETWORKTYPE_e network_type,
    object_t *physical_interfaces,
    cluster_config_package_config_features_t *features,
    cluster_config_package_config_components_t *components,
    char *terms_of_service,
    int domain_authentication_providers,
    char *max_network_monitor_file_size,
    int combined,
    list_t *flavor_filters,
    int charm_sdk,
    int highly_available,
    char *node_version,
    int invalid_build,
    int sep_sim,
    int kernel_gdb,
    int android,
    int no_ios,
    int ios_betas,
    int charm_modules,
    int btrace,
    int strace,
    int game_streaming,
    char *container_template_generation,
    int s3_supported
);

void cluster_config_package_config_free(cluster_config_package_config_t *cluster_config_package_config);

cluster_config_package_config_t *cluster_config_package_config_parseFromJSON(cJSON *cluster_config_package_configJSON);

cJSON *cluster_config_package_config_convertToJSON(cluster_config_package_config_t *cluster_config_package_config);

#endif /* _cluster_config_package_config_H_ */

