#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "invite_signup_body.h"



static invite_signup_body_t *invite_signup_body_create_internal(
    char *invite_token,
    invite_signup_body_params_t *params
    ) {
    invite_signup_body_t *invite_signup_body_local_var = malloc(sizeof(invite_signup_body_t));
    if (!invite_signup_body_local_var) {
        return NULL;
    }
    invite_signup_body_local_var->invite_token = invite_token;
    invite_signup_body_local_var->params = params;

    invite_signup_body_local_var->_library_owned = 1;
    return invite_signup_body_local_var;
}

__attribute__((deprecated)) invite_signup_body_t *invite_signup_body_create(
    char *invite_token,
    invite_signup_body_params_t *params
    ) {
    return invite_signup_body_create_internal (
        invite_token,
        params
        );
}

void invite_signup_body_free(invite_signup_body_t *invite_signup_body) {
    if(NULL == invite_signup_body){
        return ;
    }
    if(invite_signup_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "invite_signup_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (invite_signup_body->invite_token) {
        free(invite_signup_body->invite_token);
        invite_signup_body->invite_token = NULL;
    }
    if (invite_signup_body->params) {
        invite_signup_body_params_free(invite_signup_body->params);
        invite_signup_body->params = NULL;
    }
    free(invite_signup_body);
}

cJSON *invite_signup_body_convertToJSON(invite_signup_body_t *invite_signup_body) {
    cJSON *item = cJSON_CreateObject();

    // invite_signup_body->invite_token
    if (!invite_signup_body->invite_token) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "inviteToken", invite_signup_body->invite_token) == NULL) {
    goto fail; //String
    }


    // invite_signup_body->params
    if (!invite_signup_body->params) {
        goto fail;
    }
    cJSON *params_local_JSON = invite_signup_body_params_convertToJSON(invite_signup_body->params);
    if(params_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "params", params_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

invite_signup_body_t *invite_signup_body_parseFromJSON(cJSON *invite_signup_bodyJSON){

    invite_signup_body_t *invite_signup_body_local_var = NULL;

    // define the local variable for invite_signup_body->params
    invite_signup_body_params_t *params_local_nonprim = NULL;

    // invite_signup_body->invite_token
    cJSON *invite_token = cJSON_GetObjectItemCaseSensitive(invite_signup_bodyJSON, "inviteToken");
    if (cJSON_IsNull(invite_token)) {
        invite_token = NULL;
    }
    if (!invite_token) {
        goto end;
    }

    
    if(!cJSON_IsString(invite_token))
    {
    goto end; //String
    }

    // invite_signup_body->params
    cJSON *params = cJSON_GetObjectItemCaseSensitive(invite_signup_bodyJSON, "params");
    if (cJSON_IsNull(params)) {
        params = NULL;
    }
    if (!params) {
        goto end;
    }

    
    params_local_nonprim = invite_signup_body_params_parseFromJSON(params); //nonprimitive


    invite_signup_body_local_var = invite_signup_body_create_internal (
        strdup(invite_token->valuestring),
        params_local_nonprim
        );

    return invite_signup_body_local_var;
end:
    if (params_local_nonprim) {
        invite_signup_body_params_free(params_local_nonprim);
        params_local_nonprim = NULL;
    }
    return NULL;

}
