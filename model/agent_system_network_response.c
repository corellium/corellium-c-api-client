#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "agent_system_network_response.h"



static agent_system_network_response_t *agent_system_network_response_create_internal(
    char *value
    ) {
    agent_system_network_response_t *agent_system_network_response_local_var = malloc(sizeof(agent_system_network_response_t));
    if (!agent_system_network_response_local_var) {
        return NULL;
    }
    agent_system_network_response_local_var->value = value;

    agent_system_network_response_local_var->_library_owned = 1;
    return agent_system_network_response_local_var;
}

__attribute__((deprecated)) agent_system_network_response_t *agent_system_network_response_create(
    char *value
    ) {
    return agent_system_network_response_create_internal (
        value
        );
}

void agent_system_network_response_free(agent_system_network_response_t *agent_system_network_response) {
    if(NULL == agent_system_network_response){
        return ;
    }
    if(agent_system_network_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "agent_system_network_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (agent_system_network_response->value) {
        free(agent_system_network_response->value);
        agent_system_network_response->value = NULL;
    }
    free(agent_system_network_response);
}

cJSON *agent_system_network_response_convertToJSON(agent_system_network_response_t *agent_system_network_response) {
    cJSON *item = cJSON_CreateObject();

    // agent_system_network_response->value
    if (!agent_system_network_response->value) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "value", agent_system_network_response->value) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

agent_system_network_response_t *agent_system_network_response_parseFromJSON(cJSON *agent_system_network_responseJSON){

    agent_system_network_response_t *agent_system_network_response_local_var = NULL;

    // agent_system_network_response->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(agent_system_network_responseJSON, "value");
    if (cJSON_IsNull(value)) {
        value = NULL;
    }
    if (!value) {
        goto end;
    }

    
    if(!cJSON_IsString(value))
    {
    goto end; //String
    }


    agent_system_network_response_local_var = agent_system_network_response_create_internal (
        strdup(value->valuestring)
        );

    return agent_system_network_response_local_var;
end:
    return NULL;

}
