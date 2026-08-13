#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "message_body.h"



static message_body_t *message_body_create_internal(
    char *number,
    char *message,
    char *raw
    ) {
    message_body_t *message_body_local_var = malloc(sizeof(message_body_t));
    if (!message_body_local_var) {
        return NULL;
    }
    message_body_local_var->number = number;
    message_body_local_var->message = message;
    message_body_local_var->raw = raw;

    message_body_local_var->_library_owned = 1;
    return message_body_local_var;
}

__attribute__((deprecated)) message_body_t *message_body_create(
    char *number,
    char *message,
    char *raw
    ) {
    return message_body_create_internal (
        number,
        message,
        raw
        );
}

void message_body_free(message_body_t *message_body) {
    if(NULL == message_body){
        return ;
    }
    if(message_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "message_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (message_body->number) {
        free(message_body->number);
        message_body->number = NULL;
    }
    if (message_body->message) {
        free(message_body->message);
        message_body->message = NULL;
    }
    if (message_body->raw) {
        free(message_body->raw);
        message_body->raw = NULL;
    }
    free(message_body);
}

cJSON *message_body_convertToJSON(message_body_t *message_body) {
    cJSON *item = cJSON_CreateObject();

    // message_body->number
    if (!message_body->number) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "number", message_body->number) == NULL) {
    goto fail; //String
    }


    // message_body->message
    if (!message_body->message) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message", message_body->message) == NULL) {
    goto fail; //String
    }


    // message_body->raw
    if (!message_body->raw) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "raw", message_body->raw) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

message_body_t *message_body_parseFromJSON(cJSON *message_bodyJSON){

    message_body_t *message_body_local_var = NULL;

    // message_body->number
    cJSON *number = cJSON_GetObjectItemCaseSensitive(message_bodyJSON, "number");
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

    // message_body->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(message_bodyJSON, "message");
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

    // message_body->raw
    cJSON *raw = cJSON_GetObjectItemCaseSensitive(message_bodyJSON, "raw");
    if (cJSON_IsNull(raw)) {
        raw = NULL;
    }
    if (!raw) {
        goto end;
    }

    
    if(!cJSON_IsString(raw))
    {
    goto end; //String
    }


    message_body_local_var = message_body_create_internal (
        strdup(number->valuestring),
        strdup(message->valuestring),
        strdup(raw->valuestring)
        );

    return message_body_local_var;
end:
    return NULL;

}
