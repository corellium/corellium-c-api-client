#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "invitation.h"



static invitation_t *invitation_create_internal(
    char *id,
    char *email,
    invite_settings_t *settings
    ) {
    invitation_t *invitation_local_var = malloc(sizeof(invitation_t));
    if (!invitation_local_var) {
        return NULL;
    }
    invitation_local_var->id = id;
    invitation_local_var->email = email;
    invitation_local_var->settings = settings;

    invitation_local_var->_library_owned = 1;
    return invitation_local_var;
}

__attribute__((deprecated)) invitation_t *invitation_create(
    char *id,
    char *email,
    invite_settings_t *settings
    ) {
    return invitation_create_internal (
        id,
        email,
        settings
        );
}

void invitation_free(invitation_t *invitation) {
    if(NULL == invitation){
        return ;
    }
    if(invitation->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "invitation_free");
        return ;
    }
    listEntry_t *listEntry;
    if (invitation->id) {
        free(invitation->id);
        invitation->id = NULL;
    }
    if (invitation->email) {
        free(invitation->email);
        invitation->email = NULL;
    }
    if (invitation->settings) {
        invite_settings_free(invitation->settings);
        invitation->settings = NULL;
    }
    free(invitation);
}

cJSON *invitation_convertToJSON(invitation_t *invitation) {
    cJSON *item = cJSON_CreateObject();

    // invitation->id
    if (!invitation->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", invitation->id) == NULL) {
    goto fail; //String
    }


    // invitation->email
    if (!invitation->email) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "email", invitation->email) == NULL) {
    goto fail; //String
    }


    // invitation->settings
    if (!invitation->settings) {
        goto fail;
    }
    cJSON *settings_local_JSON = invite_settings_convertToJSON(invitation->settings);
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

invitation_t *invitation_parseFromJSON(cJSON *invitationJSON){

    invitation_t *invitation_local_var = NULL;

    // define the local variable for invitation->settings
    invite_settings_t *settings_local_nonprim = NULL;

    // invitation->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(invitationJSON, "id");
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

    // invitation->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(invitationJSON, "email");
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

    // invitation->settings
    cJSON *settings = cJSON_GetObjectItemCaseSensitive(invitationJSON, "settings");
    if (cJSON_IsNull(settings)) {
        settings = NULL;
    }
    if (!settings) {
        goto end;
    }

    
    settings_local_nonprim = invite_settings_parseFromJSON(settings); //nonprimitive


    invitation_local_var = invitation_create_internal (
        strdup(id->valuestring),
        strdup(email->valuestring),
        settings_local_nonprim
        );

    return invitation_local_var;
end:
    if (settings_local_nonprim) {
        invite_settings_free(settings_local_nonprim);
        settings_local_nonprim = NULL;
    }
    return NULL;

}
