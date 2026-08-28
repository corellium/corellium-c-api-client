#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "firmware_asset.h"



static firmware_asset_t *firmware_asset_create_internal(
    char *domain,
    char *url,
    char *payload,
    double size,
    char *md5sum,
    char *sha1sum,
    char *sha256sum,
    char *upload_date,
    char *created_at,
    char *updated_at
    ) {
    firmware_asset_t *firmware_asset_local_var = malloc(sizeof(firmware_asset_t));
    if (!firmware_asset_local_var) {
        return NULL;
    }
    firmware_asset_local_var->domain = domain;
    firmware_asset_local_var->url = url;
    firmware_asset_local_var->payload = payload;
    firmware_asset_local_var->size = size;
    firmware_asset_local_var->md5sum = md5sum;
    firmware_asset_local_var->sha1sum = sha1sum;
    firmware_asset_local_var->sha256sum = sha256sum;
    firmware_asset_local_var->upload_date = upload_date;
    firmware_asset_local_var->created_at = created_at;
    firmware_asset_local_var->updated_at = updated_at;

    firmware_asset_local_var->_library_owned = 1;
    return firmware_asset_local_var;
}

__attribute__((deprecated)) firmware_asset_t *firmware_asset_create(
    char *domain,
    char *url,
    char *payload,
    double size,
    char *md5sum,
    char *sha1sum,
    char *sha256sum,
    char *upload_date,
    char *created_at,
    char *updated_at
    ) {
    return firmware_asset_create_internal (
        domain,
        url,
        payload,
        size,
        md5sum,
        sha1sum,
        sha256sum,
        upload_date,
        created_at,
        updated_at
        );
}

void firmware_asset_free(firmware_asset_t *firmware_asset) {
    if(NULL == firmware_asset){
        return ;
    }
    if(firmware_asset->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "firmware_asset_free");
        return ;
    }
    listEntry_t *listEntry;
    if (firmware_asset->domain) {
        free(firmware_asset->domain);
        firmware_asset->domain = NULL;
    }
    if (firmware_asset->url) {
        free(firmware_asset->url);
        firmware_asset->url = NULL;
    }
    if (firmware_asset->payload) {
        free(firmware_asset->payload);
        firmware_asset->payload = NULL;
    }
    if (firmware_asset->md5sum) {
        free(firmware_asset->md5sum);
        firmware_asset->md5sum = NULL;
    }
    if (firmware_asset->sha1sum) {
        free(firmware_asset->sha1sum);
        firmware_asset->sha1sum = NULL;
    }
    if (firmware_asset->sha256sum) {
        free(firmware_asset->sha256sum);
        firmware_asset->sha256sum = NULL;
    }
    if (firmware_asset->upload_date) {
        free(firmware_asset->upload_date);
        firmware_asset->upload_date = NULL;
    }
    if (firmware_asset->created_at) {
        free(firmware_asset->created_at);
        firmware_asset->created_at = NULL;
    }
    if (firmware_asset->updated_at) {
        free(firmware_asset->updated_at);
        firmware_asset->updated_at = NULL;
    }
    free(firmware_asset);
}

cJSON *firmware_asset_convertToJSON(firmware_asset_t *firmware_asset) {
    cJSON *item = cJSON_CreateObject();

    // firmware_asset->domain
    if (!firmware_asset->domain) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "domain", firmware_asset->domain) == NULL) {
    goto fail; //String
    }


    // firmware_asset->url
    if (!firmware_asset->url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "url", firmware_asset->url) == NULL) {
    goto fail; //String
    }


    // firmware_asset->payload
    if (!firmware_asset->payload) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "payload", firmware_asset->payload) == NULL) {
    goto fail; //String
    }


    // firmware_asset->size
    if (!firmware_asset->size) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "size", firmware_asset->size) == NULL) {
    goto fail; //Numeric
    }


    // firmware_asset->md5sum
    if(firmware_asset->md5sum) {
    if(cJSON_AddStringToObject(item, "md5sum", firmware_asset->md5sum) == NULL) {
    goto fail; //String
    }
    }


    // firmware_asset->sha1sum
    if(firmware_asset->sha1sum) {
    if(cJSON_AddStringToObject(item, "sha1sum", firmware_asset->sha1sum) == NULL) {
    goto fail; //String
    }
    }


    // firmware_asset->sha256sum
    if(firmware_asset->sha256sum) {
    if(cJSON_AddStringToObject(item, "sha256sum", firmware_asset->sha256sum) == NULL) {
    goto fail; //String
    }
    }


    // firmware_asset->upload_date
    if(firmware_asset->upload_date) {
    if(cJSON_AddStringToObject(item, "uploadDate", firmware_asset->upload_date) == NULL) {
    goto fail; //String
    }
    }


    // firmware_asset->created_at
    if(firmware_asset->created_at) {
    if(cJSON_AddStringToObject(item, "createdAt", firmware_asset->created_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // firmware_asset->updated_at
    if(firmware_asset->updated_at) {
    if(cJSON_AddStringToObject(item, "updatedAt", firmware_asset->updated_at) == NULL) {
    goto fail; //Date-Time
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

firmware_asset_t *firmware_asset_parseFromJSON(cJSON *firmware_assetJSON){

    firmware_asset_t *firmware_asset_local_var = NULL;

    // firmware_asset->domain
    cJSON *domain = cJSON_GetObjectItemCaseSensitive(firmware_assetJSON, "domain");
    if (cJSON_IsNull(domain)) {
        domain = NULL;
    }
    if (!domain) {
        goto end;
    }

    
    if(!cJSON_IsString(domain))
    {
    goto end; //String
    }

    // firmware_asset->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(firmware_assetJSON, "url");
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

    // firmware_asset->payload
    cJSON *payload = cJSON_GetObjectItemCaseSensitive(firmware_assetJSON, "payload");
    if (cJSON_IsNull(payload)) {
        payload = NULL;
    }
    if (!payload) {
        goto end;
    }

    
    if(!cJSON_IsString(payload))
    {
    goto end; //String
    }

    // firmware_asset->size
    cJSON *size = cJSON_GetObjectItemCaseSensitive(firmware_assetJSON, "size");
    if (cJSON_IsNull(size)) {
        size = NULL;
    }
    if (!size) {
        goto end;
    }

    
    if(!cJSON_IsNumber(size))
    {
    goto end; //Numeric
    }

    // firmware_asset->md5sum
    cJSON *md5sum = cJSON_GetObjectItemCaseSensitive(firmware_assetJSON, "md5sum");
    if (cJSON_IsNull(md5sum)) {
        md5sum = NULL;
    }
    if (md5sum) { 
    if(!cJSON_IsString(md5sum) && !cJSON_IsNull(md5sum))
    {
    goto end; //String
    }
    }

    // firmware_asset->sha1sum
    cJSON *sha1sum = cJSON_GetObjectItemCaseSensitive(firmware_assetJSON, "sha1sum");
    if (cJSON_IsNull(sha1sum)) {
        sha1sum = NULL;
    }
    if (sha1sum) { 
    if(!cJSON_IsString(sha1sum) && !cJSON_IsNull(sha1sum))
    {
    goto end; //String
    }
    }

    // firmware_asset->sha256sum
    cJSON *sha256sum = cJSON_GetObjectItemCaseSensitive(firmware_assetJSON, "sha256sum");
    if (cJSON_IsNull(sha256sum)) {
        sha256sum = NULL;
    }
    if (sha256sum) { 
    if(!cJSON_IsString(sha256sum) && !cJSON_IsNull(sha256sum))
    {
    goto end; //String
    }
    }

    // firmware_asset->upload_date
    cJSON *upload_date = cJSON_GetObjectItemCaseSensitive(firmware_assetJSON, "uploadDate");
    if (cJSON_IsNull(upload_date)) {
        upload_date = NULL;
    }
    if (upload_date) { 
    if(!cJSON_IsString(upload_date) && !cJSON_IsNull(upload_date))
    {
    goto end; //String
    }
    }

    // firmware_asset->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(firmware_assetJSON, "createdAt");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (created_at) { 
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //DateTime
    }
    }

    // firmware_asset->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(firmware_assetJSON, "updatedAt");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (updated_at) { 
    if(!cJSON_IsString(updated_at) && !cJSON_IsNull(updated_at))
    {
    goto end; //DateTime
    }
    }


    firmware_asset_local_var = firmware_asset_create_internal (
        strdup(domain->valuestring),
        strdup(url->valuestring),
        strdup(payload->valuestring),
        size->valuedouble,
        md5sum && !cJSON_IsNull(md5sum) ? strdup(md5sum->valuestring) : NULL,
        sha1sum && !cJSON_IsNull(sha1sum) ? strdup(sha1sum->valuestring) : NULL,
        sha256sum && !cJSON_IsNull(sha256sum) ? strdup(sha256sum->valuestring) : NULL,
        upload_date && !cJSON_IsNull(upload_date) ? strdup(upload_date->valuestring) : NULL,
        created_at && !cJSON_IsNull(created_at) ? strdup(created_at->valuestring) : NULL,
        updated_at && !cJSON_IsNull(updated_at) ? strdup(updated_at->valuestring) : NULL
        );

    return firmware_asset_local_var;
end:
    return NULL;

}
