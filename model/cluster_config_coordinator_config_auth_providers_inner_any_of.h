/*
 * cluster_config_coordinator_config_auth_providers_inner_any_of.h
 *
 * 
 */

#ifndef _cluster_config_coordinator_config_auth_providers_inner_any_of_H_
#define _cluster_config_coordinator_config_auth_providers_inner_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cluster_config_coordinator_config_auth_providers_inner_any_of_t cluster_config_coordinator_config_auth_providers_inner_any_of_t;




typedef struct cluster_config_coordinator_config_auth_providers_inner_any_of_t {
    char *provider; // string

    int _library_owned; // Is the library responsible for freeing this object?
} cluster_config_coordinator_config_auth_providers_inner_any_of_t;

__attribute__((deprecated)) cluster_config_coordinator_config_auth_providers_inner_any_of_t *cluster_config_coordinator_config_auth_providers_inner_any_of_create(
    char *provider
);

void cluster_config_coordinator_config_auth_providers_inner_any_of_free(cluster_config_coordinator_config_auth_providers_inner_any_of_t *cluster_config_coordinator_config_auth_providers_inner_any_of);

cluster_config_coordinator_config_auth_providers_inner_any_of_t *cluster_config_coordinator_config_auth_providers_inner_any_of_parseFromJSON(cJSON *cluster_config_coordinator_config_auth_providers_inner_any_ofJSON);

cJSON *cluster_config_coordinator_config_auth_providers_inner_any_of_convertToJSON(cluster_config_coordinator_config_auth_providers_inner_any_of_t *cluster_config_coordinator_config_auth_providers_inner_any_of);

#endif /* _cluster_config_coordinator_config_auth_providers_inner_any_of_H_ */

