#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_domain_auth_provider_response.h"



static create_domain_auth_provider_response_t *create_domain_auth_provider_response_create_internal(
    char *identifier,
    create_domain_auth_provider_response_config_t *config,
    char *provider_type,
    char *label,
    int enabled,
    char *created_by,
    int _default,
    char *created_at,
    char *updated_at
    ) {
    create_domain_auth_provider_response_t *create_domain_auth_provider_response_local_var = malloc(sizeof(create_domain_auth_provider_response_t));
    if (!create_domain_auth_provider_response_local_var) {
        return NULL;
    }
    create_domain_auth_provider_response_local_var->identifier = identifier;
    create_domain_auth_provider_response_local_var->config = config;
    create_domain_auth_provider_response_local_var->provider_type = provider_type;
    create_domain_auth_provider_response_local_var->label = label;
    create_domain_auth_provider_response_local_var->enabled = enabled;
    create_domain_auth_provider_response_local_var->created_by = created_by;
    create_domain_auth_provider_response_local_var->_default = _default;
    create_domain_auth_provider_response_local_var->created_at = created_at;
    create_domain_auth_provider_response_local_var->updated_at = updated_at;

    create_domain_auth_provider_response_local_var->_library_owned = 1;
    return create_domain_auth_provider_response_local_var;
}

__attribute__((deprecated)) create_domain_auth_provider_response_t *create_domain_auth_provider_response_create(
    char *identifier,
    create_domain_auth_provider_response_config_t *config,
    char *provider_type,
    char *label,
    int enabled,
    char *created_by,
    int _default,
    char *created_at,
    char *updated_at
    ) {
    return create_domain_auth_provider_response_create_internal (
        identifier,
        config,
        provider_type,
        label,
        enabled,
        created_by,
        _default,
        created_at,
        updated_at
        );
}

void create_domain_auth_provider_response_free(create_domain_auth_provider_response_t *create_domain_auth_provider_response) {
    if(NULL == create_domain_auth_provider_response){
        return ;
    }
    if(create_domain_auth_provider_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "create_domain_auth_provider_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (create_domain_auth_provider_response->identifier) {
        free(create_domain_auth_provider_response->identifier);
        create_domain_auth_provider_response->identifier = NULL;
    }
    if (create_domain_auth_provider_response->config) {
        create_domain_auth_provider_response_config_free(create_domain_auth_provider_response->config);
        create_domain_auth_provider_response->config = NULL;
    }
    if (create_domain_auth_provider_response->provider_type) {
        free(create_domain_auth_provider_response->provider_type);
        create_domain_auth_provider_response->provider_type = NULL;
    }
    if (create_domain_auth_provider_response->label) {
        free(create_domain_auth_provider_response->label);
        create_domain_auth_provider_response->label = NULL;
    }
    if (create_domain_auth_provider_response->created_by) {
        free(create_domain_auth_provider_response->created_by);
        create_domain_auth_provider_response->created_by = NULL;
    }
    if (create_domain_auth_provider_response->created_at) {
        free(create_domain_auth_provider_response->created_at);
        create_domain_auth_provider_response->created_at = NULL;
    }
    if (create_domain_auth_provider_response->updated_at) {
        free(create_domain_auth_provider_response->updated_at);
        create_domain_auth_provider_response->updated_at = NULL;
    }
    free(create_domain_auth_provider_response);
}

cJSON *create_domain_auth_provider_response_convertToJSON(create_domain_auth_provider_response_t *create_domain_auth_provider_response) {
    cJSON *item = cJSON_CreateObject();

    // create_domain_auth_provider_response->identifier
    if (!create_domain_auth_provider_response->identifier) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "identifier", create_domain_auth_provider_response->identifier) == NULL) {
    goto fail; //String
    }


    // create_domain_auth_provider_response->config
    if(create_domain_auth_provider_response->config) {
    cJSON *config_local_JSON = create_domain_auth_provider_response_config_convertToJSON(create_domain_auth_provider_response->config);
    if(config_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "config", config_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // create_domain_auth_provider_response->provider_type
    if (!create_domain_auth_provider_response->provider_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "providerType", create_domain_auth_provider_response->provider_type) == NULL) {
    goto fail; //String
    }


    // create_domain_auth_provider_response->label
    if (!create_domain_auth_provider_response->label) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "label", create_domain_auth_provider_response->label) == NULL) {
    goto fail; //String
    }


    // create_domain_auth_provider_response->enabled
    if (!create_domain_auth_provider_response->enabled) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "enabled", create_domain_auth_provider_response->enabled) == NULL) {
    goto fail; //Bool
    }


    // create_domain_auth_provider_response->created_by
    if(create_domain_auth_provider_response->created_by) {
    if(cJSON_AddStringToObject(item, "createdBy", create_domain_auth_provider_response->created_by) == NULL) {
    goto fail; //String
    }
    }


    // create_domain_auth_provider_response->_default
    if (!create_domain_auth_provider_response->_default) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "default", create_domain_auth_provider_response->_default) == NULL) {
    goto fail; //Bool
    }


    // create_domain_auth_provider_response->created_at
    if(create_domain_auth_provider_response->created_at) {
    if(cJSON_AddStringToObject(item, "createdAt", create_domain_auth_provider_response->created_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // create_domain_auth_provider_response->updated_at
    if(create_domain_auth_provider_response->updated_at) {
    if(cJSON_AddStringToObject(item, "updatedAt", create_domain_auth_provider_response->updated_at) == NULL) {
    goto fail; //Date-Time
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

create_domain_auth_provider_response_t *create_domain_auth_provider_response_parseFromJSON(cJSON *create_domain_auth_provider_responseJSON){

    create_domain_auth_provider_response_t *create_domain_auth_provider_response_local_var = NULL;

    // define the local variable for create_domain_auth_provider_response->config
    create_domain_auth_provider_response_config_t *config_local_nonprim = NULL;

    // create_domain_auth_provider_response->identifier
    cJSON *identifier = cJSON_GetObjectItemCaseSensitive(create_domain_auth_provider_responseJSON, "identifier");
    if (cJSON_IsNull(identifier)) {
        identifier = NULL;
    }
    if (!identifier) {
        goto end;
    }

    
    if(!cJSON_IsString(identifier))
    {
    goto end; //String
    }

    // create_domain_auth_provider_response->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(create_domain_auth_provider_responseJSON, "config");
    if (cJSON_IsNull(config)) {
        config = NULL;
    }
    if (config) { 
    config_local_nonprim = create_domain_auth_provider_response_config_parseFromJSON(config); //nonprimitive
    }

    // create_domain_auth_provider_response->provider_type
    cJSON *provider_type = cJSON_GetObjectItemCaseSensitive(create_domain_auth_provider_responseJSON, "providerType");
    if (cJSON_IsNull(provider_type)) {
        provider_type = NULL;
    }
    if (!provider_type) {
        goto end;
    }

    
    if(!cJSON_IsString(provider_type))
    {
    goto end; //String
    }

    // create_domain_auth_provider_response->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(create_domain_auth_provider_responseJSON, "label");
    if (cJSON_IsNull(label)) {
        label = NULL;
    }
    if (!label) {
        goto end;
    }

    
    if(!cJSON_IsString(label))
    {
    goto end; //String
    }

    // create_domain_auth_provider_response->enabled
    cJSON *enabled = cJSON_GetObjectItemCaseSensitive(create_domain_auth_provider_responseJSON, "enabled");
    if (cJSON_IsNull(enabled)) {
        enabled = NULL;
    }
    if (!enabled) {
        goto end;
    }

    
    if(!cJSON_IsBool(enabled))
    {
    goto end; //Bool
    }

    // create_domain_auth_provider_response->created_by
    cJSON *created_by = cJSON_GetObjectItemCaseSensitive(create_domain_auth_provider_responseJSON, "createdBy");
    if (cJSON_IsNull(created_by)) {
        created_by = NULL;
    }
    if (created_by) { 
    if(!cJSON_IsString(created_by) && !cJSON_IsNull(created_by))
    {
    goto end; //String
    }
    }

    // create_domain_auth_provider_response->_default
    cJSON *_default = cJSON_GetObjectItemCaseSensitive(create_domain_auth_provider_responseJSON, "default");
    if (cJSON_IsNull(_default)) {
        _default = NULL;
    }
    if (!_default) {
        goto end;
    }

    
    if(!cJSON_IsBool(_default))
    {
    goto end; //Bool
    }

    // create_domain_auth_provider_response->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(create_domain_auth_provider_responseJSON, "createdAt");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (created_at) { 
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //DateTime
    }
    }

    // create_domain_auth_provider_response->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(create_domain_auth_provider_responseJSON, "updatedAt");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (updated_at) { 
    if(!cJSON_IsString(updated_at) && !cJSON_IsNull(updated_at))
    {
    goto end; //DateTime
    }
    }


    create_domain_auth_provider_response_local_var = create_domain_auth_provider_response_create_internal (
        strdup(identifier->valuestring),
        config ? config_local_nonprim : NULL,
        strdup(provider_type->valuestring),
        strdup(label->valuestring),
        enabled->valueint,
        created_by && !cJSON_IsNull(created_by) ? strdup(created_by->valuestring) : NULL,
        _default->valueint,
        created_at && !cJSON_IsNull(created_at) ? strdup(created_at->valuestring) : NULL,
        updated_at && !cJSON_IsNull(updated_at) ? strdup(updated_at->valuestring) : NULL
        );

    return create_domain_auth_provider_response_local_var;
end:
    if (config_local_nonprim) {
        create_domain_auth_provider_response_config_free(config_local_nonprim);
        config_local_nonprim = NULL;
    }
    return NULL;

}
