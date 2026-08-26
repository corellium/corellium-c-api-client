#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "network_connection_providers_results_inner.h"



static network_connection_providers_results_inner_t *network_connection_providers_results_inner_create_internal(
    char *name,
    char *type
    ) {
    network_connection_providers_results_inner_t *network_connection_providers_results_inner_local_var = malloc(sizeof(network_connection_providers_results_inner_t));
    if (!network_connection_providers_results_inner_local_var) {
        return NULL;
    }
    network_connection_providers_results_inner_local_var->name = name;
    network_connection_providers_results_inner_local_var->type = type;

    network_connection_providers_results_inner_local_var->_library_owned = 1;
    return network_connection_providers_results_inner_local_var;
}

__attribute__((deprecated)) network_connection_providers_results_inner_t *network_connection_providers_results_inner_create(
    char *name,
    char *type
    ) {
    return network_connection_providers_results_inner_create_internal (
        name,
        type
        );
}

void network_connection_providers_results_inner_free(network_connection_providers_results_inner_t *network_connection_providers_results_inner) {
    if(NULL == network_connection_providers_results_inner){
        return ;
    }
    if(network_connection_providers_results_inner->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "network_connection_providers_results_inner_free");
        return ;
    }
    listEntry_t *listEntry;
    if (network_connection_providers_results_inner->name) {
        free(network_connection_providers_results_inner->name);
        network_connection_providers_results_inner->name = NULL;
    }
    if (network_connection_providers_results_inner->type) {
        free(network_connection_providers_results_inner->type);
        network_connection_providers_results_inner->type = NULL;
    }
    free(network_connection_providers_results_inner);
}

cJSON *network_connection_providers_results_inner_convertToJSON(network_connection_providers_results_inner_t *network_connection_providers_results_inner) {
    cJSON *item = cJSON_CreateObject();

    // network_connection_providers_results_inner->name
    if (!network_connection_providers_results_inner->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", network_connection_providers_results_inner->name) == NULL) {
    goto fail; //String
    }


    // network_connection_providers_results_inner->type
    if (!network_connection_providers_results_inner->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", network_connection_providers_results_inner->type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

network_connection_providers_results_inner_t *network_connection_providers_results_inner_parseFromJSON(cJSON *network_connection_providers_results_innerJSON){

    network_connection_providers_results_inner_t *network_connection_providers_results_inner_local_var = NULL;

    // network_connection_providers_results_inner->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(network_connection_providers_results_innerJSON, "name");
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

    // network_connection_providers_results_inner->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(network_connection_providers_results_innerJSON, "type");
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


    network_connection_providers_results_inner_local_var = network_connection_providers_results_inner_create_internal (
        strdup(name->valuestring),
        strdup(type->valuestring)
        );

    return network_connection_providers_results_inner_local_var;
end:
    return NULL;

}
