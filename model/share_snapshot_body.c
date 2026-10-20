#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "share_snapshot_body.h"



static share_snapshot_body_t *share_snapshot_body_create_internal(
    corellium_api_snapshot_sharing_type__e sharing_type,
    char *password
    ) {
    share_snapshot_body_t *share_snapshot_body_local_var = malloc(sizeof(share_snapshot_body_t));
    if (!share_snapshot_body_local_var) {
        return NULL;
    }
    share_snapshot_body_local_var->sharing_type = sharing_type;
    share_snapshot_body_local_var->password = password;

    share_snapshot_body_local_var->_library_owned = 1;
    return share_snapshot_body_local_var;
}

__attribute__((deprecated)) share_snapshot_body_t *share_snapshot_body_create(
    corellium_api_snapshot_sharing_type__e sharing_type,
    char *password
    ) {
    return share_snapshot_body_create_internal (
        sharing_type,
        password
        );
}

void share_snapshot_body_free(share_snapshot_body_t *share_snapshot_body) {
    if(NULL == share_snapshot_body){
        return ;
    }
    if(share_snapshot_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "share_snapshot_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (share_snapshot_body->password) {
        free(share_snapshot_body->password);
        share_snapshot_body->password = NULL;
    }
    free(share_snapshot_body);
}

cJSON *share_snapshot_body_convertToJSON(share_snapshot_body_t *share_snapshot_body) {
    cJSON *item = cJSON_CreateObject();

    // share_snapshot_body->sharing_type
    if (corellium_api_snapshot_sharing_type__NULL == share_snapshot_body->sharing_type) {
        goto fail;
    }
    cJSON *sharing_type_local_JSON = snapshot_sharing_type_convertToJSON(share_snapshot_body->sharing_type);
    if(sharing_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "sharingType", sharing_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // share_snapshot_body->password
    if(share_snapshot_body->password) {
    if(cJSON_AddStringToObject(item, "password", share_snapshot_body->password) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

share_snapshot_body_t *share_snapshot_body_parseFromJSON(cJSON *share_snapshot_bodyJSON){

    share_snapshot_body_t *share_snapshot_body_local_var = NULL;

    // define the local variable for share_snapshot_body->sharing_type
    corellium_api_snapshot_sharing_type__e sharing_type_local_nonprim = 0;

    // share_snapshot_body->sharing_type
    cJSON *sharing_type = cJSON_GetObjectItemCaseSensitive(share_snapshot_bodyJSON, "sharingType");
    if (cJSON_IsNull(sharing_type)) {
        sharing_type = NULL;
    }
    if (!sharing_type) {
        goto end;
    }

    
    sharing_type_local_nonprim = snapshot_sharing_type_parseFromJSON(sharing_type); //custom

    // share_snapshot_body->password
    cJSON *password = cJSON_GetObjectItemCaseSensitive(share_snapshot_bodyJSON, "password");
    if (cJSON_IsNull(password)) {
        password = NULL;
    }
    if (password) { 
    if(!cJSON_IsString(password) && !cJSON_IsNull(password))
    {
    goto end; //String
    }
    }


    share_snapshot_body_local_var = share_snapshot_body_create_internal (
        sharing_type_local_nonprim,
        password && !cJSON_IsNull(password) ? strdup(password->valuestring) : NULL
        );

    return share_snapshot_body_local_var;
end:
    if (sharing_type_local_nonprim) {
        sharing_type_local_nonprim = 0;
    }
    return NULL;

}
