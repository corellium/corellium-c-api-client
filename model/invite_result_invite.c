#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "invite_result_invite.h"



static invite_result_invite_t *invite_result_invite_create_internal(
    char *id,
    char *email,
    invite_settings_t *settings
    ) {
    invite_result_invite_t *invite_result_invite_local_var = malloc(sizeof(invite_result_invite_t));
    if (!invite_result_invite_local_var) {
        return NULL;
    }
    invite_result_invite_local_var->id = id;
    invite_result_invite_local_var->email = email;
    invite_result_invite_local_var->settings = settings;

    invite_result_invite_local_var->_library_owned = 1;
    return invite_result_invite_local_var;
}

__attribute__((deprecated)) invite_result_invite_t *invite_result_invite_create(
    char *id,
    char *email,
    invite_settings_t *settings
    ) {
    return invite_result_invite_create_internal (
        id,
        email,
        settings
        );
}

void invite_result_invite_free(invite_result_invite_t *invite_result_invite) {
    if(NULL == invite_result_invite){
        return ;
    }
    if(invite_result_invite->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "invite_result_invite_free");
        return ;
    }
    listEntry_t *listEntry;
    if (invite_result_invite->id) {
        free(invite_result_invite->id);
        invite_result_invite->id = NULL;
    }
    if (invite_result_invite->email) {
        free(invite_result_invite->email);
        invite_result_invite->email = NULL;
    }
    if (invite_result_invite->settings) {
        invite_settings_free(invite_result_invite->settings);
        invite_result_invite->settings = NULL;
    }
    free(invite_result_invite);
}

cJSON *invite_result_invite_convertToJSON(invite_result_invite_t *invite_result_invite) {
    cJSON *item = cJSON_CreateObject();

    // invite_result_invite->id
    if (!invite_result_invite->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", invite_result_invite->id) == NULL) {
    goto fail; //String
    }


    // invite_result_invite->email
    if (!invite_result_invite->email) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "email", invite_result_invite->email) == NULL) {
    goto fail; //String
    }


    // invite_result_invite->settings
    if (!invite_result_invite->settings) {
        goto fail;
    }
    cJSON *settings_local_JSON = invite_settings_convertToJSON(invite_result_invite->settings);
    if(settings_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "settings", settings_local_JSON);
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

invite_result_invite_t *invite_result_invite_parseFromJSON(cJSON *invite_result_inviteJSON){

    invite_result_invite_t *invite_result_invite_local_var = NULL;

    // define the local variable for invite_result_invite->settings
    invite_settings_t *settings_local_nonprim = NULL;

    // invite_result_invite->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(invite_result_inviteJSON, "id");
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

    // invite_result_invite->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(invite_result_inviteJSON, "email");
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

    // invite_result_invite->settings
    cJSON *settings = cJSON_GetObjectItemCaseSensitive(invite_result_inviteJSON, "settings");
    if (cJSON_IsNull(settings)) {
        settings = NULL;
    }
    if (!settings) {
        goto end;
    }

    
    settings_local_nonprim = invite_settings_parseFromJSON(settings); //nonprimitive


    invite_result_invite_local_var = invite_result_invite_create_internal (
        strdup(id->valuestring),
        strdup(email->valuestring),
        settings_local_nonprim
        );

    return invite_result_invite_local_var;
end:
    if (settings_local_nonprim) {
        invite_settings_free(settings_local_nonprim);
        settings_local_nonprim = NULL;
    }
    return NULL;

}
