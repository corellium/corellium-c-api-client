#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "image_extended_device.h"



static image_extended_device_t *image_extended_device_create_internal(
    char *flavor,
    list_t *firmwares
    ) {
    image_extended_device_t *image_extended_device_local_var = malloc(sizeof(image_extended_device_t));
    if (!image_extended_device_local_var) {
        return NULL;
    }
    image_extended_device_local_var->flavor = flavor;
    image_extended_device_local_var->firmwares = firmwares;

    image_extended_device_local_var->_library_owned = 1;
    return image_extended_device_local_var;
}

__attribute__((deprecated)) image_extended_device_t *image_extended_device_create(
    char *flavor,
    list_t *firmwares
    ) {
    return image_extended_device_create_internal (
        flavor,
        firmwares
        );
}

void image_extended_device_free(image_extended_device_t *image_extended_device) {
    if(NULL == image_extended_device){
        return ;
    }
    if(image_extended_device->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "image_extended_device_free");
        return ;
    }
    listEntry_t *listEntry;
    if (image_extended_device->flavor) {
        free(image_extended_device->flavor);
        image_extended_device->flavor = NULL;
    }
    if (image_extended_device->firmwares) {
        list_ForEach(listEntry, image_extended_device->firmwares) {
            image_firmware_free(listEntry->data);
        }
        list_freeList(image_extended_device->firmwares);
        image_extended_device->firmwares = NULL;
    }
    free(image_extended_device);
}

cJSON *image_extended_device_convertToJSON(image_extended_device_t *image_extended_device) {
    cJSON *item = cJSON_CreateObject();

    // image_extended_device->flavor
    if(image_extended_device->flavor) {
    if(cJSON_AddStringToObject(item, "flavor", image_extended_device->flavor) == NULL) {
    goto fail; //String
    }
    }


    // image_extended_device->firmwares
    if(image_extended_device->firmwares) {
    cJSON *firmwares = cJSON_AddArrayToObject(item, "firmwares");
    if(firmwares == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *firmwaresListEntry;
    if (image_extended_device->firmwares) {
    list_ForEach(firmwaresListEntry, image_extended_device->firmwares) {
    cJSON *itemLocal = image_firmware_convertToJSON(firmwaresListEntry->data);
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

image_extended_device_t *image_extended_device_parseFromJSON(cJSON *image_extended_deviceJSON){

    image_extended_device_t *image_extended_device_local_var = NULL;

    // define the local list for image_extended_device->firmwares
    list_t *firmwaresList = NULL;

    // image_extended_device->flavor
    cJSON *flavor = cJSON_GetObjectItemCaseSensitive(image_extended_deviceJSON, "flavor");
    if (cJSON_IsNull(flavor)) {
        flavor = NULL;
    }
    if (flavor) { 
    if(!cJSON_IsString(flavor) && !cJSON_IsNull(flavor))
    {
    goto end; //String
    }
    }

    // image_extended_device->firmwares
    cJSON *firmwares = cJSON_GetObjectItemCaseSensitive(image_extended_deviceJSON, "firmwares");
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
        image_firmware_t *firmwaresItem = image_firmware_parseFromJSON(firmwares_local_nonprimitive);

        list_addElement(firmwaresList, firmwaresItem);
    }
    }


    image_extended_device_local_var = image_extended_device_create_internal (
        flavor && !cJSON_IsNull(flavor) ? strdup(flavor->valuestring) : NULL,
        firmwares ? firmwaresList : NULL
        );

    return image_extended_device_local_var;
end:
    if (firmwaresList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, firmwaresList) {
            image_firmware_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(firmwaresList);
        firmwaresList = NULL;
    }
    return NULL;

}
