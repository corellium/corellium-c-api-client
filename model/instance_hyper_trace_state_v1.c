#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "instance_hyper_trace_state_v1.h"


char* instance_hyper_trace_state_v1_enabled_ToString(corellium_api_instance_hyper_trace_state_v1_ENABLED_e enabled) {
    char* enabledArray[] =  { "NULL", "enabling", "enabled", "disabling", "disabled" };
    return enabledArray[enabled];
}

corellium_api_instance_hyper_trace_state_v1_ENABLED_e instance_hyper_trace_state_v1_enabled_FromString(char* enabled){
    int stringToReturn = 0;
    char *enabledArray[] =  { "NULL", "enabling", "enabled", "disabling", "disabled" };
    size_t sizeofArray = sizeof(enabledArray) / sizeof(enabledArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(enabled, enabledArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static instance_hyper_trace_state_v1_t *instance_hyper_trace_state_v1_create_internal(
    corellium_api_instance_hyper_trace_state_v1_ENABLED_e enabled,
    double length,
    char *filter
    ) {
    instance_hyper_trace_state_v1_t *instance_hyper_trace_state_v1_local_var = malloc(sizeof(instance_hyper_trace_state_v1_t));
    if (!instance_hyper_trace_state_v1_local_var) {
        return NULL;
    }
    instance_hyper_trace_state_v1_local_var->enabled = enabled;
    instance_hyper_trace_state_v1_local_var->length = length;
    instance_hyper_trace_state_v1_local_var->filter = filter;

    instance_hyper_trace_state_v1_local_var->_library_owned = 1;
    return instance_hyper_trace_state_v1_local_var;
}

__attribute__((deprecated)) instance_hyper_trace_state_v1_t *instance_hyper_trace_state_v1_create(
    corellium_api_instance_hyper_trace_state_v1_ENABLED_e enabled,
    double length,
    char *filter
    ) {
    return instance_hyper_trace_state_v1_create_internal (
        enabled,
        length,
        filter
        );
}

void instance_hyper_trace_state_v1_free(instance_hyper_trace_state_v1_t *instance_hyper_trace_state_v1) {
    if(NULL == instance_hyper_trace_state_v1){
        return ;
    }
    if(instance_hyper_trace_state_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "instance_hyper_trace_state_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (instance_hyper_trace_state_v1->filter) {
        free(instance_hyper_trace_state_v1->filter);
        instance_hyper_trace_state_v1->filter = NULL;
    }
    free(instance_hyper_trace_state_v1);
}

cJSON *instance_hyper_trace_state_v1_convertToJSON(instance_hyper_trace_state_v1_t *instance_hyper_trace_state_v1) {
    cJSON *item = cJSON_CreateObject();

    // instance_hyper_trace_state_v1->enabled
    if(instance_hyper_trace_state_v1->enabled != corellium_api_instance_hyper_trace_state_v1_ENABLED_NULL) {
    if(cJSON_AddStringToObject(item, "enabled", instance_hyper_trace_state_v1_enabled_ToString(instance_hyper_trace_state_v1->enabled)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // instance_hyper_trace_state_v1->length
    if(instance_hyper_trace_state_v1->length) {
    if(cJSON_AddNumberToObject(item, "length", instance_hyper_trace_state_v1->length) == NULL) {
    goto fail; //Numeric
    }
    }


    // instance_hyper_trace_state_v1->filter
    if(instance_hyper_trace_state_v1->filter) {
    if(cJSON_AddStringToObject(item, "filter", instance_hyper_trace_state_v1->filter) == NULL) {
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

instance_hyper_trace_state_v1_t *instance_hyper_trace_state_v1_parseFromJSON(cJSON *instance_hyper_trace_state_v1JSON){

    instance_hyper_trace_state_v1_t *instance_hyper_trace_state_v1_local_var = NULL;

    // instance_hyper_trace_state_v1->enabled
    cJSON *enabled = cJSON_GetObjectItemCaseSensitive(instance_hyper_trace_state_v1JSON, "enabled");
    if (cJSON_IsNull(enabled)) {
        enabled = NULL;
    }
    corellium_api_instance_hyper_trace_state_v1_ENABLED_e enabledVariable;
    if (enabled) { 
    if(!cJSON_IsString(enabled))
    {
    goto end; //Enum
    }
    enabledVariable = instance_hyper_trace_state_v1_enabled_FromString(enabled->valuestring);
    }

    // instance_hyper_trace_state_v1->length
    cJSON *length = cJSON_GetObjectItemCaseSensitive(instance_hyper_trace_state_v1JSON, "length");
    if (cJSON_IsNull(length)) {
        length = NULL;
    }
    if (length) { 
    if(!cJSON_IsNumber(length))
    {
    goto end; //Numeric
    }
    }

    // instance_hyper_trace_state_v1->filter
    cJSON *filter = cJSON_GetObjectItemCaseSensitive(instance_hyper_trace_state_v1JSON, "filter");
    if (cJSON_IsNull(filter)) {
        filter = NULL;
    }
    if (filter) { 
    if(!cJSON_IsString(filter) && !cJSON_IsNull(filter))
    {
    goto end; //String
    }
    }


    instance_hyper_trace_state_v1_local_var = instance_hyper_trace_state_v1_create_internal (
        enabled ? enabledVariable : corellium_api_instance_hyper_trace_state_v1_ENABLED_NULL,
        length ? length->valuedouble : 0,
        filter && !cJSON_IsNull(filter) ? strdup(filter->valuestring) : NULL
        );

    return instance_hyper_trace_state_v1_local_var;
end:
    return NULL;

}
