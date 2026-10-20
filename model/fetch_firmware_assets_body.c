#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "fetch_firmware_assets_body.h"



static fetch_firmware_assets_body_t *fetch_firmware_assets_body_create_internal(
    list_t *asset_urls
    ) {
    fetch_firmware_assets_body_t *fetch_firmware_assets_body_local_var = malloc(sizeof(fetch_firmware_assets_body_t));
    if (!fetch_firmware_assets_body_local_var) {
        return NULL;
    }
    fetch_firmware_assets_body_local_var->asset_urls = asset_urls;

    fetch_firmware_assets_body_local_var->_library_owned = 1;
    return fetch_firmware_assets_body_local_var;
}

__attribute__((deprecated)) fetch_firmware_assets_body_t *fetch_firmware_assets_body_create(
    list_t *asset_urls
    ) {
    return fetch_firmware_assets_body_create_internal (
        asset_urls
        );
}

void fetch_firmware_assets_body_free(fetch_firmware_assets_body_t *fetch_firmware_assets_body) {
    if(NULL == fetch_firmware_assets_body){
        return ;
    }
    if(fetch_firmware_assets_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "fetch_firmware_assets_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (fetch_firmware_assets_body->asset_urls) {
        list_ForEach(listEntry, fetch_firmware_assets_body->asset_urls) {
            free(listEntry->data);
        }
        list_freeList(fetch_firmware_assets_body->asset_urls);
        fetch_firmware_assets_body->asset_urls = NULL;
    }
    free(fetch_firmware_assets_body);
}

cJSON *fetch_firmware_assets_body_convertToJSON(fetch_firmware_assets_body_t *fetch_firmware_assets_body) {
    cJSON *item = cJSON_CreateObject();

    // fetch_firmware_assets_body->asset_urls
    if (!fetch_firmware_assets_body->asset_urls) {
        goto fail;
    }
    cJSON *asset_urls = cJSON_AddArrayToObject(item, "assetUrls");
    if(asset_urls == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *asset_urlsListEntry;
    list_ForEach(asset_urlsListEntry, fetch_firmware_assets_body->asset_urls) {
    if(cJSON_AddStringToObject(asset_urls, "", asset_urlsListEntry->data) == NULL)
    {
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

fetch_firmware_assets_body_t *fetch_firmware_assets_body_parseFromJSON(cJSON *fetch_firmware_assets_bodyJSON){

    fetch_firmware_assets_body_t *fetch_firmware_assets_body_local_var = NULL;

    // define the local list for fetch_firmware_assets_body->asset_urls
    list_t *asset_urlsList = NULL;

    // fetch_firmware_assets_body->asset_urls
    cJSON *asset_urls = cJSON_GetObjectItemCaseSensitive(fetch_firmware_assets_bodyJSON, "assetUrls");
    if (cJSON_IsNull(asset_urls)) {
        asset_urls = NULL;
    }
    if (!asset_urls) {
        goto end;
    }

    
    cJSON *asset_urls_local = NULL;
    if(!cJSON_IsArray(asset_urls)) {
        goto end;//primitive container
    }
    asset_urlsList = list_createList();

    cJSON_ArrayForEach(asset_urls_local, asset_urls)
    {
        if(!cJSON_IsString(asset_urls_local))
        {
            goto end;
        }
        list_addElement(asset_urlsList , strdup(asset_urls_local->valuestring));
    }


    fetch_firmware_assets_body_local_var = fetch_firmware_assets_body_create_internal (
        asset_urlsList
        );

    return fetch_firmware_assets_body_local_var;
end:
    if (asset_urlsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, asset_urlsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(asset_urlsList);
        asset_urlsList = NULL;
    }
    return NULL;

}
