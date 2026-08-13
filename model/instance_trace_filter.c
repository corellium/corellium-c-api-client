#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "instance_trace_filter.h"



static instance_trace_filter_t *instance_trace_filter_create_internal(
    char *trait,
    char *value
    ) {
    instance_trace_filter_t *instance_trace_filter_local_var = malloc(sizeof(instance_trace_filter_t));
    if (!instance_trace_filter_local_var) {
        return NULL;
    }
    instance_trace_filter_local_var->trait = trait;
    instance_trace_filter_local_var->value = value;

    instance_trace_filter_local_var->_library_owned = 1;
    return instance_trace_filter_local_var;
}

__attribute__((deprecated)) instance_trace_filter_t *instance_trace_filter_create(
    char *trait,
    char *value
    ) {
    return instance_trace_filter_create_internal (
        trait,
        value
        );
}

void instance_trace_filter_free(instance_trace_filter_t *instance_trace_filter) {
    if(NULL == instance_trace_filter){
        return ;
    }
    if(instance_trace_filter->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "instance_trace_filter_free");
        return ;
    }
    listEntry_t *listEntry;
    if (instance_trace_filter->trait) {
        free(instance_trace_filter->trait);
        instance_trace_filter->trait = NULL;
    }
    if (instance_trace_filter->value) {
        free(instance_trace_filter->value);
        instance_trace_filter->value = NULL;
    }
    free(instance_trace_filter);
}

cJSON *instance_trace_filter_convertToJSON(instance_trace_filter_t *instance_trace_filter) {
    cJSON *item = cJSON_CreateObject();

    // instance_trace_filter->trait
    if (!instance_trace_filter->trait) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "trait", instance_trace_filter->trait) == NULL) {
    goto fail; //String
    }


    // instance_trace_filter->value
    if (!instance_trace_filter->value) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "value", instance_trace_filter->value) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

instance_trace_filter_t *instance_trace_filter_parseFromJSON(cJSON *instance_trace_filterJSON){

    instance_trace_filter_t *instance_trace_filter_local_var = NULL;

    // instance_trace_filter->trait
    cJSON *trait = cJSON_GetObjectItemCaseSensitive(instance_trace_filterJSON, "trait");
    if (cJSON_IsNull(trait)) {
        trait = NULL;
    }
    if (!trait) {
        goto end;
    }

    
    if(!cJSON_IsString(trait))
    {
    goto end; //String
    }

    // instance_trace_filter->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(instance_trace_filterJSON, "value");
    if (cJSON_IsNull(value)) {
        value = NULL;
    }
    if (!value) {
        goto end;
    }

    
    if(!cJSON_IsString(value))
    {
    goto end; //String
    }


    instance_trace_filter_local_var = instance_trace_filter_create_internal (
        strdup(trait->valuestring),
        strdup(value->valuestring)
        );

    return instance_trace_filter_local_var;
end:
    return NULL;

}
