#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_vlan_network_connection_body.h"


char* create_vlan_network_connection_body_provider_ToString(corellium_api_create_vlan_network_connection_body_PROVIDER_e provider) {
    char* providerArray[] =  { "NULL", "vlan" };
    return providerArray[provider];
}

corellium_api_create_vlan_network_connection_body_PROVIDER_e create_vlan_network_connection_body_provider_FromString(char* provider){
    int stringToReturn = 0;
    char *providerArray[] =  { "NULL", "vlan" };
    size_t sizeofArray = sizeof(providerArray) / sizeof(providerArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(provider, providerArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static create_vlan_network_connection_body_t *create_vlan_network_connection_body_create_internal(
    char *name,
    corellium_api_create_vlan_network_connection_body_PROVIDER_e provider,
    vlan_config_t *config
    ) {
    create_vlan_network_connection_body_t *create_vlan_network_connection_body_local_var = malloc(sizeof(create_vlan_network_connection_body_t));
    if (!create_vlan_network_connection_body_local_var) {
        return NULL;
    }
    create_vlan_network_connection_body_local_var->name = name;
    create_vlan_network_connection_body_local_var->provider = provider;
    create_vlan_network_connection_body_local_var->config = config;

    create_vlan_network_connection_body_local_var->_library_owned = 1;
    return create_vlan_network_connection_body_local_var;
}

__attribute__((deprecated)) create_vlan_network_connection_body_t *create_vlan_network_connection_body_create(
    char *name,
    corellium_api_create_vlan_network_connection_body_PROVIDER_e provider,
    vlan_config_t *config
    ) {
    return create_vlan_network_connection_body_create_internal (
        name,
        provider,
        config
        );
}

void create_vlan_network_connection_body_free(create_vlan_network_connection_body_t *create_vlan_network_connection_body) {
    if(NULL == create_vlan_network_connection_body){
        return ;
    }
    if(create_vlan_network_connection_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "create_vlan_network_connection_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (create_vlan_network_connection_body->name) {
        free(create_vlan_network_connection_body->name);
        create_vlan_network_connection_body->name = NULL;
    }
    if (create_vlan_network_connection_body->config) {
        vlan_config_free(create_vlan_network_connection_body->config);
        create_vlan_network_connection_body->config = NULL;
    }
    free(create_vlan_network_connection_body);
}

cJSON *create_vlan_network_connection_body_convertToJSON(create_vlan_network_connection_body_t *create_vlan_network_connection_body) {
    cJSON *item = cJSON_CreateObject();

    // create_vlan_network_connection_body->name
    if (!create_vlan_network_connection_body->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", create_vlan_network_connection_body->name) == NULL) {
    goto fail; //String
    }


    // create_vlan_network_connection_body->provider
    if (corellium_api_create_vlan_network_connection_body_PROVIDER_NULL == create_vlan_network_connection_body->provider) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "provider", create_vlan_network_connection_body_provider_ToString(create_vlan_network_connection_body->provider)) == NULL)
    {
    goto fail; //Enum
    }


    // create_vlan_network_connection_body->config
    if (!create_vlan_network_connection_body->config) {
        goto fail;
    }
    cJSON *config_local_JSON = vlan_config_convertToJSON(create_vlan_network_connection_body->config);
    if(config_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "config", config_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

create_vlan_network_connection_body_t *create_vlan_network_connection_body_parseFromJSON(cJSON *create_vlan_network_connection_bodyJSON){

    create_vlan_network_connection_body_t *create_vlan_network_connection_body_local_var = NULL;

    // define the local variable for create_vlan_network_connection_body->config
    vlan_config_t *config_local_nonprim = NULL;

    // create_vlan_network_connection_body->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(create_vlan_network_connection_bodyJSON, "name");
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

    // create_vlan_network_connection_body->provider
    cJSON *provider = cJSON_GetObjectItemCaseSensitive(create_vlan_network_connection_bodyJSON, "provider");
    if (cJSON_IsNull(provider)) {
        provider = NULL;
    }
    if (!provider) {
        goto end;
    }

    corellium_api_create_vlan_network_connection_body_PROVIDER_e providerVariable;
    
    if(!cJSON_IsString(provider))
    {
    goto end; //Enum
    }
    providerVariable = create_vlan_network_connection_body_provider_FromString(provider->valuestring);

    // create_vlan_network_connection_body->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(create_vlan_network_connection_bodyJSON, "config");
    if (cJSON_IsNull(config)) {
        config = NULL;
    }
    if (!config) {
        goto end;
    }

    
    config_local_nonprim = vlan_config_parseFromJSON(config); //nonprimitive


    create_vlan_network_connection_body_local_var = create_vlan_network_connection_body_create_internal (
        strdup(name->valuestring),
        providerVariable,
        config_local_nonprim
        );

    return create_vlan_network_connection_body_local_var;
end:
    if (config_local_nonprim) {
        vlan_config_free(config_local_nonprim);
        config_local_nonprim = NULL;
    }
    return NULL;

}
