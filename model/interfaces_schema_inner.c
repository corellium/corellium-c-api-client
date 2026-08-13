#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "interfaces_schema_inner.h"



static interfaces_schema_inner_t *interfaces_schema_inner_create_internal(
    char *device_id,
    char *interface_id
    ) {
    interfaces_schema_inner_t *interfaces_schema_inner_local_var = malloc(sizeof(interfaces_schema_inner_t));
    if (!interfaces_schema_inner_local_var) {
        return NULL;
    }
    interfaces_schema_inner_local_var->device_id = device_id;
    interfaces_schema_inner_local_var->interface_id = interface_id;

    interfaces_schema_inner_local_var->_library_owned = 1;
    return interfaces_schema_inner_local_var;
}

__attribute__((deprecated)) interfaces_schema_inner_t *interfaces_schema_inner_create(
    char *device_id,
    char *interface_id
    ) {
    return interfaces_schema_inner_create_internal (
        device_id,
        interface_id
        );
}

void interfaces_schema_inner_free(interfaces_schema_inner_t *interfaces_schema_inner) {
    if(NULL == interfaces_schema_inner){
        return ;
    }
    if(interfaces_schema_inner->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "interfaces_schema_inner_free");
        return ;
    }
    listEntry_t *listEntry;
    if (interfaces_schema_inner->device_id) {
        free(interfaces_schema_inner->device_id);
        interfaces_schema_inner->device_id = NULL;
    }
    if (interfaces_schema_inner->interface_id) {
        free(interfaces_schema_inner->interface_id);
        interfaces_schema_inner->interface_id = NULL;
    }
    free(interfaces_schema_inner);
}

cJSON *interfaces_schema_inner_convertToJSON(interfaces_schema_inner_t *interfaces_schema_inner) {
    cJSON *item = cJSON_CreateObject();

    // interfaces_schema_inner->device_id
    if (!interfaces_schema_inner->device_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "deviceId", interfaces_schema_inner->device_id) == NULL) {
    goto fail; //String
    }


    // interfaces_schema_inner->interface_id
    if (!interfaces_schema_inner->interface_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "interfaceId", interfaces_schema_inner->interface_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

interfaces_schema_inner_t *interfaces_schema_inner_parseFromJSON(cJSON *interfaces_schema_innerJSON){

    interfaces_schema_inner_t *interfaces_schema_inner_local_var = NULL;

    // interfaces_schema_inner->device_id
    cJSON *device_id = cJSON_GetObjectItemCaseSensitive(interfaces_schema_innerJSON, "deviceId");
    if (cJSON_IsNull(device_id)) {
        device_id = NULL;
    }
    if (!device_id) {
        goto end;
    }

    
    if(!cJSON_IsString(device_id))
    {
    goto end; //String
    }

    // interfaces_schema_inner->interface_id
    cJSON *interface_id = cJSON_GetObjectItemCaseSensitive(interfaces_schema_innerJSON, "interfaceId");
    if (cJSON_IsNull(interface_id)) {
        interface_id = NULL;
    }
    if (!interface_id) {
        goto end;
    }

    
    if(!cJSON_IsString(interface_id))
    {
    goto end; //String
    }


    interfaces_schema_inner_local_var = interfaces_schema_inner_create_internal (
        strdup(device_id->valuestring),
        strdup(interface_id->valuestring)
        );

    return interfaces_schema_inner_local_var;
end:
    return NULL;

}
