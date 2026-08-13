#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "agent_remote_it_status.h"


char* agent_remote_it_status_remote_it_status_ToString(corellium_api_agent_remote_it_status_REMOTEITSTATUS_e remote_it_status) {
    char* remote_it_statusArray[] =  { "NULL", "unknown", "installed", "uninstalled", "installing", "uninstalling", "registered" };
    return remote_it_statusArray[remote_it_status];
}

corellium_api_agent_remote_it_status_REMOTEITSTATUS_e agent_remote_it_status_remote_it_status_FromString(char* remote_it_status){
    int stringToReturn = 0;
    char *remote_it_statusArray[] =  { "NULL", "unknown", "installed", "uninstalled", "installing", "uninstalling", "registered" };
    size_t sizeofArray = sizeof(remote_it_statusArray) / sizeof(remote_it_statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(remote_it_status, remote_it_statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static agent_remote_it_status_t *agent_remote_it_status_create_internal(
    corellium_api_agent_remote_it_status_REMOTEITSTATUS_e remote_it_status,
    char *claim_code
    ) {
    agent_remote_it_status_t *agent_remote_it_status_local_var = malloc(sizeof(agent_remote_it_status_t));
    if (!agent_remote_it_status_local_var) {
        return NULL;
    }
    agent_remote_it_status_local_var->remote_it_status = remote_it_status;
    agent_remote_it_status_local_var->claim_code = claim_code;

    agent_remote_it_status_local_var->_library_owned = 1;
    return agent_remote_it_status_local_var;
}

__attribute__((deprecated)) agent_remote_it_status_t *agent_remote_it_status_create(
    corellium_api_agent_remote_it_status_REMOTEITSTATUS_e remote_it_status,
    char *claim_code
    ) {
    return agent_remote_it_status_create_internal (
        remote_it_status,
        claim_code
        );
}

void agent_remote_it_status_free(agent_remote_it_status_t *agent_remote_it_status) {
    if(NULL == agent_remote_it_status){
        return ;
    }
    if(agent_remote_it_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "agent_remote_it_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (agent_remote_it_status->claim_code) {
        free(agent_remote_it_status->claim_code);
        agent_remote_it_status->claim_code = NULL;
    }
    free(agent_remote_it_status);
}

cJSON *agent_remote_it_status_convertToJSON(agent_remote_it_status_t *agent_remote_it_status) {
    cJSON *item = cJSON_CreateObject();

    // agent_remote_it_status->remote_it_status
    if (corellium_api_agent_remote_it_status_REMOTEITSTATUS_NULL == agent_remote_it_status->remote_it_status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "remoteItStatus", agent_remote_it_status_remote_it_status_ToString(agent_remote_it_status->remote_it_status)) == NULL)
    {
    goto fail; //Enum
    }


    // agent_remote_it_status->claim_code
    if(agent_remote_it_status->claim_code) {
    if(cJSON_AddStringToObject(item, "claimCode", agent_remote_it_status->claim_code) == NULL) {
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

agent_remote_it_status_t *agent_remote_it_status_parseFromJSON(cJSON *agent_remote_it_statusJSON){

    agent_remote_it_status_t *agent_remote_it_status_local_var = NULL;

    // agent_remote_it_status->remote_it_status
    cJSON *remote_it_status = cJSON_GetObjectItemCaseSensitive(agent_remote_it_statusJSON, "remoteItStatus");
    if (cJSON_IsNull(remote_it_status)) {
        remote_it_status = NULL;
    }
    if (!remote_it_status) {
        goto end;
    }

    corellium_api_agent_remote_it_status_REMOTEITSTATUS_e remote_it_statusVariable;
    
    if(!cJSON_IsString(remote_it_status))
    {
    goto end; //Enum
    }
    remote_it_statusVariable = agent_remote_it_status_remote_it_status_FromString(remote_it_status->valuestring);

    // agent_remote_it_status->claim_code
    cJSON *claim_code = cJSON_GetObjectItemCaseSensitive(agent_remote_it_statusJSON, "claimCode");
    if (cJSON_IsNull(claim_code)) {
        claim_code = NULL;
    }
    if (claim_code) { 
    if(!cJSON_IsString(claim_code) && !cJSON_IsNull(claim_code))
    {
    goto end; //String
    }
    }


    agent_remote_it_status_local_var = agent_remote_it_status_create_internal (
        remote_it_statusVariable,
        claim_code && !cJSON_IsNull(claim_code) ? strdup(claim_code->valuestring) : NULL
        );

    return agent_remote_it_status_local_var;
end:
    return NULL;

}
