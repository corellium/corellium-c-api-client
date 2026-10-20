#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "agent_system_result.h"



static agent_system_result_t *agent_system_result_create_internal(
    double id,
    int success
    ) {
    agent_system_result_t *agent_system_result_local_var = malloc(sizeof(agent_system_result_t));
    if (!agent_system_result_local_var) {
        return NULL;
    }
    agent_system_result_local_var->id = id;
    agent_system_result_local_var->success = success;

    agent_system_result_local_var->_library_owned = 1;
    return agent_system_result_local_var;
}

__attribute__((deprecated)) agent_system_result_t *agent_system_result_create(
    double id,
    int success
    ) {
    return agent_system_result_create_internal (
        id,
        success
        );
}

void agent_system_result_free(agent_system_result_t *agent_system_result) {
    if(NULL == agent_system_result){
        return ;
    }
    if(agent_system_result->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "agent_system_result_free");
        return ;
    }
    listEntry_t *listEntry;
    free(agent_system_result);
}

cJSON *agent_system_result_convertToJSON(agent_system_result_t *agent_system_result) {
    cJSON *item = cJSON_CreateObject();

    // agent_system_result->id
    if (!agent_system_result->id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "id", agent_system_result->id) == NULL) {
    goto fail; //Numeric
    }


    // agent_system_result->success
    if (!agent_system_result->success) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "success", agent_system_result->success) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

agent_system_result_t *agent_system_result_parseFromJSON(cJSON *agent_system_resultJSON){

    agent_system_result_t *agent_system_result_local_var = NULL;

    // agent_system_result->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(agent_system_resultJSON, "id");
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

    // agent_system_result->success
    cJSON *success = cJSON_GetObjectItemCaseSensitive(agent_system_resultJSON, "success");
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


    agent_system_result_local_var = agent_system_result_create_internal (
        id->valuedouble,
        success->valueint
        );

    return agent_system_result_local_var;
end:
    return NULL;

}
