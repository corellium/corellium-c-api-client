#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "device_usage.h"



static device_usage_t *device_usage_create_internal(
    double hours_used,
    double hours_max
    ) {
    device_usage_t *device_usage_local_var = malloc(sizeof(device_usage_t));
    if (!device_usage_local_var) {
        return NULL;
    }
    device_usage_local_var->hours_used = hours_used;
    device_usage_local_var->hours_max = hours_max;

    device_usage_local_var->_library_owned = 1;
    return device_usage_local_var;
}

__attribute__((deprecated)) device_usage_t *device_usage_create(
    double hours_used,
    double hours_max
    ) {
    return device_usage_create_internal (
        hours_used,
        hours_max
        );
}

void device_usage_free(device_usage_t *device_usage) {
    if(NULL == device_usage){
        return ;
    }
    if(device_usage->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "device_usage_free");
        return ;
    }
    listEntry_t *listEntry;
    free(device_usage);
}

cJSON *device_usage_convertToJSON(device_usage_t *device_usage) {
    cJSON *item = cJSON_CreateObject();

    // device_usage->hours_used
    if(device_usage->hours_used) {
    if(cJSON_AddNumberToObject(item, "hoursUsed", device_usage->hours_used) == NULL) {
    goto fail; //Numeric
    }
    }


    // device_usage->hours_max
    if(device_usage->hours_max) {
    if(cJSON_AddNumberToObject(item, "hoursMax", device_usage->hours_max) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

device_usage_t *device_usage_parseFromJSON(cJSON *device_usageJSON){

    device_usage_t *device_usage_local_var = NULL;

    // device_usage->hours_used
    cJSON *hours_used = cJSON_GetObjectItemCaseSensitive(device_usageJSON, "hoursUsed");
    if (cJSON_IsNull(hours_used)) {
        hours_used = NULL;
    }
    if (hours_used) { 
    if(!cJSON_IsNumber(hours_used))
    {
    goto end; //Numeric
    }
    }

    // device_usage->hours_max
    cJSON *hours_max = cJSON_GetObjectItemCaseSensitive(device_usageJSON, "hoursMax");
    if (cJSON_IsNull(hours_max)) {
        hours_max = NULL;
    }
    if (hours_max) { 
    if(!cJSON_IsNumber(hours_max))
    {
    goto end; //Numeric
    }
    }


    device_usage_local_var = device_usage_create_internal (
        hours_used ? hours_used->valuedouble : 0,
        hours_max ? hours_max->valuedouble : 0
        );

    return device_usage_local_var;
end:
    return NULL;

}
