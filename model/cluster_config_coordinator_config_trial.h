/*
 * cluster_config_coordinator_config_trial.h
 *
 * 
 */

#ifndef _cluster_config_coordinator_config_trial_H_
#define _cluster_config_coordinator_config_trial_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cluster_config_coordinator_config_trial_t cluster_config_coordinator_config_trial_t;




typedef struct cluster_config_coordinator_config_trial_t {
    double default_duration; //numeric
    double default_hours; //numeric
    double default_devices; //numeric
    double default_cores; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} cluster_config_coordinator_config_trial_t;

__attribute__((deprecated)) cluster_config_coordinator_config_trial_t *cluster_config_coordinator_config_trial_create(
    double default_duration,
    double default_hours,
    double default_devices,
    double default_cores
);

void cluster_config_coordinator_config_trial_free(cluster_config_coordinator_config_trial_t *cluster_config_coordinator_config_trial);

cluster_config_coordinator_config_trial_t *cluster_config_coordinator_config_trial_parseFromJSON(cJSON *cluster_config_coordinator_config_trialJSON);

cJSON *cluster_config_coordinator_config_trial_convertToJSON(cluster_config_coordinator_config_trial_t *cluster_config_coordinator_config_trial);

#endif /* _cluster_config_coordinator_config_trial_H_ */

