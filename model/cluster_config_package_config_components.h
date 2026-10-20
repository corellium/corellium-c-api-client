/*
 * cluster_config_package_config_components.h
 *
 * 
 */

#ifndef _cluster_config_package_config_components_H_
#define _cluster_config_package_config_components_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cluster_config_package_config_components_t cluster_config_package_config_components_t;




typedef struct cluster_config_package_config_components_t {
    int cellebrite_device_image; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} cluster_config_package_config_components_t;

__attribute__((deprecated)) cluster_config_package_config_components_t *cluster_config_package_config_components_create(
    int cellebrite_device_image
);

void cluster_config_package_config_components_free(cluster_config_package_config_components_t *cluster_config_package_config_components);

cluster_config_package_config_components_t *cluster_config_package_config_components_parseFromJSON(cJSON *cluster_config_package_config_componentsJSON);

cJSON *cluster_config_package_config_components_convertToJSON(cluster_config_package_config_components_t *cluster_config_package_config_components);

#endif /* _cluster_config_package_config_components_H_ */

