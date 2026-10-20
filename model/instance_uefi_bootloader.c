#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "instance_uefi_bootloader.h"



static instance_uefi_bootloader_t *instance_uefi_bootloader_create_internal(
    char *label,
    char *name
    ) {
    instance_uefi_bootloader_t *instance_uefi_bootloader_local_var = malloc(sizeof(instance_uefi_bootloader_t));
    if (!instance_uefi_bootloader_local_var) {
        return NULL;
    }
    instance_uefi_bootloader_local_var->label = label;
    instance_uefi_bootloader_local_var->name = name;

    instance_uefi_bootloader_local_var->_library_owned = 1;
    return instance_uefi_bootloader_local_var;
}

__attribute__((deprecated)) instance_uefi_bootloader_t *instance_uefi_bootloader_create(
    char *label,
    char *name
    ) {
    return instance_uefi_bootloader_create_internal (
        label,
        name
        );
}

void instance_uefi_bootloader_free(instance_uefi_bootloader_t *instance_uefi_bootloader) {
    if(NULL == instance_uefi_bootloader){
        return ;
    }
    if(instance_uefi_bootloader->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "instance_uefi_bootloader_free");
        return ;
    }
    listEntry_t *listEntry;
    if (instance_uefi_bootloader->label) {
        free(instance_uefi_bootloader->label);
        instance_uefi_bootloader->label = NULL;
    }
    if (instance_uefi_bootloader->name) {
        free(instance_uefi_bootloader->name);
        instance_uefi_bootloader->name = NULL;
    }
    free(instance_uefi_bootloader);
}

cJSON *instance_uefi_bootloader_convertToJSON(instance_uefi_bootloader_t *instance_uefi_bootloader) {
    cJSON *item = cJSON_CreateObject();

    // instance_uefi_bootloader->label
    if (!instance_uefi_bootloader->label) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "label", instance_uefi_bootloader->label) == NULL) {
    goto fail; //String
    }


    // instance_uefi_bootloader->name
    if (!instance_uefi_bootloader->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", instance_uefi_bootloader->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

instance_uefi_bootloader_t *instance_uefi_bootloader_parseFromJSON(cJSON *instance_uefi_bootloaderJSON){

    instance_uefi_bootloader_t *instance_uefi_bootloader_local_var = NULL;

    // instance_uefi_bootloader->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(instance_uefi_bootloaderJSON, "label");
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

    // instance_uefi_bootloader->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(instance_uefi_bootloaderJSON, "name");
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


    instance_uefi_bootloader_local_var = instance_uefi_bootloader_create_internal (
        strdup(label->valuestring),
        strdup(name->valuestring)
        );

    return instance_uefi_bootloader_local_var;
end:
    return NULL;

}
