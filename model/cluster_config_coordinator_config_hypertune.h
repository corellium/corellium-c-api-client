/*
 * cluster_config_coordinator_config_hypertune.h
 *
 * 
 */

#ifndef _cluster_config_coordinator_config_hypertune_H_
#define _cluster_config_coordinator_config_hypertune_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cluster_config_coordinator_config_hypertune_t cluster_config_coordinator_config_hypertune_t;




typedef struct cluster_config_coordinator_config_hypertune_t {
    char *token; // string
    char *branch_name; // string
    char *init_data_path; // string

    int _library_owned; // Is the library responsible for freeing this object?
} cluster_config_coordinator_config_hypertune_t;

__attribute__((deprecated)) cluster_config_coordinator_config_hypertune_t *cluster_config_coordinator_config_hypertune_create(
    char *token,
    char *branch_name,
    char *init_data_path
);

void cluster_config_coordinator_config_hypertune_free(cluster_config_coordinator_config_hypertune_t *cluster_config_coordinator_config_hypertune);

cluster_config_coordinator_config_hypertune_t *cluster_config_coordinator_config_hypertune_parseFromJSON(cJSON *cluster_config_coordinator_config_hypertuneJSON);

cJSON *cluster_config_coordinator_config_hypertune_convertToJSON(cluster_config_coordinator_config_hypertune_t *cluster_config_coordinator_config_hypertune);

#endif /* _cluster_config_coordinator_config_hypertune_H_ */

