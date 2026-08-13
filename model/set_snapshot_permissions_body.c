#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "set_snapshot_permissions_body.h"



static set_snapshot_permissions_body_t *set_snapshot_permissions_body_create_internal(
    list_t *members
    ) {
    set_snapshot_permissions_body_t *set_snapshot_permissions_body_local_var = malloc(sizeof(set_snapshot_permissions_body_t));
    if (!set_snapshot_permissions_body_local_var) {
        return NULL;
    }
    set_snapshot_permissions_body_local_var->members = members;

    set_snapshot_permissions_body_local_var->_library_owned = 1;
    return set_snapshot_permissions_body_local_var;
}

__attribute__((deprecated)) set_snapshot_permissions_body_t *set_snapshot_permissions_body_create(
    list_t *members
    ) {
    return set_snapshot_permissions_body_create_internal (
        members
        );
}

void set_snapshot_permissions_body_free(set_snapshot_permissions_body_t *set_snapshot_permissions_body) {
    if(NULL == set_snapshot_permissions_body){
        return ;
    }
    if(set_snapshot_permissions_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "set_snapshot_permissions_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (set_snapshot_permissions_body->members) {
        list_ForEach(listEntry, set_snapshot_permissions_body->members) {
            free(listEntry->data);
        }
        list_freeList(set_snapshot_permissions_body->members);
        set_snapshot_permissions_body->members = NULL;
    }
    free(set_snapshot_permissions_body);
}

cJSON *set_snapshot_permissions_body_convertToJSON(set_snapshot_permissions_body_t *set_snapshot_permissions_body) {
    cJSON *item = cJSON_CreateObject();

    // set_snapshot_permissions_body->members
    if (!set_snapshot_permissions_body->members) {
        goto fail;
    }
    cJSON *members = cJSON_AddArrayToObject(item, "members");
    if(members == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *membersListEntry;
    list_ForEach(membersListEntry, set_snapshot_permissions_body->members) {
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

set_snapshot_permissions_body_t *set_snapshot_permissions_body_parseFromJSON(cJSON *set_snapshot_permissions_bodyJSON){

    set_snapshot_permissions_body_t *set_snapshot_permissions_body_local_var = NULL;

    // define the local list for set_snapshot_permissions_body->members
    list_t *membersList = NULL;

    // set_snapshot_permissions_body->members
    cJSON *members = cJSON_GetObjectItemCaseSensitive(set_snapshot_permissions_bodyJSON, "members");
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


    set_snapshot_permissions_body_local_var = set_snapshot_permissions_body_create_internal (
        membersList
        );

    return set_snapshot_permissions_body_local_var;
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
