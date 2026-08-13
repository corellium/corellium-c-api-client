#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_hook_body.h"


char* create_hook_body_patch_type_ToString(corellium_api_create_hook_body_PATCHTYPE_e patch_type) {
    char* patch_typeArray[] =  { "NULL", "csmfcc", "csmfvm" };
    return patch_typeArray[patch_type];
}

corellium_api_create_hook_body_PATCHTYPE_e create_hook_body_patch_type_FromString(char* patch_type){
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

static create_hook_body_t *create_hook_body_create_internal(
    char *label,
    char *address,
    char *patch,
    corellium_api_create_hook_body_PATCHTYPE_e patch_type,
    int enabled
    ) {
    create_hook_body_t *create_hook_body_local_var = malloc(sizeof(create_hook_body_t));
    if (!create_hook_body_local_var) {
        return NULL;
    }
    create_hook_body_local_var->label = label;
    create_hook_body_local_var->address = address;
    create_hook_body_local_var->patch = patch;
    create_hook_body_local_var->patch_type = patch_type;
    create_hook_body_local_var->enabled = enabled;

    create_hook_body_local_var->_library_owned = 1;
    return create_hook_body_local_var;
}

__attribute__((deprecated)) create_hook_body_t *create_hook_body_create(
    char *label,
    char *address,
    char *patch,
    corellium_api_create_hook_body_PATCHTYPE_e patch_type,
    int enabled
    ) {
    return create_hook_body_create_internal (
        label,
        address,
        patch,
        patch_type,
        enabled
        );
}

void create_hook_body_free(create_hook_body_t *create_hook_body) {
    if(NULL == create_hook_body){
        return ;
    }
    if(create_hook_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "create_hook_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (create_hook_body->label) {
        free(create_hook_body->label);
        create_hook_body->label = NULL;
    }
    if (create_hook_body->address) {
        free(create_hook_body->address);
        create_hook_body->address = NULL;
    }
    if (create_hook_body->patch) {
        free(create_hook_body->patch);
        create_hook_body->patch = NULL;
    }
    free(create_hook_body);
}

cJSON *create_hook_body_convertToJSON(create_hook_body_t *create_hook_body) {
    cJSON *item = cJSON_CreateObject();

    // create_hook_body->label
    if (!create_hook_body->label) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "label", create_hook_body->label) == NULL) {
    goto fail; //String
    }


    // create_hook_body->address
    if (!create_hook_body->address) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "address", create_hook_body->address) == NULL) {
    goto fail; //String
    }


    // create_hook_body->patch
    if (!create_hook_body->patch) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "patch", create_hook_body->patch) == NULL) {
    goto fail; //String
    }


    // create_hook_body->patch_type
    if (corellium_api_create_hook_body_PATCHTYPE_NULL == create_hook_body->patch_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "patchType", create_hook_body_patch_type_ToString(create_hook_body->patch_type)) == NULL)
    {
    goto fail; //Enum
    }


    // create_hook_body->enabled
    if(create_hook_body->enabled) {
    if(cJSON_AddBoolToObject(item, "enabled", create_hook_body->enabled) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

create_hook_body_t *create_hook_body_parseFromJSON(cJSON *create_hook_bodyJSON){

    create_hook_body_t *create_hook_body_local_var = NULL;

    // create_hook_body->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(create_hook_bodyJSON, "label");
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

    // create_hook_body->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(create_hook_bodyJSON, "address");
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

    // create_hook_body->patch
    cJSON *patch = cJSON_GetObjectItemCaseSensitive(create_hook_bodyJSON, "patch");
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

    // create_hook_body->patch_type
    cJSON *patch_type = cJSON_GetObjectItemCaseSensitive(create_hook_bodyJSON, "patchType");
    if (cJSON_IsNull(patch_type)) {
        patch_type = NULL;
    }
    if (!patch_type) {
        goto end;
    }

    corellium_api_create_hook_body_PATCHTYPE_e patch_typeVariable;
    
    if(!cJSON_IsString(patch_type))
    {
    goto end; //Enum
    }
    patch_typeVariable = create_hook_body_patch_type_FromString(patch_type->valuestring);

    // create_hook_body->enabled
    cJSON *enabled = cJSON_GetObjectItemCaseSensitive(create_hook_bodyJSON, "enabled");
    if (cJSON_IsNull(enabled)) {
        enabled = NULL;
    }
    if (enabled) { 
    if(!cJSON_IsBool(enabled))
    {
    goto end; //Bool
    }
    }


    create_hook_body_local_var = create_hook_body_create_internal (
        strdup(label->valuestring),
        strdup(address->valuestring),
        strdup(patch->valuestring),
        patch_typeVariable,
        enabled ? enabled->valueint : 0
        );

    return create_hook_body_local_var;
end:
    return NULL;

}
