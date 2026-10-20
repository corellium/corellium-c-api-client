#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "invite_revoke_params.h"



static invite_revoke_params_t *invite_revoke_params_create_internal(
    list_t *ids
    ) {
    invite_revoke_params_t *invite_revoke_params_local_var = malloc(sizeof(invite_revoke_params_t));
    if (!invite_revoke_params_local_var) {
        return NULL;
    }
    invite_revoke_params_local_var->ids = ids;

    invite_revoke_params_local_var->_library_owned = 1;
    return invite_revoke_params_local_var;
}

__attribute__((deprecated)) invite_revoke_params_t *invite_revoke_params_create(
    list_t *ids
    ) {
    return invite_revoke_params_create_internal (
        ids
        );
}

void invite_revoke_params_free(invite_revoke_params_t *invite_revoke_params) {
    if(NULL == invite_revoke_params){
        return ;
    }
    if(invite_revoke_params->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "invite_revoke_params_free");
        return ;
    }
    listEntry_t *listEntry;
    if (invite_revoke_params->ids) {
        list_ForEach(listEntry, invite_revoke_params->ids) {
            free(listEntry->data);
        }
        list_freeList(invite_revoke_params->ids);
        invite_revoke_params->ids = NULL;
    }
    free(invite_revoke_params);
}

cJSON *invite_revoke_params_convertToJSON(invite_revoke_params_t *invite_revoke_params) {
    cJSON *item = cJSON_CreateObject();

    // invite_revoke_params->ids
    if(invite_revoke_params->ids) {
    cJSON *ids = cJSON_AddArrayToObject(item, "ids");
    if(ids == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *idsListEntry;
    list_ForEach(idsListEntry, invite_revoke_params->ids) {
    if(cJSON_AddStringToObject(ids, "", idsListEntry->data) == NULL)
    {
        goto fail;
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

invite_revoke_params_t *invite_revoke_params_parseFromJSON(cJSON *invite_revoke_paramsJSON){

    invite_revoke_params_t *invite_revoke_params_local_var = NULL;

    // define the local list for invite_revoke_params->ids
    list_t *idsList = NULL;

    // invite_revoke_params->ids
    cJSON *ids = cJSON_GetObjectItemCaseSensitive(invite_revoke_paramsJSON, "ids");
    if (cJSON_IsNull(ids)) {
        ids = NULL;
    }
    if (ids) { 
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
    }


    invite_revoke_params_local_var = invite_revoke_params_create_internal (
        ids ? idsList : NULL
        );

    return invite_revoke_params_local_var;
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
