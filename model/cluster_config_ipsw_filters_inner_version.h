/*
 * cluster_config_ipsw_filters_inner_version.h
 *
 * 
 */

#ifndef _cluster_config_ipsw_filters_inner_version_H_
#define _cluster_config_ipsw_filters_inner_version_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cluster_config_ipsw_filters_inner_version_t cluster_config_ipsw_filters_inner_version_t;




typedef struct cluster_config_ipsw_filters_inner_version_t {
    char *lt; // string
    char *gt; // string
    char *le; // string
    char *ge; // string
    char *eq; // string

    int _library_owned; // Is the library responsible for freeing this object?
} cluster_config_ipsw_filters_inner_version_t;

__attribute__((deprecated)) cluster_config_ipsw_filters_inner_version_t *cluster_config_ipsw_filters_inner_version_create(
    char *lt,
    char *gt,
    char *le,
    char *ge,
    char *eq
);

void cluster_config_ipsw_filters_inner_version_free(cluster_config_ipsw_filters_inner_version_t *cluster_config_ipsw_filters_inner_version);

cluster_config_ipsw_filters_inner_version_t *cluster_config_ipsw_filters_inner_version_parseFromJSON(cJSON *cluster_config_ipsw_filters_inner_versionJSON);

cJSON *cluster_config_ipsw_filters_inner_version_convertToJSON(cluster_config_ipsw_filters_inner_version_t *cluster_config_ipsw_filters_inner_version);

#endif /* _cluster_config_ipsw_filters_inner_version_H_ */

