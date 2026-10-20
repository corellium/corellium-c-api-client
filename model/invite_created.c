#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "invite_created.h"



static invite_created_t *invite_created_create_internal(
    char *id,
    char *email,
    object_t *settings
    ) {
    invite_created_t *invite_created_local_var = malloc(sizeof(invite_created_t));
    if (!invite_created_local_var) {
        return NULL;
    }
    invite_created_local_var->id = id;
    invite_created_local_var->email = email;
    invite_created_local_var->settings = settings;

    invite_created_local_var->_library_owned = 1;
    return invite_created_local_var;
}

__attribute__((deprecated)) invite_created_t *invite_created_create(
    char *id,
    char *email,
    object_t *settings
    ) {
    return invite_created_create_internal (
        id,
        email,
        settings
        );
}

void invite_created_free(invite_created_t *invite_created) {
    if(NULL == invite_created){
        return ;
    }
    if(invite_created->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "invite_created_free");
        return ;
    }
    listEntry_t *listEntry;
    if (invite_created->id) {
        free(invite_created->id);
        invite_created->id = NULL;
    }
    if (invite_created->email) {
        free(invite_created->email);
        invite_created->email = NULL;
    }
    if (invite_created->settings) {
        object_free(invite_created->settings);
        invite_created->settings = NULL;
    }
    free(invite_created);
}

cJSON *invite_created_convertToJSON(invite_created_t *invite_created) {
    cJSON *item = cJSON_CreateObject();

    // invite_created->id
    if(invite_created->id) {
    if(cJSON_AddStringToObject(item, "id", invite_created->id) == NULL) {
    goto fail; //String
    }
    }


    // invite_created->email
    if(invite_created->email) {
    if(cJSON_AddStringToObject(item, "email", invite_created->email) == NULL) {
    goto fail; //String
    }
    }


    // invite_created->settings
    if(invite_created->settings) {
    cJSON *settings_object = object_convertToJSON(invite_created->settings);
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

invite_created_t *invite_created_parseFromJSON(cJSON *invite_createdJSON){

    invite_created_t *invite_created_local_var = NULL;

    // invite_created->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(invite_createdJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (id) { 
    if(!cJSON_IsString(id) && !cJSON_IsNull(id))
    {
    goto end; //String
    }
    }

    // invite_created->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(invite_createdJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (email) { 
    if(!cJSON_IsString(email) && !cJSON_IsNull(email))
    {
    goto end; //String
    }
    }

    // invite_created->settings
    cJSON *settings = cJSON_GetObjectItemCaseSensitive(invite_createdJSON, "settings");
    if (cJSON_IsNull(settings)) {
        settings = NULL;
    }
    object_t *settings_local_object = NULL;
    if (settings) { 
    settings_local_object = object_parseFromJSON(settings); //object
    }


    invite_created_local_var = invite_created_create_internal (
        id && !cJSON_IsNull(id) ? strdup(id->valuestring) : NULL,
        email && !cJSON_IsNull(email) ? strdup(email->valuestring) : NULL,
        settings ? settings_local_object : NULL
        );

    return invite_created_local_var;
end:
    return NULL;

}
