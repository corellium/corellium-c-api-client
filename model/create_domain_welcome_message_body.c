#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_domain_welcome_message_body.h"



static create_domain_welcome_message_body_t *create_domain_welcome_message_body_create_internal(
    char *message,
    int enabled
    ) {
    create_domain_welcome_message_body_t *create_domain_welcome_message_body_local_var = malloc(sizeof(create_domain_welcome_message_body_t));
    if (!create_domain_welcome_message_body_local_var) {
        return NULL;
    }
    create_domain_welcome_message_body_local_var->message = message;
    create_domain_welcome_message_body_local_var->enabled = enabled;

    create_domain_welcome_message_body_local_var->_library_owned = 1;
    return create_domain_welcome_message_body_local_var;
}

__attribute__((deprecated)) create_domain_welcome_message_body_t *create_domain_welcome_message_body_create(
    char *message,
    int enabled
    ) {
    return create_domain_welcome_message_body_create_internal (
        message,
        enabled
        );
}

void create_domain_welcome_message_body_free(create_domain_welcome_message_body_t *create_domain_welcome_message_body) {
    if(NULL == create_domain_welcome_message_body){
        return ;
    }
    if(create_domain_welcome_message_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "create_domain_welcome_message_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (create_domain_welcome_message_body->message) {
        free(create_domain_welcome_message_body->message);
        create_domain_welcome_message_body->message = NULL;
    }
    free(create_domain_welcome_message_body);
}

cJSON *create_domain_welcome_message_body_convertToJSON(create_domain_welcome_message_body_t *create_domain_welcome_message_body) {
    cJSON *item = cJSON_CreateObject();

    // create_domain_welcome_message_body->message
    if (!create_domain_welcome_message_body->message) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message", create_domain_welcome_message_body->message) == NULL) {
    goto fail; //String
    }


    // create_domain_welcome_message_body->enabled
    if(create_domain_welcome_message_body->enabled) {
    if(cJSON_AddBoolToObject(item, "enabled", create_domain_welcome_message_body->enabled) == NULL) {
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

create_domain_welcome_message_body_t *create_domain_welcome_message_body_parseFromJSON(cJSON *create_domain_welcome_message_bodyJSON){

    create_domain_welcome_message_body_t *create_domain_welcome_message_body_local_var = NULL;

    // create_domain_welcome_message_body->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(create_domain_welcome_message_bodyJSON, "message");
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

    // create_domain_welcome_message_body->enabled
    cJSON *enabled = cJSON_GetObjectItemCaseSensitive(create_domain_welcome_message_bodyJSON, "enabled");
    if (cJSON_IsNull(enabled)) {
        enabled = NULL;
    }
    if (enabled) { 
    if(!cJSON_IsBool(enabled))
    {
    goto end; //Bool
    }
    }


    create_domain_welcome_message_body_local_var = create_domain_welcome_message_body_create_internal (
        strdup(message->valuestring),
        enabled ? enabled->valueint : 0
        );

    return create_domain_welcome_message_body_local_var;
end:
    return NULL;

}
