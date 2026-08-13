#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "api_not_found_error_v1.h"



static api_not_found_error_v1_t *api_not_found_error_v1_create_internal(
    char *error,
    char *error_id,
    char *name,
    object_t *params
    ) {
    api_not_found_error_v1_t *api_not_found_error_v1_local_var = malloc(sizeof(api_not_found_error_v1_t));
    if (!api_not_found_error_v1_local_var) {
        return NULL;
    }
    api_not_found_error_v1_local_var->error = error;
    api_not_found_error_v1_local_var->error_id = error_id;
    api_not_found_error_v1_local_var->name = name;
    api_not_found_error_v1_local_var->params = params;

    api_not_found_error_v1_local_var->_library_owned = 1;
    return api_not_found_error_v1_local_var;
}

__attribute__((deprecated)) api_not_found_error_v1_t *api_not_found_error_v1_create(
    char *error,
    char *error_id,
    char *name,
    object_t *params
    ) {
    return api_not_found_error_v1_create_internal (
        error,
        error_id,
        name,
        params
        );
}

void api_not_found_error_v1_free(api_not_found_error_v1_t *api_not_found_error_v1) {
    if(NULL == api_not_found_error_v1){
        return ;
    }
    if(api_not_found_error_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "api_not_found_error_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (api_not_found_error_v1->error) {
        free(api_not_found_error_v1->error);
        api_not_found_error_v1->error = NULL;
    }
    if (api_not_found_error_v1->error_id) {
        free(api_not_found_error_v1->error_id);
        api_not_found_error_v1->error_id = NULL;
    }
    if (api_not_found_error_v1->name) {
        free(api_not_found_error_v1->name);
        api_not_found_error_v1->name = NULL;
    }
    if (api_not_found_error_v1->params) {
        object_free(api_not_found_error_v1->params);
        api_not_found_error_v1->params = NULL;
    }
    free(api_not_found_error_v1);
}

cJSON *api_not_found_error_v1_convertToJSON(api_not_found_error_v1_t *api_not_found_error_v1) {
    cJSON *item = cJSON_CreateObject();

    // api_not_found_error_v1->error
    if (!api_not_found_error_v1->error) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "error", api_not_found_error_v1->error) == NULL) {
    goto fail; //String
    }


    // api_not_found_error_v1->error_id
    if (!api_not_found_error_v1->error_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "errorID", api_not_found_error_v1->error_id) == NULL) {
    goto fail; //String
    }


    // api_not_found_error_v1->name
    if(api_not_found_error_v1->name) {
    if(cJSON_AddStringToObject(item, "name", api_not_found_error_v1->name) == NULL) {
    goto fail; //String
    }
    }


    // api_not_found_error_v1->params
    if(api_not_found_error_v1->params) {
    cJSON *params_object = object_convertToJSON(api_not_found_error_v1->params);
    if(params_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "params", params_object);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

api_not_found_error_v1_t *api_not_found_error_v1_parseFromJSON(cJSON *api_not_found_error_v1JSON){

    api_not_found_error_v1_t *api_not_found_error_v1_local_var = NULL;

    // api_not_found_error_v1->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(api_not_found_error_v1JSON, "error");
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

    // api_not_found_error_v1->error_id
    cJSON *error_id = cJSON_GetObjectItemCaseSensitive(api_not_found_error_v1JSON, "errorID");
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

    // api_not_found_error_v1->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(api_not_found_error_v1JSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // api_not_found_error_v1->params
    cJSON *params = cJSON_GetObjectItemCaseSensitive(api_not_found_error_v1JSON, "params");
    if (cJSON_IsNull(params)) {
        params = NULL;
    }
    object_t *params_local_object = NULL;
    if (params) { 
    params_local_object = object_parseFromJSON(params); //object
    }


    api_not_found_error_v1_local_var = api_not_found_error_v1_create_internal (
        strdup(error->valuestring),
        strdup(error_id->valuestring),
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        params ? params_local_object : NULL
        );

    return api_not_found_error_v1_local_var;
end:
    return NULL;

}
