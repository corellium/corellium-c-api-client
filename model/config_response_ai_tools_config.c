#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "config_response_ai_tools_config.h"



static config_response_ai_tools_config_t *config_response_ai_tools_config_create_internal(
    int ai_enabled
    ) {
    config_response_ai_tools_config_t *config_response_ai_tools_config_local_var = malloc(sizeof(config_response_ai_tools_config_t));
    if (!config_response_ai_tools_config_local_var) {
        return NULL;
    }
    config_response_ai_tools_config_local_var->ai_enabled = ai_enabled;

    config_response_ai_tools_config_local_var->_library_owned = 1;
    return config_response_ai_tools_config_local_var;
}

__attribute__((deprecated)) config_response_ai_tools_config_t *config_response_ai_tools_config_create(
    int ai_enabled
    ) {
    return config_response_ai_tools_config_create_internal (
        ai_enabled
        );
}

void config_response_ai_tools_config_free(config_response_ai_tools_config_t *config_response_ai_tools_config) {
    if(NULL == config_response_ai_tools_config){
        return ;
    }
    if(config_response_ai_tools_config->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "config_response_ai_tools_config_free");
        return ;
    }
    listEntry_t *listEntry;
    free(config_response_ai_tools_config);
}

cJSON *config_response_ai_tools_config_convertToJSON(config_response_ai_tools_config_t *config_response_ai_tools_config) {
    cJSON *item = cJSON_CreateObject();

    // config_response_ai_tools_config->ai_enabled
    if(config_response_ai_tools_config->ai_enabled) {
    if(cJSON_AddBoolToObject(item, "aiEnabled", config_response_ai_tools_config->ai_enabled) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

config_response_ai_tools_config_t *config_response_ai_tools_config_parseFromJSON(cJSON *config_response_ai_tools_configJSON){

    config_response_ai_tools_config_t *config_response_ai_tools_config_local_var = NULL;

    // config_response_ai_tools_config->ai_enabled
    cJSON *ai_enabled = cJSON_GetObjectItemCaseSensitive(config_response_ai_tools_configJSON, "aiEnabled");
    if (cJSON_IsNull(ai_enabled)) {
        ai_enabled = NULL;
    }
    if (ai_enabled) { 
    if(!cJSON_IsBool(ai_enabled))
    {
    goto end; //Bool
    }
    }


    config_response_ai_tools_config_local_var = config_response_ai_tools_config_create_internal (
        ai_enabled ? ai_enabled->valueint : 0
        );

    return config_response_ai_tools_config_local_var;
end:
    return NULL;

}
