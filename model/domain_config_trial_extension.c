#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "domain_config_trial_extension.h"



static domain_config_trial_extension_t *domain_config_trial_extension_create_internal(
    double duration,
    char *reason,
    int denied,
    char *denied_reason
    ) {
    domain_config_trial_extension_t *domain_config_trial_extension_local_var = malloc(sizeof(domain_config_trial_extension_t));
    if (!domain_config_trial_extension_local_var) {
        return NULL;
    }
    domain_config_trial_extension_local_var->duration = duration;
    domain_config_trial_extension_local_var->reason = reason;
    domain_config_trial_extension_local_var->denied = denied;
    domain_config_trial_extension_local_var->denied_reason = denied_reason;

    domain_config_trial_extension_local_var->_library_owned = 1;
    return domain_config_trial_extension_local_var;
}

__attribute__((deprecated)) domain_config_trial_extension_t *domain_config_trial_extension_create(
    double duration,
    char *reason,
    int denied,
    char *denied_reason
    ) {
    return domain_config_trial_extension_create_internal (
        duration,
        reason,
        denied,
        denied_reason
        );
}

void domain_config_trial_extension_free(domain_config_trial_extension_t *domain_config_trial_extension) {
    if(NULL == domain_config_trial_extension){
        return ;
    }
    if(domain_config_trial_extension->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "domain_config_trial_extension_free");
        return ;
    }
    listEntry_t *listEntry;
    if (domain_config_trial_extension->reason) {
        free(domain_config_trial_extension->reason);
        domain_config_trial_extension->reason = NULL;
    }
    if (domain_config_trial_extension->denied_reason) {
        free(domain_config_trial_extension->denied_reason);
        domain_config_trial_extension->denied_reason = NULL;
    }
    free(domain_config_trial_extension);
}

cJSON *domain_config_trial_extension_convertToJSON(domain_config_trial_extension_t *domain_config_trial_extension) {
    cJSON *item = cJSON_CreateObject();

    // domain_config_trial_extension->duration
    if (!domain_config_trial_extension->duration) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "duration", domain_config_trial_extension->duration) == NULL) {
    goto fail; //Numeric
    }


    // domain_config_trial_extension->reason
    if(domain_config_trial_extension->reason) {
    if(cJSON_AddStringToObject(item, "reason", domain_config_trial_extension->reason) == NULL) {
    goto fail; //String
    }
    }


    // domain_config_trial_extension->denied
    if(domain_config_trial_extension->denied) {
    if(cJSON_AddBoolToObject(item, "denied", domain_config_trial_extension->denied) == NULL) {
    goto fail; //Bool
    }
    }


    // domain_config_trial_extension->denied_reason
    if(domain_config_trial_extension->denied_reason) {
    if(cJSON_AddStringToObject(item, "deniedReason", domain_config_trial_extension->denied_reason) == NULL) {
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

domain_config_trial_extension_t *domain_config_trial_extension_parseFromJSON(cJSON *domain_config_trial_extensionJSON){

    domain_config_trial_extension_t *domain_config_trial_extension_local_var = NULL;

    // domain_config_trial_extension->duration
    cJSON *duration = cJSON_GetObjectItemCaseSensitive(domain_config_trial_extensionJSON, "duration");
    if (cJSON_IsNull(duration)) {
        duration = NULL;
    }
    if (!duration) {
        goto end;
    }

    
    if(!cJSON_IsNumber(duration))
    {
    goto end; //Numeric
    }

    // domain_config_trial_extension->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(domain_config_trial_extensionJSON, "reason");
    if (cJSON_IsNull(reason)) {
        reason = NULL;
    }
    if (reason) { 
    if(!cJSON_IsString(reason) && !cJSON_IsNull(reason))
    {
    goto end; //String
    }
    }

    // domain_config_trial_extension->denied
    cJSON *denied = cJSON_GetObjectItemCaseSensitive(domain_config_trial_extensionJSON, "denied");
    if (cJSON_IsNull(denied)) {
        denied = NULL;
    }
    if (denied) { 
    if(!cJSON_IsBool(denied))
    {
    goto end; //Bool
    }
    }

    // domain_config_trial_extension->denied_reason
    cJSON *denied_reason = cJSON_GetObjectItemCaseSensitive(domain_config_trial_extensionJSON, "deniedReason");
    if (cJSON_IsNull(denied_reason)) {
        denied_reason = NULL;
    }
    if (denied_reason) { 
    if(!cJSON_IsString(denied_reason) && !cJSON_IsNull(denied_reason))
    {
    goto end; //String
    }
    }


    domain_config_trial_extension_local_var = domain_config_trial_extension_create_internal (
        duration->valuedouble,
        reason && !cJSON_IsNull(reason) ? strdup(reason->valuestring) : NULL,
        denied ? denied->valueint : 0,
        denied_reason && !cJSON_IsNull(denied_reason) ? strdup(denied_reason->valuestring) : NULL
        );

    return domain_config_trial_extension_local_var;
end:
    return NULL;

}
