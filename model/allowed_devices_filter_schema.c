#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "allowed_devices_filter_schema.h"



static allowed_devices_filter_schema_t *allowed_devices_filter_schema_create_internal(
    char *device_name,
    list_t *allowed_firmwares
    ) {
    allowed_devices_filter_schema_t *allowed_devices_filter_schema_local_var = malloc(sizeof(allowed_devices_filter_schema_t));
    if (!allowed_devices_filter_schema_local_var) {
        return NULL;
    }
    allowed_devices_filter_schema_local_var->device_name = device_name;
    allowed_devices_filter_schema_local_var->allowed_firmwares = allowed_firmwares;

    allowed_devices_filter_schema_local_var->_library_owned = 1;
    return allowed_devices_filter_schema_local_var;
}

__attribute__((deprecated)) allowed_devices_filter_schema_t *allowed_devices_filter_schema_create(
    char *device_name,
    list_t *allowed_firmwares
    ) {
    return allowed_devices_filter_schema_create_internal (
        device_name,
        allowed_firmwares
        );
}

void allowed_devices_filter_schema_free(allowed_devices_filter_schema_t *allowed_devices_filter_schema) {
    if(NULL == allowed_devices_filter_schema){
        return ;
    }
    if(allowed_devices_filter_schema->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "allowed_devices_filter_schema_free");
        return ;
    }
    listEntry_t *listEntry;
    if (allowed_devices_filter_schema->device_name) {
        free(allowed_devices_filter_schema->device_name);
        allowed_devices_filter_schema->device_name = NULL;
    }
    if (allowed_devices_filter_schema->allowed_firmwares) {
        list_ForEach(listEntry, allowed_devices_filter_schema->allowed_firmwares) {
            allowed_firmware_schema_free(listEntry->data);
        }
        list_freeList(allowed_devices_filter_schema->allowed_firmwares);
        allowed_devices_filter_schema->allowed_firmwares = NULL;
    }
    free(allowed_devices_filter_schema);
}

cJSON *allowed_devices_filter_schema_convertToJSON(allowed_devices_filter_schema_t *allowed_devices_filter_schema) {
    cJSON *item = cJSON_CreateObject();

    // allowed_devices_filter_schema->device_name
    if (!allowed_devices_filter_schema->device_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "deviceName", allowed_devices_filter_schema->device_name) == NULL) {
    goto fail; //String
    }


    // allowed_devices_filter_schema->allowed_firmwares
    if (!allowed_devices_filter_schema->allowed_firmwares) {
        goto fail;
    }
    cJSON *allowed_firmwares = cJSON_AddArrayToObject(item, "allowedFirmwares");
    if(allowed_firmwares == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *allowed_firmwaresListEntry;
    if (allowed_devices_filter_schema->allowed_firmwares) {
    list_ForEach(allowed_firmwaresListEntry, allowed_devices_filter_schema->allowed_firmwares) {
    cJSON *itemLocal = allowed_firmware_schema_convertToJSON(allowed_firmwaresListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(allowed_firmwares, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

allowed_devices_filter_schema_t *allowed_devices_filter_schema_parseFromJSON(cJSON *allowed_devices_filter_schemaJSON){

    allowed_devices_filter_schema_t *allowed_devices_filter_schema_local_var = NULL;

    // define the local list for allowed_devices_filter_schema->allowed_firmwares
    list_t *allowed_firmwaresList = NULL;

    // allowed_devices_filter_schema->device_name
    cJSON *device_name = cJSON_GetObjectItemCaseSensitive(allowed_devices_filter_schemaJSON, "deviceName");
    if (cJSON_IsNull(device_name)) {
        device_name = NULL;
    }
    if (!device_name) {
        goto end;
    }

    
    if(!cJSON_IsString(device_name))
    {
    goto end; //String
    }

    // allowed_devices_filter_schema->allowed_firmwares
    cJSON *allowed_firmwares = cJSON_GetObjectItemCaseSensitive(allowed_devices_filter_schemaJSON, "allowedFirmwares");
    if (cJSON_IsNull(allowed_firmwares)) {
        allowed_firmwares = NULL;
    }
    if (!allowed_firmwares) {
        goto end;
    }

    
    cJSON *allowed_firmwares_local_nonprimitive = NULL;
    if(!cJSON_IsArray(allowed_firmwares)){
        goto end; //nonprimitive container
    }

    allowed_firmwaresList = list_createList();

    cJSON_ArrayForEach(allowed_firmwares_local_nonprimitive,allowed_firmwares )
    {
        if(!cJSON_IsObject(allowed_firmwares_local_nonprimitive)){
            goto end;
        }
        allowed_firmware_schema_t *allowed_firmwaresItem = allowed_firmware_schema_parseFromJSON(allowed_firmwares_local_nonprimitive);

        list_addElement(allowed_firmwaresList, allowed_firmwaresItem);
    }


    allowed_devices_filter_schema_local_var = allowed_devices_filter_schema_create_internal (
        strdup(device_name->valuestring),
        allowed_firmwaresList
        );

    return allowed_devices_filter_schema_local_var;
end:
    if (allowed_firmwaresList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, allowed_firmwaresList) {
            allowed_firmware_schema_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(allowed_firmwaresList);
        allowed_firmwaresList = NULL;
    }
    return NULL;

}
