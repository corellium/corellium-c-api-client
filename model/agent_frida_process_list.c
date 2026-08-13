#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "agent_frida_process_list.h"



static agent_frida_process_list_t *agent_frida_process_list_create_internal(
    int success,
    double exit_status,
    char *output,
    agent_frida_process_list_attached_t *attached
    ) {
    agent_frida_process_list_t *agent_frida_process_list_local_var = malloc(sizeof(agent_frida_process_list_t));
    if (!agent_frida_process_list_local_var) {
        return NULL;
    }
    agent_frida_process_list_local_var->success = success;
    agent_frida_process_list_local_var->exit_status = exit_status;
    agent_frida_process_list_local_var->output = output;
    agent_frida_process_list_local_var->attached = attached;

    agent_frida_process_list_local_var->_library_owned = 1;
    return agent_frida_process_list_local_var;
}

__attribute__((deprecated)) agent_frida_process_list_t *agent_frida_process_list_create(
    int success,
    double exit_status,
    char *output,
    agent_frida_process_list_attached_t *attached
    ) {
    return agent_frida_process_list_create_internal (
        success,
        exit_status,
        output,
        attached
        );
}

void agent_frida_process_list_free(agent_frida_process_list_t *agent_frida_process_list) {
    if(NULL == agent_frida_process_list){
        return ;
    }
    if(agent_frida_process_list->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "agent_frida_process_list_free");
        return ;
    }
    listEntry_t *listEntry;
    if (agent_frida_process_list->output) {
        free(agent_frida_process_list->output);
        agent_frida_process_list->output = NULL;
    }
    if (agent_frida_process_list->attached) {
        agent_frida_process_list_attached_free(agent_frida_process_list->attached);
        agent_frida_process_list->attached = NULL;
    }
    free(agent_frida_process_list);
}

cJSON *agent_frida_process_list_convertToJSON(agent_frida_process_list_t *agent_frida_process_list) {
    cJSON *item = cJSON_CreateObject();

    // agent_frida_process_list->success
    if (!agent_frida_process_list->success) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "success", agent_frida_process_list->success) == NULL) {
    goto fail; //Bool
    }


    // agent_frida_process_list->exit_status
    if (!agent_frida_process_list->exit_status) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "exitStatus", agent_frida_process_list->exit_status) == NULL) {
    goto fail; //Numeric
    }


    // agent_frida_process_list->output
    if (!agent_frida_process_list->output) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "output", agent_frida_process_list->output) == NULL) {
    goto fail; //String
    }


    // agent_frida_process_list->attached
    if(agent_frida_process_list->attached) {
    cJSON *attached_local_JSON = agent_frida_process_list_attached_convertToJSON(agent_frida_process_list->attached);
    if(attached_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "attached", attached_local_JSON);
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

agent_frida_process_list_t *agent_frida_process_list_parseFromJSON(cJSON *agent_frida_process_listJSON){

    agent_frida_process_list_t *agent_frida_process_list_local_var = NULL;

    // define the local variable for agent_frida_process_list->attached
    agent_frida_process_list_attached_t *attached_local_nonprim = NULL;

    // agent_frida_process_list->success
    cJSON *success = cJSON_GetObjectItemCaseSensitive(agent_frida_process_listJSON, "success");
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

    // agent_frida_process_list->exit_status
    cJSON *exit_status = cJSON_GetObjectItemCaseSensitive(agent_frida_process_listJSON, "exitStatus");
    if (cJSON_IsNull(exit_status)) {
        exit_status = NULL;
    }
    if (!exit_status) {
        goto end;
    }

    
    if(!cJSON_IsNumber(exit_status))
    {
    goto end; //Numeric
    }

    // agent_frida_process_list->output
    cJSON *output = cJSON_GetObjectItemCaseSensitive(agent_frida_process_listJSON, "output");
    if (cJSON_IsNull(output)) {
        output = NULL;
    }
    if (!output) {
        goto end;
    }

    
    if(!cJSON_IsString(output))
    {
    goto end; //String
    }

    // agent_frida_process_list->attached
    cJSON *attached = cJSON_GetObjectItemCaseSensitive(agent_frida_process_listJSON, "attached");
    if (cJSON_IsNull(attached)) {
        attached = NULL;
    }
    if (attached) { 
    attached_local_nonprim = agent_frida_process_list_attached_parseFromJSON(attached); //nonprimitive
    }


    agent_frida_process_list_local_var = agent_frida_process_list_create_internal (
        success->valueint,
        exit_status->valuedouble,
        strdup(output->valuestring),
        attached ? attached_local_nonprim : NULL
        );

    return agent_frida_process_list_local_var;
end:
    if (attached_local_nonprim) {
        agent_frida_process_list_attached_free(attached_local_nonprim);
        attached_local_nonprim = NULL;
    }
    return NULL;

}
