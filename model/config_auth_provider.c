#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "config_auth_provider.h"



static config_auth_provider_t *config_auth_provider_create_internal(
    char *name,
    char *provider_type,
    int _default,
    char *label,
    int enabled,
    char *authorization_url,
    char *identifier,
    char *provider
    ) {
    config_auth_provider_t *config_auth_provider_local_var = malloc(sizeof(config_auth_provider_t));
    if (!config_auth_provider_local_var) {
        return NULL;
    }
    config_auth_provider_local_var->name = name;
    config_auth_provider_local_var->provider_type = provider_type;
    config_auth_provider_local_var->_default = _default;
    config_auth_provider_local_var->label = label;
    config_auth_provider_local_var->enabled = enabled;
    config_auth_provider_local_var->authorization_url = authorization_url;
    config_auth_provider_local_var->identifier = identifier;
    config_auth_provider_local_var->provider = provider;

    config_auth_provider_local_var->_library_owned = 1;
    return config_auth_provider_local_var;
}

__attribute__((deprecated)) config_auth_provider_t *config_auth_provider_create(
    char *name,
    char *provider_type,
    int _default,
    char *label,
    int enabled,
    char *authorization_url,
    char *identifier,
    char *provider
    ) {
    return config_auth_provider_create_internal (
        name,
        provider_type,
        _default,
        label,
        enabled,
        authorization_url,
        identifier,
        provider
        );
}

void config_auth_provider_free(config_auth_provider_t *config_auth_provider) {
    if(NULL == config_auth_provider){
        return ;
    }
    if(config_auth_provider->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "config_auth_provider_free");
        return ;
    }
    listEntry_t *listEntry;
    if (config_auth_provider->name) {
        free(config_auth_provider->name);
        config_auth_provider->name = NULL;
    }
    if (config_auth_provider->provider_type) {
        free(config_auth_provider->provider_type);
        config_auth_provider->provider_type = NULL;
    }
    if (config_auth_provider->label) {
        free(config_auth_provider->label);
        config_auth_provider->label = NULL;
    }
    if (config_auth_provider->authorization_url) {
        free(config_auth_provider->authorization_url);
        config_auth_provider->authorization_url = NULL;
    }
    if (config_auth_provider->identifier) {
        free(config_auth_provider->identifier);
        config_auth_provider->identifier = NULL;
    }
    if (config_auth_provider->provider) {
        free(config_auth_provider->provider);
        config_auth_provider->provider = NULL;
    }
    free(config_auth_provider);
}

cJSON *config_auth_provider_convertToJSON(config_auth_provider_t *config_auth_provider) {
    cJSON *item = cJSON_CreateObject();

    // config_auth_provider->name
    if (!config_auth_provider->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", config_auth_provider->name) == NULL) {
    goto fail; //String
    }


    // config_auth_provider->provider_type
    if (!config_auth_provider->provider_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "providerType", config_auth_provider->provider_type) == NULL) {
    goto fail; //String
    }


    // config_auth_provider->_default
    if (!config_auth_provider->_default) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "default", config_auth_provider->_default) == NULL) {
    goto fail; //Bool
    }


    // config_auth_provider->label
    if (!config_auth_provider->label) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "label", config_auth_provider->label) == NULL) {
    goto fail; //String
    }


    // config_auth_provider->enabled
    if (!config_auth_provider->enabled) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "enabled", config_auth_provider->enabled) == NULL) {
    goto fail; //Bool
    }


    // config_auth_provider->authorization_url
    if (!config_auth_provider->authorization_url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "authorizationUrl", config_auth_provider->authorization_url) == NULL) {
    goto fail; //String
    }


    // config_auth_provider->identifier
    if (!config_auth_provider->identifier) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "identifier", config_auth_provider->identifier) == NULL) {
    goto fail; //String
    }


    // config_auth_provider->provider
    if (!config_auth_provider->provider) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "provider", config_auth_provider->provider) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

config_auth_provider_t *config_auth_provider_parseFromJSON(cJSON *config_auth_providerJSON){

    config_auth_provider_t *config_auth_provider_local_var = NULL;

    // config_auth_provider->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(config_auth_providerJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // config_auth_provider->provider_type
    cJSON *provider_type = cJSON_GetObjectItemCaseSensitive(config_auth_providerJSON, "providerType");
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

    // config_auth_provider->_default
    cJSON *_default = cJSON_GetObjectItemCaseSensitive(config_auth_providerJSON, "default");
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

    // config_auth_provider->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(config_auth_providerJSON, "label");
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

    // config_auth_provider->enabled
    cJSON *enabled = cJSON_GetObjectItemCaseSensitive(config_auth_providerJSON, "enabled");
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

    // config_auth_provider->authorization_url
    cJSON *authorization_url = cJSON_GetObjectItemCaseSensitive(config_auth_providerJSON, "authorizationUrl");
    if (cJSON_IsNull(authorization_url)) {
        authorization_url = NULL;
    }
    if (!authorization_url) {
        goto end;
    }

    
    if(!cJSON_IsString(authorization_url))
    {
    goto end; //String
    }

    // config_auth_provider->identifier
    cJSON *identifier = cJSON_GetObjectItemCaseSensitive(config_auth_providerJSON, "identifier");
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

    // config_auth_provider->provider
    cJSON *provider = cJSON_GetObjectItemCaseSensitive(config_auth_providerJSON, "provider");
    if (cJSON_IsNull(provider)) {
        provider = NULL;
    }
    if (!provider) {
        goto end;
    }

    
    if(!cJSON_IsString(provider))
    {
    goto end; //String
    }


    config_auth_provider_local_var = config_auth_provider_create_internal (
        strdup(name->valuestring),
        strdup(provider_type->valuestring),
        _default->valueint,
        strdup(label->valuestring),
        enabled->valueint,
        strdup(authorization_url->valuestring),
        strdup(identifier->valuestring),
        strdup(provider->valuestring)
        );

    return config_auth_provider_local_var;
end:
    return NULL;

}
