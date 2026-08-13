#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "snapshot_sharing_v1.h"


char* snapshot_sharing_v1_sharing_type_ToString(corellium_api_snapshot_sharing_v1_SHARINGTYPE_e sharing_type) {
    char* sharing_typeArray[] =  { "NULL", "publicLink", "domainRestrictedLink", "passwordPublicLink", "emailInvite" };
    return sharing_typeArray[sharing_type];
}

corellium_api_snapshot_sharing_v1_SHARINGTYPE_e snapshot_sharing_v1_sharing_type_FromString(char* sharing_type){
    int stringToReturn = 0;
    char *sharing_typeArray[] =  { "NULL", "publicLink", "domainRestrictedLink", "passwordPublicLink", "emailInvite" };
    size_t sizeofArray = sizeof(sharing_typeArray) / sizeof(sharing_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(sharing_type, sharing_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static snapshot_sharing_v1_t *snapshot_sharing_v1_create_internal(
    corellium_api_snapshot_sharing_v1_SHARINGTYPE_e sharing_type,
    snapshot_owner_t *shared_by,
    list_t *members
    ) {
    snapshot_sharing_v1_t *snapshot_sharing_v1_local_var = malloc(sizeof(snapshot_sharing_v1_t));
    if (!snapshot_sharing_v1_local_var) {
        return NULL;
    }
    snapshot_sharing_v1_local_var->sharing_type = sharing_type;
    snapshot_sharing_v1_local_var->shared_by = shared_by;
    snapshot_sharing_v1_local_var->members = members;

    snapshot_sharing_v1_local_var->_library_owned = 1;
    return snapshot_sharing_v1_local_var;
}

__attribute__((deprecated)) snapshot_sharing_v1_t *snapshot_sharing_v1_create(
    corellium_api_snapshot_sharing_v1_SHARINGTYPE_e sharing_type,
    snapshot_owner_t *shared_by,
    list_t *members
    ) {
    return snapshot_sharing_v1_create_internal (
        sharing_type,
        shared_by,
        members
        );
}

void snapshot_sharing_v1_free(snapshot_sharing_v1_t *snapshot_sharing_v1) {
    if(NULL == snapshot_sharing_v1){
        return ;
    }
    if(snapshot_sharing_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "snapshot_sharing_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (snapshot_sharing_v1->shared_by) {
        snapshot_owner_free(snapshot_sharing_v1->shared_by);
        snapshot_sharing_v1->shared_by = NULL;
    }
    if (snapshot_sharing_v1->members) {
        list_ForEach(listEntry, snapshot_sharing_v1->members) {
            snapshot_member_free(listEntry->data);
        }
        list_freeList(snapshot_sharing_v1->members);
        snapshot_sharing_v1->members = NULL;
    }
    free(snapshot_sharing_v1);
}

cJSON *snapshot_sharing_v1_convertToJSON(snapshot_sharing_v1_t *snapshot_sharing_v1) {
    cJSON *item = cJSON_CreateObject();

    // snapshot_sharing_v1->sharing_type
    if (corellium_api_snapshot_sharing_v1_SHARINGTYPE_NULL == snapshot_sharing_v1->sharing_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sharingType", snapshot_sharing_v1_sharing_type_ToString(snapshot_sharing_v1->sharing_type)) == NULL)
    {
    goto fail; //Enum
    }


    // snapshot_sharing_v1->shared_by
    if(snapshot_sharing_v1->shared_by) {
    cJSON *shared_by_local_JSON = snapshot_owner_convertToJSON(snapshot_sharing_v1->shared_by);
    if(shared_by_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "sharedBy", shared_by_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // snapshot_sharing_v1->members
    if(snapshot_sharing_v1->members) {
    cJSON *members = cJSON_AddArrayToObject(item, "members");
    if(members == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *membersListEntry;
    if (snapshot_sharing_v1->members) {
    list_ForEach(membersListEntry, snapshot_sharing_v1->members) {
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

snapshot_sharing_v1_t *snapshot_sharing_v1_parseFromJSON(cJSON *snapshot_sharing_v1JSON){

    snapshot_sharing_v1_t *snapshot_sharing_v1_local_var = NULL;

    // define the local variable for snapshot_sharing_v1->shared_by
    snapshot_owner_t *shared_by_local_nonprim = NULL;

    // define the local list for snapshot_sharing_v1->members
    list_t *membersList = NULL;

    // snapshot_sharing_v1->sharing_type
    cJSON *sharing_type = cJSON_GetObjectItemCaseSensitive(snapshot_sharing_v1JSON, "sharingType");
    if (cJSON_IsNull(sharing_type)) {
        sharing_type = NULL;
    }
    if (!sharing_type) {
        goto end;
    }

    corellium_api_snapshot_sharing_v1_SHARINGTYPE_e sharing_typeVariable;
    
    if(!cJSON_IsString(sharing_type))
    {
    goto end; //Enum
    }
    sharing_typeVariable = snapshot_sharing_v1_sharing_type_FromString(sharing_type->valuestring);

    // snapshot_sharing_v1->shared_by
    cJSON *shared_by = cJSON_GetObjectItemCaseSensitive(snapshot_sharing_v1JSON, "sharedBy");
    if (cJSON_IsNull(shared_by)) {
        shared_by = NULL;
    }
    if (shared_by) { 
    shared_by_local_nonprim = snapshot_owner_parseFromJSON(shared_by); //nonprimitive
    }

    // snapshot_sharing_v1->members
    cJSON *members = cJSON_GetObjectItemCaseSensitive(snapshot_sharing_v1JSON, "members");
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


    snapshot_sharing_v1_local_var = snapshot_sharing_v1_create_internal (
        sharing_typeVariable,
        shared_by ? shared_by_local_nonprim : NULL,
        members ? membersList : NULL
        );

    return snapshot_sharing_v1_local_var;
end:
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
