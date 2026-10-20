#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "totp_generate_response.h"



static totp_generate_response_t *totp_generate_response_create_internal(
    char *qr_code,
    char *secret
    ) {
    totp_generate_response_t *totp_generate_response_local_var = malloc(sizeof(totp_generate_response_t));
    if (!totp_generate_response_local_var) {
        return NULL;
    }
    totp_generate_response_local_var->qr_code = qr_code;
    totp_generate_response_local_var->secret = secret;

    totp_generate_response_local_var->_library_owned = 1;
    return totp_generate_response_local_var;
}

__attribute__((deprecated)) totp_generate_response_t *totp_generate_response_create(
    char *qr_code,
    char *secret
    ) {
    return totp_generate_response_create_internal (
        qr_code,
        secret
        );
}

void totp_generate_response_free(totp_generate_response_t *totp_generate_response) {
    if(NULL == totp_generate_response){
        return ;
    }
    if(totp_generate_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "totp_generate_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (totp_generate_response->qr_code) {
        free(totp_generate_response->qr_code);
        totp_generate_response->qr_code = NULL;
    }
    if (totp_generate_response->secret) {
        free(totp_generate_response->secret);
        totp_generate_response->secret = NULL;
    }
    free(totp_generate_response);
}

cJSON *totp_generate_response_convertToJSON(totp_generate_response_t *totp_generate_response) {
    cJSON *item = cJSON_CreateObject();

    // totp_generate_response->qr_code
    if (!totp_generate_response->qr_code) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "qrCode", totp_generate_response->qr_code) == NULL) {
    goto fail; //String
    }


    // totp_generate_response->secret
    if (!totp_generate_response->secret) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "secret", totp_generate_response->secret) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

totp_generate_response_t *totp_generate_response_parseFromJSON(cJSON *totp_generate_responseJSON){

    totp_generate_response_t *totp_generate_response_local_var = NULL;

    // totp_generate_response->qr_code
    cJSON *qr_code = cJSON_GetObjectItemCaseSensitive(totp_generate_responseJSON, "qrCode");
    if (cJSON_IsNull(qr_code)) {
        qr_code = NULL;
    }
    if (!qr_code) {
        goto end;
    }

    
    if(!cJSON_IsString(qr_code))
    {
    goto end; //String
    }

    // totp_generate_response->secret
    cJSON *secret = cJSON_GetObjectItemCaseSensitive(totp_generate_responseJSON, "secret");
    if (cJSON_IsNull(secret)) {
        secret = NULL;
    }
    if (!secret) {
        goto end;
    }

    
    if(!cJSON_IsString(secret))
    {
    goto end; //String
    }


    totp_generate_response_local_var = totp_generate_response_create_internal (
        strdup(qr_code->valuestring),
        strdup(secret->valuestring)
        );

    return totp_generate_response_local_var;
end:
    return NULL;

}
