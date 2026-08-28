#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "firmware_asset_filter.h"



static firmware_asset_filter_t *firmware_asset_filter_create_internal(
    char *url,
    char *domain
    ) {
    firmware_asset_filter_t *firmware_asset_filter_local_var = malloc(sizeof(firmware_asset_filter_t));
    if (!firmware_asset_filter_local_var) {
        return NULL;
    }
    firmware_asset_filter_local_var->url = url;
    firmware_asset_filter_local_var->domain = domain;

    firmware_asset_filter_local_var->_library_owned = 1;
    return firmware_asset_filter_local_var;
}

__attribute__((deprecated)) firmware_asset_filter_t *firmware_asset_filter_create(
    char *url,
    char *domain
    ) {
    return firmware_asset_filter_create_internal (
        url,
        domain
        );
}

void firmware_asset_filter_free(firmware_asset_filter_t *firmware_asset_filter) {
    if(NULL == firmware_asset_filter){
        return ;
    }
    if(firmware_asset_filter->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "firmware_asset_filter_free");
        return ;
    }
    listEntry_t *listEntry;
    if (firmware_asset_filter->url) {
        free(firmware_asset_filter->url);
        firmware_asset_filter->url = NULL;
    }
    if (firmware_asset_filter->domain) {
        free(firmware_asset_filter->domain);
        firmware_asset_filter->domain = NULL;
    }
    free(firmware_asset_filter);
}

cJSON *firmware_asset_filter_convertToJSON(firmware_asset_filter_t *firmware_asset_filter) {
    cJSON *item = cJSON_CreateObject();

    // firmware_asset_filter->url
    if(firmware_asset_filter->url) {
    if(cJSON_AddStringToObject(item, "url", firmware_asset_filter->url) == NULL) {
    goto fail; //String
    }
    }


    // firmware_asset_filter->domain
    if(firmware_asset_filter->domain) {
    if(cJSON_AddStringToObject(item, "domain", firmware_asset_filter->domain) == NULL) {
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

firmware_asset_filter_t *firmware_asset_filter_parseFromJSON(cJSON *firmware_asset_filterJSON){

    firmware_asset_filter_t *firmware_asset_filter_local_var = NULL;

    // firmware_asset_filter->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(firmware_asset_filterJSON, "url");
    if (cJSON_IsNull(url)) {
        url = NULL;
    }
    if (url) { 
    if(!cJSON_IsString(url) && !cJSON_IsNull(url))
    {
    goto end; //String
    }
    }

    // firmware_asset_filter->domain
    cJSON *domain = cJSON_GetObjectItemCaseSensitive(firmware_asset_filterJSON, "domain");
    if (cJSON_IsNull(domain)) {
        domain = NULL;
    }
    if (domain) { 
    if(!cJSON_IsString(domain) && !cJSON_IsNull(domain))
    {
    goto end; //String
    }
    }


    firmware_asset_filter_local_var = firmware_asset_filter_create_internal (
        url && !cJSON_IsNull(url) ? strdup(url->valuestring) : NULL,
        domain && !cJSON_IsNull(domain) ? strdup(domain->valuestring) : NULL
        );

    return firmware_asset_filter_local_var;
end:
    return NULL;

}
