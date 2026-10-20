#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "domain_auth_provider_response.h"



static domain_auth_provider_response_t *domain_auth_provider_response_create_internal(
    char *identifier,
    create_domain_auth_provider_response_config_t *config,
    char *provider_type,
    char *label,
    int enabled,
    char *created_by,
    int _default,
    char *authorization_url,
    char *name,
    char *created_at,
    char *updated_at
    ) {
    domain_auth_provider_response_t *domain_auth_provider_response_local_var = malloc(sizeof(domain_auth_provider_response_t));
    if (!domain_auth_provider_response_local_var) {
        return NULL;
    }
    domain_auth_provider_response_local_var->identifier = identifier;
    domain_auth_provider_response_local_var->config = config;
    domain_auth_provider_response_local_var->provider_type = provider_type;
    domain_auth_provider_response_local_var->label = label;
    domain_auth_provider_response_local_var->enabled = enabled;
    domain_auth_provider_response_local_var->created_by = created_by;
    domain_auth_provider_response_local_var->_default = _default;
    domain_auth_provider_response_local_var->authorization_url = authorization_url;
    domain_auth_provider_response_local_var->name = name;
    domain_auth_provider_response_local_var->created_at = created_at;
    domain_auth_provider_response_local_var->updated_at = updated_at;

    domain_auth_provider_response_local_var->_library_owned = 1;
    return domain_auth_provider_response_local_var;
}

__attribute__((deprecated)) domain_auth_provider_response_t *domain_auth_provider_response_create(
    char *identifier,
    create_domain_auth_provider_response_config_t *config,
    char *provider_type,
    char *label,
    int enabled,
    char *created_by,
    int _default,
    char *authorization_url,
    char *name,
    char *created_at,
    char *updated_at
    ) {
    return domain_auth_provider_response_create_internal (
        identifier,
        config,
        provider_type,
        label,
        enabled,
        created_by,
        _default,
        authorization_url,
        name,
        created_at,
        updated_at
        );
}

void domain_auth_provider_response_free(domain_auth_provider_response_t *domain_auth_provider_response) {
    if(NULL == domain_auth_provider_response){
        return ;
    }
    if(domain_auth_provider_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "domain_auth_provider_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (domain_auth_provider_response->identifier) {
        free(domain_auth_provider_response->identifier);
        domain_auth_provider_response->identifier = NULL;
    }
    if (domain_auth_provider_response->config) {
        create_domain_auth_provider_response_config_free(domain_auth_provider_response->config);
        domain_auth_provider_response->config = NULL;
    }
    if (domain_auth_provider_response->provider_type) {
        free(domain_auth_provider_response->provider_type);
        domain_auth_provider_response->provider_type = NULL;
    }
    if (domain_auth_provider_response->label) {
        free(domain_auth_provider_response->label);
        domain_auth_provider_response->label = NULL;
    }
    if (domain_auth_provider_response->created_by) {
        free(domain_auth_provider_response->created_by);
        domain_auth_provider_response->created_by = NULL;
    }
    if (domain_auth_provider_response->authorization_url) {
        free(domain_auth_provider_response->authorization_url);
        domain_auth_provider_response->authorization_url = NULL;
    }
    if (domain_auth_provider_response->name) {
        free(domain_auth_provider_response->name);
        domain_auth_provider_response->name = NULL;
    }
    if (domain_auth_provider_response->created_at) {
        free(domain_auth_provider_response->created_at);
        domain_auth_provider_response->created_at = NULL;
    }
    if (domain_auth_provider_response->updated_at) {
        free(domain_auth_provider_response->updated_at);
        domain_auth_provider_response->updated_at = NULL;
    }
    free(domain_auth_provider_response);
}

cJSON *domain_auth_provider_response_convertToJSON(domain_auth_provider_response_t *domain_auth_provider_response) {
    cJSON *item = cJSON_CreateObject();

    // domain_auth_provider_response->identifier
    if (!domain_auth_provider_response->identifier) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "identifier", domain_auth_provider_response->identifier) == NULL) {
    goto fail; //String
    }


    // domain_auth_provider_response->config
    if(domain_auth_provider_response->config) {
    cJSON *config_local_JSON = create_domain_auth_provider_response_config_convertToJSON(domain_auth_provider_response->config);
    if(config_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "config", config_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // domain_auth_provider_response->provider_type
    if (!domain_auth_provider_response->provider_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "providerType", domain_auth_provider_response->provider_type) == NULL) {
    goto fail; //String
    }


    // domain_auth_provider_response->label
    if (!domain_auth_provider_response->label) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "label", domain_auth_provider_response->label) == NULL) {
    goto fail; //String
    }


    // domain_auth_provider_response->enabled
    if (!domain_auth_provider_response->enabled) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "enabled", domain_auth_provider_response->enabled) == NULL) {
    goto fail; //Bool
    }


    // domain_auth_provider_response->created_by
    if(domain_auth_provider_response->created_by) {
    if(cJSON_AddStringToObject(item, "createdBy", domain_auth_provider_response->created_by) == NULL) {
    goto fail; //String
    }
    }


    // domain_auth_provider_response->_default
    if (!domain_auth_provider_response->_default) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "default", domain_auth_provider_response->_default) == NULL) {
    goto fail; //Bool
    }


    // domain_auth_provider_response->authorization_url
    if(domain_auth_provider_response->authorization_url) {
    if(cJSON_AddStringToObject(item, "authorizationUrl", domain_auth_provider_response->authorization_url) == NULL) {
    goto fail; //String
    }
    }


    // domain_auth_provider_response->name
    if(domain_auth_provider_response->name) {
    if(cJSON_AddStringToObject(item, "name", domain_auth_provider_response->name) == NULL) {
    goto fail; //String
    }
    }


    // domain_auth_provider_response->created_at
    if(domain_auth_provider_response->created_at) {
    if(cJSON_AddStringToObject(item, "createdAt", domain_auth_provider_response->created_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // domain_auth_provider_response->updated_at
    if(domain_auth_provider_response->updated_at) {
    if(cJSON_AddStringToObject(item, "updatedAt", domain_auth_provider_response->updated_at) == NULL) {
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

domain_auth_provider_response_t *domain_auth_provider_response_parseFromJSON(cJSON *domain_auth_provider_responseJSON){

    domain_auth_provider_response_t *domain_auth_provider_response_local_var = NULL;

    // define the local variable for domain_auth_provider_response->config
    create_domain_auth_provider_response_config_t *config_local_nonprim = NULL;

    // domain_auth_provider_response->identifier
    cJSON *identifier = cJSON_GetObjectItemCaseSensitive(domain_auth_provider_responseJSON, "identifier");
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

    // domain_auth_provider_response->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(domain_auth_provider_responseJSON, "config");
    if (cJSON_IsNull(config)) {
        config = NULL;
    }
    if (config) { 
    config_local_nonprim = create_domain_auth_provider_response_config_parseFromJSON(config); //nonprimitive
    }

    // domain_auth_provider_response->provider_type
    cJSON *provider_type = cJSON_GetObjectItemCaseSensitive(domain_auth_provider_responseJSON, "providerType");
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

    // domain_auth_provider_response->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(domain_auth_provider_responseJSON, "label");
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

    // domain_auth_provider_response->enabled
    cJSON *enabled = cJSON_GetObjectItemCaseSensitive(domain_auth_provider_responseJSON, "enabled");
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

    // domain_auth_provider_response->created_by
    cJSON *created_by = cJSON_GetObjectItemCaseSensitive(domain_auth_provider_responseJSON, "createdBy");
    if (cJSON_IsNull(created_by)) {
        created_by = NULL;
    }
    if (created_by) { 
    if(!cJSON_IsString(created_by) && !cJSON_IsNull(created_by))
    {
    goto end; //String
    }
    }

    // domain_auth_provider_response->_default
    cJSON *_default = cJSON_GetObjectItemCaseSensitive(domain_auth_provider_responseJSON, "default");
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

    // domain_auth_provider_response->authorization_url
    cJSON *authorization_url = cJSON_GetObjectItemCaseSensitive(domain_auth_provider_responseJSON, "authorizationUrl");
    if (cJSON_IsNull(authorization_url)) {
        authorization_url = NULL;
    }
    if (authorization_url) { 
    if(!cJSON_IsString(authorization_url) && !cJSON_IsNull(authorization_url))
    {
    goto end; //String
    }
    }

    // domain_auth_provider_response->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(domain_auth_provider_responseJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // domain_auth_provider_response->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(domain_auth_provider_responseJSON, "createdAt");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (created_at) { 
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //DateTime
    }
    }

    // domain_auth_provider_response->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(domain_auth_provider_responseJSON, "updatedAt");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (updated_at) { 
    if(!cJSON_IsString(updated_at) && !cJSON_IsNull(updated_at))
    {
    goto end; //DateTime
    }
    }


    domain_auth_provider_response_local_var = domain_auth_provider_response_create_internal (
        strdup(identifier->valuestring),
        config ? config_local_nonprim : NULL,
        strdup(provider_type->valuestring),
        strdup(label->valuestring),
        enabled->valueint,
        created_by && !cJSON_IsNull(created_by) ? strdup(created_by->valuestring) : NULL,
        _default->valueint,
        authorization_url && !cJSON_IsNull(authorization_url) ? strdup(authorization_url->valuestring) : NULL,
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        created_at && !cJSON_IsNull(created_at) ? strdup(created_at->valuestring) : NULL,
        updated_at && !cJSON_IsNull(updated_at) ? strdup(updated_at->valuestring) : NULL
        );

    return domain_auth_provider_response_local_var;
end:
    if (config_local_nonprim) {
        create_domain_auth_provider_response_config_free(config_local_nonprim);
        config_local_nonprim = NULL;
    }
    return NULL;

}
