/*
 * cluster_config_net_mon_ca.h
 *
 * 
 */

#ifndef _cluster_config_net_mon_ca_H_
#define _cluster_config_net_mon_ca_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cluster_config_net_mon_ca_t cluster_config_net_mon_ca_t;




typedef struct cluster_config_net_mon_ca_t {
    char *certificate; // string
    char *key; // string
    char *subject_hash2; // string

    int _library_owned; // Is the library responsible for freeing this object?
} cluster_config_net_mon_ca_t;

__attribute__((deprecated)) cluster_config_net_mon_ca_t *cluster_config_net_mon_ca_create(
    char *certificate,
    char *key,
    char *subject_hash2
);

void cluster_config_net_mon_ca_free(cluster_config_net_mon_ca_t *cluster_config_net_mon_ca);

cluster_config_net_mon_ca_t *cluster_config_net_mon_ca_parseFromJSON(cJSON *cluster_config_net_mon_caJSON);

cJSON *cluster_config_net_mon_ca_convertToJSON(cluster_config_net_mon_ca_t *cluster_config_net_mon_ca);

#endif /* _cluster_config_net_mon_ca_H_ */

