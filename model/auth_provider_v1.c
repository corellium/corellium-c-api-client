#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "auth_provider_v1.h"



static auth_provider_v1_t *auth_provider_v1_create_internal(
    char *name,
    char *identifier,
    char *provider_type,
    int _default,
    char *label,
    int enabled,
    char *authorization_url,
    char *id,
    char *provider
    ) {
    auth_provider_v1_t *auth_provider_v1_local_var = malloc(sizeof(auth_provider_v1_t));
    if (!auth_provider_v1_local_var) {
        return NULL;
    }
    auth_provider_v1_local_var->name = name;
    auth_provider_v1_local_var->identifier = identifier;
    auth_provider_v1_local_var->provider_type = provider_type;
    auth_provider_v1_local_var->_default = _default;
    auth_provider_v1_local_var->label = label;
    auth_provider_v1_local_var->enabled = enabled;
    auth_provider_v1_local_var->authorization_url = authorization_url;
    auth_provider_v1_local_var->id = id;
    auth_provider_v1_local_var->provider = provider;

    auth_provider_v1_local_var->_library_owned = 1;
    return auth_provider_v1_local_var;
}

__attribute__((deprecated)) auth_provider_v1_t *auth_provider_v1_create(
    char *name,
    char *identifier,
    char *provider_type,
    int _default,
    char *label,
    int enabled,
    char *authorization_url,
    char *id,
    char *provider
    ) {
    return auth_provider_v1_create_internal (
        name,
        identifier,
        provider_type,
        _default,
        label,
        enabled,
        authorization_url,
        id,
        provider
        );
}

void auth_provider_v1_free(auth_provider_v1_t *auth_provider_v1) {
    if(NULL == auth_provider_v1){
        return ;
    }
    if(auth_provider_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "auth_provider_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (auth_provider_v1->name) {
        free(auth_provider_v1->name);
        auth_provider_v1->name = NULL;
    }
    if (auth_provider_v1->identifier) {
        free(auth_provider_v1->identifier);
        auth_provider_v1->identifier = NULL;
    }
    if (auth_provider_v1->provider_type) {
        free(auth_provider_v1->provider_type);
        auth_provider_v1->provider_type = NULL;
    }
    if (auth_provider_v1->label) {
        free(auth_provider_v1->label);
        auth_provider_v1->label = NULL;
    }
    if (auth_provider_v1->authorization_url) {
        free(auth_provider_v1->authorization_url);
        auth_provider_v1->authorization_url = NULL;
    }
    if (auth_provider_v1->id) {
        free(auth_provider_v1->id);
        auth_provider_v1->id = NULL;
    }
    if (auth_provider_v1->provider) {
        free(auth_provider_v1->provider);
        auth_provider_v1->provider = NULL;
    }
    free(auth_provider_v1);
}

cJSON *auth_provider_v1_convertToJSON(auth_provider_v1_t *auth_provider_v1) {
    cJSON *item = cJSON_CreateObject();

    // auth_provider_v1->name
    if(auth_provider_v1->name) {
    if(cJSON_AddStringToObject(item, "name", auth_provider_v1->name) == NULL) {
    goto fail; //String
    }
    }


    // auth_provider_v1->identifier
    if(auth_provider_v1->identifier) {
    if(cJSON_AddStringToObject(item, "identifier", auth_provider_v1->identifier) == NULL) {
    goto fail; //String
    }
    }


    // auth_provider_v1->provider_type
    if(auth_provider_v1->provider_type) {
    if(cJSON_AddStringToObject(item, "providerType", auth_provider_v1->provider_type) == NULL) {
    goto fail; //String
    }
    }


    // auth_provider_v1->_default
    if(auth_provider_v1->_default) {
    if(cJSON_AddBoolToObject(item, "default", auth_provider_v1->_default) == NULL) {
    goto fail; //Bool
    }
    }


    // auth_provider_v1->label
    if(auth_provider_v1->label) {
    if(cJSON_AddStringToObject(item, "label", auth_provider_v1->label) == NULL) {
    goto fail; //String
    }
    }


    // auth_provider_v1->enabled
    if(auth_provider_v1->enabled) {
    if(cJSON_AddBoolToObject(item, "enabled", auth_provider_v1->enabled) == NULL) {
    goto fail; //Bool
    }
    }


    // auth_provider_v1->authorization_url
    if(auth_provider_v1->authorization_url) {
    if(cJSON_AddStringToObject(item, "authorizationUrl", auth_provider_v1->authorization_url) == NULL) {
    goto fail; //String
    }
    }


    // auth_provider_v1->id
    if(auth_provider_v1->id) {
    if(cJSON_AddStringToObject(item, "id", auth_provider_v1->id) == NULL) {
    goto fail; //String
    }
    }


    // auth_provider_v1->provider
    if(auth_provider_v1->provider) {
    if(cJSON_AddStringToObject(item, "provider", auth_provider_v1->provider) == NULL) {
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

auth_provider_v1_t *auth_provider_v1_parseFromJSON(cJSON *auth_provider_v1JSON){

    auth_provider_v1_t *auth_provider_v1_local_var = NULL;

    // auth_provider_v1->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(auth_provider_v1JSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // auth_provider_v1->identifier
    cJSON *identifier = cJSON_GetObjectItemCaseSensitive(auth_provider_v1JSON, "identifier");
    if (cJSON_IsNull(identifier)) {
        identifier = NULL;
    }
    if (identifier) { 
    if(!cJSON_IsString(identifier) && !cJSON_IsNull(identifier))
    {
    goto end; //String
    }
    }

    // auth_provider_v1->provider_type
    cJSON *provider_type = cJSON_GetObjectItemCaseSensitive(auth_provider_v1JSON, "providerType");
    if (cJSON_IsNull(provider_type)) {
        provider_type = NULL;
    }
    if (provider_type) { 
    if(!cJSON_IsString(provider_type) && !cJSON_IsNull(provider_type))
    {
    goto end; //String
    }
    }

    // auth_provider_v1->_default
    cJSON *_default = cJSON_GetObjectItemCaseSensitive(auth_provider_v1JSON, "default");
    if (cJSON_IsNull(_default)) {
        _default = NULL;
    }
    if (_default) { 
    if(!cJSON_IsBool(_default))
    {
    goto end; //Bool
    }
    }

    // auth_provider_v1->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(auth_provider_v1JSON, "label");
    if (cJSON_IsNull(label)) {
        label = NULL;
    }
    if (label) { 
    if(!cJSON_IsString(label) && !cJSON_IsNull(label))
    {
    goto end; //String
    }
    }

    // auth_provider_v1->enabled
    cJSON *enabled = cJSON_GetObjectItemCaseSensitive(auth_provider_v1JSON, "enabled");
    if (cJSON_IsNull(enabled)) {
        enabled = NULL;
    }
    if (enabled) { 
    if(!cJSON_IsBool(enabled))
    {
    goto end; //Bool
    }
    }

    // auth_provider_v1->authorization_url
    cJSON *authorization_url = cJSON_GetObjectItemCaseSensitive(auth_provider_v1JSON, "authorizationUrl");
    if (cJSON_IsNull(authorization_url)) {
        authorization_url = NULL;
    }
    if (authorization_url) { 
    if(!cJSON_IsString(authorization_url) && !cJSON_IsNull(authorization_url))
    {
    goto end; //String
    }
    }

    // auth_provider_v1->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(auth_provider_v1JSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (id) { 
    if(!cJSON_IsString(id) && !cJSON_IsNull(id))
    {
    goto end; //String
    }
    }

    // auth_provider_v1->provider
    cJSON *provider = cJSON_GetObjectItemCaseSensitive(auth_provider_v1JSON, "provider");
    if (cJSON_IsNull(provider)) {
        provider = NULL;
    }
    if (provider) { 
    if(!cJSON_IsString(provider) && !cJSON_IsNull(provider))
    {
    goto end; //String
    }
    }


    auth_provider_v1_local_var = auth_provider_v1_create_internal (
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        identifier && !cJSON_IsNull(identifier) ? strdup(identifier->valuestring) : NULL,
        provider_type && !cJSON_IsNull(provider_type) ? strdup(provider_type->valuestring) : NULL,
        _default ? _default->valueint : 0,
        label && !cJSON_IsNull(label) ? strdup(label->valuestring) : NULL,
        enabled ? enabled->valueint : 0,
        authorization_url && !cJSON_IsNull(authorization_url) ? strdup(authorization_url->valuestring) : NULL,
        id && !cJSON_IsNull(id) ? strdup(id->valuestring) : NULL,
        provider && !cJSON_IsNull(provider) ? strdup(provider->valuestring) : NULL
        );

    return auth_provider_v1_local_var;
end:
    return NULL;

}
