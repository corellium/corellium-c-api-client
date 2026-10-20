#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "firmware_service_config_cache_firmware.h"



static firmware_service_config_cache_firmware_t *firmware_service_config_cache_firmware_create_internal(
    int value,
    char *component,
    char *title,
    char *description,
    char *type
    ) {
    firmware_service_config_cache_firmware_t *firmware_service_config_cache_firmware_local_var = malloc(sizeof(firmware_service_config_cache_firmware_t));
    if (!firmware_service_config_cache_firmware_local_var) {
        return NULL;
    }
    firmware_service_config_cache_firmware_local_var->value = value;
    firmware_service_config_cache_firmware_local_var->component = component;
    firmware_service_config_cache_firmware_local_var->title = title;
    firmware_service_config_cache_firmware_local_var->description = description;
    firmware_service_config_cache_firmware_local_var->type = type;

    firmware_service_config_cache_firmware_local_var->_library_owned = 1;
    return firmware_service_config_cache_firmware_local_var;
}

__attribute__((deprecated)) firmware_service_config_cache_firmware_t *firmware_service_config_cache_firmware_create(
    int value,
    char *component,
    char *title,
    char *description,
    char *type
    ) {
    return firmware_service_config_cache_firmware_create_internal (
        value,
        component,
        title,
        description,
        type
        );
}

void firmware_service_config_cache_firmware_free(firmware_service_config_cache_firmware_t *firmware_service_config_cache_firmware) {
    if(NULL == firmware_service_config_cache_firmware){
        return ;
    }
    if(firmware_service_config_cache_firmware->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "firmware_service_config_cache_firmware_free");
        return ;
    }
    listEntry_t *listEntry;
    if (firmware_service_config_cache_firmware->component) {
        free(firmware_service_config_cache_firmware->component);
        firmware_service_config_cache_firmware->component = NULL;
    }
    if (firmware_service_config_cache_firmware->title) {
        free(firmware_service_config_cache_firmware->title);
        firmware_service_config_cache_firmware->title = NULL;
    }
    if (firmware_service_config_cache_firmware->description) {
        free(firmware_service_config_cache_firmware->description);
        firmware_service_config_cache_firmware->description = NULL;
    }
    if (firmware_service_config_cache_firmware->type) {
        free(firmware_service_config_cache_firmware->type);
        firmware_service_config_cache_firmware->type = NULL;
    }
    free(firmware_service_config_cache_firmware);
}

cJSON *firmware_service_config_cache_firmware_convertToJSON(firmware_service_config_cache_firmware_t *firmware_service_config_cache_firmware) {
    cJSON *item = cJSON_CreateObject();

    // firmware_service_config_cache_firmware->value
    if (!firmware_service_config_cache_firmware->value) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "value", firmware_service_config_cache_firmware->value) == NULL) {
    goto fail; //Bool
    }


    // firmware_service_config_cache_firmware->component
    if(firmware_service_config_cache_firmware->component) {
    if(cJSON_AddStringToObject(item, "component", firmware_service_config_cache_firmware->component) == NULL) {
    goto fail; //String
    }
    }


    // firmware_service_config_cache_firmware->title
    if(firmware_service_config_cache_firmware->title) {
    if(cJSON_AddStringToObject(item, "title", firmware_service_config_cache_firmware->title) == NULL) {
    goto fail; //String
    }
    }


    // firmware_service_config_cache_firmware->description
    if(firmware_service_config_cache_firmware->description) {
    if(cJSON_AddStringToObject(item, "description", firmware_service_config_cache_firmware->description) == NULL) {
    goto fail; //String
    }
    }


    // firmware_service_config_cache_firmware->type
    if(firmware_service_config_cache_firmware->type) {
    if(cJSON_AddStringToObject(item, "type", firmware_service_config_cache_firmware->type) == NULL) {
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

firmware_service_config_cache_firmware_t *firmware_service_config_cache_firmware_parseFromJSON(cJSON *firmware_service_config_cache_firmwareJSON){

    firmware_service_config_cache_firmware_t *firmware_service_config_cache_firmware_local_var = NULL;

    // firmware_service_config_cache_firmware->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(firmware_service_config_cache_firmwareJSON, "value");
    if (cJSON_IsNull(value)) {
        value = NULL;
    }
    if (!value) {
        goto end;
    }

    
    if(!cJSON_IsBool(value))
    {
    goto end; //Bool
    }

    // firmware_service_config_cache_firmware->component
    cJSON *component = cJSON_GetObjectItemCaseSensitive(firmware_service_config_cache_firmwareJSON, "component");
    if (cJSON_IsNull(component)) {
        component = NULL;
    }
    if (component) { 
    if(!cJSON_IsString(component) && !cJSON_IsNull(component))
    {
    goto end; //String
    }
    }

    // firmware_service_config_cache_firmware->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(firmware_service_config_cache_firmwareJSON, "title");
    if (cJSON_IsNull(title)) {
        title = NULL;
    }
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }

    // firmware_service_config_cache_firmware->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(firmware_service_config_cache_firmwareJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // firmware_service_config_cache_firmware->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(firmware_service_config_cache_firmwareJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (type) { 
    if(!cJSON_IsString(type) && !cJSON_IsNull(type))
    {
    goto end; //String
    }
    }


    firmware_service_config_cache_firmware_local_var = firmware_service_config_cache_firmware_create_internal (
        value->valueint,
        component && !cJSON_IsNull(component) ? strdup(component->valuestring) : NULL,
        title && !cJSON_IsNull(title) ? strdup(title->valuestring) : NULL,
        description && !cJSON_IsNull(description) ? strdup(description->valuestring) : NULL,
        type && !cJSON_IsNull(type) ? strdup(type->valuestring) : NULL
        );

    return firmware_service_config_cache_firmware_local_var;
end:
    return NULL;

}
