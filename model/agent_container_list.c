#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "agent_container_list.h"



static agent_container_list_t *agent_container_list_create_internal(
    list_t *containers
    ) {
    agent_container_list_t *agent_container_list_local_var = malloc(sizeof(agent_container_list_t));
    if (!agent_container_list_local_var) {
        return NULL;
    }
    agent_container_list_local_var->containers = containers;

    agent_container_list_local_var->_library_owned = 1;
    return agent_container_list_local_var;
}

__attribute__((deprecated)) agent_container_list_t *agent_container_list_create(
    list_t *containers
    ) {
    return agent_container_list_create_internal (
        containers
        );
}

void agent_container_list_free(agent_container_list_t *agent_container_list) {
    if(NULL == agent_container_list){
        return ;
    }
    if(agent_container_list->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "agent_container_list_free");
        return ;
    }
    listEntry_t *listEntry;
    if (agent_container_list->containers) {
        list_ForEach(listEntry, agent_container_list->containers) {
            agent_container_free(listEntry->data);
        }
        list_freeList(agent_container_list->containers);
        agent_container_list->containers = NULL;
    }
    free(agent_container_list);
}

cJSON *agent_container_list_convertToJSON(agent_container_list_t *agent_container_list) {
    cJSON *item = cJSON_CreateObject();

    // agent_container_list->containers
    if (!agent_container_list->containers) {
        goto fail;
    }
    cJSON *containers = cJSON_AddArrayToObject(item, "containers");
    if(containers == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *containersListEntry;
    if (agent_container_list->containers) {
    list_ForEach(containersListEntry, agent_container_list->containers) {
    cJSON *itemLocal = agent_container_convertToJSON(containersListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(containers, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

agent_container_list_t *agent_container_list_parseFromJSON(cJSON *agent_container_listJSON){

    agent_container_list_t *agent_container_list_local_var = NULL;

    // define the local list for agent_container_list->containers
    list_t *containersList = NULL;

    // agent_container_list->containers
    cJSON *containers = cJSON_GetObjectItemCaseSensitive(agent_container_listJSON, "containers");
    if (cJSON_IsNull(containers)) {
        containers = NULL;
    }
    if (!containers) {
        goto end;
    }

    
    cJSON *containers_local_nonprimitive = NULL;
    if(!cJSON_IsArray(containers)){
        goto end; //nonprimitive container
    }

    containersList = list_createList();

    cJSON_ArrayForEach(containers_local_nonprimitive,containers )
    {
        if(!cJSON_IsObject(containers_local_nonprimitive)){
            goto end;
        }
        agent_container_t *containersItem = agent_container_parseFromJSON(containers_local_nonprimitive);

        list_addElement(containersList, containersItem);
    }


    agent_container_list_local_var = agent_container_list_create_internal (
        containersList
        );

    return agent_container_list_local_var;
end:
    if (containersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, containersList) {
            agent_container_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(containersList);
        containersList = NULL;
    }
    return NULL;

}
