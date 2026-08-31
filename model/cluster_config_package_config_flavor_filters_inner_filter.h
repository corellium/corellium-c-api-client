/*
 * cluster_config_package_config_flavor_filters_inner_filter.h
 *
 * 
 */

#ifndef _cluster_config_package_config_flavor_filters_inner_filter_H_
#define _cluster_config_package_config_flavor_filters_inner_filter_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cluster_config_package_config_flavor_filters_inner_filter_t cluster_config_package_config_flavor_filters_inner_filter_t;




typedef struct cluster_config_package_config_flavor_filters_inner_filter_t {
    char *license; // string
    char *type; // string

    int _library_owned; // Is the library responsible for freeing this object?
} cluster_config_package_config_flavor_filters_inner_filter_t;

__attribute__((deprecated)) cluster_config_package_config_flavor_filters_inner_filter_t *cluster_config_package_config_flavor_filters_inner_filter_create(
    char *license,
    char *type
);

void cluster_config_package_config_flavor_filters_inner_filter_free(cluster_config_package_config_flavor_filters_inner_filter_t *cluster_config_package_config_flavor_filters_inner_filter);

cluster_config_package_config_flavor_filters_inner_filter_t *cluster_config_package_config_flavor_filters_inner_filter_parseFromJSON(cJSON *cluster_config_package_config_flavor_filters_inner_filterJSON);

cJSON *cluster_config_package_config_flavor_filters_inner_filter_convertToJSON(cluster_config_package_config_flavor_filters_inner_filter_t *cluster_config_package_config_flavor_filters_inner_filter);

#endif /* _cluster_config_package_config_flavor_filters_inner_filter_H_ */

