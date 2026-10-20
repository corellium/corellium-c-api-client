#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "login_body.h"



static login_body_t *login_body_create_internal(
    char *username,
    char *password,
    char *totp_token,
    char *api_token,
    char *token,
    int revoke_old
    ) {
    login_body_t *login_body_local_var = malloc(sizeof(login_body_t));
    if (!login_body_local_var) {
        return NULL;
    }
    login_body_local_var->username = username;
    login_body_local_var->password = password;
    login_body_local_var->totp_token = totp_token;
    login_body_local_var->api_token = api_token;
    login_body_local_var->token = token;
    login_body_local_var->revoke_old = revoke_old;

    login_body_local_var->_library_owned = 1;
    return login_body_local_var;
}

__attribute__((deprecated)) login_body_t *login_body_create(
    char *username,
    char *password,
    char *totp_token,
    char *api_token,
    char *token,
    int revoke_old
    ) {
    return login_body_create_internal (
        username,
        password,
        totp_token,
        api_token,
        token,
        revoke_old
        );
}

void login_body_free(login_body_t *login_body) {
    if(NULL == login_body){
        return ;
    }
    if(login_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "login_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (login_body->username) {
        free(login_body->username);
        login_body->username = NULL;
    }
    if (login_body->password) {
        free(login_body->password);
        login_body->password = NULL;
    }
    if (login_body->totp_token) {
        free(login_body->totp_token);
        login_body->totp_token = NULL;
    }
    if (login_body->api_token) {
        free(login_body->api_token);
        login_body->api_token = NULL;
    }
    if (login_body->token) {
        free(login_body->token);
        login_body->token = NULL;
    }
    free(login_body);
}

cJSON *login_body_convertToJSON(login_body_t *login_body) {
    cJSON *item = cJSON_CreateObject();

    // login_body->username
    if(login_body->username) {
    if(cJSON_AddStringToObject(item, "username", login_body->username) == NULL) {
    goto fail; //String
    }
    }


    // login_body->password
    if(login_body->password) {
    if(cJSON_AddStringToObject(item, "password", login_body->password) == NULL) {
    goto fail; //String
    }
    }


    // login_body->totp_token
    if(login_body->totp_token) {
    if(cJSON_AddStringToObject(item, "totpToken", login_body->totp_token) == NULL) {
    goto fail; //String
    }
    }


    // login_body->api_token
    if(login_body->api_token) {
    if(cJSON_AddStringToObject(item, "apiToken", login_body->api_token) == NULL) {
    goto fail; //String
    }
    }


    // login_body->token
    if(login_body->token) {
    if(cJSON_AddStringToObject(item, "token", login_body->token) == NULL) {
    goto fail; //String
    }
    }


    // login_body->revoke_old
    if(login_body->revoke_old) {
    if(cJSON_AddBoolToObject(item, "revokeOld", login_body->revoke_old) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

login_body_t *login_body_parseFromJSON(cJSON *login_bodyJSON){

    login_body_t *login_body_local_var = NULL;

    // login_body->username
    cJSON *username = cJSON_GetObjectItemCaseSensitive(login_bodyJSON, "username");
    if (cJSON_IsNull(username)) {
        username = NULL;
    }
    if (username) { 
    if(!cJSON_IsString(username) && !cJSON_IsNull(username))
    {
    goto end; //String
    }
    }

    // login_body->password
    cJSON *password = cJSON_GetObjectItemCaseSensitive(login_bodyJSON, "password");
    if (cJSON_IsNull(password)) {
        password = NULL;
    }
    if (password) { 
    if(!cJSON_IsString(password) && !cJSON_IsNull(password))
    {
    goto end; //String
    }
    }

    // login_body->totp_token
    cJSON *totp_token = cJSON_GetObjectItemCaseSensitive(login_bodyJSON, "totpToken");
    if (cJSON_IsNull(totp_token)) {
        totp_token = NULL;
    }
    if (totp_token) { 
    if(!cJSON_IsString(totp_token) && !cJSON_IsNull(totp_token))
    {
    goto end; //String
    }
    }

    // login_body->api_token
    cJSON *api_token = cJSON_GetObjectItemCaseSensitive(login_bodyJSON, "apiToken");
    if (cJSON_IsNull(api_token)) {
        api_token = NULL;
    }
    if (api_token) { 
    if(!cJSON_IsString(api_token) && !cJSON_IsNull(api_token))
    {
    goto end; //String
    }
    }

    // login_body->token
    cJSON *token = cJSON_GetObjectItemCaseSensitive(login_bodyJSON, "token");
    if (cJSON_IsNull(token)) {
        token = NULL;
    }
    if (token) { 
    if(!cJSON_IsString(token) && !cJSON_IsNull(token))
    {
    goto end; //String
    }
    }

    // login_body->revoke_old
    cJSON *revoke_old = cJSON_GetObjectItemCaseSensitive(login_bodyJSON, "revokeOld");
    if (cJSON_IsNull(revoke_old)) {
        revoke_old = NULL;
    }
    if (revoke_old) { 
    if(!cJSON_IsBool(revoke_old))
    {
    goto end; //Bool
    }
    }


    login_body_local_var = login_body_create_internal (
        username && !cJSON_IsNull(username) ? strdup(username->valuestring) : NULL,
        password && !cJSON_IsNull(password) ? strdup(password->valuestring) : NULL,
        totp_token && !cJSON_IsNull(totp_token) ? strdup(totp_token->valuestring) : NULL,
        api_token && !cJSON_IsNull(api_token) ? strdup(api_token->valuestring) : NULL,
        token && !cJSON_IsNull(token) ? strdup(token->valuestring) : NULL,
        revoke_old ? revoke_old->valueint : 0
        );

    return login_body_local_var;
end:
    return NULL;

}
