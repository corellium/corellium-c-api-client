#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "agent_file_download_token.h"



static agent_file_download_token_t *agent_file_download_token_create_internal(
    char *token
    ) {
    agent_file_download_token_t *agent_file_download_token_local_var = malloc(sizeof(agent_file_download_token_t));
    if (!agent_file_download_token_local_var) {
        return NULL;
    }
    agent_file_download_token_local_var->token = token;

    agent_file_download_token_local_var->_library_owned = 1;
    return agent_file_download_token_local_var;
}

__attribute__((deprecated)) agent_file_download_token_t *agent_file_download_token_create(
    char *token
    ) {
    return agent_file_download_token_create_internal (
        token
        );
}

void agent_file_download_token_free(agent_file_download_token_t *agent_file_download_token) {
    if(NULL == agent_file_download_token){
        return ;
    }
    if(agent_file_download_token->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "agent_file_download_token_free");
        return ;
    }
    listEntry_t *listEntry;
    if (agent_file_download_token->token) {
        free(agent_file_download_token->token);
        agent_file_download_token->token = NULL;
    }
    free(agent_file_download_token);
}

cJSON *agent_file_download_token_convertToJSON(agent_file_download_token_t *agent_file_download_token) {
    cJSON *item = cJSON_CreateObject();

    // agent_file_download_token->token
    if (!agent_file_download_token->token) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "token", agent_file_download_token->token) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

agent_file_download_token_t *agent_file_download_token_parseFromJSON(cJSON *agent_file_download_tokenJSON){

    agent_file_download_token_t *agent_file_download_token_local_var = NULL;

    // agent_file_download_token->token
    cJSON *token = cJSON_GetObjectItemCaseSensitive(agent_file_download_tokenJSON, "token");
    if (cJSON_IsNull(token)) {
        token = NULL;
    }
    if (!token) {
        goto end;
    }

    
    if(!cJSON_IsString(token))
    {
    goto end; //String
    }


    agent_file_download_token_local_var = agent_file_download_token_create_internal (
        strdup(token->valuestring)
        );

    return agent_file_download_token_local_var;
end:
    return NULL;

}
