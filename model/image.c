#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "image.h"



static image_t *image_create_internal(
    char *status,
    char *id,
    char *name,
    corellium_api_image_type__e type,
    double size,
    char *checksum,
    char *corellium_checksum,
    corellium_api_image_encoding__e encoding,
    char *project,
    char *instance,
    char *created_at,
    char *updated_at
    ) {
    image_t *image_local_var = malloc(sizeof(image_t));
    if (!image_local_var) {
        return NULL;
    }
    image_local_var->status = status;
    image_local_var->id = id;
    image_local_var->name = name;
    image_local_var->type = type;
    image_local_var->size = size;
    image_local_var->checksum = checksum;
    image_local_var->corellium_checksum = corellium_checksum;
    image_local_var->encoding = encoding;
    image_local_var->project = project;
    image_local_var->instance = instance;
    image_local_var->created_at = created_at;
    image_local_var->updated_at = updated_at;

    image_local_var->_library_owned = 1;
    return image_local_var;
}

__attribute__((deprecated)) image_t *image_create(
    char *status,
    char *id,
    char *name,
    corellium_api_image_type__e type,
    double size,
    char *checksum,
    char *corellium_checksum,
    corellium_api_image_encoding__e encoding,
    char *project,
    char *instance,
    char *created_at,
    char *updated_at
    ) {
    return image_create_internal (
        status,
        id,
        name,
        type,
        size,
        checksum,
        corellium_checksum,
        encoding,
        project,
        instance,
        created_at,
        updated_at
        );
}

void image_free(image_t *image) {
    if(NULL == image){
        return ;
    }
    if(image->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "image_free");
        return ;
    }
    listEntry_t *listEntry;
    if (image->status) {
        free(image->status);
        image->status = NULL;
    }
    if (image->id) {
        free(image->id);
        image->id = NULL;
    }
    if (image->name) {
        free(image->name);
        image->name = NULL;
    }
    if (image->checksum) {
        free(image->checksum);
        image->checksum = NULL;
    }
    if (image->corellium_checksum) {
        free(image->corellium_checksum);
        image->corellium_checksum = NULL;
    }
    if (image->project) {
        free(image->project);
        image->project = NULL;
    }
    if (image->instance) {
        free(image->instance);
        image->instance = NULL;
    }
    if (image->created_at) {
        free(image->created_at);
        image->created_at = NULL;
    }
    if (image->updated_at) {
        free(image->updated_at);
        image->updated_at = NULL;
    }
    free(image);
}

cJSON *image_convertToJSON(image_t *image) {
    cJSON *item = cJSON_CreateObject();

    // image->status
    if (!image->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", image->status) == NULL) {
    goto fail; //String
    }


    // image->id
    if (!image->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", image->id) == NULL) {
    goto fail; //String
    }


    // image->name
    if (!image->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", image->name) == NULL) {
    goto fail; //String
    }


    // image->type
    if (corellium_api_image_type__NULL == image->type) {
        goto fail;
    }
    cJSON *type_local_JSON = image_type_convertToJSON(image->type);
    if(type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "type", type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // image->size
    if(image->size) {
    if(cJSON_AddNumberToObject(item, "size", image->size) == NULL) {
    goto fail; //Numeric
    }
    }


    // image->checksum
    if(image->checksum) {
    if(cJSON_AddStringToObject(item, "checksum", image->checksum) == NULL) {
    goto fail; //String
    }
    }


    // image->corellium_checksum
    if(image->corellium_checksum) {
    if(cJSON_AddStringToObject(item, "corelliumChecksum", image->corellium_checksum) == NULL) {
    goto fail; //String
    }
    }


    // image->encoding
    if(image->encoding != corellium_api_image_encoding__NULL) {
    cJSON *encoding_local_JSON = image_encoding_convertToJSON(image->encoding);
    if(encoding_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "encoding", encoding_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // image->project
    if(image->project) {
    if(cJSON_AddStringToObject(item, "project", image->project) == NULL) {
    goto fail; //String
    }
    }


    // image->instance
    if(image->instance) {
    if(cJSON_AddStringToObject(item, "instance", image->instance) == NULL) {
    goto fail; //String
    }
    }


    // image->created_at
    if(image->created_at) {
    if(cJSON_AddStringToObject(item, "createdAt", image->created_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // image->updated_at
    if(image->updated_at) {
    if(cJSON_AddStringToObject(item, "updatedAt", image->updated_at) == NULL) {
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

image_t *image_parseFromJSON(cJSON *imageJSON){

    image_t *image_local_var = NULL;

    // define the local variable for image->type
    corellium_api_image_type__e type_local_nonprim = 0;

    // define the local variable for image->encoding
    corellium_api_image_encoding__e encoding_local_nonprim = 0;

    // image->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(imageJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    if(!cJSON_IsString(status))
    {
    goto end; //String
    }

    // image->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(imageJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // image->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(imageJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // image->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(imageJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    
    type_local_nonprim = image_type_parseFromJSON(type); //custom

    // image->size
    cJSON *size = cJSON_GetObjectItemCaseSensitive(imageJSON, "size");
    if (cJSON_IsNull(size)) {
        size = NULL;
    }
    if (size) { 
    if(!cJSON_IsNumber(size))
    {
    goto end; //Numeric
    }
    }

    // image->checksum
    cJSON *checksum = cJSON_GetObjectItemCaseSensitive(imageJSON, "checksum");
    if (cJSON_IsNull(checksum)) {
        checksum = NULL;
    }
    if (checksum) { 
    if(!cJSON_IsString(checksum) && !cJSON_IsNull(checksum))
    {
    goto end; //String
    }
    }

    // image->corellium_checksum
    cJSON *corellium_checksum = cJSON_GetObjectItemCaseSensitive(imageJSON, "corelliumChecksum");
    if (cJSON_IsNull(corellium_checksum)) {
        corellium_checksum = NULL;
    }
    if (corellium_checksum) { 
    if(!cJSON_IsString(corellium_checksum) && !cJSON_IsNull(corellium_checksum))
    {
    goto end; //String
    }
    }

    // image->encoding
    cJSON *encoding = cJSON_GetObjectItemCaseSensitive(imageJSON, "encoding");
    if (cJSON_IsNull(encoding)) {
        encoding = NULL;
    }
    if (encoding) { 
    encoding_local_nonprim = image_encoding_parseFromJSON(encoding); //custom
    }

    // image->project
    cJSON *project = cJSON_GetObjectItemCaseSensitive(imageJSON, "project");
    if (cJSON_IsNull(project)) {
        project = NULL;
    }
    if (project) { 
    if(!cJSON_IsString(project) && !cJSON_IsNull(project))
    {
    goto end; //String
    }
    }

    // image->instance
    cJSON *instance = cJSON_GetObjectItemCaseSensitive(imageJSON, "instance");
    if (cJSON_IsNull(instance)) {
        instance = NULL;
    }
    if (instance) { 
    if(!cJSON_IsString(instance) && !cJSON_IsNull(instance))
    {
    goto end; //String
    }
    }

    // image->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(imageJSON, "createdAt");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (created_at) { 
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //DateTime
    }
    }

    // image->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(imageJSON, "updatedAt");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (updated_at) { 
    if(!cJSON_IsString(updated_at) && !cJSON_IsNull(updated_at))
    {
    goto end; //DateTime
    }
    }


    image_local_var = image_create_internal (
        strdup(status->valuestring),
        strdup(id->valuestring),
        strdup(name->valuestring),
        type_local_nonprim,
        size ? size->valuedouble : 0,
        checksum && !cJSON_IsNull(checksum) ? strdup(checksum->valuestring) : NULL,
        corellium_checksum && !cJSON_IsNull(corellium_checksum) ? strdup(corellium_checksum->valuestring) : NULL,
        encoding ? encoding_local_nonprim : 0,
        project && !cJSON_IsNull(project) ? strdup(project->valuestring) : NULL,
        instance && !cJSON_IsNull(instance) ? strdup(instance->valuestring) : NULL,
        created_at && !cJSON_IsNull(created_at) ? strdup(created_at->valuestring) : NULL,
        updated_at && !cJSON_IsNull(updated_at) ? strdup(updated_at->valuestring) : NULL
        );

    return image_local_var;
end:
    if (type_local_nonprim) {
        type_local_nonprim = 0;
    }
    if (encoding_local_nonprim) {
        encoding_local_nonprim = 0;
    }
    return NULL;

}
