#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_update_hook_parameters.h"


char* v1_update_hook_parameters_patch_type_ToString(corellium_api_v1_update_hook_parameters_PATCHTYPE_e patch_type) {
    char* patch_typeArray[] =  { "NULL", "csmfcc", "csmfvm" };
    return patch_typeArray[patch_type];
}

corellium_api_v1_update_hook_parameters_PATCHTYPE_e v1_update_hook_parameters_patch_type_FromString(char* patch_type){
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

static v1_update_hook_parameters_t *v1_update_hook_parameters_create_internal(
    char *label,
    char *address,
    char *patch,
    corellium_api_v1_update_hook_parameters_PATCHTYPE_e patch_type,
    int enabled
    ) {
    v1_update_hook_parameters_t *v1_update_hook_parameters_local_var = malloc(sizeof(v1_update_hook_parameters_t));
    if (!v1_update_hook_parameters_local_var) {
        return NULL;
    }
    v1_update_hook_parameters_local_var->label = label;
    v1_update_hook_parameters_local_var->address = address;
    v1_update_hook_parameters_local_var->patch = patch;
    v1_update_hook_parameters_local_var->patch_type = patch_type;
    v1_update_hook_parameters_local_var->enabled = enabled;

    v1_update_hook_parameters_local_var->_library_owned = 1;
    return v1_update_hook_parameters_local_var;
}

__attribute__((deprecated)) v1_update_hook_parameters_t *v1_update_hook_parameters_create(
    char *label,
    char *address,
    char *patch,
    corellium_api_v1_update_hook_parameters_PATCHTYPE_e patch_type,
    int enabled
    ) {
    return v1_update_hook_parameters_create_internal (
        label,
        address,
        patch,
        patch_type,
        enabled
        );
}

void v1_update_hook_parameters_free(v1_update_hook_parameters_t *v1_update_hook_parameters) {
    if(NULL == v1_update_hook_parameters){
        return ;
    }
    if(v1_update_hook_parameters->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_update_hook_parameters_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_update_hook_parameters->label) {
        free(v1_update_hook_parameters->label);
        v1_update_hook_parameters->label = NULL;
    }
    if (v1_update_hook_parameters->address) {
        free(v1_update_hook_parameters->address);
        v1_update_hook_parameters->address = NULL;
    }
    if (v1_update_hook_parameters->patch) {
        free(v1_update_hook_parameters->patch);
        v1_update_hook_parameters->patch = NULL;
    }
    free(v1_update_hook_parameters);
}

cJSON *v1_update_hook_parameters_convertToJSON(v1_update_hook_parameters_t *v1_update_hook_parameters) {
    cJSON *item = cJSON_CreateObject();

    // v1_update_hook_parameters->label
    if(v1_update_hook_parameters->label) {
    if(cJSON_AddStringToObject(item, "label", v1_update_hook_parameters->label) == NULL) {
    goto fail; //String
    }
    }


    // v1_update_hook_parameters->address
    if(v1_update_hook_parameters->address) {
    if(cJSON_AddStringToObject(item, "address", v1_update_hook_parameters->address) == NULL) {
    goto fail; //String
    }
    }


    // v1_update_hook_parameters->patch
    if(v1_update_hook_parameters->patch) {
    if(cJSON_AddStringToObject(item, "patch", v1_update_hook_parameters->patch) == NULL) {
    goto fail; //String
    }
    }


    // v1_update_hook_parameters->patch_type
    if(v1_update_hook_parameters->patch_type != corellium_api_v1_update_hook_parameters_PATCHTYPE_NULL) {
    if(cJSON_AddStringToObject(item, "patchType", v1_update_hook_parameters_patch_type_ToString(v1_update_hook_parameters->patch_type)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // v1_update_hook_parameters->enabled
    if(v1_update_hook_parameters->enabled) {
    if(cJSON_AddBoolToObject(item, "enabled", v1_update_hook_parameters->enabled) == NULL) {
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

v1_update_hook_parameters_t *v1_update_hook_parameters_parseFromJSON(cJSON *v1_update_hook_parametersJSON){

    v1_update_hook_parameters_t *v1_update_hook_parameters_local_var = NULL;

    // v1_update_hook_parameters->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(v1_update_hook_parametersJSON, "label");
    if (cJSON_IsNull(label)) {
        label = NULL;
    }
    if (label) { 
    if(!cJSON_IsString(label) && !cJSON_IsNull(label))
    {
    goto end; //String
    }
    }

    // v1_update_hook_parameters->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(v1_update_hook_parametersJSON, "address");
    if (cJSON_IsNull(address)) {
        address = NULL;
    }
    if (address) { 
    if(!cJSON_IsString(address) && !cJSON_IsNull(address))
    {
    goto end; //String
    }
    }

    // v1_update_hook_parameters->patch
    cJSON *patch = cJSON_GetObjectItemCaseSensitive(v1_update_hook_parametersJSON, "patch");
    if (cJSON_IsNull(patch)) {
        patch = NULL;
    }
    if (patch) { 
    if(!cJSON_IsString(patch) && !cJSON_IsNull(patch))
    {
    goto end; //String
    }
    }

    // v1_update_hook_parameters->patch_type
    cJSON *patch_type = cJSON_GetObjectItemCaseSensitive(v1_update_hook_parametersJSON, "patchType");
    if (cJSON_IsNull(patch_type)) {
        patch_type = NULL;
    }
    corellium_api_v1_update_hook_parameters_PATCHTYPE_e patch_typeVariable;
    if (patch_type) { 
    if(!cJSON_IsString(patch_type))
    {
    goto end; //Enum
    }
    patch_typeVariable = v1_update_hook_parameters_patch_type_FromString(patch_type->valuestring);
    }

    // v1_update_hook_parameters->enabled
    cJSON *enabled = cJSON_GetObjectItemCaseSensitive(v1_update_hook_parametersJSON, "enabled");
    if (cJSON_IsNull(enabled)) {
        enabled = NULL;
    }
    if (enabled) { 
    if(!cJSON_IsBool(enabled))
    {
    goto end; //Bool
    }
    }


    v1_update_hook_parameters_local_var = v1_update_hook_parameters_create_internal (
        label && !cJSON_IsNull(label) ? strdup(label->valuestring) : NULL,
        address && !cJSON_IsNull(address) ? strdup(address->valuestring) : NULL,
        patch && !cJSON_IsNull(patch) ? strdup(patch->valuestring) : NULL,
        patch_type ? patch_typeVariable : corellium_api_v1_update_hook_parameters_PATCHTYPE_NULL,
        enabled ? enabled->valueint : 0
        );

    return v1_update_hook_parameters_local_var;
end:
    return NULL;

}
