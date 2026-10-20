#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "api_error_v1.h"



static api_error_v1_t *api_error_v1_create_internal(
    char *error,
    char *error_id,
    char *original_error
    ) {
    api_error_v1_t *api_error_v1_local_var = malloc(sizeof(api_error_v1_t));
    if (!api_error_v1_local_var) {
        return NULL;
    }
    api_error_v1_local_var->error = error;
    api_error_v1_local_var->error_id = error_id;
    api_error_v1_local_var->original_error = original_error;

    api_error_v1_local_var->_library_owned = 1;
    return api_error_v1_local_var;
}

__attribute__((deprecated)) api_error_v1_t *api_error_v1_create(
    char *error,
    char *error_id,
    char *original_error
    ) {
    return api_error_v1_create_internal (
        error,
        error_id,
        original_error
        );
}

void api_error_v1_free(api_error_v1_t *api_error_v1) {
    if(NULL == api_error_v1){
        return ;
    }
    if(api_error_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "api_error_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (api_error_v1->error) {
        free(api_error_v1->error);
        api_error_v1->error = NULL;
    }
    if (api_error_v1->error_id) {
        free(api_error_v1->error_id);
        api_error_v1->error_id = NULL;
    }
    if (api_error_v1->original_error) {
        free(api_error_v1->original_error);
        api_error_v1->original_error = NULL;
    }
    free(api_error_v1);
}

cJSON *api_error_v1_convertToJSON(api_error_v1_t *api_error_v1) {
    cJSON *item = cJSON_CreateObject();

    // api_error_v1->error
    if (!api_error_v1->error) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "error", api_error_v1->error) == NULL) {
    goto fail; //String
    }


    // api_error_v1->error_id
    if (!api_error_v1->error_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "errorID", api_error_v1->error_id) == NULL) {
    goto fail; //String
    }


    // api_error_v1->original_error
    if(api_error_v1->original_error) {
    if(cJSON_AddStringToObject(item, "originalError", api_error_v1->original_error) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

api_error_v1_t *api_error_v1_parseFromJSON(cJSON *api_error_v1JSON){

    api_error_v1_t *api_error_v1_local_var = NULL;

    // api_error_v1->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(api_error_v1JSON, "error");
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

    // api_error_v1->error_id
    cJSON *error_id = cJSON_GetObjectItemCaseSensitive(api_error_v1JSON, "errorID");
    if (cJSON_IsNull(error_id)) {
        error_id = NULL;
    }
    if (!error_id) {
        goto end;
    }

    
    if(!cJSON_IsString(error_id))
    {
    goto end; //String
    }

    // api_error_v1->original_error
    cJSON *original_error = cJSON_GetObjectItemCaseSensitive(api_error_v1JSON, "originalError");
    if (cJSON_IsNull(original_error)) {
        original_error = NULL;
    }
    if (original_error) { 
    if(!cJSON_IsString(original_error) && !cJSON_IsNull(original_error))
    {
    goto end; //String
    }
    }


    api_error_v1_local_var = api_error_v1_create_internal (
        strdup(error->valuestring),
        strdup(error_id->valuestring),
        original_error && !cJSON_IsNull(original_error) ? strdup(original_error->valuestring) : NULL
        );

    return api_error_v1_local_var;
end:
    return NULL;

}
