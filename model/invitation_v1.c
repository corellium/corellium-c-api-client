#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "invitation_v1.h"



static invitation_v1_t *invitation_v1_create_internal(
    char *identifier,
    char *email,
    object_t *settings
    ) {
    invitation_v1_t *invitation_v1_local_var = malloc(sizeof(invitation_v1_t));
    if (!invitation_v1_local_var) {
        return NULL;
    }
    invitation_v1_local_var->identifier = identifier;
    invitation_v1_local_var->email = email;
    invitation_v1_local_var->settings = settings;

    invitation_v1_local_var->_library_owned = 1;
    return invitation_v1_local_var;
}

__attribute__((deprecated)) invitation_v1_t *invitation_v1_create(
    char *identifier,
    char *email,
    object_t *settings
    ) {
    return invitation_v1_create_internal (
        identifier,
        email,
        settings
        );
}

void invitation_v1_free(invitation_v1_t *invitation_v1) {
    if(NULL == invitation_v1){
        return ;
    }
    if(invitation_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "invitation_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (invitation_v1->identifier) {
        free(invitation_v1->identifier);
        invitation_v1->identifier = NULL;
    }
    if (invitation_v1->email) {
        free(invitation_v1->email);
        invitation_v1->email = NULL;
    }
    if (invitation_v1->settings) {
        object_free(invitation_v1->settings);
        invitation_v1->settings = NULL;
    }
    free(invitation_v1);
}

cJSON *invitation_v1_convertToJSON(invitation_v1_t *invitation_v1) {
    cJSON *item = cJSON_CreateObject();

    // invitation_v1->identifier
    if(invitation_v1->identifier) {
    if(cJSON_AddStringToObject(item, "identifier", invitation_v1->identifier) == NULL) {
    goto fail; //String
    }
    }


    // invitation_v1->email
    if(invitation_v1->email) {
    if(cJSON_AddStringToObject(item, "email", invitation_v1->email) == NULL) {
    goto fail; //String
    }
    }


    // invitation_v1->settings
    if(invitation_v1->settings) {
    cJSON *settings_object = object_convertToJSON(invitation_v1->settings);
    if(settings_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "settings", settings_object);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

invitation_v1_t *invitation_v1_parseFromJSON(cJSON *invitation_v1JSON){

    invitation_v1_t *invitation_v1_local_var = NULL;

    // invitation_v1->identifier
    cJSON *identifier = cJSON_GetObjectItemCaseSensitive(invitation_v1JSON, "identifier");
    if (cJSON_IsNull(identifier)) {
        identifier = NULL;
    }
    if (identifier) { 
    if(!cJSON_IsString(identifier) && !cJSON_IsNull(identifier))
    {
    goto end; //String
    }
    }

    // invitation_v1->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(invitation_v1JSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (email) { 
    if(!cJSON_IsString(email) && !cJSON_IsNull(email))
    {
    goto end; //String
    }
    }

    // invitation_v1->settings
    cJSON *settings = cJSON_GetObjectItemCaseSensitive(invitation_v1JSON, "settings");
    if (cJSON_IsNull(settings)) {
        settings = NULL;
    }
    object_t *settings_local_object = NULL;
    if (settings) { 
    settings_local_object = object_parseFromJSON(settings); //object
    }


    invitation_v1_local_var = invitation_v1_create_internal (
        identifier && !cJSON_IsNull(identifier) ? strdup(identifier->valuestring) : NULL,
        email && !cJSON_IsNull(email) ? strdup(email->valuestring) : NULL,
        settings ? settings_local_object : NULL
        );

    return invitation_v1_local_var;
end:
    return NULL;

}
