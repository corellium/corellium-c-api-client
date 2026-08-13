#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "firmware_asset_v1.h"



static firmware_asset_v1_t *firmware_asset_v1_create_internal(
    char *domain,
    char *url,
    char *payload,
    double size,
    char *md5sum,
    char *sha1sum,
    char *sha256sum,
    char *uploaddate,
    char *created_at,
    char *updated_at
    ) {
    firmware_asset_v1_t *firmware_asset_v1_local_var = malloc(sizeof(firmware_asset_v1_t));
    if (!firmware_asset_v1_local_var) {
        return NULL;
    }
    firmware_asset_v1_local_var->domain = domain;
    firmware_asset_v1_local_var->url = url;
    firmware_asset_v1_local_var->payload = payload;
    firmware_asset_v1_local_var->size = size;
    firmware_asset_v1_local_var->md5sum = md5sum;
    firmware_asset_v1_local_var->sha1sum = sha1sum;
    firmware_asset_v1_local_var->sha256sum = sha256sum;
    firmware_asset_v1_local_var->uploaddate = uploaddate;
    firmware_asset_v1_local_var->created_at = created_at;
    firmware_asset_v1_local_var->updated_at = updated_at;

    firmware_asset_v1_local_var->_library_owned = 1;
    return firmware_asset_v1_local_var;
}

__attribute__((deprecated)) firmware_asset_v1_t *firmware_asset_v1_create(
    char *domain,
    char *url,
    char *payload,
    double size,
    char *md5sum,
    char *sha1sum,
    char *sha256sum,
    char *uploaddate,
    char *created_at,
    char *updated_at
    ) {
    return firmware_asset_v1_create_internal (
        domain,
        url,
        payload,
        size,
        md5sum,
        sha1sum,
        sha256sum,
        uploaddate,
        created_at,
        updated_at
        );
}

void firmware_asset_v1_free(firmware_asset_v1_t *firmware_asset_v1) {
    if(NULL == firmware_asset_v1){
        return ;
    }
    if(firmware_asset_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "firmware_asset_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (firmware_asset_v1->domain) {
        free(firmware_asset_v1->domain);
        firmware_asset_v1->domain = NULL;
    }
    if (firmware_asset_v1->url) {
        free(firmware_asset_v1->url);
        firmware_asset_v1->url = NULL;
    }
    if (firmware_asset_v1->payload) {
        free(firmware_asset_v1->payload);
        firmware_asset_v1->payload = NULL;
    }
    if (firmware_asset_v1->md5sum) {
        free(firmware_asset_v1->md5sum);
        firmware_asset_v1->md5sum = NULL;
    }
    if (firmware_asset_v1->sha1sum) {
        free(firmware_asset_v1->sha1sum);
        firmware_asset_v1->sha1sum = NULL;
    }
    if (firmware_asset_v1->sha256sum) {
        free(firmware_asset_v1->sha256sum);
        firmware_asset_v1->sha256sum = NULL;
    }
    if (firmware_asset_v1->uploaddate) {
        free(firmware_asset_v1->uploaddate);
        firmware_asset_v1->uploaddate = NULL;
    }
    if (firmware_asset_v1->created_at) {
        free(firmware_asset_v1->created_at);
        firmware_asset_v1->created_at = NULL;
    }
    if (firmware_asset_v1->updated_at) {
        free(firmware_asset_v1->updated_at);
        firmware_asset_v1->updated_at = NULL;
    }
    free(firmware_asset_v1);
}

cJSON *firmware_asset_v1_convertToJSON(firmware_asset_v1_t *firmware_asset_v1) {
    cJSON *item = cJSON_CreateObject();

    // firmware_asset_v1->domain
    if (!firmware_asset_v1->domain) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "domain", firmware_asset_v1->domain) == NULL) {
    goto fail; //String
    }


    // firmware_asset_v1->url
    if (!firmware_asset_v1->url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "url", firmware_asset_v1->url) == NULL) {
    goto fail; //String
    }


    // firmware_asset_v1->payload
    if (!firmware_asset_v1->payload) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "payload", firmware_asset_v1->payload) == NULL) {
    goto fail; //String
    }


    // firmware_asset_v1->size
    if (!firmware_asset_v1->size) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "size", firmware_asset_v1->size) == NULL) {
    goto fail; //Numeric
    }


    // firmware_asset_v1->md5sum
    if(firmware_asset_v1->md5sum) {
    if(cJSON_AddStringToObject(item, "md5sum", firmware_asset_v1->md5sum) == NULL) {
    goto fail; //String
    }
    }


    // firmware_asset_v1->sha1sum
    if(firmware_asset_v1->sha1sum) {
    if(cJSON_AddStringToObject(item, "sha1sum", firmware_asset_v1->sha1sum) == NULL) {
    goto fail; //String
    }
    }


    // firmware_asset_v1->sha256sum
    if(firmware_asset_v1->sha256sum) {
    if(cJSON_AddStringToObject(item, "sha256sum", firmware_asset_v1->sha256sum) == NULL) {
    goto fail; //String
    }
    }


    // firmware_asset_v1->uploaddate
    if(firmware_asset_v1->uploaddate) {
    if(cJSON_AddStringToObject(item, "uploaddate", firmware_asset_v1->uploaddate) == NULL) {
    goto fail; //String
    }
    }


    // firmware_asset_v1->created_at
    if(firmware_asset_v1->created_at) {
    if(cJSON_AddStringToObject(item, "createdAt", firmware_asset_v1->created_at) == NULL) {
    goto fail; //String
    }
    }


    // firmware_asset_v1->updated_at
    if(firmware_asset_v1->updated_at) {
    if(cJSON_AddStringToObject(item, "updatedAt", firmware_asset_v1->updated_at) == NULL) {
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

firmware_asset_v1_t *firmware_asset_v1_parseFromJSON(cJSON *firmware_asset_v1JSON){

    firmware_asset_v1_t *firmware_asset_v1_local_var = NULL;

    // firmware_asset_v1->domain
    cJSON *domain = cJSON_GetObjectItemCaseSensitive(firmware_asset_v1JSON, "domain");
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

    // firmware_asset_v1->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(firmware_asset_v1JSON, "url");
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

    // firmware_asset_v1->payload
    cJSON *payload = cJSON_GetObjectItemCaseSensitive(firmware_asset_v1JSON, "payload");
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

    // firmware_asset_v1->size
    cJSON *size = cJSON_GetObjectItemCaseSensitive(firmware_asset_v1JSON, "size");
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

    // firmware_asset_v1->md5sum
    cJSON *md5sum = cJSON_GetObjectItemCaseSensitive(firmware_asset_v1JSON, "md5sum");
    if (cJSON_IsNull(md5sum)) {
        md5sum = NULL;
    }
    if (md5sum) { 
    if(!cJSON_IsString(md5sum) && !cJSON_IsNull(md5sum))
    {
    goto end; //String
    }
    }

    // firmware_asset_v1->sha1sum
    cJSON *sha1sum = cJSON_GetObjectItemCaseSensitive(firmware_asset_v1JSON, "sha1sum");
    if (cJSON_IsNull(sha1sum)) {
        sha1sum = NULL;
    }
    if (sha1sum) { 
    if(!cJSON_IsString(sha1sum) && !cJSON_IsNull(sha1sum))
    {
    goto end; //String
    }
    }

    // firmware_asset_v1->sha256sum
    cJSON *sha256sum = cJSON_GetObjectItemCaseSensitive(firmware_asset_v1JSON, "sha256sum");
    if (cJSON_IsNull(sha256sum)) {
        sha256sum = NULL;
    }
    if (sha256sum) { 
    if(!cJSON_IsString(sha256sum) && !cJSON_IsNull(sha256sum))
    {
    goto end; //String
    }
    }

    // firmware_asset_v1->uploaddate
    cJSON *uploaddate = cJSON_GetObjectItemCaseSensitive(firmware_asset_v1JSON, "uploaddate");
    if (cJSON_IsNull(uploaddate)) {
        uploaddate = NULL;
    }
    if (uploaddate) { 
    if(!cJSON_IsString(uploaddate) && !cJSON_IsNull(uploaddate))
    {
    goto end; //String
    }
    }

    // firmware_asset_v1->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(firmware_asset_v1JSON, "createdAt");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (created_at) { 
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //String
    }
    }

    // firmware_asset_v1->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(firmware_asset_v1JSON, "updatedAt");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (updated_at) { 
    if(!cJSON_IsString(updated_at) && !cJSON_IsNull(updated_at))
    {
    goto end; //String
    }
    }


    firmware_asset_v1_local_var = firmware_asset_v1_create_internal (
        strdup(domain->valuestring),
        strdup(url->valuestring),
        strdup(payload->valuestring),
        size->valuedouble,
        md5sum && !cJSON_IsNull(md5sum) ? strdup(md5sum->valuestring) : NULL,
        sha1sum && !cJSON_IsNull(sha1sum) ? strdup(sha1sum->valuestring) : NULL,
        sha256sum && !cJSON_IsNull(sha256sum) ? strdup(sha256sum->valuestring) : NULL,
        uploaddate && !cJSON_IsNull(uploaddate) ? strdup(uploaddate->valuestring) : NULL,
        created_at && !cJSON_IsNull(created_at) ? strdup(created_at->valuestring) : NULL,
        updated_at && !cJSON_IsNull(updated_at) ? strdup(updated_at->valuestring) : NULL
        );

    return firmware_asset_v1_local_var;
end:
    return NULL;

}
