#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "media_store.h"


char* media_store_mount_policy_ToString(corellium_api_media_store_MOUNTPOLICY_e mount_policy) {
    char* mount_policyArray[] =  { "NULL", "RO", "RW" };
    return mount_policyArray[mount_policy];
}

corellium_api_media_store_MOUNTPOLICY_e media_store_mount_policy_FromString(char* mount_policy){
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
char* media_store_status_ToString(corellium_api_media_store_STATUS_e status) {
    char* statusArray[] =  { "NULL", "mounted", "unmounted" };
    return statusArray[status];
}

corellium_api_media_store_STATUS_e media_store_status_FromString(char* status){
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

static media_store_t *media_store_create_internal(
    char *identifier,
    char *device,
    char *fs_type,
    char *fs_uuid,
    char *label,
    char *serial,
    char *vendor,
    char *model,
    corellium_api_media_store_MOUNTPOLICY_e mount_policy,
    corellium_api_media_store_STATUS_e status,
    char *created_at,
    char *updated_at
    ) {
    media_store_t *media_store_local_var = malloc(sizeof(media_store_t));
    if (!media_store_local_var) {
        return NULL;
    }
    media_store_local_var->identifier = identifier;
    media_store_local_var->device = device;
    media_store_local_var->fs_type = fs_type;
    media_store_local_var->fs_uuid = fs_uuid;
    media_store_local_var->label = label;
    media_store_local_var->serial = serial;
    media_store_local_var->vendor = vendor;
    media_store_local_var->model = model;
    media_store_local_var->mount_policy = mount_policy;
    media_store_local_var->status = status;
    media_store_local_var->created_at = created_at;
    media_store_local_var->updated_at = updated_at;

    media_store_local_var->_library_owned = 1;
    return media_store_local_var;
}

__attribute__((deprecated)) media_store_t *media_store_create(
    char *identifier,
    char *device,
    char *fs_type,
    char *fs_uuid,
    char *label,
    char *serial,
    char *vendor,
    char *model,
    corellium_api_media_store_MOUNTPOLICY_e mount_policy,
    corellium_api_media_store_STATUS_e status,
    char *created_at,
    char *updated_at
    ) {
    return media_store_create_internal (
        identifier,
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

void media_store_free(media_store_t *media_store) {
    if(NULL == media_store){
        return ;
    }
    if(media_store->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "media_store_free");
        return ;
    }
    listEntry_t *listEntry;
    if (media_store->identifier) {
        free(media_store->identifier);
        media_store->identifier = NULL;
    }
    if (media_store->device) {
        free(media_store->device);
        media_store->device = NULL;
    }
    if (media_store->fs_type) {
        free(media_store->fs_type);
        media_store->fs_type = NULL;
    }
    if (media_store->fs_uuid) {
        free(media_store->fs_uuid);
        media_store->fs_uuid = NULL;
    }
    if (media_store->label) {
        free(media_store->label);
        media_store->label = NULL;
    }
    if (media_store->serial) {
        free(media_store->serial);
        media_store->serial = NULL;
    }
    if (media_store->vendor) {
        free(media_store->vendor);
        media_store->vendor = NULL;
    }
    if (media_store->model) {
        free(media_store->model);
        media_store->model = NULL;
    }
    if (media_store->created_at) {
        free(media_store->created_at);
        media_store->created_at = NULL;
    }
    if (media_store->updated_at) {
        free(media_store->updated_at);
        media_store->updated_at = NULL;
    }
    free(media_store);
}

cJSON *media_store_convertToJSON(media_store_t *media_store) {
    cJSON *item = cJSON_CreateObject();

    // media_store->identifier
    if (!media_store->identifier) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "identifier", media_store->identifier) == NULL) {
    goto fail; //String
    }


    // media_store->device
    if (!media_store->device) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "device", media_store->device) == NULL) {
    goto fail; //String
    }


    // media_store->fs_type
    if (!media_store->fs_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "fsType", media_store->fs_type) == NULL) {
    goto fail; //String
    }


    // media_store->fs_uuid
    if (!media_store->fs_uuid) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "fsUuid", media_store->fs_uuid) == NULL) {
    goto fail; //String
    }


    // media_store->label
    if (!media_store->label) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "label", media_store->label) == NULL) {
    goto fail; //String
    }


    // media_store->serial
    if (!media_store->serial) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "serial", media_store->serial) == NULL) {
    goto fail; //String
    }


    // media_store->vendor
    if (!media_store->vendor) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "vendor", media_store->vendor) == NULL) {
    goto fail; //String
    }


    // media_store->model
    if (!media_store->model) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "model", media_store->model) == NULL) {
    goto fail; //String
    }


    // media_store->mount_policy
    if (corellium_api_media_store_MOUNTPOLICY_NULL == media_store->mount_policy) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "mountPolicy", media_store_mount_policy_ToString(media_store->mount_policy)) == NULL)
    {
    goto fail; //Enum
    }


    // media_store->status
    if (corellium_api_media_store_STATUS_NULL == media_store->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", media_store_status_ToString(media_store->status)) == NULL)
    {
    goto fail; //Enum
    }


    // media_store->created_at
    if (!media_store->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "createdAt", media_store->created_at) == NULL) {
    goto fail; //Date-Time
    }


    // media_store->updated_at
    if (!media_store->updated_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "updatedAt", media_store->updated_at) == NULL) {
    goto fail; //Date-Time
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

media_store_t *media_store_parseFromJSON(cJSON *media_storeJSON){

    media_store_t *media_store_local_var = NULL;

    // media_store->identifier
    cJSON *identifier = cJSON_GetObjectItemCaseSensitive(media_storeJSON, "identifier");
    if (cJSON_IsNull(identifier)) {
        identifier = NULL;
    }
    if (!identifier) {
        goto end;
    }

    
    if(!cJSON_IsString(identifier))
    {
    goto end; //String
    }

    // media_store->device
    cJSON *device = cJSON_GetObjectItemCaseSensitive(media_storeJSON, "device");
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

    // media_store->fs_type
    cJSON *fs_type = cJSON_GetObjectItemCaseSensitive(media_storeJSON, "fsType");
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

    // media_store->fs_uuid
    cJSON *fs_uuid = cJSON_GetObjectItemCaseSensitive(media_storeJSON, "fsUuid");
    if (cJSON_IsNull(fs_uuid)) {
        fs_uuid = NULL;
    }
    if (!fs_uuid) {
        goto end;
    }

    
    if(!cJSON_IsString(fs_uuid))
    {
    goto end; //String
    }

    // media_store->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(media_storeJSON, "label");
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

    // media_store->serial
    cJSON *serial = cJSON_GetObjectItemCaseSensitive(media_storeJSON, "serial");
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

    // media_store->vendor
    cJSON *vendor = cJSON_GetObjectItemCaseSensitive(media_storeJSON, "vendor");
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

    // media_store->model
    cJSON *model = cJSON_GetObjectItemCaseSensitive(media_storeJSON, "model");
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

    // media_store->mount_policy
    cJSON *mount_policy = cJSON_GetObjectItemCaseSensitive(media_storeJSON, "mountPolicy");
    if (cJSON_IsNull(mount_policy)) {
        mount_policy = NULL;
    }
    if (!mount_policy) {
        goto end;
    }

    corellium_api_media_store_MOUNTPOLICY_e mount_policyVariable;
    
    if(!cJSON_IsString(mount_policy))
    {
    goto end; //Enum
    }
    mount_policyVariable = media_store_mount_policy_FromString(mount_policy->valuestring);

    // media_store->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(media_storeJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    corellium_api_media_store_STATUS_e statusVariable;
    
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = media_store_status_FromString(status->valuestring);

    // media_store->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(media_storeJSON, "createdAt");
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

    // media_store->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(media_storeJSON, "updatedAt");
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


    media_store_local_var = media_store_create_internal (
        strdup(identifier->valuestring),
        strdup(device->valuestring),
        strdup(fs_type->valuestring),
        strdup(fs_uuid->valuestring),
        strdup(label->valuestring),
        strdup(serial->valuestring),
        strdup(vendor->valuestring),
        strdup(model->valuestring),
        mount_policyVariable,
        statusVariable,
        strdup(created_at->valuestring),
        strdup(updated_at->valuestring)
        );

    return media_store_local_var;
end:
    return NULL;

}
