#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "agent_frida_response.h"



static agent_frida_response_t *agent_frida_response_create_internal(
    double id,
    int success
    ) {
    agent_frida_response_t *agent_frida_response_local_var = malloc(sizeof(agent_frida_response_t));
    if (!agent_frida_response_local_var) {
        return NULL;
    }
    agent_frida_response_local_var->id = id;
    agent_frida_response_local_var->success = success;

    agent_frida_response_local_var->_library_owned = 1;
    return agent_frida_response_local_var;
}

__attribute__((deprecated)) agent_frida_response_t *agent_frida_response_create(
    double id,
    int success
    ) {
    return agent_frida_response_create_internal (
        id,
        success
        );
}

void agent_frida_response_free(agent_frida_response_t *agent_frida_response) {
    if(NULL == agent_frida_response){
        return ;
    }
    if(agent_frida_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "agent_frida_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(agent_frida_response);
}

cJSON *agent_frida_response_convertToJSON(agent_frida_response_t *agent_frida_response) {
    cJSON *item = cJSON_CreateObject();

    // agent_frida_response->id
    if (!agent_frida_response->id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "id", agent_frida_response->id) == NULL) {
    goto fail; //Numeric
    }


    // agent_frida_response->success
    if (!agent_frida_response->success) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "success", agent_frida_response->success) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

agent_frida_response_t *agent_frida_response_parseFromJSON(cJSON *agent_frida_responseJSON){

    agent_frida_response_t *agent_frida_response_local_var = NULL;

    // agent_frida_response->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(agent_frida_responseJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(id))
    {
    goto end; //Numeric
    }

    // agent_frida_response->success
    cJSON *success = cJSON_GetObjectItemCaseSensitive(agent_frida_responseJSON, "success");
    if (cJSON_IsNull(success)) {
        success = NULL;
    }
    if (!success) {
        goto end;
    }

    
    if(!cJSON_IsBool(success))
    {
    goto end; //Bool
    }


    agent_frida_response_local_var = agent_frida_response_create_internal (
        id->valuedouble,
        success->valueint
        );

    return agent_frida_response_local_var;
end:
    return NULL;

}
