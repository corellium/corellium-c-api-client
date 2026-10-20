#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "trial_extension_v1.h"



static trial_extension_v1_t *trial_extension_v1_create_internal(
    double duration,
    char *reason,
    int denied,
    char *denied_reason
    ) {
    trial_extension_v1_t *trial_extension_v1_local_var = malloc(sizeof(trial_extension_v1_t));
    if (!trial_extension_v1_local_var) {
        return NULL;
    }
    trial_extension_v1_local_var->duration = duration;
    trial_extension_v1_local_var->reason = reason;
    trial_extension_v1_local_var->denied = denied;
    trial_extension_v1_local_var->denied_reason = denied_reason;

    trial_extension_v1_local_var->_library_owned = 1;
    return trial_extension_v1_local_var;
}

__attribute__((deprecated)) trial_extension_v1_t *trial_extension_v1_create(
    double duration,
    char *reason,
    int denied,
    char *denied_reason
    ) {
    return trial_extension_v1_create_internal (
        duration,
        reason,
        denied,
        denied_reason
        );
}

void trial_extension_v1_free(trial_extension_v1_t *trial_extension_v1) {
    if(NULL == trial_extension_v1){
        return ;
    }
    if(trial_extension_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "trial_extension_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (trial_extension_v1->reason) {
        free(trial_extension_v1->reason);
        trial_extension_v1->reason = NULL;
    }
    if (trial_extension_v1->denied_reason) {
        free(trial_extension_v1->denied_reason);
        trial_extension_v1->denied_reason = NULL;
    }
    free(trial_extension_v1);
}

cJSON *trial_extension_v1_convertToJSON(trial_extension_v1_t *trial_extension_v1) {
    cJSON *item = cJSON_CreateObject();

    // trial_extension_v1->duration
    if(trial_extension_v1->duration) {
    if(cJSON_AddNumberToObject(item, "duration", trial_extension_v1->duration) == NULL) {
    goto fail; //Numeric
    }
    }


    // trial_extension_v1->reason
    if(trial_extension_v1->reason) {
    if(cJSON_AddStringToObject(item, "reason", trial_extension_v1->reason) == NULL) {
    goto fail; //String
    }
    }


    // trial_extension_v1->denied
    if(trial_extension_v1->denied) {
    if(cJSON_AddBoolToObject(item, "denied", trial_extension_v1->denied) == NULL) {
    goto fail; //Bool
    }
    }


    // trial_extension_v1->denied_reason
    if(trial_extension_v1->denied_reason) {
    if(cJSON_AddStringToObject(item, "deniedReason", trial_extension_v1->denied_reason) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

trial_extension_v1_t *trial_extension_v1_parseFromJSON(cJSON *trial_extension_v1JSON){

    trial_extension_v1_t *trial_extension_v1_local_var = NULL;

    // trial_extension_v1->duration
    cJSON *duration = cJSON_GetObjectItemCaseSensitive(trial_extension_v1JSON, "duration");
    if (cJSON_IsNull(duration)) {
        duration = NULL;
    }
    if (duration) { 
    if(!cJSON_IsNumber(duration))
    {
    goto end; //Numeric
    }
    }

    // trial_extension_v1->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(trial_extension_v1JSON, "reason");
    if (cJSON_IsNull(reason)) {
        reason = NULL;
    }
    if (reason) { 
    if(!cJSON_IsString(reason) && !cJSON_IsNull(reason))
    {
    goto end; //String
    }
    }

    // trial_extension_v1->denied
    cJSON *denied = cJSON_GetObjectItemCaseSensitive(trial_extension_v1JSON, "denied");
    if (cJSON_IsNull(denied)) {
        denied = NULL;
    }
    if (denied) { 
    if(!cJSON_IsBool(denied))
    {
    goto end; //Bool
    }
    }

    // trial_extension_v1->denied_reason
    cJSON *denied_reason = cJSON_GetObjectItemCaseSensitive(trial_extension_v1JSON, "deniedReason");
    if (cJSON_IsNull(denied_reason)) {
        denied_reason = NULL;
    }
    if (denied_reason) { 
    if(!cJSON_IsString(denied_reason) && !cJSON_IsNull(denied_reason))
    {
    goto end; //String
    }
    }


    trial_extension_v1_local_var = trial_extension_v1_create_internal (
        duration ? duration->valuedouble : 0,
        reason && !cJSON_IsNull(reason) ? strdup(reason->valuestring) : NULL,
        denied ? denied->valueint : 0,
        denied_reason && !cJSON_IsNull(denied_reason) ? strdup(denied_reason->valuestring) : NULL
        );

    return trial_extension_v1_local_var;
end:
    return NULL;

}
