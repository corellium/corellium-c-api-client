#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_network_connection_options.h"



static create_network_connection_options_t *create_network_connection_options_create_internal(
    char *identifier,
    char *name,
    char *provider,
    object_t *config
    ) {
    create_network_connection_options_t *create_network_connection_options_local_var = malloc(sizeof(create_network_connection_options_t));
    if (!create_network_connection_options_local_var) {
        return NULL;
    }
    create_network_connection_options_local_var->identifier = identifier;
    create_network_connection_options_local_var->name = name;
    create_network_connection_options_local_var->provider = provider;
    create_network_connection_options_local_var->config = config;

    create_network_connection_options_local_var->_library_owned = 1;
    return create_network_connection_options_local_var;
}

__attribute__((deprecated)) create_network_connection_options_t *create_network_connection_options_create(
    char *identifier,
    char *name,
    char *provider,
    object_t *config
    ) {
    return create_network_connection_options_create_internal (
        identifier,
        name,
        provider,
        config
        );
}

void create_network_connection_options_free(create_network_connection_options_t *create_network_connection_options) {
    if(NULL == create_network_connection_options){
        return ;
    }
    if(create_network_connection_options->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "create_network_connection_options_free");
        return ;
    }
    listEntry_t *listEntry;
    if (create_network_connection_options->identifier) {
        free(create_network_connection_options->identifier);
        create_network_connection_options->identifier = NULL;
    }
    if (create_network_connection_options->name) {
        free(create_network_connection_options->name);
        create_network_connection_options->name = NULL;
    }
    if (create_network_connection_options->provider) {
        free(create_network_connection_options->provider);
        create_network_connection_options->provider = NULL;
    }
    if (create_network_connection_options->config) {
        object_free(create_network_connection_options->config);
        create_network_connection_options->config = NULL;
    }
    free(create_network_connection_options);
}

cJSON *create_network_connection_options_convertToJSON(create_network_connection_options_t *create_network_connection_options) {
    cJSON *item = cJSON_CreateObject();

    // create_network_connection_options->identifier
    if (!create_network_connection_options->identifier) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "identifier", create_network_connection_options->identifier) == NULL) {
    goto fail; //String
    }


    // create_network_connection_options->name
    if (!create_network_connection_options->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", create_network_connection_options->name) == NULL) {
    goto fail; //String
    }


    // create_network_connection_options->provider
    if (!create_network_connection_options->provider) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "provider", create_network_connection_options->provider) == NULL) {
    goto fail; //String
    }


    // create_network_connection_options->config
    if(create_network_connection_options->config) {
    cJSON *config_object = object_convertToJSON(create_network_connection_options->config);
    if(config_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "config", config_object);
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

create_network_connection_options_t *create_network_connection_options_parseFromJSON(cJSON *create_network_connection_optionsJSON){

    create_network_connection_options_t *create_network_connection_options_local_var = NULL;

    // create_network_connection_options->identifier
    cJSON *identifier = cJSON_GetObjectItemCaseSensitive(create_network_connection_optionsJSON, "identifier");
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

    // create_network_connection_options->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(create_network_connection_optionsJSON, "name");
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

    // create_network_connection_options->provider
    cJSON *provider = cJSON_GetObjectItemCaseSensitive(create_network_connection_optionsJSON, "provider");
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

    // create_network_connection_options->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(create_network_connection_optionsJSON, "config");
    if (cJSON_IsNull(config)) {
        config = NULL;
    }
    object_t *config_local_object = NULL;
    if (config) { 
    config_local_object = object_parseFromJSON(config); //object
    }


    create_network_connection_options_local_var = create_network_connection_options_create_internal (
        strdup(identifier->valuestring),
        strdup(name->valuestring),
        strdup(provider->valuestring),
        config ? config_local_object : NULL
        );

    return create_network_connection_options_local_var;
end:
    return NULL;

}
