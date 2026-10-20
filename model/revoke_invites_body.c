#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "revoke_invites_body.h"



static revoke_invites_body_t *revoke_invites_body_create_internal(
    list_t *ids
    ) {
    revoke_invites_body_t *revoke_invites_body_local_var = malloc(sizeof(revoke_invites_body_t));
    if (!revoke_invites_body_local_var) {
        return NULL;
    }
    revoke_invites_body_local_var->ids = ids;

    revoke_invites_body_local_var->_library_owned = 1;
    return revoke_invites_body_local_var;
}

__attribute__((deprecated)) revoke_invites_body_t *revoke_invites_body_create(
    list_t *ids
    ) {
    return revoke_invites_body_create_internal (
        ids
        );
}

void revoke_invites_body_free(revoke_invites_body_t *revoke_invites_body) {
    if(NULL == revoke_invites_body){
        return ;
    }
    if(revoke_invites_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "revoke_invites_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (revoke_invites_body->ids) {
        list_ForEach(listEntry, revoke_invites_body->ids) {
            free(listEntry->data);
        }
        list_freeList(revoke_invites_body->ids);
        revoke_invites_body->ids = NULL;
    }
    free(revoke_invites_body);
}

cJSON *revoke_invites_body_convertToJSON(revoke_invites_body_t *revoke_invites_body) {
    cJSON *item = cJSON_CreateObject();

    // revoke_invites_body->ids
    if (!revoke_invites_body->ids) {
        goto fail;
    }
    cJSON *ids = cJSON_AddArrayToObject(item, "ids");
    if(ids == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *idsListEntry;
    list_ForEach(idsListEntry, revoke_invites_body->ids) {
    if(cJSON_AddStringToObject(ids, "", idsListEntry->data) == NULL)
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

revoke_invites_body_t *revoke_invites_body_parseFromJSON(cJSON *revoke_invites_bodyJSON){

    revoke_invites_body_t *revoke_invites_body_local_var = NULL;

    // define the local list for revoke_invites_body->ids
    list_t *idsList = NULL;

    // revoke_invites_body->ids
    cJSON *ids = cJSON_GetObjectItemCaseSensitive(revoke_invites_bodyJSON, "ids");
    if (cJSON_IsNull(ids)) {
        ids = NULL;
    }
    if (!ids) {
        goto end;
    }

    
    cJSON *ids_local = NULL;
    if(!cJSON_IsArray(ids)) {
        goto end;//primitive container
    }
    idsList = list_createList();

    cJSON_ArrayForEach(ids_local, ids)
    {
        if(!cJSON_IsString(ids_local))
        {
            goto end;
        }
        list_addElement(idsList , strdup(ids_local->valuestring));
    }


    revoke_invites_body_local_var = revoke_invites_body_create_internal (
        idsList
        );

    return revoke_invites_body_local_var;
end:
    if (idsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, idsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(idsList);
        idsList = NULL;
    }
    return NULL;

}
