#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "instance_hyper_trace_state.h"


char* instance_hyper_trace_state_enabled_ToString(corellium_api_instance_hyper_trace_state_ENABLED_e enabled) {
    char* enabledArray[] =  { "NULL", "enabling", "enabled", "disabling", "disabled", "" };
    return enabledArray[enabled];
}

corellium_api_instance_hyper_trace_state_ENABLED_e instance_hyper_trace_state_enabled_FromString(char* enabled){
    int stringToReturn = 0;
    char *enabledArray[] =  { "NULL", "enabling", "enabled", "disabling", "disabled", "" };
    size_t sizeofArray = sizeof(enabledArray) / sizeof(enabledArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(enabled, enabledArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static instance_hyper_trace_state_t *instance_hyper_trace_state_create_internal(
    corellium_api_instance_hyper_trace_state_ENABLED_e enabled,
    double length,
    list_t *filter
    ) {
    instance_hyper_trace_state_t *instance_hyper_trace_state_local_var = malloc(sizeof(instance_hyper_trace_state_t));
    if (!instance_hyper_trace_state_local_var) {
        return NULL;
    }
    instance_hyper_trace_state_local_var->enabled = enabled;
    instance_hyper_trace_state_local_var->length = length;
    instance_hyper_trace_state_local_var->filter = filter;

    instance_hyper_trace_state_local_var->_library_owned = 1;
    return instance_hyper_trace_state_local_var;
}

__attribute__((deprecated)) instance_hyper_trace_state_t *instance_hyper_trace_state_create(
    corellium_api_instance_hyper_trace_state_ENABLED_e enabled,
    double length,
    list_t *filter
    ) {
    return instance_hyper_trace_state_create_internal (
        enabled,
        length,
        filter
        );
}

void instance_hyper_trace_state_free(instance_hyper_trace_state_t *instance_hyper_trace_state) {
    if(NULL == instance_hyper_trace_state){
        return ;
    }
    if(instance_hyper_trace_state->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "instance_hyper_trace_state_free");
        return ;
    }
    listEntry_t *listEntry;
    if (instance_hyper_trace_state->filter) {
        list_ForEach(listEntry, instance_hyper_trace_state->filter) {
            instance_trace_filter_free(listEntry->data);
        }
        list_freeList(instance_hyper_trace_state->filter);
        instance_hyper_trace_state->filter = NULL;
    }
    free(instance_hyper_trace_state);
}

cJSON *instance_hyper_trace_state_convertToJSON(instance_hyper_trace_state_t *instance_hyper_trace_state) {
    cJSON *item = cJSON_CreateObject();

    // instance_hyper_trace_state->enabled
    if(instance_hyper_trace_state->enabled != corellium_api_instance_hyper_trace_state_ENABLED_NULL) {
    if(cJSON_AddStringToObject(item, "enabled", instance_hyper_trace_state_enabled_ToString(instance_hyper_trace_state->enabled)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // instance_hyper_trace_state->length
    if(instance_hyper_trace_state->length) {
    if(cJSON_AddNumberToObject(item, "length", instance_hyper_trace_state->length) == NULL) {
    goto fail; //Numeric
    }
    }


    // instance_hyper_trace_state->filter
    if(instance_hyper_trace_state->filter) {
    cJSON *filter = cJSON_AddArrayToObject(item, "filter");
    if(filter == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *filterListEntry;
    if (instance_hyper_trace_state->filter) {
    list_ForEach(filterListEntry, instance_hyper_trace_state->filter) {
    cJSON *itemLocal = instance_trace_filter_convertToJSON(filterListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(filter, itemLocal);
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

instance_hyper_trace_state_t *instance_hyper_trace_state_parseFromJSON(cJSON *instance_hyper_trace_stateJSON){

    instance_hyper_trace_state_t *instance_hyper_trace_state_local_var = NULL;

    // define the local list for instance_hyper_trace_state->filter
    list_t *filterList = NULL;

    // instance_hyper_trace_state->enabled
    cJSON *enabled = cJSON_GetObjectItemCaseSensitive(instance_hyper_trace_stateJSON, "enabled");
    if (cJSON_IsNull(enabled)) {
        enabled = NULL;
    }
    corellium_api_instance_hyper_trace_state_ENABLED_e enabledVariable;
    if (enabled) { 
    if(!cJSON_IsString(enabled))
    {
    goto end; //Enum
    }
    enabledVariable = instance_hyper_trace_state_enabled_FromString(enabled->valuestring);
    }

    // instance_hyper_trace_state->length
    cJSON *length = cJSON_GetObjectItemCaseSensitive(instance_hyper_trace_stateJSON, "length");
    if (cJSON_IsNull(length)) {
        length = NULL;
    }
    if (length) { 
    if(!cJSON_IsNumber(length))
    {
    goto end; //Numeric
    }
    }

    // instance_hyper_trace_state->filter
    cJSON *filter = cJSON_GetObjectItemCaseSensitive(instance_hyper_trace_stateJSON, "filter");
    if (cJSON_IsNull(filter)) {
        filter = NULL;
    }
    if (filter) { 
    cJSON *filter_local_nonprimitive = NULL;
    if(!cJSON_IsArray(filter)){
        goto end; //nonprimitive container
    }

    filterList = list_createList();

    cJSON_ArrayForEach(filter_local_nonprimitive,filter )
    {
        if(!cJSON_IsObject(filter_local_nonprimitive)){
            goto end;
        }
        instance_trace_filter_t *filterItem = instance_trace_filter_parseFromJSON(filter_local_nonprimitive);

        list_addElement(filterList, filterItem);
    }
    }


    instance_hyper_trace_state_local_var = instance_hyper_trace_state_create_internal (
        enabled ? enabledVariable : corellium_api_instance_hyper_trace_state_ENABLED_NULL,
        length ? length->valuedouble : 0,
        filter ? filterList : NULL
        );

    return instance_hyper_trace_state_local_var;
end:
    if (filterList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, filterList) {
            instance_trace_filter_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(filterList);
        filterList = NULL;
    }
    return NULL;

}
