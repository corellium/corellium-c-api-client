#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "snapshot_permissions_request_payload.h"



static snapshot_permissions_request_payload_t *snapshot_permissions_request_payload_create_internal(
    list_t *members
    ) {
    snapshot_permissions_request_payload_t *snapshot_permissions_request_payload_local_var = malloc(sizeof(snapshot_permissions_request_payload_t));
    if (!snapshot_permissions_request_payload_local_var) {
        return NULL;
    }
    snapshot_permissions_request_payload_local_var->members = members;

    snapshot_permissions_request_payload_local_var->_library_owned = 1;
    return snapshot_permissions_request_payload_local_var;
}

__attribute__((deprecated)) snapshot_permissions_request_payload_t *snapshot_permissions_request_payload_create(
    list_t *members
    ) {
    return snapshot_permissions_request_payload_create_internal (
        members
        );
}

void snapshot_permissions_request_payload_free(snapshot_permissions_request_payload_t *snapshot_permissions_request_payload) {
    if(NULL == snapshot_permissions_request_payload){
        return ;
    }
    if(snapshot_permissions_request_payload->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "snapshot_permissions_request_payload_free");
        return ;
    }
    listEntry_t *listEntry;
    if (snapshot_permissions_request_payload->members) {
        list_ForEach(listEntry, snapshot_permissions_request_payload->members) {
            free(listEntry->data);
        }
        list_freeList(snapshot_permissions_request_payload->members);
        snapshot_permissions_request_payload->members = NULL;
    }
    free(snapshot_permissions_request_payload);
}

cJSON *snapshot_permissions_request_payload_convertToJSON(snapshot_permissions_request_payload_t *snapshot_permissions_request_payload) {
    cJSON *item = cJSON_CreateObject();

    // snapshot_permissions_request_payload->members
    if (!snapshot_permissions_request_payload->members) {
        goto fail;
    }
    cJSON *members = cJSON_AddArrayToObject(item, "members");
    if(members == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *membersListEntry;
    list_ForEach(membersListEntry, snapshot_permissions_request_payload->members) {
    if(cJSON_AddStringToObject(members, "", membersListEntry->data) == NULL)
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

snapshot_permissions_request_payload_t *snapshot_permissions_request_payload_parseFromJSON(cJSON *snapshot_permissions_request_payloadJSON){

    snapshot_permissions_request_payload_t *snapshot_permissions_request_payload_local_var = NULL;

    // define the local list for snapshot_permissions_request_payload->members
    list_t *membersList = NULL;

    // snapshot_permissions_request_payload->members
    cJSON *members = cJSON_GetObjectItemCaseSensitive(snapshot_permissions_request_payloadJSON, "members");
    if (cJSON_IsNull(members)) {
        members = NULL;
    }
    if (!members) {
        goto end;
    }

    
    cJSON *members_local = NULL;
    if(!cJSON_IsArray(members)) {
        goto end;//primitive container
    }
    membersList = list_createList();

    cJSON_ArrayForEach(members_local, members)
    {
        if(!cJSON_IsString(members_local))
        {
            goto end;
        }
        list_addElement(membersList , strdup(members_local->valuestring));
    }


    snapshot_permissions_request_payload_local_var = snapshot_permissions_request_payload_create_internal (
        membersList
        );

    return snapshot_permissions_request_payload_local_var;
end:
    if (membersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, membersList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(membersList);
        membersList = NULL;
    }
    return NULL;

}
