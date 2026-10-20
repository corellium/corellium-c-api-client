#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_image_body.h"



static create_image_body_t *create_image_body_create_internal(
    corellium_api_image_type__e type,
    corellium_api_image_encoding__e encoding,
    int encapsulated,
    char *name,
    char *full_path,
    char *project_id,
    char *instance_id,
    binary_t* file
    ) {
    create_image_body_t *create_image_body_local_var = malloc(sizeof(create_image_body_t));
    if (!create_image_body_local_var) {
        return NULL;
    }
    create_image_body_local_var->type = type;
    create_image_body_local_var->encoding = encoding;
    create_image_body_local_var->encapsulated = encapsulated;
    create_image_body_local_var->name = name;
    create_image_body_local_var->full_path = full_path;
    create_image_body_local_var->project_id = project_id;
    create_image_body_local_var->instance_id = instance_id;
    create_image_body_local_var->file = file;

    create_image_body_local_var->_library_owned = 1;
    return create_image_body_local_var;
}

__attribute__((deprecated)) create_image_body_t *create_image_body_create(
    corellium_api_image_type__e type,
    corellium_api_image_encoding__e encoding,
    int encapsulated,
    char *name,
    char *full_path,
    char *project_id,
    char *instance_id,
    binary_t* file
    ) {
    return create_image_body_create_internal (
        type,
        encoding,
        encapsulated,
        name,
        full_path,
        project_id,
        instance_id,
        file
        );
}

void create_image_body_free(create_image_body_t *create_image_body) {
    if(NULL == create_image_body){
        return ;
    }
    if(create_image_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "create_image_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (create_image_body->name) {
        free(create_image_body->name);
        create_image_body->name = NULL;
    }
    if (create_image_body->full_path) {
        free(create_image_body->full_path);
        create_image_body->full_path = NULL;
    }
    if (create_image_body->project_id) {
        free(create_image_body->project_id);
        create_image_body->project_id = NULL;
    }
    if (create_image_body->instance_id) {
        free(create_image_body->instance_id);
        create_image_body->instance_id = NULL;
    }
    if (create_image_body->file) {
        free(create_image_body->file->data);
        create_image_body->file = NULL;
    }
    free(create_image_body);
}

cJSON *create_image_body_convertToJSON(create_image_body_t *create_image_body) {
    cJSON *item = cJSON_CreateObject();

    // create_image_body->type
    if (corellium_api_image_type__NULL == create_image_body->type) {
        goto fail;
    }
    cJSON *type_local_JSON = image_type_convertToJSON(create_image_body->type);
    if(type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "type", type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // create_image_body->encoding
    if (corellium_api_image_encoding__NULL == create_image_body->encoding) {
        goto fail;
    }
    cJSON *encoding_local_JSON = image_encoding_convertToJSON(create_image_body->encoding);
    if(encoding_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "encoding", encoding_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // create_image_body->encapsulated
    if(create_image_body->encapsulated) {
    if(cJSON_AddBoolToObject(item, "encapsulated", create_image_body->encapsulated) == NULL) {
    goto fail; //Bool
    }
    }


    // create_image_body->name
    if(create_image_body->name) {
    if(cJSON_AddStringToObject(item, "name", create_image_body->name) == NULL) {
    goto fail; //String
    }
    }


    // create_image_body->full_path
    if(create_image_body->full_path) {
    if(cJSON_AddStringToObject(item, "fullPath", create_image_body->full_path) == NULL) {
    goto fail; //String
    }
    }


    // create_image_body->project_id
    if(create_image_body->project_id) {
    if(cJSON_AddStringToObject(item, "projectId", create_image_body->project_id) == NULL) {
    goto fail; //String
    }
    }


    // create_image_body->instance_id
    if(create_image_body->instance_id) {
    if(cJSON_AddStringToObject(item, "instanceId", create_image_body->instance_id) == NULL) {
    goto fail; //String
    }
    }


    // create_image_body->file
    if(create_image_body->file) {
    char* encoded_str_file = base64encode(create_image_body->file->data,create_image_body->file->len);
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

create_image_body_t *create_image_body_parseFromJSON(cJSON *create_image_bodyJSON){

    create_image_body_t *create_image_body_local_var = NULL;

    // define the local variable for create_image_body->type
    corellium_api_image_type__e type_local_nonprim = 0;

    // define the local variable for create_image_body->encoding
    corellium_api_image_encoding__e encoding_local_nonprim = 0;

    // create_image_body->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(create_image_bodyJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    
    type_local_nonprim = image_type_parseFromJSON(type); //custom

    // create_image_body->encoding
    cJSON *encoding = cJSON_GetObjectItemCaseSensitive(create_image_bodyJSON, "encoding");
    if (cJSON_IsNull(encoding)) {
        encoding = NULL;
    }
    if (!encoding) {
        goto end;
    }

    
    encoding_local_nonprim = image_encoding_parseFromJSON(encoding); //custom

    // create_image_body->encapsulated
    cJSON *encapsulated = cJSON_GetObjectItemCaseSensitive(create_image_bodyJSON, "encapsulated");
    if (cJSON_IsNull(encapsulated)) {
        encapsulated = NULL;
    }
    if (encapsulated) { 
    if(!cJSON_IsBool(encapsulated))
    {
    goto end; //Bool
    }
    }

    // create_image_body->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(create_image_bodyJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // create_image_body->full_path
    cJSON *full_path = cJSON_GetObjectItemCaseSensitive(create_image_bodyJSON, "fullPath");
    if (cJSON_IsNull(full_path)) {
        full_path = NULL;
    }
    if (full_path) { 
    if(!cJSON_IsString(full_path) && !cJSON_IsNull(full_path))
    {
    goto end; //String
    }
    }

    // create_image_body->project_id
    cJSON *project_id = cJSON_GetObjectItemCaseSensitive(create_image_bodyJSON, "projectId");
    if (cJSON_IsNull(project_id)) {
        project_id = NULL;
    }
    if (project_id) { 
    if(!cJSON_IsString(project_id) && !cJSON_IsNull(project_id))
    {
    goto end; //String
    }
    }

    // create_image_body->instance_id
    cJSON *instance_id = cJSON_GetObjectItemCaseSensitive(create_image_bodyJSON, "instanceId");
    if (cJSON_IsNull(instance_id)) {
        instance_id = NULL;
    }
    if (instance_id) { 
    if(!cJSON_IsString(instance_id) && !cJSON_IsNull(instance_id))
    {
    goto end; //String
    }
    }

    // create_image_body->file
    cJSON *file = cJSON_GetObjectItemCaseSensitive(create_image_bodyJSON, "file");
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


    create_image_body_local_var = create_image_body_create_internal (
        type_local_nonprim,
        encoding_local_nonprim,
        encapsulated ? encapsulated->valueint : 0,
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        full_path && !cJSON_IsNull(full_path) ? strdup(full_path->valuestring) : NULL,
        project_id && !cJSON_IsNull(project_id) ? strdup(project_id->valuestring) : NULL,
        instance_id && !cJSON_IsNull(instance_id) ? strdup(instance_id->valuestring) : NULL,
        file ? decoded_str_file : NULL
        );

    return create_image_body_local_var;
end:
    if (type_local_nonprim) {
        type_local_nonprim = 0;
    }
    if (encoding_local_nonprim) {
        encoding_local_nonprim = 0;
    }
    return NULL;

}
