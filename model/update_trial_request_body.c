#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "update_trial_request_body.h"



static update_trial_request_body_t *update_trial_request_body_create_internal(
    double extension_days,
    double extension_hours
    ) {
    update_trial_request_body_t *update_trial_request_body_local_var = malloc(sizeof(update_trial_request_body_t));
    if (!update_trial_request_body_local_var) {
        return NULL;
    }
    update_trial_request_body_local_var->extension_days = extension_days;
    update_trial_request_body_local_var->extension_hours = extension_hours;

    update_trial_request_body_local_var->_library_owned = 1;
    return update_trial_request_body_local_var;
}

__attribute__((deprecated)) update_trial_request_body_t *update_trial_request_body_create(
    double extension_days,
    double extension_hours
    ) {
    return update_trial_request_body_create_internal (
        extension_days,
        extension_hours
        );
}

void update_trial_request_body_free(update_trial_request_body_t *update_trial_request_body) {
    if(NULL == update_trial_request_body){
        return ;
    }
    if(update_trial_request_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "update_trial_request_body_free");
        return ;
    }
    listEntry_t *listEntry;
    free(update_trial_request_body);
}

cJSON *update_trial_request_body_convertToJSON(update_trial_request_body_t *update_trial_request_body) {
    cJSON *item = cJSON_CreateObject();

    // update_trial_request_body->extension_days
    if(update_trial_request_body->extension_days) {
    if(cJSON_AddNumberToObject(item, "extensionDays", update_trial_request_body->extension_days) == NULL) {
    goto fail; //Numeric
    }
    }


    // update_trial_request_body->extension_hours
    if(update_trial_request_body->extension_hours) {
    if(cJSON_AddNumberToObject(item, "extensionHours", update_trial_request_body->extension_hours) == NULL) {
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

update_trial_request_body_t *update_trial_request_body_parseFromJSON(cJSON *update_trial_request_bodyJSON){

    update_trial_request_body_t *update_trial_request_body_local_var = NULL;

    // update_trial_request_body->extension_days
    cJSON *extension_days = cJSON_GetObjectItemCaseSensitive(update_trial_request_bodyJSON, "extensionDays");
    if (cJSON_IsNull(extension_days)) {
        extension_days = NULL;
    }
    if (extension_days) { 
    if(!cJSON_IsNumber(extension_days))
    {
    goto end; //Numeric
    }
    }

    // update_trial_request_body->extension_hours
    cJSON *extension_hours = cJSON_GetObjectItemCaseSensitive(update_trial_request_bodyJSON, "extensionHours");
    if (cJSON_IsNull(extension_hours)) {
        extension_hours = NULL;
    }
    if (extension_hours) { 
    if(!cJSON_IsNumber(extension_hours))
    {
    goto end; //Numeric
    }
    }


    update_trial_request_body_local_var = update_trial_request_body_create_internal (
        extension_days ? extension_days->valuedouble : 0,
        extension_hours ? extension_hours->valuedouble : 0
        );

    return update_trial_request_body_local_var;
end:
    return NULL;

}
