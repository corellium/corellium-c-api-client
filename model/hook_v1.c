#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hook_v1.h"


char* hook_v1_patch_type_ToString(corellium_api_hook_v1_PATCHTYPE_e patch_type) {
    char* patch_typeArray[] =  { "NULL", "csmfcc", "csmfvm" };
    return patch_typeArray[patch_type];
}

corellium_api_hook_v1_PATCHTYPE_e hook_v1_patch_type_FromString(char* patch_type){
    int stringToReturn = 0;
    char *patch_typeArray[] =  { "NULL", "csmfcc", "csmfvm" };
    size_t sizeofArray = sizeof(patch_typeArray) / sizeof(patch_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(patch_type, patch_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static hook_v1_t *hook_v1_create_internal(
    char *identifier,
    char *label,
    char *address,
    char *patch,
    corellium_api_hook_v1_PATCHTYPE_e patch_type,
    int enabled,
    char *created_at,
    char *updated_at,
    char *instance_id
    ) {
    hook_v1_t *hook_v1_local_var = malloc(sizeof(hook_v1_t));
    if (!hook_v1_local_var) {
        return NULL;
    }
    hook_v1_local_var->identifier = identifier;
    hook_v1_local_var->label = label;
    hook_v1_local_var->address = address;
    hook_v1_local_var->patch = patch;
    hook_v1_local_var->patch_type = patch_type;
    hook_v1_local_var->enabled = enabled;
    hook_v1_local_var->created_at = created_at;
    hook_v1_local_var->updated_at = updated_at;
    hook_v1_local_var->instance_id = instance_id;

    hook_v1_local_var->_library_owned = 1;
    return hook_v1_local_var;
}

__attribute__((deprecated)) hook_v1_t *hook_v1_create(
    char *identifier,
    char *label,
    char *address,
    char *patch,
    corellium_api_hook_v1_PATCHTYPE_e patch_type,
    int enabled,
    char *created_at,
    char *updated_at,
    char *instance_id
    ) {
    return hook_v1_create_internal (
        identifier,
        label,
        address,
        patch,
        patch_type,
        enabled,
        created_at,
        updated_at,
        instance_id
        );
}

void hook_v1_free(hook_v1_t *hook_v1) {
    if(NULL == hook_v1){
        return ;
    }
    if(hook_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "hook_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (hook_v1->identifier) {
        free(hook_v1->identifier);
        hook_v1->identifier = NULL;
    }
    if (hook_v1->label) {
        free(hook_v1->label);
        hook_v1->label = NULL;
    }
    if (hook_v1->address) {
        free(hook_v1->address);
        hook_v1->address = NULL;
    }
    if (hook_v1->patch) {
        free(hook_v1->patch);
        hook_v1->patch = NULL;
    }
    if (hook_v1->created_at) {
        free(hook_v1->created_at);
        hook_v1->created_at = NULL;
    }
    if (hook_v1->updated_at) {
        free(hook_v1->updated_at);
        hook_v1->updated_at = NULL;
    }
    if (hook_v1->instance_id) {
        free(hook_v1->instance_id);
        hook_v1->instance_id = NULL;
    }
    free(hook_v1);
}

cJSON *hook_v1_convertToJSON(hook_v1_t *hook_v1) {
    cJSON *item = cJSON_CreateObject();

    // hook_v1->identifier
    if(hook_v1->identifier) {
    if(cJSON_AddStringToObject(item, "identifier", hook_v1->identifier) == NULL) {
    goto fail; //String
    }
    }


    // hook_v1->label
    if(hook_v1->label) {
    if(cJSON_AddStringToObject(item, "label", hook_v1->label) == NULL) {
    goto fail; //String
    }
    }


    // hook_v1->address
    if(hook_v1->address) {
    if(cJSON_AddStringToObject(item, "address", hook_v1->address) == NULL) {
    goto fail; //String
    }
    }


    // hook_v1->patch
    if(hook_v1->patch) {
    if(cJSON_AddStringToObject(item, "patch", hook_v1->patch) == NULL) {
    goto fail; //String
    }
    }


    // hook_v1->patch_type
    if(hook_v1->patch_type != corellium_api_hook_v1_PATCHTYPE_NULL) {
    if(cJSON_AddStringToObject(item, "patchType", hook_v1_patch_type_ToString(hook_v1->patch_type)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // hook_v1->enabled
    if(hook_v1->enabled) {
    if(cJSON_AddBoolToObject(item, "enabled", hook_v1->enabled) == NULL) {
    goto fail; //Bool
    }
    }


    // hook_v1->created_at
    if(hook_v1->created_at) {
    if(cJSON_AddStringToObject(item, "createdAt", hook_v1->created_at) == NULL) {
    goto fail; //String
    }
    }


    // hook_v1->updated_at
    if(hook_v1->updated_at) {
    if(cJSON_AddStringToObject(item, "updatedAt", hook_v1->updated_at) == NULL) {
    goto fail; //String
    }
    }


    // hook_v1->instance_id
    if(hook_v1->instance_id) {
    if(cJSON_AddStringToObject(item, "instanceId", hook_v1->instance_id) == NULL) {
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

hook_v1_t *hook_v1_parseFromJSON(cJSON *hook_v1JSON){

    hook_v1_t *hook_v1_local_var = NULL;

    // hook_v1->identifier
    cJSON *identifier = cJSON_GetObjectItemCaseSensitive(hook_v1JSON, "identifier");
    if (cJSON_IsNull(identifier)) {
        identifier = NULL;
    }
    if (identifier) { 
    if(!cJSON_IsString(identifier) && !cJSON_IsNull(identifier))
    {
    goto end; //String
    }
    }

    // hook_v1->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(hook_v1JSON, "label");
    if (cJSON_IsNull(label)) {
        label = NULL;
    }
    if (label) { 
    if(!cJSON_IsString(label) && !cJSON_IsNull(label))
    {
    goto end; //String
    }
    }

    // hook_v1->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(hook_v1JSON, "address");
    if (cJSON_IsNull(address)) {
        address = NULL;
    }
    if (address) { 
    if(!cJSON_IsString(address) && !cJSON_IsNull(address))
    {
    goto end; //String
    }
    }

    // hook_v1->patch
    cJSON *patch = cJSON_GetObjectItemCaseSensitive(hook_v1JSON, "patch");
    if (cJSON_IsNull(patch)) {
        patch = NULL;
    }
    if (patch) { 
    if(!cJSON_IsString(patch) && !cJSON_IsNull(patch))
    {
    goto end; //String
    }
    }

    // hook_v1->patch_type
    cJSON *patch_type = cJSON_GetObjectItemCaseSensitive(hook_v1JSON, "patchType");
    if (cJSON_IsNull(patch_type)) {
        patch_type = NULL;
    }
    corellium_api_hook_v1_PATCHTYPE_e patch_typeVariable;
    if (patch_type) { 
    if(!cJSON_IsString(patch_type))
    {
    goto end; //Enum
    }
    patch_typeVariable = hook_v1_patch_type_FromString(patch_type->valuestring);
    }

    // hook_v1->enabled
    cJSON *enabled = cJSON_GetObjectItemCaseSensitive(hook_v1JSON, "enabled");
    if (cJSON_IsNull(enabled)) {
        enabled = NULL;
    }
    if (enabled) { 
    if(!cJSON_IsBool(enabled))
    {
    goto end; //Bool
    }
    }

    // hook_v1->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(hook_v1JSON, "createdAt");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (created_at) { 
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //String
    }
    }

    // hook_v1->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(hook_v1JSON, "updatedAt");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (updated_at) { 
    if(!cJSON_IsString(updated_at) && !cJSON_IsNull(updated_at))
    {
    goto end; //String
    }
    }

    // hook_v1->instance_id
    cJSON *instance_id = cJSON_GetObjectItemCaseSensitive(hook_v1JSON, "instanceId");
    if (cJSON_IsNull(instance_id)) {
        instance_id = NULL;
    }
    if (instance_id) { 
    if(!cJSON_IsString(instance_id) && !cJSON_IsNull(instance_id))
    {
    goto end; //String
    }
    }


    hook_v1_local_var = hook_v1_create_internal (
        identifier && !cJSON_IsNull(identifier) ? strdup(identifier->valuestring) : NULL,
        label && !cJSON_IsNull(label) ? strdup(label->valuestring) : NULL,
        address && !cJSON_IsNull(address) ? strdup(address->valuestring) : NULL,
        patch && !cJSON_IsNull(patch) ? strdup(patch->valuestring) : NULL,
        patch_type ? patch_typeVariable : corellium_api_hook_v1_PATCHTYPE_NULL,
        enabled ? enabled->valueint : 0,
        created_at && !cJSON_IsNull(created_at) ? strdup(created_at->valuestring) : NULL,
        updated_at && !cJSON_IsNull(updated_at) ? strdup(updated_at->valuestring) : NULL,
        instance_id && !cJSON_IsNull(instance_id) ? strdup(instance_id->valuestring) : NULL
        );

    return hook_v1_local_var;
end:
    return NULL;

}
