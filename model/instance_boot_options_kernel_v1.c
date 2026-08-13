#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "instance_boot_options_kernel_v1.h"



static instance_boot_options_kernel_v1_t *instance_boot_options_kernel_v1_create_internal(
    char *firmware_path
    ) {
    instance_boot_options_kernel_v1_t *instance_boot_options_kernel_v1_local_var = malloc(sizeof(instance_boot_options_kernel_v1_t));
    if (!instance_boot_options_kernel_v1_local_var) {
        return NULL;
    }
    instance_boot_options_kernel_v1_local_var->firmware_path = firmware_path;

    instance_boot_options_kernel_v1_local_var->_library_owned = 1;
    return instance_boot_options_kernel_v1_local_var;
}

__attribute__((deprecated)) instance_boot_options_kernel_v1_t *instance_boot_options_kernel_v1_create(
    char *firmware_path
    ) {
    return instance_boot_options_kernel_v1_create_internal (
        firmware_path
        );
}

void instance_boot_options_kernel_v1_free(instance_boot_options_kernel_v1_t *instance_boot_options_kernel_v1) {
    if(NULL == instance_boot_options_kernel_v1){
        return ;
    }
    if(instance_boot_options_kernel_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "instance_boot_options_kernel_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (instance_boot_options_kernel_v1->firmware_path) {
        free(instance_boot_options_kernel_v1->firmware_path);
        instance_boot_options_kernel_v1->firmware_path = NULL;
    }
    free(instance_boot_options_kernel_v1);
}

cJSON *instance_boot_options_kernel_v1_convertToJSON(instance_boot_options_kernel_v1_t *instance_boot_options_kernel_v1) {
    cJSON *item = cJSON_CreateObject();

    // instance_boot_options_kernel_v1->firmware_path
    if(instance_boot_options_kernel_v1->firmware_path) {
    if(cJSON_AddStringToObject(item, "firmwarePath", instance_boot_options_kernel_v1->firmware_path) == NULL) {
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

instance_boot_options_kernel_v1_t *instance_boot_options_kernel_v1_parseFromJSON(cJSON *instance_boot_options_kernel_v1JSON){

    instance_boot_options_kernel_v1_t *instance_boot_options_kernel_v1_local_var = NULL;

    // instance_boot_options_kernel_v1->firmware_path
    cJSON *firmware_path = cJSON_GetObjectItemCaseSensitive(instance_boot_options_kernel_v1JSON, "firmwarePath");
    if (cJSON_IsNull(firmware_path)) {
        firmware_path = NULL;
    }
    if (firmware_path) { 
    if(!cJSON_IsString(firmware_path) && !cJSON_IsNull(firmware_path))
    {
    goto end; //String
    }
    }


    instance_boot_options_kernel_v1_local_var = instance_boot_options_kernel_v1_create_internal (
        firmware_path && !cJSON_IsNull(firmware_path) ? strdup(firmware_path->valuestring) : NULL
        );

    return instance_boot_options_kernel_v1_local_var;
end:
    return NULL;

}
