#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "patch_firmware_service_config_body.h"



static patch_firmware_service_config_body_t *patch_firmware_service_config_body_create_internal(
    int cache_firmware,
    int cluster_firmware_assets,
    int fallback_original_url,
    int fetch_firmware_assets,
    int should_download,
    list_t *download_ipsw_filters
    ) {
    patch_firmware_service_config_body_t *patch_firmware_service_config_body_local_var = malloc(sizeof(patch_firmware_service_config_body_t));
    if (!patch_firmware_service_config_body_local_var) {
        return NULL;
    }
    patch_firmware_service_config_body_local_var->cache_firmware = cache_firmware;
    patch_firmware_service_config_body_local_var->cluster_firmware_assets = cluster_firmware_assets;
    patch_firmware_service_config_body_local_var->fallback_original_url = fallback_original_url;
    patch_firmware_service_config_body_local_var->fetch_firmware_assets = fetch_firmware_assets;
    patch_firmware_service_config_body_local_var->should_download = should_download;
    patch_firmware_service_config_body_local_var->download_ipsw_filters = download_ipsw_filters;

    patch_firmware_service_config_body_local_var->_library_owned = 1;
    return patch_firmware_service_config_body_local_var;
}

__attribute__((deprecated)) patch_firmware_service_config_body_t *patch_firmware_service_config_body_create(
    int cache_firmware,
    int cluster_firmware_assets,
    int fallback_original_url,
    int fetch_firmware_assets,
    int should_download,
    list_t *download_ipsw_filters
    ) {
    return patch_firmware_service_config_body_create_internal (
        cache_firmware,
        cluster_firmware_assets,
        fallback_original_url,
        fetch_firmware_assets,
        should_download,
        download_ipsw_filters
        );
}

void patch_firmware_service_config_body_free(patch_firmware_service_config_body_t *patch_firmware_service_config_body) {
    if(NULL == patch_firmware_service_config_body){
        return ;
    }
    if(patch_firmware_service_config_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "patch_firmware_service_config_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (patch_firmware_service_config_body->download_ipsw_filters) {
        list_ForEach(listEntry, patch_firmware_service_config_body->download_ipsw_filters) {
            object_free(listEntry->data);
        }
        list_freeList(patch_firmware_service_config_body->download_ipsw_filters);
        patch_firmware_service_config_body->download_ipsw_filters = NULL;
    }
    free(patch_firmware_service_config_body);
}

cJSON *patch_firmware_service_config_body_convertToJSON(patch_firmware_service_config_body_t *patch_firmware_service_config_body) {
    cJSON *item = cJSON_CreateObject();

    // patch_firmware_service_config_body->cache_firmware
    if(patch_firmware_service_config_body->cache_firmware) {
    if(cJSON_AddBoolToObject(item, "cacheFirmware", patch_firmware_service_config_body->cache_firmware) == NULL) {
    goto fail; //Bool
    }
    }


    // patch_firmware_service_config_body->cluster_firmware_assets
    if(patch_firmware_service_config_body->cluster_firmware_assets) {
    if(cJSON_AddBoolToObject(item, "clusterFirmwareAssets", patch_firmware_service_config_body->cluster_firmware_assets) == NULL) {
    goto fail; //Bool
    }
    }


    // patch_firmware_service_config_body->fallback_original_url
    if(patch_firmware_service_config_body->fallback_original_url) {
    if(cJSON_AddBoolToObject(item, "fallbackOriginalUrl", patch_firmware_service_config_body->fallback_original_url) == NULL) {
    goto fail; //Bool
    }
    }


    // patch_firmware_service_config_body->fetch_firmware_assets
    if(patch_firmware_service_config_body->fetch_firmware_assets) {
    if(cJSON_AddBoolToObject(item, "fetchFirmwareAssets", patch_firmware_service_config_body->fetch_firmware_assets) == NULL) {
    goto fail; //Bool
    }
    }


    // patch_firmware_service_config_body->should_download
    if(patch_firmware_service_config_body->should_download) {
    if(cJSON_AddBoolToObject(item, "shouldDownload", patch_firmware_service_config_body->should_download) == NULL) {
    goto fail; //Bool
    }
    }


    // patch_firmware_service_config_body->download_ipsw_filters
    if(patch_firmware_service_config_body->download_ipsw_filters) {
    cJSON *download_ipsw_filters = cJSON_AddArrayToObject(item, "downloadIpswFilters");
    if(download_ipsw_filters == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *download_ipsw_filtersListEntry;
    if (patch_firmware_service_config_body->download_ipsw_filters) {
    list_ForEach(download_ipsw_filtersListEntry, patch_firmware_service_config_body->download_ipsw_filters) {
    cJSON *itemLocal = object_convertToJSON(download_ipsw_filtersListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(download_ipsw_filters, itemLocal);
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

patch_firmware_service_config_body_t *patch_firmware_service_config_body_parseFromJSON(cJSON *patch_firmware_service_config_bodyJSON){

    patch_firmware_service_config_body_t *patch_firmware_service_config_body_local_var = NULL;

    // define the local list for patch_firmware_service_config_body->download_ipsw_filters
    list_t *download_ipsw_filtersList = NULL;

    // patch_firmware_service_config_body->cache_firmware
    cJSON *cache_firmware = cJSON_GetObjectItemCaseSensitive(patch_firmware_service_config_bodyJSON, "cacheFirmware");
    if (cJSON_IsNull(cache_firmware)) {
        cache_firmware = NULL;
    }
    if (cache_firmware) { 
    if(!cJSON_IsBool(cache_firmware))
    {
    goto end; //Bool
    }
    }

    // patch_firmware_service_config_body->cluster_firmware_assets
    cJSON *cluster_firmware_assets = cJSON_GetObjectItemCaseSensitive(patch_firmware_service_config_bodyJSON, "clusterFirmwareAssets");
    if (cJSON_IsNull(cluster_firmware_assets)) {
        cluster_firmware_assets = NULL;
    }
    if (cluster_firmware_assets) { 
    if(!cJSON_IsBool(cluster_firmware_assets))
    {
    goto end; //Bool
    }
    }

    // patch_firmware_service_config_body->fallback_original_url
    cJSON *fallback_original_url = cJSON_GetObjectItemCaseSensitive(patch_firmware_service_config_bodyJSON, "fallbackOriginalUrl");
    if (cJSON_IsNull(fallback_original_url)) {
        fallback_original_url = NULL;
    }
    if (fallback_original_url) { 
    if(!cJSON_IsBool(fallback_original_url))
    {
    goto end; //Bool
    }
    }

    // patch_firmware_service_config_body->fetch_firmware_assets
    cJSON *fetch_firmware_assets = cJSON_GetObjectItemCaseSensitive(patch_firmware_service_config_bodyJSON, "fetchFirmwareAssets");
    if (cJSON_IsNull(fetch_firmware_assets)) {
        fetch_firmware_assets = NULL;
    }
    if (fetch_firmware_assets) { 
    if(!cJSON_IsBool(fetch_firmware_assets))
    {
    goto end; //Bool
    }
    }

    // patch_firmware_service_config_body->should_download
    cJSON *should_download = cJSON_GetObjectItemCaseSensitive(patch_firmware_service_config_bodyJSON, "shouldDownload");
    if (cJSON_IsNull(should_download)) {
        should_download = NULL;
    }
    if (should_download) { 
    if(!cJSON_IsBool(should_download))
    {
    goto end; //Bool
    }
    }

    // patch_firmware_service_config_body->download_ipsw_filters
    cJSON *download_ipsw_filters = cJSON_GetObjectItemCaseSensitive(patch_firmware_service_config_bodyJSON, "downloadIpswFilters");
    if (cJSON_IsNull(download_ipsw_filters)) {
        download_ipsw_filters = NULL;
    }
    if (download_ipsw_filters) { 
    cJSON *download_ipsw_filters_local_nonprimitive = NULL;
    if(!cJSON_IsArray(download_ipsw_filters)){
        goto end; //nonprimitive container
    }

    download_ipsw_filtersList = list_createList();

    cJSON_ArrayForEach(download_ipsw_filters_local_nonprimitive,download_ipsw_filters )
    {
        if(!cJSON_IsObject(download_ipsw_filters_local_nonprimitive)){
            goto end;
        }
        object_t *download_ipsw_filtersItem = object_parseFromJSON(download_ipsw_filters_local_nonprimitive);

        list_addElement(download_ipsw_filtersList, download_ipsw_filtersItem);
    }
    }


    patch_firmware_service_config_body_local_var = patch_firmware_service_config_body_create_internal (
        cache_firmware ? cache_firmware->valueint : 0,
        cluster_firmware_assets ? cluster_firmware_assets->valueint : 0,
        fallback_original_url ? fallback_original_url->valueint : 0,
        fetch_firmware_assets ? fetch_firmware_assets->valueint : 0,
        should_download ? should_download->valueint : 0,
        download_ipsw_filters ? download_ipsw_filtersList : NULL
        );

    return patch_firmware_service_config_body_local_var;
end:
    if (download_ipsw_filtersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, download_ipsw_filtersList) {
            object_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(download_ipsw_filtersList);
        download_ipsw_filtersList = NULL;
    }
    return NULL;

}
