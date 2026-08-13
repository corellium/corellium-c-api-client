#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "update_domain_welcome_message_request.h"



static update_domain_welcome_message_request_t *update_domain_welcome_message_request_create_internal(
    char *message,
    int enabled
    ) {
    update_domain_welcome_message_request_t *update_domain_welcome_message_request_local_var = malloc(sizeof(update_domain_welcome_message_request_t));
    if (!update_domain_welcome_message_request_local_var) {
        return NULL;
    }
    update_domain_welcome_message_request_local_var->message = message;
    update_domain_welcome_message_request_local_var->enabled = enabled;

    update_domain_welcome_message_request_local_var->_library_owned = 1;
    return update_domain_welcome_message_request_local_var;
}

__attribute__((deprecated)) update_domain_welcome_message_request_t *update_domain_welcome_message_request_create(
    char *message,
    int enabled
    ) {
    return update_domain_welcome_message_request_create_internal (
        message,
        enabled
        );
}

void update_domain_welcome_message_request_free(update_domain_welcome_message_request_t *update_domain_welcome_message_request) {
    if(NULL == update_domain_welcome_message_request){
        return ;
    }
    if(update_domain_welcome_message_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "update_domain_welcome_message_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (update_domain_welcome_message_request->message) {
        free(update_domain_welcome_message_request->message);
        update_domain_welcome_message_request->message = NULL;
    }
    free(update_domain_welcome_message_request);
}

cJSON *update_domain_welcome_message_request_convertToJSON(update_domain_welcome_message_request_t *update_domain_welcome_message_request) {
    cJSON *item = cJSON_CreateObject();

    // update_domain_welcome_message_request->message
    if(update_domain_welcome_message_request->message) {
    if(cJSON_AddStringToObject(item, "message", update_domain_welcome_message_request->message) == NULL) {
    goto fail; //String
    }
    }


    // update_domain_welcome_message_request->enabled
    if(update_domain_welcome_message_request->enabled) {
    if(cJSON_AddBoolToObject(item, "enabled", update_domain_welcome_message_request->enabled) == NULL) {
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

update_domain_welcome_message_request_t *update_domain_welcome_message_request_parseFromJSON(cJSON *update_domain_welcome_message_requestJSON){

    update_domain_welcome_message_request_t *update_domain_welcome_message_request_local_var = NULL;

    // update_domain_welcome_message_request->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(update_domain_welcome_message_requestJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (message) { 
    if(!cJSON_IsString(message) && !cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // update_domain_welcome_message_request->enabled
    cJSON *enabled = cJSON_GetObjectItemCaseSensitive(update_domain_welcome_message_requestJSON, "enabled");
    if (cJSON_IsNull(enabled)) {
        enabled = NULL;
    }
    if (enabled) { 
    if(!cJSON_IsBool(enabled))
    {
    goto end; //Bool
    }
    }


    update_domain_welcome_message_request_local_var = update_domain_welcome_message_request_create_internal (
        message && !cJSON_IsNull(message) ? strdup(message->valuestring) : NULL,
        enabled ? enabled->valueint : 0
        );

    return update_domain_welcome_message_request_local_var;
end:
    return NULL;

}
