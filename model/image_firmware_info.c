#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "image_firmware_info.h"



static image_firmware_info_t *image_firmware_info_create_internal(
    char *type,
    char *version,
    char *build_id,
    list_t *device_ids,
    char *board_config,
    double bdid,
    double cpid,
    char *platform,
    image_firmware_info_boot_args_t *boot_args,
    list_t *variants,
    firmware_info_device_t *device
    ) {
    image_firmware_info_t *image_firmware_info_local_var = malloc(sizeof(image_firmware_info_t));
    if (!image_firmware_info_local_var) {
        return NULL;
    }
    image_firmware_info_local_var->type = type;
    image_firmware_info_local_var->version = version;
    image_firmware_info_local_var->build_id = build_id;
    image_firmware_info_local_var->device_ids = device_ids;
    image_firmware_info_local_var->board_config = board_config;
    image_firmware_info_local_var->bdid = bdid;
    image_firmware_info_local_var->cpid = cpid;
    image_firmware_info_local_var->platform = platform;
    image_firmware_info_local_var->boot_args = boot_args;
    image_firmware_info_local_var->variants = variants;
    image_firmware_info_local_var->device = device;

    image_firmware_info_local_var->_library_owned = 1;
    return image_firmware_info_local_var;
}

__attribute__((deprecated)) image_firmware_info_t *image_firmware_info_create(
    char *type,
    char *version,
    char *build_id,
    list_t *device_ids,
    char *board_config,
    double bdid,
    double cpid,
    char *platform,
    image_firmware_info_boot_args_t *boot_args,
    list_t *variants,
    firmware_info_device_t *device
    ) {
    return image_firmware_info_create_internal (
        type,
        version,
        build_id,
        device_ids,
        board_config,
        bdid,
        cpid,
        platform,
        boot_args,
        variants,
        device
        );
}

void image_firmware_info_free(image_firmware_info_t *image_firmware_info) {
    if(NULL == image_firmware_info){
        return ;
    }
    if(image_firmware_info->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "image_firmware_info_free");
        return ;
    }
    listEntry_t *listEntry;
    if (image_firmware_info->type) {
        free(image_firmware_info->type);
        image_firmware_info->type = NULL;
    }
    if (image_firmware_info->version) {
        free(image_firmware_info->version);
        image_firmware_info->version = NULL;
    }
    if (image_firmware_info->build_id) {
        free(image_firmware_info->build_id);
        image_firmware_info->build_id = NULL;
    }
    if (image_firmware_info->device_ids) {
        list_ForEach(listEntry, image_firmware_info->device_ids) {
            free(listEntry->data);
        }
        list_freeList(image_firmware_info->device_ids);
        image_firmware_info->device_ids = NULL;
    }
    if (image_firmware_info->board_config) {
        free(image_firmware_info->board_config);
        image_firmware_info->board_config = NULL;
    }
    if (image_firmware_info->platform) {
        free(image_firmware_info->platform);
        image_firmware_info->platform = NULL;
    }
    if (image_firmware_info->boot_args) {
        image_firmware_info_boot_args_free(image_firmware_info->boot_args);
        image_firmware_info->boot_args = NULL;
    }
    if (image_firmware_info->variants) {
        list_ForEach(listEntry, image_firmware_info->variants) {
            free(listEntry->data);
        }
        list_freeList(image_firmware_info->variants);
        image_firmware_info->variants = NULL;
    }
    if (image_firmware_info->device) {
        firmware_info_device_free(image_firmware_info->device);
        image_firmware_info->device = NULL;
    }
    free(image_firmware_info);
}

cJSON *image_firmware_info_convertToJSON(image_firmware_info_t *image_firmware_info) {
    cJSON *item = cJSON_CreateObject();

    // image_firmware_info->type
    if(image_firmware_info->type) {
    if(cJSON_AddStringToObject(item, "type", image_firmware_info->type) == NULL) {
    goto fail; //String
    }
    }


    // image_firmware_info->version
    if(image_firmware_info->version) {
    if(cJSON_AddStringToObject(item, "version", image_firmware_info->version) == NULL) {
    goto fail; //String
    }
    }


    // image_firmware_info->build_id
    if(image_firmware_info->build_id) {
    if(cJSON_AddStringToObject(item, "buildId", image_firmware_info->build_id) == NULL) {
    goto fail; //String
    }
    }


    // image_firmware_info->device_ids
    if(image_firmware_info->device_ids) {
    cJSON *device_ids = cJSON_AddArrayToObject(item, "deviceIds");
    if(device_ids == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *device_idsListEntry;
    list_ForEach(device_idsListEntry, image_firmware_info->device_ids) {
    if(cJSON_AddStringToObject(device_ids, "", device_idsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // image_firmware_info->board_config
    if(image_firmware_info->board_config) {
    if(cJSON_AddStringToObject(item, "boardConfig", image_firmware_info->board_config) == NULL) {
    goto fail; //String
    }
    }


    // image_firmware_info->bdid
    if(image_firmware_info->bdid) {
    if(cJSON_AddNumberToObject(item, "bdid", image_firmware_info->bdid) == NULL) {
    goto fail; //Numeric
    }
    }


    // image_firmware_info->cpid
    if(image_firmware_info->cpid) {
    if(cJSON_AddNumberToObject(item, "cpid", image_firmware_info->cpid) == NULL) {
    goto fail; //Numeric
    }
    }


    // image_firmware_info->platform
    if(image_firmware_info->platform) {
    if(cJSON_AddStringToObject(item, "platform", image_firmware_info->platform) == NULL) {
    goto fail; //String
    }
    }


    // image_firmware_info->boot_args
    if(image_firmware_info->boot_args) {
    cJSON *boot_args_local_JSON = image_firmware_info_boot_args_convertToJSON(image_firmware_info->boot_args);
    if(boot_args_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "bootArgs", boot_args_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // image_firmware_info->variants
    if(image_firmware_info->variants) {
    cJSON *variants = cJSON_AddArrayToObject(item, "variants");
    if(variants == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *variantsListEntry;
    list_ForEach(variantsListEntry, image_firmware_info->variants) {
    if(cJSON_AddStringToObject(variants, "", variantsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // image_firmware_info->device
    if(image_firmware_info->device) {
    cJSON *device_local_JSON = firmware_info_device_convertToJSON(image_firmware_info->device);
    if(device_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "device", device_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

image_firmware_info_t *image_firmware_info_parseFromJSON(cJSON *image_firmware_infoJSON){

    image_firmware_info_t *image_firmware_info_local_var = NULL;

    // define the local list for image_firmware_info->device_ids
    list_t *device_idsList = NULL;

    // define the local variable for image_firmware_info->boot_args
    image_firmware_info_boot_args_t *boot_args_local_nonprim = NULL;

    // define the local list for image_firmware_info->variants
    list_t *variantsList = NULL;

    // define the local variable for image_firmware_info->device
    firmware_info_device_t *device_local_nonprim = NULL;

    // image_firmware_info->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(image_firmware_infoJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (type) { 
    if(!cJSON_IsString(type) && !cJSON_IsNull(type))
    {
    goto end; //String
    }
    }

    // image_firmware_info->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(image_firmware_infoJSON, "version");
    if (cJSON_IsNull(version)) {
        version = NULL;
    }
    if (version) { 
    if(!cJSON_IsString(version) && !cJSON_IsNull(version))
    {
    goto end; //String
    }
    }

    // image_firmware_info->build_id
    cJSON *build_id = cJSON_GetObjectItemCaseSensitive(image_firmware_infoJSON, "buildId");
    if (cJSON_IsNull(build_id)) {
        build_id = NULL;
    }
    if (build_id) { 
    if(!cJSON_IsString(build_id) && !cJSON_IsNull(build_id))
    {
    goto end; //String
    }
    }

    // image_firmware_info->device_ids
    cJSON *device_ids = cJSON_GetObjectItemCaseSensitive(image_firmware_infoJSON, "deviceIds");
    if (cJSON_IsNull(device_ids)) {
        device_ids = NULL;
    }
    if (device_ids) { 
    cJSON *device_ids_local = NULL;
    if(!cJSON_IsArray(device_ids)) {
        goto end;//primitive container
    }
    device_idsList = list_createList();

    cJSON_ArrayForEach(device_ids_local, device_ids)
    {
        if(!cJSON_IsString(device_ids_local))
        {
            goto end;
        }
        list_addElement(device_idsList , strdup(device_ids_local->valuestring));
    }
    }

    // image_firmware_info->board_config
    cJSON *board_config = cJSON_GetObjectItemCaseSensitive(image_firmware_infoJSON, "boardConfig");
    if (cJSON_IsNull(board_config)) {
        board_config = NULL;
    }
    if (board_config) { 
    if(!cJSON_IsString(board_config) && !cJSON_IsNull(board_config))
    {
    goto end; //String
    }
    }

    // image_firmware_info->bdid
    cJSON *bdid = cJSON_GetObjectItemCaseSensitive(image_firmware_infoJSON, "bdid");
    if (cJSON_IsNull(bdid)) {
        bdid = NULL;
    }
    if (bdid) { 
    if(!cJSON_IsNumber(bdid))
    {
    goto end; //Numeric
    }
    }

    // image_firmware_info->cpid
    cJSON *cpid = cJSON_GetObjectItemCaseSensitive(image_firmware_infoJSON, "cpid");
    if (cJSON_IsNull(cpid)) {
        cpid = NULL;
    }
    if (cpid) { 
    if(!cJSON_IsNumber(cpid))
    {
    goto end; //Numeric
    }
    }

    // image_firmware_info->platform
    cJSON *platform = cJSON_GetObjectItemCaseSensitive(image_firmware_infoJSON, "platform");
    if (cJSON_IsNull(platform)) {
        platform = NULL;
    }
    if (platform) { 
    if(!cJSON_IsString(platform) && !cJSON_IsNull(platform))
    {
    goto end; //String
    }
    }

    // image_firmware_info->boot_args
    cJSON *boot_args = cJSON_GetObjectItemCaseSensitive(image_firmware_infoJSON, "bootArgs");
    if (cJSON_IsNull(boot_args)) {
        boot_args = NULL;
    }
    if (boot_args) { 
    boot_args_local_nonprim = image_firmware_info_boot_args_parseFromJSON(boot_args); //nonprimitive
    }

    // image_firmware_info->variants
    cJSON *variants = cJSON_GetObjectItemCaseSensitive(image_firmware_infoJSON, "variants");
    if (cJSON_IsNull(variants)) {
        variants = NULL;
    }
    if (variants) { 
    cJSON *variants_local = NULL;
    if(!cJSON_IsArray(variants)) {
        goto end;//primitive container
    }
    variantsList = list_createList();

    cJSON_ArrayForEach(variants_local, variants)
    {
        if(!cJSON_IsString(variants_local))
        {
            goto end;
        }
        list_addElement(variantsList , strdup(variants_local->valuestring));
    }
    }

    // image_firmware_info->device
    cJSON *device = cJSON_GetObjectItemCaseSensitive(image_firmware_infoJSON, "device");
    if (cJSON_IsNull(device)) {
        device = NULL;
    }
    if (device) { 
    device_local_nonprim = firmware_info_device_parseFromJSON(device); //nonprimitive
    }


    image_firmware_info_local_var = image_firmware_info_create_internal (
        type && !cJSON_IsNull(type) ? strdup(type->valuestring) : NULL,
        version && !cJSON_IsNull(version) ? strdup(version->valuestring) : NULL,
        build_id && !cJSON_IsNull(build_id) ? strdup(build_id->valuestring) : NULL,
        device_ids ? device_idsList : NULL,
        board_config && !cJSON_IsNull(board_config) ? strdup(board_config->valuestring) : NULL,
        bdid ? bdid->valuedouble : 0,
        cpid ? cpid->valuedouble : 0,
        platform && !cJSON_IsNull(platform) ? strdup(platform->valuestring) : NULL,
        boot_args ? boot_args_local_nonprim : NULL,
        variants ? variantsList : NULL,
        device ? device_local_nonprim : NULL
        );

    return image_firmware_info_local_var;
end:
    if (device_idsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, device_idsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(device_idsList);
        device_idsList = NULL;
    }
    if (boot_args_local_nonprim) {
        image_firmware_info_boot_args_free(boot_args_local_nonprim);
        boot_args_local_nonprim = NULL;
    }
    if (variantsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, variantsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(variantsList);
        variantsList = NULL;
    }
    if (device_local_nonprim) {
        firmware_info_device_free(device_local_nonprim);
        device_local_nonprim = NULL;
    }
    return NULL;

}
