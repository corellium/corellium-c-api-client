/*
 * cluster_config_coordinator_config_ensure_domain_quotas.h
 *
 * 
 */

#ifndef _cluster_config_coordinator_config_ensure_domain_quotas_H_
#define _cluster_config_coordinator_config_ensure_domain_quotas_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cluster_config_coordinator_config_ensure_domain_quotas_t cluster_config_coordinator_config_ensure_domain_quotas_t;




typedef struct cluster_config_coordinator_config_ensure_domain_quotas_t {
    double cores; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} cluster_config_coordinator_config_ensure_domain_quotas_t;

__attribute__((deprecated)) cluster_config_coordinator_config_ensure_domain_quotas_t *cluster_config_coordinator_config_ensure_domain_quotas_create(
    double cores
);

void cluster_config_coordinator_config_ensure_domain_quotas_free(cluster_config_coordinator_config_ensure_domain_quotas_t *cluster_config_coordinator_config_ensure_domain_quotas);

cluster_config_coordinator_config_ensure_domain_quotas_t *cluster_config_coordinator_config_ensure_domain_quotas_parseFromJSON(cJSON *cluster_config_coordinator_config_ensure_domain_quotasJSON);

cJSON *cluster_config_coordinator_config_ensure_domain_quotas_convertToJSON(cluster_config_coordinator_config_ensure_domain_quotas_t *cluster_config_coordinator_config_ensure_domain_quotas);

#endif /* _cluster_config_coordinator_config_ensure_domain_quotas_H_ */

