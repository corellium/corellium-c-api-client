#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "totp_enable_body.h"



static totp_enable_body_t *totp_enable_body_create_internal(
    char *secret,
    char *totp_token,
    char *password
    ) {
    totp_enable_body_t *totp_enable_body_local_var = malloc(sizeof(totp_enable_body_t));
    if (!totp_enable_body_local_var) {
        return NULL;
    }
    totp_enable_body_local_var->secret = secret;
    totp_enable_body_local_var->totp_token = totp_token;
    totp_enable_body_local_var->password = password;

    totp_enable_body_local_var->_library_owned = 1;
    return totp_enable_body_local_var;
}

__attribute__((deprecated)) totp_enable_body_t *totp_enable_body_create(
    char *secret,
    char *totp_token,
    char *password
    ) {
    return totp_enable_body_create_internal (
        secret,
        totp_token,
        password
        );
}

void totp_enable_body_free(totp_enable_body_t *totp_enable_body) {
    if(NULL == totp_enable_body){
        return ;
    }
    if(totp_enable_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "totp_enable_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (totp_enable_body->secret) {
        free(totp_enable_body->secret);
        totp_enable_body->secret = NULL;
    }
    if (totp_enable_body->totp_token) {
        free(totp_enable_body->totp_token);
        totp_enable_body->totp_token = NULL;
    }
    if (totp_enable_body->password) {
        free(totp_enable_body->password);
        totp_enable_body->password = NULL;
    }
    free(totp_enable_body);
}

cJSON *totp_enable_body_convertToJSON(totp_enable_body_t *totp_enable_body) {
    cJSON *item = cJSON_CreateObject();

    // totp_enable_body->secret
    if (!totp_enable_body->secret) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "secret", totp_enable_body->secret) == NULL) {
    goto fail; //String
    }


    // totp_enable_body->totp_token
    if (!totp_enable_body->totp_token) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "totpToken", totp_enable_body->totp_token) == NULL) {
    goto fail; //String
    }


    // totp_enable_body->password
    if (!totp_enable_body->password) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "password", totp_enable_body->password) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

totp_enable_body_t *totp_enable_body_parseFromJSON(cJSON *totp_enable_bodyJSON){

    totp_enable_body_t *totp_enable_body_local_var = NULL;

    // totp_enable_body->secret
    cJSON *secret = cJSON_GetObjectItemCaseSensitive(totp_enable_bodyJSON, "secret");
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

    // totp_enable_body->totp_token
    cJSON *totp_token = cJSON_GetObjectItemCaseSensitive(totp_enable_bodyJSON, "totpToken");
    if (cJSON_IsNull(totp_token)) {
        totp_token = NULL;
    }
    if (!totp_token) {
        goto end;
    }

    
    if(!cJSON_IsString(totp_token))
    {
    goto end; //String
    }

    // totp_enable_body->password
    cJSON *password = cJSON_GetObjectItemCaseSensitive(totp_enable_bodyJSON, "password");
    if (cJSON_IsNull(password)) {
        password = NULL;
    }
    if (!password) {
        goto end;
    }

    
    if(!cJSON_IsString(password))
    {
    goto end; //String
    }


    totp_enable_body_local_var = totp_enable_body_create_internal (
        strdup(secret->valuestring),
        strdup(totp_token->valuestring),
        strdup(password->valuestring)
        );

    return totp_enable_body_local_var;
end:
    return NULL;

}
