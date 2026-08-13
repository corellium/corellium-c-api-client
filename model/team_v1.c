#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "team_v1.h"



static team_v1_t *team_v1_create_internal(
    char *id,
    char *label,
    list_t *users
    ) {
    team_v1_t *team_v1_local_var = malloc(sizeof(team_v1_t));
    if (!team_v1_local_var) {
        return NULL;
    }
    team_v1_local_var->id = id;
    team_v1_local_var->label = label;
    team_v1_local_var->users = users;

    team_v1_local_var->_library_owned = 1;
    return team_v1_local_var;
}

__attribute__((deprecated)) team_v1_t *team_v1_create(
    char *id,
    char *label,
    list_t *users
    ) {
    return team_v1_create_internal (
        id,
        label,
        users
        );
}

void team_v1_free(team_v1_t *team_v1) {
    if(NULL == team_v1){
        return ;
    }
    if(team_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "team_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (team_v1->id) {
        free(team_v1->id);
        team_v1->id = NULL;
    }
    if (team_v1->label) {
        free(team_v1->label);
        team_v1->label = NULL;
    }
    if (team_v1->users) {
        list_ForEach(listEntry, team_v1->users) {
            user_free(listEntry->data);
        }
        list_freeList(team_v1->users);
        team_v1->users = NULL;
    }
    free(team_v1);
}

cJSON *team_v1_convertToJSON(team_v1_t *team_v1) {
    cJSON *item = cJSON_CreateObject();

    // team_v1->id
    if (!team_v1->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", team_v1->id) == NULL) {
    goto fail; //String
    }


    // team_v1->label
    if (!team_v1->label) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "label", team_v1->label) == NULL) {
    goto fail; //String
    }


    // team_v1->users
    if(team_v1->users) {
    cJSON *users = cJSON_AddArrayToObject(item, "users");
    if(users == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *usersListEntry;
    if (team_v1->users) {
    list_ForEach(usersListEntry, team_v1->users) {
    cJSON *itemLocal = user_convertToJSON(usersListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(users, itemLocal);
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

team_v1_t *team_v1_parseFromJSON(cJSON *team_v1JSON){

    team_v1_t *team_v1_local_var = NULL;

    // define the local list for team_v1->users
    list_t *usersList = NULL;

    // team_v1->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(team_v1JSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // team_v1->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(team_v1JSON, "label");
    if (cJSON_IsNull(label)) {
        label = NULL;
    }
    if (!label) {
        goto end;
    }

    
    if(!cJSON_IsString(label))
    {
    goto end; //String
    }

    // team_v1->users
    cJSON *users = cJSON_GetObjectItemCaseSensitive(team_v1JSON, "users");
    if (cJSON_IsNull(users)) {
        users = NULL;
    }
    if (users) { 
    cJSON *users_local_nonprimitive = NULL;
    if(!cJSON_IsArray(users)){
        goto end; //nonprimitive container
    }

    usersList = list_createList();

    cJSON_ArrayForEach(users_local_nonprimitive,users )
    {
        if(!cJSON_IsObject(users_local_nonprimitive)){
            goto end;
        }
        user_t *usersItem = user_parseFromJSON(users_local_nonprimitive);

        list_addElement(usersList, usersItem);
    }
    }


    team_v1_local_var = team_v1_create_internal (
        strdup(id->valuestring),
        strdup(label->valuestring),
        users ? usersList : NULL
        );

    return team_v1_local_var;
end:
    if (usersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, usersList) {
            user_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(usersList);
        usersList = NULL;
    }
    return NULL;

}
