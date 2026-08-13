#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "device_auto_shutdown_schema.h"



static device_auto_shutdown_schema_t *device_auto_shutdown_schema_create_internal(
    int enabled,
    double threshold
    ) {
    device_auto_shutdown_schema_t *device_auto_shutdown_schema_local_var = malloc(sizeof(device_auto_shutdown_schema_t));
    if (!device_auto_shutdown_schema_local_var) {
        return NULL;
    }
    device_auto_shutdown_schema_local_var->enabled = enabled;
    device_auto_shutdown_schema_local_var->threshold = threshold;

    device_auto_shutdown_schema_local_var->_library_owned = 1;
    return device_auto_shutdown_schema_local_var;
}

__attribute__((deprecated)) device_auto_shutdown_schema_t *device_auto_shutdown_schema_create(
    int enabled,
    double threshold
    ) {
    return device_auto_shutdown_schema_create_internal (
        enabled,
        threshold
        );
}

void device_auto_shutdown_schema_free(device_auto_shutdown_schema_t *device_auto_shutdown_schema) {
    if(NULL == device_auto_shutdown_schema){
        return ;
    }
    if(device_auto_shutdown_schema->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "device_auto_shutdown_schema_free");
        return ;
    }
    listEntry_t *listEntry;
    free(device_auto_shutdown_schema);
}

cJSON *device_auto_shutdown_schema_convertToJSON(device_auto_shutdown_schema_t *device_auto_shutdown_schema) {
    cJSON *item = cJSON_CreateObject();

    // device_auto_shutdown_schema->enabled
    if(device_auto_shutdown_schema->enabled) {
    if(cJSON_AddBoolToObject(item, "enabled", device_auto_shutdown_schema->enabled) == NULL) {
    goto fail; //Bool
    }
    }


    // device_auto_shutdown_schema->threshold
    if(device_auto_shutdown_schema->threshold) {
    if(cJSON_AddNumberToObject(item, "threshold", device_auto_shutdown_schema->threshold) == NULL) {
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

device_auto_shutdown_schema_t *device_auto_shutdown_schema_parseFromJSON(cJSON *device_auto_shutdown_schemaJSON){

    device_auto_shutdown_schema_t *device_auto_shutdown_schema_local_var = NULL;

    // device_auto_shutdown_schema->enabled
    cJSON *enabled = cJSON_GetObjectItemCaseSensitive(device_auto_shutdown_schemaJSON, "enabled");
    if (cJSON_IsNull(enabled)) {
        enabled = NULL;
    }
    if (enabled) { 
    if(!cJSON_IsBool(enabled))
    {
    goto end; //Bool
    }
    }

    // device_auto_shutdown_schema->threshold
    cJSON *threshold = cJSON_GetObjectItemCaseSensitive(device_auto_shutdown_schemaJSON, "threshold");
    if (cJSON_IsNull(threshold)) {
        threshold = NULL;
    }
    if (threshold) { 
    if(!cJSON_IsNumber(threshold))
    {
    goto end; //Numeric
    }
    }


    device_auto_shutdown_schema_local_var = device_auto_shutdown_schema_create_internal (
        enabled ? enabled->valueint : 0,
        threshold ? threshold->valuedouble : 0
        );

    return device_auto_shutdown_schema_local_var;
end:
    return NULL;

}
