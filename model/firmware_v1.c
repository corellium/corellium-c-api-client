#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "firmware_v1.h"



static firmware_v1_t *firmware_v1_create_internal(
    char *version,
    char *buildid,
    char *android_flavor,
    char *api_version,
    char *sha256sum,
    char *sha1sum,
    char *md5sum,
    double size,
    char *unique_id,
    object_t *metadata,
    char *releasedate,
    char *uploaddate,
    char *url,
    char *orig_url,
    char *filename
    ) {
    firmware_v1_t *firmware_v1_local_var = malloc(sizeof(firmware_v1_t));
    if (!firmware_v1_local_var) {
        return NULL;
    }
    firmware_v1_local_var->version = version;
    firmware_v1_local_var->buildid = buildid;
    firmware_v1_local_var->android_flavor = android_flavor;
    firmware_v1_local_var->api_version = api_version;
    firmware_v1_local_var->sha256sum = sha256sum;
    firmware_v1_local_var->sha1sum = sha1sum;
    firmware_v1_local_var->md5sum = md5sum;
    firmware_v1_local_var->size = size;
    firmware_v1_local_var->unique_id = unique_id;
    firmware_v1_local_var->metadata = metadata;
    firmware_v1_local_var->releasedate = releasedate;
    firmware_v1_local_var->uploaddate = uploaddate;
    firmware_v1_local_var->url = url;
    firmware_v1_local_var->orig_url = orig_url;
    firmware_v1_local_var->filename = filename;

    firmware_v1_local_var->_library_owned = 1;
    return firmware_v1_local_var;
}

__attribute__((deprecated)) firmware_v1_t *firmware_v1_create(
    char *version,
    char *buildid,
    char *android_flavor,
    char *api_version,
    char *sha256sum,
    char *sha1sum,
    char *md5sum,
    double size,
    char *unique_id,
    object_t *metadata,
    char *releasedate,
    char *uploaddate,
    char *url,
    char *orig_url,
    char *filename
    ) {
    return firmware_v1_create_internal (
        version,
        buildid,
        android_flavor,
        api_version,
        sha256sum,
        sha1sum,
        md5sum,
        size,
        unique_id,
        metadata,
        releasedate,
        uploaddate,
        url,
        orig_url,
        filename
        );
}

void firmware_v1_free(firmware_v1_t *firmware_v1) {
    if(NULL == firmware_v1){
        return ;
    }
    if(firmware_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "firmware_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (firmware_v1->version) {
        free(firmware_v1->version);
        firmware_v1->version = NULL;
    }
    if (firmware_v1->buildid) {
        free(firmware_v1->buildid);
        firmware_v1->buildid = NULL;
    }
    if (firmware_v1->android_flavor) {
        free(firmware_v1->android_flavor);
        firmware_v1->android_flavor = NULL;
    }
    if (firmware_v1->api_version) {
        free(firmware_v1->api_version);
        firmware_v1->api_version = NULL;
    }
    if (firmware_v1->sha256sum) {
        free(firmware_v1->sha256sum);
        firmware_v1->sha256sum = NULL;
    }
    if (firmware_v1->sha1sum) {
        free(firmware_v1->sha1sum);
        firmware_v1->sha1sum = NULL;
    }
    if (firmware_v1->md5sum) {
        free(firmware_v1->md5sum);
        firmware_v1->md5sum = NULL;
    }
    if (firmware_v1->unique_id) {
        free(firmware_v1->unique_id);
        firmware_v1->unique_id = NULL;
    }
    if (firmware_v1->metadata) {
        object_free(firmware_v1->metadata);
        firmware_v1->metadata = NULL;
    }
    if (firmware_v1->releasedate) {
        free(firmware_v1->releasedate);
        firmware_v1->releasedate = NULL;
    }
    if (firmware_v1->uploaddate) {
        free(firmware_v1->uploaddate);
        firmware_v1->uploaddate = NULL;
    }
    if (firmware_v1->url) {
        free(firmware_v1->url);
        firmware_v1->url = NULL;
    }
    if (firmware_v1->orig_url) {
        free(firmware_v1->orig_url);
        firmware_v1->orig_url = NULL;
    }
    if (firmware_v1->filename) {
        free(firmware_v1->filename);
        firmware_v1->filename = NULL;
    }
    free(firmware_v1);
}

cJSON *firmware_v1_convertToJSON(firmware_v1_t *firmware_v1) {
    cJSON *item = cJSON_CreateObject();

    // firmware_v1->version
    if(firmware_v1->version) {
    if(cJSON_AddStringToObject(item, "version", firmware_v1->version) == NULL) {
    goto fail; //String
    }
    }


    // firmware_v1->buildid
    if(firmware_v1->buildid) {
    if(cJSON_AddStringToObject(item, "buildid", firmware_v1->buildid) == NULL) {
    goto fail; //String
    }
    }


    // firmware_v1->android_flavor
    if(firmware_v1->android_flavor) {
    if(cJSON_AddStringToObject(item, "AndroidFlavor", firmware_v1->android_flavor) == NULL) {
    goto fail; //String
    }
    }


    // firmware_v1->api_version
    if(firmware_v1->api_version) {
    if(cJSON_AddStringToObject(item, "APIVersion", firmware_v1->api_version) == NULL) {
    goto fail; //String
    }
    }


    // firmware_v1->sha256sum
    if(firmware_v1->sha256sum) {
    if(cJSON_AddStringToObject(item, "sha256sum", firmware_v1->sha256sum) == NULL) {
    goto fail; //String
    }
    }


    // firmware_v1->sha1sum
    if(firmware_v1->sha1sum) {
    if(cJSON_AddStringToObject(item, "sha1sum", firmware_v1->sha1sum) == NULL) {
    goto fail; //String
    }
    }


    // firmware_v1->md5sum
    if(firmware_v1->md5sum) {
    if(cJSON_AddStringToObject(item, "md5sum", firmware_v1->md5sum) == NULL) {
    goto fail; //String
    }
    }


    // firmware_v1->size
    if(firmware_v1->size) {
    if(cJSON_AddNumberToObject(item, "size", firmware_v1->size) == NULL) {
    goto fail; //Numeric
    }
    }


    // firmware_v1->unique_id
    if(firmware_v1->unique_id) {
    if(cJSON_AddStringToObject(item, "uniqueId", firmware_v1->unique_id) == NULL) {
    goto fail; //String
    }
    }


    // firmware_v1->metadata
    if(firmware_v1->metadata) {
    cJSON *metadata_object = object_convertToJSON(firmware_v1->metadata);
    if(metadata_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // firmware_v1->releasedate
    if(firmware_v1->releasedate) {
    if(cJSON_AddStringToObject(item, "releasedate", firmware_v1->releasedate) == NULL) {
    goto fail; //Date-Time
    }
    }


    // firmware_v1->uploaddate
    if(firmware_v1->uploaddate) {
    if(cJSON_AddStringToObject(item, "uploaddate", firmware_v1->uploaddate) == NULL) {
    goto fail; //Date-Time
    }
    }


    // firmware_v1->url
    if(firmware_v1->url) {
    if(cJSON_AddStringToObject(item, "url", firmware_v1->url) == NULL) {
    goto fail; //String
    }
    }


    // firmware_v1->orig_url
    if(firmware_v1->orig_url) {
    if(cJSON_AddStringToObject(item, "orig_url", firmware_v1->orig_url) == NULL) {
    goto fail; //String
    }
    }


    // firmware_v1->filename
    if(firmware_v1->filename) {
    if(cJSON_AddStringToObject(item, "filename", firmware_v1->filename) == NULL) {
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

firmware_v1_t *firmware_v1_parseFromJSON(cJSON *firmware_v1JSON){

    firmware_v1_t *firmware_v1_local_var = NULL;

    // firmware_v1->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(firmware_v1JSON, "version");
    if (cJSON_IsNull(version)) {
        version = NULL;
    }
    if (version) { 
    if(!cJSON_IsString(version) && !cJSON_IsNull(version))
    {
    goto end; //String
    }
    }

    // firmware_v1->buildid
    cJSON *buildid = cJSON_GetObjectItemCaseSensitive(firmware_v1JSON, "buildid");
    if (cJSON_IsNull(buildid)) {
        buildid = NULL;
    }
    if (buildid) { 
    if(!cJSON_IsString(buildid) && !cJSON_IsNull(buildid))
    {
    goto end; //String
    }
    }

    // firmware_v1->android_flavor
    cJSON *android_flavor = cJSON_GetObjectItemCaseSensitive(firmware_v1JSON, "AndroidFlavor");
    if (cJSON_IsNull(android_flavor)) {
        android_flavor = NULL;
    }
    if (android_flavor) { 
    if(!cJSON_IsString(android_flavor) && !cJSON_IsNull(android_flavor))
    {
    goto end; //String
    }
    }

    // firmware_v1->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(firmware_v1JSON, "APIVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // firmware_v1->sha256sum
    cJSON *sha256sum = cJSON_GetObjectItemCaseSensitive(firmware_v1JSON, "sha256sum");
    if (cJSON_IsNull(sha256sum)) {
        sha256sum = NULL;
    }
    if (sha256sum) { 
    if(!cJSON_IsString(sha256sum) && !cJSON_IsNull(sha256sum))
    {
    goto end; //String
    }
    }

    // firmware_v1->sha1sum
    cJSON *sha1sum = cJSON_GetObjectItemCaseSensitive(firmware_v1JSON, "sha1sum");
    if (cJSON_IsNull(sha1sum)) {
        sha1sum = NULL;
    }
    if (sha1sum) { 
    if(!cJSON_IsString(sha1sum) && !cJSON_IsNull(sha1sum))
    {
    goto end; //String
    }
    }

    // firmware_v1->md5sum
    cJSON *md5sum = cJSON_GetObjectItemCaseSensitive(firmware_v1JSON, "md5sum");
    if (cJSON_IsNull(md5sum)) {
        md5sum = NULL;
    }
    if (md5sum) { 
    if(!cJSON_IsString(md5sum) && !cJSON_IsNull(md5sum))
    {
    goto end; //String
    }
    }

    // firmware_v1->size
    cJSON *size = cJSON_GetObjectItemCaseSensitive(firmware_v1JSON, "size");
    if (cJSON_IsNull(size)) {
        size = NULL;
    }
    if (size) { 
    if(!cJSON_IsNumber(size))
    {
    goto end; //Numeric
    }
    }

    // firmware_v1->unique_id
    cJSON *unique_id = cJSON_GetObjectItemCaseSensitive(firmware_v1JSON, "uniqueId");
    if (cJSON_IsNull(unique_id)) {
        unique_id = NULL;
    }
    if (unique_id) { 
    if(!cJSON_IsString(unique_id) && !cJSON_IsNull(unique_id))
    {
    goto end; //String
    }
    }

    // firmware_v1->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(firmware_v1JSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    object_t *metadata_local_object = NULL;
    if (metadata) { 
    metadata_local_object = object_parseFromJSON(metadata); //object
    }

    // firmware_v1->releasedate
    cJSON *releasedate = cJSON_GetObjectItemCaseSensitive(firmware_v1JSON, "releasedate");
    if (cJSON_IsNull(releasedate)) {
        releasedate = NULL;
    }
    if (releasedate) { 
    if(!cJSON_IsString(releasedate) && !cJSON_IsNull(releasedate))
    {
    goto end; //DateTime
    }
    }

    // firmware_v1->uploaddate
    cJSON *uploaddate = cJSON_GetObjectItemCaseSensitive(firmware_v1JSON, "uploaddate");
    if (cJSON_IsNull(uploaddate)) {
        uploaddate = NULL;
    }
    if (uploaddate) { 
    if(!cJSON_IsString(uploaddate) && !cJSON_IsNull(uploaddate))
    {
    goto end; //DateTime
    }
    }

    // firmware_v1->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(firmware_v1JSON, "url");
    if (cJSON_IsNull(url)) {
        url = NULL;
    }
    if (url) { 
    if(!cJSON_IsString(url) && !cJSON_IsNull(url))
    {
    goto end; //String
    }
    }

    // firmware_v1->orig_url
    cJSON *orig_url = cJSON_GetObjectItemCaseSensitive(firmware_v1JSON, "orig_url");
    if (cJSON_IsNull(orig_url)) {
        orig_url = NULL;
    }
    if (orig_url) { 
    if(!cJSON_IsString(orig_url) && !cJSON_IsNull(orig_url))
    {
    goto end; //String
    }
    }

    // firmware_v1->filename
    cJSON *filename = cJSON_GetObjectItemCaseSensitive(firmware_v1JSON, "filename");
    if (cJSON_IsNull(filename)) {
        filename = NULL;
    }
    if (filename) { 
    if(!cJSON_IsString(filename) && !cJSON_IsNull(filename))
    {
    goto end; //String
    }
    }


    firmware_v1_local_var = firmware_v1_create_internal (
        version && !cJSON_IsNull(version) ? strdup(version->valuestring) : NULL,
        buildid && !cJSON_IsNull(buildid) ? strdup(buildid->valuestring) : NULL,
        android_flavor && !cJSON_IsNull(android_flavor) ? strdup(android_flavor->valuestring) : NULL,
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        sha256sum && !cJSON_IsNull(sha256sum) ? strdup(sha256sum->valuestring) : NULL,
        sha1sum && !cJSON_IsNull(sha1sum) ? strdup(sha1sum->valuestring) : NULL,
        md5sum && !cJSON_IsNull(md5sum) ? strdup(md5sum->valuestring) : NULL,
        size ? size->valuedouble : 0,
        unique_id && !cJSON_IsNull(unique_id) ? strdup(unique_id->valuestring) : NULL,
        metadata ? metadata_local_object : NULL,
        releasedate && !cJSON_IsNull(releasedate) ? strdup(releasedate->valuestring) : NULL,
        uploaddate && !cJSON_IsNull(uploaddate) ? strdup(uploaddate->valuestring) : NULL,
        url && !cJSON_IsNull(url) ? strdup(url->valuestring) : NULL,
        orig_url && !cJSON_IsNull(orig_url) ? strdup(orig_url->valuestring) : NULL,
        filename && !cJSON_IsNull(filename) ? strdup(filename->valuestring) : NULL
        );

    return firmware_v1_local_var;
end:
    return NULL;

}
