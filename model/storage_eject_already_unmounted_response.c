#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "storage_eject_already_unmounted_response.h"



static storage_eject_already_unmounted_response_t *storage_eject_already_unmounted_response_create_internal(
    char *message
    ) {
    storage_eject_already_unmounted_response_t *storage_eject_already_unmounted_response_local_var = malloc(sizeof(storage_eject_already_unmounted_response_t));
    if (!storage_eject_already_unmounted_response_local_var) {
        return NULL;
    }
    storage_eject_already_unmounted_response_local_var->message = message;

    storage_eject_already_unmounted_response_local_var->_library_owned = 1;
    return storage_eject_already_unmounted_response_local_var;
}

__attribute__((deprecated)) storage_eject_already_unmounted_response_t *storage_eject_already_unmounted_response_create(
    char *message
    ) {
    return storage_eject_already_unmounted_response_create_internal (
        message
        );
}

void storage_eject_already_unmounted_response_free(storage_eject_already_unmounted_response_t *storage_eject_already_unmounted_response) {
    if(NULL == storage_eject_already_unmounted_response){
        return ;
    }
    if(storage_eject_already_unmounted_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "storage_eject_already_unmounted_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (storage_eject_already_unmounted_response->message) {
        free(storage_eject_already_unmounted_response->message);
        storage_eject_already_unmounted_response->message = NULL;
    }
    free(storage_eject_already_unmounted_response);
}

cJSON *storage_eject_already_unmounted_response_convertToJSON(storage_eject_already_unmounted_response_t *storage_eject_already_unmounted_response) {
    cJSON *item = cJSON_CreateObject();

    // storage_eject_already_unmounted_response->message
    if (!storage_eject_already_unmounted_response->message) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message", storage_eject_already_unmounted_response->message) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

storage_eject_already_unmounted_response_t *storage_eject_already_unmounted_response_parseFromJSON(cJSON *storage_eject_already_unmounted_responseJSON){

    storage_eject_already_unmounted_response_t *storage_eject_already_unmounted_response_local_var = NULL;

    // storage_eject_already_unmounted_response->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(storage_eject_already_unmounted_responseJSON, "message");
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


    storage_eject_already_unmounted_response_local_var = storage_eject_already_unmounted_response_create_internal (
        strdup(message->valuestring)
        );

    return storage_eject_already_unmounted_response_local_var;
end:
    return NULL;

}
