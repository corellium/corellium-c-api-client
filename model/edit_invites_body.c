#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "edit_invites_body.h"



static edit_invites_body_t *edit_invites_body_create_internal(
    list_t *ids,
    edit_invites_body_changes_t *changes
    ) {
    edit_invites_body_t *edit_invites_body_local_var = malloc(sizeof(edit_invites_body_t));
    if (!edit_invites_body_local_var) {
        return NULL;
    }
    edit_invites_body_local_var->ids = ids;
    edit_invites_body_local_var->changes = changes;

    edit_invites_body_local_var->_library_owned = 1;
    return edit_invites_body_local_var;
}

__attribute__((deprecated)) edit_invites_body_t *edit_invites_body_create(
    list_t *ids,
    edit_invites_body_changes_t *changes
    ) {
    return edit_invites_body_create_internal (
        ids,
        changes
        );
}

void edit_invites_body_free(edit_invites_body_t *edit_invites_body) {
    if(NULL == edit_invites_body){
        return ;
    }
    if(edit_invites_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "edit_invites_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (edit_invites_body->ids) {
        list_ForEach(listEntry, edit_invites_body->ids) {
            free(listEntry->data);
        }
        list_freeList(edit_invites_body->ids);
        edit_invites_body->ids = NULL;
    }
    if (edit_invites_body->changes) {
        edit_invites_body_changes_free(edit_invites_body->changes);
        edit_invites_body->changes = NULL;
    }
    free(edit_invites_body);
}

cJSON *edit_invites_body_convertToJSON(edit_invites_body_t *edit_invites_body) {
    cJSON *item = cJSON_CreateObject();

    // edit_invites_body->ids
    if (!edit_invites_body->ids) {
        goto fail;
    }
    cJSON *ids = cJSON_AddArrayToObject(item, "ids");
    if(ids == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *idsListEntry;
    list_ForEach(idsListEntry, edit_invites_body->ids) {
    if(cJSON_AddStringToObject(ids, "", idsListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // edit_invites_body->changes
    if (!edit_invites_body->changes) {
        goto fail;
    }
    cJSON *changes_local_JSON = edit_invites_body_changes_convertToJSON(edit_invites_body->changes);
    if(changes_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "changes", changes_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

edit_invites_body_t *edit_invites_body_parseFromJSON(cJSON *edit_invites_bodyJSON){

    edit_invites_body_t *edit_invites_body_local_var = NULL;

    // define the local list for edit_invites_body->ids
    list_t *idsList = NULL;

    // define the local variable for edit_invites_body->changes
    edit_invites_body_changes_t *changes_local_nonprim = NULL;

    // edit_invites_body->ids
    cJSON *ids = cJSON_GetObjectItemCaseSensitive(edit_invites_bodyJSON, "ids");
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

    // edit_invites_body->changes
    cJSON *changes = cJSON_GetObjectItemCaseSensitive(edit_invites_bodyJSON, "changes");
    if (cJSON_IsNull(changes)) {
        changes = NULL;
    }
    if (!changes) {
        goto end;
    }

    
    changes_local_nonprim = edit_invites_body_changes_parseFromJSON(changes); //nonprimitive


    edit_invites_body_local_var = edit_invites_body_create_internal (
        idsList,
        changes_local_nonprim
        );

    return edit_invites_body_local_var;
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
    if (changes_local_nonprim) {
        edit_invites_body_changes_free(changes_local_nonprim);
        changes_local_nonprim = NULL;
    }
    return NULL;

}
