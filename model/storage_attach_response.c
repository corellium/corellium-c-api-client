#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "storage_attach_response.h"



static storage_attach_response_t *storage_attach_response_create_internal(
    char *status,
    char *message,
    char *id
    ) {
    storage_attach_response_t *storage_attach_response_local_var = malloc(sizeof(storage_attach_response_t));
    if (!storage_attach_response_local_var) {
        return NULL;
    }
    storage_attach_response_local_var->status = status;
    storage_attach_response_local_var->message = message;
    storage_attach_response_local_var->id = id;

    storage_attach_response_local_var->_library_owned = 1;
    return storage_attach_response_local_var;
}

__attribute__((deprecated)) storage_attach_response_t *storage_attach_response_create(
    char *status,
    char *message,
    char *id
    ) {
    return storage_attach_response_create_internal (
        status,
        message,
        id
        );
}

void storage_attach_response_free(storage_attach_response_t *storage_attach_response) {
    if(NULL == storage_attach_response){
        return ;
    }
    if(storage_attach_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "storage_attach_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (storage_attach_response->status) {
        free(storage_attach_response->status);
        storage_attach_response->status = NULL;
    }
    if (storage_attach_response->message) {
        free(storage_attach_response->message);
        storage_attach_response->message = NULL;
    }
    if (storage_attach_response->id) {
        free(storage_attach_response->id);
        storage_attach_response->id = NULL;
    }
    free(storage_attach_response);
}

cJSON *storage_attach_response_convertToJSON(storage_attach_response_t *storage_attach_response) {
    cJSON *item = cJSON_CreateObject();

    // storage_attach_response->status
    if (!storage_attach_response->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", storage_attach_response->status) == NULL) {
    goto fail; //String
    }


    // storage_attach_response->message
    if (!storage_attach_response->message) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message", storage_attach_response->message) == NULL) {
    goto fail; //String
    }


    // storage_attach_response->id
    if (!storage_attach_response->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", storage_attach_response->id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

storage_attach_response_t *storage_attach_response_parseFromJSON(cJSON *storage_attach_responseJSON){

    storage_attach_response_t *storage_attach_response_local_var = NULL;

    // storage_attach_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(storage_attach_responseJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    if(!cJSON_IsString(status))
    {
    goto end; //String
    }

    // storage_attach_response->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(storage_attach_responseJSON, "message");
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

    // storage_attach_response->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(storage_attach_responseJSON, "id");
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


    storage_attach_response_local_var = storage_attach_response_create_internal (
        strdup(status->valuestring),
        strdup(message->valuestring),
        strdup(id->valuestring)
        );

    return storage_attach_response_local_var;
end:
    return NULL;

}
