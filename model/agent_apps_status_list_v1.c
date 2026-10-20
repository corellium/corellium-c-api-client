#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "agent_apps_status_list_v1.h"



static agent_apps_status_list_v1_t *agent_apps_status_list_v1_create_internal(
    list_t *apps,
    char *frontmost
    ) {
    agent_apps_status_list_v1_t *agent_apps_status_list_v1_local_var = malloc(sizeof(agent_apps_status_list_v1_t));
    if (!agent_apps_status_list_v1_local_var) {
        return NULL;
    }
    agent_apps_status_list_v1_local_var->apps = apps;
    agent_apps_status_list_v1_local_var->frontmost = frontmost;

    agent_apps_status_list_v1_local_var->_library_owned = 1;
    return agent_apps_status_list_v1_local_var;
}

__attribute__((deprecated)) agent_apps_status_list_v1_t *agent_apps_status_list_v1_create(
    list_t *apps,
    char *frontmost
    ) {
    return agent_apps_status_list_v1_create_internal (
        apps,
        frontmost
        );
}

void agent_apps_status_list_v1_free(agent_apps_status_list_v1_t *agent_apps_status_list_v1) {
    if(NULL == agent_apps_status_list_v1){
        return ;
    }
    if(agent_apps_status_list_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "agent_apps_status_list_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (agent_apps_status_list_v1->apps) {
        list_ForEach(listEntry, agent_apps_status_list_v1->apps) {
            agent_app_status_v1_free(listEntry->data);
        }
        list_freeList(agent_apps_status_list_v1->apps);
        agent_apps_status_list_v1->apps = NULL;
    }
    if (agent_apps_status_list_v1->frontmost) {
        free(agent_apps_status_list_v1->frontmost);
        agent_apps_status_list_v1->frontmost = NULL;
    }
    free(agent_apps_status_list_v1);
}

cJSON *agent_apps_status_list_v1_convertToJSON(agent_apps_status_list_v1_t *agent_apps_status_list_v1) {
    cJSON *item = cJSON_CreateObject();

    // agent_apps_status_list_v1->apps
    if(agent_apps_status_list_v1->apps) {
    cJSON *apps = cJSON_AddArrayToObject(item, "apps");
    if(apps == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *appsListEntry;
    if (agent_apps_status_list_v1->apps) {
    list_ForEach(appsListEntry, agent_apps_status_list_v1->apps) {
    cJSON *itemLocal = agent_app_status_v1_convertToJSON(appsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(apps, itemLocal);
    }
    }
    }


    // agent_apps_status_list_v1->frontmost
    if(agent_apps_status_list_v1->frontmost) {
    if(cJSON_AddStringToObject(item, "frontmost", agent_apps_status_list_v1->frontmost) == NULL) {
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

agent_apps_status_list_v1_t *agent_apps_status_list_v1_parseFromJSON(cJSON *agent_apps_status_list_v1JSON){

    agent_apps_status_list_v1_t *agent_apps_status_list_v1_local_var = NULL;

    // define the local list for agent_apps_status_list_v1->apps
    list_t *appsList = NULL;

    // agent_apps_status_list_v1->apps
    cJSON *apps = cJSON_GetObjectItemCaseSensitive(agent_apps_status_list_v1JSON, "apps");
    if (cJSON_IsNull(apps)) {
        apps = NULL;
    }
    if (apps) { 
    cJSON *apps_local_nonprimitive = NULL;
    if(!cJSON_IsArray(apps)){
        goto end; //nonprimitive container
    }

    appsList = list_createList();

    cJSON_ArrayForEach(apps_local_nonprimitive,apps )
    {
        if(!cJSON_IsObject(apps_local_nonprimitive)){
            goto end;
        }
        agent_app_status_v1_t *appsItem = agent_app_status_v1_parseFromJSON(apps_local_nonprimitive);

        list_addElement(appsList, appsItem);
    }
    }

    // agent_apps_status_list_v1->frontmost
    cJSON *frontmost = cJSON_GetObjectItemCaseSensitive(agent_apps_status_list_v1JSON, "frontmost");
    if (cJSON_IsNull(frontmost)) {
        frontmost = NULL;
    }
    if (frontmost) { 
    if(!cJSON_IsString(frontmost) && !cJSON_IsNull(frontmost))
    {
    goto end; //String
    }
    }


    agent_apps_status_list_v1_local_var = agent_apps_status_list_v1_create_internal (
        apps ? appsList : NULL,
        frontmost && !cJSON_IsNull(frontmost) ? strdup(frontmost->valuestring) : NULL
        );

    return agent_apps_status_list_v1_local_var;
end:
    if (appsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, appsList) {
            agent_app_status_v1_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(appsList);
        appsList = NULL;
    }
    return NULL;

}
