#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "firmware_service_config_download_ipsw_filters.h"



static firmware_service_config_download_ipsw_filters_t *firmware_service_config_download_ipsw_filters_create_internal(
    list_t *value,
    char *component,
    char *title,
    char *description,
    char *type
    ) {
    firmware_service_config_download_ipsw_filters_t *firmware_service_config_download_ipsw_filters_local_var = malloc(sizeof(firmware_service_config_download_ipsw_filters_t));
    if (!firmware_service_config_download_ipsw_filters_local_var) {
        return NULL;
    }
    firmware_service_config_download_ipsw_filters_local_var->value = value;
    firmware_service_config_download_ipsw_filters_local_var->component = component;
    firmware_service_config_download_ipsw_filters_local_var->title = title;
    firmware_service_config_download_ipsw_filters_local_var->description = description;
    firmware_service_config_download_ipsw_filters_local_var->type = type;

    firmware_service_config_download_ipsw_filters_local_var->_library_owned = 1;
    return firmware_service_config_download_ipsw_filters_local_var;
}

__attribute__((deprecated)) firmware_service_config_download_ipsw_filters_t *firmware_service_config_download_ipsw_filters_create(
    list_t *value,
    char *component,
    char *title,
    char *description,
    char *type
    ) {
    return firmware_service_config_download_ipsw_filters_create_internal (
        value,
        component,
        title,
        description,
        type
        );
}

void firmware_service_config_download_ipsw_filters_free(firmware_service_config_download_ipsw_filters_t *firmware_service_config_download_ipsw_filters) {
    if(NULL == firmware_service_config_download_ipsw_filters){
        return ;
    }
    if(firmware_service_config_download_ipsw_filters->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "firmware_service_config_download_ipsw_filters_free");
        return ;
    }
    listEntry_t *listEntry;
    if (firmware_service_config_download_ipsw_filters->value) {
        list_ForEach(listEntry, firmware_service_config_download_ipsw_filters->value) {
            ipsw_filter_v3_free(listEntry->data);
        }
        list_freeList(firmware_service_config_download_ipsw_filters->value);
        firmware_service_config_download_ipsw_filters->value = NULL;
    }
    if (firmware_service_config_download_ipsw_filters->component) {
        free(firmware_service_config_download_ipsw_filters->component);
        firmware_service_config_download_ipsw_filters->component = NULL;
    }
    if (firmware_service_config_download_ipsw_filters->title) {
        free(firmware_service_config_download_ipsw_filters->title);
        firmware_service_config_download_ipsw_filters->title = NULL;
    }
    if (firmware_service_config_download_ipsw_filters->description) {
        free(firmware_service_config_download_ipsw_filters->description);
        firmware_service_config_download_ipsw_filters->description = NULL;
    }
    if (firmware_service_config_download_ipsw_filters->type) {
        free(firmware_service_config_download_ipsw_filters->type);
        firmware_service_config_download_ipsw_filters->type = NULL;
    }
    free(firmware_service_config_download_ipsw_filters);
}

cJSON *firmware_service_config_download_ipsw_filters_convertToJSON(firmware_service_config_download_ipsw_filters_t *firmware_service_config_download_ipsw_filters) {
    cJSON *item = cJSON_CreateObject();

    // firmware_service_config_download_ipsw_filters->value
    if (!firmware_service_config_download_ipsw_filters->value) {
        goto fail;
    }
    cJSON *value = cJSON_AddArrayToObject(item, "value");
    if(value == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *valueListEntry;
    if (firmware_service_config_download_ipsw_filters->value) {
    list_ForEach(valueListEntry, firmware_service_config_download_ipsw_filters->value) {
    cJSON *itemLocal = ipsw_filter_v3_convertToJSON(valueListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(value, itemLocal);
    }
    }


    // firmware_service_config_download_ipsw_filters->component
    if(firmware_service_config_download_ipsw_filters->component) {
    if(cJSON_AddStringToObject(item, "component", firmware_service_config_download_ipsw_filters->component) == NULL) {
    goto fail; //String
    }
    }


    // firmware_service_config_download_ipsw_filters->title
    if(firmware_service_config_download_ipsw_filters->title) {
    if(cJSON_AddStringToObject(item, "title", firmware_service_config_download_ipsw_filters->title) == NULL) {
    goto fail; //String
    }
    }


    // firmware_service_config_download_ipsw_filters->description
    if(firmware_service_config_download_ipsw_filters->description) {
    if(cJSON_AddStringToObject(item, "description", firmware_service_config_download_ipsw_filters->description) == NULL) {
    goto fail; //String
    }
    }


    // firmware_service_config_download_ipsw_filters->type
    if(firmware_service_config_download_ipsw_filters->type) {
    if(cJSON_AddStringToObject(item, "type", firmware_service_config_download_ipsw_filters->type) == NULL) {
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

firmware_service_config_download_ipsw_filters_t *firmware_service_config_download_ipsw_filters_parseFromJSON(cJSON *firmware_service_config_download_ipsw_filtersJSON){

    firmware_service_config_download_ipsw_filters_t *firmware_service_config_download_ipsw_filters_local_var = NULL;

    // define the local list for firmware_service_config_download_ipsw_filters->value
    list_t *valueList = NULL;

    // firmware_service_config_download_ipsw_filters->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(firmware_service_config_download_ipsw_filtersJSON, "value");
    if (cJSON_IsNull(value)) {
        value = NULL;
    }
    if (!value) {
        goto end;
    }

    
    cJSON *value_local_nonprimitive = NULL;
    if(!cJSON_IsArray(value)){
        goto end; //nonprimitive container
    }

    valueList = list_createList();

    cJSON_ArrayForEach(value_local_nonprimitive,value )
    {
        if(!cJSON_IsObject(value_local_nonprimitive)){
            goto end;
        }
        ipsw_filter_v3_t *valueItem = ipsw_filter_v3_parseFromJSON(value_local_nonprimitive);

        list_addElement(valueList, valueItem);
    }

    // firmware_service_config_download_ipsw_filters->component
    cJSON *component = cJSON_GetObjectItemCaseSensitive(firmware_service_config_download_ipsw_filtersJSON, "component");
    if (cJSON_IsNull(component)) {
        component = NULL;
    }
    if (component) { 
    if(!cJSON_IsString(component) && !cJSON_IsNull(component))
    {
    goto end; //String
    }
    }

    // firmware_service_config_download_ipsw_filters->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(firmware_service_config_download_ipsw_filtersJSON, "title");
    if (cJSON_IsNull(title)) {
        title = NULL;
    }
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }

    // firmware_service_config_download_ipsw_filters->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(firmware_service_config_download_ipsw_filtersJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // firmware_service_config_download_ipsw_filters->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(firmware_service_config_download_ipsw_filtersJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (type) { 
    if(!cJSON_IsString(type) && !cJSON_IsNull(type))
    {
    goto end; //String
    }
    }


    firmware_service_config_download_ipsw_filters_local_var = firmware_service_config_download_ipsw_filters_create_internal (
        valueList,
        component && !cJSON_IsNull(component) ? strdup(component->valuestring) : NULL,
        title && !cJSON_IsNull(title) ? strdup(title->valuestring) : NULL,
        description && !cJSON_IsNull(description) ? strdup(description->valuestring) : NULL,
        type && !cJSON_IsNull(type) ? strdup(type->valuestring) : NULL
        );

    return firmware_service_config_download_ipsw_filters_local_var;
end:
    if (valueList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, valueList) {
            ipsw_filter_v3_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(valueList);
        valueList = NULL;
    }
    return NULL;

}
