#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "instance_boot_options_kernel.h"



static instance_boot_options_kernel_t *instance_boot_options_kernel_create_internal(
    char *firmware_path
    ) {
    instance_boot_options_kernel_t *instance_boot_options_kernel_local_var = malloc(sizeof(instance_boot_options_kernel_t));
    if (!instance_boot_options_kernel_local_var) {
        return NULL;
    }
    instance_boot_options_kernel_local_var->firmware_path = firmware_path;

    instance_boot_options_kernel_local_var->_library_owned = 1;
    return instance_boot_options_kernel_local_var;
}

__attribute__((deprecated)) instance_boot_options_kernel_t *instance_boot_options_kernel_create(
    char *firmware_path
    ) {
    return instance_boot_options_kernel_create_internal (
        firmware_path
        );
}

void instance_boot_options_kernel_free(instance_boot_options_kernel_t *instance_boot_options_kernel) {
    if(NULL == instance_boot_options_kernel){
        return ;
    }
    if(instance_boot_options_kernel->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "instance_boot_options_kernel_free");
        return ;
    }
    listEntry_t *listEntry;
    if (instance_boot_options_kernel->firmware_path) {
        free(instance_boot_options_kernel->firmware_path);
        instance_boot_options_kernel->firmware_path = NULL;
    }
    free(instance_boot_options_kernel);
}

cJSON *instance_boot_options_kernel_convertToJSON(instance_boot_options_kernel_t *instance_boot_options_kernel) {
    cJSON *item = cJSON_CreateObject();

    // instance_boot_options_kernel->firmware_path
    if (!instance_boot_options_kernel->firmware_path) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "firmwarePath", instance_boot_options_kernel->firmware_path) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

instance_boot_options_kernel_t *instance_boot_options_kernel_parseFromJSON(cJSON *instance_boot_options_kernelJSON){

    instance_boot_options_kernel_t *instance_boot_options_kernel_local_var = NULL;

    // instance_boot_options_kernel->firmware_path
    cJSON *firmware_path = cJSON_GetObjectItemCaseSensitive(instance_boot_options_kernelJSON, "firmwarePath");
    if (cJSON_IsNull(firmware_path)) {
        firmware_path = NULL;
    }
    if (!firmware_path) {
        goto end;
    }

    
    if(!cJSON_IsString(firmware_path))
    {
    goto end; //String
    }


    instance_boot_options_kernel_local_var = instance_boot_options_kernel_create_internal (
        strdup(firmware_path->valuestring)
        );

    return instance_boot_options_kernel_local_var;
end:
    return NULL;

}
