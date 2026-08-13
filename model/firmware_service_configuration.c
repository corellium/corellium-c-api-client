#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "firmware_service_configuration.h"



static firmware_service_configuration_t *firmware_service_configuration_create_internal(
    int cache_firmware,
    int cluster_firmware_assets,
    int fallback_original_url,
    int fetch_firmware_assets,
    int should_download,
    list_t *download_ipsw_filters
    ) {
    firmware_service_configuration_t *firmware_service_configuration_local_var = malloc(sizeof(firmware_service_configuration_t));
    if (!firmware_service_configuration_local_var) {
        return NULL;
    }
    firmware_service_configuration_local_var->cache_firmware = cache_firmware;
    firmware_service_configuration_local_var->cluster_firmware_assets = cluster_firmware_assets;
    firmware_service_configuration_local_var->fallback_original_url = fallback_original_url;
    firmware_service_configuration_local_var->fetch_firmware_assets = fetch_firmware_assets;
    firmware_service_configuration_local_var->should_download = should_download;
    firmware_service_configuration_local_var->download_ipsw_filters = download_ipsw_filters;

    firmware_service_configuration_local_var->_library_owned = 1;
    return firmware_service_configuration_local_var;
}

__attribute__((deprecated)) firmware_service_configuration_t *firmware_service_configuration_create(
    int cache_firmware,
    int cluster_firmware_assets,
    int fallback_original_url,
    int fetch_firmware_assets,
    int should_download,
    list_t *download_ipsw_filters
    ) {
    return firmware_service_configuration_create_internal (
        cache_firmware,
        cluster_firmware_assets,
        fallback_original_url,
        fetch_firmware_assets,
        should_download,
        download_ipsw_filters
        );
}

void firmware_service_configuration_free(firmware_service_configuration_t *firmware_service_configuration) {
    if(NULL == firmware_service_configuration){
        return ;
    }
    if(firmware_service_configuration->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "firmware_service_configuration_free");
        return ;
    }
    listEntry_t *listEntry;
    if (firmware_service_configuration->download_ipsw_filters) {
        list_ForEach(listEntry, firmware_service_configuration->download_ipsw_filters) {
            ipsw_filter_free(listEntry->data);
        }
        list_freeList(firmware_service_configuration->download_ipsw_filters);
        firmware_service_configuration->download_ipsw_filters = NULL;
    }
    free(firmware_service_configuration);
}

cJSON *firmware_service_configuration_convertToJSON(firmware_service_configuration_t *firmware_service_configuration) {
    cJSON *item = cJSON_CreateObject();

    // firmware_service_configuration->cache_firmware
    if(firmware_service_configuration->cache_firmware) {
    if(cJSON_AddBoolToObject(item, "cacheFirmware", firmware_service_configuration->cache_firmware) == NULL) {
    goto fail; //Bool
    }
    }


    // firmware_service_configuration->cluster_firmware_assets
    if(firmware_service_configuration->cluster_firmware_assets) {
    if(cJSON_AddBoolToObject(item, "clusterFirmwareAssets", firmware_service_configuration->cluster_firmware_assets) == NULL) {
    goto fail; //Bool
    }
    }


    // firmware_service_configuration->fallback_original_url
    if(firmware_service_configuration->fallback_original_url) {
    if(cJSON_AddBoolToObject(item, "fallbackOriginalUrl", firmware_service_configuration->fallback_original_url) == NULL) {
    goto fail; //Bool
    }
    }


    // firmware_service_configuration->fetch_firmware_assets
    if(firmware_service_configuration->fetch_firmware_assets) {
    if(cJSON_AddBoolToObject(item, "fetchFirmwareAssets", firmware_service_configuration->fetch_firmware_assets) == NULL) {
    goto fail; //Bool
    }
    }


    // firmware_service_configuration->should_download
    if(firmware_service_configuration->should_download) {
    if(cJSON_AddBoolToObject(item, "shouldDownload", firmware_service_configuration->should_download) == NULL) {
    goto fail; //Bool
    }
    }


    // firmware_service_configuration->download_ipsw_filters
    if(firmware_service_configuration->download_ipsw_filters) {
    cJSON *download_ipsw_filters = cJSON_AddArrayToObject(item, "downloadIpswFilters");
    if(download_ipsw_filters == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *download_ipsw_filtersListEntry;
    if (firmware_service_configuration->download_ipsw_filters) {
    list_ForEach(download_ipsw_filtersListEntry, firmware_service_configuration->download_ipsw_filters) {
    cJSON *itemLocal = ipsw_filter_convertToJSON(download_ipsw_filtersListEntry->data);
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

firmware_service_configuration_t *firmware_service_configuration_parseFromJSON(cJSON *firmware_service_configurationJSON){

    firmware_service_configuration_t *firmware_service_configuration_local_var = NULL;

    // define the local list for firmware_service_configuration->download_ipsw_filters
    list_t *download_ipsw_filtersList = NULL;

    // firmware_service_configuration->cache_firmware
    cJSON *cache_firmware = cJSON_GetObjectItemCaseSensitive(firmware_service_configurationJSON, "cacheFirmware");
    if (cJSON_IsNull(cache_firmware)) {
        cache_firmware = NULL;
    }
    if (cache_firmware) { 
    if(!cJSON_IsBool(cache_firmware))
    {
    goto end; //Bool
    }
    }

    // firmware_service_configuration->cluster_firmware_assets
    cJSON *cluster_firmware_assets = cJSON_GetObjectItemCaseSensitive(firmware_service_configurationJSON, "clusterFirmwareAssets");
    if (cJSON_IsNull(cluster_firmware_assets)) {
        cluster_firmware_assets = NULL;
    }
    if (cluster_firmware_assets) { 
    if(!cJSON_IsBool(cluster_firmware_assets))
    {
    goto end; //Bool
    }
    }

    // firmware_service_configuration->fallback_original_url
    cJSON *fallback_original_url = cJSON_GetObjectItemCaseSensitive(firmware_service_configurationJSON, "fallbackOriginalUrl");
    if (cJSON_IsNull(fallback_original_url)) {
        fallback_original_url = NULL;
    }
    if (fallback_original_url) { 
    if(!cJSON_IsBool(fallback_original_url))
    {
    goto end; //Bool
    }
    }

    // firmware_service_configuration->fetch_firmware_assets
    cJSON *fetch_firmware_assets = cJSON_GetObjectItemCaseSensitive(firmware_service_configurationJSON, "fetchFirmwareAssets");
    if (cJSON_IsNull(fetch_firmware_assets)) {
        fetch_firmware_assets = NULL;
    }
    if (fetch_firmware_assets) { 
    if(!cJSON_IsBool(fetch_firmware_assets))
    {
    goto end; //Bool
    }
    }

    // firmware_service_configuration->should_download
    cJSON *should_download = cJSON_GetObjectItemCaseSensitive(firmware_service_configurationJSON, "shouldDownload");
    if (cJSON_IsNull(should_download)) {
        should_download = NULL;
    }
    if (should_download) { 
    if(!cJSON_IsBool(should_download))
    {
    goto end; //Bool
    }
    }

    // firmware_service_configuration->download_ipsw_filters
    cJSON *download_ipsw_filters = cJSON_GetObjectItemCaseSensitive(firmware_service_configurationJSON, "downloadIpswFilters");
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
        ipsw_filter_t *download_ipsw_filtersItem = ipsw_filter_parseFromJSON(download_ipsw_filters_local_nonprimitive);

        list_addElement(download_ipsw_filtersList, download_ipsw_filtersItem);
    }
    }


    firmware_service_configuration_local_var = firmware_service_configuration_create_internal (
        cache_firmware ? cache_firmware->valueint : 0,
        cluster_firmware_assets ? cluster_firmware_assets->valueint : 0,
        fallback_original_url ? fallback_original_url->valueint : 0,
        fetch_firmware_assets ? fetch_firmware_assets->valueint : 0,
        should_download ? should_download->valueint : 0,
        download_ipsw_filters ? download_ipsw_filtersList : NULL
        );

    return firmware_service_configuration_local_var;
end:
    if (download_ipsw_filtersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, download_ipsw_filtersList) {
            ipsw_filter_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(download_ipsw_filtersList);
        download_ipsw_filtersList = NULL;
    }
    return NULL;

}
