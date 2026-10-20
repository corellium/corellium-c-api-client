#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "image_firmware.h"



static image_firmware_t *image_firmware_create_internal(
    char *filename,
    char *version,
    char *buildid,
    char *url,
    char *orig_url
    ) {
    image_firmware_t *image_firmware_local_var = malloc(sizeof(image_firmware_t));
    if (!image_firmware_local_var) {
        return NULL;
    }
    image_firmware_local_var->filename = filename;
    image_firmware_local_var->version = version;
    image_firmware_local_var->buildid = buildid;
    image_firmware_local_var->url = url;
    image_firmware_local_var->orig_url = orig_url;

    image_firmware_local_var->_library_owned = 1;
    return image_firmware_local_var;
}

__attribute__((deprecated)) image_firmware_t *image_firmware_create(
    char *filename,
    char *version,
    char *buildid,
    char *url,
    char *orig_url
    ) {
    return image_firmware_create_internal (
        filename,
        version,
        buildid,
        url,
        orig_url
        );
}

void image_firmware_free(image_firmware_t *image_firmware) {
    if(NULL == image_firmware){
        return ;
    }
    if(image_firmware->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "image_firmware_free");
        return ;
    }
    listEntry_t *listEntry;
    if (image_firmware->filename) {
        free(image_firmware->filename);
        image_firmware->filename = NULL;
    }
    if (image_firmware->version) {
        free(image_firmware->version);
        image_firmware->version = NULL;
    }
    if (image_firmware->buildid) {
        free(image_firmware->buildid);
        image_firmware->buildid = NULL;
    }
    if (image_firmware->url) {
        free(image_firmware->url);
        image_firmware->url = NULL;
    }
    if (image_firmware->orig_url) {
        free(image_firmware->orig_url);
        image_firmware->orig_url = NULL;
    }
    free(image_firmware);
}

cJSON *image_firmware_convertToJSON(image_firmware_t *image_firmware) {
    cJSON *item = cJSON_CreateObject();

    // image_firmware->filename
    if(image_firmware->filename) {
    if(cJSON_AddStringToObject(item, "filename", image_firmware->filename) == NULL) {
    goto fail; //String
    }
    }


    // image_firmware->version
    if(image_firmware->version) {
    if(cJSON_AddStringToObject(item, "version", image_firmware->version) == NULL) {
    goto fail; //String
    }
    }


    // image_firmware->buildid
    if(image_firmware->buildid) {
    if(cJSON_AddStringToObject(item, "buildid", image_firmware->buildid) == NULL) {
    goto fail; //String
    }
    }


    // image_firmware->url
    if(image_firmware->url) {
    if(cJSON_AddStringToObject(item, "url", image_firmware->url) == NULL) {
    goto fail; //String
    }
    }


    // image_firmware->orig_url
    if(image_firmware->orig_url) {
    if(cJSON_AddStringToObject(item, "orig_url", image_firmware->orig_url) == NULL) {
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

image_firmware_t *image_firmware_parseFromJSON(cJSON *image_firmwareJSON){

    image_firmware_t *image_firmware_local_var = NULL;

    // image_firmware->filename
    cJSON *filename = cJSON_GetObjectItemCaseSensitive(image_firmwareJSON, "filename");
    if (cJSON_IsNull(filename)) {
        filename = NULL;
    }
    if (filename) { 
    if(!cJSON_IsString(filename) && !cJSON_IsNull(filename))
    {
    goto end; //String
    }
    }

    // image_firmware->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(image_firmwareJSON, "version");
    if (cJSON_IsNull(version)) {
        version = NULL;
    }
    if (version) { 
    if(!cJSON_IsString(version) && !cJSON_IsNull(version))
    {
    goto end; //String
    }
    }

    // image_firmware->buildid
    cJSON *buildid = cJSON_GetObjectItemCaseSensitive(image_firmwareJSON, "buildid");
    if (cJSON_IsNull(buildid)) {
        buildid = NULL;
    }
    if (buildid) { 
    if(!cJSON_IsString(buildid) && !cJSON_IsNull(buildid))
    {
    goto end; //String
    }
    }

    // image_firmware->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(image_firmwareJSON, "url");
    if (cJSON_IsNull(url)) {
        url = NULL;
    }
    if (url) { 
    if(!cJSON_IsString(url) && !cJSON_IsNull(url))
    {
    goto end; //String
    }
    }

    // image_firmware->orig_url
    cJSON *orig_url = cJSON_GetObjectItemCaseSensitive(image_firmwareJSON, "orig_url");
    if (cJSON_IsNull(orig_url)) {
        orig_url = NULL;
    }
    if (orig_url) { 
    if(!cJSON_IsString(orig_url) && !cJSON_IsNull(orig_url))
    {
    goto end; //String
    }
    }


    image_firmware_local_var = image_firmware_create_internal (
        filename && !cJSON_IsNull(filename) ? strdup(filename->valuestring) : NULL,
        version && !cJSON_IsNull(version) ? strdup(version->valuestring) : NULL,
        buildid && !cJSON_IsNull(buildid) ? strdup(buildid->valuestring) : NULL,
        url && !cJSON_IsNull(url) ? strdup(url->valuestring) : NULL,
        orig_url && !cJSON_IsNull(orig_url) ? strdup(orig_url->valuestring) : NULL
        );

    return image_firmware_local_var;
end:
    return NULL;

}
