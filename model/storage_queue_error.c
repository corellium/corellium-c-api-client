#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "storage_queue_error.h"



static storage_queue_error_t *storage_queue_error_create_internal(
    char *error,
    char *details,
    char *suggestion
    ) {
    storage_queue_error_t *storage_queue_error_local_var = malloc(sizeof(storage_queue_error_t));
    if (!storage_queue_error_local_var) {
        return NULL;
    }
    storage_queue_error_local_var->error = error;
    storage_queue_error_local_var->details = details;
    storage_queue_error_local_var->suggestion = suggestion;

    storage_queue_error_local_var->_library_owned = 1;
    return storage_queue_error_local_var;
}

__attribute__((deprecated)) storage_queue_error_t *storage_queue_error_create(
    char *error,
    char *details,
    char *suggestion
    ) {
    return storage_queue_error_create_internal (
        error,
        details,
        suggestion
        );
}

void storage_queue_error_free(storage_queue_error_t *storage_queue_error) {
    if(NULL == storage_queue_error){
        return ;
    }
    if(storage_queue_error->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "storage_queue_error_free");
        return ;
    }
    listEntry_t *listEntry;
    if (storage_queue_error->error) {
        free(storage_queue_error->error);
        storage_queue_error->error = NULL;
    }
    if (storage_queue_error->details) {
        free(storage_queue_error->details);
        storage_queue_error->details = NULL;
    }
    if (storage_queue_error->suggestion) {
        free(storage_queue_error->suggestion);
        storage_queue_error->suggestion = NULL;
    }
    free(storage_queue_error);
}

cJSON *storage_queue_error_convertToJSON(storage_queue_error_t *storage_queue_error) {
    cJSON *item = cJSON_CreateObject();

    // storage_queue_error->error
    if (!storage_queue_error->error) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "error", storage_queue_error->error) == NULL) {
    goto fail; //String
    }


    // storage_queue_error->details
    if (!storage_queue_error->details) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "details", storage_queue_error->details) == NULL) {
    goto fail; //String
    }


    // storage_queue_error->suggestion
    if (!storage_queue_error->suggestion) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "suggestion", storage_queue_error->suggestion) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

storage_queue_error_t *storage_queue_error_parseFromJSON(cJSON *storage_queue_errorJSON){

    storage_queue_error_t *storage_queue_error_local_var = NULL;

    // storage_queue_error->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(storage_queue_errorJSON, "error");
    if (cJSON_IsNull(error)) {
        error = NULL;
    }
    if (!error) {
        goto end;
    }

    
    if(!cJSON_IsString(error))
    {
    goto end; //String
    }

    // storage_queue_error->details
    cJSON *details = cJSON_GetObjectItemCaseSensitive(storage_queue_errorJSON, "details");
    if (cJSON_IsNull(details)) {
        details = NULL;
    }
    if (!details) {
        goto end;
    }

    
    if(!cJSON_IsString(details))
    {
    goto end; //String
    }

    // storage_queue_error->suggestion
    cJSON *suggestion = cJSON_GetObjectItemCaseSensitive(storage_queue_errorJSON, "suggestion");
    if (cJSON_IsNull(suggestion)) {
        suggestion = NULL;
    }
    if (!suggestion) {
        goto end;
    }

    
    if(!cJSON_IsString(suggestion))
    {
    goto end; //String
    }


    storage_queue_error_local_var = storage_queue_error_create_internal (
        strdup(error->valuestring),
        strdup(details->valuestring),
        strdup(suggestion->valuestring)
        );

    return storage_queue_error_local_var;
end:
    return NULL;

}
