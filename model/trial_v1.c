#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "trial_v1.h"



static trial_v1_t *trial_v1_create_internal(
    double default_duration,
    double default_hours,
    double default_devices,
    double default_cores
    ) {
    trial_v1_t *trial_v1_local_var = malloc(sizeof(trial_v1_t));
    if (!trial_v1_local_var) {
        return NULL;
    }
    trial_v1_local_var->default_duration = default_duration;
    trial_v1_local_var->default_hours = default_hours;
    trial_v1_local_var->default_devices = default_devices;
    trial_v1_local_var->default_cores = default_cores;

    trial_v1_local_var->_library_owned = 1;
    return trial_v1_local_var;
}

__attribute__((deprecated)) trial_v1_t *trial_v1_create(
    double default_duration,
    double default_hours,
    double default_devices,
    double default_cores
    ) {
    return trial_v1_create_internal (
        default_duration,
        default_hours,
        default_devices,
        default_cores
        );
}

void trial_v1_free(trial_v1_t *trial_v1) {
    if(NULL == trial_v1){
        return ;
    }
    if(trial_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "trial_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    free(trial_v1);
}

cJSON *trial_v1_convertToJSON(trial_v1_t *trial_v1) {
    cJSON *item = cJSON_CreateObject();

    // trial_v1->default_duration
    if(trial_v1->default_duration) {
    if(cJSON_AddNumberToObject(item, "defaultDuration", trial_v1->default_duration) == NULL) {
    goto fail; //Numeric
    }
    }


    // trial_v1->default_hours
    if(trial_v1->default_hours) {
    if(cJSON_AddNumberToObject(item, "defaultHours", trial_v1->default_hours) == NULL) {
    goto fail; //Numeric
    }
    }


    // trial_v1->default_devices
    if(trial_v1->default_devices) {
    if(cJSON_AddNumberToObject(item, "defaultDevices", trial_v1->default_devices) == NULL) {
    goto fail; //Numeric
    }
    }


    // trial_v1->default_cores
    if(trial_v1->default_cores) {
    if(cJSON_AddNumberToObject(item, "defaultCores", trial_v1->default_cores) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

trial_v1_t *trial_v1_parseFromJSON(cJSON *trial_v1JSON){

    trial_v1_t *trial_v1_local_var = NULL;

    // trial_v1->default_duration
    cJSON *default_duration = cJSON_GetObjectItemCaseSensitive(trial_v1JSON, "defaultDuration");
    if (cJSON_IsNull(default_duration)) {
        default_duration = NULL;
    }
    if (default_duration) { 
    if(!cJSON_IsNumber(default_duration))
    {
    goto end; //Numeric
    }
    }

    // trial_v1->default_hours
    cJSON *default_hours = cJSON_GetObjectItemCaseSensitive(trial_v1JSON, "defaultHours");
    if (cJSON_IsNull(default_hours)) {
        default_hours = NULL;
    }
    if (default_hours) { 
    if(!cJSON_IsNumber(default_hours))
    {
    goto end; //Numeric
    }
    }

    // trial_v1->default_devices
    cJSON *default_devices = cJSON_GetObjectItemCaseSensitive(trial_v1JSON, "defaultDevices");
    if (cJSON_IsNull(default_devices)) {
        default_devices = NULL;
    }
    if (default_devices) { 
    if(!cJSON_IsNumber(default_devices))
    {
    goto end; //Numeric
    }
    }

    // trial_v1->default_cores
    cJSON *default_cores = cJSON_GetObjectItemCaseSensitive(trial_v1JSON, "defaultCores");
    if (cJSON_IsNull(default_cores)) {
        default_cores = NULL;
    }
    if (default_cores) { 
    if(!cJSON_IsNumber(default_cores))
    {
    goto end; //Numeric
    }
    }


    trial_v1_local_var = trial_v1_create_internal (
        default_duration ? default_duration->valuedouble : 0,
        default_hours ? default_hours->valuedouble : 0,
        default_devices ? default_devices->valuedouble : 0,
        default_cores ? default_cores->valuedouble : 0
        );

    return trial_v1_local_var;
end:
    return NULL;

}
