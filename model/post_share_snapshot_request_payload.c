#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_share_snapshot_request_payload.h"



static post_share_snapshot_request_payload_t *post_share_snapshot_request_payload_create_internal(
    char *sharing_type,
    char *password
    ) {
    post_share_snapshot_request_payload_t *post_share_snapshot_request_payload_local_var = malloc(sizeof(post_share_snapshot_request_payload_t));
    if (!post_share_snapshot_request_payload_local_var) {
        return NULL;
    }
    post_share_snapshot_request_payload_local_var->sharing_type = sharing_type;
    post_share_snapshot_request_payload_local_var->password = password;

    post_share_snapshot_request_payload_local_var->_library_owned = 1;
    return post_share_snapshot_request_payload_local_var;
}

__attribute__((deprecated)) post_share_snapshot_request_payload_t *post_share_snapshot_request_payload_create(
    char *sharing_type,
    char *password
    ) {
    return post_share_snapshot_request_payload_create_internal (
        sharing_type,
        password
        );
}

void post_share_snapshot_request_payload_free(post_share_snapshot_request_payload_t *post_share_snapshot_request_payload) {
    if(NULL == post_share_snapshot_request_payload){
        return ;
    }
    if(post_share_snapshot_request_payload->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_share_snapshot_request_payload_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_share_snapshot_request_payload->sharing_type) {
        free(post_share_snapshot_request_payload->sharing_type);
        post_share_snapshot_request_payload->sharing_type = NULL;
    }
    if (post_share_snapshot_request_payload->password) {
        free(post_share_snapshot_request_payload->password);
        post_share_snapshot_request_payload->password = NULL;
    }
    free(post_share_snapshot_request_payload);
}

cJSON *post_share_snapshot_request_payload_convertToJSON(post_share_snapshot_request_payload_t *post_share_snapshot_request_payload) {
    cJSON *item = cJSON_CreateObject();

    // post_share_snapshot_request_payload->sharing_type
    if (!post_share_snapshot_request_payload->sharing_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sharingType", post_share_snapshot_request_payload->sharing_type) == NULL) {
    goto fail; //String
    }


    // post_share_snapshot_request_payload->password
    if(post_share_snapshot_request_payload->password) {
    if(cJSON_AddStringToObject(item, "password", post_share_snapshot_request_payload->password) == NULL) {
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

post_share_snapshot_request_payload_t *post_share_snapshot_request_payload_parseFromJSON(cJSON *post_share_snapshot_request_payloadJSON){

    post_share_snapshot_request_payload_t *post_share_snapshot_request_payload_local_var = NULL;

    // post_share_snapshot_request_payload->sharing_type
    cJSON *sharing_type = cJSON_GetObjectItemCaseSensitive(post_share_snapshot_request_payloadJSON, "sharingType");
    if (cJSON_IsNull(sharing_type)) {
        sharing_type = NULL;
    }
    if (!sharing_type) {
        goto end;
    }

    
    if(!cJSON_IsString(sharing_type))
    {
    goto end; //String
    }

    // post_share_snapshot_request_payload->password
    cJSON *password = cJSON_GetObjectItemCaseSensitive(post_share_snapshot_request_payloadJSON, "password");
    if (cJSON_IsNull(password)) {
        password = NULL;
    }
    if (password) { 
    if(!cJSON_IsString(password) && !cJSON_IsNull(password))
    {
    goto end; //String
    }
    }


    post_share_snapshot_request_payload_local_var = post_share_snapshot_request_payload_create_internal (
        strdup(sharing_type->valuestring),
        password && !cJSON_IsNull(password) ? strdup(password->valuestring) : NULL
        );

    return post_share_snapshot_request_payload_local_var;
end:
    return NULL;

}
