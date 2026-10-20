#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "instance_state_v1.h"


char* instance_state_v1_instance_state_v1_ToString(corellium_api_instance_state_v1__e instance_state_v1) {
    char *instance_state_v1Array[] =  { "NULL", "on", "off", "booting", "deleting", "creating", "restoring", "paused", "rebooting", "error" };
    return instance_state_v1Array[instance_state_v1];
}

corellium_api_instance_state_v1__e instance_state_v1_instance_state_v1_FromString(char* instance_state_v1) {
    int stringToReturn = 0;
    char *instance_state_v1Array[] =  { "NULL", "on", "off", "booting", "deleting", "creating", "restoring", "paused", "rebooting", "error" };
    size_t sizeofArray = sizeof(instance_state_v1Array) / sizeof(instance_state_v1Array[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(instance_state_v1, instance_state_v1Array[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *instance_state_v1_convertToJSON(corellium_api_instance_state_v1__e instance_state_v1) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "instance_state_v1", instance_state_v1_instance_state_v1_ToString(instance_state_v1)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

corellium_api_instance_state_v1__e instance_state_v1_parseFromJSON(cJSON *instance_state_v1JSON) {
    if(!cJSON_IsString(instance_state_v1JSON) || (instance_state_v1JSON->valuestring == NULL)) {
        return 0;
    }
    return instance_state_v1_instance_state_v1_FromString(instance_state_v1JSON->valuestring);
}
