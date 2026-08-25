#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "instance_interface_status.h"


char* instance_interface_status_status_ToString(corellium_api_instance_interface_status_STATUS_e status) {
    char* statusArray[] =  { "NULL", "attached", "detached", "connected" };
    return statusArray[status];
}

corellium_api_instance_interface_status_STATUS_e instance_interface_status_status_FromString(char* status){
    int stringToReturn = 0;
    char *statusArray[] =  { "NULL", "attached", "detached", "connected" };
    size_t sizeofArray = sizeof(statusArray) / sizeof(statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(status, statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static instance_interface_status_t *instance_interface_status_create_internal(
    char *interface_id,
    char *interconnect_id,
    corellium_api_instance_interface_status_STATUS_e status
    ) {
    instance_interface_status_t *instance_interface_status_local_var = malloc(sizeof(instance_interface_status_t));
    if (!instance_interface_status_local_var) {
        return NULL;
    }
    instance_interface_status_local_var->interface_id = interface_id;
    instance_interface_status_local_var->interconnect_id = interconnect_id;
    instance_interface_status_local_var->status = status;

    instance_interface_status_local_var->_library_owned = 1;
    return instance_interface_status_local_var;
}

__attribute__((deprecated)) instance_interface_status_t *instance_interface_status_create(
    char *interface_id,
    char *interconnect_id,
    corellium_api_instance_interface_status_STATUS_e status
    ) {
    return instance_interface_status_create_internal (
        interface_id,
        interconnect_id,
        status
        );
}

void instance_interface_status_free(instance_interface_status_t *instance_interface_status) {
    if(NULL == instance_interface_status){
        return ;
    }
    if(instance_interface_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "instance_interface_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (instance_interface_status->interface_id) {
        free(instance_interface_status->interface_id);
        instance_interface_status->interface_id = NULL;
    }
    if (instance_interface_status->interconnect_id) {
        free(instance_interface_status->interconnect_id);
        instance_interface_status->interconnect_id = NULL;
    }
    free(instance_interface_status);
}

cJSON *instance_interface_status_convertToJSON(instance_interface_status_t *instance_interface_status) {
    cJSON *item = cJSON_CreateObject();

    // instance_interface_status->interface_id
    if (!instance_interface_status->interface_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "interfaceId", instance_interface_status->interface_id) == NULL) {
    goto fail; //String
    }


    // instance_interface_status->interconnect_id
    if(instance_interface_status->interconnect_id) {
    if(cJSON_AddStringToObject(item, "interconnectId", instance_interface_status->interconnect_id) == NULL) {
    goto fail; //String
    }
    }


    // instance_interface_status->status
    if (corellium_api_instance_interface_status_STATUS_NULL == instance_interface_status->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", instance_interface_status_status_ToString(instance_interface_status->status)) == NULL)
    {
    goto fail; //Enum
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

instance_interface_status_t *instance_interface_status_parseFromJSON(cJSON *instance_interface_statusJSON){

    instance_interface_status_t *instance_interface_status_local_var = NULL;

    // instance_interface_status->interface_id
    cJSON *interface_id = cJSON_GetObjectItemCaseSensitive(instance_interface_statusJSON, "interfaceId");
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

    // instance_interface_status->interconnect_id
    cJSON *interconnect_id = cJSON_GetObjectItemCaseSensitive(instance_interface_statusJSON, "interconnectId");
    if (cJSON_IsNull(interconnect_id)) {
        interconnect_id = NULL;
    }
    if (interconnect_id) { 
    if(!cJSON_IsString(interconnect_id) && !cJSON_IsNull(interconnect_id))
    {
    goto end; //String
    }
    }

    // instance_interface_status->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(instance_interface_statusJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    corellium_api_instance_interface_status_STATUS_e statusVariable;
    
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = instance_interface_status_status_FromString(status->valuestring);


    instance_interface_status_local_var = instance_interface_status_create_internal (
        strdup(interface_id->valuestring),
        interconnect_id && !cJSON_IsNull(interconnect_id) ? strdup(interconnect_id->valuestring) : NULL,
        statusVariable
        );

    return instance_interface_status_local_var;
end:
    return NULL;

}
