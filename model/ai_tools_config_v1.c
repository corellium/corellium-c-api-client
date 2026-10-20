#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ai_tools_config_v1.h"



static ai_tools_config_v1_t *ai_tools_config_v1_create_internal(
    int ai_enabled
    ) {
    ai_tools_config_v1_t *ai_tools_config_v1_local_var = malloc(sizeof(ai_tools_config_v1_t));
    if (!ai_tools_config_v1_local_var) {
        return NULL;
    }
    ai_tools_config_v1_local_var->ai_enabled = ai_enabled;

    ai_tools_config_v1_local_var->_library_owned = 1;
    return ai_tools_config_v1_local_var;
}

__attribute__((deprecated)) ai_tools_config_v1_t *ai_tools_config_v1_create(
    int ai_enabled
    ) {
    return ai_tools_config_v1_create_internal (
        ai_enabled
        );
}

void ai_tools_config_v1_free(ai_tools_config_v1_t *ai_tools_config_v1) {
    if(NULL == ai_tools_config_v1){
        return ;
    }
    if(ai_tools_config_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ai_tools_config_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    free(ai_tools_config_v1);
}

cJSON *ai_tools_config_v1_convertToJSON(ai_tools_config_v1_t *ai_tools_config_v1) {
    cJSON *item = cJSON_CreateObject();

    // ai_tools_config_v1->ai_enabled
    if(ai_tools_config_v1->ai_enabled) {
    if(cJSON_AddBoolToObject(item, "aiEnabled", ai_tools_config_v1->ai_enabled) == NULL) {
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

ai_tools_config_v1_t *ai_tools_config_v1_parseFromJSON(cJSON *ai_tools_config_v1JSON){

    ai_tools_config_v1_t *ai_tools_config_v1_local_var = NULL;

    // ai_tools_config_v1->ai_enabled
    cJSON *ai_enabled = cJSON_GetObjectItemCaseSensitive(ai_tools_config_v1JSON, "aiEnabled");
    if (cJSON_IsNull(ai_enabled)) {
        ai_enabled = NULL;
    }
    if (ai_enabled) { 
    if(!cJSON_IsBool(ai_enabled))
    {
    goto end; //Bool
    }
    }


    ai_tools_config_v1_local_var = ai_tools_config_v1_create_internal (
        ai_enabled ? ai_enabled->valueint : 0
        );

    return ai_tools_config_v1_local_var;
end:
    return NULL;

}
