#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "patch_domain_auth_provider_body.h"



static patch_domain_auth_provider_body_t *patch_domain_auth_provider_body_create_internal(
    char *provider_type,
    int enabled,
    char *label,
    domain_auth_provider_config_t *config
    ) {
    patch_domain_auth_provider_body_t *patch_domain_auth_provider_body_local_var = malloc(sizeof(patch_domain_auth_provider_body_t));
    if (!patch_domain_auth_provider_body_local_var) {
        return NULL;
    }
    patch_domain_auth_provider_body_local_var->provider_type = provider_type;
    patch_domain_auth_provider_body_local_var->enabled = enabled;
    patch_domain_auth_provider_body_local_var->label = label;
    patch_domain_auth_provider_body_local_var->config = config;

    patch_domain_auth_provider_body_local_var->_library_owned = 1;
    return patch_domain_auth_provider_body_local_var;
}

__attribute__((deprecated)) patch_domain_auth_provider_body_t *patch_domain_auth_provider_body_create(
    char *provider_type,
    int enabled,
    char *label,
    domain_auth_provider_config_t *config
    ) {
    return patch_domain_auth_provider_body_create_internal (
        provider_type,
        enabled,
        label,
        config
        );
}

void patch_domain_auth_provider_body_free(patch_domain_auth_provider_body_t *patch_domain_auth_provider_body) {
    if(NULL == patch_domain_auth_provider_body){
        return ;
    }
    if(patch_domain_auth_provider_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "patch_domain_auth_provider_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (patch_domain_auth_provider_body->provider_type) {
        free(patch_domain_auth_provider_body->provider_type);
        patch_domain_auth_provider_body->provider_type = NULL;
    }
    if (patch_domain_auth_provider_body->label) {
        free(patch_domain_auth_provider_body->label);
        patch_domain_auth_provider_body->label = NULL;
    }
    if (patch_domain_auth_provider_body->config) {
        domain_auth_provider_config_free(patch_domain_auth_provider_body->config);
        patch_domain_auth_provider_body->config = NULL;
    }
    free(patch_domain_auth_provider_body);
}

cJSON *patch_domain_auth_provider_body_convertToJSON(patch_domain_auth_provider_body_t *patch_domain_auth_provider_body) {
    cJSON *item = cJSON_CreateObject();

    // patch_domain_auth_provider_body->provider_type
    if(patch_domain_auth_provider_body->provider_type) {
    if(cJSON_AddStringToObject(item, "providerType", patch_domain_auth_provider_body->provider_type) == NULL) {
    goto fail; //String
    }
    }


    // patch_domain_auth_provider_body->enabled
    if(patch_domain_auth_provider_body->enabled) {
    if(cJSON_AddBoolToObject(item, "enabled", patch_domain_auth_provider_body->enabled) == NULL) {
    goto fail; //Bool
    }
    }


    // patch_domain_auth_provider_body->label
    if(patch_domain_auth_provider_body->label) {
    if(cJSON_AddStringToObject(item, "label", patch_domain_auth_provider_body->label) == NULL) {
    goto fail; //String
    }
    }


    // patch_domain_auth_provider_body->config
    if(patch_domain_auth_provider_body->config) {
    cJSON *config_local_JSON = domain_auth_provider_config_convertToJSON(patch_domain_auth_provider_body->config);
    if(config_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "config", config_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

patch_domain_auth_provider_body_t *patch_domain_auth_provider_body_parseFromJSON(cJSON *patch_domain_auth_provider_bodyJSON){

    patch_domain_auth_provider_body_t *patch_domain_auth_provider_body_local_var = NULL;

    // define the local variable for patch_domain_auth_provider_body->config
    domain_auth_provider_config_t *config_local_nonprim = NULL;

    // patch_domain_auth_provider_body->provider_type
    cJSON *provider_type = cJSON_GetObjectItemCaseSensitive(patch_domain_auth_provider_bodyJSON, "providerType");
    if (cJSON_IsNull(provider_type)) {
        provider_type = NULL;
    }
    if (provider_type) { 
    if(!cJSON_IsString(provider_type) && !cJSON_IsNull(provider_type))
    {
    goto end; //String
    }
    }

    // patch_domain_auth_provider_body->enabled
    cJSON *enabled = cJSON_GetObjectItemCaseSensitive(patch_domain_auth_provider_bodyJSON, "enabled");
    if (cJSON_IsNull(enabled)) {
        enabled = NULL;
    }
    if (enabled) { 
    if(!cJSON_IsBool(enabled))
    {
    goto end; //Bool
    }
    }

    // patch_domain_auth_provider_body->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(patch_domain_auth_provider_bodyJSON, "label");
    if (cJSON_IsNull(label)) {
        label = NULL;
    }
    if (label) { 
    if(!cJSON_IsString(label) && !cJSON_IsNull(label))
    {
    goto end; //String
    }
    }

    // patch_domain_auth_provider_body->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(patch_domain_auth_provider_bodyJSON, "config");
    if (cJSON_IsNull(config)) {
        config = NULL;
    }
    if (config) { 
    config_local_nonprim = domain_auth_provider_config_parseFromJSON(config); //nonprimitive
    }


    patch_domain_auth_provider_body_local_var = patch_domain_auth_provider_body_create_internal (
        provider_type && !cJSON_IsNull(provider_type) ? strdup(provider_type->valuestring) : NULL,
        enabled ? enabled->valueint : 0,
        label && !cJSON_IsNull(label) ? strdup(label->valuestring) : NULL,
        config ? config_local_nonprim : NULL
        );

    return patch_domain_auth_provider_body_local_var;
end:
    if (config_local_nonprim) {
        domain_auth_provider_config_free(config_local_nonprim);
        config_local_nonprim = NULL;
    }
    return NULL;

}
