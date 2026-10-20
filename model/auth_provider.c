#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "auth_provider.h"



static auth_provider_t *auth_provider_create_internal(
    char *identifier,
    char *provider_type,
    int enabled,
    int _default,
    char *label,
    char *name,
    char *authorization_url
    ) {
    auth_provider_t *auth_provider_local_var = malloc(sizeof(auth_provider_t));
    if (!auth_provider_local_var) {
        return NULL;
    }
    auth_provider_local_var->identifier = identifier;
    auth_provider_local_var->provider_type = provider_type;
    auth_provider_local_var->enabled = enabled;
    auth_provider_local_var->_default = _default;
    auth_provider_local_var->label = label;
    auth_provider_local_var->name = name;
    auth_provider_local_var->authorization_url = authorization_url;

    auth_provider_local_var->_library_owned = 1;
    return auth_provider_local_var;
}

__attribute__((deprecated)) auth_provider_t *auth_provider_create(
    char *identifier,
    char *provider_type,
    int enabled,
    int _default,
    char *label,
    char *name,
    char *authorization_url
    ) {
    return auth_provider_create_internal (
        identifier,
        provider_type,
        enabled,
        _default,
        label,
        name,
        authorization_url
        );
}

void auth_provider_free(auth_provider_t *auth_provider) {
    if(NULL == auth_provider){
        return ;
    }
    if(auth_provider->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "auth_provider_free");
        return ;
    }
    listEntry_t *listEntry;
    if (auth_provider->identifier) {
        free(auth_provider->identifier);
        auth_provider->identifier = NULL;
    }
    if (auth_provider->provider_type) {
        free(auth_provider->provider_type);
        auth_provider->provider_type = NULL;
    }
    if (auth_provider->label) {
        free(auth_provider->label);
        auth_provider->label = NULL;
    }
    if (auth_provider->name) {
        free(auth_provider->name);
        auth_provider->name = NULL;
    }
    if (auth_provider->authorization_url) {
        free(auth_provider->authorization_url);
        auth_provider->authorization_url = NULL;
    }
    free(auth_provider);
}

cJSON *auth_provider_convertToJSON(auth_provider_t *auth_provider) {
    cJSON *item = cJSON_CreateObject();

    // auth_provider->identifier
    if (!auth_provider->identifier) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "identifier", auth_provider->identifier) == NULL) {
    goto fail; //String
    }


    // auth_provider->provider_type
    if (!auth_provider->provider_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "providerType", auth_provider->provider_type) == NULL) {
    goto fail; //String
    }


    // auth_provider->enabled
    if (!auth_provider->enabled) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "enabled", auth_provider->enabled) == NULL) {
    goto fail; //Bool
    }


    // auth_provider->_default
    if (!auth_provider->_default) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "default", auth_provider->_default) == NULL) {
    goto fail; //Bool
    }


    // auth_provider->label
    if(auth_provider->label) {
    if(cJSON_AddStringToObject(item, "label", auth_provider->label) == NULL) {
    goto fail; //String
    }
    }


    // auth_provider->name
    if (!auth_provider->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", auth_provider->name) == NULL) {
    goto fail; //String
    }


    // auth_provider->authorization_url
    if (!auth_provider->authorization_url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "authorizationUrl", auth_provider->authorization_url) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

auth_provider_t *auth_provider_parseFromJSON(cJSON *auth_providerJSON){

    auth_provider_t *auth_provider_local_var = NULL;

    // auth_provider->identifier
    cJSON *identifier = cJSON_GetObjectItemCaseSensitive(auth_providerJSON, "identifier");
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

    // auth_provider->provider_type
    cJSON *provider_type = cJSON_GetObjectItemCaseSensitive(auth_providerJSON, "providerType");
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

    // auth_provider->enabled
    cJSON *enabled = cJSON_GetObjectItemCaseSensitive(auth_providerJSON, "enabled");
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

    // auth_provider->_default
    cJSON *_default = cJSON_GetObjectItemCaseSensitive(auth_providerJSON, "default");
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

    // auth_provider->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(auth_providerJSON, "label");
    if (cJSON_IsNull(label)) {
        label = NULL;
    }
    if (label) { 
    if(!cJSON_IsString(label) && !cJSON_IsNull(label))
    {
    goto end; //String
    }
    }

    // auth_provider->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(auth_providerJSON, "name");
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

    // auth_provider->authorization_url
    cJSON *authorization_url = cJSON_GetObjectItemCaseSensitive(auth_providerJSON, "authorizationUrl");
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


    auth_provider_local_var = auth_provider_create_internal (
        strdup(identifier->valuestring),
        strdup(provider_type->valuestring),
        enabled->valueint,
        _default->valueint,
        label && !cJSON_IsNull(label) ? strdup(label->valuestring) : NULL,
        strdup(name->valuestring),
        strdup(authorization_url->valuestring)
        );

    return auth_provider_local_var;
end:
    return NULL;

}
