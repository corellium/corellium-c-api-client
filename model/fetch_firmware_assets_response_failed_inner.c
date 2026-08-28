#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "fetch_firmware_assets_response_failed_inner.h"



static fetch_firmware_assets_response_failed_inner_t *fetch_firmware_assets_response_failed_inner_create_internal(
    char *url,
    char *error
    ) {
    fetch_firmware_assets_response_failed_inner_t *fetch_firmware_assets_response_failed_inner_local_var = malloc(sizeof(fetch_firmware_assets_response_failed_inner_t));
    if (!fetch_firmware_assets_response_failed_inner_local_var) {
        return NULL;
    }
    fetch_firmware_assets_response_failed_inner_local_var->url = url;
    fetch_firmware_assets_response_failed_inner_local_var->error = error;

    fetch_firmware_assets_response_failed_inner_local_var->_library_owned = 1;
    return fetch_firmware_assets_response_failed_inner_local_var;
}

__attribute__((deprecated)) fetch_firmware_assets_response_failed_inner_t *fetch_firmware_assets_response_failed_inner_create(
    char *url,
    char *error
    ) {
    return fetch_firmware_assets_response_failed_inner_create_internal (
        url,
        error
        );
}

void fetch_firmware_assets_response_failed_inner_free(fetch_firmware_assets_response_failed_inner_t *fetch_firmware_assets_response_failed_inner) {
    if(NULL == fetch_firmware_assets_response_failed_inner){
        return ;
    }
    if(fetch_firmware_assets_response_failed_inner->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "fetch_firmware_assets_response_failed_inner_free");
        return ;
    }
    listEntry_t *listEntry;
    if (fetch_firmware_assets_response_failed_inner->url) {
        free(fetch_firmware_assets_response_failed_inner->url);
        fetch_firmware_assets_response_failed_inner->url = NULL;
    }
    if (fetch_firmware_assets_response_failed_inner->error) {
        free(fetch_firmware_assets_response_failed_inner->error);
        fetch_firmware_assets_response_failed_inner->error = NULL;
    }
    free(fetch_firmware_assets_response_failed_inner);
}

cJSON *fetch_firmware_assets_response_failed_inner_convertToJSON(fetch_firmware_assets_response_failed_inner_t *fetch_firmware_assets_response_failed_inner) {
    cJSON *item = cJSON_CreateObject();

    // fetch_firmware_assets_response_failed_inner->url
    if (!fetch_firmware_assets_response_failed_inner->url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "url", fetch_firmware_assets_response_failed_inner->url) == NULL) {
    goto fail; //String
    }


    // fetch_firmware_assets_response_failed_inner->error
    if (!fetch_firmware_assets_response_failed_inner->error) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "error", fetch_firmware_assets_response_failed_inner->error) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

fetch_firmware_assets_response_failed_inner_t *fetch_firmware_assets_response_failed_inner_parseFromJSON(cJSON *fetch_firmware_assets_response_failed_innerJSON){

    fetch_firmware_assets_response_failed_inner_t *fetch_firmware_assets_response_failed_inner_local_var = NULL;

    // fetch_firmware_assets_response_failed_inner->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(fetch_firmware_assets_response_failed_innerJSON, "url");
    if (cJSON_IsNull(url)) {
        url = NULL;
    }
    if (!url) {
        goto end;
    }

    
    if(!cJSON_IsString(url))
    {
    goto end; //String
    }

    // fetch_firmware_assets_response_failed_inner->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(fetch_firmware_assets_response_failed_innerJSON, "error");
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


    fetch_firmware_assets_response_failed_inner_local_var = fetch_firmware_assets_response_failed_inner_create_internal (
        strdup(url->valuestring),
        strdup(error->valuestring)
        );

    return fetch_firmware_assets_response_failed_inner_local_var;
end:
    return NULL;

}
