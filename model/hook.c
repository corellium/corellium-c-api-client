#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hook.h"


char* hook_patch_type_ToString(corellium_api_hook_PATCHTYPE_e patch_type) {
    char* patch_typeArray[] =  { "NULL", "csmfcc", "csmfvm" };
    return patch_typeArray[patch_type];
}

corellium_api_hook_PATCHTYPE_e hook_patch_type_FromString(char* patch_type){
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

static hook_t *hook_create_internal(
    char *identifier,
    char *label,
    char *address,
    char *patch,
    corellium_api_hook_PATCHTYPE_e patch_type,
    int enabled,
    char *instance_id,
    char *created_at,
    char *updated_at
    ) {
    hook_t *hook_local_var = malloc(sizeof(hook_t));
    if (!hook_local_var) {
        return NULL;
    }
    hook_local_var->identifier = identifier;
    hook_local_var->label = label;
    hook_local_var->address = address;
    hook_local_var->patch = patch;
    hook_local_var->patch_type = patch_type;
    hook_local_var->enabled = enabled;
    hook_local_var->instance_id = instance_id;
    hook_local_var->created_at = created_at;
    hook_local_var->updated_at = updated_at;

    hook_local_var->_library_owned = 1;
    return hook_local_var;
}

__attribute__((deprecated)) hook_t *hook_create(
    char *identifier,
    char *label,
    char *address,
    char *patch,
    corellium_api_hook_PATCHTYPE_e patch_type,
    int enabled,
    char *instance_id,
    char *created_at,
    char *updated_at
    ) {
    return hook_create_internal (
        identifier,
        label,
        address,
        patch,
        patch_type,
        enabled,
        instance_id,
        created_at,
        updated_at
        );
}

void hook_free(hook_t *hook) {
    if(NULL == hook){
        return ;
    }
    if(hook->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "hook_free");
        return ;
    }
    listEntry_t *listEntry;
    if (hook->identifier) {
        free(hook->identifier);
        hook->identifier = NULL;
    }
    if (hook->label) {
        free(hook->label);
        hook->label = NULL;
    }
    if (hook->address) {
        free(hook->address);
        hook->address = NULL;
    }
    if (hook->patch) {
        free(hook->patch);
        hook->patch = NULL;
    }
    if (hook->instance_id) {
        free(hook->instance_id);
        hook->instance_id = NULL;
    }
    if (hook->created_at) {
        free(hook->created_at);
        hook->created_at = NULL;
    }
    if (hook->updated_at) {
        free(hook->updated_at);
        hook->updated_at = NULL;
    }
    free(hook);
}

cJSON *hook_convertToJSON(hook_t *hook) {
    cJSON *item = cJSON_CreateObject();

    // hook->identifier
    if (!hook->identifier) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "identifier", hook->identifier) == NULL) {
    goto fail; //String
    }


    // hook->label
    if (!hook->label) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "label", hook->label) == NULL) {
    goto fail; //String
    }


    // hook->address
    if (!hook->address) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "address", hook->address) == NULL) {
    goto fail; //String
    }


    // hook->patch
    if (!hook->patch) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "patch", hook->patch) == NULL) {
    goto fail; //String
    }


    // hook->patch_type
    if (corellium_api_hook_PATCHTYPE_NULL == hook->patch_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "patchType", hook_patch_type_ToString(hook->patch_type)) == NULL)
    {
    goto fail; //Enum
    }


    // hook->enabled
    if (!hook->enabled) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "enabled", hook->enabled) == NULL) {
    goto fail; //Bool
    }


    // hook->instance_id
    if (!hook->instance_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "instanceId", hook->instance_id) == NULL) {
    goto fail; //String
    }


    // hook->created_at
    if (!hook->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "createdAt", hook->created_at) == NULL) {
    goto fail; //Date-Time
    }


    // hook->updated_at
    if (!hook->updated_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "updatedAt", hook->updated_at) == NULL) {
    goto fail; //Date-Time
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

hook_t *hook_parseFromJSON(cJSON *hookJSON){

    hook_t *hook_local_var = NULL;

    // hook->identifier
    cJSON *identifier = cJSON_GetObjectItemCaseSensitive(hookJSON, "identifier");
    if (cJSON_IsNull(identifier)) {
        identifier = NULL;
    }
    if (!identifier) {
        goto end;
    }

    
    if(!cJSON_IsString(identifier))
    {
    goto end; //String
    }

    // hook->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(hookJSON, "label");
    if (cJSON_IsNull(label)) {
        label = NULL;
    }
    if (!label) {
        goto end;
    }

    
    if(!cJSON_IsString(label))
    {
    goto end; //String
    }

    // hook->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(hookJSON, "address");
    if (cJSON_IsNull(address)) {
        address = NULL;
    }
    if (!address) {
        goto end;
    }

    
    if(!cJSON_IsString(address))
    {
    goto end; //String
    }

    // hook->patch
    cJSON *patch = cJSON_GetObjectItemCaseSensitive(hookJSON, "patch");
    if (cJSON_IsNull(patch)) {
        patch = NULL;
    }
    if (!patch) {
        goto end;
    }

    
    if(!cJSON_IsString(patch))
    {
    goto end; //String
    }

    // hook->patch_type
    cJSON *patch_type = cJSON_GetObjectItemCaseSensitive(hookJSON, "patchType");
    if (cJSON_IsNull(patch_type)) {
        patch_type = NULL;
    }
    if (!patch_type) {
        goto end;
    }

    corellium_api_hook_PATCHTYPE_e patch_typeVariable;
    
    if(!cJSON_IsString(patch_type))
    {
    goto end; //Enum
    }
    patch_typeVariable = hook_patch_type_FromString(patch_type->valuestring);

    // hook->enabled
    cJSON *enabled = cJSON_GetObjectItemCaseSensitive(hookJSON, "enabled");
    if (cJSON_IsNull(enabled)) {
        enabled = NULL;
    }
    if (!enabled) {
        goto end;
    }

    
    if(!cJSON_IsBool(enabled))
    {
    goto end; //Bool
    }

    // hook->instance_id
    cJSON *instance_id = cJSON_GetObjectItemCaseSensitive(hookJSON, "instanceId");
    if (cJSON_IsNull(instance_id)) {
        instance_id = NULL;
    }
    if (!instance_id) {
        goto end;
    }

    
    if(!cJSON_IsString(instance_id))
    {
    goto end; //String
    }

    // hook->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(hookJSON, "createdAt");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (!created_at) {
        goto end;
    }

    
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //DateTime
    }

    // hook->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(hookJSON, "updatedAt");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (!updated_at) {
        goto end;
    }

    
    if(!cJSON_IsString(updated_at) && !cJSON_IsNull(updated_at))
    {
    goto end; //DateTime
    }


    hook_local_var = hook_create_internal (
        strdup(identifier->valuestring),
        strdup(label->valuestring),
        strdup(address->valuestring),
        strdup(patch->valuestring),
        patch_typeVariable,
        enabled->valueint,
        strdup(instance_id->valuestring),
        strdup(created_at->valuestring),
        strdup(updated_at->valuestring)
        );

    return hook_local_var;
end:
    return NULL;

}
