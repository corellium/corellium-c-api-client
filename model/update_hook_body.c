#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "update_hook_body.h"


char* update_hook_body_patch_type_ToString(corellium_api_update_hook_body_PATCHTYPE_e patch_type) {
    char* patch_typeArray[] =  { "NULL", "csmfcc", "csmfvm" };
    return patch_typeArray[patch_type];
}

corellium_api_update_hook_body_PATCHTYPE_e update_hook_body_patch_type_FromString(char* patch_type){
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

static update_hook_body_t *update_hook_body_create_internal(
    char *label,
    char *address,
    char *patch,
    corellium_api_update_hook_body_PATCHTYPE_e patch_type,
    int enabled
    ) {
    update_hook_body_t *update_hook_body_local_var = malloc(sizeof(update_hook_body_t));
    if (!update_hook_body_local_var) {
        return NULL;
    }
    update_hook_body_local_var->label = label;
    update_hook_body_local_var->address = address;
    update_hook_body_local_var->patch = patch;
    update_hook_body_local_var->patch_type = patch_type;
    update_hook_body_local_var->enabled = enabled;

    update_hook_body_local_var->_library_owned = 1;
    return update_hook_body_local_var;
}

__attribute__((deprecated)) update_hook_body_t *update_hook_body_create(
    char *label,
    char *address,
    char *patch,
    corellium_api_update_hook_body_PATCHTYPE_e patch_type,
    int enabled
    ) {
    return update_hook_body_create_internal (
        label,
        address,
        patch,
        patch_type,
        enabled
        );
}

void update_hook_body_free(update_hook_body_t *update_hook_body) {
    if(NULL == update_hook_body){
        return ;
    }
    if(update_hook_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "update_hook_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (update_hook_body->label) {
        free(update_hook_body->label);
        update_hook_body->label = NULL;
    }
    if (update_hook_body->address) {
        free(update_hook_body->address);
        update_hook_body->address = NULL;
    }
    if (update_hook_body->patch) {
        free(update_hook_body->patch);
        update_hook_body->patch = NULL;
    }
    free(update_hook_body);
}

cJSON *update_hook_body_convertToJSON(update_hook_body_t *update_hook_body) {
    cJSON *item = cJSON_CreateObject();

    // update_hook_body->label
    if(update_hook_body->label) {
    if(cJSON_AddStringToObject(item, "label", update_hook_body->label) == NULL) {
    goto fail; //String
    }
    }


    // update_hook_body->address
    if(update_hook_body->address) {
    if(cJSON_AddStringToObject(item, "address", update_hook_body->address) == NULL) {
    goto fail; //String
    }
    }


    // update_hook_body->patch
    if(update_hook_body->patch) {
    if(cJSON_AddStringToObject(item, "patch", update_hook_body->patch) == NULL) {
    goto fail; //String
    }
    }


    // update_hook_body->patch_type
    if(update_hook_body->patch_type != corellium_api_update_hook_body_PATCHTYPE_NULL) {
    if(cJSON_AddStringToObject(item, "patchType", update_hook_body_patch_type_ToString(update_hook_body->patch_type)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // update_hook_body->enabled
    if(update_hook_body->enabled) {
    if(cJSON_AddBoolToObject(item, "enabled", update_hook_body->enabled) == NULL) {
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

update_hook_body_t *update_hook_body_parseFromJSON(cJSON *update_hook_bodyJSON){

    update_hook_body_t *update_hook_body_local_var = NULL;

    // update_hook_body->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(update_hook_bodyJSON, "label");
    if (cJSON_IsNull(label)) {
        label = NULL;
    }
    if (label) { 
    if(!cJSON_IsString(label) && !cJSON_IsNull(label))
    {
    goto end; //String
    }
    }

    // update_hook_body->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(update_hook_bodyJSON, "address");
    if (cJSON_IsNull(address)) {
        address = NULL;
    }
    if (address) { 
    if(!cJSON_IsString(address) && !cJSON_IsNull(address))
    {
    goto end; //String
    }
    }

    // update_hook_body->patch
    cJSON *patch = cJSON_GetObjectItemCaseSensitive(update_hook_bodyJSON, "patch");
    if (cJSON_IsNull(patch)) {
        patch = NULL;
    }
    if (patch) { 
    if(!cJSON_IsString(patch) && !cJSON_IsNull(patch))
    {
    goto end; //String
    }
    }

    // update_hook_body->patch_type
    cJSON *patch_type = cJSON_GetObjectItemCaseSensitive(update_hook_bodyJSON, "patchType");
    if (cJSON_IsNull(patch_type)) {
        patch_type = NULL;
    }
    corellium_api_update_hook_body_PATCHTYPE_e patch_typeVariable;
    if (patch_type) { 
    if(!cJSON_IsString(patch_type))
    {
    goto end; //Enum
    }
    patch_typeVariable = update_hook_body_patch_type_FromString(patch_type->valuestring);
    }

    // update_hook_body->enabled
    cJSON *enabled = cJSON_GetObjectItemCaseSensitive(update_hook_bodyJSON, "enabled");
    if (cJSON_IsNull(enabled)) {
        enabled = NULL;
    }
    if (enabled) { 
    if(!cJSON_IsBool(enabled))
    {
    goto end; //Bool
    }
    }


    update_hook_body_local_var = update_hook_body_create_internal (
        label && !cJSON_IsNull(label) ? strdup(label->valuestring) : NULL,
        address && !cJSON_IsNull(address) ? strdup(address->valuestring) : NULL,
        patch && !cJSON_IsNull(patch) ? strdup(patch->valuestring) : NULL,
        patch_type ? patch_typeVariable : corellium_api_update_hook_body_PATCHTYPE_NULL,
        enabled ? enabled->valueint : 0
        );

    return update_hook_body_local_var;
end:
    return NULL;

}
