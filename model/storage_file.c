#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "storage_file.h"


char* storage_file_type_ToString(corellium_api_storage_file_TYPE_e type) {
    char* typeArray[] =  { "NULL", "file", "directory" };
    return typeArray[type];
}

corellium_api_storage_file_TYPE_e storage_file_type_FromString(char* type){
    int stringToReturn = 0;
    char *typeArray[] =  { "NULL", "file", "directory" };
    size_t sizeofArray = sizeof(typeArray) / sizeof(typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(type, typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static storage_file_t *storage_file_create_internal(
    char *name,
    char *ext,
    corellium_api_storage_file_TYPE_e type,
    double size,
    char *last_modified_time
    ) {
    storage_file_t *storage_file_local_var = malloc(sizeof(storage_file_t));
    if (!storage_file_local_var) {
        return NULL;
    }
    storage_file_local_var->name = name;
    storage_file_local_var->ext = ext;
    storage_file_local_var->type = type;
    storage_file_local_var->size = size;
    storage_file_local_var->last_modified_time = last_modified_time;

    storage_file_local_var->_library_owned = 1;
    return storage_file_local_var;
}

__attribute__((deprecated)) storage_file_t *storage_file_create(
    char *name,
    char *ext,
    corellium_api_storage_file_TYPE_e type,
    double size,
    char *last_modified_time
    ) {
    return storage_file_create_internal (
        name,
        ext,
        type,
        size,
        last_modified_time
        );
}

void storage_file_free(storage_file_t *storage_file) {
    if(NULL == storage_file){
        return ;
    }
    if(storage_file->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "storage_file_free");
        return ;
    }
    listEntry_t *listEntry;
    if (storage_file->name) {
        free(storage_file->name);
        storage_file->name = NULL;
    }
    if (storage_file->ext) {
        free(storage_file->ext);
        storage_file->ext = NULL;
    }
    if (storage_file->last_modified_time) {
        free(storage_file->last_modified_time);
        storage_file->last_modified_time = NULL;
    }
    free(storage_file);
}

cJSON *storage_file_convertToJSON(storage_file_t *storage_file) {
    cJSON *item = cJSON_CreateObject();

    // storage_file->name
    if (!storage_file->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", storage_file->name) == NULL) {
    goto fail; //String
    }


    // storage_file->ext
    if(storage_file->ext) {
    if(cJSON_AddStringToObject(item, "ext", storage_file->ext) == NULL) {
    goto fail; //String
    }
    }


    // storage_file->type
    if (corellium_api_storage_file_TYPE_NULL == storage_file->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", storage_file_type_ToString(storage_file->type)) == NULL)
    {
    goto fail; //Enum
    }


    // storage_file->size
    if (!storage_file->size) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "size", storage_file->size) == NULL) {
    goto fail; //Numeric
    }


    // storage_file->last_modified_time
    if(storage_file->last_modified_time) {
    if(cJSON_AddStringToObject(item, "lastModifiedTime", storage_file->last_modified_time) == NULL) {
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

storage_file_t *storage_file_parseFromJSON(cJSON *storage_fileJSON){

    storage_file_t *storage_file_local_var = NULL;

    // storage_file->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(storage_fileJSON, "name");
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

    // storage_file->ext
    cJSON *ext = cJSON_GetObjectItemCaseSensitive(storage_fileJSON, "ext");
    if (cJSON_IsNull(ext)) {
        ext = NULL;
    }
    if (ext) { 
    if(!cJSON_IsString(ext) && !cJSON_IsNull(ext))
    {
    goto end; //String
    }
    }

    // storage_file->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(storage_fileJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    corellium_api_storage_file_TYPE_e typeVariable;
    
    if(!cJSON_IsString(type))
    {
    goto end; //Enum
    }
    typeVariable = storage_file_type_FromString(type->valuestring);

    // storage_file->size
    cJSON *size = cJSON_GetObjectItemCaseSensitive(storage_fileJSON, "size");
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

    // storage_file->last_modified_time
    cJSON *last_modified_time = cJSON_GetObjectItemCaseSensitive(storage_fileJSON, "lastModifiedTime");
    if (cJSON_IsNull(last_modified_time)) {
        last_modified_time = NULL;
    }
    if (last_modified_time) { 
    if(!cJSON_IsString(last_modified_time) && !cJSON_IsNull(last_modified_time))
    {
    goto end; //DateTime
    }
    }


    storage_file_local_var = storage_file_create_internal (
        strdup(name->valuestring),
        ext && !cJSON_IsNull(ext) ? strdup(ext->valuestring) : NULL,
        typeVariable,
        size->valuedouble,
        last_modified_time && !cJSON_IsNull(last_modified_time) ? strdup(last_modified_time->valuestring) : NULL
        );

    return storage_file_local_var;
end:
    return NULL;

}
