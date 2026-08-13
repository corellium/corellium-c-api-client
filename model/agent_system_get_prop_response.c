#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "agent_system_get_prop_response.h"



static agent_system_get_prop_response_t *agent_system_get_prop_response_create_internal(
    double id,
    int success,
    char *value
    ) {
    agent_system_get_prop_response_t *agent_system_get_prop_response_local_var = malloc(sizeof(agent_system_get_prop_response_t));
    if (!agent_system_get_prop_response_local_var) {
        return NULL;
    }
    agent_system_get_prop_response_local_var->id = id;
    agent_system_get_prop_response_local_var->success = success;
    agent_system_get_prop_response_local_var->value = value;

    agent_system_get_prop_response_local_var->_library_owned = 1;
    return agent_system_get_prop_response_local_var;
}

__attribute__((deprecated)) agent_system_get_prop_response_t *agent_system_get_prop_response_create(
    double id,
    int success,
    char *value
    ) {
    return agent_system_get_prop_response_create_internal (
        id,
        success,
        value
        );
}

void agent_system_get_prop_response_free(agent_system_get_prop_response_t *agent_system_get_prop_response) {
    if(NULL == agent_system_get_prop_response){
        return ;
    }
    if(agent_system_get_prop_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "agent_system_get_prop_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (agent_system_get_prop_response->value) {
        free(agent_system_get_prop_response->value);
        agent_system_get_prop_response->value = NULL;
    }
    free(agent_system_get_prop_response);
}

cJSON *agent_system_get_prop_response_convertToJSON(agent_system_get_prop_response_t *agent_system_get_prop_response) {
    cJSON *item = cJSON_CreateObject();

    // agent_system_get_prop_response->id
    if (!agent_system_get_prop_response->id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "id", agent_system_get_prop_response->id) == NULL) {
    goto fail; //Numeric
    }


    // agent_system_get_prop_response->success
    if (!agent_system_get_prop_response->success) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "success", agent_system_get_prop_response->success) == NULL) {
    goto fail; //Bool
    }


    // agent_system_get_prop_response->value
    if(agent_system_get_prop_response->value) {
    if(cJSON_AddStringToObject(item, "value", agent_system_get_prop_response->value) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

agent_system_get_prop_response_t *agent_system_get_prop_response_parseFromJSON(cJSON *agent_system_get_prop_responseJSON){

    agent_system_get_prop_response_t *agent_system_get_prop_response_local_var = NULL;

    // agent_system_get_prop_response->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(agent_system_get_prop_responseJSON, "id");
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

    // agent_system_get_prop_response->success
    cJSON *success = cJSON_GetObjectItemCaseSensitive(agent_system_get_prop_responseJSON, "success");
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

    // agent_system_get_prop_response->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(agent_system_get_prop_responseJSON, "value");
    if (cJSON_IsNull(value)) {
        value = NULL;
    }
    if (value) { 
    if(!cJSON_IsString(value) && !cJSON_IsNull(value))
    {
    goto end; //String
    }
    }


    agent_system_get_prop_response_local_var = agent_system_get_prop_response_create_internal (
        id->valuedouble,
        success->valueint,
        value && !cJSON_IsNull(value) ? strdup(value->valuestring) : NULL
        );

    return agent_system_get_prop_response_local_var;
end:
    return NULL;

}
