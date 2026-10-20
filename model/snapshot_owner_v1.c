#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "snapshot_owner_v1.h"



static snapshot_owner_v1_t *snapshot_owner_v1_create_internal(
    char *name,
    char *email
    ) {
    snapshot_owner_v1_t *snapshot_owner_v1_local_var = malloc(sizeof(snapshot_owner_v1_t));
    if (!snapshot_owner_v1_local_var) {
        return NULL;
    }
    snapshot_owner_v1_local_var->name = name;
    snapshot_owner_v1_local_var->email = email;

    snapshot_owner_v1_local_var->_library_owned = 1;
    return snapshot_owner_v1_local_var;
}

__attribute__((deprecated)) snapshot_owner_v1_t *snapshot_owner_v1_create(
    char *name,
    char *email
    ) {
    return snapshot_owner_v1_create_internal (
        name,
        email
        );
}

void snapshot_owner_v1_free(snapshot_owner_v1_t *snapshot_owner_v1) {
    if(NULL == snapshot_owner_v1){
        return ;
    }
    if(snapshot_owner_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "snapshot_owner_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (snapshot_owner_v1->name) {
        free(snapshot_owner_v1->name);
        snapshot_owner_v1->name = NULL;
    }
    if (snapshot_owner_v1->email) {
        free(snapshot_owner_v1->email);
        snapshot_owner_v1->email = NULL;
    }
    free(snapshot_owner_v1);
}

cJSON *snapshot_owner_v1_convertToJSON(snapshot_owner_v1_t *snapshot_owner_v1) {
    cJSON *item = cJSON_CreateObject();

    // snapshot_owner_v1->name
    if (!snapshot_owner_v1->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", snapshot_owner_v1->name) == NULL) {
    goto fail; //String
    }


    // snapshot_owner_v1->email
    if (!snapshot_owner_v1->email) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "email", snapshot_owner_v1->email) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

snapshot_owner_v1_t *snapshot_owner_v1_parseFromJSON(cJSON *snapshot_owner_v1JSON){

    snapshot_owner_v1_t *snapshot_owner_v1_local_var = NULL;

    // snapshot_owner_v1->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(snapshot_owner_v1JSON, "name");
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

    // snapshot_owner_v1->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(snapshot_owner_v1JSON, "email");
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


    snapshot_owner_v1_local_var = snapshot_owner_v1_create_internal (
        strdup(name->valuestring),
        strdup(email->valuestring)
        );

    return snapshot_owner_v1_local_var;
end:
    return NULL;

}
