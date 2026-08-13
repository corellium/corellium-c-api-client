#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "patch_domain_welcome_message_body.h"



static patch_domain_welcome_message_body_t *patch_domain_welcome_message_body_create_internal(
    char *message,
    int enabled
    ) {
    patch_domain_welcome_message_body_t *patch_domain_welcome_message_body_local_var = malloc(sizeof(patch_domain_welcome_message_body_t));
    if (!patch_domain_welcome_message_body_local_var) {
        return NULL;
    }
    patch_domain_welcome_message_body_local_var->message = message;
    patch_domain_welcome_message_body_local_var->enabled = enabled;

    patch_domain_welcome_message_body_local_var->_library_owned = 1;
    return patch_domain_welcome_message_body_local_var;
}

__attribute__((deprecated)) patch_domain_welcome_message_body_t *patch_domain_welcome_message_body_create(
    char *message,
    int enabled
    ) {
    return patch_domain_welcome_message_body_create_internal (
        message,
        enabled
        );
}

void patch_domain_welcome_message_body_free(patch_domain_welcome_message_body_t *patch_domain_welcome_message_body) {
    if(NULL == patch_domain_welcome_message_body){
        return ;
    }
    if(patch_domain_welcome_message_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "patch_domain_welcome_message_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (patch_domain_welcome_message_body->message) {
        free(patch_domain_welcome_message_body->message);
        patch_domain_welcome_message_body->message = NULL;
    }
    free(patch_domain_welcome_message_body);
}

cJSON *patch_domain_welcome_message_body_convertToJSON(patch_domain_welcome_message_body_t *patch_domain_welcome_message_body) {
    cJSON *item = cJSON_CreateObject();

    // patch_domain_welcome_message_body->message
    if(patch_domain_welcome_message_body->message) {
    if(cJSON_AddStringToObject(item, "message", patch_domain_welcome_message_body->message) == NULL) {
    goto fail; //String
    }
    }


    // patch_domain_welcome_message_body->enabled
    if(patch_domain_welcome_message_body->enabled) {
    if(cJSON_AddBoolToObject(item, "enabled", patch_domain_welcome_message_body->enabled) == NULL) {
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

patch_domain_welcome_message_body_t *patch_domain_welcome_message_body_parseFromJSON(cJSON *patch_domain_welcome_message_bodyJSON){

    patch_domain_welcome_message_body_t *patch_domain_welcome_message_body_local_var = NULL;

    // patch_domain_welcome_message_body->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(patch_domain_welcome_message_bodyJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (message) { 
    if(!cJSON_IsString(message) && !cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // patch_domain_welcome_message_body->enabled
    cJSON *enabled = cJSON_GetObjectItemCaseSensitive(patch_domain_welcome_message_bodyJSON, "enabled");
    if (cJSON_IsNull(enabled)) {
        enabled = NULL;
    }
    if (enabled) { 
    if(!cJSON_IsBool(enabled))
    {
    goto end; //Bool
    }
    }


    patch_domain_welcome_message_body_local_var = patch_domain_welcome_message_body_create_internal (
        message && !cJSON_IsNull(message) ? strdup(message->valuestring) : NULL,
        enabled ? enabled->valueint : 0
        );

    return patch_domain_welcome_message_body_local_var;
end:
    return NULL;

}
