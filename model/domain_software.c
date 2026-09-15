#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "domain_software.h"



static domain_software_t *domain_software_create_internal(
    char *image_id,
    char *flavor,
    char *description,
    char *model,
    char *platform,
    int has_product_image,
    char *os_version,
    char *os_build,
    char *filename,
    double size,
    char *release_date,
    char *upload_date,
    char *download_url
    ) {
    domain_software_t *domain_software_local_var = malloc(sizeof(domain_software_t));
    if (!domain_software_local_var) {
        return NULL;
    }
    domain_software_local_var->image_id = image_id;
    domain_software_local_var->flavor = flavor;
    domain_software_local_var->description = description;
    domain_software_local_var->model = model;
    domain_software_local_var->platform = platform;
    domain_software_local_var->has_product_image = has_product_image;
    domain_software_local_var->os_version = os_version;
    domain_software_local_var->os_build = os_build;
    domain_software_local_var->filename = filename;
    domain_software_local_var->size = size;
    domain_software_local_var->release_date = release_date;
    domain_software_local_var->upload_date = upload_date;
    domain_software_local_var->download_url = download_url;

    domain_software_local_var->_library_owned = 1;
    return domain_software_local_var;
}

__attribute__((deprecated)) domain_software_t *domain_software_create(
    char *image_id,
    char *flavor,
    char *description,
    char *model,
    char *platform,
    int has_product_image,
    char *os_version,
    char *os_build,
    char *filename,
    double size,
    char *release_date,
    char *upload_date,
    char *download_url
    ) {
    return domain_software_create_internal (
        image_id,
        flavor,
        description,
        model,
        platform,
        has_product_image,
        os_version,
        os_build,
        filename,
        size,
        release_date,
        upload_date,
        download_url
        );
}

void domain_software_free(domain_software_t *domain_software) {
    if(NULL == domain_software){
        return ;
    }
    if(domain_software->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "domain_software_free");
        return ;
    }
    listEntry_t *listEntry;
    if (domain_software->image_id) {
        free(domain_software->image_id);
        domain_software->image_id = NULL;
    }
    if (domain_software->flavor) {
        free(domain_software->flavor);
        domain_software->flavor = NULL;
    }
    if (domain_software->description) {
        free(domain_software->description);
        domain_software->description = NULL;
    }
    if (domain_software->model) {
        free(domain_software->model);
        domain_software->model = NULL;
    }
    if (domain_software->platform) {
        free(domain_software->platform);
        domain_software->platform = NULL;
    }
    if (domain_software->os_version) {
        free(domain_software->os_version);
        domain_software->os_version = NULL;
    }
    if (domain_software->os_build) {
        free(domain_software->os_build);
        domain_software->os_build = NULL;
    }
    if (domain_software->filename) {
        free(domain_software->filename);
        domain_software->filename = NULL;
    }
    if (domain_software->release_date) {
        free(domain_software->release_date);
        domain_software->release_date = NULL;
    }
    if (domain_software->upload_date) {
        free(domain_software->upload_date);
        domain_software->upload_date = NULL;
    }
    if (domain_software->download_url) {
        free(domain_software->download_url);
        domain_software->download_url = NULL;
    }
    free(domain_software);
}

cJSON *domain_software_convertToJSON(domain_software_t *domain_software) {
    cJSON *item = cJSON_CreateObject();

    // domain_software->image_id
    if (!domain_software->image_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "imageId", domain_software->image_id) == NULL) {
    goto fail; //String
    }


    // domain_software->flavor
    if (!domain_software->flavor) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "flavor", domain_software->flavor) == NULL) {
    goto fail; //String
    }


    // domain_software->description
    if (!domain_software->description) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "description", domain_software->description) == NULL) {
    goto fail; //String
    }


    // domain_software->model
    if (!domain_software->model) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "model", domain_software->model) == NULL) {
    goto fail; //String
    }


    // domain_software->platform
    if(domain_software->platform) {
    if(cJSON_AddStringToObject(item, "platform", domain_software->platform) == NULL) {
    goto fail; //String
    }
    }


    // domain_software->has_product_image
    if (!domain_software->has_product_image) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "hasProductImage", domain_software->has_product_image) == NULL) {
    goto fail; //Bool
    }


    // domain_software->os_version
    if(domain_software->os_version) {
    if(cJSON_AddStringToObject(item, "osVersion", domain_software->os_version) == NULL) {
    goto fail; //String
    }
    }


    // domain_software->os_build
    if(domain_software->os_build) {
    if(cJSON_AddStringToObject(item, "osBuild", domain_software->os_build) == NULL) {
    goto fail; //String
    }
    }


    // domain_software->filename
    if (!domain_software->filename) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "filename", domain_software->filename) == NULL) {
    goto fail; //String
    }


    // domain_software->size
    if(domain_software->size) {
    if(cJSON_AddNumberToObject(item, "size", domain_software->size) == NULL) {
    goto fail; //Numeric
    }
    }


    // domain_software->release_date
    if(domain_software->release_date) {
    if(cJSON_AddStringToObject(item, "releaseDate", domain_software->release_date) == NULL) {
    goto fail; //Date-Time
    }
    }


    // domain_software->upload_date
    if (!domain_software->upload_date) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "uploadDate", domain_software->upload_date) == NULL) {
    goto fail; //Date-Time
    }


    // domain_software->download_url
    if(domain_software->download_url) {
    if(cJSON_AddStringToObject(item, "downloadUrl", domain_software->download_url) == NULL) {
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

domain_software_t *domain_software_parseFromJSON(cJSON *domain_softwareJSON){

    domain_software_t *domain_software_local_var = NULL;

    // domain_software->image_id
    cJSON *image_id = cJSON_GetObjectItemCaseSensitive(domain_softwareJSON, "imageId");
    if (cJSON_IsNull(image_id)) {
        image_id = NULL;
    }
    if (!image_id) {
        goto end;
    }

    
    if(!cJSON_IsString(image_id))
    {
    goto end; //String
    }

    // domain_software->flavor
    cJSON *flavor = cJSON_GetObjectItemCaseSensitive(domain_softwareJSON, "flavor");
    if (cJSON_IsNull(flavor)) {
        flavor = NULL;
    }
    if (!flavor) {
        goto end;
    }

    
    if(!cJSON_IsString(flavor))
    {
    goto end; //String
    }

    // domain_software->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(domain_softwareJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (!description) {
        goto end;
    }

    
    if(!cJSON_IsString(description))
    {
    goto end; //String
    }

    // domain_software->model
    cJSON *model = cJSON_GetObjectItemCaseSensitive(domain_softwareJSON, "model");
    if (cJSON_IsNull(model)) {
        model = NULL;
    }
    if (!model) {
        goto end;
    }

    
    if(!cJSON_IsString(model))
    {
    goto end; //String
    }

    // domain_software->platform
    cJSON *platform = cJSON_GetObjectItemCaseSensitive(domain_softwareJSON, "platform");
    if (cJSON_IsNull(platform)) {
        platform = NULL;
    }
    if (platform) { 
    if(!cJSON_IsString(platform) && !cJSON_IsNull(platform))
    {
    goto end; //String
    }
    }

    // domain_software->has_product_image
    cJSON *has_product_image = cJSON_GetObjectItemCaseSensitive(domain_softwareJSON, "hasProductImage");
    if (cJSON_IsNull(has_product_image)) {
        has_product_image = NULL;
    }
    if (!has_product_image) {
        goto end;
    }

    
    if(!cJSON_IsBool(has_product_image))
    {
    goto end; //Bool
    }

    // domain_software->os_version
    cJSON *os_version = cJSON_GetObjectItemCaseSensitive(domain_softwareJSON, "osVersion");
    if (cJSON_IsNull(os_version)) {
        os_version = NULL;
    }
    if (os_version) { 
    if(!cJSON_IsString(os_version) && !cJSON_IsNull(os_version))
    {
    goto end; //String
    }
    }

    // domain_software->os_build
    cJSON *os_build = cJSON_GetObjectItemCaseSensitive(domain_softwareJSON, "osBuild");
    if (cJSON_IsNull(os_build)) {
        os_build = NULL;
    }
    if (os_build) { 
    if(!cJSON_IsString(os_build) && !cJSON_IsNull(os_build))
    {
    goto end; //String
    }
    }

    // domain_software->filename
    cJSON *filename = cJSON_GetObjectItemCaseSensitive(domain_softwareJSON, "filename");
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

    // domain_software->size
    cJSON *size = cJSON_GetObjectItemCaseSensitive(domain_softwareJSON, "size");
    if (cJSON_IsNull(size)) {
        size = NULL;
    }
    if (size) { 
    if(!cJSON_IsNumber(size))
    {
    goto end; //Numeric
    }
    }

    // domain_software->release_date
    cJSON *release_date = cJSON_GetObjectItemCaseSensitive(domain_softwareJSON, "releaseDate");
    if (cJSON_IsNull(release_date)) {
        release_date = NULL;
    }
    if (release_date) { 
    if(!cJSON_IsString(release_date) && !cJSON_IsNull(release_date))
    {
    goto end; //DateTime
    }
    }

    // domain_software->upload_date
    cJSON *upload_date = cJSON_GetObjectItemCaseSensitive(domain_softwareJSON, "uploadDate");
    if (cJSON_IsNull(upload_date)) {
        upload_date = NULL;
    }
    if (!upload_date) {
        goto end;
    }

    
    if(!cJSON_IsString(upload_date) && !cJSON_IsNull(upload_date))
    {
    goto end; //DateTime
    }

    // domain_software->download_url
    cJSON *download_url = cJSON_GetObjectItemCaseSensitive(domain_softwareJSON, "downloadUrl");
    if (cJSON_IsNull(download_url)) {
        download_url = NULL;
    }
    if (download_url) { 
    if(!cJSON_IsString(download_url) && !cJSON_IsNull(download_url))
    {
    goto end; //String
    }
    }


    domain_software_local_var = domain_software_create_internal (
        strdup(image_id->valuestring),
        strdup(flavor->valuestring),
        strdup(description->valuestring),
        strdup(model->valuestring),
        platform && !cJSON_IsNull(platform) ? strdup(platform->valuestring) : NULL,
        has_product_image->valueint,
        os_version && !cJSON_IsNull(os_version) ? strdup(os_version->valuestring) : NULL,
        os_build && !cJSON_IsNull(os_build) ? strdup(os_build->valuestring) : NULL,
        strdup(filename->valuestring),
        size ? size->valuedouble : 0,
        release_date && !cJSON_IsNull(release_date) ? strdup(release_date->valuestring) : NULL,
        strdup(upload_date->valuestring),
        download_url && !cJSON_IsNull(download_url) ? strdup(download_url->valuestring) : NULL
        );

    return domain_software_local_var;
end:
    return NULL;

}
