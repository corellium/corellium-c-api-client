#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "instance_interface.h"



static instance_interface_t *instance_interface_create_internal(
    char *device_id,
    char *interface_id
    ) {
    instance_interface_t *instance_interface_local_var = malloc(sizeof(instance_interface_t));
    if (!instance_interface_local_var) {
        return NULL;
    }
    instance_interface_local_var->device_id = device_id;
    instance_interface_local_var->interface_id = interface_id;

    instance_interface_local_var->_library_owned = 1;
    return instance_interface_local_var;
}

__attribute__((deprecated)) instance_interface_t *instance_interface_create(
    char *device_id,
    char *interface_id
    ) {
    return instance_interface_create_internal (
        device_id,
        interface_id
        );
}

void instance_interface_free(instance_interface_t *instance_interface) {
    if(NULL == instance_interface){
        return ;
    }
    if(instance_interface->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "instance_interface_free");
        return ;
    }
    listEntry_t *listEntry;
    if (instance_interface->device_id) {
        free(instance_interface->device_id);
        instance_interface->device_id = NULL;
    }
    if (instance_interface->interface_id) {
        free(instance_interface->interface_id);
        instance_interface->interface_id = NULL;
    }
    free(instance_interface);
}

cJSON *instance_interface_convertToJSON(instance_interface_t *instance_interface) {
    cJSON *item = cJSON_CreateObject();

    // instance_interface->device_id
    if(instance_interface->device_id) {
    if(cJSON_AddStringToObject(item, "deviceId", instance_interface->device_id) == NULL) {
    goto fail; //String
    }
    }


    // instance_interface->interface_id
    if(instance_interface->interface_id) {
    if(cJSON_AddStringToObject(item, "interfaceId", instance_interface->interface_id) == NULL) {
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

instance_interface_t *instance_interface_parseFromJSON(cJSON *instance_interfaceJSON){

    instance_interface_t *instance_interface_local_var = NULL;

    // instance_interface->device_id
    cJSON *device_id = cJSON_GetObjectItemCaseSensitive(instance_interfaceJSON, "deviceId");
    if (cJSON_IsNull(device_id)) {
        device_id = NULL;
    }
    if (device_id) { 
    if(!cJSON_IsString(device_id) && !cJSON_IsNull(device_id))
    {
    goto end; //String
    }
    }

    // instance_interface->interface_id
    cJSON *interface_id = cJSON_GetObjectItemCaseSensitive(instance_interfaceJSON, "interfaceId");
    if (cJSON_IsNull(interface_id)) {
        interface_id = NULL;
    }
    if (interface_id) { 
    if(!cJSON_IsString(interface_id) && !cJSON_IsNull(interface_id))
    {
    goto end; //String
    }
    }


    instance_interface_local_var = instance_interface_create_internal (
        device_id && !cJSON_IsNull(device_id) ? strdup(device_id->valuestring) : NULL,
        interface_id && !cJSON_IsNull(interface_id) ? strdup(interface_id->valuestring) : NULL
        );

    return instance_interface_local_var;
end:
    return NULL;

}
