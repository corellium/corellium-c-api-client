#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "role.h"



static role_t *role_create_internal(
    corellium_api_role_name__e role,
    char *project,
    char *deployment,
    char *user,
    char *team
    ) {
    role_t *role_local_var = malloc(sizeof(role_t));
    if (!role_local_var) {
        return NULL;
    }
    role_local_var->role = role;
    role_local_var->project = project;
    role_local_var->deployment = deployment;
    role_local_var->user = user;
    role_local_var->team = team;

    role_local_var->_library_owned = 1;
    return role_local_var;
}

__attribute__((deprecated)) role_t *role_create(
    corellium_api_role_name__e role,
    char *project,
    char *deployment,
    char *user,
    char *team
    ) {
    return role_create_internal (
        role,
        project,
        deployment,
        user,
        team
        );
}

void role_free(role_t *role) {
    if(NULL == role){
        return ;
    }
    if(role->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "role_free");
        return ;
    }
    listEntry_t *listEntry;
    if (role->project) {
        free(role->project);
        role->project = NULL;
    }
    if (role->deployment) {
        free(role->deployment);
        role->deployment = NULL;
    }
    if (role->user) {
        free(role->user);
        role->user = NULL;
    }
    if (role->team) {
        free(role->team);
        role->team = NULL;
    }
    free(role);
}

cJSON *role_convertToJSON(role_t *role) {
    cJSON *item = cJSON_CreateObject();

    // role->role
    if (corellium_api_role_name__NULL == role->role) {
        goto fail;
    }
    cJSON *role_local_JSON = role_name_convertToJSON(role->role);
    if(role_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "role", role_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // role->project
    if(role->project) {
    if(cJSON_AddStringToObject(item, "project", role->project) == NULL) {
    goto fail; //String
    }
    }


    // role->deployment
    if(role->deployment) {
    if(cJSON_AddStringToObject(item, "deployment", role->deployment) == NULL) {
    goto fail; //String
    }
    }


    // role->user
    if(role->user) {
    if(cJSON_AddStringToObject(item, "user", role->user) == NULL) {
    goto fail; //String
    }
    }


    // role->team
    if(role->team) {
    if(cJSON_AddStringToObject(item, "team", role->team) == NULL) {
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

role_t *role_parseFromJSON(cJSON *roleJSON){

    role_t *role_local_var = NULL;

    // define the local variable for role->role
    corellium_api_role_name__e role_local_nonprim = 0;

    // role->role
    cJSON *role = cJSON_GetObjectItemCaseSensitive(roleJSON, "role");
    if (cJSON_IsNull(role)) {
        role = NULL;
    }
    if (!role) {
        goto end;
    }

    
    role_local_nonprim = role_name_parseFromJSON(role); //custom

    // role->project
    cJSON *project = cJSON_GetObjectItemCaseSensitive(roleJSON, "project");
    if (cJSON_IsNull(project)) {
        project = NULL;
    }
    if (project) { 
    if(!cJSON_IsString(project) && !cJSON_IsNull(project))
    {
    goto end; //String
    }
    }

    // role->deployment
    cJSON *deployment = cJSON_GetObjectItemCaseSensitive(roleJSON, "deployment");
    if (cJSON_IsNull(deployment)) {
        deployment = NULL;
    }
    if (deployment) { 
    if(!cJSON_IsString(deployment) && !cJSON_IsNull(deployment))
    {
    goto end; //String
    }
    }

    // role->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(roleJSON, "user");
    if (cJSON_IsNull(user)) {
        user = NULL;
    }
    if (user) { 
    if(!cJSON_IsString(user) && !cJSON_IsNull(user))
    {
    goto end; //String
    }
    }

    // role->team
    cJSON *team = cJSON_GetObjectItemCaseSensitive(roleJSON, "team");
    if (cJSON_IsNull(team)) {
        team = NULL;
    }
    if (team) { 
    if(!cJSON_IsString(team) && !cJSON_IsNull(team))
    {
    goto end; //String
    }
    }


    role_local_var = role_create_internal (
        role_local_nonprim,
        project && !cJSON_IsNull(project) ? strdup(project->valuestring) : NULL,
        deployment && !cJSON_IsNull(deployment) ? strdup(deployment->valuestring) : NULL,
        user && !cJSON_IsNull(user) ? strdup(user->valuestring) : NULL,
        team && !cJSON_IsNull(team) ? strdup(team->valuestring) : NULL
        );

    return role_local_var;
end:
    if (role_local_nonprim) {
        role_local_nonprim = 0;
    }
    return NULL;

}
