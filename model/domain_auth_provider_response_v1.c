#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "domain_auth_provider_response_v1.h"



static domain_auth_provider_response_v1_t *domain_auth_provider_response_v1_create_internal(
    char *identifier,
    char *id,
    char *provider_type,
    char *provider,
    char *label,
    char *name,
    char *authorization_url,
    int _default,
    int enabled,
    open_id_config_v1_t *config,
    char *created_by,
    char *created_at,
    char *updated_at
    ) {
    domain_auth_provider_response_v1_t *domain_auth_provider_response_v1_local_var = malloc(sizeof(domain_auth_provider_response_v1_t));
    if (!domain_auth_provider_response_v1_local_var) {
        return NULL;
    }
    domain_auth_provider_response_v1_local_var->identifier = identifier;
    domain_auth_provider_response_v1_local_var->id = id;
    domain_auth_provider_response_v1_local_var->provider_type = provider_type;
    domain_auth_provider_response_v1_local_var->provider = provider;
    domain_auth_provider_response_v1_local_var->label = label;
    domain_auth_provider_response_v1_local_var->name = name;
    domain_auth_provider_response_v1_local_var->authorization_url = authorization_url;
    domain_auth_provider_response_v1_local_var->_default = _default;
    domain_auth_provider_response_v1_local_var->enabled = enabled;
    domain_auth_provider_response_v1_local_var->config = config;
    domain_auth_provider_response_v1_local_var->created_by = created_by;
    domain_auth_provider_response_v1_local_var->created_at = created_at;
    domain_auth_provider_response_v1_local_var->updated_at = updated_at;

    domain_auth_provider_response_v1_local_var->_library_owned = 1;
    return domain_auth_provider_response_v1_local_var;
}

__attribute__((deprecated)) domain_auth_provider_response_v1_t *domain_auth_provider_response_v1_create(
    char *identifier,
    char *id,
    char *provider_type,
    char *provider,
    char *label,
    char *name,
    char *authorization_url,
    int _default,
    int enabled,
    open_id_config_v1_t *config,
    char *created_by,
    char *created_at,
    char *updated_at
    ) {
    return domain_auth_provider_response_v1_create_internal (
        identifier,
        id,
        provider_type,
        provider,
        label,
        name,
        authorization_url,
        _default,
        enabled,
        config,
        created_by,
        created_at,
        updated_at
        );
}

void domain_auth_provider_response_v1_free(domain_auth_provider_response_v1_t *domain_auth_provider_response_v1) {
    if(NULL == domain_auth_provider_response_v1){
        return ;
    }
    if(domain_auth_provider_response_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "domain_auth_provider_response_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (domain_auth_provider_response_v1->identifier) {
        free(domain_auth_provider_response_v1->identifier);
        domain_auth_provider_response_v1->identifier = NULL;
    }
    if (domain_auth_provider_response_v1->id) {
        free(domain_auth_provider_response_v1->id);
        domain_auth_provider_response_v1->id = NULL;
    }
    if (domain_auth_provider_response_v1->provider_type) {
        free(domain_auth_provider_response_v1->provider_type);
        domain_auth_provider_response_v1->provider_type = NULL;
    }
    if (domain_auth_provider_response_v1->provider) {
        free(domain_auth_provider_response_v1->provider);
        domain_auth_provider_response_v1->provider = NULL;
    }
    if (domain_auth_provider_response_v1->label) {
        free(domain_auth_provider_response_v1->label);
        domain_auth_provider_response_v1->label = NULL;
    }
    if (domain_auth_provider_response_v1->name) {
        free(domain_auth_provider_response_v1->name);
        domain_auth_provider_response_v1->name = NULL;
    }
    if (domain_auth_provider_response_v1->authorization_url) {
        free(domain_auth_provider_response_v1->authorization_url);
        domain_auth_provider_response_v1->authorization_url = NULL;
    }
    if (domain_auth_provider_response_v1->config) {
        open_id_config_v1_free(domain_auth_provider_response_v1->config);
        domain_auth_provider_response_v1->config = NULL;
    }
    if (domain_auth_provider_response_v1->created_by) {
        free(domain_auth_provider_response_v1->created_by);
        domain_auth_provider_response_v1->created_by = NULL;
    }
    if (domain_auth_provider_response_v1->created_at) {
        free(domain_auth_provider_response_v1->created_at);
        domain_auth_provider_response_v1->created_at = NULL;
    }
    if (domain_auth_provider_response_v1->updated_at) {
        free(domain_auth_provider_response_v1->updated_at);
        domain_auth_provider_response_v1->updated_at = NULL;
    }
    free(domain_auth_provider_response_v1);
}

cJSON *domain_auth_provider_response_v1_convertToJSON(domain_auth_provider_response_v1_t *domain_auth_provider_response_v1) {
    cJSON *item = cJSON_CreateObject();

    // domain_auth_provider_response_v1->identifier
    if (!domain_auth_provider_response_v1->identifier) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "identifier", domain_auth_provider_response_v1->identifier) == NULL) {
    goto fail; //String
    }


    // domain_auth_provider_response_v1->id
    if(domain_auth_provider_response_v1->id) {
    if(cJSON_AddStringToObject(item, "id", domain_auth_provider_response_v1->id) == NULL) {
    goto fail; //String
    }
    }


    // domain_auth_provider_response_v1->provider_type
    if (!domain_auth_provider_response_v1->provider_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "providerType", domain_auth_provider_response_v1->provider_type) == NULL) {
    goto fail; //String
    }


    // domain_auth_provider_response_v1->provider
    if(domain_auth_provider_response_v1->provider) {
    if(cJSON_AddStringToObject(item, "provider", domain_auth_provider_response_v1->provider) == NULL) {
    goto fail; //String
    }
    }


    // domain_auth_provider_response_v1->label
    if (!domain_auth_provider_response_v1->label) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "label", domain_auth_provider_response_v1->label) == NULL) {
    goto fail; //String
    }


    // domain_auth_provider_response_v1->name
    if(domain_auth_provider_response_v1->name) {
    if(cJSON_AddStringToObject(item, "name", domain_auth_provider_response_v1->name) == NULL) {
    goto fail; //String
    }
    }


    // domain_auth_provider_response_v1->authorization_url
    if(domain_auth_provider_response_v1->authorization_url) {
    if(cJSON_AddStringToObject(item, "authorizationUrl", domain_auth_provider_response_v1->authorization_url) == NULL) {
    goto fail; //String
    }
    }


    // domain_auth_provider_response_v1->_default
    if (!domain_auth_provider_response_v1->_default) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "default", domain_auth_provider_response_v1->_default) == NULL) {
    goto fail; //Bool
    }


    // domain_auth_provider_response_v1->enabled
    if (!domain_auth_provider_response_v1->enabled) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "enabled", domain_auth_provider_response_v1->enabled) == NULL) {
    goto fail; //Bool
    }


    // domain_auth_provider_response_v1->config
    if(domain_auth_provider_response_v1->config) {
    cJSON *config_local_JSON = open_id_config_v1_convertToJSON(domain_auth_provider_response_v1->config);
    if(config_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "config", config_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // domain_auth_provider_response_v1->created_by
    if(domain_auth_provider_response_v1->created_by) {
    if(cJSON_AddStringToObject(item, "createdBy", domain_auth_provider_response_v1->created_by) == NULL) {
    goto fail; //String
    }
    }


    // domain_auth_provider_response_v1->created_at
    if (!domain_auth_provider_response_v1->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "createdAt", domain_auth_provider_response_v1->created_at) == NULL) {
    goto fail; //String
    }


    // domain_auth_provider_response_v1->updated_at
    if (!domain_auth_provider_response_v1->updated_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "updatedAt", domain_auth_provider_response_v1->updated_at) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

domain_auth_provider_response_v1_t *domain_auth_provider_response_v1_parseFromJSON(cJSON *domain_auth_provider_response_v1JSON){

    domain_auth_provider_response_v1_t *domain_auth_provider_response_v1_local_var = NULL;

    // define the local variable for domain_auth_provider_response_v1->config
    open_id_config_v1_t *config_local_nonprim = NULL;

    // domain_auth_provider_response_v1->identifier
    cJSON *identifier = cJSON_GetObjectItemCaseSensitive(domain_auth_provider_response_v1JSON, "identifier");
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

    // domain_auth_provider_response_v1->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(domain_auth_provider_response_v1JSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (id) { 
    if(!cJSON_IsString(id) && !cJSON_IsNull(id))
    {
    goto end; //String
    }
    }

    // domain_auth_provider_response_v1->provider_type
    cJSON *provider_type = cJSON_GetObjectItemCaseSensitive(domain_auth_provider_response_v1JSON, "providerType");
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

    // domain_auth_provider_response_v1->provider
    cJSON *provider = cJSON_GetObjectItemCaseSensitive(domain_auth_provider_response_v1JSON, "provider");
    if (cJSON_IsNull(provider)) {
        provider = NULL;
    }
    if (provider) { 
    if(!cJSON_IsString(provider) && !cJSON_IsNull(provider))
    {
    goto end; //String
    }
    }

    // domain_auth_provider_response_v1->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(domain_auth_provider_response_v1JSON, "label");
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

    // domain_auth_provider_response_v1->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(domain_auth_provider_response_v1JSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // domain_auth_provider_response_v1->authorization_url
    cJSON *authorization_url = cJSON_GetObjectItemCaseSensitive(domain_auth_provider_response_v1JSON, "authorizationUrl");
    if (cJSON_IsNull(authorization_url)) {
        authorization_url = NULL;
    }
    if (authorization_url) { 
    if(!cJSON_IsString(authorization_url) && !cJSON_IsNull(authorization_url))
    {
    goto end; //String
    }
    }

    // domain_auth_provider_response_v1->_default
    cJSON *_default = cJSON_GetObjectItemCaseSensitive(domain_auth_provider_response_v1JSON, "default");
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

    // domain_auth_provider_response_v1->enabled
    cJSON *enabled = cJSON_GetObjectItemCaseSensitive(domain_auth_provider_response_v1JSON, "enabled");
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

    // domain_auth_provider_response_v1->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(domain_auth_provider_response_v1JSON, "config");
    if (cJSON_IsNull(config)) {
        config = NULL;
    }
    if (config) { 
    config_local_nonprim = open_id_config_v1_parseFromJSON(config); //nonprimitive
    }

    // domain_auth_provider_response_v1->created_by
    cJSON *created_by = cJSON_GetObjectItemCaseSensitive(domain_auth_provider_response_v1JSON, "createdBy");
    if (cJSON_IsNull(created_by)) {
        created_by = NULL;
    }
    if (created_by) { 
    if(!cJSON_IsString(created_by) && !cJSON_IsNull(created_by))
    {
    goto end; //String
    }
    }

    // domain_auth_provider_response_v1->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(domain_auth_provider_response_v1JSON, "createdAt");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (!created_at) {
        goto end;
    }

    
    if(!cJSON_IsString(created_at))
    {
    goto end; //String
    }

    // domain_auth_provider_response_v1->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(domain_auth_provider_response_v1JSON, "updatedAt");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (!updated_at) {
        goto end;
    }

    
    if(!cJSON_IsString(updated_at))
    {
    goto end; //String
    }


    domain_auth_provider_response_v1_local_var = domain_auth_provider_response_v1_create_internal (
        strdup(identifier->valuestring),
        id && !cJSON_IsNull(id) ? strdup(id->valuestring) : NULL,
        strdup(provider_type->valuestring),
        provider && !cJSON_IsNull(provider) ? strdup(provider->valuestring) : NULL,
        strdup(label->valuestring),
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        authorization_url && !cJSON_IsNull(authorization_url) ? strdup(authorization_url->valuestring) : NULL,
        _default->valueint,
        enabled->valueint,
        config ? config_local_nonprim : NULL,
        created_by && !cJSON_IsNull(created_by) ? strdup(created_by->valuestring) : NULL,
        strdup(created_at->valuestring),
        strdup(updated_at->valuestring)
        );

    return domain_auth_provider_response_v1_local_var;
end:
    if (config_local_nonprim) {
        open_id_config_v1_free(config_local_nonprim);
        config_local_nonprim = NULL;
    }
    return NULL;

}
