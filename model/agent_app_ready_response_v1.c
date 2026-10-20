#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "agent_app_ready_response_v1.h"



static agent_app_ready_response_v1_t *agent_app_ready_response_v1_create_internal(
    int ready
    ) {
    agent_app_ready_response_v1_t *agent_app_ready_response_v1_local_var = malloc(sizeof(agent_app_ready_response_v1_t));
    if (!agent_app_ready_response_v1_local_var) {
        return NULL;
    }
    agent_app_ready_response_v1_local_var->ready = ready;

    agent_app_ready_response_v1_local_var->_library_owned = 1;
    return agent_app_ready_response_v1_local_var;
}

__attribute__((deprecated)) agent_app_ready_response_v1_t *agent_app_ready_response_v1_create(
    int ready
    ) {
    return agent_app_ready_response_v1_create_internal (
        ready
        );
}

void agent_app_ready_response_v1_free(agent_app_ready_response_v1_t *agent_app_ready_response_v1) {
    if(NULL == agent_app_ready_response_v1){
        return ;
    }
    if(agent_app_ready_response_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "agent_app_ready_response_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    free(agent_app_ready_response_v1);
}

cJSON *agent_app_ready_response_v1_convertToJSON(agent_app_ready_response_v1_t *agent_app_ready_response_v1) {
    cJSON *item = cJSON_CreateObject();

    // agent_app_ready_response_v1->ready
    if (!agent_app_ready_response_v1->ready) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ready", agent_app_ready_response_v1->ready) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

agent_app_ready_response_v1_t *agent_app_ready_response_v1_parseFromJSON(cJSON *agent_app_ready_response_v1JSON){

    agent_app_ready_response_v1_t *agent_app_ready_response_v1_local_var = NULL;

    // agent_app_ready_response_v1->ready
    cJSON *ready = cJSON_GetObjectItemCaseSensitive(agent_app_ready_response_v1JSON, "ready");
    if (cJSON_IsNull(ready)) {
        ready = NULL;
    }
    if (!ready) {
        goto end;
    }

    
    if(!cJSON_IsBool(ready))
    {
    goto end; //Bool
    }


    agent_app_ready_response_v1_local_var = agent_app_ready_response_v1_create_internal (
        ready->valueint
        );

    return agent_app_ready_response_v1_local_var;
end:
    return NULL;

}
