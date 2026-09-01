#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hook_patch_type.h"


char* hook_patch_type_hook_patch_type_ToString(corellium_api_hook_patch_type__e hook_patch_type) {
    char *hook_patch_typeArray[] =  { "NULL", "csmfcc", "csmfvm" };
    return hook_patch_typeArray[hook_patch_type];
}

corellium_api_hook_patch_type__e hook_patch_type_hook_patch_type_FromString(char* hook_patch_type) {
    int stringToReturn = 0;
    char *hook_patch_typeArray[] =  { "NULL", "csmfcc", "csmfvm" };
    size_t sizeofArray = sizeof(hook_patch_typeArray) / sizeof(hook_patch_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(hook_patch_type, hook_patch_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *hook_patch_type_convertToJSON(corellium_api_hook_patch_type__e hook_patch_type) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "hook_patch_type", hook_patch_type_hook_patch_type_ToString(hook_patch_type)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

corellium_api_hook_patch_type__e hook_patch_type_parseFromJSON(cJSON *hook_patch_typeJSON) {
    if(!cJSON_IsString(hook_patch_typeJSON) || (hook_patch_typeJSON->valuestring == NULL)) {
        return 0;
    }
    return hook_patch_type_hook_patch_type_FromString(hook_patch_typeJSON->valuestring);
}
