#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "invite_signup_body_params.h"



static invite_signup_body_params_t *invite_signup_body_params_create_internal(
    char *email,
    char *password,
    char *label
    ) {
    invite_signup_body_params_t *invite_signup_body_params_local_var = malloc(sizeof(invite_signup_body_params_t));
    if (!invite_signup_body_params_local_var) {
        return NULL;
    }
    invite_signup_body_params_local_var->email = email;
    invite_signup_body_params_local_var->password = password;
    invite_signup_body_params_local_var->label = label;

    invite_signup_body_params_local_var->_library_owned = 1;
    return invite_signup_body_params_local_var;
}

__attribute__((deprecated)) invite_signup_body_params_t *invite_signup_body_params_create(
    char *email,
    char *password,
    char *label
    ) {
    return invite_signup_body_params_create_internal (
        email,
        password,
        label
        );
}

void invite_signup_body_params_free(invite_signup_body_params_t *invite_signup_body_params) {
    if(NULL == invite_signup_body_params){
        return ;
    }
    if(invite_signup_body_params->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "invite_signup_body_params_free");
        return ;
    }
    listEntry_t *listEntry;
    if (invite_signup_body_params->email) {
        free(invite_signup_body_params->email);
        invite_signup_body_params->email = NULL;
    }
    if (invite_signup_body_params->password) {
        free(invite_signup_body_params->password);
        invite_signup_body_params->password = NULL;
    }
    if (invite_signup_body_params->label) {
        free(invite_signup_body_params->label);
        invite_signup_body_params->label = NULL;
    }
    free(invite_signup_body_params);
}

cJSON *invite_signup_body_params_convertToJSON(invite_signup_body_params_t *invite_signup_body_params) {
    cJSON *item = cJSON_CreateObject();

    // invite_signup_body_params->email
    if(invite_signup_body_params->email) {
    if(cJSON_AddStringToObject(item, "email", invite_signup_body_params->email) == NULL) {
    goto fail; //String
    }
    }


    // invite_signup_body_params->password
    if (!invite_signup_body_params->password) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "password", invite_signup_body_params->password) == NULL) {
    goto fail; //String
    }


    // invite_signup_body_params->label
    if (!invite_signup_body_params->label) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "label", invite_signup_body_params->label) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

invite_signup_body_params_t *invite_signup_body_params_parseFromJSON(cJSON *invite_signup_body_paramsJSON){

    invite_signup_body_params_t *invite_signup_body_params_local_var = NULL;

    // invite_signup_body_params->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(invite_signup_body_paramsJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (email) { 
    if(!cJSON_IsString(email) && !cJSON_IsNull(email))
    {
    goto end; //String
    }
    }

    // invite_signup_body_params->password
    cJSON *password = cJSON_GetObjectItemCaseSensitive(invite_signup_body_paramsJSON, "password");
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

    // invite_signup_body_params->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(invite_signup_body_paramsJSON, "label");
    if (cJSON_IsNull(label)) {
        label = NULL;
    }
    if (!label) {
        goto end;
    }

    
    if(!cJSON_IsString(label))
    {
    goto end; //String
    }


    invite_signup_body_params_local_var = invite_signup_body_params_create_internal (
        email && !cJSON_IsNull(email) ? strdup(email->valuestring) : NULL,
        strdup(password->valuestring),
        strdup(label->valuestring)
        );

    return invite_signup_body_params_local_var;
end:
    return NULL;

}
