#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cluster_config_ai_tools_config.h"



static cluster_config_ai_tools_config_t *cluster_config_ai_tools_config_create_internal(
    int ai_enabled
    ) {
    cluster_config_ai_tools_config_t *cluster_config_ai_tools_config_local_var = malloc(sizeof(cluster_config_ai_tools_config_t));
    if (!cluster_config_ai_tools_config_local_var) {
        return NULL;
    }
    cluster_config_ai_tools_config_local_var->ai_enabled = ai_enabled;

    cluster_config_ai_tools_config_local_var->_library_owned = 1;
    return cluster_config_ai_tools_config_local_var;
}

__attribute__((deprecated)) cluster_config_ai_tools_config_t *cluster_config_ai_tools_config_create(
    int ai_enabled
    ) {
    return cluster_config_ai_tools_config_create_internal (
        ai_enabled
        );
}

void cluster_config_ai_tools_config_free(cluster_config_ai_tools_config_t *cluster_config_ai_tools_config) {
    if(NULL == cluster_config_ai_tools_config){
        return ;
    }
    if(cluster_config_ai_tools_config->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cluster_config_ai_tools_config_free");
        return ;
    }
    listEntry_t *listEntry;
    free(cluster_config_ai_tools_config);
}

cJSON *cluster_config_ai_tools_config_convertToJSON(cluster_config_ai_tools_config_t *cluster_config_ai_tools_config) {
    cJSON *item = cJSON_CreateObject();

    // cluster_config_ai_tools_config->ai_enabled
    if(cluster_config_ai_tools_config->ai_enabled) {
    if(cJSON_AddBoolToObject(item, "aiEnabled", cluster_config_ai_tools_config->ai_enabled) == NULL) {
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

cluster_config_ai_tools_config_t *cluster_config_ai_tools_config_parseFromJSON(cJSON *cluster_config_ai_tools_configJSON){

    cluster_config_ai_tools_config_t *cluster_config_ai_tools_config_local_var = NULL;

    // cluster_config_ai_tools_config->ai_enabled
    cJSON *ai_enabled = cJSON_GetObjectItemCaseSensitive(cluster_config_ai_tools_configJSON, "aiEnabled");
    if (cJSON_IsNull(ai_enabled)) {
        ai_enabled = NULL;
    }
    if (ai_enabled) { 
    if(!cJSON_IsBool(ai_enabled))
    {
    goto end; //Bool
    }
    }


    cluster_config_ai_tools_config_local_var = cluster_config_ai_tools_config_create_internal (
        ai_enabled ? ai_enabled->valueint : 0
        );

    return cluster_config_ai_tools_config_local_var;
end:
    return NULL;

}
