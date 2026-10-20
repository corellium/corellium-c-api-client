#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "agent_frida_process_list_attached.h"



static agent_frida_process_list_attached_t *agent_frida_process_list_attached_create_internal(
    char *target_name,
    double target_pid
    ) {
    agent_frida_process_list_attached_t *agent_frida_process_list_attached_local_var = malloc(sizeof(agent_frida_process_list_attached_t));
    if (!agent_frida_process_list_attached_local_var) {
        return NULL;
    }
    agent_frida_process_list_attached_local_var->target_name = target_name;
    agent_frida_process_list_attached_local_var->target_pid = target_pid;

    agent_frida_process_list_attached_local_var->_library_owned = 1;
    return agent_frida_process_list_attached_local_var;
}

__attribute__((deprecated)) agent_frida_process_list_attached_t *agent_frida_process_list_attached_create(
    char *target_name,
    double target_pid
    ) {
    return agent_frida_process_list_attached_create_internal (
        target_name,
        target_pid
        );
}

void agent_frida_process_list_attached_free(agent_frida_process_list_attached_t *agent_frida_process_list_attached) {
    if(NULL == agent_frida_process_list_attached){
        return ;
    }
    if(agent_frida_process_list_attached->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "agent_frida_process_list_attached_free");
        return ;
    }
    listEntry_t *listEntry;
    if (agent_frida_process_list_attached->target_name) {
        free(agent_frida_process_list_attached->target_name);
        agent_frida_process_list_attached->target_name = NULL;
    }
    free(agent_frida_process_list_attached);
}

cJSON *agent_frida_process_list_attached_convertToJSON(agent_frida_process_list_attached_t *agent_frida_process_list_attached) {
    cJSON *item = cJSON_CreateObject();

    // agent_frida_process_list_attached->target_name
    if (!agent_frida_process_list_attached->target_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "targetName", agent_frida_process_list_attached->target_name) == NULL) {
    goto fail; //String
    }


    // agent_frida_process_list_attached->target_pid
    if (!agent_frida_process_list_attached->target_pid) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "targetPid", agent_frida_process_list_attached->target_pid) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

agent_frida_process_list_attached_t *agent_frida_process_list_attached_parseFromJSON(cJSON *agent_frida_process_list_attachedJSON){

    agent_frida_process_list_attached_t *agent_frida_process_list_attached_local_var = NULL;

    // agent_frida_process_list_attached->target_name
    cJSON *target_name = cJSON_GetObjectItemCaseSensitive(agent_frida_process_list_attachedJSON, "targetName");
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

    // agent_frida_process_list_attached->target_pid
    cJSON *target_pid = cJSON_GetObjectItemCaseSensitive(agent_frida_process_list_attachedJSON, "targetPid");
    if (cJSON_IsNull(target_pid)) {
        target_pid = NULL;
    }
    if (!target_pid) {
        goto end;
    }

    
    if(!cJSON_IsNumber(target_pid))
    {
    goto end; //Numeric
    }


    agent_frida_process_list_attached_local_var = agent_frida_process_list_attached_create_internal (
        strdup(target_name->valuestring),
        target_pid->valuedouble
        );

    return agent_frida_process_list_attached_local_var;
end:
    return NULL;

}
