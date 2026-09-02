#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ai_tools_config.h"



static ai_tools_config_t *ai_tools_config_create_internal(
    int ai_enabled
    ) {
    ai_tools_config_t *ai_tools_config_local_var = malloc(sizeof(ai_tools_config_t));
    if (!ai_tools_config_local_var) {
        return NULL;
    }
    ai_tools_config_local_var->ai_enabled = ai_enabled;

    ai_tools_config_local_var->_library_owned = 1;
    return ai_tools_config_local_var;
}

__attribute__((deprecated)) ai_tools_config_t *ai_tools_config_create(
    int ai_enabled
    ) {
    return ai_tools_config_create_internal (
        ai_enabled
        );
}

void ai_tools_config_free(ai_tools_config_t *ai_tools_config) {
    if(NULL == ai_tools_config){
        return ;
    }
    if(ai_tools_config->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ai_tools_config_free");
        return ;
    }
    listEntry_t *listEntry;
    free(ai_tools_config);
}

cJSON *ai_tools_config_convertToJSON(ai_tools_config_t *ai_tools_config) {
    cJSON *item = cJSON_CreateObject();

    // ai_tools_config->ai_enabled
    if(ai_tools_config->ai_enabled) {
    if(cJSON_AddBoolToObject(item, "aiEnabled", ai_tools_config->ai_enabled) == NULL) {
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

ai_tools_config_t *ai_tools_config_parseFromJSON(cJSON *ai_tools_configJSON){

    ai_tools_config_t *ai_tools_config_local_var = NULL;

    // ai_tools_config->ai_enabled
    cJSON *ai_enabled = cJSON_GetObjectItemCaseSensitive(ai_tools_configJSON, "aiEnabled");
    if (cJSON_IsNull(ai_enabled)) {
        ai_enabled = NULL;
    }
    if (ai_enabled) { 
    if(!cJSON_IsBool(ai_enabled))
    {
    goto end; //Bool
    }
    }


    ai_tools_config_local_var = ai_tools_config_create_internal (
        ai_enabled ? ai_enabled->valueint : 0
        );

    return ai_tools_config_local_var;
end:
    return NULL;

}
