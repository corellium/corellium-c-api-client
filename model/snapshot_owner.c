#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "snapshot_owner.h"



static snapshot_owner_t *snapshot_owner_create_internal(
    char *name,
    char *email
    ) {
    snapshot_owner_t *snapshot_owner_local_var = malloc(sizeof(snapshot_owner_t));
    if (!snapshot_owner_local_var) {
        return NULL;
    }
    snapshot_owner_local_var->name = name;
    snapshot_owner_local_var->email = email;

    snapshot_owner_local_var->_library_owned = 1;
    return snapshot_owner_local_var;
}

__attribute__((deprecated)) snapshot_owner_t *snapshot_owner_create(
    char *name,
    char *email
    ) {
    return snapshot_owner_create_internal (
        name,
        email
        );
}

void snapshot_owner_free(snapshot_owner_t *snapshot_owner) {
    if(NULL == snapshot_owner){
        return ;
    }
    if(snapshot_owner->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "snapshot_owner_free");
        return ;
    }
    listEntry_t *listEntry;
    if (snapshot_owner->name) {
        free(snapshot_owner->name);
        snapshot_owner->name = NULL;
    }
    if (snapshot_owner->email) {
        free(snapshot_owner->email);
        snapshot_owner->email = NULL;
    }
    free(snapshot_owner);
}

cJSON *snapshot_owner_convertToJSON(snapshot_owner_t *snapshot_owner) {
    cJSON *item = cJSON_CreateObject();

    // snapshot_owner->name
    if (!snapshot_owner->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", snapshot_owner->name) == NULL) {
    goto fail; //String
    }


    // snapshot_owner->email
    if (!snapshot_owner->email) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "email", snapshot_owner->email) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

snapshot_owner_t *snapshot_owner_parseFromJSON(cJSON *snapshot_ownerJSON){

    snapshot_owner_t *snapshot_owner_local_var = NULL;

    // snapshot_owner->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(snapshot_ownerJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // snapshot_owner->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(snapshot_ownerJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (!email) {
        goto end;
    }

    
    if(!cJSON_IsString(email))
    {
    goto end; //String
    }


    snapshot_owner_local_var = snapshot_owner_create_internal (
        strdup(name->valuestring),
        strdup(email->valuestring)
        );

    return snapshot_owner_local_var;
end:
    return NULL;

}
