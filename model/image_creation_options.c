#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "image_creation_options.h"


char* image_creation_options_encoding_ToString(corellium_api_image_creation_options_ENCODING_e encoding) {
    char* encodingArray[] =  { "NULL", "plain", "encrypted" };
    return encodingArray[encoding];
}

corellium_api_image_creation_options_ENCODING_e image_creation_options_encoding_FromString(char* encoding){
    int stringToReturn = 0;
    char *encodingArray[] =  { "NULL", "plain", "encrypted" };
    size_t sizeofArray = sizeof(encodingArray) / sizeof(encodingArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(encoding, encodingArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static image_creation_options_t *image_creation_options_create_internal(
    char *type,
    corellium_api_image_creation_options_ENCODING_e encoding,
    int encapsulated,
    char *name,
    char *full_path,
    char *project,
    char *instance,
    binary_t* file
    ) {
    image_creation_options_t *image_creation_options_local_var = malloc(sizeof(image_creation_options_t));
    if (!image_creation_options_local_var) {
        return NULL;
    }
    image_creation_options_local_var->type = type;
    image_creation_options_local_var->encoding = encoding;
    image_creation_options_local_var->encapsulated = encapsulated;
    image_creation_options_local_var->name = name;
    image_creation_options_local_var->full_path = full_path;
    image_creation_options_local_var->project = project;
    image_creation_options_local_var->instance = instance;
    image_creation_options_local_var->file = file;

    image_creation_options_local_var->_library_owned = 1;
    return image_creation_options_local_var;
}

__attribute__((deprecated)) image_creation_options_t *image_creation_options_create(
    char *type,
    corellium_api_image_creation_options_ENCODING_e encoding,
    int encapsulated,
    char *name,
    char *full_path,
    char *project,
    char *instance,
    binary_t* file
    ) {
    return image_creation_options_create_internal (
        type,
        encoding,
        encapsulated,
        name,
        full_path,
        project,
        instance,
        file
        );
}

void image_creation_options_free(image_creation_options_t *image_creation_options) {
    if(NULL == image_creation_options){
        return ;
    }
    if(image_creation_options->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "image_creation_options_free");
        return ;
    }
    listEntry_t *listEntry;
    if (image_creation_options->type) {
        free(image_creation_options->type);
        image_creation_options->type = NULL;
    }
    if (image_creation_options->name) {
        free(image_creation_options->name);
        image_creation_options->name = NULL;
    }
    if (image_creation_options->full_path) {
        free(image_creation_options->full_path);
        image_creation_options->full_path = NULL;
    }
    if (image_creation_options->project) {
        free(image_creation_options->project);
        image_creation_options->project = NULL;
    }
    if (image_creation_options->instance) {
        free(image_creation_options->instance);
        image_creation_options->instance = NULL;
    }
    if (image_creation_options->file) {
        free(image_creation_options->file->data);
        image_creation_options->file = NULL;
    }
    free(image_creation_options);
}

cJSON *image_creation_options_convertToJSON(image_creation_options_t *image_creation_options) {
    cJSON *item = cJSON_CreateObject();

    // image_creation_options->type
    if (!image_creation_options->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", image_creation_options->type) == NULL) {
    goto fail; //String
    }


    // image_creation_options->encoding
    if (corellium_api_image_creation_options_ENCODING_NULL == image_creation_options->encoding) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "encoding", image_creation_options_encoding_ToString(image_creation_options->encoding)) == NULL)
    {
    goto fail; //Enum
    }


    // image_creation_options->encapsulated
    if(image_creation_options->encapsulated) {
    if(cJSON_AddBoolToObject(item, "encapsulated", image_creation_options->encapsulated) == NULL) {
    goto fail; //Bool
    }
    }


    // image_creation_options->name
    if(image_creation_options->name) {
    if(cJSON_AddStringToObject(item, "name", image_creation_options->name) == NULL) {
    goto fail; //String
    }
    }


    // image_creation_options->full_path
    if(image_creation_options->full_path) {
    if(cJSON_AddStringToObject(item, "fullPath", image_creation_options->full_path) == NULL) {
    goto fail; //String
    }
    }


    // image_creation_options->project
    if(image_creation_options->project) {
    if(cJSON_AddStringToObject(item, "project", image_creation_options->project) == NULL) {
    goto fail; //String
    }
    }


    // image_creation_options->instance
    if(image_creation_options->instance) {
    if(cJSON_AddStringToObject(item, "instance", image_creation_options->instance) == NULL) {
    goto fail; //String
    }
    }


    // image_creation_options->file
    if(image_creation_options->file) {
    char* encoded_str_file = base64encode(image_creation_options->file->data,image_creation_options->file->len);
    if(cJSON_AddStringToObject(item, "file", encoded_str_file) == NULL) {
    goto fail; //Binary
    }
    free (encoded_str_file);
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

image_creation_options_t *image_creation_options_parseFromJSON(cJSON *image_creation_optionsJSON){

    image_creation_options_t *image_creation_options_local_var = NULL;

    // image_creation_options->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(image_creation_optionsJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }

    // image_creation_options->encoding
    cJSON *encoding = cJSON_GetObjectItemCaseSensitive(image_creation_optionsJSON, "encoding");
    if (cJSON_IsNull(encoding)) {
        encoding = NULL;
    }
    if (!encoding) {
        goto end;
    }

    corellium_api_image_creation_options_ENCODING_e encodingVariable;
    
    if(!cJSON_IsString(encoding))
    {
    goto end; //Enum
    }
    encodingVariable = image_creation_options_encoding_FromString(encoding->valuestring);

    // image_creation_options->encapsulated
    cJSON *encapsulated = cJSON_GetObjectItemCaseSensitive(image_creation_optionsJSON, "encapsulated");
    if (cJSON_IsNull(encapsulated)) {
        encapsulated = NULL;
    }
    if (encapsulated) { 
    if(!cJSON_IsBool(encapsulated))
    {
    goto end; //Bool
    }
    }

    // image_creation_options->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(image_creation_optionsJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // image_creation_options->full_path
    cJSON *full_path = cJSON_GetObjectItemCaseSensitive(image_creation_optionsJSON, "fullPath");
    if (cJSON_IsNull(full_path)) {
        full_path = NULL;
    }
    if (full_path) { 
    if(!cJSON_IsString(full_path) && !cJSON_IsNull(full_path))
    {
    goto end; //String
    }
    }

    // image_creation_options->project
    cJSON *project = cJSON_GetObjectItemCaseSensitive(image_creation_optionsJSON, "project");
    if (cJSON_IsNull(project)) {
        project = NULL;
    }
    if (project) { 
    if(!cJSON_IsString(project) && !cJSON_IsNull(project))
    {
    goto end; //String
    }
    }

    // image_creation_options->instance
    cJSON *instance = cJSON_GetObjectItemCaseSensitive(image_creation_optionsJSON, "instance");
    if (cJSON_IsNull(instance)) {
        instance = NULL;
    }
    if (instance) { 
    if(!cJSON_IsString(instance) && !cJSON_IsNull(instance))
    {
    goto end; //String
    }
    }

    // image_creation_options->file
    cJSON *file = cJSON_GetObjectItemCaseSensitive(image_creation_optionsJSON, "file");
    if (cJSON_IsNull(file)) {
        file = NULL;
    }
    binary_t* decoded_str_file = malloc(sizeof(struct binary_t));
    if (file) { 
    if(!cJSON_IsString(file))
    {
    goto end; //Binary
    }
    decoded_str_file->data = base64decode(file->valuestring, strlen(file->valuestring), &decoded_str_file->len);
    if (!decoded_str_file->data) {
        goto end;
    }
    }


    image_creation_options_local_var = image_creation_options_create_internal (
        strdup(type->valuestring),
        encodingVariable,
        encapsulated ? encapsulated->valueint : 0,
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        full_path && !cJSON_IsNull(full_path) ? strdup(full_path->valuestring) : NULL,
        project && !cJSON_IsNull(project) ? strdup(project->valuestring) : NULL,
        instance && !cJSON_IsNull(instance) ? strdup(instance->valuestring) : NULL,
        file ? decoded_str_file : NULL
        );

    return image_creation_options_local_var;
end:
    return NULL;

}
