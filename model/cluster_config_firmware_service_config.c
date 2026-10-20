#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cluster_config_firmware_service_config.h"



static cluster_config_firmware_service_config_t *cluster_config_firmware_service_config_create_internal(
    int fetch_firmware_assets,
    int cluster_firmware_assets,
    int cache_firmware,
    int should_download,
    int fallback_original_url
    ) {
    cluster_config_firmware_service_config_t *cluster_config_firmware_service_config_local_var = malloc(sizeof(cluster_config_firmware_service_config_t));
    if (!cluster_config_firmware_service_config_local_var) {
        return NULL;
    }
    cluster_config_firmware_service_config_local_var->fetch_firmware_assets = fetch_firmware_assets;
    cluster_config_firmware_service_config_local_var->cluster_firmware_assets = cluster_firmware_assets;
    cluster_config_firmware_service_config_local_var->cache_firmware = cache_firmware;
    cluster_config_firmware_service_config_local_var->should_download = should_download;
    cluster_config_firmware_service_config_local_var->fallback_original_url = fallback_original_url;

    cluster_config_firmware_service_config_local_var->_library_owned = 1;
    return cluster_config_firmware_service_config_local_var;
}

__attribute__((deprecated)) cluster_config_firmware_service_config_t *cluster_config_firmware_service_config_create(
    int fetch_firmware_assets,
    int cluster_firmware_assets,
    int cache_firmware,
    int should_download,
    int fallback_original_url
    ) {
    return cluster_config_firmware_service_config_create_internal (
        fetch_firmware_assets,
        cluster_firmware_assets,
        cache_firmware,
        should_download,
        fallback_original_url
        );
}

void cluster_config_firmware_service_config_free(cluster_config_firmware_service_config_t *cluster_config_firmware_service_config) {
    if(NULL == cluster_config_firmware_service_config){
        return ;
    }
    if(cluster_config_firmware_service_config->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cluster_config_firmware_service_config_free");
        return ;
    }
    listEntry_t *listEntry;
    free(cluster_config_firmware_service_config);
}

cJSON *cluster_config_firmware_service_config_convertToJSON(cluster_config_firmware_service_config_t *cluster_config_firmware_service_config) {
    cJSON *item = cJSON_CreateObject();

    // cluster_config_firmware_service_config->fetch_firmware_assets
    if(cluster_config_firmware_service_config->fetch_firmware_assets) {
    if(cJSON_AddBoolToObject(item, "fetchFirmwareAssets", cluster_config_firmware_service_config->fetch_firmware_assets) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_firmware_service_config->cluster_firmware_assets
    if(cluster_config_firmware_service_config->cluster_firmware_assets) {
    if(cJSON_AddBoolToObject(item, "clusterFirmwareAssets", cluster_config_firmware_service_config->cluster_firmware_assets) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_firmware_service_config->cache_firmware
    if(cluster_config_firmware_service_config->cache_firmware) {
    if(cJSON_AddBoolToObject(item, "cacheFirmware", cluster_config_firmware_service_config->cache_firmware) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_firmware_service_config->should_download
    if(cluster_config_firmware_service_config->should_download) {
    if(cJSON_AddBoolToObject(item, "shouldDownload", cluster_config_firmware_service_config->should_download) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_firmware_service_config->fallback_original_url
    if(cluster_config_firmware_service_config->fallback_original_url) {
    if(cJSON_AddBoolToObject(item, "fallbackOriginalUrl", cluster_config_firmware_service_config->fallback_original_url) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

cluster_config_firmware_service_config_t *cluster_config_firmware_service_config_parseFromJSON(cJSON *cluster_config_firmware_service_configJSON){

    cluster_config_firmware_service_config_t *cluster_config_firmware_service_config_local_var = NULL;

    // cluster_config_firmware_service_config->fetch_firmware_assets
    cJSON *fetch_firmware_assets = cJSON_GetObjectItemCaseSensitive(cluster_config_firmware_service_configJSON, "fetchFirmwareAssets");
    if (cJSON_IsNull(fetch_firmware_assets)) {
        fetch_firmware_assets = NULL;
    }
    if (fetch_firmware_assets) { 
    if(!cJSON_IsBool(fetch_firmware_assets))
    {
    goto end; //Bool
    }
    }

    // cluster_config_firmware_service_config->cluster_firmware_assets
    cJSON *cluster_firmware_assets = cJSON_GetObjectItemCaseSensitive(cluster_config_firmware_service_configJSON, "clusterFirmwareAssets");
    if (cJSON_IsNull(cluster_firmware_assets)) {
        cluster_firmware_assets = NULL;
    }
    if (cluster_firmware_assets) { 
    if(!cJSON_IsBool(cluster_firmware_assets))
    {
    goto end; //Bool
    }
    }

    // cluster_config_firmware_service_config->cache_firmware
    cJSON *cache_firmware = cJSON_GetObjectItemCaseSensitive(cluster_config_firmware_service_configJSON, "cacheFirmware");
    if (cJSON_IsNull(cache_firmware)) {
        cache_firmware = NULL;
    }
    if (cache_firmware) { 
    if(!cJSON_IsBool(cache_firmware))
    {
    goto end; //Bool
    }
    }

    // cluster_config_firmware_service_config->should_download
    cJSON *should_download = cJSON_GetObjectItemCaseSensitive(cluster_config_firmware_service_configJSON, "shouldDownload");
    if (cJSON_IsNull(should_download)) {
        should_download = NULL;
    }
    if (should_download) { 
    if(!cJSON_IsBool(should_download))
    {
    goto end; //Bool
    }
    }

    // cluster_config_firmware_service_config->fallback_original_url
    cJSON *fallback_original_url = cJSON_GetObjectItemCaseSensitive(cluster_config_firmware_service_configJSON, "fallbackOriginalUrl");
    if (cJSON_IsNull(fallback_original_url)) {
        fallback_original_url = NULL;
    }
    if (fallback_original_url) { 
    if(!cJSON_IsBool(fallback_original_url))
    {
    goto end; //Bool
    }
    }


    cluster_config_firmware_service_config_local_var = cluster_config_firmware_service_config_create_internal (
        fetch_firmware_assets ? fetch_firmware_assets->valueint : 0,
        cluster_firmware_assets ? cluster_firmware_assets->valueint : 0,
        cache_firmware ? cache_firmware->valueint : 0,
        should_download ? should_download->valueint : 0,
        fallback_original_url ? fallback_original_url->valueint : 0
        );

    return cluster_config_firmware_service_config_local_var;
end:
    return NULL;

}
