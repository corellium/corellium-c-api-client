#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "update_trial_request_params.h"



static update_trial_request_params_t *update_trial_request_params_create_internal(
    double extension_days,
    double extension_hours
    ) {
    update_trial_request_params_t *update_trial_request_params_local_var = malloc(sizeof(update_trial_request_params_t));
    if (!update_trial_request_params_local_var) {
        return NULL;
    }
    update_trial_request_params_local_var->extension_days = extension_days;
    update_trial_request_params_local_var->extension_hours = extension_hours;

    update_trial_request_params_local_var->_library_owned = 1;
    return update_trial_request_params_local_var;
}

__attribute__((deprecated)) update_trial_request_params_t *update_trial_request_params_create(
    double extension_days,
    double extension_hours
    ) {
    return update_trial_request_params_create_internal (
        extension_days,
        extension_hours
        );
}

void update_trial_request_params_free(update_trial_request_params_t *update_trial_request_params) {
    if(NULL == update_trial_request_params){
        return ;
    }
    if(update_trial_request_params->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "update_trial_request_params_free");
        return ;
    }
    listEntry_t *listEntry;
    free(update_trial_request_params);
}

cJSON *update_trial_request_params_convertToJSON(update_trial_request_params_t *update_trial_request_params) {
    cJSON *item = cJSON_CreateObject();

    // update_trial_request_params->extension_days
    if(update_trial_request_params->extension_days) {
    if(cJSON_AddNumberToObject(item, "extensionDays", update_trial_request_params->extension_days) == NULL) {
    goto fail; //Numeric
    }
    }


    // update_trial_request_params->extension_hours
    if(update_trial_request_params->extension_hours) {
    if(cJSON_AddNumberToObject(item, "extensionHours", update_trial_request_params->extension_hours) == NULL) {
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

update_trial_request_params_t *update_trial_request_params_parseFromJSON(cJSON *update_trial_request_paramsJSON){

    update_trial_request_params_t *update_trial_request_params_local_var = NULL;

    // update_trial_request_params->extension_days
    cJSON *extension_days = cJSON_GetObjectItemCaseSensitive(update_trial_request_paramsJSON, "extensionDays");
    if (cJSON_IsNull(extension_days)) {
        extension_days = NULL;
    }
    if (extension_days) { 
    if(!cJSON_IsNumber(extension_days))
    {
    goto end; //Numeric
    }
    }

    // update_trial_request_params->extension_hours
    cJSON *extension_hours = cJSON_GetObjectItemCaseSensitive(update_trial_request_paramsJSON, "extensionHours");
    if (cJSON_IsNull(extension_hours)) {
        extension_hours = NULL;
    }
    if (extension_hours) { 
    if(!cJSON_IsNumber(extension_hours))
    {
    goto end; //Numeric
    }
    }


    update_trial_request_params_local_var = update_trial_request_params_create_internal (
        extension_days ? extension_days->valuedouble : 0,
        extension_hours ? extension_hours->valuedouble : 0
        );

    return update_trial_request_params_local_var;
end:
    return NULL;

}
