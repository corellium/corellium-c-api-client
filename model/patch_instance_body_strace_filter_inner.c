#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "patch_instance_body_strace_filter_inner.h"


char* patch_instance_body_strace_filter_inner_trait_ToString(corellium_api_patch_instance_body_strace_filter_inner_TRAIT_e trait) {
    char* traitArray[] =  { "NULL", "name", "pid", "tid" };
    return traitArray[trait];
}

corellium_api_patch_instance_body_strace_filter_inner_TRAIT_e patch_instance_body_strace_filter_inner_trait_FromString(char* trait){
    int stringToReturn = 0;
    char *traitArray[] =  { "NULL", "name", "pid", "tid" };
    size_t sizeofArray = sizeof(traitArray) / sizeof(traitArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(trait, traitArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static patch_instance_body_strace_filter_inner_t *patch_instance_body_strace_filter_inner_create_internal(
    corellium_api_patch_instance_body_strace_filter_inner_TRAIT_e trait,
    char *value
    ) {
    patch_instance_body_strace_filter_inner_t *patch_instance_body_strace_filter_inner_local_var = malloc(sizeof(patch_instance_body_strace_filter_inner_t));
    if (!patch_instance_body_strace_filter_inner_local_var) {
        return NULL;
    }
    patch_instance_body_strace_filter_inner_local_var->trait = trait;
    patch_instance_body_strace_filter_inner_local_var->value = value;

    patch_instance_body_strace_filter_inner_local_var->_library_owned = 1;
    return patch_instance_body_strace_filter_inner_local_var;
}

__attribute__((deprecated)) patch_instance_body_strace_filter_inner_t *patch_instance_body_strace_filter_inner_create(
    corellium_api_patch_instance_body_strace_filter_inner_TRAIT_e trait,
    char *value
    ) {
    return patch_instance_body_strace_filter_inner_create_internal (
        trait,
        value
        );
}

void patch_instance_body_strace_filter_inner_free(patch_instance_body_strace_filter_inner_t *patch_instance_body_strace_filter_inner) {
    if(NULL == patch_instance_body_strace_filter_inner){
        return ;
    }
    if(patch_instance_body_strace_filter_inner->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "patch_instance_body_strace_filter_inner_free");
        return ;
    }
    listEntry_t *listEntry;
    if (patch_instance_body_strace_filter_inner->value) {
        free(patch_instance_body_strace_filter_inner->value);
        patch_instance_body_strace_filter_inner->value = NULL;
    }
    free(patch_instance_body_strace_filter_inner);
}

cJSON *patch_instance_body_strace_filter_inner_convertToJSON(patch_instance_body_strace_filter_inner_t *patch_instance_body_strace_filter_inner) {
    cJSON *item = cJSON_CreateObject();

    // patch_instance_body_strace_filter_inner->trait
    if (corellium_api_patch_instance_body_strace_filter_inner_TRAIT_NULL == patch_instance_body_strace_filter_inner->trait) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "trait", patch_instance_body_strace_filter_inner_trait_ToString(patch_instance_body_strace_filter_inner->trait)) == NULL)
    {
    goto fail; //Enum
    }


    // patch_instance_body_strace_filter_inner->value
    if (!patch_instance_body_strace_filter_inner->value) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "value", patch_instance_body_strace_filter_inner->value) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

patch_instance_body_strace_filter_inner_t *patch_instance_body_strace_filter_inner_parseFromJSON(cJSON *patch_instance_body_strace_filter_innerJSON){

    patch_instance_body_strace_filter_inner_t *patch_instance_body_strace_filter_inner_local_var = NULL;

    // patch_instance_body_strace_filter_inner->trait
    cJSON *trait = cJSON_GetObjectItemCaseSensitive(patch_instance_body_strace_filter_innerJSON, "trait");
    if (cJSON_IsNull(trait)) {
        trait = NULL;
    }
    if (!trait) {
        goto end;
    }

    corellium_api_patch_instance_body_strace_filter_inner_TRAIT_e traitVariable;
    
    if(!cJSON_IsString(trait))
    {
    goto end; //Enum
    }
    traitVariable = patch_instance_body_strace_filter_inner_trait_FromString(trait->valuestring);

    // patch_instance_body_strace_filter_inner->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(patch_instance_body_strace_filter_innerJSON, "value");
    if (cJSON_IsNull(value)) {
        value = NULL;
    }
    if (!value) {
        goto end;
    }

    
    if(!cJSON_IsString(value))
    {
    goto end; //String
    }


    patch_instance_body_strace_filter_inner_local_var = patch_instance_body_strace_filter_inner_create_internal (
        traitVariable,
        strdup(value->valuestring)
        );

    return patch_instance_body_strace_filter_inner_local_var;
end:
    return NULL;

}
