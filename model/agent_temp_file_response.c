#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "agent_temp_file_response.h"



static agent_temp_file_response_t *agent_temp_file_response_create_internal(
    char *path
    ) {
    agent_temp_file_response_t *agent_temp_file_response_local_var = malloc(sizeof(agent_temp_file_response_t));
    if (!agent_temp_file_response_local_var) {
        return NULL;
    }
    agent_temp_file_response_local_var->path = path;

    agent_temp_file_response_local_var->_library_owned = 1;
    return agent_temp_file_response_local_var;
}

__attribute__((deprecated)) agent_temp_file_response_t *agent_temp_file_response_create(
    char *path
    ) {
    return agent_temp_file_response_create_internal (
        path
        );
}

void agent_temp_file_response_free(agent_temp_file_response_t *agent_temp_file_response) {
    if(NULL == agent_temp_file_response){
        return ;
    }
    if(agent_temp_file_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "agent_temp_file_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (agent_temp_file_response->path) {
        free(agent_temp_file_response->path);
        agent_temp_file_response->path = NULL;
    }
    free(agent_temp_file_response);
}

cJSON *agent_temp_file_response_convertToJSON(agent_temp_file_response_t *agent_temp_file_response) {
    cJSON *item = cJSON_CreateObject();

    // agent_temp_file_response->path
    if (!agent_temp_file_response->path) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "path", agent_temp_file_response->path) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

agent_temp_file_response_t *agent_temp_file_response_parseFromJSON(cJSON *agent_temp_file_responseJSON){

    agent_temp_file_response_t *agent_temp_file_response_local_var = NULL;

    // agent_temp_file_response->path
    cJSON *path = cJSON_GetObjectItemCaseSensitive(agent_temp_file_responseJSON, "path");
    if (cJSON_IsNull(path)) {
        path = NULL;
    }
    if (!path) {
        goto end;
    }

    
    if(!cJSON_IsString(path))
    {
    goto end; //String
    }


    agent_temp_file_response_local_var = agent_temp_file_response_create_internal (
        strdup(path->valuestring)
        );

    return agent_temp_file_response_local_var;
end:
    return NULL;

}
