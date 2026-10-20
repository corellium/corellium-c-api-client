#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "patch_domain_body.h"



static patch_domain_body_t *patch_domain_body_create_internal(
    int totp_required,
    trial_extension_t *trial_extension,
    device_auto_shutdown_schema_t *device_auto_shutdown,
    list_t *allowed_devices_filters,
    patch_domain_body_webplayer_t *webplayer,
    snapshot_sharing_permissions_request_schema_t *snapshot_sharing_permissions
    ) {
    patch_domain_body_t *patch_domain_body_local_var = malloc(sizeof(patch_domain_body_t));
    if (!patch_domain_body_local_var) {
        return NULL;
    }
    patch_domain_body_local_var->totp_required = totp_required;
    patch_domain_body_local_var->trial_extension = trial_extension;
    patch_domain_body_local_var->device_auto_shutdown = device_auto_shutdown;
    patch_domain_body_local_var->allowed_devices_filters = allowed_devices_filters;
    patch_domain_body_local_var->webplayer = webplayer;
    patch_domain_body_local_var->snapshot_sharing_permissions = snapshot_sharing_permissions;

    patch_domain_body_local_var->_library_owned = 1;
    return patch_domain_body_local_var;
}

__attribute__((deprecated)) patch_domain_body_t *patch_domain_body_create(
    int totp_required,
    trial_extension_t *trial_extension,
    device_auto_shutdown_schema_t *device_auto_shutdown,
    list_t *allowed_devices_filters,
    patch_domain_body_webplayer_t *webplayer,
    snapshot_sharing_permissions_request_schema_t *snapshot_sharing_permissions
    ) {
    return patch_domain_body_create_internal (
        totp_required,
        trial_extension,
        device_auto_shutdown,
        allowed_devices_filters,
        webplayer,
        snapshot_sharing_permissions
        );
}

void patch_domain_body_free(patch_domain_body_t *patch_domain_body) {
    if(NULL == patch_domain_body){
        return ;
    }
    if(patch_domain_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "patch_domain_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (patch_domain_body->trial_extension) {
        trial_extension_free(patch_domain_body->trial_extension);
        patch_domain_body->trial_extension = NULL;
    }
    if (patch_domain_body->device_auto_shutdown) {
        device_auto_shutdown_schema_free(patch_domain_body->device_auto_shutdown);
        patch_domain_body->device_auto_shutdown = NULL;
    }
    if (patch_domain_body->allowed_devices_filters) {
        list_ForEach(listEntry, patch_domain_body->allowed_devices_filters) {
            allowed_devices_filter_schema_free(listEntry->data);
        }
        list_freeList(patch_domain_body->allowed_devices_filters);
        patch_domain_body->allowed_devices_filters = NULL;
    }
    if (patch_domain_body->webplayer) {
        patch_domain_body_webplayer_free(patch_domain_body->webplayer);
        patch_domain_body->webplayer = NULL;
    }
    if (patch_domain_body->snapshot_sharing_permissions) {
        snapshot_sharing_permissions_request_schema_free(patch_domain_body->snapshot_sharing_permissions);
        patch_domain_body->snapshot_sharing_permissions = NULL;
    }
    free(patch_domain_body);
}

cJSON *patch_domain_body_convertToJSON(patch_domain_body_t *patch_domain_body) {
    cJSON *item = cJSON_CreateObject();

    // patch_domain_body->totp_required
    if(patch_domain_body->totp_required) {
    if(cJSON_AddBoolToObject(item, "totpRequired", patch_domain_body->totp_required) == NULL) {
    goto fail; //Bool
    }
    }


    // patch_domain_body->trial_extension
    if(patch_domain_body->trial_extension) {
    cJSON *trial_extension_local_JSON = trial_extension_convertToJSON(patch_domain_body->trial_extension);
    if(trial_extension_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "trialExtension", trial_extension_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // patch_domain_body->device_auto_shutdown
    if(patch_domain_body->device_auto_shutdown) {
    cJSON *device_auto_shutdown_local_JSON = device_auto_shutdown_schema_convertToJSON(patch_domain_body->device_auto_shutdown);
    if(device_auto_shutdown_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "deviceAutoShutdown", device_auto_shutdown_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // patch_domain_body->allowed_devices_filters
    if(patch_domain_body->allowed_devices_filters) {
    cJSON *allowed_devices_filters = cJSON_AddArrayToObject(item, "allowedDevicesFilters");
    if(allowed_devices_filters == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *allowed_devices_filtersListEntry;
    if (patch_domain_body->allowed_devices_filters) {
    list_ForEach(allowed_devices_filtersListEntry, patch_domain_body->allowed_devices_filters) {
    cJSON *itemLocal = allowed_devices_filter_schema_convertToJSON(allowed_devices_filtersListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(allowed_devices_filters, itemLocal);
    }
    }
    }


    // patch_domain_body->webplayer
    if(patch_domain_body->webplayer) {
    cJSON *webplayer_local_JSON = patch_domain_body_webplayer_convertToJSON(patch_domain_body->webplayer);
    if(webplayer_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "webplayer", webplayer_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // patch_domain_body->snapshot_sharing_permissions
    if(patch_domain_body->snapshot_sharing_permissions) {
    cJSON *snapshot_sharing_permissions_local_JSON = snapshot_sharing_permissions_request_schema_convertToJSON(patch_domain_body->snapshot_sharing_permissions);
    if(snapshot_sharing_permissions_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "snapshotSharingPermissions", snapshot_sharing_permissions_local_JSON);
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

patch_domain_body_t *patch_domain_body_parseFromJSON(cJSON *patch_domain_bodyJSON){

    patch_domain_body_t *patch_domain_body_local_var = NULL;

    // define the local variable for patch_domain_body->trial_extension
    trial_extension_t *trial_extension_local_nonprim = NULL;

    // define the local variable for patch_domain_body->device_auto_shutdown
    device_auto_shutdown_schema_t *device_auto_shutdown_local_nonprim = NULL;

    // define the local list for patch_domain_body->allowed_devices_filters
    list_t *allowed_devices_filtersList = NULL;

    // define the local variable for patch_domain_body->webplayer
    patch_domain_body_webplayer_t *webplayer_local_nonprim = NULL;

    // define the local variable for patch_domain_body->snapshot_sharing_permissions
    snapshot_sharing_permissions_request_schema_t *snapshot_sharing_permissions_local_nonprim = NULL;

    // patch_domain_body->totp_required
    cJSON *totp_required = cJSON_GetObjectItemCaseSensitive(patch_domain_bodyJSON, "totpRequired");
    if (cJSON_IsNull(totp_required)) {
        totp_required = NULL;
    }
    if (totp_required) { 
    if(!cJSON_IsBool(totp_required))
    {
    goto end; //Bool
    }
    }

    // patch_domain_body->trial_extension
    cJSON *trial_extension = cJSON_GetObjectItemCaseSensitive(patch_domain_bodyJSON, "trialExtension");
    if (cJSON_IsNull(trial_extension)) {
        trial_extension = NULL;
    }
    if (trial_extension) { 
    trial_extension_local_nonprim = trial_extension_parseFromJSON(trial_extension); //nonprimitive
    }

    // patch_domain_body->device_auto_shutdown
    cJSON *device_auto_shutdown = cJSON_GetObjectItemCaseSensitive(patch_domain_bodyJSON, "deviceAutoShutdown");
    if (cJSON_IsNull(device_auto_shutdown)) {
        device_auto_shutdown = NULL;
    }
    if (device_auto_shutdown) { 
    device_auto_shutdown_local_nonprim = device_auto_shutdown_schema_parseFromJSON(device_auto_shutdown); //nonprimitive
    }

    // patch_domain_body->allowed_devices_filters
    cJSON *allowed_devices_filters = cJSON_GetObjectItemCaseSensitive(patch_domain_bodyJSON, "allowedDevicesFilters");
    if (cJSON_IsNull(allowed_devices_filters)) {
        allowed_devices_filters = NULL;
    }
    if (allowed_devices_filters) { 
    cJSON *allowed_devices_filters_local_nonprimitive = NULL;
    if(!cJSON_IsArray(allowed_devices_filters)){
        goto end; //nonprimitive container
    }

    allowed_devices_filtersList = list_createList();

    cJSON_ArrayForEach(allowed_devices_filters_local_nonprimitive,allowed_devices_filters )
    {
        if(!cJSON_IsObject(allowed_devices_filters_local_nonprimitive)){
            goto end;
        }
        allowed_devices_filter_schema_t *allowed_devices_filtersItem = allowed_devices_filter_schema_parseFromJSON(allowed_devices_filters_local_nonprimitive);

        list_addElement(allowed_devices_filtersList, allowed_devices_filtersItem);
    }
    }

    // patch_domain_body->webplayer
    cJSON *webplayer = cJSON_GetObjectItemCaseSensitive(patch_domain_bodyJSON, "webplayer");
    if (cJSON_IsNull(webplayer)) {
        webplayer = NULL;
    }
    if (webplayer) { 
    webplayer_local_nonprim = patch_domain_body_webplayer_parseFromJSON(webplayer); //nonprimitive
    }

    // patch_domain_body->snapshot_sharing_permissions
    cJSON *snapshot_sharing_permissions = cJSON_GetObjectItemCaseSensitive(patch_domain_bodyJSON, "snapshotSharingPermissions");
    if (cJSON_IsNull(snapshot_sharing_permissions)) {
        snapshot_sharing_permissions = NULL;
    }
    if (snapshot_sharing_permissions) { 
    snapshot_sharing_permissions_local_nonprim = snapshot_sharing_permissions_request_schema_parseFromJSON(snapshot_sharing_permissions); //nonprimitive
    }


    patch_domain_body_local_var = patch_domain_body_create_internal (
        totp_required ? totp_required->valueint : 0,
        trial_extension ? trial_extension_local_nonprim : NULL,
        device_auto_shutdown ? device_auto_shutdown_local_nonprim : NULL,
        allowed_devices_filters ? allowed_devices_filtersList : NULL,
        webplayer ? webplayer_local_nonprim : NULL,
        snapshot_sharing_permissions ? snapshot_sharing_permissions_local_nonprim : NULL
        );

    return patch_domain_body_local_var;
end:
    if (trial_extension_local_nonprim) {
        trial_extension_free(trial_extension_local_nonprim);
        trial_extension_local_nonprim = NULL;
    }
    if (device_auto_shutdown_local_nonprim) {
        device_auto_shutdown_schema_free(device_auto_shutdown_local_nonprim);
        device_auto_shutdown_local_nonprim = NULL;
    }
    if (allowed_devices_filtersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, allowed_devices_filtersList) {
            allowed_devices_filter_schema_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(allowed_devices_filtersList);
        allowed_devices_filtersList = NULL;
    }
    if (webplayer_local_nonprim) {
        patch_domain_body_webplayer_free(webplayer_local_nonprim);
        webplayer_local_nonprim = NULL;
    }
    if (snapshot_sharing_permissions_local_nonprim) {
        snapshot_sharing_permissions_request_schema_free(snapshot_sharing_permissions_local_nonprim);
        snapshot_sharing_permissions_local_nonprim = NULL;
    }
    return NULL;

}
