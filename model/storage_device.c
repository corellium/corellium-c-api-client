#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "storage_device.h"


char* storage_device_mount_policy_ToString(corellium_api_storage_device_MOUNTPOLICY_e mount_policy) {
    char* mount_policyArray[] =  { "NULL", "RO", "RW" };
    return mount_policyArray[mount_policy];
}

corellium_api_storage_device_MOUNTPOLICY_e storage_device_mount_policy_FromString(char* mount_policy){
    int stringToReturn = 0;
    char *mount_policyArray[] =  { "NULL", "RO", "RW" };
    size_t sizeofArray = sizeof(mount_policyArray) / sizeof(mount_policyArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(mount_policy, mount_policyArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}
char* storage_device_status_ToString(corellium_api_storage_device_STATUS_e status) {
    char* statusArray[] =  { "NULL", "mounted", "unmounted" };
    return statusArray[status];
}

corellium_api_storage_device_STATUS_e storage_device_status_FromString(char* status){
    int stringToReturn = 0;
    char *statusArray[] =  { "NULL", "mounted", "unmounted" };
    size_t sizeofArray = sizeof(statusArray) / sizeof(statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(status, statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static storage_device_t *storage_device_create_internal(
    char *id,
    char *device,
    char *fs_type,
    char *fs_uuid,
    char *label,
    char *serial,
    char *vendor,
    char *model,
    corellium_api_storage_device_MOUNTPOLICY_e mount_policy,
    corellium_api_storage_device_STATUS_e status,
    char *created_at,
    char *updated_at
    ) {
    storage_device_t *storage_device_local_var = malloc(sizeof(storage_device_t));
    if (!storage_device_local_var) {
        return NULL;
    }
    storage_device_local_var->id = id;
    storage_device_local_var->device = device;
    storage_device_local_var->fs_type = fs_type;
    storage_device_local_var->fs_uuid = fs_uuid;
    storage_device_local_var->label = label;
    storage_device_local_var->serial = serial;
    storage_device_local_var->vendor = vendor;
    storage_device_local_var->model = model;
    storage_device_local_var->mount_policy = mount_policy;
    storage_device_local_var->status = status;
    storage_device_local_var->created_at = created_at;
    storage_device_local_var->updated_at = updated_at;

    storage_device_local_var->_library_owned = 1;
    return storage_device_local_var;
}

__attribute__((deprecated)) storage_device_t *storage_device_create(
    char *id,
    char *device,
    char *fs_type,
    char *fs_uuid,
    char *label,
    char *serial,
    char *vendor,
    char *model,
    corellium_api_storage_device_MOUNTPOLICY_e mount_policy,
    corellium_api_storage_device_STATUS_e status,
    char *created_at,
    char *updated_at
    ) {
    return storage_device_create_internal (
        id,
        device,
        fs_type,
        fs_uuid,
        label,
        serial,
        vendor,
        model,
        mount_policy,
        status,
        created_at,
        updated_at
        );
}

void storage_device_free(storage_device_t *storage_device) {
    if(NULL == storage_device){
        return ;
    }
    if(storage_device->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "storage_device_free");
        return ;
    }
    listEntry_t *listEntry;
    if (storage_device->id) {
        free(storage_device->id);
        storage_device->id = NULL;
    }
    if (storage_device->device) {
        free(storage_device->device);
        storage_device->device = NULL;
    }
    if (storage_device->fs_type) {
        free(storage_device->fs_type);
        storage_device->fs_type = NULL;
    }
    if (storage_device->fs_uuid) {
        free(storage_device->fs_uuid);
        storage_device->fs_uuid = NULL;
    }
    if (storage_device->label) {
        free(storage_device->label);
        storage_device->label = NULL;
    }
    if (storage_device->serial) {
        free(storage_device->serial);
        storage_device->serial = NULL;
    }
    if (storage_device->vendor) {
        free(storage_device->vendor);
        storage_device->vendor = NULL;
    }
    if (storage_device->model) {
        free(storage_device->model);
        storage_device->model = NULL;
    }
    if (storage_device->created_at) {
        free(storage_device->created_at);
        storage_device->created_at = NULL;
    }
    if (storage_device->updated_at) {
        free(storage_device->updated_at);
        storage_device->updated_at = NULL;
    }
    free(storage_device);
}

cJSON *storage_device_convertToJSON(storage_device_t *storage_device) {
    cJSON *item = cJSON_CreateObject();

    // storage_device->id
    if (!storage_device->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", storage_device->id) == NULL) {
    goto fail; //String
    }


    // storage_device->device
    if (!storage_device->device) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "device", storage_device->device) == NULL) {
    goto fail; //String
    }


    // storage_device->fs_type
    if (!storage_device->fs_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "fsType", storage_device->fs_type) == NULL) {
    goto fail; //String
    }


    // storage_device->fs_uuid
    if(storage_device->fs_uuid) {
    if(cJSON_AddStringToObject(item, "fsUuid", storage_device->fs_uuid) == NULL) {
    goto fail; //String
    }
    }


    // storage_device->label
    if (!storage_device->label) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "label", storage_device->label) == NULL) {
    goto fail; //String
    }


    // storage_device->serial
    if (!storage_device->serial) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "serial", storage_device->serial) == NULL) {
    goto fail; //String
    }


    // storage_device->vendor
    if (!storage_device->vendor) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "vendor", storage_device->vendor) == NULL) {
    goto fail; //String
    }


    // storage_device->model
    if (!storage_device->model) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "model", storage_device->model) == NULL) {
    goto fail; //String
    }


    // storage_device->mount_policy
    if (corellium_api_storage_device_MOUNTPOLICY_NULL == storage_device->mount_policy) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "mountPolicy", storage_device_mount_policy_ToString(storage_device->mount_policy)) == NULL)
    {
    goto fail; //Enum
    }


    // storage_device->status
    if (corellium_api_storage_device_STATUS_NULL == storage_device->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", storage_device_status_ToString(storage_device->status)) == NULL)
    {
    goto fail; //Enum
    }


    // storage_device->created_at
    if (!storage_device->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "createdAt", storage_device->created_at) == NULL) {
    goto fail; //Date-Time
    }


    // storage_device->updated_at
    if (!storage_device->updated_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "updatedAt", storage_device->updated_at) == NULL) {
    goto fail; //Date-Time
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

storage_device_t *storage_device_parseFromJSON(cJSON *storage_deviceJSON){

    storage_device_t *storage_device_local_var = NULL;

    // storage_device->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(storage_deviceJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // storage_device->device
    cJSON *device = cJSON_GetObjectItemCaseSensitive(storage_deviceJSON, "device");
    if (cJSON_IsNull(device)) {
        device = NULL;
    }
    if (!device) {
        goto end;
    }

    
    if(!cJSON_IsString(device))
    {
    goto end; //String
    }

    // storage_device->fs_type
    cJSON *fs_type = cJSON_GetObjectItemCaseSensitive(storage_deviceJSON, "fsType");
    if (cJSON_IsNull(fs_type)) {
        fs_type = NULL;
    }
    if (!fs_type) {
        goto end;
    }

    
    if(!cJSON_IsString(fs_type))
    {
    goto end; //String
    }

    // storage_device->fs_uuid
    cJSON *fs_uuid = cJSON_GetObjectItemCaseSensitive(storage_deviceJSON, "fsUuid");
    if (cJSON_IsNull(fs_uuid)) {
        fs_uuid = NULL;
    }
    if (fs_uuid) { 
    if(!cJSON_IsString(fs_uuid) && !cJSON_IsNull(fs_uuid))
    {
    goto end; //String
    }
    }

    // storage_device->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(storage_deviceJSON, "label");
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

    // storage_device->serial
    cJSON *serial = cJSON_GetObjectItemCaseSensitive(storage_deviceJSON, "serial");
    if (cJSON_IsNull(serial)) {
        serial = NULL;
    }
    if (!serial) {
        goto end;
    }

    
    if(!cJSON_IsString(serial))
    {
    goto end; //String
    }

    // storage_device->vendor
    cJSON *vendor = cJSON_GetObjectItemCaseSensitive(storage_deviceJSON, "vendor");
    if (cJSON_IsNull(vendor)) {
        vendor = NULL;
    }
    if (!vendor) {
        goto end;
    }

    
    if(!cJSON_IsString(vendor))
    {
    goto end; //String
    }

    // storage_device->model
    cJSON *model = cJSON_GetObjectItemCaseSensitive(storage_deviceJSON, "model");
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

    // storage_device->mount_policy
    cJSON *mount_policy = cJSON_GetObjectItemCaseSensitive(storage_deviceJSON, "mountPolicy");
    if (cJSON_IsNull(mount_policy)) {
        mount_policy = NULL;
    }
    if (!mount_policy) {
        goto end;
    }

    corellium_api_storage_device_MOUNTPOLICY_e mount_policyVariable;
    
    if(!cJSON_IsString(mount_policy))
    {
    goto end; //Enum
    }
    mount_policyVariable = storage_device_mount_policy_FromString(mount_policy->valuestring);

    // storage_device->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(storage_deviceJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    corellium_api_storage_device_STATUS_e statusVariable;
    
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = storage_device_status_FromString(status->valuestring);

    // storage_device->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(storage_deviceJSON, "createdAt");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (!created_at) {
        goto end;
    }

    
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //DateTime
    }

    // storage_device->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(storage_deviceJSON, "updatedAt");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (!updated_at) {
        goto end;
    }

    
    if(!cJSON_IsString(updated_at) && !cJSON_IsNull(updated_at))
    {
    goto end; //DateTime
    }


    storage_device_local_var = storage_device_create_internal (
        strdup(id->valuestring),
        strdup(device->valuestring),
        strdup(fs_type->valuestring),
        fs_uuid && !cJSON_IsNull(fs_uuid) ? strdup(fs_uuid->valuestring) : NULL,
        strdup(label->valuestring),
        strdup(serial->valuestring),
        strdup(vendor->valuestring),
        strdup(model->valuestring),
        mount_policyVariable,
        statusVariable,
        strdup(created_at->valuestring),
        strdup(updated_at->valuestring)
        );

    return storage_device_local_var;
end:
    return NULL;

}
