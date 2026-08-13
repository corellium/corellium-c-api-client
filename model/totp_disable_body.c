#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "totp_disable_body.h"



static totp_disable_body_t *totp_disable_body_create_internal(
    char *totp_token,
    char *password
    ) {
    totp_disable_body_t *totp_disable_body_local_var = malloc(sizeof(totp_disable_body_t));
    if (!totp_disable_body_local_var) {
        return NULL;
    }
    totp_disable_body_local_var->totp_token = totp_token;
    totp_disable_body_local_var->password = password;

    totp_disable_body_local_var->_library_owned = 1;
    return totp_disable_body_local_var;
}

__attribute__((deprecated)) totp_disable_body_t *totp_disable_body_create(
    char *totp_token,
    char *password
    ) {
    return totp_disable_body_create_internal (
        totp_token,
        password
        );
}

void totp_disable_body_free(totp_disable_body_t *totp_disable_body) {
    if(NULL == totp_disable_body){
        return ;
    }
    if(totp_disable_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "totp_disable_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (totp_disable_body->totp_token) {
        free(totp_disable_body->totp_token);
        totp_disable_body->totp_token = NULL;
    }
    if (totp_disable_body->password) {
        free(totp_disable_body->password);
        totp_disable_body->password = NULL;
    }
    free(totp_disable_body);
}

cJSON *totp_disable_body_convertToJSON(totp_disable_body_t *totp_disable_body) {
    cJSON *item = cJSON_CreateObject();

    // totp_disable_body->totp_token
    if (!totp_disable_body->totp_token) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "totpToken", totp_disable_body->totp_token) == NULL) {
    goto fail; //String
    }


    // totp_disable_body->password
    if (!totp_disable_body->password) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "password", totp_disable_body->password) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

totp_disable_body_t *totp_disable_body_parseFromJSON(cJSON *totp_disable_bodyJSON){

    totp_disable_body_t *totp_disable_body_local_var = NULL;

    // totp_disable_body->totp_token
    cJSON *totp_token = cJSON_GetObjectItemCaseSensitive(totp_disable_bodyJSON, "totpToken");
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

    // totp_disable_body->password
    cJSON *password = cJSON_GetObjectItemCaseSensitive(totp_disable_bodyJSON, "password");
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


    totp_disable_body_local_var = totp_disable_body_create_internal (
        strdup(totp_token->valuestring),
        strdup(password->valuestring)
        );

    return totp_disable_body_local_var;
end:
    return NULL;

}
