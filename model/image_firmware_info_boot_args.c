#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "image_firmware_info_boot_args.h"



static image_firmware_info_boot_args_t *image_firmware_info_boot_args_create_internal(
    char *normal,
    char *restore
    ) {
    image_firmware_info_boot_args_t *image_firmware_info_boot_args_local_var = malloc(sizeof(image_firmware_info_boot_args_t));
    if (!image_firmware_info_boot_args_local_var) {
        return NULL;
    }
    image_firmware_info_boot_args_local_var->normal = normal;
    image_firmware_info_boot_args_local_var->restore = restore;

    image_firmware_info_boot_args_local_var->_library_owned = 1;
    return image_firmware_info_boot_args_local_var;
}

__attribute__((deprecated)) image_firmware_info_boot_args_t *image_firmware_info_boot_args_create(
    char *normal,
    char *restore
    ) {
    return image_firmware_info_boot_args_create_internal (
        normal,
        restore
        );
}

void image_firmware_info_boot_args_free(image_firmware_info_boot_args_t *image_firmware_info_boot_args) {
    if(NULL == image_firmware_info_boot_args){
        return ;
    }
    if(image_firmware_info_boot_args->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "image_firmware_info_boot_args_free");
        return ;
    }
    listEntry_t *listEntry;
    if (image_firmware_info_boot_args->normal) {
        free(image_firmware_info_boot_args->normal);
        image_firmware_info_boot_args->normal = NULL;
    }
    if (image_firmware_info_boot_args->restore) {
        free(image_firmware_info_boot_args->restore);
        image_firmware_info_boot_args->restore = NULL;
    }
    free(image_firmware_info_boot_args);
}

cJSON *image_firmware_info_boot_args_convertToJSON(image_firmware_info_boot_args_t *image_firmware_info_boot_args) {
    cJSON *item = cJSON_CreateObject();

    // image_firmware_info_boot_args->normal
    if(image_firmware_info_boot_args->normal) {
    if(cJSON_AddStringToObject(item, "normal", image_firmware_info_boot_args->normal) == NULL) {
    goto fail; //String
    }
    }


    // image_firmware_info_boot_args->restore
    if(image_firmware_info_boot_args->restore) {
    if(cJSON_AddStringToObject(item, "restore", image_firmware_info_boot_args->restore) == NULL) {
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

image_firmware_info_boot_args_t *image_firmware_info_boot_args_parseFromJSON(cJSON *image_firmware_info_boot_argsJSON){

    image_firmware_info_boot_args_t *image_firmware_info_boot_args_local_var = NULL;

    // image_firmware_info_boot_args->normal
    cJSON *normal = cJSON_GetObjectItemCaseSensitive(image_firmware_info_boot_argsJSON, "normal");
    if (cJSON_IsNull(normal)) {
        normal = NULL;
    }
    if (normal) { 
    if(!cJSON_IsString(normal) && !cJSON_IsNull(normal))
    {
    goto end; //String
    }
    }

    // image_firmware_info_boot_args->restore
    cJSON *restore = cJSON_GetObjectItemCaseSensitive(image_firmware_info_boot_argsJSON, "restore");
    if (cJSON_IsNull(restore)) {
        restore = NULL;
    }
    if (restore) { 
    if(!cJSON_IsString(restore) && !cJSON_IsNull(restore))
    {
    goto end; //String
    }
    }


    image_firmware_info_boot_args_local_var = image_firmware_info_boot_args_create_internal (
        normal && !cJSON_IsNull(normal) ? strdup(normal->valuestring) : NULL,
        restore && !cJSON_IsNull(restore) ? strdup(restore->valuestring) : NULL
        );

    return image_firmware_info_boot_args_local_var;
end:
    return NULL;

}
