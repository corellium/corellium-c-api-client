#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "role_v1.h"


char* role_v1_role_ToString(corellium_api_role_v1_ROLE_e role) {
    char* roleArray[] =  { "NULL", "admin", "_member_" };
    return roleArray[role];
}

corellium_api_role_v1_ROLE_e role_v1_role_FromString(char* role){
    int stringToReturn = 0;
    char *roleArray[] =  { "NULL", "admin", "_member_" };
    size_t sizeofArray = sizeof(roleArray) / sizeof(roleArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(role, roleArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static role_v1_t *role_v1_create_internal(
    corellium_api_role_v1_ROLE_e role,
    char *project,
    char *user,
    char *team
    ) {
    role_v1_t *role_v1_local_var = malloc(sizeof(role_v1_t));
    if (!role_v1_local_var) {
        return NULL;
    }
    role_v1_local_var->role = role;
    role_v1_local_var->project = project;
    role_v1_local_var->user = user;
    role_v1_local_var->team = team;

    role_v1_local_var->_library_owned = 1;
    return role_v1_local_var;
}

__attribute__((deprecated)) role_v1_t *role_v1_create(
    corellium_api_role_v1_ROLE_e role,
    char *project,
    char *user,
    char *team
    ) {
    return role_v1_create_internal (
        role,
        project,
        user,
        team
        );
}

void role_v1_free(role_v1_t *role_v1) {
    if(NULL == role_v1){
        return ;
    }
    if(role_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "role_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (role_v1->project) {
        free(role_v1->project);
        role_v1->project = NULL;
    }
    if (role_v1->user) {
        free(role_v1->user);
        role_v1->user = NULL;
    }
    if (role_v1->team) {
        free(role_v1->team);
        role_v1->team = NULL;
    }
    free(role_v1);
}

cJSON *role_v1_convertToJSON(role_v1_t *role_v1) {
    cJSON *item = cJSON_CreateObject();

    // role_v1->role
    if (corellium_api_role_v1_ROLE_NULL == role_v1->role) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "role", role_v1_role_ToString(role_v1->role)) == NULL)
    {
    goto fail; //Enum
    }


    // role_v1->project
    if(role_v1->project) {
    if(cJSON_AddStringToObject(item, "project", role_v1->project) == NULL) {
    goto fail; //String
    }
    }


    // role_v1->user
    if(role_v1->user) {
    if(cJSON_AddStringToObject(item, "user", role_v1->user) == NULL) {
    goto fail; //String
    }
    }


    // role_v1->team
    if(role_v1->team) {
    if(cJSON_AddStringToObject(item, "team", role_v1->team) == NULL) {
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

role_v1_t *role_v1_parseFromJSON(cJSON *role_v1JSON){

    role_v1_t *role_v1_local_var = NULL;

    // role_v1->role
    cJSON *role = cJSON_GetObjectItemCaseSensitive(role_v1JSON, "role");
    if (cJSON_IsNull(role)) {
        role = NULL;
    }
    if (!role) {
        goto end;
    }

    corellium_api_role_v1_ROLE_e roleVariable;
    
    if(!cJSON_IsString(role))
    {
    goto end; //Enum
    }
    roleVariable = role_v1_role_FromString(role->valuestring);

    // role_v1->project
    cJSON *project = cJSON_GetObjectItemCaseSensitive(role_v1JSON, "project");
    if (cJSON_IsNull(project)) {
        project = NULL;
    }
    if (project) { 
    if(!cJSON_IsString(project) && !cJSON_IsNull(project))
    {
    goto end; //String
    }
    }

    // role_v1->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(role_v1JSON, "user");
    if (cJSON_IsNull(user)) {
        user = NULL;
    }
    if (user) { 
    if(!cJSON_IsString(user) && !cJSON_IsNull(user))
    {
    goto end; //String
    }
    }

    // role_v1->team
    cJSON *team = cJSON_GetObjectItemCaseSensitive(role_v1JSON, "team");
    if (cJSON_IsNull(team)) {
        team = NULL;
    }
    if (team) { 
    if(!cJSON_IsString(team) && !cJSON_IsNull(team))
    {
    goto end; //String
    }
    }


    role_v1_local_var = role_v1_create_internal (
        roleVariable,
        project && !cJSON_IsNull(project) ? strdup(project->valuestring) : NULL,
        user && !cJSON_IsNull(user) ? strdup(user->valuestring) : NULL,
        team && !cJSON_IsNull(team) ? strdup(team->valuestring) : NULL
        );

    return role_v1_local_var;
end:
    return NULL;

}
