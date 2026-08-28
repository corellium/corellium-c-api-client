#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "firmware_service_config.h"



static firmware_service_config_t *firmware_service_config_create_internal(
    firmware_service_config_cache_firmware_t *cache_firmware,
    firmware_service_config_cache_firmware_t *cluster_firmware_assets,
    firmware_service_config_cache_firmware_t *fallback_original_url,
    firmware_service_config_cache_firmware_t *fetch_firmware_assets,
    firmware_service_config_cache_firmware_t *should_download,
    firmware_service_config_download_ipsw_filters_t *download_ipsw_filters
    ) {
    firmware_service_config_t *firmware_service_config_local_var = malloc(sizeof(firmware_service_config_t));
    if (!firmware_service_config_local_var) {
        return NULL;
    }
    firmware_service_config_local_var->cache_firmware = cache_firmware;
    firmware_service_config_local_var->cluster_firmware_assets = cluster_firmware_assets;
    firmware_service_config_local_var->fallback_original_url = fallback_original_url;
    firmware_service_config_local_var->fetch_firmware_assets = fetch_firmware_assets;
    firmware_service_config_local_var->should_download = should_download;
    firmware_service_config_local_var->download_ipsw_filters = download_ipsw_filters;

    firmware_service_config_local_var->_library_owned = 1;
    return firmware_service_config_local_var;
}

__attribute__((deprecated)) firmware_service_config_t *firmware_service_config_create(
    firmware_service_config_cache_firmware_t *cache_firmware,
    firmware_service_config_cache_firmware_t *cluster_firmware_assets,
    firmware_service_config_cache_firmware_t *fallback_original_url,
    firmware_service_config_cache_firmware_t *fetch_firmware_assets,
    firmware_service_config_cache_firmware_t *should_download,
    firmware_service_config_download_ipsw_filters_t *download_ipsw_filters
    ) {
    return firmware_service_config_create_internal (
        cache_firmware,
        cluster_firmware_assets,
        fallback_original_url,
        fetch_firmware_assets,
        should_download,
        download_ipsw_filters
        );
}

void firmware_service_config_free(firmware_service_config_t *firmware_service_config) {
    if(NULL == firmware_service_config){
        return ;
    }
    if(firmware_service_config->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "firmware_service_config_free");
        return ;
    }
    listEntry_t *listEntry;
    if (firmware_service_config->cache_firmware) {
        firmware_service_config_cache_firmware_free(firmware_service_config->cache_firmware);
        firmware_service_config->cache_firmware = NULL;
    }
    if (firmware_service_config->cluster_firmware_assets) {
        firmware_service_config_cache_firmware_free(firmware_service_config->cluster_firmware_assets);
        firmware_service_config->cluster_firmware_assets = NULL;
    }
    if (firmware_service_config->fallback_original_url) {
        firmware_service_config_cache_firmware_free(firmware_service_config->fallback_original_url);
        firmware_service_config->fallback_original_url = NULL;
    }
    if (firmware_service_config->fetch_firmware_assets) {
        firmware_service_config_cache_firmware_free(firmware_service_config->fetch_firmware_assets);
        firmware_service_config->fetch_firmware_assets = NULL;
    }
    if (firmware_service_config->should_download) {
        firmware_service_config_cache_firmware_free(firmware_service_config->should_download);
        firmware_service_config->should_download = NULL;
    }
    if (firmware_service_config->download_ipsw_filters) {
        firmware_service_config_download_ipsw_filters_free(firmware_service_config->download_ipsw_filters);
        firmware_service_config->download_ipsw_filters = NULL;
    }
    free(firmware_service_config);
}

cJSON *firmware_service_config_convertToJSON(firmware_service_config_t *firmware_service_config) {
    cJSON *item = cJSON_CreateObject();

    // firmware_service_config->cache_firmware
    if (!firmware_service_config->cache_firmware) {
        goto fail;
    }
    cJSON *cache_firmware_local_JSON = firmware_service_config_cache_firmware_convertToJSON(firmware_service_config->cache_firmware);
    if(cache_firmware_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "cacheFirmware", cache_firmware_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // firmware_service_config->cluster_firmware_assets
    if (!firmware_service_config->cluster_firmware_assets) {
        goto fail;
    }
    cJSON *cluster_firmware_assets_local_JSON = firmware_service_config_cache_firmware_convertToJSON(firmware_service_config->cluster_firmware_assets);
    if(cluster_firmware_assets_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "clusterFirmwareAssets", cluster_firmware_assets_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // firmware_service_config->fallback_original_url
    if (!firmware_service_config->fallback_original_url) {
        goto fail;
    }
    cJSON *fallback_original_url_local_JSON = firmware_service_config_cache_firmware_convertToJSON(firmware_service_config->fallback_original_url);
    if(fallback_original_url_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "fallbackOriginalUrl", fallback_original_url_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // firmware_service_config->fetch_firmware_assets
    if (!firmware_service_config->fetch_firmware_assets) {
        goto fail;
    }
    cJSON *fetch_firmware_assets_local_JSON = firmware_service_config_cache_firmware_convertToJSON(firmware_service_config->fetch_firmware_assets);
    if(fetch_firmware_assets_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "fetchFirmwareAssets", fetch_firmware_assets_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // firmware_service_config->should_download
    if (!firmware_service_config->should_download) {
        goto fail;
    }
    cJSON *should_download_local_JSON = firmware_service_config_cache_firmware_convertToJSON(firmware_service_config->should_download);
    if(should_download_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "shouldDownload", should_download_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // firmware_service_config->download_ipsw_filters
    if (!firmware_service_config->download_ipsw_filters) {
        goto fail;
    }
    cJSON *download_ipsw_filters_local_JSON = firmware_service_config_download_ipsw_filters_convertToJSON(firmware_service_config->download_ipsw_filters);
    if(download_ipsw_filters_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "downloadIpswFilters", download_ipsw_filters_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

firmware_service_config_t *firmware_service_config_parseFromJSON(cJSON *firmware_service_configJSON){

    firmware_service_config_t *firmware_service_config_local_var = NULL;

    // define the local variable for firmware_service_config->cache_firmware
    firmware_service_config_cache_firmware_t *cache_firmware_local_nonprim = NULL;

    // define the local variable for firmware_service_config->cluster_firmware_assets
    firmware_service_config_cache_firmware_t *cluster_firmware_assets_local_nonprim = NULL;

    // define the local variable for firmware_service_config->fallback_original_url
    firmware_service_config_cache_firmware_t *fallback_original_url_local_nonprim = NULL;

    // define the local variable for firmware_service_config->fetch_firmware_assets
    firmware_service_config_cache_firmware_t *fetch_firmware_assets_local_nonprim = NULL;

    // define the local variable for firmware_service_config->should_download
    firmware_service_config_cache_firmware_t *should_download_local_nonprim = NULL;

    // define the local variable for firmware_service_config->download_ipsw_filters
    firmware_service_config_download_ipsw_filters_t *download_ipsw_filters_local_nonprim = NULL;

    // firmware_service_config->cache_firmware
    cJSON *cache_firmware = cJSON_GetObjectItemCaseSensitive(firmware_service_configJSON, "cacheFirmware");
    if (cJSON_IsNull(cache_firmware)) {
        cache_firmware = NULL;
    }
    if (!cache_firmware) {
        goto end;
    }

    
    cache_firmware_local_nonprim = firmware_service_config_cache_firmware_parseFromJSON(cache_firmware); //nonprimitive

    // firmware_service_config->cluster_firmware_assets
    cJSON *cluster_firmware_assets = cJSON_GetObjectItemCaseSensitive(firmware_service_configJSON, "clusterFirmwareAssets");
    if (cJSON_IsNull(cluster_firmware_assets)) {
        cluster_firmware_assets = NULL;
    }
    if (!cluster_firmware_assets) {
        goto end;
    }

    
    cluster_firmware_assets_local_nonprim = firmware_service_config_cache_firmware_parseFromJSON(cluster_firmware_assets); //nonprimitive

    // firmware_service_config->fallback_original_url
    cJSON *fallback_original_url = cJSON_GetObjectItemCaseSensitive(firmware_service_configJSON, "fallbackOriginalUrl");
    if (cJSON_IsNull(fallback_original_url)) {
        fallback_original_url = NULL;
    }
    if (!fallback_original_url) {
        goto end;
    }

    
    fallback_original_url_local_nonprim = firmware_service_config_cache_firmware_parseFromJSON(fallback_original_url); //nonprimitive

    // firmware_service_config->fetch_firmware_assets
    cJSON *fetch_firmware_assets = cJSON_GetObjectItemCaseSensitive(firmware_service_configJSON, "fetchFirmwareAssets");
    if (cJSON_IsNull(fetch_firmware_assets)) {
        fetch_firmware_assets = NULL;
    }
    if (!fetch_firmware_assets) {
        goto end;
    }

    
    fetch_firmware_assets_local_nonprim = firmware_service_config_cache_firmware_parseFromJSON(fetch_firmware_assets); //nonprimitive

    // firmware_service_config->should_download
    cJSON *should_download = cJSON_GetObjectItemCaseSensitive(firmware_service_configJSON, "shouldDownload");
    if (cJSON_IsNull(should_download)) {
        should_download = NULL;
    }
    if (!should_download) {
        goto end;
    }

    
    should_download_local_nonprim = firmware_service_config_cache_firmware_parseFromJSON(should_download); //nonprimitive

    // firmware_service_config->download_ipsw_filters
    cJSON *download_ipsw_filters = cJSON_GetObjectItemCaseSensitive(firmware_service_configJSON, "downloadIpswFilters");
    if (cJSON_IsNull(download_ipsw_filters)) {
        download_ipsw_filters = NULL;
    }
    if (!download_ipsw_filters) {
        goto end;
    }

    
    download_ipsw_filters_local_nonprim = firmware_service_config_download_ipsw_filters_parseFromJSON(download_ipsw_filters); //nonprimitive


    firmware_service_config_local_var = firmware_service_config_create_internal (
        cache_firmware_local_nonprim,
        cluster_firmware_assets_local_nonprim,
        fallback_original_url_local_nonprim,
        fetch_firmware_assets_local_nonprim,
        should_download_local_nonprim,
        download_ipsw_filters_local_nonprim
        );

    return firmware_service_config_local_var;
end:
    if (cache_firmware_local_nonprim) {
        firmware_service_config_cache_firmware_free(cache_firmware_local_nonprim);
        cache_firmware_local_nonprim = NULL;
    }
    if (cluster_firmware_assets_local_nonprim) {
        firmware_service_config_cache_firmware_free(cluster_firmware_assets_local_nonprim);
        cluster_firmware_assets_local_nonprim = NULL;
    }
    if (fallback_original_url_local_nonprim) {
        firmware_service_config_cache_firmware_free(fallback_original_url_local_nonprim);
        fallback_original_url_local_nonprim = NULL;
    }
    if (fetch_firmware_assets_local_nonprim) {
        firmware_service_config_cache_firmware_free(fetch_firmware_assets_local_nonprim);
        fetch_firmware_assets_local_nonprim = NULL;
    }
    if (should_download_local_nonprim) {
        firmware_service_config_cache_firmware_free(should_download_local_nonprim);
        should_download_local_nonprim = NULL;
    }
    if (download_ipsw_filters_local_nonprim) {
        firmware_service_config_download_ipsw_filters_free(download_ipsw_filters_local_nonprim);
        download_ipsw_filters_local_nonprim = NULL;
    }
    return NULL;

}
