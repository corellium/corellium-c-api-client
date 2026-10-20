#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "coordinator_config.h"



static coordinator_config_t *coordinator_config_create_internal(
    int usb_media_access_enabled
    ) {
    coordinator_config_t *coordinator_config_local_var = malloc(sizeof(coordinator_config_t));
    if (!coordinator_config_local_var) {
        return NULL;
    }
    coordinator_config_local_var->usb_media_access_enabled = usb_media_access_enabled;

    coordinator_config_local_var->_library_owned = 1;
    return coordinator_config_local_var;
}

__attribute__((deprecated)) coordinator_config_t *coordinator_config_create(
    int usb_media_access_enabled
    ) {
    return coordinator_config_create_internal (
        usb_media_access_enabled
        );
}

void coordinator_config_free(coordinator_config_t *coordinator_config) {
    if(NULL == coordinator_config){
        return ;
    }
    if(coordinator_config->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "coordinator_config_free");
        return ;
    }
    listEntry_t *listEntry;
    free(coordinator_config);
}

cJSON *coordinator_config_convertToJSON(coordinator_config_t *coordinator_config) {
    cJSON *item = cJSON_CreateObject();

    // coordinator_config->usb_media_access_enabled
    if(coordinator_config->usb_media_access_enabled) {
    if(cJSON_AddBoolToObject(item, "usbMediaAccessEnabled", coordinator_config->usb_media_access_enabled) == NULL) {
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

coordinator_config_t *coordinator_config_parseFromJSON(cJSON *coordinator_configJSON){

    coordinator_config_t *coordinator_config_local_var = NULL;

    // coordinator_config->usb_media_access_enabled
    cJSON *usb_media_access_enabled = cJSON_GetObjectItemCaseSensitive(coordinator_configJSON, "usbMediaAccessEnabled");
    if (cJSON_IsNull(usb_media_access_enabled)) {
        usb_media_access_enabled = NULL;
    }
    if (usb_media_access_enabled) { 
    if(!cJSON_IsBool(usb_media_access_enabled))
    {
    goto end; //Bool
    }
    }


    coordinator_config_local_var = coordinator_config_create_internal (
        usb_media_access_enabled ? usb_media_access_enabled->valueint : 0
        );

    return coordinator_config_local_var;
end:
    return NULL;

}
