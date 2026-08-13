#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "user_snapshots_schema.h"



static user_snapshots_schema_t *user_snapshots_schema_create_internal(
    list_t *shared_with_user,
    list_t *shared_by_user
    ) {
    user_snapshots_schema_t *user_snapshots_schema_local_var = malloc(sizeof(user_snapshots_schema_t));
    if (!user_snapshots_schema_local_var) {
        return NULL;
    }
    user_snapshots_schema_local_var->shared_with_user = shared_with_user;
    user_snapshots_schema_local_var->shared_by_user = shared_by_user;

    user_snapshots_schema_local_var->_library_owned = 1;
    return user_snapshots_schema_local_var;
}

__attribute__((deprecated)) user_snapshots_schema_t *user_snapshots_schema_create(
    list_t *shared_with_user,
    list_t *shared_by_user
    ) {
    return user_snapshots_schema_create_internal (
        shared_with_user,
        shared_by_user
        );
}

void user_snapshots_schema_free(user_snapshots_schema_t *user_snapshots_schema) {
    if(NULL == user_snapshots_schema){
        return ;
    }
    if(user_snapshots_schema->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "user_snapshots_schema_free");
        return ;
    }
    listEntry_t *listEntry;
    if (user_snapshots_schema->shared_with_user) {
        list_ForEach(listEntry, user_snapshots_schema->shared_with_user) {
            shared_snapshots_info_schema_free(listEntry->data);
        }
        list_freeList(user_snapshots_schema->shared_with_user);
        user_snapshots_schema->shared_with_user = NULL;
    }
    if (user_snapshots_schema->shared_by_user) {
        list_ForEach(listEntry, user_snapshots_schema->shared_by_user) {
            shared_snapshots_info_schema_free(listEntry->data);
        }
        list_freeList(user_snapshots_schema->shared_by_user);
        user_snapshots_schema->shared_by_user = NULL;
    }
    free(user_snapshots_schema);
}

cJSON *user_snapshots_schema_convertToJSON(user_snapshots_schema_t *user_snapshots_schema) {
    cJSON *item = cJSON_CreateObject();

    // user_snapshots_schema->shared_with_user
    if (!user_snapshots_schema->shared_with_user) {
        goto fail;
    }
    cJSON *shared_with_user = cJSON_AddArrayToObject(item, "sharedWithUser");
    if(shared_with_user == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *shared_with_userListEntry;
    if (user_snapshots_schema->shared_with_user) {
    list_ForEach(shared_with_userListEntry, user_snapshots_schema->shared_with_user) {
    cJSON *itemLocal = shared_snapshots_info_schema_convertToJSON(shared_with_userListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(shared_with_user, itemLocal);
    }
    }


    // user_snapshots_schema->shared_by_user
    if (!user_snapshots_schema->shared_by_user) {
        goto fail;
    }
    cJSON *shared_by_user = cJSON_AddArrayToObject(item, "sharedByUser");
    if(shared_by_user == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *shared_by_userListEntry;
    if (user_snapshots_schema->shared_by_user) {
    list_ForEach(shared_by_userListEntry, user_snapshots_schema->shared_by_user) {
    cJSON *itemLocal = shared_snapshots_info_schema_convertToJSON(shared_by_userListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(shared_by_user, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

user_snapshots_schema_t *user_snapshots_schema_parseFromJSON(cJSON *user_snapshots_schemaJSON){

    user_snapshots_schema_t *user_snapshots_schema_local_var = NULL;

    // define the local list for user_snapshots_schema->shared_with_user
    list_t *shared_with_userList = NULL;

    // define the local list for user_snapshots_schema->shared_by_user
    list_t *shared_by_userList = NULL;

    // user_snapshots_schema->shared_with_user
    cJSON *shared_with_user = cJSON_GetObjectItemCaseSensitive(user_snapshots_schemaJSON, "sharedWithUser");
    if (cJSON_IsNull(shared_with_user)) {
        shared_with_user = NULL;
    }
    if (!shared_with_user) {
        goto end;
    }

    
    cJSON *shared_with_user_local_nonprimitive = NULL;
    if(!cJSON_IsArray(shared_with_user)){
        goto end; //nonprimitive container
    }

    shared_with_userList = list_createList();

    cJSON_ArrayForEach(shared_with_user_local_nonprimitive,shared_with_user )
    {
        if(!cJSON_IsObject(shared_with_user_local_nonprimitive)){
            goto end;
        }
        shared_snapshots_info_schema_t *shared_with_userItem = shared_snapshots_info_schema_parseFromJSON(shared_with_user_local_nonprimitive);

        list_addElement(shared_with_userList, shared_with_userItem);
    }

    // user_snapshots_schema->shared_by_user
    cJSON *shared_by_user = cJSON_GetObjectItemCaseSensitive(user_snapshots_schemaJSON, "sharedByUser");
    if (cJSON_IsNull(shared_by_user)) {
        shared_by_user = NULL;
    }
    if (!shared_by_user) {
        goto end;
    }

    
    cJSON *shared_by_user_local_nonprimitive = NULL;
    if(!cJSON_IsArray(shared_by_user)){
        goto end; //nonprimitive container
    }

    shared_by_userList = list_createList();

    cJSON_ArrayForEach(shared_by_user_local_nonprimitive,shared_by_user )
    {
        if(!cJSON_IsObject(shared_by_user_local_nonprimitive)){
            goto end;
        }
        shared_snapshots_info_schema_t *shared_by_userItem = shared_snapshots_info_schema_parseFromJSON(shared_by_user_local_nonprimitive);

        list_addElement(shared_by_userList, shared_by_userItem);
    }


    user_snapshots_schema_local_var = user_snapshots_schema_create_internal (
        shared_with_userList,
        shared_by_userList
        );

    return user_snapshots_schema_local_var;
end:
    if (shared_with_userList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, shared_with_userList) {
            shared_snapshots_info_schema_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(shared_with_userList);
        shared_with_userList = NULL;
    }
    if (shared_by_userList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, shared_by_userList) {
            shared_snapshots_info_schema_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(shared_by_userList);
        shared_by_userList = NULL;
    }
    return NULL;

}
