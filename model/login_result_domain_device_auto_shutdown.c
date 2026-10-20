#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "login_result_domain_device_auto_shutdown.h"



static login_result_domain_device_auto_shutdown_t *login_result_domain_device_auto_shutdown_create_internal(
    int enabled,
    double threshold
    ) {
    login_result_domain_device_auto_shutdown_t *login_result_domain_device_auto_shutdown_local_var = malloc(sizeof(login_result_domain_device_auto_shutdown_t));
    if (!login_result_domain_device_auto_shutdown_local_var) {
        return NULL;
    }
    login_result_domain_device_auto_shutdown_local_var->enabled = enabled;
    login_result_domain_device_auto_shutdown_local_var->threshold = threshold;

    login_result_domain_device_auto_shutdown_local_var->_library_owned = 1;
    return login_result_domain_device_auto_shutdown_local_var;
}

__attribute__((deprecated)) login_result_domain_device_auto_shutdown_t *login_result_domain_device_auto_shutdown_create(
    int enabled,
    double threshold
    ) {
    return login_result_domain_device_auto_shutdown_create_internal (
        enabled,
        threshold
        );
}

void login_result_domain_device_auto_shutdown_free(login_result_domain_device_auto_shutdown_t *login_result_domain_device_auto_shutdown) {
    if(NULL == login_result_domain_device_auto_shutdown){
        return ;
    }
    if(login_result_domain_device_auto_shutdown->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "login_result_domain_device_auto_shutdown_free");
        return ;
    }
    listEntry_t *listEntry;
    free(login_result_domain_device_auto_shutdown);
}

cJSON *login_result_domain_device_auto_shutdown_convertToJSON(login_result_domain_device_auto_shutdown_t *login_result_domain_device_auto_shutdown) {
    cJSON *item = cJSON_CreateObject();

    // login_result_domain_device_auto_shutdown->enabled
    if(login_result_domain_device_auto_shutdown->enabled) {
    if(cJSON_AddBoolToObject(item, "enabled", login_result_domain_device_auto_shutdown->enabled) == NULL) {
    goto fail; //Bool
    }
    }


    // login_result_domain_device_auto_shutdown->threshold
    if(login_result_domain_device_auto_shutdown->threshold) {
    if(cJSON_AddNumberToObject(item, "threshold", login_result_domain_device_auto_shutdown->threshold) == NULL) {
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

login_result_domain_device_auto_shutdown_t *login_result_domain_device_auto_shutdown_parseFromJSON(cJSON *login_result_domain_device_auto_shutdownJSON){

    login_result_domain_device_auto_shutdown_t *login_result_domain_device_auto_shutdown_local_var = NULL;

    // login_result_domain_device_auto_shutdown->enabled
    cJSON *enabled = cJSON_GetObjectItemCaseSensitive(login_result_domain_device_auto_shutdownJSON, "enabled");
    if (cJSON_IsNull(enabled)) {
        enabled = NULL;
    }
    if (enabled) { 
    if(!cJSON_IsBool(enabled))
    {
    goto end; //Bool
    }
    }

    // login_result_domain_device_auto_shutdown->threshold
    cJSON *threshold = cJSON_GetObjectItemCaseSensitive(login_result_domain_device_auto_shutdownJSON, "threshold");
    if (cJSON_IsNull(threshold)) {
        threshold = NULL;
    }
    if (threshold) { 
    if(!cJSON_IsNumber(threshold))
    {
    goto end; //Numeric
    }
    }


    login_result_domain_device_auto_shutdown_local_var = login_result_domain_device_auto_shutdown_create_internal (
        enabled ? enabled->valueint : 0,
        threshold ? threshold->valuedouble : 0
        );

    return login_result_domain_device_auto_shutdown_local_var;
end:
    return NULL;

}
