#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "firmware.h"



static firmware_t *firmware_create_internal(
    list_t *model,
    list_t *firmware_assets,
    char *filename,
    char *type,
    double size,
    char *url,
    char *version,
    char *build_id,
    char *md5sum,
    char *sha1sum,
    char *sha256sum,
    char *release_date,
    char *upload_date,
    object_t *metadata,
    char *unique_id,
    int installed
    ) {
    firmware_t *firmware_local_var = malloc(sizeof(firmware_t));
    if (!firmware_local_var) {
        return NULL;
    }
    firmware_local_var->model = model;
    firmware_local_var->firmware_assets = firmware_assets;
    firmware_local_var->filename = filename;
    firmware_local_var->type = type;
    firmware_local_var->size = size;
    firmware_local_var->url = url;
    firmware_local_var->version = version;
    firmware_local_var->build_id = build_id;
    firmware_local_var->md5sum = md5sum;
    firmware_local_var->sha1sum = sha1sum;
    firmware_local_var->sha256sum = sha256sum;
    firmware_local_var->release_date = release_date;
    firmware_local_var->upload_date = upload_date;
    firmware_local_var->metadata = metadata;
    firmware_local_var->unique_id = unique_id;
    firmware_local_var->installed = installed;

    firmware_local_var->_library_owned = 1;
    return firmware_local_var;
}

__attribute__((deprecated)) firmware_t *firmware_create(
    list_t *model,
    list_t *firmware_assets,
    char *filename,
    char *type,
    double size,
    char *url,
    char *version,
    char *build_id,
    char *md5sum,
    char *sha1sum,
    char *sha256sum,
    char *release_date,
    char *upload_date,
    object_t *metadata,
    char *unique_id,
    int installed
    ) {
    return firmware_create_internal (
        model,
        firmware_assets,
        filename,
        type,
        size,
        url,
        version,
        build_id,
        md5sum,
        sha1sum,
        sha256sum,
        release_date,
        upload_date,
        metadata,
        unique_id,
        installed
        );
}

void firmware_free(firmware_t *firmware) {
    if(NULL == firmware){
        return ;
    }
    if(firmware->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "firmware_free");
        return ;
    }
    listEntry_t *listEntry;
    if (firmware->model) {
        list_ForEach(listEntry, firmware->model) {
            free(listEntry->data);
        }
        list_freeList(firmware->model);
        firmware->model = NULL;
    }
    if (firmware->firmware_assets) {
        list_ForEach(listEntry, firmware->firmware_assets) {
            free(listEntry->data);
        }
        list_freeList(firmware->firmware_assets);
        firmware->firmware_assets = NULL;
    }
    if (firmware->filename) {
        free(firmware->filename);
        firmware->filename = NULL;
    }
    if (firmware->type) {
        free(firmware->type);
        firmware->type = NULL;
    }
    if (firmware->url) {
        free(firmware->url);
        firmware->url = NULL;
    }
    if (firmware->version) {
        free(firmware->version);
        firmware->version = NULL;
    }
    if (firmware->build_id) {
        free(firmware->build_id);
        firmware->build_id = NULL;
    }
    if (firmware->md5sum) {
        free(firmware->md5sum);
        firmware->md5sum = NULL;
    }
    if (firmware->sha1sum) {
        free(firmware->sha1sum);
        firmware->sha1sum = NULL;
    }
    if (firmware->sha256sum) {
        free(firmware->sha256sum);
        firmware->sha256sum = NULL;
    }
    if (firmware->release_date) {
        free(firmware->release_date);
        firmware->release_date = NULL;
    }
    if (firmware->upload_date) {
        free(firmware->upload_date);
        firmware->upload_date = NULL;
    }
    if (firmware->metadata) {
        object_free(firmware->metadata);
        firmware->metadata = NULL;
    }
    if (firmware->unique_id) {
        free(firmware->unique_id);
        firmware->unique_id = NULL;
    }
    free(firmware);
}

cJSON *firmware_convertToJSON(firmware_t *firmware) {
    cJSON *item = cJSON_CreateObject();

    // firmware->model
    if (!firmware->model) {
        goto fail;
    }
    cJSON *model = cJSON_AddArrayToObject(item, "model");
    if(model == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *modelListEntry;
    list_ForEach(modelListEntry, firmware->model) {
    if(cJSON_AddStringToObject(model, "", modelListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // firmware->firmware_assets
    if(firmware->firmware_assets) {
    cJSON *firmware_assets = cJSON_AddArrayToObject(item, "firmwareAssets");
    if(firmware_assets == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *firmware_assetsListEntry;
    list_ForEach(firmware_assetsListEntry, firmware->firmware_assets) {
    if(cJSON_AddStringToObject(firmware_assets, "", firmware_assetsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // firmware->filename
    if (!firmware->filename) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "filename", firmware->filename) == NULL) {
    goto fail; //String
    }


    // firmware->type
    if(firmware->type) {
    if(cJSON_AddStringToObject(item, "type", firmware->type) == NULL) {
    goto fail; //String
    }
    }


    // firmware->size
    if (!firmware->size) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "size", firmware->size) == NULL) {
    goto fail; //Numeric
    }


    // firmware->url
    if (!firmware->url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "url", firmware->url) == NULL) {
    goto fail; //String
    }


    // firmware->version
    if (!firmware->version) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "version", firmware->version) == NULL) {
    goto fail; //String
    }


    // firmware->build_id
    if (!firmware->build_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "buildId", firmware->build_id) == NULL) {
    goto fail; //String
    }


    // firmware->md5sum
    if(firmware->md5sum) {
    if(cJSON_AddStringToObject(item, "md5sum", firmware->md5sum) == NULL) {
    goto fail; //String
    }
    }


    // firmware->sha1sum
    if(firmware->sha1sum) {
    if(cJSON_AddStringToObject(item, "sha1sum", firmware->sha1sum) == NULL) {
    goto fail; //String
    }
    }


    // firmware->sha256sum
    if(firmware->sha256sum) {
    if(cJSON_AddStringToObject(item, "sha256sum", firmware->sha256sum) == NULL) {
    goto fail; //String
    }
    }


    // firmware->release_date
    if(firmware->release_date) {
    if(cJSON_AddStringToObject(item, "releaseDate", firmware->release_date) == NULL) {
    goto fail; //Date-Time
    }
    }


    // firmware->upload_date
    if(firmware->upload_date) {
    if(cJSON_AddStringToObject(item, "uploadDate", firmware->upload_date) == NULL) {
    goto fail; //Date-Time
    }
    }


    // firmware->metadata
    if(firmware->metadata) {
    cJSON *metadata_object = object_convertToJSON(firmware->metadata);
    if(metadata_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // firmware->unique_id
    if(firmware->unique_id) {
    if(cJSON_AddStringToObject(item, "uniqueId", firmware->unique_id) == NULL) {
    goto fail; //String
    }
    }


    // firmware->installed
    if (!firmware->installed) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "installed", firmware->installed) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

firmware_t *firmware_parseFromJSON(cJSON *firmwareJSON){

    firmware_t *firmware_local_var = NULL;

    // define the local list for firmware->model
    list_t *modelList = NULL;

    // define the local list for firmware->firmware_assets
    list_t *firmware_assetsList = NULL;

    // firmware->model
    cJSON *model = cJSON_GetObjectItemCaseSensitive(firmwareJSON, "model");
    if (cJSON_IsNull(model)) {
        model = NULL;
    }
    if (!model) {
        goto end;
    }

    
    cJSON *model_local = NULL;
    if(!cJSON_IsArray(model)) {
        goto end;//primitive container
    }
    modelList = list_createList();

    cJSON_ArrayForEach(model_local, model)
    {
        if(!cJSON_IsString(model_local))
        {
            goto end;
        }
        list_addElement(modelList , strdup(model_local->valuestring));
    }

    // firmware->firmware_assets
    cJSON *firmware_assets = cJSON_GetObjectItemCaseSensitive(firmwareJSON, "firmwareAssets");
    if (cJSON_IsNull(firmware_assets)) {
        firmware_assets = NULL;
    }
    if (firmware_assets) { 
    cJSON *firmware_assets_local = NULL;
    if(!cJSON_IsArray(firmware_assets)) {
        goto end;//primitive container
    }
    firmware_assetsList = list_createList();

    cJSON_ArrayForEach(firmware_assets_local, firmware_assets)
    {
        if(!cJSON_IsString(firmware_assets_local))
        {
            goto end;
        }
        list_addElement(firmware_assetsList , strdup(firmware_assets_local->valuestring));
    }
    }

    // firmware->filename
    cJSON *filename = cJSON_GetObjectItemCaseSensitive(firmwareJSON, "filename");
    if (cJSON_IsNull(filename)) {
        filename = NULL;
    }
    if (!filename) {
        goto end;
    }

    
    if(!cJSON_IsString(filename))
    {
    goto end; //String
    }

    // firmware->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(firmwareJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (type) { 
    if(!cJSON_IsString(type) && !cJSON_IsNull(type))
    {
    goto end; //String
    }
    }

    // firmware->size
    cJSON *size = cJSON_GetObjectItemCaseSensitive(firmwareJSON, "size");
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

    // firmware->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(firmwareJSON, "url");
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

    // firmware->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(firmwareJSON, "version");
    if (cJSON_IsNull(version)) {
        version = NULL;
    }
    if (!version) {
        goto end;
    }

    
    if(!cJSON_IsString(version))
    {
    goto end; //String
    }

    // firmware->build_id
    cJSON *build_id = cJSON_GetObjectItemCaseSensitive(firmwareJSON, "buildId");
    if (cJSON_IsNull(build_id)) {
        build_id = NULL;
    }
    if (!build_id) {
        goto end;
    }

    
    if(!cJSON_IsString(build_id))
    {
    goto end; //String
    }

    // firmware->md5sum
    cJSON *md5sum = cJSON_GetObjectItemCaseSensitive(firmwareJSON, "md5sum");
    if (cJSON_IsNull(md5sum)) {
        md5sum = NULL;
    }
    if (md5sum) { 
    if(!cJSON_IsString(md5sum) && !cJSON_IsNull(md5sum))
    {
    goto end; //String
    }
    }

    // firmware->sha1sum
    cJSON *sha1sum = cJSON_GetObjectItemCaseSensitive(firmwareJSON, "sha1sum");
    if (cJSON_IsNull(sha1sum)) {
        sha1sum = NULL;
    }
    if (sha1sum) { 
    if(!cJSON_IsString(sha1sum) && !cJSON_IsNull(sha1sum))
    {
    goto end; //String
    }
    }

    // firmware->sha256sum
    cJSON *sha256sum = cJSON_GetObjectItemCaseSensitive(firmwareJSON, "sha256sum");
    if (cJSON_IsNull(sha256sum)) {
        sha256sum = NULL;
    }
    if (sha256sum) { 
    if(!cJSON_IsString(sha256sum) && !cJSON_IsNull(sha256sum))
    {
    goto end; //String
    }
    }

    // firmware->release_date
    cJSON *release_date = cJSON_GetObjectItemCaseSensitive(firmwareJSON, "releaseDate");
    if (cJSON_IsNull(release_date)) {
        release_date = NULL;
    }
    if (release_date) { 
    if(!cJSON_IsString(release_date) && !cJSON_IsNull(release_date))
    {
    goto end; //DateTime
    }
    }

    // firmware->upload_date
    cJSON *upload_date = cJSON_GetObjectItemCaseSensitive(firmwareJSON, "uploadDate");
    if (cJSON_IsNull(upload_date)) {
        upload_date = NULL;
    }
    if (upload_date) { 
    if(!cJSON_IsString(upload_date) && !cJSON_IsNull(upload_date))
    {
    goto end; //DateTime
    }
    }

    // firmware->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(firmwareJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    object_t *metadata_local_object = NULL;
    if (metadata) { 
    metadata_local_object = object_parseFromJSON(metadata); //object
    }

    // firmware->unique_id
    cJSON *unique_id = cJSON_GetObjectItemCaseSensitive(firmwareJSON, "uniqueId");
    if (cJSON_IsNull(unique_id)) {
        unique_id = NULL;
    }
    if (unique_id) { 
    if(!cJSON_IsString(unique_id) && !cJSON_IsNull(unique_id))
    {
    goto end; //String
    }
    }

    // firmware->installed
    cJSON *installed = cJSON_GetObjectItemCaseSensitive(firmwareJSON, "installed");
    if (cJSON_IsNull(installed)) {
        installed = NULL;
    }
    if (!installed) {
        goto end;
    }

    
    if(!cJSON_IsBool(installed))
    {
    goto end; //Bool
    }


    firmware_local_var = firmware_create_internal (
        modelList,
        firmware_assets ? firmware_assetsList : NULL,
        strdup(filename->valuestring),
        type && !cJSON_IsNull(type) ? strdup(type->valuestring) : NULL,
        size->valuedouble,
        strdup(url->valuestring),
        strdup(version->valuestring),
        strdup(build_id->valuestring),
        md5sum && !cJSON_IsNull(md5sum) ? strdup(md5sum->valuestring) : NULL,
        sha1sum && !cJSON_IsNull(sha1sum) ? strdup(sha1sum->valuestring) : NULL,
        sha256sum && !cJSON_IsNull(sha256sum) ? strdup(sha256sum->valuestring) : NULL,
        release_date && !cJSON_IsNull(release_date) ? strdup(release_date->valuestring) : NULL,
        upload_date && !cJSON_IsNull(upload_date) ? strdup(upload_date->valuestring) : NULL,
        metadata ? metadata_local_object : NULL,
        unique_id && !cJSON_IsNull(unique_id) ? strdup(unique_id->valuestring) : NULL,
        installed->valueint
        );

    return firmware_local_var;
end:
    if (modelList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, modelList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(modelList);
        modelList = NULL;
    }
    if (firmware_assetsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, firmware_assetsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(firmware_assetsList);
        firmware_assetsList = NULL;
    }
    return NULL;

}
