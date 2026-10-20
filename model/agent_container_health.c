#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "agent_container_health.h"



static agent_container_health_t *agent_container_health_create_internal(
    int healthy
    ) {
    agent_container_health_t *agent_container_health_local_var = malloc(sizeof(agent_container_health_t));
    if (!agent_container_health_local_var) {
        return NULL;
    }
    agent_container_health_local_var->healthy = healthy;

    agent_container_health_local_var->_library_owned = 1;
    return agent_container_health_local_var;
}

__attribute__((deprecated)) agent_container_health_t *agent_container_health_create(
    int healthy
    ) {
    return agent_container_health_create_internal (
        healthy
        );
}

void agent_container_health_free(agent_container_health_t *agent_container_health) {
    if(NULL == agent_container_health){
        return ;
    }
    if(agent_container_health->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "agent_container_health_free");
        return ;
    }
    listEntry_t *listEntry;
    free(agent_container_health);
}

cJSON *agent_container_health_convertToJSON(agent_container_health_t *agent_container_health) {
    cJSON *item = cJSON_CreateObject();

    // agent_container_health->healthy
    if (!agent_container_health->healthy) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "healthy", agent_container_health->healthy) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

agent_container_health_t *agent_container_health_parseFromJSON(cJSON *agent_container_healthJSON){

    agent_container_health_t *agent_container_health_local_var = NULL;

    // agent_container_health->healthy
    cJSON *healthy = cJSON_GetObjectItemCaseSensitive(agent_container_healthJSON, "healthy");
    if (cJSON_IsNull(healthy)) {
        healthy = NULL;
    }
    if (!healthy) {
        goto end;
    }

    
    if(!cJSON_IsBool(healthy))
    {
    goto end; //Bool
    }


    agent_container_health_local_var = agent_container_health_create_internal (
        healthy->valueint
        );

    return agent_container_health_local_var;
end:
    return NULL;

}
