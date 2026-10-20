#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "message_body_any_of.h"



static message_body_any_of_t *message_body_any_of_create_internal(
    char *number,
    char *message
    ) {
    message_body_any_of_t *message_body_any_of_local_var = malloc(sizeof(message_body_any_of_t));
    if (!message_body_any_of_local_var) {
        return NULL;
    }
    message_body_any_of_local_var->number = number;
    message_body_any_of_local_var->message = message;

    message_body_any_of_local_var->_library_owned = 1;
    return message_body_any_of_local_var;
}

__attribute__((deprecated)) message_body_any_of_t *message_body_any_of_create(
    char *number,
    char *message
    ) {
    return message_body_any_of_create_internal (
        number,
        message
        );
}

void message_body_any_of_free(message_body_any_of_t *message_body_any_of) {
    if(NULL == message_body_any_of){
        return ;
    }
    if(message_body_any_of->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "message_body_any_of_free");
        return ;
    }
    listEntry_t *listEntry;
    if (message_body_any_of->number) {
        free(message_body_any_of->number);
        message_body_any_of->number = NULL;
    }
    if (message_body_any_of->message) {
        free(message_body_any_of->message);
        message_body_any_of->message = NULL;
    }
    free(message_body_any_of);
}

cJSON *message_body_any_of_convertToJSON(message_body_any_of_t *message_body_any_of) {
    cJSON *item = cJSON_CreateObject();

    // message_body_any_of->number
    if (!message_body_any_of->number) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "number", message_body_any_of->number) == NULL) {
    goto fail; //String
    }


    // message_body_any_of->message
    if (!message_body_any_of->message) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message", message_body_any_of->message) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

message_body_any_of_t *message_body_any_of_parseFromJSON(cJSON *message_body_any_ofJSON){

    message_body_any_of_t *message_body_any_of_local_var = NULL;

    // message_body_any_of->number
    cJSON *number = cJSON_GetObjectItemCaseSensitive(message_body_any_ofJSON, "number");
    if (cJSON_IsNull(number)) {
        number = NULL;
    }
    if (!number) {
        goto end;
    }

    
    if(!cJSON_IsString(number))
    {
    goto end; //String
    }

    // message_body_any_of->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(message_body_any_ofJSON, "message");
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


    message_body_any_of_local_var = message_body_any_of_create_internal (
        strdup(number->valuestring),
        strdup(message->valuestring)
        );

    return message_body_any_of_local_var;
end:
    return NULL;

}
