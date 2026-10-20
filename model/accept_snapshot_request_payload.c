#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "accept_snapshot_request_payload.h"



static accept_snapshot_request_payload_t *accept_snapshot_request_payload_create_internal(
    char *access_code,
    char *password
    ) {
    accept_snapshot_request_payload_t *accept_snapshot_request_payload_local_var = malloc(sizeof(accept_snapshot_request_payload_t));
    if (!accept_snapshot_request_payload_local_var) {
        return NULL;
    }
    accept_snapshot_request_payload_local_var->access_code = access_code;
    accept_snapshot_request_payload_local_var->password = password;

    accept_snapshot_request_payload_local_var->_library_owned = 1;
    return accept_snapshot_request_payload_local_var;
}

__attribute__((deprecated)) accept_snapshot_request_payload_t *accept_snapshot_request_payload_create(
    char *access_code,
    char *password
    ) {
    return accept_snapshot_request_payload_create_internal (
        access_code,
        password
        );
}

void accept_snapshot_request_payload_free(accept_snapshot_request_payload_t *accept_snapshot_request_payload) {
    if(NULL == accept_snapshot_request_payload){
        return ;
    }
    if(accept_snapshot_request_payload->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "accept_snapshot_request_payload_free");
        return ;
    }
    listEntry_t *listEntry;
    if (accept_snapshot_request_payload->access_code) {
        free(accept_snapshot_request_payload->access_code);
        accept_snapshot_request_payload->access_code = NULL;
    }
    if (accept_snapshot_request_payload->password) {
        free(accept_snapshot_request_payload->password);
        accept_snapshot_request_payload->password = NULL;
    }
    free(accept_snapshot_request_payload);
}

cJSON *accept_snapshot_request_payload_convertToJSON(accept_snapshot_request_payload_t *accept_snapshot_request_payload) {
    cJSON *item = cJSON_CreateObject();

    // accept_snapshot_request_payload->access_code
    if (!accept_snapshot_request_payload->access_code) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "accessCode", accept_snapshot_request_payload->access_code) == NULL) {
    goto fail; //String
    }


    // accept_snapshot_request_payload->password
    if(accept_snapshot_request_payload->password) {
    if(cJSON_AddStringToObject(item, "password", accept_snapshot_request_payload->password) == NULL) {
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

accept_snapshot_request_payload_t *accept_snapshot_request_payload_parseFromJSON(cJSON *accept_snapshot_request_payloadJSON){

    accept_snapshot_request_payload_t *accept_snapshot_request_payload_local_var = NULL;

    // accept_snapshot_request_payload->access_code
    cJSON *access_code = cJSON_GetObjectItemCaseSensitive(accept_snapshot_request_payloadJSON, "accessCode");
    if (cJSON_IsNull(access_code)) {
        access_code = NULL;
    }
    if (!access_code) {
        goto end;
    }

    
    if(!cJSON_IsString(access_code))
    {
    goto end; //String
    }

    // accept_snapshot_request_payload->password
    cJSON *password = cJSON_GetObjectItemCaseSensitive(accept_snapshot_request_payloadJSON, "password");
    if (cJSON_IsNull(password)) {
        password = NULL;
    }
    if (password) { 
    if(!cJSON_IsString(password) && !cJSON_IsNull(password))
    {
    goto end; //String
    }
    }


    accept_snapshot_request_payload_local_var = accept_snapshot_request_payload_create_internal (
        strdup(access_code->valuestring),
        password && !cJSON_IsNull(password) ? strdup(password->valuestring) : NULL
        );

    return accept_snapshot_request_payload_local_var;
end:
    return NULL;

}
