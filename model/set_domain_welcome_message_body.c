#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "set_domain_welcome_message_body.h"



static set_domain_welcome_message_body_t *set_domain_welcome_message_body_create_internal(
    char *message,
    int enabled
    ) {
    set_domain_welcome_message_body_t *set_domain_welcome_message_body_local_var = malloc(sizeof(set_domain_welcome_message_body_t));
    if (!set_domain_welcome_message_body_local_var) {
        return NULL;
    }
    set_domain_welcome_message_body_local_var->message = message;
    set_domain_welcome_message_body_local_var->enabled = enabled;

    set_domain_welcome_message_body_local_var->_library_owned = 1;
    return set_domain_welcome_message_body_local_var;
}

__attribute__((deprecated)) set_domain_welcome_message_body_t *set_domain_welcome_message_body_create(
    char *message,
    int enabled
    ) {
    return set_domain_welcome_message_body_create_internal (
        message,
        enabled
        );
}

void set_domain_welcome_message_body_free(set_domain_welcome_message_body_t *set_domain_welcome_message_body) {
    if(NULL == set_domain_welcome_message_body){
        return ;
    }
    if(set_domain_welcome_message_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "set_domain_welcome_message_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (set_domain_welcome_message_body->message) {
        free(set_domain_welcome_message_body->message);
        set_domain_welcome_message_body->message = NULL;
    }
    free(set_domain_welcome_message_body);
}

cJSON *set_domain_welcome_message_body_convertToJSON(set_domain_welcome_message_body_t *set_domain_welcome_message_body) {
    cJSON *item = cJSON_CreateObject();

    // set_domain_welcome_message_body->message
    if (!set_domain_welcome_message_body->message) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message", set_domain_welcome_message_body->message) == NULL) {
    goto fail; //String
    }


    // set_domain_welcome_message_body->enabled
    if (!set_domain_welcome_message_body->enabled) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "enabled", set_domain_welcome_message_body->enabled) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

set_domain_welcome_message_body_t *set_domain_welcome_message_body_parseFromJSON(cJSON *set_domain_welcome_message_bodyJSON){

    set_domain_welcome_message_body_t *set_domain_welcome_message_body_local_var = NULL;

    // set_domain_welcome_message_body->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(set_domain_welcome_message_bodyJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (!message) {
        goto end;
    }

    
    if(!cJSON_IsString(message))
    {
    goto end; //String
    }

    // set_domain_welcome_message_body->enabled
    cJSON *enabled = cJSON_GetObjectItemCaseSensitive(set_domain_welcome_message_bodyJSON, "enabled");
    if (cJSON_IsNull(enabled)) {
        enabled = NULL;
    }
    if (!enabled) {
        goto end;
    }

    
    if(!cJSON_IsBool(enabled))
    {
    goto end; //Bool
    }


    set_domain_welcome_message_body_local_var = set_domain_welcome_message_body_create_internal (
        strdup(message->valuestring),
        enabled->valueint
        );

    return set_domain_welcome_message_body_local_var;
end:
    return NULL;

}
