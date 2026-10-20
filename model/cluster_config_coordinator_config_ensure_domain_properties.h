/*
 * cluster_config_coordinator_config_ensure_domain_properties.h
 *
 * 
 */

#ifndef _cluster_config_coordinator_config_ensure_domain_properties_H_
#define _cluster_config_coordinator_config_ensure_domain_properties_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cluster_config_coordinator_config_ensure_domain_properties_t cluster_config_coordinator_config_ensure_domain_properties_t;




typedef struct cluster_config_coordinator_config_ensure_domain_properties_t {
    char *license_type; // string
    int android; //boolean
    int no_ios; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} cluster_config_coordinator_config_ensure_domain_properties_t;

__attribute__((deprecated)) cluster_config_coordinator_config_ensure_domain_properties_t *cluster_config_coordinator_config_ensure_domain_properties_create(
    char *license_type,
    int android,
    int no_ios
);

void cluster_config_coordinator_config_ensure_domain_properties_free(cluster_config_coordinator_config_ensure_domain_properties_t *cluster_config_coordinator_config_ensure_domain_properties);

cluster_config_coordinator_config_ensure_domain_properties_t *cluster_config_coordinator_config_ensure_domain_properties_parseFromJSON(cJSON *cluster_config_coordinator_config_ensure_domain_propertiesJSON);

cJSON *cluster_config_coordinator_config_ensure_domain_properties_convertToJSON(cluster_config_coordinator_config_ensure_domain_properties_t *cluster_config_coordinator_config_ensure_domain_properties);

#endif /* _cluster_config_coordinator_config_ensure_domain_properties_H_ */

