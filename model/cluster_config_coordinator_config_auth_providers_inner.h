/*
 * cluster_config_coordinator_config_auth_providers_inner.h
 *
 * 
 */

#ifndef _cluster_config_coordinator_config_auth_providers_inner_H_
#define _cluster_config_coordinator_config_auth_providers_inner_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cluster_config_coordinator_config_auth_providers_inner_t cluster_config_coordinator_config_auth_providers_inner_t;

#include "cluster_config_coordinator_config_auth_providers_inner_any_of.h"
#include "cluster_config_coordinator_config_auth_providers_inner_any_of_1.h"



typedef struct cluster_config_coordinator_config_auth_providers_inner_t {
    char *provider; // string
    char *discovery_url; // string
    char *client_id; // string
    char *client_secret; // string
    char *label; // string
    int invited_only; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} cluster_config_coordinator_config_auth_providers_inner_t;

__attribute__((deprecated)) cluster_config_coordinator_config_auth_providers_inner_t *cluster_config_coordinator_config_auth_providers_inner_create(
    char *provider,
    char *discovery_url,
    char *client_id,
    char *client_secret,
    char *label,
    int invited_only
);

void cluster_config_coordinator_config_auth_providers_inner_free(cluster_config_coordinator_config_auth_providers_inner_t *cluster_config_coordinator_config_auth_providers_inner);

cluster_config_coordinator_config_auth_providers_inner_t *cluster_config_coordinator_config_auth_providers_inner_parseFromJSON(cJSON *cluster_config_coordinator_config_auth_providers_innerJSON);

cJSON *cluster_config_coordinator_config_auth_providers_inner_convertToJSON(cluster_config_coordinator_config_auth_providers_inner_t *cluster_config_coordinator_config_auth_providers_inner);

#endif /* _cluster_config_coordinator_config_auth_providers_inner_H_ */

