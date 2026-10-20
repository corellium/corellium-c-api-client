#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "domain_auth_provider_request.h"



static domain_auth_provider_request_t *domain_auth_provider_request_create_internal(
    char *provider_type,
    int enabled,
    char *label,
    open_id_config_v1_t *config
    ) {
    domain_auth_provider_request_t *domain_auth_provider_request_local_var = malloc(sizeof(domain_auth_provider_request_t));
    if (!domain_auth_provider_request_local_var) {
        return NULL;
    }
    domain_auth_provider_request_local_var->provider_type = provider_type;
    domain_auth_provider_request_local_var->enabled = enabled;
    domain_auth_provider_request_local_var->label = label;
    domain_auth_provider_request_local_var->config = config;

    domain_auth_provider_request_local_var->_library_owned = 1;
    return domain_auth_provider_request_local_var;
}

__attribute__((deprecated)) domain_auth_provider_request_t *domain_auth_provider_request_create(
    char *provider_type,
    int enabled,
    char *label,
    open_id_config_v1_t *config
    ) {
    return domain_auth_provider_request_create_internal (
        provider_type,
        enabled,
        label,
        config
        );
}

void domain_auth_provider_request_free(domain_auth_provider_request_t *domain_auth_provider_request) {
    if(NULL == domain_auth_provider_request){
        return ;
    }
    if(domain_auth_provider_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "domain_auth_provider_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (domain_auth_provider_request->provider_type) {
        free(domain_auth_provider_request->provider_type);
        domain_auth_provider_request->provider_type = NULL;
    }
    if (domain_auth_provider_request->label) {
        free(domain_auth_provider_request->label);
        domain_auth_provider_request->label = NULL;
    }
    if (domain_auth_provider_request->config) {
        open_id_config_v1_free(domain_auth_provider_request->config);
        domain_auth_provider_request->config = NULL;
    }
    free(domain_auth_provider_request);
}

cJSON *domain_auth_provider_request_convertToJSON(domain_auth_provider_request_t *domain_auth_provider_request) {
    cJSON *item = cJSON_CreateObject();

    // domain_auth_provider_request->provider_type
    if (!domain_auth_provider_request->provider_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "providerType", domain_auth_provider_request->provider_type) == NULL) {
    goto fail; //String
    }


    // domain_auth_provider_request->enabled
    if (!domain_auth_provider_request->enabled) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "enabled", domain_auth_provider_request->enabled) == NULL) {
    goto fail; //Bool
    }


    // domain_auth_provider_request->label
    if(domain_auth_provider_request->label) {
    if(cJSON_AddStringToObject(item, "label", domain_auth_provider_request->label) == NULL) {
    goto fail; //String
    }
    }


    // domain_auth_provider_request->config
    if(domain_auth_provider_request->config) {
    cJSON *config_local_JSON = open_id_config_v1_convertToJSON(domain_auth_provider_request->config);
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

domain_auth_provider_request_t *domain_auth_provider_request_parseFromJSON(cJSON *domain_auth_provider_requestJSON){

    domain_auth_provider_request_t *domain_auth_provider_request_local_var = NULL;

    // define the local variable for domain_auth_provider_request->config
    open_id_config_v1_t *config_local_nonprim = NULL;

    // domain_auth_provider_request->provider_type
    cJSON *provider_type = cJSON_GetObjectItemCaseSensitive(domain_auth_provider_requestJSON, "providerType");
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

    // domain_auth_provider_request->enabled
    cJSON *enabled = cJSON_GetObjectItemCaseSensitive(domain_auth_provider_requestJSON, "enabled");
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

    // domain_auth_provider_request->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(domain_auth_provider_requestJSON, "label");
    if (cJSON_IsNull(label)) {
        label = NULL;
    }
    if (label) { 
    if(!cJSON_IsString(label) && !cJSON_IsNull(label))
    {
    goto end; //String
    }
    }

    // domain_auth_provider_request->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(domain_auth_provider_requestJSON, "config");
    if (cJSON_IsNull(config)) {
        config = NULL;
    }
    if (config) { 
    config_local_nonprim = open_id_config_v1_parseFromJSON(config); //nonprimitive
    }


    domain_auth_provider_request_local_var = domain_auth_provider_request_create_internal (
        strdup(provider_type->valuestring),
        enabled->valueint,
        label && !cJSON_IsNull(label) ? strdup(label->valuestring) : NULL,
        config ? config_local_nonprim : NULL
        );

    return domain_auth_provider_request_local_var;
end:
    if (config_local_nonprim) {
        open_id_config_v1_free(config_local_nonprim);
        config_local_nonprim = NULL;
    }
    return NULL;

}
