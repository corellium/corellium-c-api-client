#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "trial.h"



static trial_t *trial_create_internal(
    double default_duration,
    double default_hours,
    double default_devices,
    double default_cores
    ) {
    trial_t *trial_local_var = malloc(sizeof(trial_t));
    if (!trial_local_var) {
        return NULL;
    }
    trial_local_var->default_duration = default_duration;
    trial_local_var->default_hours = default_hours;
    trial_local_var->default_devices = default_devices;
    trial_local_var->default_cores = default_cores;

    trial_local_var->_library_owned = 1;
    return trial_local_var;
}

__attribute__((deprecated)) trial_t *trial_create(
    double default_duration,
    double default_hours,
    double default_devices,
    double default_cores
    ) {
    return trial_create_internal (
        default_duration,
        default_hours,
        default_devices,
        default_cores
        );
}

void trial_free(trial_t *trial) {
    if(NULL == trial){
        return ;
    }
    if(trial->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "trial_free");
        return ;
    }
    listEntry_t *listEntry;
    free(trial);
}

cJSON *trial_convertToJSON(trial_t *trial) {
    cJSON *item = cJSON_CreateObject();

    // trial->default_duration
    if (!trial->default_duration) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "defaultDuration", trial->default_duration) == NULL) {
    goto fail; //Numeric
    }


    // trial->default_hours
    if (!trial->default_hours) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "defaultHours", trial->default_hours) == NULL) {
    goto fail; //Numeric
    }


    // trial->default_devices
    if (!trial->default_devices) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "defaultDevices", trial->default_devices) == NULL) {
    goto fail; //Numeric
    }


    // trial->default_cores
    if (!trial->default_cores) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "defaultCores", trial->default_cores) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

trial_t *trial_parseFromJSON(cJSON *trialJSON){

    trial_t *trial_local_var = NULL;

    // trial->default_duration
    cJSON *default_duration = cJSON_GetObjectItemCaseSensitive(trialJSON, "defaultDuration");
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

    // trial->default_hours
    cJSON *default_hours = cJSON_GetObjectItemCaseSensitive(trialJSON, "defaultHours");
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

    // trial->default_devices
    cJSON *default_devices = cJSON_GetObjectItemCaseSensitive(trialJSON, "defaultDevices");
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

    // trial->default_cores
    cJSON *default_cores = cJSON_GetObjectItemCaseSensitive(trialJSON, "defaultCores");
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


    trial_local_var = trial_create_internal (
        default_duration->valuedouble,
        default_hours->valuedouble,
        default_devices->valuedouble,
        default_cores->valuedouble
        );

    return trial_local_var;
end:
    return NULL;

}
