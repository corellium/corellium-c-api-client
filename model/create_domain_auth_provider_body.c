#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_domain_auth_provider_body.h"



static create_domain_auth_provider_body_t *create_domain_auth_provider_body_create_internal(
    char *provider_type,
    int enabled,
    char *label,
    domain_auth_provider_config_t *config
    ) {
    create_domain_auth_provider_body_t *create_domain_auth_provider_body_local_var = malloc(sizeof(create_domain_auth_provider_body_t));
    if (!create_domain_auth_provider_body_local_var) {
        return NULL;
    }
    create_domain_auth_provider_body_local_var->provider_type = provider_type;
    create_domain_auth_provider_body_local_var->enabled = enabled;
    create_domain_auth_provider_body_local_var->label = label;
    create_domain_auth_provider_body_local_var->config = config;

    create_domain_auth_provider_body_local_var->_library_owned = 1;
    return create_domain_auth_provider_body_local_var;
}

__attribute__((deprecated)) create_domain_auth_provider_body_t *create_domain_auth_provider_body_create(
    char *provider_type,
    int enabled,
    char *label,
    domain_auth_provider_config_t *config
    ) {
    return create_domain_auth_provider_body_create_internal (
        provider_type,
        enabled,
        label,
        config
        );
}

void create_domain_auth_provider_body_free(create_domain_auth_provider_body_t *create_domain_auth_provider_body) {
    if(NULL == create_domain_auth_provider_body){
        return ;
    }
    if(create_domain_auth_provider_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "create_domain_auth_provider_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (create_domain_auth_provider_body->provider_type) {
        free(create_domain_auth_provider_body->provider_type);
        create_domain_auth_provider_body->provider_type = NULL;
    }
    if (create_domain_auth_provider_body->label) {
        free(create_domain_auth_provider_body->label);
        create_domain_auth_provider_body->label = NULL;
    }
    if (create_domain_auth_provider_body->config) {
        domain_auth_provider_config_free(create_domain_auth_provider_body->config);
        create_domain_auth_provider_body->config = NULL;
    }
    free(create_domain_auth_provider_body);
}

cJSON *create_domain_auth_provider_body_convertToJSON(create_domain_auth_provider_body_t *create_domain_auth_provider_body) {
    cJSON *item = cJSON_CreateObject();

    // create_domain_auth_provider_body->provider_type
    if (!create_domain_auth_provider_body->provider_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "providerType", create_domain_auth_provider_body->provider_type) == NULL) {
    goto fail; //String
    }


    // create_domain_auth_provider_body->enabled
    if (!create_domain_auth_provider_body->enabled) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "enabled", create_domain_auth_provider_body->enabled) == NULL) {
    goto fail; //Bool
    }


    // create_domain_auth_provider_body->label
    if(create_domain_auth_provider_body->label) {
    if(cJSON_AddStringToObject(item, "label", create_domain_auth_provider_body->label) == NULL) {
    goto fail; //String
    }
    }


    // create_domain_auth_provider_body->config
    if(create_domain_auth_provider_body->config) {
    cJSON *config_local_JSON = domain_auth_provider_config_convertToJSON(create_domain_auth_provider_body->config);
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

create_domain_auth_provider_body_t *create_domain_auth_provider_body_parseFromJSON(cJSON *create_domain_auth_provider_bodyJSON){

    create_domain_auth_provider_body_t *create_domain_auth_provider_body_local_var = NULL;

    // define the local variable for create_domain_auth_provider_body->config
    domain_auth_provider_config_t *config_local_nonprim = NULL;

    // create_domain_auth_provider_body->provider_type
    cJSON *provider_type = cJSON_GetObjectItemCaseSensitive(create_domain_auth_provider_bodyJSON, "providerType");
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

    // create_domain_auth_provider_body->enabled
    cJSON *enabled = cJSON_GetObjectItemCaseSensitive(create_domain_auth_provider_bodyJSON, "enabled");
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

    // create_domain_auth_provider_body->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(create_domain_auth_provider_bodyJSON, "label");
    if (cJSON_IsNull(label)) {
        label = NULL;
    }
    if (label) { 
    if(!cJSON_IsString(label) && !cJSON_IsNull(label))
    {
    goto end; //String
    }
    }

    // create_domain_auth_provider_body->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(create_domain_auth_provider_bodyJSON, "config");
    if (cJSON_IsNull(config)) {
        config = NULL;
    }
    if (config) { 
    config_local_nonprim = domain_auth_provider_config_parseFromJSON(config); //nonprimitive
    }


    create_domain_auth_provider_body_local_var = create_domain_auth_provider_body_create_internal (
        strdup(provider_type->valuestring),
        enabled->valueint,
        label && !cJSON_IsNull(label) ? strdup(label->valuestring) : NULL,
        config ? config_local_nonprim : NULL
        );

    return create_domain_auth_provider_body_local_var;
end:
    if (config_local_nonprim) {
        domain_auth_provider_config_free(config_local_nonprim);
        config_local_nonprim = NULL;
    }
    return NULL;

}
