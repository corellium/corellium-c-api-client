#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "shared_snapshots_response.h"



static shared_snapshots_response_t *shared_snapshots_response_create_internal(
    list_t *shared_with_user,
    list_t *shared_by_user
    ) {
    shared_snapshots_response_t *shared_snapshots_response_local_var = malloc(sizeof(shared_snapshots_response_t));
    if (!shared_snapshots_response_local_var) {
        return NULL;
    }
    shared_snapshots_response_local_var->shared_with_user = shared_with_user;
    shared_snapshots_response_local_var->shared_by_user = shared_by_user;

    shared_snapshots_response_local_var->_library_owned = 1;
    return shared_snapshots_response_local_var;
}

__attribute__((deprecated)) shared_snapshots_response_t *shared_snapshots_response_create(
    list_t *shared_with_user,
    list_t *shared_by_user
    ) {
    return shared_snapshots_response_create_internal (
        shared_with_user,
        shared_by_user
        );
}

void shared_snapshots_response_free(shared_snapshots_response_t *shared_snapshots_response) {
    if(NULL == shared_snapshots_response){
        return ;
    }
    if(shared_snapshots_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "shared_snapshots_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (shared_snapshots_response->shared_with_user) {
        list_ForEach(listEntry, shared_snapshots_response->shared_with_user) {
            shared_snapshot_free(listEntry->data);
        }
        list_freeList(shared_snapshots_response->shared_with_user);
        shared_snapshots_response->shared_with_user = NULL;
    }
    if (shared_snapshots_response->shared_by_user) {
        list_ForEach(listEntry, shared_snapshots_response->shared_by_user) {
            shared_snapshot_free(listEntry->data);
        }
        list_freeList(shared_snapshots_response->shared_by_user);
        shared_snapshots_response->shared_by_user = NULL;
    }
    free(shared_snapshots_response);
}

cJSON *shared_snapshots_response_convertToJSON(shared_snapshots_response_t *shared_snapshots_response) {
    cJSON *item = cJSON_CreateObject();

    // shared_snapshots_response->shared_with_user
    if (!shared_snapshots_response->shared_with_user) {
        goto fail;
    }
    cJSON *shared_with_user = cJSON_AddArrayToObject(item, "sharedWithUser");
    if(shared_with_user == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *shared_with_userListEntry;
    if (shared_snapshots_response->shared_with_user) {
    list_ForEach(shared_with_userListEntry, shared_snapshots_response->shared_with_user) {
    cJSON *itemLocal = shared_snapshot_convertToJSON(shared_with_userListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(shared_with_user, itemLocal);
    }
    }


    // shared_snapshots_response->shared_by_user
    if (!shared_snapshots_response->shared_by_user) {
        goto fail;
    }
    cJSON *shared_by_user = cJSON_AddArrayToObject(item, "sharedByUser");
    if(shared_by_user == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *shared_by_userListEntry;
    if (shared_snapshots_response->shared_by_user) {
    list_ForEach(shared_by_userListEntry, shared_snapshots_response->shared_by_user) {
    cJSON *itemLocal = shared_snapshot_convertToJSON(shared_by_userListEntry->data);
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

shared_snapshots_response_t *shared_snapshots_response_parseFromJSON(cJSON *shared_snapshots_responseJSON){

    shared_snapshots_response_t *shared_snapshots_response_local_var = NULL;

    // define the local list for shared_snapshots_response->shared_with_user
    list_t *shared_with_userList = NULL;

    // define the local list for shared_snapshots_response->shared_by_user
    list_t *shared_by_userList = NULL;

    // shared_snapshots_response->shared_with_user
    cJSON *shared_with_user = cJSON_GetObjectItemCaseSensitive(shared_snapshots_responseJSON, "sharedWithUser");
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
        shared_snapshot_t *shared_with_userItem = shared_snapshot_parseFromJSON(shared_with_user_local_nonprimitive);

        list_addElement(shared_with_userList, shared_with_userItem);
    }

    // shared_snapshots_response->shared_by_user
    cJSON *shared_by_user = cJSON_GetObjectItemCaseSensitive(shared_snapshots_responseJSON, "sharedByUser");
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
        shared_snapshot_t *shared_by_userItem = shared_snapshot_parseFromJSON(shared_by_user_local_nonprimitive);

        list_addElement(shared_by_userList, shared_by_userItem);
    }


    shared_snapshots_response_local_var = shared_snapshots_response_create_internal (
        shared_with_userList,
        shared_by_userList
        );

    return shared_snapshots_response_local_var;
end:
    if (shared_with_userList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, shared_with_userList) {
            shared_snapshot_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(shared_with_userList);
        shared_with_userList = NULL;
    }
    if (shared_by_userList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, shared_by_userList) {
            shared_snapshot_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(shared_by_userList);
        shared_by_userList = NULL;
    }
    return NULL;

}
