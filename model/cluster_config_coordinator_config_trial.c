#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cluster_config_coordinator_config_trial.h"



static cluster_config_coordinator_config_trial_t *cluster_config_coordinator_config_trial_create_internal(
    double default_duration,
    double default_hours,
    double default_devices,
    double default_cores
    ) {
    cluster_config_coordinator_config_trial_t *cluster_config_coordinator_config_trial_local_var = malloc(sizeof(cluster_config_coordinator_config_trial_t));
    if (!cluster_config_coordinator_config_trial_local_var) {
        return NULL;
    }
    cluster_config_coordinator_config_trial_local_var->default_duration = default_duration;
    cluster_config_coordinator_config_trial_local_var->default_hours = default_hours;
    cluster_config_coordinator_config_trial_local_var->default_devices = default_devices;
    cluster_config_coordinator_config_trial_local_var->default_cores = default_cores;

    cluster_config_coordinator_config_trial_local_var->_library_owned = 1;
    return cluster_config_coordinator_config_trial_local_var;
}

__attribute__((deprecated)) cluster_config_coordinator_config_trial_t *cluster_config_coordinator_config_trial_create(
    double default_duration,
    double default_hours,
    double default_devices,
    double default_cores
    ) {
    return cluster_config_coordinator_config_trial_create_internal (
        default_duration,
        default_hours,
        default_devices,
        default_cores
        );
}

void cluster_config_coordinator_config_trial_free(cluster_config_coordinator_config_trial_t *cluster_config_coordinator_config_trial) {
    if(NULL == cluster_config_coordinator_config_trial){
        return ;
    }
    if(cluster_config_coordinator_config_trial->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cluster_config_coordinator_config_trial_free");
        return ;
    }
    listEntry_t *listEntry;
    free(cluster_config_coordinator_config_trial);
}

cJSON *cluster_config_coordinator_config_trial_convertToJSON(cluster_config_coordinator_config_trial_t *cluster_config_coordinator_config_trial) {
    cJSON *item = cJSON_CreateObject();

    // cluster_config_coordinator_config_trial->default_duration
    if (!cluster_config_coordinator_config_trial->default_duration) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "defaultDuration", cluster_config_coordinator_config_trial->default_duration) == NULL) {
    goto fail; //Numeric
    }


    // cluster_config_coordinator_config_trial->default_hours
    if (!cluster_config_coordinator_config_trial->default_hours) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "defaultHours", cluster_config_coordinator_config_trial->default_hours) == NULL) {
    goto fail; //Numeric
    }


    // cluster_config_coordinator_config_trial->default_devices
    if (!cluster_config_coordinator_config_trial->default_devices) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "defaultDevices", cluster_config_coordinator_config_trial->default_devices) == NULL) {
    goto fail; //Numeric
    }


    // cluster_config_coordinator_config_trial->default_cores
    if (!cluster_config_coordinator_config_trial->default_cores) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "defaultCores", cluster_config_coordinator_config_trial->default_cores) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

cluster_config_coordinator_config_trial_t *cluster_config_coordinator_config_trial_parseFromJSON(cJSON *cluster_config_coordinator_config_trialJSON){

    cluster_config_coordinator_config_trial_t *cluster_config_coordinator_config_trial_local_var = NULL;

    // cluster_config_coordinator_config_trial->default_duration
    cJSON *default_duration = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_config_trialJSON, "defaultDuration");
    if (cJSON_IsNull(default_duration)) {
        default_duration = NULL;
    }
    if (!default_duration) {
        goto end;
    }

    
    if(!cJSON_IsNumber(default_duration))
    {
    goto end; //Numeric
    }

    // cluster_config_coordinator_config_trial->default_hours
    cJSON *default_hours = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_config_trialJSON, "defaultHours");
    if (cJSON_IsNull(default_hours)) {
        default_hours = NULL;
    }
    if (!default_hours) {
        goto end;
    }

    
    if(!cJSON_IsNumber(default_hours))
    {
    goto end; //Numeric
    }

    // cluster_config_coordinator_config_trial->default_devices
    cJSON *default_devices = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_config_trialJSON, "defaultDevices");
    if (cJSON_IsNull(default_devices)) {
        default_devices = NULL;
    }
    if (!default_devices) {
        goto end;
    }

    
    if(!cJSON_IsNumber(default_devices))
    {
    goto end; //Numeric
    }

    // cluster_config_coordinator_config_trial->default_cores
    cJSON *default_cores = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_config_trialJSON, "defaultCores");
    if (cJSON_IsNull(default_cores)) {
        default_cores = NULL;
    }
    if (!default_cores) {
        goto end;
    }

    
    if(!cJSON_IsNumber(default_cores))
    {
    goto end; //Numeric
    }


    cluster_config_coordinator_config_trial_local_var = cluster_config_coordinator_config_trial_create_internal (
        default_duration->valuedouble,
        default_hours->valuedouble,
        default_devices->valuedouble,
        default_cores->valuedouble
        );

    return cluster_config_coordinator_config_trial_local_var;
end:
    return NULL;

}
