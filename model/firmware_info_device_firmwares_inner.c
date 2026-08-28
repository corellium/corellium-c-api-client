#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "firmware_info_device_firmwares_inner.h"



static firmware_info_device_firmwares_inner_t *firmware_info_device_firmwares_inner_create_internal(
    char *filename,
    char *version,
    char *build_id,
    char *url,
    char *orig_url
    ) {
    firmware_info_device_firmwares_inner_t *firmware_info_device_firmwares_inner_local_var = malloc(sizeof(firmware_info_device_firmwares_inner_t));
    if (!firmware_info_device_firmwares_inner_local_var) {
        return NULL;
    }
    firmware_info_device_firmwares_inner_local_var->filename = filename;
    firmware_info_device_firmwares_inner_local_var->version = version;
    firmware_info_device_firmwares_inner_local_var->build_id = build_id;
    firmware_info_device_firmwares_inner_local_var->url = url;
    firmware_info_device_firmwares_inner_local_var->orig_url = orig_url;

    firmware_info_device_firmwares_inner_local_var->_library_owned = 1;
    return firmware_info_device_firmwares_inner_local_var;
}

__attribute__((deprecated)) firmware_info_device_firmwares_inner_t *firmware_info_device_firmwares_inner_create(
    char *filename,
    char *version,
    char *build_id,
    char *url,
    char *orig_url
    ) {
    return firmware_info_device_firmwares_inner_create_internal (
        filename,
        version,
        build_id,
        url,
        orig_url
        );
}

void firmware_info_device_firmwares_inner_free(firmware_info_device_firmwares_inner_t *firmware_info_device_firmwares_inner) {
    if(NULL == firmware_info_device_firmwares_inner){
        return ;
    }
    if(firmware_info_device_firmwares_inner->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "firmware_info_device_firmwares_inner_free");
        return ;
    }
    listEntry_t *listEntry;
    if (firmware_info_device_firmwares_inner->filename) {
        free(firmware_info_device_firmwares_inner->filename);
        firmware_info_device_firmwares_inner->filename = NULL;
    }
    if (firmware_info_device_firmwares_inner->version) {
        free(firmware_info_device_firmwares_inner->version);
        firmware_info_device_firmwares_inner->version = NULL;
    }
    if (firmware_info_device_firmwares_inner->build_id) {
        free(firmware_info_device_firmwares_inner->build_id);
        firmware_info_device_firmwares_inner->build_id = NULL;
    }
    if (firmware_info_device_firmwares_inner->url) {
        free(firmware_info_device_firmwares_inner->url);
        firmware_info_device_firmwares_inner->url = NULL;
    }
    if (firmware_info_device_firmwares_inner->orig_url) {
        free(firmware_info_device_firmwares_inner->orig_url);
        firmware_info_device_firmwares_inner->orig_url = NULL;
    }
    free(firmware_info_device_firmwares_inner);
}

cJSON *firmware_info_device_firmwares_inner_convertToJSON(firmware_info_device_firmwares_inner_t *firmware_info_device_firmwares_inner) {
    cJSON *item = cJSON_CreateObject();

    // firmware_info_device_firmwares_inner->filename
    if(firmware_info_device_firmwares_inner->filename) {
    if(cJSON_AddStringToObject(item, "filename", firmware_info_device_firmwares_inner->filename) == NULL) {
    goto fail; //String
    }
    }


    // firmware_info_device_firmwares_inner->version
    if(firmware_info_device_firmwares_inner->version) {
    if(cJSON_AddStringToObject(item, "version", firmware_info_device_firmwares_inner->version) == NULL) {
    goto fail; //String
    }
    }


    // firmware_info_device_firmwares_inner->build_id
    if(firmware_info_device_firmwares_inner->build_id) {
    if(cJSON_AddStringToObject(item, "buildId", firmware_info_device_firmwares_inner->build_id) == NULL) {
    goto fail; //String
    }
    }


    // firmware_info_device_firmwares_inner->url
    if(firmware_info_device_firmwares_inner->url) {
    if(cJSON_AddStringToObject(item, "url", firmware_info_device_firmwares_inner->url) == NULL) {
    goto fail; //String
    }
    }


    // firmware_info_device_firmwares_inner->orig_url
    if(firmware_info_device_firmwares_inner->orig_url) {
    if(cJSON_AddStringToObject(item, "origUrl", firmware_info_device_firmwares_inner->orig_url) == NULL) {
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

firmware_info_device_firmwares_inner_t *firmware_info_device_firmwares_inner_parseFromJSON(cJSON *firmware_info_device_firmwares_innerJSON){

    firmware_info_device_firmwares_inner_t *firmware_info_device_firmwares_inner_local_var = NULL;

    // firmware_info_device_firmwares_inner->filename
    cJSON *filename = cJSON_GetObjectItemCaseSensitive(firmware_info_device_firmwares_innerJSON, "filename");
    if (cJSON_IsNull(filename)) {
        filename = NULL;
    }
    if (filename) { 
    if(!cJSON_IsString(filename) && !cJSON_IsNull(filename))
    {
    goto end; //String
    }
    }

    // firmware_info_device_firmwares_inner->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(firmware_info_device_firmwares_innerJSON, "version");
    if (cJSON_IsNull(version)) {
        version = NULL;
    }
    if (version) { 
    if(!cJSON_IsString(version) && !cJSON_IsNull(version))
    {
    goto end; //String
    }
    }

    // firmware_info_device_firmwares_inner->build_id
    cJSON *build_id = cJSON_GetObjectItemCaseSensitive(firmware_info_device_firmwares_innerJSON, "buildId");
    if (cJSON_IsNull(build_id)) {
        build_id = NULL;
    }
    if (build_id) { 
    if(!cJSON_IsString(build_id) && !cJSON_IsNull(build_id))
    {
    goto end; //String
    }
    }

    // firmware_info_device_firmwares_inner->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(firmware_info_device_firmwares_innerJSON, "url");
    if (cJSON_IsNull(url)) {
        url = NULL;
    }
    if (url) { 
    if(!cJSON_IsString(url) && !cJSON_IsNull(url))
    {
    goto end; //String
    }
    }

    // firmware_info_device_firmwares_inner->orig_url
    cJSON *orig_url = cJSON_GetObjectItemCaseSensitive(firmware_info_device_firmwares_innerJSON, "origUrl");
    if (cJSON_IsNull(orig_url)) {
        orig_url = NULL;
    }
    if (orig_url) { 
    if(!cJSON_IsString(orig_url) && !cJSON_IsNull(orig_url))
    {
    goto end; //String
    }
    }


    firmware_info_device_firmwares_inner_local_var = firmware_info_device_firmwares_inner_create_internal (
        filename && !cJSON_IsNull(filename) ? strdup(filename->valuestring) : NULL,
        version && !cJSON_IsNull(version) ? strdup(version->valuestring) : NULL,
        build_id && !cJSON_IsNull(build_id) ? strdup(build_id->valuestring) : NULL,
        url && !cJSON_IsNull(url) ? strdup(url->valuestring) : NULL,
        orig_url && !cJSON_IsNull(orig_url) ? strdup(orig_url->valuestring) : NULL
        );

    return firmware_info_device_firmwares_inner_local_var;
end:
    return NULL;

}
