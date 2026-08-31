/*
 * cluster_config_coordinator_config_auth_providers_inner_any_of_1.h
 *
 * 
 */

#ifndef _cluster_config_coordinator_config_auth_providers_inner_any_of_1_H_
#define _cluster_config_coordinator_config_auth_providers_inner_any_of_1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cluster_config_coordinator_config_auth_providers_inner_any_of_1_t cluster_config_coordinator_config_auth_providers_inner_any_of_1_t;




typedef struct cluster_config_coordinator_config_auth_providers_inner_any_of_1_t {
    char *provider; // string
    char *discovery_url; // string
    char *client_id; // string
    char *client_secret; // string
    char *label; // string
    int invited_only; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} cluster_config_coordinator_config_auth_providers_inner_any_of_1_t;

__attribute__((deprecated)) cluster_config_coordinator_config_auth_providers_inner_any_of_1_t *cluster_config_coordinator_config_auth_providers_inner_any_of_1_create(
    char *provider,
    char *discovery_url,
    char *client_id,
    char *client_secret,
    char *label,
    int invited_only
);

void cluster_config_coordinator_config_auth_providers_inner_any_of_1_free(cluster_config_coordinator_config_auth_providers_inner_any_of_1_t *cluster_config_coordinator_config_auth_providers_inner_any_of_1);

cluster_config_coordinator_config_auth_providers_inner_any_of_1_t *cluster_config_coordinator_config_auth_providers_inner_any_of_1_parseFromJSON(cJSON *cluster_config_coordinator_config_auth_providers_inner_any_of_1JSON);

cJSON *cluster_config_coordinator_config_auth_providers_inner_any_of_1_convertToJSON(cluster_config_coordinator_config_auth_providers_inner_any_of_1_t *cluster_config_coordinator_config_auth_providers_inner_any_of_1);

#endif /* _cluster_config_coordinator_config_auth_providers_inner_any_of_1_H_ */

