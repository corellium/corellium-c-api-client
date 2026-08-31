/*
 * cluster_config_ipsw_filters_inner.h
 *
 * 
 */

#ifndef _cluster_config_ipsw_filters_inner_H_
#define _cluster_config_ipsw_filters_inner_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cluster_config_ipsw_filters_inner_t cluster_config_ipsw_filters_inner_t;

#include "cluster_config_ipsw_filters_inner_device.h"
#include "cluster_config_ipsw_filters_inner_version.h"



typedef struct cluster_config_ipsw_filters_inner_t {
    struct cluster_config_ipsw_filters_inner_device_t *device; //model
    struct cluster_config_ipsw_filters_inner_version_t *version; //model
    int include; //boolean
    int exclude; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} cluster_config_ipsw_filters_inner_t;

__attribute__((deprecated)) cluster_config_ipsw_filters_inner_t *cluster_config_ipsw_filters_inner_create(
    cluster_config_ipsw_filters_inner_device_t *device,
    cluster_config_ipsw_filters_inner_version_t *version,
    int include,
    int exclude
);

void cluster_config_ipsw_filters_inner_free(cluster_config_ipsw_filters_inner_t *cluster_config_ipsw_filters_inner);

cluster_config_ipsw_filters_inner_t *cluster_config_ipsw_filters_inner_parseFromJSON(cJSON *cluster_config_ipsw_filters_innerJSON);

cJSON *cluster_config_ipsw_filters_inner_convertToJSON(cluster_config_ipsw_filters_inner_t *cluster_config_ipsw_filters_inner);

#endif /* _cluster_config_ipsw_filters_inner_H_ */

