#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "patch_cluster_config_body_ai_tools_config.h"



static patch_cluster_config_body_ai_tools_config_t *patch_cluster_config_body_ai_tools_config_create_internal(
    int ai_enabled
    ) {
    patch_cluster_config_body_ai_tools_config_t *patch_cluster_config_body_ai_tools_config_local_var = malloc(sizeof(patch_cluster_config_body_ai_tools_config_t));
    if (!patch_cluster_config_body_ai_tools_config_local_var) {
        return NULL;
    }
    patch_cluster_config_body_ai_tools_config_local_var->ai_enabled = ai_enabled;

    patch_cluster_config_body_ai_tools_config_local_var->_library_owned = 1;
    return patch_cluster_config_body_ai_tools_config_local_var;
}

__attribute__((deprecated)) patch_cluster_config_body_ai_tools_config_t *patch_cluster_config_body_ai_tools_config_create(
    int ai_enabled
    ) {
    return patch_cluster_config_body_ai_tools_config_create_internal (
        ai_enabled
        );
}

void patch_cluster_config_body_ai_tools_config_free(patch_cluster_config_body_ai_tools_config_t *patch_cluster_config_body_ai_tools_config) {
    if(NULL == patch_cluster_config_body_ai_tools_config){
        return ;
    }
    if(patch_cluster_config_body_ai_tools_config->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "patch_cluster_config_body_ai_tools_config_free");
        return ;
    }
    listEntry_t *listEntry;
    free(patch_cluster_config_body_ai_tools_config);
}

cJSON *patch_cluster_config_body_ai_tools_config_convertToJSON(patch_cluster_config_body_ai_tools_config_t *patch_cluster_config_body_ai_tools_config) {
    cJSON *item = cJSON_CreateObject();

    // patch_cluster_config_body_ai_tools_config->ai_enabled
    if(patch_cluster_config_body_ai_tools_config->ai_enabled) {
    if(cJSON_AddBoolToObject(item, "aiEnabled", patch_cluster_config_body_ai_tools_config->ai_enabled) == NULL) {
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

patch_cluster_config_body_ai_tools_config_t *patch_cluster_config_body_ai_tools_config_parseFromJSON(cJSON *patch_cluster_config_body_ai_tools_configJSON){

    patch_cluster_config_body_ai_tools_config_t *patch_cluster_config_body_ai_tools_config_local_var = NULL;

    // patch_cluster_config_body_ai_tools_config->ai_enabled
    cJSON *ai_enabled = cJSON_GetObjectItemCaseSensitive(patch_cluster_config_body_ai_tools_configJSON, "aiEnabled");
    if (cJSON_IsNull(ai_enabled)) {
        ai_enabled = NULL;
    }
    if (ai_enabled) { 
    if(!cJSON_IsBool(ai_enabled))
    {
    goto end; //Bool
    }
    }


    patch_cluster_config_body_ai_tools_config_local_var = patch_cluster_config_body_ai_tools_config_create_internal (
        ai_enabled ? ai_enabled->valueint : 0
        );

    return patch_cluster_config_body_ai_tools_config_local_var;
end:
    return NULL;

}
