#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "model_firmware.h"



static model_firmware_t *model_firmware_create_internal(
    char *os_version,
    char *os_build,
    char *android_flavor,
    char *api_version,
    char *sha256sum,
    char *sha1sum,
    char *md5sum,
    double size,
    char *unique_id,
    object_t *metadata,
    char *release_date,
    char *upload_date,
    char *url,
    char *orig_url,
    char *filename,
    int rooted
    ) {
    model_firmware_t *model_firmware_local_var = malloc(sizeof(model_firmware_t));
    if (!model_firmware_local_var) {
        return NULL;
    }
    model_firmware_local_var->os_version = os_version;
    model_firmware_local_var->os_build = os_build;
    model_firmware_local_var->android_flavor = android_flavor;
    model_firmware_local_var->api_version = api_version;
    model_firmware_local_var->sha256sum = sha256sum;
    model_firmware_local_var->sha1sum = sha1sum;
    model_firmware_local_var->md5sum = md5sum;
    model_firmware_local_var->size = size;
    model_firmware_local_var->unique_id = unique_id;
    model_firmware_local_var->metadata = metadata;
    model_firmware_local_var->release_date = release_date;
    model_firmware_local_var->upload_date = upload_date;
    model_firmware_local_var->url = url;
    model_firmware_local_var->orig_url = orig_url;
    model_firmware_local_var->filename = filename;
    model_firmware_local_var->rooted = rooted;

    model_firmware_local_var->_library_owned = 1;
    return model_firmware_local_var;
}

__attribute__((deprecated)) model_firmware_t *model_firmware_create(
    char *os_version,
    char *os_build,
    char *android_flavor,
    char *api_version,
    char *sha256sum,
    char *sha1sum,
    char *md5sum,
    double size,
    char *unique_id,
    object_t *metadata,
    char *release_date,
    char *upload_date,
    char *url,
    char *orig_url,
    char *filename,
    int rooted
    ) {
    return model_firmware_create_internal (
        os_version,
        os_build,
        android_flavor,
        api_version,
        sha256sum,
        sha1sum,
        md5sum,
        size,
        unique_id,
        metadata,
        release_date,
        upload_date,
        url,
        orig_url,
        filename,
        rooted
        );
}

void model_firmware_free(model_firmware_t *model_firmware) {
    if(NULL == model_firmware){
        return ;
    }
    if(model_firmware->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "model_firmware_free");
        return ;
    }
    listEntry_t *listEntry;
    if (model_firmware->os_version) {
        free(model_firmware->os_version);
        model_firmware->os_version = NULL;
    }
    if (model_firmware->os_build) {
        free(model_firmware->os_build);
        model_firmware->os_build = NULL;
    }
    if (model_firmware->android_flavor) {
        free(model_firmware->android_flavor);
        model_firmware->android_flavor = NULL;
    }
    if (model_firmware->api_version) {
        free(model_firmware->api_version);
        model_firmware->api_version = NULL;
    }
    if (model_firmware->sha256sum) {
        free(model_firmware->sha256sum);
        model_firmware->sha256sum = NULL;
    }
    if (model_firmware->sha1sum) {
        free(model_firmware->sha1sum);
        model_firmware->sha1sum = NULL;
    }
    if (model_firmware->md5sum) {
        free(model_firmware->md5sum);
        model_firmware->md5sum = NULL;
    }
    if (model_firmware->unique_id) {
        free(model_firmware->unique_id);
        model_firmware->unique_id = NULL;
    }
    if (model_firmware->metadata) {
        object_free(model_firmware->metadata);
        model_firmware->metadata = NULL;
    }
    if (model_firmware->release_date) {
        free(model_firmware->release_date);
        model_firmware->release_date = NULL;
    }
    if (model_firmware->upload_date) {
        free(model_firmware->upload_date);
        model_firmware->upload_date = NULL;
    }
    if (model_firmware->url) {
        free(model_firmware->url);
        model_firmware->url = NULL;
    }
    if (model_firmware->orig_url) {
        free(model_firmware->orig_url);
        model_firmware->orig_url = NULL;
    }
    if (model_firmware->filename) {
        free(model_firmware->filename);
        model_firmware->filename = NULL;
    }
    free(model_firmware);
}

cJSON *model_firmware_convertToJSON(model_firmware_t *model_firmware) {
    cJSON *item = cJSON_CreateObject();

    // model_firmware->os_version
    if (!model_firmware->os_version) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "osVersion", model_firmware->os_version) == NULL) {
    goto fail; //String
    }


    // model_firmware->os_build
    if(model_firmware->os_build) {
    if(cJSON_AddStringToObject(item, "osBuild", model_firmware->os_build) == NULL) {
    goto fail; //String
    }
    }


    // model_firmware->android_flavor
    if(model_firmware->android_flavor) {
    if(cJSON_AddStringToObject(item, "androidFlavor", model_firmware->android_flavor) == NULL) {
    goto fail; //String
    }
    }


    // model_firmware->api_version
    if(model_firmware->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", model_firmware->api_version) == NULL) {
    goto fail; //String
    }
    }


    // model_firmware->sha256sum
    if(model_firmware->sha256sum) {
    if(cJSON_AddStringToObject(item, "sha256sum", model_firmware->sha256sum) == NULL) {
    goto fail; //String
    }
    }


    // model_firmware->sha1sum
    if(model_firmware->sha1sum) {
    if(cJSON_AddStringToObject(item, "sha1sum", model_firmware->sha1sum) == NULL) {
    goto fail; //String
    }
    }


    // model_firmware->md5sum
    if(model_firmware->md5sum) {
    if(cJSON_AddStringToObject(item, "md5sum", model_firmware->md5sum) == NULL) {
    goto fail; //String
    }
    }


    // model_firmware->size
    if(model_firmware->size) {
    if(cJSON_AddNumberToObject(item, "size", model_firmware->size) == NULL) {
    goto fail; //Numeric
    }
    }


    // model_firmware->unique_id
    if(model_firmware->unique_id) {
    if(cJSON_AddStringToObject(item, "uniqueId", model_firmware->unique_id) == NULL) {
    goto fail; //String
    }
    }


    // model_firmware->metadata
    if(model_firmware->metadata) {
    cJSON *metadata_object = object_convertToJSON(model_firmware->metadata);
    if(metadata_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // model_firmware->release_date
    if(model_firmware->release_date) {
    if(cJSON_AddStringToObject(item, "releaseDate", model_firmware->release_date) == NULL) {
    goto fail; //Date-Time
    }
    }


    // model_firmware->upload_date
    if(model_firmware->upload_date) {
    if(cJSON_AddStringToObject(item, "uploadDate", model_firmware->upload_date) == NULL) {
    goto fail; //String
    }
    }


    // model_firmware->url
    if(model_firmware->url) {
    if(cJSON_AddStringToObject(item, "url", model_firmware->url) == NULL) {
    goto fail; //String
    }
    }


    // model_firmware->orig_url
    if(model_firmware->orig_url) {
    if(cJSON_AddStringToObject(item, "origUrl", model_firmware->orig_url) == NULL) {
    goto fail; //String
    }
    }


    // model_firmware->filename
    if(model_firmware->filename) {
    if(cJSON_AddStringToObject(item, "filename", model_firmware->filename) == NULL) {
    goto fail; //String
    }
    }


    // model_firmware->rooted
    if(model_firmware->rooted) {
    if(cJSON_AddBoolToObject(item, "rooted", model_firmware->rooted) == NULL) {
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

model_firmware_t *model_firmware_parseFromJSON(cJSON *model_firmwareJSON){

    model_firmware_t *model_firmware_local_var = NULL;

    // model_firmware->os_version
    cJSON *os_version = cJSON_GetObjectItemCaseSensitive(model_firmwareJSON, "osVersion");
    if (cJSON_IsNull(os_version)) {
        os_version = NULL;
    }
    if (!os_version) {
        goto end;
    }

    
    if(!cJSON_IsString(os_version))
    {
    goto end; //String
    }

    // model_firmware->os_build
    cJSON *os_build = cJSON_GetObjectItemCaseSensitive(model_firmwareJSON, "osBuild");
    if (cJSON_IsNull(os_build)) {
        os_build = NULL;
    }
    if (os_build) { 
    if(!cJSON_IsString(os_build) && !cJSON_IsNull(os_build))
    {
    goto end; //String
    }
    }

    // model_firmware->android_flavor
    cJSON *android_flavor = cJSON_GetObjectItemCaseSensitive(model_firmwareJSON, "androidFlavor");
    if (cJSON_IsNull(android_flavor)) {
        android_flavor = NULL;
    }
    if (android_flavor) { 
    if(!cJSON_IsString(android_flavor) && !cJSON_IsNull(android_flavor))
    {
    goto end; //String
    }
    }

    // model_firmware->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(model_firmwareJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // model_firmware->sha256sum
    cJSON *sha256sum = cJSON_GetObjectItemCaseSensitive(model_firmwareJSON, "sha256sum");
    if (cJSON_IsNull(sha256sum)) {
        sha256sum = NULL;
    }
    if (sha256sum) { 
    if(!cJSON_IsString(sha256sum) && !cJSON_IsNull(sha256sum))
    {
    goto end; //String
    }
    }

    // model_firmware->sha1sum
    cJSON *sha1sum = cJSON_GetObjectItemCaseSensitive(model_firmwareJSON, "sha1sum");
    if (cJSON_IsNull(sha1sum)) {
        sha1sum = NULL;
    }
    if (sha1sum) { 
    if(!cJSON_IsString(sha1sum) && !cJSON_IsNull(sha1sum))
    {
    goto end; //String
    }
    }

    // model_firmware->md5sum
    cJSON *md5sum = cJSON_GetObjectItemCaseSensitive(model_firmwareJSON, "md5sum");
    if (cJSON_IsNull(md5sum)) {
        md5sum = NULL;
    }
    if (md5sum) { 
    if(!cJSON_IsString(md5sum) && !cJSON_IsNull(md5sum))
    {
    goto end; //String
    }
    }

    // model_firmware->size
    cJSON *size = cJSON_GetObjectItemCaseSensitive(model_firmwareJSON, "size");
    if (cJSON_IsNull(size)) {
        size = NULL;
    }
    if (size) { 
    if(!cJSON_IsNumber(size))
    {
    goto end; //Numeric
    }
    }

    // model_firmware->unique_id
    cJSON *unique_id = cJSON_GetObjectItemCaseSensitive(model_firmwareJSON, "uniqueId");
    if (cJSON_IsNull(unique_id)) {
        unique_id = NULL;
    }
    if (unique_id) { 
    if(!cJSON_IsString(unique_id) && !cJSON_IsNull(unique_id))
    {
    goto end; //String
    }
    }

    // model_firmware->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(model_firmwareJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    object_t *metadata_local_object = NULL;
    if (metadata) { 
    metadata_local_object = object_parseFromJSON(metadata); //object
    }

    // model_firmware->release_date
    cJSON *release_date = cJSON_GetObjectItemCaseSensitive(model_firmwareJSON, "releaseDate");
    if (cJSON_IsNull(release_date)) {
        release_date = NULL;
    }
    if (release_date) { 
    if(!cJSON_IsString(release_date) && !cJSON_IsNull(release_date))
    {
    goto end; //DateTime
    }
    }

    // model_firmware->upload_date
    cJSON *upload_date = cJSON_GetObjectItemCaseSensitive(model_firmwareJSON, "uploadDate");
    if (cJSON_IsNull(upload_date)) {
        upload_date = NULL;
    }
    if (upload_date) { 
    if(!cJSON_IsString(upload_date) && !cJSON_IsNull(upload_date))
    {
    goto end; //String
    }
    }

    // model_firmware->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(model_firmwareJSON, "url");
    if (cJSON_IsNull(url)) {
        url = NULL;
    }
    if (url) { 
    if(!cJSON_IsString(url) && !cJSON_IsNull(url))
    {
    goto end; //String
    }
    }

    // model_firmware->orig_url
    cJSON *orig_url = cJSON_GetObjectItemCaseSensitive(model_firmwareJSON, "origUrl");
    if (cJSON_IsNull(orig_url)) {
        orig_url = NULL;
    }
    if (orig_url) { 
    if(!cJSON_IsString(orig_url) && !cJSON_IsNull(orig_url))
    {
    goto end; //String
    }
    }

    // model_firmware->filename
    cJSON *filename = cJSON_GetObjectItemCaseSensitive(model_firmwareJSON, "filename");
    if (cJSON_IsNull(filename)) {
        filename = NULL;
    }
    if (filename) { 
    if(!cJSON_IsString(filename) && !cJSON_IsNull(filename))
    {
    goto end; //String
    }
    }

    // model_firmware->rooted
    cJSON *rooted = cJSON_GetObjectItemCaseSensitive(model_firmwareJSON, "rooted");
    if (cJSON_IsNull(rooted)) {
        rooted = NULL;
    }
    if (rooted) { 
    if(!cJSON_IsBool(rooted))
    {
    goto end; //Bool
    }
    }


    model_firmware_local_var = model_firmware_create_internal (
        strdup(os_version->valuestring),
        os_build && !cJSON_IsNull(os_build) ? strdup(os_build->valuestring) : NULL,
        android_flavor && !cJSON_IsNull(android_flavor) ? strdup(android_flavor->valuestring) : NULL,
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        sha256sum && !cJSON_IsNull(sha256sum) ? strdup(sha256sum->valuestring) : NULL,
        sha1sum && !cJSON_IsNull(sha1sum) ? strdup(sha1sum->valuestring) : NULL,
        md5sum && !cJSON_IsNull(md5sum) ? strdup(md5sum->valuestring) : NULL,
        size ? size->valuedouble : 0,
        unique_id && !cJSON_IsNull(unique_id) ? strdup(unique_id->valuestring) : NULL,
        metadata ? metadata_local_object : NULL,
        release_date && !cJSON_IsNull(release_date) ? strdup(release_date->valuestring) : NULL,
        upload_date && !cJSON_IsNull(upload_date) ? strdup(upload_date->valuestring) : NULL,
        url && !cJSON_IsNull(url) ? strdup(url->valuestring) : NULL,
        orig_url && !cJSON_IsNull(orig_url) ? strdup(orig_url->valuestring) : NULL,
        filename && !cJSON_IsNull(filename) ? strdup(filename->valuestring) : NULL,
        rooted ? rooted->valueint : 0
        );

    return model_firmware_local_var;
end:
    return NULL;

}
