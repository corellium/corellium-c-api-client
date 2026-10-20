#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "storage_already_mounted_response.h"



static storage_already_mounted_response_t *storage_already_mounted_response_create_internal(
    char *message,
    char *mount_point,
    char *device
    ) {
    storage_already_mounted_response_t *storage_already_mounted_response_local_var = malloc(sizeof(storage_already_mounted_response_t));
    if (!storage_already_mounted_response_local_var) {
        return NULL;
    }
    storage_already_mounted_response_local_var->message = message;
    storage_already_mounted_response_local_var->mount_point = mount_point;
    storage_already_mounted_response_local_var->device = device;

    storage_already_mounted_response_local_var->_library_owned = 1;
    return storage_already_mounted_response_local_var;
}

__attribute__((deprecated)) storage_already_mounted_response_t *storage_already_mounted_response_create(
    char *message,
    char *mount_point,
    char *device
    ) {
    return storage_already_mounted_response_create_internal (
        message,
        mount_point,
        device
        );
}

void storage_already_mounted_response_free(storage_already_mounted_response_t *storage_already_mounted_response) {
    if(NULL == storage_already_mounted_response){
        return ;
    }
    if(storage_already_mounted_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "storage_already_mounted_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (storage_already_mounted_response->message) {
        free(storage_already_mounted_response->message);
        storage_already_mounted_response->message = NULL;
    }
    if (storage_already_mounted_response->mount_point) {
        free(storage_already_mounted_response->mount_point);
        storage_already_mounted_response->mount_point = NULL;
    }
    if (storage_already_mounted_response->device) {
        free(storage_already_mounted_response->device);
        storage_already_mounted_response->device = NULL;
    }
    free(storage_already_mounted_response);
}

cJSON *storage_already_mounted_response_convertToJSON(storage_already_mounted_response_t *storage_already_mounted_response) {
    cJSON *item = cJSON_CreateObject();

    // storage_already_mounted_response->message
    if (!storage_already_mounted_response->message) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message", storage_already_mounted_response->message) == NULL) {
    goto fail; //String
    }


    // storage_already_mounted_response->mount_point
    if (!storage_already_mounted_response->mount_point) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "mountPoint", storage_already_mounted_response->mount_point) == NULL) {
    goto fail; //String
    }


    // storage_already_mounted_response->device
    if (!storage_already_mounted_response->device) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "device", storage_already_mounted_response->device) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

storage_already_mounted_response_t *storage_already_mounted_response_parseFromJSON(cJSON *storage_already_mounted_responseJSON){

    storage_already_mounted_response_t *storage_already_mounted_response_local_var = NULL;

    // storage_already_mounted_response->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(storage_already_mounted_responseJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (!message) {
        goto end;
    }

    
    if(!cJSON_IsString(message))
    {
    goto end; //String
    }

    // storage_already_mounted_response->mount_point
    cJSON *mount_point = cJSON_GetObjectItemCaseSensitive(storage_already_mounted_responseJSON, "mountPoint");
    if (cJSON_IsNull(mount_point)) {
        mount_point = NULL;
    }
    if (!mount_point) {
        goto end;
    }

    
    if(!cJSON_IsString(mount_point))
    {
    goto end; //String
    }

    // storage_already_mounted_response->device
    cJSON *device = cJSON_GetObjectItemCaseSensitive(storage_already_mounted_responseJSON, "device");
    if (cJSON_IsNull(device)) {
        device = NULL;
    }
    if (!device) {
        goto end;
    }

    
    if(!cJSON_IsString(device))
    {
    goto end; //String
    }


    storage_already_mounted_response_local_var = storage_already_mounted_response_create_internal (
        strdup(message->valuestring),
        strdup(mount_point->valuestring),
        strdup(device->valuestring)
        );

    return storage_already_mounted_response_local_var;
end:
    return NULL;

}
