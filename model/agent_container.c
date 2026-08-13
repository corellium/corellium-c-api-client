#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "agent_container.h"



static agent_container_t *agent_container_create_internal(
    char *autostart,
    char *groups,
    char *ipv4,
    char *ipv6,
    char *name,
    char *pid,
    char *ram,
    char *state,
    char *swap,
    char *unprivileged
    ) {
    agent_container_t *agent_container_local_var = malloc(sizeof(agent_container_t));
    if (!agent_container_local_var) {
        return NULL;
    }
    agent_container_local_var->autostart = autostart;
    agent_container_local_var->groups = groups;
    agent_container_local_var->ipv4 = ipv4;
    agent_container_local_var->ipv6 = ipv6;
    agent_container_local_var->name = name;
    agent_container_local_var->pid = pid;
    agent_container_local_var->ram = ram;
    agent_container_local_var->state = state;
    agent_container_local_var->swap = swap;
    agent_container_local_var->unprivileged = unprivileged;

    agent_container_local_var->_library_owned = 1;
    return agent_container_local_var;
}

__attribute__((deprecated)) agent_container_t *agent_container_create(
    char *autostart,
    char *groups,
    char *ipv4,
    char *ipv6,
    char *name,
    char *pid,
    char *ram,
    char *state,
    char *swap,
    char *unprivileged
    ) {
    return agent_container_create_internal (
        autostart,
        groups,
        ipv4,
        ipv6,
        name,
        pid,
        ram,
        state,
        swap,
        unprivileged
        );
}

void agent_container_free(agent_container_t *agent_container) {
    if(NULL == agent_container){
        return ;
    }
    if(agent_container->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "agent_container_free");
        return ;
    }
    listEntry_t *listEntry;
    if (agent_container->autostart) {
        free(agent_container->autostart);
        agent_container->autostart = NULL;
    }
    if (agent_container->groups) {
        free(agent_container->groups);
        agent_container->groups = NULL;
    }
    if (agent_container->ipv4) {
        free(agent_container->ipv4);
        agent_container->ipv4 = NULL;
    }
    if (agent_container->ipv6) {
        free(agent_container->ipv6);
        agent_container->ipv6 = NULL;
    }
    if (agent_container->name) {
        free(agent_container->name);
        agent_container->name = NULL;
    }
    if (agent_container->pid) {
        free(agent_container->pid);
        agent_container->pid = NULL;
    }
    if (agent_container->ram) {
        free(agent_container->ram);
        agent_container->ram = NULL;
    }
    if (agent_container->state) {
        free(agent_container->state);
        agent_container->state = NULL;
    }
    if (agent_container->swap) {
        free(agent_container->swap);
        agent_container->swap = NULL;
    }
    if (agent_container->unprivileged) {
        free(agent_container->unprivileged);
        agent_container->unprivileged = NULL;
    }
    free(agent_container);
}

cJSON *agent_container_convertToJSON(agent_container_t *agent_container) {
    cJSON *item = cJSON_CreateObject();

    // agent_container->autostart
    if (!agent_container->autostart) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "autostart", agent_container->autostart) == NULL) {
    goto fail; //String
    }


    // agent_container->groups
    if (!agent_container->groups) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "groups", agent_container->groups) == NULL) {
    goto fail; //String
    }


    // agent_container->ipv4
    if (!agent_container->ipv4) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "ipv4", agent_container->ipv4) == NULL) {
    goto fail; //String
    }


    // agent_container->ipv6
    if (!agent_container->ipv6) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "ipv6", agent_container->ipv6) == NULL) {
    goto fail; //String
    }


    // agent_container->name
    if (!agent_container->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", agent_container->name) == NULL) {
    goto fail; //String
    }


    // agent_container->pid
    if (!agent_container->pid) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "pid", agent_container->pid) == NULL) {
    goto fail; //String
    }


    // agent_container->ram
    if (!agent_container->ram) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "ram", agent_container->ram) == NULL) {
    goto fail; //String
    }


    // agent_container->state
    if (!agent_container->state) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "state", agent_container->state) == NULL) {
    goto fail; //String
    }


    // agent_container->swap
    if (!agent_container->swap) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "swap", agent_container->swap) == NULL) {
    goto fail; //String
    }


    // agent_container->unprivileged
    if (!agent_container->unprivileged) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "unprivileged", agent_container->unprivileged) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

agent_container_t *agent_container_parseFromJSON(cJSON *agent_containerJSON){

    agent_container_t *agent_container_local_var = NULL;

    // agent_container->autostart
    cJSON *autostart = cJSON_GetObjectItemCaseSensitive(agent_containerJSON, "autostart");
    if (cJSON_IsNull(autostart)) {
        autostart = NULL;
    }
    if (!autostart) {
        goto end;
    }

    
    if(!cJSON_IsString(autostart))
    {
    goto end; //String
    }

    // agent_container->groups
    cJSON *groups = cJSON_GetObjectItemCaseSensitive(agent_containerJSON, "groups");
    if (cJSON_IsNull(groups)) {
        groups = NULL;
    }
    if (!groups) {
        goto end;
    }

    
    if(!cJSON_IsString(groups))
    {
    goto end; //String
    }

    // agent_container->ipv4
    cJSON *ipv4 = cJSON_GetObjectItemCaseSensitive(agent_containerJSON, "ipv4");
    if (cJSON_IsNull(ipv4)) {
        ipv4 = NULL;
    }
    if (!ipv4) {
        goto end;
    }

    
    if(!cJSON_IsString(ipv4))
    {
    goto end; //String
    }

    // agent_container->ipv6
    cJSON *ipv6 = cJSON_GetObjectItemCaseSensitive(agent_containerJSON, "ipv6");
    if (cJSON_IsNull(ipv6)) {
        ipv6 = NULL;
    }
    if (!ipv6) {
        goto end;
    }

    
    if(!cJSON_IsString(ipv6))
    {
    goto end; //String
    }

    // agent_container->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(agent_containerJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // agent_container->pid
    cJSON *pid = cJSON_GetObjectItemCaseSensitive(agent_containerJSON, "pid");
    if (cJSON_IsNull(pid)) {
        pid = NULL;
    }
    if (!pid) {
        goto end;
    }

    
    if(!cJSON_IsString(pid))
    {
    goto end; //String
    }

    // agent_container->ram
    cJSON *ram = cJSON_GetObjectItemCaseSensitive(agent_containerJSON, "ram");
    if (cJSON_IsNull(ram)) {
        ram = NULL;
    }
    if (!ram) {
        goto end;
    }

    
    if(!cJSON_IsString(ram))
    {
    goto end; //String
    }

    // agent_container->state
    cJSON *state = cJSON_GetObjectItemCaseSensitive(agent_containerJSON, "state");
    if (cJSON_IsNull(state)) {
        state = NULL;
    }
    if (!state) {
        goto end;
    }

    
    if(!cJSON_IsString(state))
    {
    goto end; //String
    }

    // agent_container->swap
    cJSON *swap = cJSON_GetObjectItemCaseSensitive(agent_containerJSON, "swap");
    if (cJSON_IsNull(swap)) {
        swap = NULL;
    }
    if (!swap) {
        goto end;
    }

    
    if(!cJSON_IsString(swap))
    {
    goto end; //String
    }

    // agent_container->unprivileged
    cJSON *unprivileged = cJSON_GetObjectItemCaseSensitive(agent_containerJSON, "unprivileged");
    if (cJSON_IsNull(unprivileged)) {
        unprivileged = NULL;
    }
    if (!unprivileged) {
        goto end;
    }

    
    if(!cJSON_IsString(unprivileged))
    {
    goto end; //String
    }


    agent_container_local_var = agent_container_create_internal (
        strdup(autostart->valuestring),
        strdup(groups->valuestring),
        strdup(ipv4->valuestring),
        strdup(ipv6->valuestring),
        strdup(name->valuestring),
        strdup(pid->valuestring),
        strdup(ram->valuestring),
        strdup(state->valuestring),
        strdup(swap->valuestring),
        strdup(unprivileged->valuestring)
        );

    return agent_container_local_var;
end:
    return NULL;

}
