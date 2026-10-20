/*
 * cluster_config_package_config_flavor_filters_inner.h
 *
 * 
 */

#ifndef _cluster_config_package_config_flavor_filters_inner_H_
#define _cluster_config_package_config_flavor_filters_inner_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cluster_config_package_config_flavor_filters_inner_t cluster_config_package_config_flavor_filters_inner_t;

#include "cluster_config_package_config_flavor_filters_inner_apply.h"
#include "cluster_config_package_config_flavor_filters_inner_filter.h"



typedef struct cluster_config_package_config_flavor_filters_inner_t {
    struct cluster_config_package_config_flavor_filters_inner_filter_t *filter; //model
    struct cluster_config_package_config_flavor_filters_inner_apply_t *apply; //model

    int _library_owned; // Is the library responsible for freeing this object?
} cluster_config_package_config_flavor_filters_inner_t;

__attribute__((deprecated)) cluster_config_package_config_flavor_filters_inner_t *cluster_config_package_config_flavor_filters_inner_create(
    cluster_config_package_config_flavor_filters_inner_filter_t *filter,
    cluster_config_package_config_flavor_filters_inner_apply_t *apply
);

void cluster_config_package_config_flavor_filters_inner_free(cluster_config_package_config_flavor_filters_inner_t *cluster_config_package_config_flavor_filters_inner);

cluster_config_package_config_flavor_filters_inner_t *cluster_config_package_config_flavor_filters_inner_parseFromJSON(cJSON *cluster_config_package_config_flavor_filters_innerJSON);

cJSON *cluster_config_package_config_flavor_filters_inner_convertToJSON(cluster_config_package_config_flavor_filters_inner_t *cluster_config_package_config_flavor_filters_inner);

#endif /* _cluster_config_package_config_flavor_filters_inner_H_ */

