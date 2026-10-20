/*
 * cluster_config_coordinator_config_ensure_domain.h
 *
 * 
 */

#ifndef _cluster_config_coordinator_config_ensure_domain_H_
#define _cluster_config_coordinator_config_ensure_domain_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cluster_config_coordinator_config_ensure_domain_t cluster_config_coordinator_config_ensure_domain_t;

#include "cluster_config_coordinator_config_ensure_domain_properties.h"
#include "cluster_config_coordinator_config_ensure_domain_quotas.h"



typedef struct cluster_config_coordinator_config_ensure_domain_t {
    char *domain; // string
    char *domain_name; // string
    struct cluster_config_coordinator_config_ensure_domain_quotas_t *quotas; //model
    struct cluster_config_coordinator_config_ensure_domain_properties_t *properties; //model
    char *admin_password_hash; // string
    int admin_user_cloud_administrator; //boolean
    int is_individual_aggregate; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} cluster_config_coordinator_config_ensure_domain_t;

__attribute__((deprecated)) cluster_config_coordinator_config_ensure_domain_t *cluster_config_coordinator_config_ensure_domain_create(
    char *domain,
    char *domain_name,
    cluster_config_coordinator_config_ensure_domain_quotas_t *quotas,
    cluster_config_coordinator_config_ensure_domain_properties_t *properties,
    char *admin_password_hash,
    int admin_user_cloud_administrator,
    int is_individual_aggregate
);

void cluster_config_coordinator_config_ensure_domain_free(cluster_config_coordinator_config_ensure_domain_t *cluster_config_coordinator_config_ensure_domain);

cluster_config_coordinator_config_ensure_domain_t *cluster_config_coordinator_config_ensure_domain_parseFromJSON(cJSON *cluster_config_coordinator_config_ensure_domainJSON);

cJSON *cluster_config_coordinator_config_ensure_domain_convertToJSON(cluster_config_coordinator_config_ensure_domain_t *cluster_config_coordinator_config_ensure_domain);

#endif /* _cluster_config_coordinator_config_ensure_domain_H_ */

