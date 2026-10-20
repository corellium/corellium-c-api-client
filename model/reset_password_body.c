#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "reset_password_body.h"



static reset_password_body_t *reset_password_body_create_internal(
    char *token,
    char *new_password,
    char *totp_token
    ) {
    reset_password_body_t *reset_password_body_local_var = malloc(sizeof(reset_password_body_t));
    if (!reset_password_body_local_var) {
        return NULL;
    }
    reset_password_body_local_var->token = token;
    reset_password_body_local_var->new_password = new_password;
    reset_password_body_local_var->totp_token = totp_token;

    reset_password_body_local_var->_library_owned = 1;
    return reset_password_body_local_var;
}

__attribute__((deprecated)) reset_password_body_t *reset_password_body_create(
    char *token,
    char *new_password,
    char *totp_token
    ) {
    return reset_password_body_create_internal (
        token,
        new_password,
        totp_token
        );
}

void reset_password_body_free(reset_password_body_t *reset_password_body) {
    if(NULL == reset_password_body){
        return ;
    }
    if(reset_password_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "reset_password_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (reset_password_body->token) {
        free(reset_password_body->token);
        reset_password_body->token = NULL;
    }
    if (reset_password_body->new_password) {
        free(reset_password_body->new_password);
        reset_password_body->new_password = NULL;
    }
    if (reset_password_body->totp_token) {
        free(reset_password_body->totp_token);
        reset_password_body->totp_token = NULL;
    }
    free(reset_password_body);
}

cJSON *reset_password_body_convertToJSON(reset_password_body_t *reset_password_body) {
    cJSON *item = cJSON_CreateObject();

    // reset_password_body->token
    if (!reset_password_body->token) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "token", reset_password_body->token) == NULL) {
    goto fail; //String
    }


    // reset_password_body->new_password
    if (!reset_password_body->new_password) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "newPassword", reset_password_body->new_password) == NULL) {
    goto fail; //String
    }


    // reset_password_body->totp_token
    if(reset_password_body->totp_token) {
    if(cJSON_AddStringToObject(item, "totpToken", reset_password_body->totp_token) == NULL) {
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

reset_password_body_t *reset_password_body_parseFromJSON(cJSON *reset_password_bodyJSON){

    reset_password_body_t *reset_password_body_local_var = NULL;

    // reset_password_body->token
    cJSON *token = cJSON_GetObjectItemCaseSensitive(reset_password_bodyJSON, "token");
    if (cJSON_IsNull(token)) {
        token = NULL;
    }
    if (!token) {
        goto end;
    }

    
    if(!cJSON_IsString(token))
    {
    goto end; //String
    }

    // reset_password_body->new_password
    cJSON *new_password = cJSON_GetObjectItemCaseSensitive(reset_password_bodyJSON, "newPassword");
    if (cJSON_IsNull(new_password)) {
        new_password = NULL;
    }
    if (!new_password) {
        goto end;
    }

    
    if(!cJSON_IsString(new_password))
    {
    goto end; //String
    }

    // reset_password_body->totp_token
    cJSON *totp_token = cJSON_GetObjectItemCaseSensitive(reset_password_bodyJSON, "totpToken");
    if (cJSON_IsNull(totp_token)) {
        totp_token = NULL;
    }
    if (totp_token) { 
    if(!cJSON_IsString(totp_token) && !cJSON_IsNull(totp_token))
    {
    goto end; //String
    }
    }


    reset_password_body_local_var = reset_password_body_create_internal (
        strdup(token->valuestring),
        strdup(new_password->valuestring),
        totp_token && !cJSON_IsNull(totp_token) ? strdup(totp_token->valuestring) : NULL
        );

    return reset_password_body_local_var;
end:
    return NULL;

}
