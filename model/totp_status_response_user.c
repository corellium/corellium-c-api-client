#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "totp_status_response_user.h"



static totp_status_response_user_t *totp_status_response_user_create_internal(
    char *id,
    char *name,
    char *label,
    char *email
    ) {
    totp_status_response_user_t *totp_status_response_user_local_var = malloc(sizeof(totp_status_response_user_t));
    if (!totp_status_response_user_local_var) {
        return NULL;
    }
    totp_status_response_user_local_var->id = id;
    totp_status_response_user_local_var->name = name;
    totp_status_response_user_local_var->label = label;
    totp_status_response_user_local_var->email = email;

    totp_status_response_user_local_var->_library_owned = 1;
    return totp_status_response_user_local_var;
}

__attribute__((deprecated)) totp_status_response_user_t *totp_status_response_user_create(
    char *id,
    char *name,
    char *label,
    char *email
    ) {
    return totp_status_response_user_create_internal (
        id,
        name,
        label,
        email
        );
}

void totp_status_response_user_free(totp_status_response_user_t *totp_status_response_user) {
    if(NULL == totp_status_response_user){
        return ;
    }
    if(totp_status_response_user->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "totp_status_response_user_free");
        return ;
    }
    listEntry_t *listEntry;
    if (totp_status_response_user->id) {
        free(totp_status_response_user->id);
        totp_status_response_user->id = NULL;
    }
    if (totp_status_response_user->name) {
        free(totp_status_response_user->name);
        totp_status_response_user->name = NULL;
    }
    if (totp_status_response_user->label) {
        free(totp_status_response_user->label);
        totp_status_response_user->label = NULL;
    }
    if (totp_status_response_user->email) {
        free(totp_status_response_user->email);
        totp_status_response_user->email = NULL;
    }
    free(totp_status_response_user);
}

cJSON *totp_status_response_user_convertToJSON(totp_status_response_user_t *totp_status_response_user) {
    cJSON *item = cJSON_CreateObject();

    // totp_status_response_user->id
    if (!totp_status_response_user->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", totp_status_response_user->id) == NULL) {
    goto fail; //String
    }


    // totp_status_response_user->name
    if (!totp_status_response_user->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", totp_status_response_user->name) == NULL) {
    goto fail; //String
    }


    // totp_status_response_user->label
    if(totp_status_response_user->label) {
    if(cJSON_AddStringToObject(item, "label", totp_status_response_user->label) == NULL) {
    goto fail; //String
    }
    }


    // totp_status_response_user->email
    if (!totp_status_response_user->email) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "email", totp_status_response_user->email) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

totp_status_response_user_t *totp_status_response_user_parseFromJSON(cJSON *totp_status_response_userJSON){

    totp_status_response_user_t *totp_status_response_user_local_var = NULL;

    // totp_status_response_user->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(totp_status_response_userJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // totp_status_response_user->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(totp_status_response_userJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // totp_status_response_user->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(totp_status_response_userJSON, "label");
    if (cJSON_IsNull(label)) {
        label = NULL;
    }
    if (label) { 
    if(!cJSON_IsString(label) && !cJSON_IsNull(label))
    {
    goto end; //String
    }
    }

    // totp_status_response_user->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(totp_status_response_userJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (!email) {
        goto end;
    }

    
    if(!cJSON_IsString(email))
    {
    goto end; //String
    }


    totp_status_response_user_local_var = totp_status_response_user_create_internal (
        strdup(id->valuestring),
        strdup(name->valuestring),
        label && !cJSON_IsNull(label) ? strdup(label->valuestring) : NULL,
        strdup(email->valuestring)
        );

    return totp_status_response_user_local_var;
end:
    return NULL;

}
