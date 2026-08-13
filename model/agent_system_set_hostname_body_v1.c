#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "agent_system_set_hostname_body_v1.h"



static agent_system_set_hostname_body_v1_t *agent_system_set_hostname_body_v1_create_internal(
    char *hostname
    ) {
    agent_system_set_hostname_body_v1_t *agent_system_set_hostname_body_v1_local_var = malloc(sizeof(agent_system_set_hostname_body_v1_t));
    if (!agent_system_set_hostname_body_v1_local_var) {
        return NULL;
    }
    agent_system_set_hostname_body_v1_local_var->hostname = hostname;

    agent_system_set_hostname_body_v1_local_var->_library_owned = 1;
    return agent_system_set_hostname_body_v1_local_var;
}

__attribute__((deprecated)) agent_system_set_hostname_body_v1_t *agent_system_set_hostname_body_v1_create(
    char *hostname
    ) {
    return agent_system_set_hostname_body_v1_create_internal (
        hostname
        );
}

void agent_system_set_hostname_body_v1_free(agent_system_set_hostname_body_v1_t *agent_system_set_hostname_body_v1) {
    if(NULL == agent_system_set_hostname_body_v1){
        return ;
    }
    if(agent_system_set_hostname_body_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "agent_system_set_hostname_body_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (agent_system_set_hostname_body_v1->hostname) {
        free(agent_system_set_hostname_body_v1->hostname);
        agent_system_set_hostname_body_v1->hostname = NULL;
    }
    free(agent_system_set_hostname_body_v1);
}

cJSON *agent_system_set_hostname_body_v1_convertToJSON(agent_system_set_hostname_body_v1_t *agent_system_set_hostname_body_v1) {
    cJSON *item = cJSON_CreateObject();

    // agent_system_set_hostname_body_v1->hostname
    if (!agent_system_set_hostname_body_v1->hostname) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "hostname", agent_system_set_hostname_body_v1->hostname) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

agent_system_set_hostname_body_v1_t *agent_system_set_hostname_body_v1_parseFromJSON(cJSON *agent_system_set_hostname_body_v1JSON){

    agent_system_set_hostname_body_v1_t *agent_system_set_hostname_body_v1_local_var = NULL;

    // agent_system_set_hostname_body_v1->hostname
    cJSON *hostname = cJSON_GetObjectItemCaseSensitive(agent_system_set_hostname_body_v1JSON, "hostname");
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


    agent_system_set_hostname_body_v1_local_var = agent_system_set_hostname_body_v1_create_internal (
        strdup(hostname->valuestring)
        );

    return agent_system_set_hostname_body_v1_local_var;
end:
    return NULL;

}
