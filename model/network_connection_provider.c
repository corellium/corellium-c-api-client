#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "network_connection_provider.h"



static network_connection_provider_t *network_connection_provider_create_internal(
    char *name,
    char *type
    ) {
    network_connection_provider_t *network_connection_provider_local_var = malloc(sizeof(network_connection_provider_t));
    if (!network_connection_provider_local_var) {
        return NULL;
    }
    network_connection_provider_local_var->name = name;
    network_connection_provider_local_var->type = type;

    network_connection_provider_local_var->_library_owned = 1;
    return network_connection_provider_local_var;
}

__attribute__((deprecated)) network_connection_provider_t *network_connection_provider_create(
    char *name,
    char *type
    ) {
    return network_connection_provider_create_internal (
        name,
        type
        );
}

void network_connection_provider_free(network_connection_provider_t *network_connection_provider) {
    if(NULL == network_connection_provider){
        return ;
    }
    if(network_connection_provider->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "network_connection_provider_free");
        return ;
    }
    listEntry_t *listEntry;
    if (network_connection_provider->name) {
        free(network_connection_provider->name);
        network_connection_provider->name = NULL;
    }
    if (network_connection_provider->type) {
        free(network_connection_provider->type);
        network_connection_provider->type = NULL;
    }
    free(network_connection_provider);
}

cJSON *network_connection_provider_convertToJSON(network_connection_provider_t *network_connection_provider) {
    cJSON *item = cJSON_CreateObject();

    // network_connection_provider->name
    if (!network_connection_provider->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", network_connection_provider->name) == NULL) {
    goto fail; //String
    }


    // network_connection_provider->type
    if (!network_connection_provider->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", network_connection_provider->type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

network_connection_provider_t *network_connection_provider_parseFromJSON(cJSON *network_connection_providerJSON){

    network_connection_provider_t *network_connection_provider_local_var = NULL;

    // network_connection_provider->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(network_connection_providerJSON, "name");
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

    // network_connection_provider->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(network_connection_providerJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }


    network_connection_provider_local_var = network_connection_provider_create_internal (
        strdup(name->valuestring),
        strdup(type->valuestring)
        );

    return network_connection_provider_local_var;
end:
    return NULL;

}
