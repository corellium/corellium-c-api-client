#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_invites_body_settings.h"



static create_invites_body_settings_t *create_invites_body_settings_create_internal(
    list_t *teams,
    list_t *projects
    ) {
    create_invites_body_settings_t *create_invites_body_settings_local_var = malloc(sizeof(create_invites_body_settings_t));
    if (!create_invites_body_settings_local_var) {
        return NULL;
    }
    create_invites_body_settings_local_var->teams = teams;
    create_invites_body_settings_local_var->projects = projects;

    create_invites_body_settings_local_var->_library_owned = 1;
    return create_invites_body_settings_local_var;
}

__attribute__((deprecated)) create_invites_body_settings_t *create_invites_body_settings_create(
    list_t *teams,
    list_t *projects
    ) {
    return create_invites_body_settings_create_internal (
        teams,
        projects
        );
}

void create_invites_body_settings_free(create_invites_body_settings_t *create_invites_body_settings) {
    if(NULL == create_invites_body_settings){
        return ;
    }
    if(create_invites_body_settings->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "create_invites_body_settings_free");
        return ;
    }
    listEntry_t *listEntry;
    if (create_invites_body_settings->teams) {
        list_ForEach(listEntry, create_invites_body_settings->teams) {
            free(listEntry->data);
        }
        list_freeList(create_invites_body_settings->teams);
        create_invites_body_settings->teams = NULL;
    }
    if (create_invites_body_settings->projects) {
        list_ForEach(listEntry, create_invites_body_settings->projects) {
            free(listEntry->data);
        }
        list_freeList(create_invites_body_settings->projects);
        create_invites_body_settings->projects = NULL;
    }
    free(create_invites_body_settings);
}

cJSON *create_invites_body_settings_convertToJSON(create_invites_body_settings_t *create_invites_body_settings) {
    cJSON *item = cJSON_CreateObject();

    // create_invites_body_settings->teams
    if(create_invites_body_settings->teams) {
    cJSON *teams = cJSON_AddArrayToObject(item, "teams");
    if(teams == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *teamsListEntry;
    list_ForEach(teamsListEntry, create_invites_body_settings->teams) {
    if(cJSON_AddStringToObject(teams, "", teamsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // create_invites_body_settings->projects
    if(create_invites_body_settings->projects) {
    cJSON *projects = cJSON_AddArrayToObject(item, "projects");
    if(projects == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *projectsListEntry;
    list_ForEach(projectsListEntry, create_invites_body_settings->projects) {
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

create_invites_body_settings_t *create_invites_body_settings_parseFromJSON(cJSON *create_invites_body_settingsJSON){

    create_invites_body_settings_t *create_invites_body_settings_local_var = NULL;

    // define the local list for create_invites_body_settings->teams
    list_t *teamsList = NULL;

    // define the local list for create_invites_body_settings->projects
    list_t *projectsList = NULL;

    // create_invites_body_settings->teams
    cJSON *teams = cJSON_GetObjectItemCaseSensitive(create_invites_body_settingsJSON, "teams");
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

    // create_invites_body_settings->projects
    cJSON *projects = cJSON_GetObjectItemCaseSensitive(create_invites_body_settingsJSON, "projects");
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


    create_invites_body_settings_local_var = create_invites_body_settings_create_internal (
        teams ? teamsList : NULL,
        projects ? projectsList : NULL
        );

    return create_invites_body_settings_local_var;
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
