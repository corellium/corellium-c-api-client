#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "firmware_info_device.h"



static firmware_info_device_t *firmware_info_device_create_internal(
    char *flavor,
    list_t *firmwares
    ) {
    firmware_info_device_t *firmware_info_device_local_var = malloc(sizeof(firmware_info_device_t));
    if (!firmware_info_device_local_var) {
        return NULL;
    }
    firmware_info_device_local_var->flavor = flavor;
    firmware_info_device_local_var->firmwares = firmwares;

    firmware_info_device_local_var->_library_owned = 1;
    return firmware_info_device_local_var;
}

__attribute__((deprecated)) firmware_info_device_t *firmware_info_device_create(
    char *flavor,
    list_t *firmwares
    ) {
    return firmware_info_device_create_internal (
        flavor,
        firmwares
        );
}

void firmware_info_device_free(firmware_info_device_t *firmware_info_device) {
    if(NULL == firmware_info_device){
        return ;
    }
    if(firmware_info_device->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "firmware_info_device_free");
        return ;
    }
    listEntry_t *listEntry;
    if (firmware_info_device->flavor) {
        free(firmware_info_device->flavor);
        firmware_info_device->flavor = NULL;
    }
    if (firmware_info_device->firmwares) {
        list_ForEach(listEntry, firmware_info_device->firmwares) {
            firmware_info_device_firmwares_inner_free(listEntry->data);
        }
        list_freeList(firmware_info_device->firmwares);
        firmware_info_device->firmwares = NULL;
    }
    free(firmware_info_device);
}

cJSON *firmware_info_device_convertToJSON(firmware_info_device_t *firmware_info_device) {
    cJSON *item = cJSON_CreateObject();

    // firmware_info_device->flavor
    if(firmware_info_device->flavor) {
    if(cJSON_AddStringToObject(item, "flavor", firmware_info_device->flavor) == NULL) {
    goto fail; //String
    }
    }


    // firmware_info_device->firmwares
    if(firmware_info_device->firmwares) {
    cJSON *firmwares = cJSON_AddArrayToObject(item, "firmwares");
    if(firmwares == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *firmwaresListEntry;
    if (firmware_info_device->firmwares) {
    list_ForEach(firmwaresListEntry, firmware_info_device->firmwares) {
    cJSON *itemLocal = firmware_info_device_firmwares_inner_convertToJSON(firmwaresListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(firmwares, itemLocal);
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

firmware_info_device_t *firmware_info_device_parseFromJSON(cJSON *firmware_info_deviceJSON){

    firmware_info_device_t *firmware_info_device_local_var = NULL;

    // define the local list for firmware_info_device->firmwares
    list_t *firmwaresList = NULL;

    // firmware_info_device->flavor
    cJSON *flavor = cJSON_GetObjectItemCaseSensitive(firmware_info_deviceJSON, "flavor");
    if (cJSON_IsNull(flavor)) {
        flavor = NULL;
    }
    if (flavor) { 
    if(!cJSON_IsString(flavor) && !cJSON_IsNull(flavor))
    {
    goto end; //String
    }
    }

    // firmware_info_device->firmwares
    cJSON *firmwares = cJSON_GetObjectItemCaseSensitive(firmware_info_deviceJSON, "firmwares");
    if (cJSON_IsNull(firmwares)) {
        firmwares = NULL;
    }
    if (firmwares) { 
    cJSON *firmwares_local_nonprimitive = NULL;
    if(!cJSON_IsArray(firmwares)){
        goto end; //nonprimitive container
    }

    firmwaresList = list_createList();

    cJSON_ArrayForEach(firmwares_local_nonprimitive,firmwares )
    {
        if(!cJSON_IsObject(firmwares_local_nonprimitive)){
            goto end;
        }
        firmware_info_device_firmwares_inner_t *firmwaresItem = firmware_info_device_firmwares_inner_parseFromJSON(firmwares_local_nonprimitive);

        list_addElement(firmwaresList, firmwaresItem);
    }
    }


    firmware_info_device_local_var = firmware_info_device_create_internal (
        flavor && !cJSON_IsNull(flavor) ? strdup(flavor->valuestring) : NULL,
        firmwares ? firmwaresList : NULL
        );

    return firmware_info_device_local_var;
end:
    if (firmwaresList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, firmwaresList) {
            firmware_info_device_firmwares_inner_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(firmwaresList);
        firmwaresList = NULL;
    }
    return NULL;

}
