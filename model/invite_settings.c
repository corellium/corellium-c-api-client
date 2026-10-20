#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "invite_settings.h"



static invite_settings_t *invite_settings_create_internal(
    list_t *teams,
    list_t *projects
    ) {
    invite_settings_t *invite_settings_local_var = malloc(sizeof(invite_settings_t));
    if (!invite_settings_local_var) {
        return NULL;
    }
    invite_settings_local_var->teams = teams;
    invite_settings_local_var->projects = projects;

    invite_settings_local_var->_library_owned = 1;
    return invite_settings_local_var;
}

__attribute__((deprecated)) invite_settings_t *invite_settings_create(
    list_t *teams,
    list_t *projects
    ) {
    return invite_settings_create_internal (
        teams,
        projects
        );
}

void invite_settings_free(invite_settings_t *invite_settings) {
    if(NULL == invite_settings){
        return ;
    }
    if(invite_settings->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "invite_settings_free");
        return ;
    }
    listEntry_t *listEntry;
    if (invite_settings->teams) {
        list_ForEach(listEntry, invite_settings->teams) {
            free(listEntry->data);
        }
        list_freeList(invite_settings->teams);
        invite_settings->teams = NULL;
    }
    if (invite_settings->projects) {
        list_ForEach(listEntry, invite_settings->projects) {
            free(listEntry->data);
        }
        list_freeList(invite_settings->projects);
        invite_settings->projects = NULL;
    }
    free(invite_settings);
}

cJSON *invite_settings_convertToJSON(invite_settings_t *invite_settings) {
    cJSON *item = cJSON_CreateObject();

    // invite_settings->teams
    if(invite_settings->teams) {
    cJSON *teams = cJSON_AddArrayToObject(item, "teams");
    if(teams == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *teamsListEntry;
    list_ForEach(teamsListEntry, invite_settings->teams) {
    if(cJSON_AddStringToObject(teams, "", teamsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // invite_settings->projects
    if(invite_settings->projects) {
    cJSON *projects = cJSON_AddArrayToObject(item, "projects");
    if(projects == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *projectsListEntry;
    list_ForEach(projectsListEntry, invite_settings->projects) {
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

invite_settings_t *invite_settings_parseFromJSON(cJSON *invite_settingsJSON){

    invite_settings_t *invite_settings_local_var = NULL;

    // define the local list for invite_settings->teams
    list_t *teamsList = NULL;

    // define the local list for invite_settings->projects
    list_t *projectsList = NULL;

    // invite_settings->teams
    cJSON *teams = cJSON_GetObjectItemCaseSensitive(invite_settingsJSON, "teams");
    if (cJSON_IsNull(teams)) {
        teams = NULL;
    }
    if (teams) { 
    cJSON *teams_local = NULL;
    if(!cJSON_IsArray(teams)) {
        goto end;//primitive container
    }
    teamsList = list_createList();

    cJSON_ArrayForEach(teams_local, teams)
    {
        if(!cJSON_IsString(teams_local))
        {
            goto end;
        }
        list_addElement(teamsList , strdup(teams_local->valuestring));
    }
    }

    // invite_settings->projects
    cJSON *projects = cJSON_GetObjectItemCaseSensitive(invite_settingsJSON, "projects");
    if (cJSON_IsNull(projects)) {
        projects = NULL;
    }
    if (projects) { 
    cJSON *projects_local = NULL;
    if(!cJSON_IsArray(projects)) {
        goto end;//primitive container
    }
    projectsList = list_createList();

    cJSON_ArrayForEach(projects_local, projects)
    {
    }
    }


    invite_settings_local_var = invite_settings_create_internal (
        teams ? teamsList : NULL,
        projects ? projectsList : NULL
        );

    return invite_settings_local_var;
end:
    if (teamsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, teamsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(teamsList);
        teamsList = NULL;
    }
    if (projectsList) {
        list_freeList(projectsList);
        projectsList = NULL;
    }
    return NULL;

}
