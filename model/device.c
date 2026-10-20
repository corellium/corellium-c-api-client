#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "device.h"



static device_t *device_create_internal(
    char *type,
    char *model,
    char *name,
    char *platform,
    char *hwmodel,
    char *bdid,
    char *cpid,
    char *created_at,
    char *updated_at
    ) {
    device_t *device_local_var = malloc(sizeof(device_t));
    if (!device_local_var) {
        return NULL;
    }
    device_local_var->type = type;
    device_local_var->model = model;
    device_local_var->name = name;
    device_local_var->platform = platform;
    device_local_var->hwmodel = hwmodel;
    device_local_var->bdid = bdid;
    device_local_var->cpid = cpid;
    device_local_var->created_at = created_at;
    device_local_var->updated_at = updated_at;

    device_local_var->_library_owned = 1;
    return device_local_var;
}

__attribute__((deprecated)) device_t *device_create(
    char *type,
    char *model,
    char *name,
    char *platform,
    char *hwmodel,
    char *bdid,
    char *cpid,
    char *created_at,
    char *updated_at
    ) {
    return device_create_internal (
        type,
        model,
        name,
        platform,
        hwmodel,
        bdid,
        cpid,
        created_at,
        updated_at
        );
}

void device_free(device_t *device) {
    if(NULL == device){
        return ;
    }
    if(device->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "device_free");
        return ;
    }
    listEntry_t *listEntry;
    if (device->type) {
        free(device->type);
        device->type = NULL;
    }
    if (device->model) {
        free(device->model);
        device->model = NULL;
    }
    if (device->name) {
        free(device->name);
        device->name = NULL;
    }
    if (device->platform) {
        free(device->platform);
        device->platform = NULL;
    }
    if (device->hwmodel) {
        free(device->hwmodel);
        device->hwmodel = NULL;
    }
    if (device->bdid) {
        free(device->bdid);
        device->bdid = NULL;
    }
    if (device->cpid) {
        free(device->cpid);
        device->cpid = NULL;
    }
    if (device->created_at) {
        free(device->created_at);
        device->created_at = NULL;
    }
    if (device->updated_at) {
        free(device->updated_at);
        device->updated_at = NULL;
    }
    free(device);
}

cJSON *device_convertToJSON(device_t *device) {
    cJSON *item = cJSON_CreateObject();

    // device->type
    if (!device->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", device->type) == NULL) {
    goto fail; //String
    }


    // device->model
    if (!device->model) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "model", device->model) == NULL) {
    goto fail; //String
    }


    // device->name
    if (!device->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", device->name) == NULL) {
    goto fail; //String
    }


    // device->platform
    if(device->platform) {
    if(cJSON_AddStringToObject(item, "platform", device->platform) == NULL) {
    goto fail; //String
    }
    }


    // device->hwmodel
    if(device->hwmodel) {
    if(cJSON_AddStringToObject(item, "hwmodel", device->hwmodel) == NULL) {
    goto fail; //String
    }
    }


    // device->bdid
    if(device->bdid) {
    if(cJSON_AddStringToObject(item, "bdid", device->bdid) == NULL) {
    goto fail; //String
    }
    }


    // device->cpid
    if(device->cpid) {
    if(cJSON_AddStringToObject(item, "cpid", device->cpid) == NULL) {
    goto fail; //String
    }
    }


    // device->created_at
    if(device->created_at) {
    if(cJSON_AddStringToObject(item, "createdAt", device->created_at) == NULL) {
    goto fail; //String
    }
    }


    // device->updated_at
    if(device->updated_at) {
    if(cJSON_AddStringToObject(item, "updatedAt", device->updated_at) == NULL) {
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

device_t *device_parseFromJSON(cJSON *deviceJSON){

    device_t *device_local_var = NULL;

    // device->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(deviceJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }

    // device->model
    cJSON *model = cJSON_GetObjectItemCaseSensitive(deviceJSON, "model");
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

    // device->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(deviceJSON, "name");
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

    // device->platform
    cJSON *platform = cJSON_GetObjectItemCaseSensitive(deviceJSON, "platform");
    if (cJSON_IsNull(platform)) {
        platform = NULL;
    }
    if (platform) { 
    if(!cJSON_IsString(platform) && !cJSON_IsNull(platform))
    {
    goto end; //String
    }
    }

    // device->hwmodel
    cJSON *hwmodel = cJSON_GetObjectItemCaseSensitive(deviceJSON, "hwmodel");
    if (cJSON_IsNull(hwmodel)) {
        hwmodel = NULL;
    }
    if (hwmodel) { 
    if(!cJSON_IsString(hwmodel) && !cJSON_IsNull(hwmodel))
    {
    goto end; //String
    }
    }

    // device->bdid
    cJSON *bdid = cJSON_GetObjectItemCaseSensitive(deviceJSON, "bdid");
    if (cJSON_IsNull(bdid)) {
        bdid = NULL;
    }
    if (bdid) { 
    if(!cJSON_IsString(bdid) && !cJSON_IsNull(bdid))
    {
    goto end; //String
    }
    }

    // device->cpid
    cJSON *cpid = cJSON_GetObjectItemCaseSensitive(deviceJSON, "cpid");
    if (cJSON_IsNull(cpid)) {
        cpid = NULL;
    }
    if (cpid) { 
    if(!cJSON_IsString(cpid) && !cJSON_IsNull(cpid))
    {
    goto end; //String
    }
    }

    // device->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(deviceJSON, "createdAt");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (created_at) { 
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //String
    }
    }

    // device->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(deviceJSON, "updatedAt");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (updated_at) { 
    if(!cJSON_IsString(updated_at) && !cJSON_IsNull(updated_at))
    {
    goto end; //String
    }
    }


    device_local_var = device_create_internal (
        strdup(type->valuestring),
        strdup(model->valuestring),
        strdup(name->valuestring),
        platform && !cJSON_IsNull(platform) ? strdup(platform->valuestring) : NULL,
        hwmodel && !cJSON_IsNull(hwmodel) ? strdup(hwmodel->valuestring) : NULL,
        bdid && !cJSON_IsNull(bdid) ? strdup(bdid->valuestring) : NULL,
        cpid && !cJSON_IsNull(cpid) ? strdup(cpid->valuestring) : NULL,
        created_at && !cJSON_IsNull(created_at) ? strdup(created_at->valuestring) : NULL,
        updated_at && !cJSON_IsNull(updated_at) ? strdup(updated_at->valuestring) : NULL
        );

    return device_local_var;
end:
    return NULL;

}
