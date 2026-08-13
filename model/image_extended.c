#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "image_extended.h"



static image_extended_t *image_extended_create_internal(
    char *type,
    char *version,
    char *buildid,
    list_t *device_ids,
    char *board_config,
    image_extended_device_t *device
    ) {
    image_extended_t *image_extended_local_var = malloc(sizeof(image_extended_t));
    if (!image_extended_local_var) {
        return NULL;
    }
    image_extended_local_var->type = type;
    image_extended_local_var->version = version;
    image_extended_local_var->buildid = buildid;
    image_extended_local_var->device_ids = device_ids;
    image_extended_local_var->board_config = board_config;
    image_extended_local_var->device = device;

    image_extended_local_var->_library_owned = 1;
    return image_extended_local_var;
}

__attribute__((deprecated)) image_extended_t *image_extended_create(
    char *type,
    char *version,
    char *buildid,
    list_t *device_ids,
    char *board_config,
    image_extended_device_t *device
    ) {
    return image_extended_create_internal (
        type,
        version,
        buildid,
        device_ids,
        board_config,
        device
        );
}

void image_extended_free(image_extended_t *image_extended) {
    if(NULL == image_extended){
        return ;
    }
    if(image_extended->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "image_extended_free");
        return ;
    }
    listEntry_t *listEntry;
    if (image_extended->type) {
        free(image_extended->type);
        image_extended->type = NULL;
    }
    if (image_extended->version) {
        free(image_extended->version);
        image_extended->version = NULL;
    }
    if (image_extended->buildid) {
        free(image_extended->buildid);
        image_extended->buildid = NULL;
    }
    if (image_extended->device_ids) {
        list_ForEach(listEntry, image_extended->device_ids) {
            free(listEntry->data);
        }
        list_freeList(image_extended->device_ids);
        image_extended->device_ids = NULL;
    }
    if (image_extended->board_config) {
        free(image_extended->board_config);
        image_extended->board_config = NULL;
    }
    if (image_extended->device) {
        image_extended_device_free(image_extended->device);
        image_extended->device = NULL;
    }
    free(image_extended);
}

cJSON *image_extended_convertToJSON(image_extended_t *image_extended) {
    cJSON *item = cJSON_CreateObject();

    // image_extended->type
    if(image_extended->type) {
    if(cJSON_AddStringToObject(item, "type", image_extended->type) == NULL) {
    goto fail; //String
    }
    }


    // image_extended->version
    if(image_extended->version) {
    if(cJSON_AddStringToObject(item, "version", image_extended->version) == NULL) {
    goto fail; //String
    }
    }


    // image_extended->buildid
    if(image_extended->buildid) {
    if(cJSON_AddStringToObject(item, "buildid", image_extended->buildid) == NULL) {
    goto fail; //String
    }
    }


    // image_extended->device_ids
    if(image_extended->device_ids) {
    cJSON *device_ids = cJSON_AddArrayToObject(item, "deviceIds");
    if(device_ids == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *device_idsListEntry;
    list_ForEach(device_idsListEntry, image_extended->device_ids) {
    if(cJSON_AddStringToObject(device_ids, "", device_idsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // image_extended->board_config
    if(image_extended->board_config) {
    if(cJSON_AddStringToObject(item, "boardConfig", image_extended->board_config) == NULL) {
    goto fail; //String
    }
    }


    // image_extended->device
    if(image_extended->device) {
    cJSON *device_local_JSON = image_extended_device_convertToJSON(image_extended->device);
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

image_extended_t *image_extended_parseFromJSON(cJSON *image_extendedJSON){

    image_extended_t *image_extended_local_var = NULL;

    // define the local list for image_extended->device_ids
    list_t *device_idsList = NULL;

    // define the local variable for image_extended->device
    image_extended_device_t *device_local_nonprim = NULL;

    // image_extended->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(image_extendedJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (type) { 
    if(!cJSON_IsString(type) && !cJSON_IsNull(type))
    {
    goto end; //String
    }
    }

    // image_extended->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(image_extendedJSON, "version");
    if (cJSON_IsNull(version)) {
        version = NULL;
    }
    if (version) { 
    if(!cJSON_IsString(version) && !cJSON_IsNull(version))
    {
    goto end; //String
    }
    }

    // image_extended->buildid
    cJSON *buildid = cJSON_GetObjectItemCaseSensitive(image_extendedJSON, "buildid");
    if (cJSON_IsNull(buildid)) {
        buildid = NULL;
    }
    if (buildid) { 
    if(!cJSON_IsString(buildid) && !cJSON_IsNull(buildid))
    {
    goto end; //String
    }
    }

    // image_extended->device_ids
    cJSON *device_ids = cJSON_GetObjectItemCaseSensitive(image_extendedJSON, "deviceIds");
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

    // image_extended->board_config
    cJSON *board_config = cJSON_GetObjectItemCaseSensitive(image_extendedJSON, "boardConfig");
    if (cJSON_IsNull(board_config)) {
        board_config = NULL;
    }
    if (board_config) { 
    if(!cJSON_IsString(board_config) && !cJSON_IsNull(board_config))
    {
    goto end; //String
    }
    }

    // image_extended->device
    cJSON *device = cJSON_GetObjectItemCaseSensitive(image_extendedJSON, "device");
    if (cJSON_IsNull(device)) {
        device = NULL;
    }
    if (device) { 
    device_local_nonprim = image_extended_device_parseFromJSON(device); //nonprimitive
    }


    image_extended_local_var = image_extended_create_internal (
        type && !cJSON_IsNull(type) ? strdup(type->valuestring) : NULL,
        version && !cJSON_IsNull(version) ? strdup(version->valuestring) : NULL,
        buildid && !cJSON_IsNull(buildid) ? strdup(buildid->valuestring) : NULL,
        device_ids ? device_idsList : NULL,
        board_config && !cJSON_IsNull(board_config) ? strdup(board_config->valuestring) : NULL,
        device ? device_local_nonprim : NULL
        );

    return image_extended_local_var;
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
    if (device_local_nonprim) {
        image_extended_device_free(device_local_nonprim);
        device_local_nonprim = NULL;
    }
    return NULL;

}
