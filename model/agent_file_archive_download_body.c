#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "agent_file_archive_download_body.h"



static agent_file_archive_download_body_t *agent_file_archive_download_body_create_internal(
    list_t *paths
    ) {
    agent_file_archive_download_body_t *agent_file_archive_download_body_local_var = malloc(sizeof(agent_file_archive_download_body_t));
    if (!agent_file_archive_download_body_local_var) {
        return NULL;
    }
    agent_file_archive_download_body_local_var->paths = paths;

    agent_file_archive_download_body_local_var->_library_owned = 1;
    return agent_file_archive_download_body_local_var;
}

__attribute__((deprecated)) agent_file_archive_download_body_t *agent_file_archive_download_body_create(
    list_t *paths
    ) {
    return agent_file_archive_download_body_create_internal (
        paths
        );
}

void agent_file_archive_download_body_free(agent_file_archive_download_body_t *agent_file_archive_download_body) {
    if(NULL == agent_file_archive_download_body){
        return ;
    }
    if(agent_file_archive_download_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "agent_file_archive_download_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (agent_file_archive_download_body->paths) {
        list_ForEach(listEntry, agent_file_archive_download_body->paths) {
            free(listEntry->data);
        }
        list_freeList(agent_file_archive_download_body->paths);
        agent_file_archive_download_body->paths = NULL;
    }
    free(agent_file_archive_download_body);
}

cJSON *agent_file_archive_download_body_convertToJSON(agent_file_archive_download_body_t *agent_file_archive_download_body) {
    cJSON *item = cJSON_CreateObject();

    // agent_file_archive_download_body->paths
    if (!agent_file_archive_download_body->paths) {
        goto fail;
    }
    cJSON *paths = cJSON_AddArrayToObject(item, "paths");
    if(paths == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *pathsListEntry;
    list_ForEach(pathsListEntry, agent_file_archive_download_body->paths) {
    if(cJSON_AddStringToObject(paths, "", pathsListEntry->data) == NULL)
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

agent_file_archive_download_body_t *agent_file_archive_download_body_parseFromJSON(cJSON *agent_file_archive_download_bodyJSON){

    agent_file_archive_download_body_t *agent_file_archive_download_body_local_var = NULL;

    // define the local list for agent_file_archive_download_body->paths
    list_t *pathsList = NULL;

    // agent_file_archive_download_body->paths
    cJSON *paths = cJSON_GetObjectItemCaseSensitive(agent_file_archive_download_bodyJSON, "paths");
    if (cJSON_IsNull(paths)) {
        paths = NULL;
    }
    if (!paths) {
        goto end;
    }

    
    cJSON *paths_local = NULL;
    if(!cJSON_IsArray(paths)) {
        goto end;//primitive container
    }
    pathsList = list_createList();

    cJSON_ArrayForEach(paths_local, paths)
    {
        if(!cJSON_IsString(paths_local))
        {
            goto end;
        }
        list_addElement(pathsList , strdup(paths_local->valuestring));
    }


    agent_file_archive_download_body_local_var = agent_file_archive_download_body_create_internal (
        pathsList
        );

    return agent_file_archive_download_body_local_var;
end:
    if (pathsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, pathsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(pathsList);
        pathsList = NULL;
    }
    return NULL;

}
