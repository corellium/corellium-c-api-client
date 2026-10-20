/*
 * cluster_config_node_specific_config.h
 *
 * 
 */

#ifndef _cluster_config_node_specific_config_H_
#define _cluster_config_node_specific_config_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cluster_config_node_specific_config_t cluster_config_node_specific_config_t;




typedef struct cluster_config_node_specific_config_t {
    char *az; // string
    char *external_ip; // string
    char *node_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} cluster_config_node_specific_config_t;

__attribute__((deprecated)) cluster_config_node_specific_config_t *cluster_config_node_specific_config_create(
    char *az,
    char *external_ip,
    char *node_id
);

void cluster_config_node_specific_config_free(cluster_config_node_specific_config_t *cluster_config_node_specific_config);

cluster_config_node_specific_config_t *cluster_config_node_specific_config_parseFromJSON(cJSON *cluster_config_node_specific_configJSON);

cJSON *cluster_config_node_specific_config_convertToJSON(cluster_config_node_specific_config_t *cluster_config_node_specific_config);

#endif /* _cluster_config_node_specific_config_H_ */

