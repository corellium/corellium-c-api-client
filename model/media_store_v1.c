#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "media_store_v1.h"



static media_store_v1_t *media_store_v1_create_internal(
    char *identifier,
    char *device,
    char *fs_type,
    char *fs_uuid,
    char *label,
    char *serial,
    char *vendor,
    char *model,
    char *mount_policy,
    char *created_at,
    char *updated_at
    ) {
    media_store_v1_t *media_store_v1_local_var = malloc(sizeof(media_store_v1_t));
    if (!media_store_v1_local_var) {
        return NULL;
    }
    media_store_v1_local_var->identifier = identifier;
    media_store_v1_local_var->device = device;
    media_store_v1_local_var->fs_type = fs_type;
    media_store_v1_local_var->fs_uuid = fs_uuid;
    media_store_v1_local_var->label = label;
    media_store_v1_local_var->serial = serial;
    media_store_v1_local_var->vendor = vendor;
    media_store_v1_local_var->model = model;
    media_store_v1_local_var->mount_policy = mount_policy;
    media_store_v1_local_var->created_at = created_at;
    media_store_v1_local_var->updated_at = updated_at;

    media_store_v1_local_var->_library_owned = 1;
    return media_store_v1_local_var;
}

__attribute__((deprecated)) media_store_v1_t *media_store_v1_create(
    char *identifier,
    char *device,
    char *fs_type,
    char *fs_uuid,
    char *label,
    char *serial,
    char *vendor,
    char *model,
    char *mount_policy,
    char *created_at,
    char *updated_at
    ) {
    return media_store_v1_create_internal (
        identifier,
        device,
        fs_type,
        fs_uuid,
        label,
        serial,
        vendor,
        model,
        mount_policy,
        created_at,
        updated_at
        );
}

void media_store_v1_free(media_store_v1_t *media_store_v1) {
    if(NULL == media_store_v1){
        return ;
    }
    if(media_store_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "media_store_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (media_store_v1->identifier) {
        free(media_store_v1->identifier);
        media_store_v1->identifier = NULL;
    }
    if (media_store_v1->device) {
        free(media_store_v1->device);
        media_store_v1->device = NULL;
    }
    if (media_store_v1->fs_type) {
        free(media_store_v1->fs_type);
        media_store_v1->fs_type = NULL;
    }
    if (media_store_v1->fs_uuid) {
        free(media_store_v1->fs_uuid);
        media_store_v1->fs_uuid = NULL;
    }
    if (media_store_v1->label) {
        free(media_store_v1->label);
        media_store_v1->label = NULL;
    }
    if (media_store_v1->serial) {
        free(media_store_v1->serial);
        media_store_v1->serial = NULL;
    }
    if (media_store_v1->vendor) {
        free(media_store_v1->vendor);
        media_store_v1->vendor = NULL;
    }
    if (media_store_v1->model) {
        free(media_store_v1->model);
        media_store_v1->model = NULL;
    }
    if (media_store_v1->mount_policy) {
        free(media_store_v1->mount_policy);
        media_store_v1->mount_policy = NULL;
    }
    if (media_store_v1->created_at) {
        free(media_store_v1->created_at);
        media_store_v1->created_at = NULL;
    }
    if (media_store_v1->updated_at) {
        free(media_store_v1->updated_at);
        media_store_v1->updated_at = NULL;
    }
    free(media_store_v1);
}

cJSON *media_store_v1_convertToJSON(media_store_v1_t *media_store_v1) {
    cJSON *item = cJSON_CreateObject();

    // media_store_v1->identifier
    if(media_store_v1->identifier) {
    if(cJSON_AddStringToObject(item, "identifier", media_store_v1->identifier) == NULL) {
    goto fail; //String
    }
    }


    // media_store_v1->device
    if(media_store_v1->device) {
    if(cJSON_AddStringToObject(item, "device", media_store_v1->device) == NULL) {
    goto fail; //String
    }
    }


    // media_store_v1->fs_type
    if(media_store_v1->fs_type) {
    if(cJSON_AddStringToObject(item, "fsType", media_store_v1->fs_type) == NULL) {
    goto fail; //String
    }
    }


    // media_store_v1->fs_uuid
    if(media_store_v1->fs_uuid) {
    if(cJSON_AddStringToObject(item, "fsUuid", media_store_v1->fs_uuid) == NULL) {
    goto fail; //String
    }
    }


    // media_store_v1->label
    if(media_store_v1->label) {
    if(cJSON_AddStringToObject(item, "label", media_store_v1->label) == NULL) {
    goto fail; //String
    }
    }


    // media_store_v1->serial
    if(media_store_v1->serial) {
    if(cJSON_AddStringToObject(item, "serial", media_store_v1->serial) == NULL) {
    goto fail; //String
    }
    }


    // media_store_v1->vendor
    if(media_store_v1->vendor) {
    if(cJSON_AddStringToObject(item, "vendor", media_store_v1->vendor) == NULL) {
    goto fail; //String
    }
    }


    // media_store_v1->model
    if(media_store_v1->model) {
    if(cJSON_AddStringToObject(item, "model", media_store_v1->model) == NULL) {
    goto fail; //String
    }
    }


    // media_store_v1->mount_policy
    if(media_store_v1->mount_policy) {
    if(cJSON_AddStringToObject(item, "mountPolicy", media_store_v1->mount_policy) == NULL) {
    goto fail; //String
    }
    }


    // media_store_v1->created_at
    if(media_store_v1->created_at) {
    if(cJSON_AddStringToObject(item, "createdAt", media_store_v1->created_at) == NULL) {
    goto fail; //String
    }
    }


    // media_store_v1->updated_at
    if(media_store_v1->updated_at) {
    if(cJSON_AddStringToObject(item, "updatedAt", media_store_v1->updated_at) == NULL) {
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

media_store_v1_t *media_store_v1_parseFromJSON(cJSON *media_store_v1JSON){

    media_store_v1_t *media_store_v1_local_var = NULL;

    // media_store_v1->identifier
    cJSON *identifier = cJSON_GetObjectItemCaseSensitive(media_store_v1JSON, "identifier");
    if (cJSON_IsNull(identifier)) {
        identifier = NULL;
    }
    if (identifier) { 
    if(!cJSON_IsString(identifier) && !cJSON_IsNull(identifier))
    {
    goto end; //String
    }
    }

    // media_store_v1->device
    cJSON *device = cJSON_GetObjectItemCaseSensitive(media_store_v1JSON, "device");
    if (cJSON_IsNull(device)) {
        device = NULL;
    }
    if (device) { 
    if(!cJSON_IsString(device) && !cJSON_IsNull(device))
    {
    goto end; //String
    }
    }

    // media_store_v1->fs_type
    cJSON *fs_type = cJSON_GetObjectItemCaseSensitive(media_store_v1JSON, "fsType");
    if (cJSON_IsNull(fs_type)) {
        fs_type = NULL;
    }
    if (fs_type) { 
    if(!cJSON_IsString(fs_type) && !cJSON_IsNull(fs_type))
    {
    goto end; //String
    }
    }

    // media_store_v1->fs_uuid
    cJSON *fs_uuid = cJSON_GetObjectItemCaseSensitive(media_store_v1JSON, "fsUuid");
    if (cJSON_IsNull(fs_uuid)) {
        fs_uuid = NULL;
    }
    if (fs_uuid) { 
    if(!cJSON_IsString(fs_uuid) && !cJSON_IsNull(fs_uuid))
    {
    goto end; //String
    }
    }

    // media_store_v1->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(media_store_v1JSON, "label");
    if (cJSON_IsNull(label)) {
        label = NULL;
    }
    if (label) { 
    if(!cJSON_IsString(label) && !cJSON_IsNull(label))
    {
    goto end; //String
    }
    }

    // media_store_v1->serial
    cJSON *serial = cJSON_GetObjectItemCaseSensitive(media_store_v1JSON, "serial");
    if (cJSON_IsNull(serial)) {
        serial = NULL;
    }
    if (serial) { 
    if(!cJSON_IsString(serial) && !cJSON_IsNull(serial))
    {
    goto end; //String
    }
    }

    // media_store_v1->vendor
    cJSON *vendor = cJSON_GetObjectItemCaseSensitive(media_store_v1JSON, "vendor");
    if (cJSON_IsNull(vendor)) {
        vendor = NULL;
    }
    if (vendor) { 
    if(!cJSON_IsString(vendor) && !cJSON_IsNull(vendor))
    {
    goto end; //String
    }
    }

    // media_store_v1->model
    cJSON *model = cJSON_GetObjectItemCaseSensitive(media_store_v1JSON, "model");
    if (cJSON_IsNull(model)) {
        model = NULL;
    }
    if (model) { 
    if(!cJSON_IsString(model) && !cJSON_IsNull(model))
    {
    goto end; //String
    }
    }

    // media_store_v1->mount_policy
    cJSON *mount_policy = cJSON_GetObjectItemCaseSensitive(media_store_v1JSON, "mountPolicy");
    if (cJSON_IsNull(mount_policy)) {
        mount_policy = NULL;
    }
    if (mount_policy) { 
    if(!cJSON_IsString(mount_policy) && !cJSON_IsNull(mount_policy))
    {
    goto end; //String
    }
    }

    // media_store_v1->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(media_store_v1JSON, "createdAt");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (created_at) { 
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //String
    }
    }

    // media_store_v1->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(media_store_v1JSON, "updatedAt");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (updated_at) { 
    if(!cJSON_IsString(updated_at) && !cJSON_IsNull(updated_at))
    {
    goto end; //String
    }
    }


    media_store_v1_local_var = media_store_v1_create_internal (
        identifier && !cJSON_IsNull(identifier) ? strdup(identifier->valuestring) : NULL,
        device && !cJSON_IsNull(device) ? strdup(device->valuestring) : NULL,
        fs_type && !cJSON_IsNull(fs_type) ? strdup(fs_type->valuestring) : NULL,
        fs_uuid && !cJSON_IsNull(fs_uuid) ? strdup(fs_uuid->valuestring) : NULL,
        label && !cJSON_IsNull(label) ? strdup(label->valuestring) : NULL,
        serial && !cJSON_IsNull(serial) ? strdup(serial->valuestring) : NULL,
        vendor && !cJSON_IsNull(vendor) ? strdup(vendor->valuestring) : NULL,
        model && !cJSON_IsNull(model) ? strdup(model->valuestring) : NULL,
        mount_policy && !cJSON_IsNull(mount_policy) ? strdup(mount_policy->valuestring) : NULL,
        created_at && !cJSON_IsNull(created_at) ? strdup(created_at->valuestring) : NULL,
        updated_at && !cJSON_IsNull(updated_at) ? strdup(updated_at->valuestring) : NULL
        );

    return media_store_v1_local_var;
end:
    return NULL;

}
