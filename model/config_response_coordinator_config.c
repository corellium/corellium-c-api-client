#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "config_response_coordinator_config.h"



static config_response_coordinator_config_t *config_response_coordinator_config_create_internal(
    int usb_media_access_enabled
    ) {
    config_response_coordinator_config_t *config_response_coordinator_config_local_var = malloc(sizeof(config_response_coordinator_config_t));
    if (!config_response_coordinator_config_local_var) {
        return NULL;
    }
    config_response_coordinator_config_local_var->usb_media_access_enabled = usb_media_access_enabled;

    config_response_coordinator_config_local_var->_library_owned = 1;
    return config_response_coordinator_config_local_var;
}

__attribute__((deprecated)) config_response_coordinator_config_t *config_response_coordinator_config_create(
    int usb_media_access_enabled
    ) {
    return config_response_coordinator_config_create_internal (
        usb_media_access_enabled
        );
}

void config_response_coordinator_config_free(config_response_coordinator_config_t *config_response_coordinator_config) {
    if(NULL == config_response_coordinator_config){
        return ;
    }
    if(config_response_coordinator_config->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "config_response_coordinator_config_free");
        return ;
    }
    listEntry_t *listEntry;
    free(config_response_coordinator_config);
}

cJSON *config_response_coordinator_config_convertToJSON(config_response_coordinator_config_t *config_response_coordinator_config) {
    cJSON *item = cJSON_CreateObject();

    // config_response_coordinator_config->usb_media_access_enabled
    if(config_response_coordinator_config->usb_media_access_enabled) {
    if(cJSON_AddBoolToObject(item, "usbMediaAccessEnabled", config_response_coordinator_config->usb_media_access_enabled) == NULL) {
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

config_response_coordinator_config_t *config_response_coordinator_config_parseFromJSON(cJSON *config_response_coordinator_configJSON){

    config_response_coordinator_config_t *config_response_coordinator_config_local_var = NULL;

    // config_response_coordinator_config->usb_media_access_enabled
    cJSON *usb_media_access_enabled = cJSON_GetObjectItemCaseSensitive(config_response_coordinator_configJSON, "usbMediaAccessEnabled");
    if (cJSON_IsNull(usb_media_access_enabled)) {
        usb_media_access_enabled = NULL;
    }
    if (usb_media_access_enabled) { 
    if(!cJSON_IsBool(usb_media_access_enabled))
    {
    goto end; //Bool
    }
    }


    config_response_coordinator_config_local_var = config_response_coordinator_config_create_internal (
        usb_media_access_enabled ? usb_media_access_enabled->valueint : 0
        );

    return config_response_coordinator_config_local_var;
end:
    return NULL;

}
