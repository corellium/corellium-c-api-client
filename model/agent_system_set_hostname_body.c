#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "agent_system_set_hostname_body.h"



static agent_system_set_hostname_body_t *agent_system_set_hostname_body_create_internal(
    char *hostname
    ) {
    agent_system_set_hostname_body_t *agent_system_set_hostname_body_local_var = malloc(sizeof(agent_system_set_hostname_body_t));
    if (!agent_system_set_hostname_body_local_var) {
        return NULL;
    }
    agent_system_set_hostname_body_local_var->hostname = hostname;

    agent_system_set_hostname_body_local_var->_library_owned = 1;
    return agent_system_set_hostname_body_local_var;
}

__attribute__((deprecated)) agent_system_set_hostname_body_t *agent_system_set_hostname_body_create(
    char *hostname
    ) {
    return agent_system_set_hostname_body_create_internal (
        hostname
        );
}

void agent_system_set_hostname_body_free(agent_system_set_hostname_body_t *agent_system_set_hostname_body) {
    if(NULL == agent_system_set_hostname_body){
        return ;
    }
    if(agent_system_set_hostname_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "agent_system_set_hostname_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (agent_system_set_hostname_body->hostname) {
        free(agent_system_set_hostname_body->hostname);
        agent_system_set_hostname_body->hostname = NULL;
    }
    free(agent_system_set_hostname_body);
}

cJSON *agent_system_set_hostname_body_convertToJSON(agent_system_set_hostname_body_t *agent_system_set_hostname_body) {
    cJSON *item = cJSON_CreateObject();

    // agent_system_set_hostname_body->hostname
    if (!agent_system_set_hostname_body->hostname) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "hostname", agent_system_set_hostname_body->hostname) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

agent_system_set_hostname_body_t *agent_system_set_hostname_body_parseFromJSON(cJSON *agent_system_set_hostname_bodyJSON){

    agent_system_set_hostname_body_t *agent_system_set_hostname_body_local_var = NULL;

    // agent_system_set_hostname_body->hostname
    cJSON *hostname = cJSON_GetObjectItemCaseSensitive(agent_system_set_hostname_bodyJSON, "hostname");
    if (cJSON_IsNull(hostname)) {
        hostname = NULL;
    }
    if (!hostname) {
        goto end;
    }

    
    if(!cJSON_IsString(hostname))
    {
    goto end; //String
    }


    agent_system_set_hostname_body_local_var = agent_system_set_hostname_body_create_internal (
        strdup(hostname->valuestring)
        );

    return agent_system_set_hostname_body_local_var;
end:
    return NULL;

}
