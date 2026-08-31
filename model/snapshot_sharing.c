#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "snapshot_sharing.h"



static snapshot_sharing_t *snapshot_sharing_create_internal(
    corellium_api_snapshot_sharing_type__e sharing_type,
    char *access_code,
    char *shared_on,
    snapshot_owner_t *shared_by,
    list_t *members
    ) {
    snapshot_sharing_t *snapshot_sharing_local_var = malloc(sizeof(snapshot_sharing_t));
    if (!snapshot_sharing_local_var) {
        return NULL;
    }
    snapshot_sharing_local_var->sharing_type = sharing_type;
    snapshot_sharing_local_var->access_code = access_code;
    snapshot_sharing_local_var->shared_on = shared_on;
    snapshot_sharing_local_var->shared_by = shared_by;
    snapshot_sharing_local_var->members = members;

    snapshot_sharing_local_var->_library_owned = 1;
    return snapshot_sharing_local_var;
}

__attribute__((deprecated)) snapshot_sharing_t *snapshot_sharing_create(
    corellium_api_snapshot_sharing_type__e sharing_type,
    char *access_code,
    char *shared_on,
    snapshot_owner_t *shared_by,
    list_t *members
    ) {
    return snapshot_sharing_create_internal (
        sharing_type,
        access_code,
        shared_on,
        shared_by,
        members
        );
}

void snapshot_sharing_free(snapshot_sharing_t *snapshot_sharing) {
    if(NULL == snapshot_sharing){
        return ;
    }
    if(snapshot_sharing->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "snapshot_sharing_free");
        return ;
    }
    listEntry_t *listEntry;
    if (snapshot_sharing->access_code) {
        free(snapshot_sharing->access_code);
        snapshot_sharing->access_code = NULL;
    }
    if (snapshot_sharing->shared_on) {
        free(snapshot_sharing->shared_on);
        snapshot_sharing->shared_on = NULL;
    }
    if (snapshot_sharing->shared_by) {
        snapshot_owner_free(snapshot_sharing->shared_by);
        snapshot_sharing->shared_by = NULL;
    }
    if (snapshot_sharing->members) {
        list_ForEach(listEntry, snapshot_sharing->members) {
            snapshot_member_free(listEntry->data);
        }
        list_freeList(snapshot_sharing->members);
        snapshot_sharing->members = NULL;
    }
    free(snapshot_sharing);
}

cJSON *snapshot_sharing_convertToJSON(snapshot_sharing_t *snapshot_sharing) {
    cJSON *item = cJSON_CreateObject();

    // snapshot_sharing->sharing_type
    if (corellium_api_snapshot_sharing_type__NULL == snapshot_sharing->sharing_type) {
        goto fail;
    }
    cJSON *sharing_type_local_JSON = snapshot_sharing_type_convertToJSON(snapshot_sharing->sharing_type);
    if(sharing_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "sharingType", sharing_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // snapshot_sharing->access_code
    if(snapshot_sharing->access_code) {
    if(cJSON_AddStringToObject(item, "accessCode", snapshot_sharing->access_code) == NULL) {
    goto fail; //String
    }
    }


    // snapshot_sharing->shared_on
    if(snapshot_sharing->shared_on) {
    if(cJSON_AddStringToObject(item, "sharedOn", snapshot_sharing->shared_on) == NULL) {
    goto fail; //Date-Time
    }
    }


    // snapshot_sharing->shared_by
    if(snapshot_sharing->shared_by) {
    cJSON *shared_by_local_JSON = snapshot_owner_convertToJSON(snapshot_sharing->shared_by);
    if(shared_by_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "sharedBy", shared_by_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // snapshot_sharing->members
    if(snapshot_sharing->members) {
    cJSON *members = cJSON_AddArrayToObject(item, "members");
    if(members == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *membersListEntry;
    if (snapshot_sharing->members) {
    list_ForEach(membersListEntry, snapshot_sharing->members) {
    cJSON *itemLocal = snapshot_member_convertToJSON(membersListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(members, itemLocal);
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

snapshot_sharing_t *snapshot_sharing_parseFromJSON(cJSON *snapshot_sharingJSON){

    snapshot_sharing_t *snapshot_sharing_local_var = NULL;

    // define the local variable for snapshot_sharing->sharing_type
    corellium_api_snapshot_sharing_type__e sharing_type_local_nonprim = 0;

    // define the local variable for snapshot_sharing->shared_by
    snapshot_owner_t *shared_by_local_nonprim = NULL;

    // define the local list for snapshot_sharing->members
    list_t *membersList = NULL;

    // snapshot_sharing->sharing_type
    cJSON *sharing_type = cJSON_GetObjectItemCaseSensitive(snapshot_sharingJSON, "sharingType");
    if (cJSON_IsNull(sharing_type)) {
        sharing_type = NULL;
    }
    if (!sharing_type) {
        goto end;
    }

    
    sharing_type_local_nonprim = snapshot_sharing_type_parseFromJSON(sharing_type); //custom

    // snapshot_sharing->access_code
    cJSON *access_code = cJSON_GetObjectItemCaseSensitive(snapshot_sharingJSON, "accessCode");
    if (cJSON_IsNull(access_code)) {
        access_code = NULL;
    }
    if (access_code) { 
    if(!cJSON_IsString(access_code) && !cJSON_IsNull(access_code))
    {
    goto end; //String
    }
    }

    // snapshot_sharing->shared_on
    cJSON *shared_on = cJSON_GetObjectItemCaseSensitive(snapshot_sharingJSON, "sharedOn");
    if (cJSON_IsNull(shared_on)) {
        shared_on = NULL;
    }
    if (shared_on) { 
    if(!cJSON_IsString(shared_on) && !cJSON_IsNull(shared_on))
    {
    goto end; //DateTime
    }
    }

    // snapshot_sharing->shared_by
    cJSON *shared_by = cJSON_GetObjectItemCaseSensitive(snapshot_sharingJSON, "sharedBy");
    if (cJSON_IsNull(shared_by)) {
        shared_by = NULL;
    }
    if (shared_by) { 
    shared_by_local_nonprim = snapshot_owner_parseFromJSON(shared_by); //nonprimitive
    }

    // snapshot_sharing->members
    cJSON *members = cJSON_GetObjectItemCaseSensitive(snapshot_sharingJSON, "members");
    if (cJSON_IsNull(members)) {
        members = NULL;
    }
    if (members) { 
    cJSON *members_local_nonprimitive = NULL;
    if(!cJSON_IsArray(members)){
        goto end; //nonprimitive container
    }

    membersList = list_createList();

    cJSON_ArrayForEach(members_local_nonprimitive,members )
    {
        if(!cJSON_IsObject(members_local_nonprimitive)){
            goto end;
        }
        snapshot_member_t *membersItem = snapshot_member_parseFromJSON(members_local_nonprimitive);

        list_addElement(membersList, membersItem);
    }
    }


    snapshot_sharing_local_var = snapshot_sharing_create_internal (
        sharing_type_local_nonprim,
        access_code && !cJSON_IsNull(access_code) ? strdup(access_code->valuestring) : NULL,
        shared_on && !cJSON_IsNull(shared_on) ? strdup(shared_on->valuestring) : NULL,
        shared_by ? shared_by_local_nonprim : NULL,
        members ? membersList : NULL
        );

    return snapshot_sharing_local_var;
end:
    if (sharing_type_local_nonprim) {
        sharing_type_local_nonprim = 0;
    }
    if (shared_by_local_nonprim) {
        snapshot_owner_free(shared_by_local_nonprim);
        shared_by_local_nonprim = NULL;
    }
    if (membersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, membersList) {
            snapshot_member_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(membersList);
        membersList = NULL;
    }
    return NULL;

}
