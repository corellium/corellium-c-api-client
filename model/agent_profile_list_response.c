#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "agent_profile_list_response.h"



static agent_profile_list_response_t *agent_profile_list_response_create_internal(
    list_t *profiles
    ) {
    agent_profile_list_response_t *agent_profile_list_response_local_var = malloc(sizeof(agent_profile_list_response_t));
    if (!agent_profile_list_response_local_var) {
        return NULL;
    }
    agent_profile_list_response_local_var->profiles = profiles;

    agent_profile_list_response_local_var->_library_owned = 1;
    return agent_profile_list_response_local_var;
}

__attribute__((deprecated)) agent_profile_list_response_t *agent_profile_list_response_create(
    list_t *profiles
    ) {
    return agent_profile_list_response_create_internal (
        profiles
        );
}

void agent_profile_list_response_free(agent_profile_list_response_t *agent_profile_list_response) {
    if(NULL == agent_profile_list_response){
        return ;
    }
    if(agent_profile_list_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "agent_profile_list_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (agent_profile_list_response->profiles) {
        list_ForEach(listEntry, agent_profile_list_response->profiles) {
            free(listEntry->data);
        }
        list_freeList(agent_profile_list_response->profiles);
        agent_profile_list_response->profiles = NULL;
    }
    free(agent_profile_list_response);
}

cJSON *agent_profile_list_response_convertToJSON(agent_profile_list_response_t *agent_profile_list_response) {
    cJSON *item = cJSON_CreateObject();

    // agent_profile_list_response->profiles
    if (!agent_profile_list_response->profiles) {
        goto fail;
    }
    cJSON *profiles = cJSON_AddArrayToObject(item, "profiles");
    if(profiles == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *profilesListEntry;
    list_ForEach(profilesListEntry, agent_profile_list_response->profiles) {
    if(cJSON_AddStringToObject(profiles, "", profilesListEntry->data) == NULL)
    {
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

agent_profile_list_response_t *agent_profile_list_response_parseFromJSON(cJSON *agent_profile_list_responseJSON){

    agent_profile_list_response_t *agent_profile_list_response_local_var = NULL;

    // define the local list for agent_profile_list_response->profiles
    list_t *profilesList = NULL;

    // agent_profile_list_response->profiles
    cJSON *profiles = cJSON_GetObjectItemCaseSensitive(agent_profile_list_responseJSON, "profiles");
    if (cJSON_IsNull(profiles)) {
        profiles = NULL;
    }
    if (!profiles) {
        goto end;
    }

    
    cJSON *profiles_local = NULL;
    if(!cJSON_IsArray(profiles)) {
        goto end;//primitive container
    }
    profilesList = list_createList();

    cJSON_ArrayForEach(profiles_local, profiles)
    {
        if(!cJSON_IsString(profiles_local))
        {
            goto end;
        }
        list_addElement(profilesList , strdup(profiles_local->valuestring));
    }


    agent_profile_list_response_local_var = agent_profile_list_response_create_internal (
        profilesList
        );

    return agent_profile_list_response_local_var;
end:
    if (profilesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, profilesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(profilesList);
        profilesList = NULL;
    }
    return NULL;

}
