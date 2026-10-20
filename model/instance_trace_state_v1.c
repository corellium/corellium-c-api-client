#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "instance_trace_state_v1.h"



static instance_trace_state_v1_t *instance_trace_state_v1_create_internal(
    int enabled,
    double length,
    char *filter
    ) {
    instance_trace_state_v1_t *instance_trace_state_v1_local_var = malloc(sizeof(instance_trace_state_v1_t));
    if (!instance_trace_state_v1_local_var) {
        return NULL;
    }
    instance_trace_state_v1_local_var->enabled = enabled;
    instance_trace_state_v1_local_var->length = length;
    instance_trace_state_v1_local_var->filter = filter;

    instance_trace_state_v1_local_var->_library_owned = 1;
    return instance_trace_state_v1_local_var;
}

__attribute__((deprecated)) instance_trace_state_v1_t *instance_trace_state_v1_create(
    int enabled,
    double length,
    char *filter
    ) {
    return instance_trace_state_v1_create_internal (
        enabled,
        length,
        filter
        );
}

void instance_trace_state_v1_free(instance_trace_state_v1_t *instance_trace_state_v1) {
    if(NULL == instance_trace_state_v1){
        return ;
    }
    if(instance_trace_state_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "instance_trace_state_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (instance_trace_state_v1->filter) {
        free(instance_trace_state_v1->filter);
        instance_trace_state_v1->filter = NULL;
    }
    free(instance_trace_state_v1);
}

cJSON *instance_trace_state_v1_convertToJSON(instance_trace_state_v1_t *instance_trace_state_v1) {
    cJSON *item = cJSON_CreateObject();

    // instance_trace_state_v1->enabled
    if(instance_trace_state_v1->enabled) {
    if(cJSON_AddBoolToObject(item, "enabled", instance_trace_state_v1->enabled) == NULL) {
    goto fail; //Bool
    }
    }


    // instance_trace_state_v1->length
    if(instance_trace_state_v1->length) {
    if(cJSON_AddNumberToObject(item, "length", instance_trace_state_v1->length) == NULL) {
    goto fail; //Numeric
    }
    }


    // instance_trace_state_v1->filter
    if(instance_trace_state_v1->filter) {
    if(cJSON_AddStringToObject(item, "filter", instance_trace_state_v1->filter) == NULL) {
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

instance_trace_state_v1_t *instance_trace_state_v1_parseFromJSON(cJSON *instance_trace_state_v1JSON){

    instance_trace_state_v1_t *instance_trace_state_v1_local_var = NULL;

    // instance_trace_state_v1->enabled
    cJSON *enabled = cJSON_GetObjectItemCaseSensitive(instance_trace_state_v1JSON, "enabled");
    if (cJSON_IsNull(enabled)) {
        enabled = NULL;
    }
    if (enabled) { 
    if(!cJSON_IsBool(enabled))
    {
    goto end; //Bool
    }
    }

    // instance_trace_state_v1->length
    cJSON *length = cJSON_GetObjectItemCaseSensitive(instance_trace_state_v1JSON, "length");
    if (cJSON_IsNull(length)) {
        length = NULL;
    }
    if (length) { 
    if(!cJSON_IsNumber(length))
    {
    goto end; //Numeric
    }
    }

    // instance_trace_state_v1->filter
    cJSON *filter = cJSON_GetObjectItemCaseSensitive(instance_trace_state_v1JSON, "filter");
    if (cJSON_IsNull(filter)) {
        filter = NULL;
    }
    if (filter) { 
    if(!cJSON_IsString(filter) && !cJSON_IsNull(filter))
    {
    goto end; //String
    }
    }


    instance_trace_state_v1_local_var = instance_trace_state_v1_create_internal (
        enabled ? enabled->valueint : 0,
        length ? length->valuedouble : 0,
        filter && !cJSON_IsNull(filter) ? strdup(filter->valuestring) : NULL
        );

    return instance_trace_state_v1_local_var;
end:
    return NULL;

}
