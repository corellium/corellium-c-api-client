#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "firmware_device.h"



static firmware_device_t *firmware_device_create_internal(
    char *type,
    char *model,
    char *name,
    char *platform,
    char *hw_model,
    char *bdid,
    char *cpid,
    char *created_at,
    char *updated_at
    ) {
    firmware_device_t *firmware_device_local_var = malloc(sizeof(firmware_device_t));
    if (!firmware_device_local_var) {
        return NULL;
    }
    firmware_device_local_var->type = type;
    firmware_device_local_var->model = model;
    firmware_device_local_var->name = name;
    firmware_device_local_var->platform = platform;
    firmware_device_local_var->hw_model = hw_model;
    firmware_device_local_var->bdid = bdid;
    firmware_device_local_var->cpid = cpid;
    firmware_device_local_var->created_at = created_at;
    firmware_device_local_var->updated_at = updated_at;

    firmware_device_local_var->_library_owned = 1;
    return firmware_device_local_var;
}

__attribute__((deprecated)) firmware_device_t *firmware_device_create(
    char *type,
    char *model,
    char *name,
    char *platform,
    char *hw_model,
    char *bdid,
    char *cpid,
    char *created_at,
    char *updated_at
    ) {
    return firmware_device_create_internal (
        type,
        model,
        name,
        platform,
        hw_model,
        bdid,
        cpid,
        created_at,
        updated_at
        );
}

void firmware_device_free(firmware_device_t *firmware_device) {
    if(NULL == firmware_device){
        return ;
    }
    if(firmware_device->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "firmware_device_free");
        return ;
    }
    listEntry_t *listEntry;
    if (firmware_device->type) {
        free(firmware_device->type);
        firmware_device->type = NULL;
    }
    if (firmware_device->model) {
        free(firmware_device->model);
        firmware_device->model = NULL;
    }
    if (firmware_device->name) {
        free(firmware_device->name);
        firmware_device->name = NULL;
    }
    if (firmware_device->platform) {
        free(firmware_device->platform);
        firmware_device->platform = NULL;
    }
    if (firmware_device->hw_model) {
        free(firmware_device->hw_model);
        firmware_device->hw_model = NULL;
    }
    if (firmware_device->bdid) {
        free(firmware_device->bdid);
        firmware_device->bdid = NULL;
    }
    if (firmware_device->cpid) {
        free(firmware_device->cpid);
        firmware_device->cpid = NULL;
    }
    if (firmware_device->created_at) {
        free(firmware_device->created_at);
        firmware_device->created_at = NULL;
    }
    if (firmware_device->updated_at) {
        free(firmware_device->updated_at);
        firmware_device->updated_at = NULL;
    }
    free(firmware_device);
}

cJSON *firmware_device_convertToJSON(firmware_device_t *firmware_device) {
    cJSON *item = cJSON_CreateObject();

    // firmware_device->type
    if(firmware_device->type) {
    if(cJSON_AddStringToObject(item, "type", firmware_device->type) == NULL) {
    goto fail; //String
    }
    }


    // firmware_device->model
    if (!firmware_device->model) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "model", firmware_device->model) == NULL) {
    goto fail; //String
    }


    // firmware_device->name
    if (!firmware_device->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", firmware_device->name) == NULL) {
    goto fail; //String
    }


    // firmware_device->platform
    if(firmware_device->platform) {
    if(cJSON_AddStringToObject(item, "platform", firmware_device->platform) == NULL) {
    goto fail; //String
    }
    }


    // firmware_device->hw_model
    if(firmware_device->hw_model) {
    if(cJSON_AddStringToObject(item, "hwModel", firmware_device->hw_model) == NULL) {
    goto fail; //String
    }
    }


    // firmware_device->bdid
    if(firmware_device->bdid) {
    if(cJSON_AddStringToObject(item, "bdid", firmware_device->bdid) == NULL) {
    goto fail; //String
    }
    }


    // firmware_device->cpid
    if(firmware_device->cpid) {
    if(cJSON_AddStringToObject(item, "cpid", firmware_device->cpid) == NULL) {
    goto fail; //String
    }
    }


    // firmware_device->created_at
    if(firmware_device->created_at) {
    if(cJSON_AddStringToObject(item, "createdAt", firmware_device->created_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // firmware_device->updated_at
    if(firmware_device->updated_at) {
    if(cJSON_AddStringToObject(item, "updatedAt", firmware_device->updated_at) == NULL) {
    goto fail; //Date-Time
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

firmware_device_t *firmware_device_parseFromJSON(cJSON *firmware_deviceJSON){

    firmware_device_t *firmware_device_local_var = NULL;

    // firmware_device->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(firmware_deviceJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (type) { 
    if(!cJSON_IsString(type) && !cJSON_IsNull(type))
    {
    goto end; //String
    }
    }

    // firmware_device->model
    cJSON *model = cJSON_GetObjectItemCaseSensitive(firmware_deviceJSON, "model");
    if (cJSON_IsNull(model)) {
        model = NULL;
    }
    if (!model) {
        goto end;
    }

    
    if(!cJSON_IsString(model))
    {
    goto end; //String
    }

    // firmware_device->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(firmware_deviceJSON, "name");
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

    // firmware_device->platform
    cJSON *platform = cJSON_GetObjectItemCaseSensitive(firmware_deviceJSON, "platform");
    if (cJSON_IsNull(platform)) {
        platform = NULL;
    }
    if (platform) { 
    if(!cJSON_IsString(platform) && !cJSON_IsNull(platform))
    {
    goto end; //String
    }
    }

    // firmware_device->hw_model
    cJSON *hw_model = cJSON_GetObjectItemCaseSensitive(firmware_deviceJSON, "hwModel");
    if (cJSON_IsNull(hw_model)) {
        hw_model = NULL;
    }
    if (hw_model) { 
    if(!cJSON_IsString(hw_model) && !cJSON_IsNull(hw_model))
    {
    goto end; //String
    }
    }

    // firmware_device->bdid
    cJSON *bdid = cJSON_GetObjectItemCaseSensitive(firmware_deviceJSON, "bdid");
    if (cJSON_IsNull(bdid)) {
        bdid = NULL;
    }
    if (bdid) { 
    if(!cJSON_IsString(bdid) && !cJSON_IsNull(bdid))
    {
    goto end; //String
    }
    }

    // firmware_device->cpid
    cJSON *cpid = cJSON_GetObjectItemCaseSensitive(firmware_deviceJSON, "cpid");
    if (cJSON_IsNull(cpid)) {
        cpid = NULL;
    }
    if (cpid) { 
    if(!cJSON_IsString(cpid) && !cJSON_IsNull(cpid))
    {
    goto end; //String
    }
    }

    // firmware_device->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(firmware_deviceJSON, "createdAt");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (created_at) { 
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //DateTime
    }
    }

    // firmware_device->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(firmware_deviceJSON, "updatedAt");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (updated_at) { 
    if(!cJSON_IsString(updated_at) && !cJSON_IsNull(updated_at))
    {
    goto end; //DateTime
    }
    }


    firmware_device_local_var = firmware_device_create_internal (
        type && !cJSON_IsNull(type) ? strdup(type->valuestring) : NULL,
        strdup(model->valuestring),
        strdup(name->valuestring),
        platform && !cJSON_IsNull(platform) ? strdup(platform->valuestring) : NULL,
        hw_model && !cJSON_IsNull(hw_model) ? strdup(hw_model->valuestring) : NULL,
        bdid && !cJSON_IsNull(bdid) ? strdup(bdid->valuestring) : NULL,
        cpid && !cJSON_IsNull(cpid) ? strdup(cpid->valuestring) : NULL,
        created_at && !cJSON_IsNull(created_at) ? strdup(created_at->valuestring) : NULL,
        updated_at && !cJSON_IsNull(updated_at) ? strdup(updated_at->valuestring) : NULL
        );

    return firmware_device_local_var;
end:
    return NULL;

}
