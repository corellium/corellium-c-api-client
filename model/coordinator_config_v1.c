#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "coordinator_config_v1.h"



static coordinator_config_v1_t *coordinator_config_v1_create_internal(
    int usb_media_access_enabled
    ) {
    coordinator_config_v1_t *coordinator_config_v1_local_var = malloc(sizeof(coordinator_config_v1_t));
    if (!coordinator_config_v1_local_var) {
        return NULL;
    }
    coordinator_config_v1_local_var->usb_media_access_enabled = usb_media_access_enabled;

    coordinator_config_v1_local_var->_library_owned = 1;
    return coordinator_config_v1_local_var;
}

__attribute__((deprecated)) coordinator_config_v1_t *coordinator_config_v1_create(
    int usb_media_access_enabled
    ) {
    return coordinator_config_v1_create_internal (
        usb_media_access_enabled
        );
}

void coordinator_config_v1_free(coordinator_config_v1_t *coordinator_config_v1) {
    if(NULL == coordinator_config_v1){
        return ;
    }
    if(coordinator_config_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "coordinator_config_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    free(coordinator_config_v1);
}

cJSON *coordinator_config_v1_convertToJSON(coordinator_config_v1_t *coordinator_config_v1) {
    cJSON *item = cJSON_CreateObject();

    // coordinator_config_v1->usb_media_access_enabled
    if(coordinator_config_v1->usb_media_access_enabled) {
    if(cJSON_AddBoolToObject(item, "usbMediaAccessEnabled", coordinator_config_v1->usb_media_access_enabled) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

coordinator_config_v1_t *coordinator_config_v1_parseFromJSON(cJSON *coordinator_config_v1JSON){

    coordinator_config_v1_t *coordinator_config_v1_local_var = NULL;

    // coordinator_config_v1->usb_media_access_enabled
    cJSON *usb_media_access_enabled = cJSON_GetObjectItemCaseSensitive(coordinator_config_v1JSON, "usbMediaAccessEnabled");
    if (cJSON_IsNull(usb_media_access_enabled)) {
        usb_media_access_enabled = NULL;
    }
    if (usb_media_access_enabled) { 
    if(!cJSON_IsBool(usb_media_access_enabled))
    {
    goto end; //Bool
    }
    }


    coordinator_config_v1_local_var = coordinator_config_v1_create_internal (
        usb_media_access_enabled ? usb_media_access_enabled->valueint : 0
        );

    return coordinator_config_v1_local_var;
end:
    return NULL;

}
