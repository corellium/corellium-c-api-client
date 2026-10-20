#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "agent_frida_run_body.h"



static agent_frida_run_body_t *agent_frida_run_body_create_internal(
    char *target_pid,
    char *target_name
    ) {
    agent_frida_run_body_t *agent_frida_run_body_local_var = malloc(sizeof(agent_frida_run_body_t));
    if (!agent_frida_run_body_local_var) {
        return NULL;
    }
    agent_frida_run_body_local_var->target_pid = target_pid;
    agent_frida_run_body_local_var->target_name = target_name;

    agent_frida_run_body_local_var->_library_owned = 1;
    return agent_frida_run_body_local_var;
}

__attribute__((deprecated)) agent_frida_run_body_t *agent_frida_run_body_create(
    char *target_pid,
    char *target_name
    ) {
    return agent_frida_run_body_create_internal (
        target_pid,
        target_name
        );
}

void agent_frida_run_body_free(agent_frida_run_body_t *agent_frida_run_body) {
    if(NULL == agent_frida_run_body){
        return ;
    }
    if(agent_frida_run_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "agent_frida_run_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (agent_frida_run_body->target_pid) {
        free(agent_frida_run_body->target_pid);
        agent_frida_run_body->target_pid = NULL;
    }
    if (agent_frida_run_body->target_name) {
        free(agent_frida_run_body->target_name);
        agent_frida_run_body->target_name = NULL;
    }
    free(agent_frida_run_body);
}

cJSON *agent_frida_run_body_convertToJSON(agent_frida_run_body_t *agent_frida_run_body) {
    cJSON *item = cJSON_CreateObject();

    // agent_frida_run_body->target_pid
    if (!agent_frida_run_body->target_pid) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "targetPid", agent_frida_run_body->target_pid) == NULL) {
    goto fail; //String
    }


    // agent_frida_run_body->target_name
    if (!agent_frida_run_body->target_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "targetName", agent_frida_run_body->target_name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

agent_frida_run_body_t *agent_frida_run_body_parseFromJSON(cJSON *agent_frida_run_bodyJSON){

    agent_frida_run_body_t *agent_frida_run_body_local_var = NULL;

    // agent_frida_run_body->target_pid
    cJSON *target_pid = cJSON_GetObjectItemCaseSensitive(agent_frida_run_bodyJSON, "targetPid");
    if (cJSON_IsNull(target_pid)) {
        target_pid = NULL;
    }
    if (!target_pid) {
        goto end;
    }

    
    if(!cJSON_IsString(target_pid))
    {
    goto end; //String
    }

    // agent_frida_run_body->target_name
    cJSON *target_name = cJSON_GetObjectItemCaseSensitive(agent_frida_run_bodyJSON, "targetName");
    if (cJSON_IsNull(target_name)) {
        target_name = NULL;
    }
    if (!target_name) {
        goto end;
    }

    
    if(!cJSON_IsString(target_name))
    {
    goto end; //String
    }


    agent_frida_run_body_local_var = agent_frida_run_body_create_internal (
        strdup(target_pid->valuestring),
        strdup(target_name->valuestring)
        );

    return agent_frida_run_body_local_var;
end:
    return NULL;

}
