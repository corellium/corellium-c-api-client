#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "agent_error_v1.h"


char* agent_error_v1_error_id_ToString(corellium_api_agent_error_v1_ERRORID_e error_id) {
    char* error_idArray[] =  { "NULL", "AgentError" };
    return error_idArray[error_id];
}

corellium_api_agent_error_v1_ERRORID_e agent_error_v1_error_id_FromString(char* error_id){
    int stringToReturn = 0;
    char *error_idArray[] =  { "NULL", "AgentError" };
    size_t sizeofArray = sizeof(error_idArray) / sizeof(error_idArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(error_id, error_idArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static agent_error_v1_t *agent_error_v1_create_internal(
    char *error,
    corellium_api_agent_error_v1_ERRORID_e error_id,
    object_t *original_error
    ) {
    agent_error_v1_t *agent_error_v1_local_var = malloc(sizeof(agent_error_v1_t));
    if (!agent_error_v1_local_var) {
        return NULL;
    }
    agent_error_v1_local_var->error = error;
    agent_error_v1_local_var->error_id = error_id;
    agent_error_v1_local_var->original_error = original_error;

    agent_error_v1_local_var->_library_owned = 1;
    return agent_error_v1_local_var;
}

__attribute__((deprecated)) agent_error_v1_t *agent_error_v1_create(
    char *error,
    corellium_api_agent_error_v1_ERRORID_e error_id,
    object_t *original_error
    ) {
    return agent_error_v1_create_internal (
        error,
        error_id,
        original_error
        );
}

void agent_error_v1_free(agent_error_v1_t *agent_error_v1) {
    if(NULL == agent_error_v1){
        return ;
    }
    if(agent_error_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "agent_error_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (agent_error_v1->error) {
        free(agent_error_v1->error);
        agent_error_v1->error = NULL;
    }
    if (agent_error_v1->original_error) {
        object_free(agent_error_v1->original_error);
        agent_error_v1->original_error = NULL;
    }
    free(agent_error_v1);
}

cJSON *agent_error_v1_convertToJSON(agent_error_v1_t *agent_error_v1) {
    cJSON *item = cJSON_CreateObject();

    // agent_error_v1->error
    if (!agent_error_v1->error) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "error", agent_error_v1->error) == NULL) {
    goto fail; //String
    }


    // agent_error_v1->error_id
    if (corellium_api_agent_error_v1_ERRORID_NULL == agent_error_v1->error_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "errorID", agent_error_v1_error_id_ToString(agent_error_v1->error_id)) == NULL)
    {
    goto fail; //Enum
    }


    // agent_error_v1->original_error
    if(agent_error_v1->original_error) {
    cJSON *original_error_object = object_convertToJSON(agent_error_v1->original_error);
    if(original_error_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "originalError", original_error_object);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

agent_error_v1_t *agent_error_v1_parseFromJSON(cJSON *agent_error_v1JSON){

    agent_error_v1_t *agent_error_v1_local_var = NULL;

    // agent_error_v1->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(agent_error_v1JSON, "error");
    if (cJSON_IsNull(error)) {
        error = NULL;
    }
    if (!error) {
        goto end;
    }

    
    if(!cJSON_IsString(error))
    {
    goto end; //String
    }

    // agent_error_v1->error_id
    cJSON *error_id = cJSON_GetObjectItemCaseSensitive(agent_error_v1JSON, "errorID");
    if (cJSON_IsNull(error_id)) {
        error_id = NULL;
    }
    if (!error_id) {
        goto end;
    }

    corellium_api_agent_error_v1_ERRORID_e error_idVariable;
    
    if(!cJSON_IsString(error_id))
    {
    goto end; //Enum
    }
    error_idVariable = agent_error_v1_error_id_FromString(error_id->valuestring);

    // agent_error_v1->original_error
    cJSON *original_error = cJSON_GetObjectItemCaseSensitive(agent_error_v1JSON, "originalError");
    if (cJSON_IsNull(original_error)) {
        original_error = NULL;
    }
    object_t *original_error_local_object = NULL;
    if (original_error) { 
    original_error_local_object = object_parseFromJSON(original_error); //object
    }


    agent_error_v1_local_var = agent_error_v1_create_internal (
        strdup(error->valuestring),
        error_idVariable,
        original_error ? original_error_local_object : NULL
        );

    return agent_error_v1_local_var;
end:
    return NULL;

}
