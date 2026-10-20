/*
 * cluster_config_coordinator_config_hubspot.h
 *
 * 
 */

#ifndef _cluster_config_coordinator_config_hubspot_H_
#define _cluster_config_coordinator_config_hubspot_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cluster_config_coordinator_config_hubspot_t cluster_config_coordinator_config_hubspot_t;




typedef struct cluster_config_coordinator_config_hubspot_t {
    char *access_token; // string
    char *hubspot_contact_link; // string

    int _library_owned; // Is the library responsible for freeing this object?
} cluster_config_coordinator_config_hubspot_t;

__attribute__((deprecated)) cluster_config_coordinator_config_hubspot_t *cluster_config_coordinator_config_hubspot_create(
    char *access_token,
    char *hubspot_contact_link
);

void cluster_config_coordinator_config_hubspot_free(cluster_config_coordinator_config_hubspot_t *cluster_config_coordinator_config_hubspot);

cluster_config_coordinator_config_hubspot_t *cluster_config_coordinator_config_hubspot_parseFromJSON(cJSON *cluster_config_coordinator_config_hubspotJSON);

cJSON *cluster_config_coordinator_config_hubspot_convertToJSON(cluster_config_coordinator_config_hubspot_t *cluster_config_coordinator_config_hubspot);

#endif /* _cluster_config_coordinator_config_hubspot_H_ */

