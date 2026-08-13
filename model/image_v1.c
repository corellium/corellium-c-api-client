#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "image_v1.h"


char* image_v1_type_ToString(corellium_api_image_v1_TYPE_e type) {
    char* typeArray[] =  { "NULL", "fwbinary", "kernel", "devicetree", "ramdisk", "loaderfile", "sepfw", "seprom", "bootrom", "llb", "iboot", "ibootdata", "fwpackage", "partition", "backup", "ufd" };
    return typeArray[type];
}

corellium_api_image_v1_TYPE_e image_v1_type_FromString(char* type){
    int stringToReturn = 0;
    char *typeArray[] =  { "NULL", "fwbinary", "kernel", "devicetree", "ramdisk", "loaderfile", "sepfw", "seprom", "bootrom", "llb", "iboot", "ibootdata", "fwpackage", "partition", "backup", "ufd" };
    size_t sizeofArray = sizeof(typeArray) / sizeof(typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(type, typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static image_v1_t *image_v1_create_internal(
    char *status,
    char *id,
    char *identifier,
    char *name,
    corellium_api_image_v1_TYPE_e type,
    double size,
    char *checksum,
    char *corellium_checksum,
    char *encoding,
    char *filename,
    char *uniqueid,
    char *project,
    char *instance,
    char *created_at,
    char *updated_at,
    image_extended_t *extended
    ) {
    image_v1_t *image_v1_local_var = malloc(sizeof(image_v1_t));
    if (!image_v1_local_var) {
        return NULL;
    }
    image_v1_local_var->status = status;
    image_v1_local_var->id = id;
    image_v1_local_var->identifier = identifier;
    image_v1_local_var->name = name;
    image_v1_local_var->type = type;
    image_v1_local_var->size = size;
    image_v1_local_var->checksum = checksum;
    image_v1_local_var->corellium_checksum = corellium_checksum;
    image_v1_local_var->encoding = encoding;
    image_v1_local_var->filename = filename;
    image_v1_local_var->uniqueid = uniqueid;
    image_v1_local_var->project = project;
    image_v1_local_var->instance = instance;
    image_v1_local_var->created_at = created_at;
    image_v1_local_var->updated_at = updated_at;
    image_v1_local_var->extended = extended;

    image_v1_local_var->_library_owned = 1;
    return image_v1_local_var;
}

__attribute__((deprecated)) image_v1_t *image_v1_create(
    char *status,
    char *id,
    char *identifier,
    char *name,
    corellium_api_image_v1_TYPE_e type,
    double size,
    char *checksum,
    char *corellium_checksum,
    char *encoding,
    char *filename,
    char *uniqueid,
    char *project,
    char *instance,
    char *created_at,
    char *updated_at,
    image_extended_t *extended
    ) {
    return image_v1_create_internal (
        status,
        id,
        identifier,
        name,
        type,
        size,
        checksum,
        corellium_checksum,
        encoding,
        filename,
        uniqueid,
        project,
        instance,
        created_at,
        updated_at,
        extended
        );
}

void image_v1_free(image_v1_t *image_v1) {
    if(NULL == image_v1){
        return ;
    }
    if(image_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "image_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (image_v1->status) {
        free(image_v1->status);
        image_v1->status = NULL;
    }
    if (image_v1->id) {
        free(image_v1->id);
        image_v1->id = NULL;
    }
    if (image_v1->identifier) {
        free(image_v1->identifier);
        image_v1->identifier = NULL;
    }
    if (image_v1->name) {
        free(image_v1->name);
        image_v1->name = NULL;
    }
    if (image_v1->checksum) {
        free(image_v1->checksum);
        image_v1->checksum = NULL;
    }
    if (image_v1->corellium_checksum) {
        free(image_v1->corellium_checksum);
        image_v1->corellium_checksum = NULL;
    }
    if (image_v1->encoding) {
        free(image_v1->encoding);
        image_v1->encoding = NULL;
    }
    if (image_v1->filename) {
        free(image_v1->filename);
        image_v1->filename = NULL;
    }
    if (image_v1->uniqueid) {
        free(image_v1->uniqueid);
        image_v1->uniqueid = NULL;
    }
    if (image_v1->project) {
        free(image_v1->project);
        image_v1->project = NULL;
    }
    if (image_v1->instance) {
        free(image_v1->instance);
        image_v1->instance = NULL;
    }
    if (image_v1->created_at) {
        free(image_v1->created_at);
        image_v1->created_at = NULL;
    }
    if (image_v1->updated_at) {
        free(image_v1->updated_at);
        image_v1->updated_at = NULL;
    }
    if (image_v1->extended) {
        image_extended_free(image_v1->extended);
        image_v1->extended = NULL;
    }
    free(image_v1);
}

cJSON *image_v1_convertToJSON(image_v1_t *image_v1) {
    cJSON *item = cJSON_CreateObject();

    // image_v1->status
    if(image_v1->status) {
    if(cJSON_AddStringToObject(item, "status", image_v1->status) == NULL) {
    goto fail; //String
    }
    }


    // image_v1->id
    if(image_v1->id) {
    if(cJSON_AddStringToObject(item, "id", image_v1->id) == NULL) {
    goto fail; //String
    }
    }


    // image_v1->identifier
    if(image_v1->identifier) {
    if(cJSON_AddStringToObject(item, "identifier", image_v1->identifier) == NULL) {
    goto fail; //String
    }
    }


    // image_v1->name
    if(image_v1->name) {
    if(cJSON_AddStringToObject(item, "name", image_v1->name) == NULL) {
    goto fail; //String
    }
    }


    // image_v1->type
    if(image_v1->type != corellium_api_image_v1_TYPE_NULL) {
    if(cJSON_AddStringToObject(item, "type", image_v1_type_ToString(image_v1->type)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // image_v1->size
    if(image_v1->size) {
    if(cJSON_AddNumberToObject(item, "size", image_v1->size) == NULL) {
    goto fail; //Numeric
    }
    }


    // image_v1->checksum
    if(image_v1->checksum) {
    if(cJSON_AddStringToObject(item, "checksum", image_v1->checksum) == NULL) {
    goto fail; //String
    }
    }


    // image_v1->corellium_checksum
    if(image_v1->corellium_checksum) {
    if(cJSON_AddStringToObject(item, "corelliumChecksum", image_v1->corellium_checksum) == NULL) {
    goto fail; //String
    }
    }


    // image_v1->encoding
    if(image_v1->encoding) {
    if(cJSON_AddStringToObject(item, "encoding", image_v1->encoding) == NULL) {
    goto fail; //String
    }
    }


    // image_v1->filename
    if(image_v1->filename) {
    if(cJSON_AddStringToObject(item, "filename", image_v1->filename) == NULL) {
    goto fail; //String
    }
    }


    // image_v1->uniqueid
    if(image_v1->uniqueid) {
    if(cJSON_AddStringToObject(item, "uniqueid", image_v1->uniqueid) == NULL) {
    goto fail; //String
    }
    }


    // image_v1->project
    if(image_v1->project) {
    if(cJSON_AddStringToObject(item, "project", image_v1->project) == NULL) {
    goto fail; //String
    }
    }


    // image_v1->instance
    if(image_v1->instance) {
    if(cJSON_AddStringToObject(item, "instance", image_v1->instance) == NULL) {
    goto fail; //String
    }
    }


    // image_v1->created_at
    if(image_v1->created_at) {
    if(cJSON_AddStringToObject(item, "created_at", image_v1->created_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // image_v1->updated_at
    if(image_v1->updated_at) {
    if(cJSON_AddStringToObject(item, "updated_at", image_v1->updated_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // image_v1->extended
    if(image_v1->extended) {
    cJSON *extended_local_JSON = image_extended_convertToJSON(image_v1->extended);
    if(extended_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "extended", extended_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

image_v1_t *image_v1_parseFromJSON(cJSON *image_v1JSON){

    image_v1_t *image_v1_local_var = NULL;

    // define the local variable for image_v1->extended
    image_extended_t *extended_local_nonprim = NULL;

    // image_v1->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(image_v1JSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    if(!cJSON_IsString(status) && !cJSON_IsNull(status))
    {
    goto end; //String
    }
    }

    // image_v1->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(image_v1JSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (id) { 
    if(!cJSON_IsString(id) && !cJSON_IsNull(id))
    {
    goto end; //String
    }
    }

    // image_v1->identifier
    cJSON *identifier = cJSON_GetObjectItemCaseSensitive(image_v1JSON, "identifier");
    if (cJSON_IsNull(identifier)) {
        identifier = NULL;
    }
    if (identifier) { 
    if(!cJSON_IsString(identifier) && !cJSON_IsNull(identifier))
    {
    goto end; //String
    }
    }

    // image_v1->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(image_v1JSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // image_v1->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(image_v1JSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    corellium_api_image_v1_TYPE_e typeVariable;
    if (type) { 
    if(!cJSON_IsString(type))
    {
    goto end; //Enum
    }
    typeVariable = image_v1_type_FromString(type->valuestring);
    }

    // image_v1->size
    cJSON *size = cJSON_GetObjectItemCaseSensitive(image_v1JSON, "size");
    if (cJSON_IsNull(size)) {
        size = NULL;
    }
    if (size) { 
    if(!cJSON_IsNumber(size))
    {
    goto end; //Numeric
    }
    }

    // image_v1->checksum
    cJSON *checksum = cJSON_GetObjectItemCaseSensitive(image_v1JSON, "checksum");
    if (cJSON_IsNull(checksum)) {
        checksum = NULL;
    }
    if (checksum) { 
    if(!cJSON_IsString(checksum) && !cJSON_IsNull(checksum))
    {
    goto end; //String
    }
    }

    // image_v1->corellium_checksum
    cJSON *corellium_checksum = cJSON_GetObjectItemCaseSensitive(image_v1JSON, "corelliumChecksum");
    if (cJSON_IsNull(corellium_checksum)) {
        corellium_checksum = NULL;
    }
    if (corellium_checksum) { 
    if(!cJSON_IsString(corellium_checksum) && !cJSON_IsNull(corellium_checksum))
    {
    goto end; //String
    }
    }

    // image_v1->encoding
    cJSON *encoding = cJSON_GetObjectItemCaseSensitive(image_v1JSON, "encoding");
    if (cJSON_IsNull(encoding)) {
        encoding = NULL;
    }
    if (encoding) { 
    if(!cJSON_IsString(encoding) && !cJSON_IsNull(encoding))
    {
    goto end; //String
    }
    }

    // image_v1->filename
    cJSON *filename = cJSON_GetObjectItemCaseSensitive(image_v1JSON, "filename");
    if (cJSON_IsNull(filename)) {
        filename = NULL;
    }
    if (filename) { 
    if(!cJSON_IsString(filename) && !cJSON_IsNull(filename))
    {
    goto end; //String
    }
    }

    // image_v1->uniqueid
    cJSON *uniqueid = cJSON_GetObjectItemCaseSensitive(image_v1JSON, "uniqueid");
    if (cJSON_IsNull(uniqueid)) {
        uniqueid = NULL;
    }
    if (uniqueid) { 
    if(!cJSON_IsString(uniqueid) && !cJSON_IsNull(uniqueid))
    {
    goto end; //String
    }
    }

    // image_v1->project
    cJSON *project = cJSON_GetObjectItemCaseSensitive(image_v1JSON, "project");
    if (cJSON_IsNull(project)) {
        project = NULL;
    }
    if (project) { 
    if(!cJSON_IsString(project) && !cJSON_IsNull(project))
    {
    goto end; //String
    }
    }

    // image_v1->instance
    cJSON *instance = cJSON_GetObjectItemCaseSensitive(image_v1JSON, "instance");
    if (cJSON_IsNull(instance)) {
        instance = NULL;
    }
    if (instance) { 
    if(!cJSON_IsString(instance) && !cJSON_IsNull(instance))
    {
    goto end; //String
    }
    }

    // image_v1->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(image_v1JSON, "created_at");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (created_at) { 
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //DateTime
    }
    }

    // image_v1->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(image_v1JSON, "updated_at");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (updated_at) { 
    if(!cJSON_IsString(updated_at) && !cJSON_IsNull(updated_at))
    {
    goto end; //DateTime
    }
    }

    // image_v1->extended
    cJSON *extended = cJSON_GetObjectItemCaseSensitive(image_v1JSON, "extended");
    if (cJSON_IsNull(extended)) {
        extended = NULL;
    }
    if (extended) { 
    extended_local_nonprim = image_extended_parseFromJSON(extended); //nonprimitive
    }


    image_v1_local_var = image_v1_create_internal (
        status && !cJSON_IsNull(status) ? strdup(status->valuestring) : NULL,
        id && !cJSON_IsNull(id) ? strdup(id->valuestring) : NULL,
        identifier && !cJSON_IsNull(identifier) ? strdup(identifier->valuestring) : NULL,
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        type ? typeVariable : corellium_api_image_v1_TYPE_NULL,
        size ? size->valuedouble : 0,
        checksum && !cJSON_IsNull(checksum) ? strdup(checksum->valuestring) : NULL,
        corellium_checksum && !cJSON_IsNull(corellium_checksum) ? strdup(corellium_checksum->valuestring) : NULL,
        encoding && !cJSON_IsNull(encoding) ? strdup(encoding->valuestring) : NULL,
        filename && !cJSON_IsNull(filename) ? strdup(filename->valuestring) : NULL,
        uniqueid && !cJSON_IsNull(uniqueid) ? strdup(uniqueid->valuestring) : NULL,
        project && !cJSON_IsNull(project) ? strdup(project->valuestring) : NULL,
        instance && !cJSON_IsNull(instance) ? strdup(instance->valuestring) : NULL,
        created_at && !cJSON_IsNull(created_at) ? strdup(created_at->valuestring) : NULL,
        updated_at && !cJSON_IsNull(updated_at) ? strdup(updated_at->valuestring) : NULL,
        extended ? extended_local_nonprim : NULL
        );

    return image_v1_local_var;
end:
    if (extended_local_nonprim) {
        image_extended_free(extended_local_nonprim);
        extended_local_nonprim = NULL;
    }
    return NULL;

}
