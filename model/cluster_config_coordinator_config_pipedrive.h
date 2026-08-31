/*
 * cluster_config_coordinator_config_pipedrive.h
 *
 * 
 */

#ifndef _cluster_config_coordinator_config_pipedrive_H_
#define _cluster_config_coordinator_config_pipedrive_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cluster_config_coordinator_config_pipedrive_t cluster_config_coordinator_config_pipedrive_t;




typedef struct cluster_config_coordinator_config_pipedrive_t {
    char *token; // string

    int _library_owned; // Is the library responsible for freeing this object?
} cluster_config_coordinator_config_pipedrive_t;

__attribute__((deprecated)) cluster_config_coordinator_config_pipedrive_t *cluster_config_coordinator_config_pipedrive_create(
    char *token
);

void cluster_config_coordinator_config_pipedrive_free(cluster_config_coordinator_config_pipedrive_t *cluster_config_coordinator_config_pipedrive);

cluster_config_coordinator_config_pipedrive_t *cluster_config_coordinator_config_pipedrive_parseFromJSON(cJSON *cluster_config_coordinator_config_pipedriveJSON);

cJSON *cluster_config_coordinator_config_pipedrive_convertToJSON(cluster_config_coordinator_config_pipedrive_t *cluster_config_coordinator_config_pipedrive);

#endif /* _cluster_config_coordinator_config_pipedrive_H_ */

