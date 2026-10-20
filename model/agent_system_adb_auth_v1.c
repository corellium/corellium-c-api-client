#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "agent_system_adb_auth_v1.h"



static agent_system_adb_auth_v1_t *agent_system_adb_auth_v1_create_internal(
    int enabled
    ) {
    agent_system_adb_auth_v1_t *agent_system_adb_auth_v1_local_var = malloc(sizeof(agent_system_adb_auth_v1_t));
    if (!agent_system_adb_auth_v1_local_var) {
        return NULL;
    }
    agent_system_adb_auth_v1_local_var->enabled = enabled;

    agent_system_adb_auth_v1_local_var->_library_owned = 1;
    return agent_system_adb_auth_v1_local_var;
}

__attribute__((deprecated)) agent_system_adb_auth_v1_t *agent_system_adb_auth_v1_create(
    int enabled
    ) {
    return agent_system_adb_auth_v1_create_internal (
        enabled
        );
}

void agent_system_adb_auth_v1_free(agent_system_adb_auth_v1_t *agent_system_adb_auth_v1) {
    if(NULL == agent_system_adb_auth_v1){
        return ;
    }
    if(agent_system_adb_auth_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "agent_system_adb_auth_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    free(agent_system_adb_auth_v1);
}

cJSON *agent_system_adb_auth_v1_convertToJSON(agent_system_adb_auth_v1_t *agent_system_adb_auth_v1) {
    cJSON *item = cJSON_CreateObject();

    // agent_system_adb_auth_v1->enabled
    if(agent_system_adb_auth_v1->enabled) {
    if(cJSON_AddBoolToObject(item, "enabled", agent_system_adb_auth_v1->enabled) == NULL) {
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

agent_system_adb_auth_v1_t *agent_system_adb_auth_v1_parseFromJSON(cJSON *agent_system_adb_auth_v1JSON){

    agent_system_adb_auth_v1_t *agent_system_adb_auth_v1_local_var = NULL;

    // agent_system_adb_auth_v1->enabled
    cJSON *enabled = cJSON_GetObjectItemCaseSensitive(agent_system_adb_auth_v1JSON, "enabled");
    if (cJSON_IsNull(enabled)) {
        enabled = NULL;
    }
    if (enabled) { 
    if(!cJSON_IsBool(enabled))
    {
    goto end; //Bool
    }
    }


    agent_system_adb_auth_v1_local_var = agent_system_adb_auth_v1_create_internal (
        enabled ? enabled->valueint : 0
        );

    return agent_system_adb_auth_v1_local_var;
end:
    return NULL;

}
