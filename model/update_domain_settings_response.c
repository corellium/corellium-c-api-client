#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "update_domain_settings_response.h"



static update_domain_settings_response_t *update_domain_settings_response_create_internal(
    char *domain_id,
    update_domain_settings_response_settings_t *settings,
    trial_extension_t *trial_extension,
    device_auto_shutdown_schema_t *device_auto_shutdown,
    list_t *allowed_devices_filters,
    update_domain_settings_response_webplayer_t *webplayer,
    update_domain_settings_response_snapshot_sharing_permissions_t *snapshot_sharing_permissions
    ) {
    update_domain_settings_response_t *update_domain_settings_response_local_var = malloc(sizeof(update_domain_settings_response_t));
    if (!update_domain_settings_response_local_var) {
        return NULL;
    }
    update_domain_settings_response_local_var->domain_id = domain_id;
    update_domain_settings_response_local_var->settings = settings;
    update_domain_settings_response_local_var->trial_extension = trial_extension;
    update_domain_settings_response_local_var->device_auto_shutdown = device_auto_shutdown;
    update_domain_settings_response_local_var->allowed_devices_filters = allowed_devices_filters;
    update_domain_settings_response_local_var->webplayer = webplayer;
    update_domain_settings_response_local_var->snapshot_sharing_permissions = snapshot_sharing_permissions;

    update_domain_settings_response_local_var->_library_owned = 1;
    return update_domain_settings_response_local_var;
}

__attribute__((deprecated)) update_domain_settings_response_t *update_domain_settings_response_create(
    char *domain_id,
    update_domain_settings_response_settings_t *settings,
    trial_extension_t *trial_extension,
    device_auto_shutdown_schema_t *device_auto_shutdown,
    list_t *allowed_devices_filters,
    update_domain_settings_response_webplayer_t *webplayer,
    update_domain_settings_response_snapshot_sharing_permissions_t *snapshot_sharing_permissions
    ) {
    return update_domain_settings_response_create_internal (
        domain_id,
        settings,
        trial_extension,
        device_auto_shutdown,
        allowed_devices_filters,
        webplayer,
        snapshot_sharing_permissions
        );
}

void update_domain_settings_response_free(update_domain_settings_response_t *update_domain_settings_response) {
    if(NULL == update_domain_settings_response){
        return ;
    }
    if(update_domain_settings_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "update_domain_settings_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (update_domain_settings_response->domain_id) {
        free(update_domain_settings_response->domain_id);
        update_domain_settings_response->domain_id = NULL;
    }
    if (update_domain_settings_response->settings) {
        update_domain_settings_response_settings_free(update_domain_settings_response->settings);
        update_domain_settings_response->settings = NULL;
    }
    if (update_domain_settings_response->trial_extension) {
        trial_extension_free(update_domain_settings_response->trial_extension);
        update_domain_settings_response->trial_extension = NULL;
    }
    if (update_domain_settings_response->device_auto_shutdown) {
        device_auto_shutdown_schema_free(update_domain_settings_response->device_auto_shutdown);
        update_domain_settings_response->device_auto_shutdown = NULL;
    }
    if (update_domain_settings_response->allowed_devices_filters) {
        list_ForEach(listEntry, update_domain_settings_response->allowed_devices_filters) {
            allowed_devices_filter_schema_free(listEntry->data);
        }
        list_freeList(update_domain_settings_response->allowed_devices_filters);
        update_domain_settings_response->allowed_devices_filters = NULL;
    }
    if (update_domain_settings_response->webplayer) {
        update_domain_settings_response_webplayer_free(update_domain_settings_response->webplayer);
        update_domain_settings_response->webplayer = NULL;
    }
    if (update_domain_settings_response->snapshot_sharing_permissions) {
        update_domain_settings_response_snapshot_sharing_permissions_free(update_domain_settings_response->snapshot_sharing_permissions);
        update_domain_settings_response->snapshot_sharing_permissions = NULL;
    }
    free(update_domain_settings_response);
}

cJSON *update_domain_settings_response_convertToJSON(update_domain_settings_response_t *update_domain_settings_response) {
    cJSON *item = cJSON_CreateObject();

    // update_domain_settings_response->domain_id
    if (!update_domain_settings_response->domain_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "domainId", update_domain_settings_response->domain_id) == NULL) {
    goto fail; //String
    }


    // update_domain_settings_response->settings
    if (!update_domain_settings_response->settings) {
        goto fail;
    }
    cJSON *settings_local_JSON = update_domain_settings_response_settings_convertToJSON(update_domain_settings_response->settings);
    if(settings_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "settings", settings_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // update_domain_settings_response->trial_extension
    if(update_domain_settings_response->trial_extension) {
    cJSON *trial_extension_local_JSON = trial_extension_convertToJSON(update_domain_settings_response->trial_extension);
    if(trial_extension_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "trialExtension", trial_extension_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // update_domain_settings_response->device_auto_shutdown
    if(update_domain_settings_response->device_auto_shutdown) {
    cJSON *device_auto_shutdown_local_JSON = device_auto_shutdown_schema_convertToJSON(update_domain_settings_response->device_auto_shutdown);
    if(device_auto_shutdown_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "deviceAutoShutdown", device_auto_shutdown_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // update_domain_settings_response->allowed_devices_filters
    if(update_domain_settings_response->allowed_devices_filters) {
    cJSON *allowed_devices_filters = cJSON_AddArrayToObject(item, "allowedDevicesFilters");
    if(allowed_devices_filters == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *allowed_devices_filtersListEntry;
    if (update_domain_settings_response->allowed_devices_filters) {
    list_ForEach(allowed_devices_filtersListEntry, update_domain_settings_response->allowed_devices_filters) {
    cJSON *itemLocal = allowed_devices_filter_schema_convertToJSON(allowed_devices_filtersListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(allowed_devices_filters, itemLocal);
    }
    }
    }


    // update_domain_settings_response->webplayer
    if(update_domain_settings_response->webplayer) {
    cJSON *webplayer_local_JSON = update_domain_settings_response_webplayer_convertToJSON(update_domain_settings_response->webplayer);
    if(webplayer_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "webplayer", webplayer_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // update_domain_settings_response->snapshot_sharing_permissions
    if(update_domain_settings_response->snapshot_sharing_permissions) {
    cJSON *snapshot_sharing_permissions_local_JSON = update_domain_settings_response_snapshot_sharing_permissions_convertToJSON(update_domain_settings_response->snapshot_sharing_permissions);
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

update_domain_settings_response_t *update_domain_settings_response_parseFromJSON(cJSON *update_domain_settings_responseJSON){

    update_domain_settings_response_t *update_domain_settings_response_local_var = NULL;

    // define the local variable for update_domain_settings_response->settings
    update_domain_settings_response_settings_t *settings_local_nonprim = NULL;

    // define the local variable for update_domain_settings_response->trial_extension
    trial_extension_t *trial_extension_local_nonprim = NULL;

    // define the local variable for update_domain_settings_response->device_auto_shutdown
    device_auto_shutdown_schema_t *device_auto_shutdown_local_nonprim = NULL;

    // define the local list for update_domain_settings_response->allowed_devices_filters
    list_t *allowed_devices_filtersList = NULL;

    // define the local variable for update_domain_settings_response->webplayer
    update_domain_settings_response_webplayer_t *webplayer_local_nonprim = NULL;

    // define the local variable for update_domain_settings_response->snapshot_sharing_permissions
    update_domain_settings_response_snapshot_sharing_permissions_t *snapshot_sharing_permissions_local_nonprim = NULL;

    // update_domain_settings_response->domain_id
    cJSON *domain_id = cJSON_GetObjectItemCaseSensitive(update_domain_settings_responseJSON, "domainId");
    if (cJSON_IsNull(domain_id)) {
        domain_id = NULL;
    }
    if (!domain_id) {
        goto end;
    }

    
    if(!cJSON_IsString(domain_id))
    {
    goto end; //String
    }

    // update_domain_settings_response->settings
    cJSON *settings = cJSON_GetObjectItemCaseSensitive(update_domain_settings_responseJSON, "settings");
    if (cJSON_IsNull(settings)) {
        settings = NULL;
    }
    if (!settings) {
        goto end;
    }

    
    settings_local_nonprim = update_domain_settings_response_settings_parseFromJSON(settings); //nonprimitive

    // update_domain_settings_response->trial_extension
    cJSON *trial_extension = cJSON_GetObjectItemCaseSensitive(update_domain_settings_responseJSON, "trialExtension");
    if (cJSON_IsNull(trial_extension)) {
        trial_extension = NULL;
    }
    if (trial_extension) { 
    trial_extension_local_nonprim = trial_extension_parseFromJSON(trial_extension); //nonprimitive
    }

    // update_domain_settings_response->device_auto_shutdown
    cJSON *device_auto_shutdown = cJSON_GetObjectItemCaseSensitive(update_domain_settings_responseJSON, "deviceAutoShutdown");
    if (cJSON_IsNull(device_auto_shutdown)) {
        device_auto_shutdown = NULL;
    }
    if (device_auto_shutdown) { 
    device_auto_shutdown_local_nonprim = device_auto_shutdown_schema_parseFromJSON(device_auto_shutdown); //nonprimitive
    }

    // update_domain_settings_response->allowed_devices_filters
    cJSON *allowed_devices_filters = cJSON_GetObjectItemCaseSensitive(update_domain_settings_responseJSON, "allowedDevicesFilters");
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

    // update_domain_settings_response->webplayer
    cJSON *webplayer = cJSON_GetObjectItemCaseSensitive(update_domain_settings_responseJSON, "webplayer");
    if (cJSON_IsNull(webplayer)) {
        webplayer = NULL;
    }
    if (webplayer) { 
    webplayer_local_nonprim = update_domain_settings_response_webplayer_parseFromJSON(webplayer); //nonprimitive
    }

    // update_domain_settings_response->snapshot_sharing_permissions
    cJSON *snapshot_sharing_permissions = cJSON_GetObjectItemCaseSensitive(update_domain_settings_responseJSON, "snapshotSharingPermissions");
    if (cJSON_IsNull(snapshot_sharing_permissions)) {
        snapshot_sharing_permissions = NULL;
    }
    if (snapshot_sharing_permissions) { 
    snapshot_sharing_permissions_local_nonprim = update_domain_settings_response_snapshot_sharing_permissions_parseFromJSON(snapshot_sharing_permissions); //nonprimitive
    }


    update_domain_settings_response_local_var = update_domain_settings_response_create_internal (
        strdup(domain_id->valuestring),
        settings_local_nonprim,
        trial_extension ? trial_extension_local_nonprim : NULL,
        device_auto_shutdown ? device_auto_shutdown_local_nonprim : NULL,
        allowed_devices_filters ? allowed_devices_filtersList : NULL,
        webplayer ? webplayer_local_nonprim : NULL,
        snapshot_sharing_permissions ? snapshot_sharing_permissions_local_nonprim : NULL
        );

    return update_domain_settings_response_local_var;
end:
    if (settings_local_nonprim) {
        update_domain_settings_response_settings_free(settings_local_nonprim);
        settings_local_nonprim = NULL;
    }
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
        update_domain_settings_response_webplayer_free(webplayer_local_nonprim);
        webplayer_local_nonprim = NULL;
    }
    if (snapshot_sharing_permissions_local_nonprim) {
        update_domain_settings_response_snapshot_sharing_permissions_free(snapshot_sharing_permissions_local_nonprim);
        snapshot_sharing_permissions_local_nonprim = NULL;
    }
    return NULL;

}
