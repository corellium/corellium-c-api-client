#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "network_connection.h"



static network_connection_t *network_connection_create_internal(
    char *identifier,
    char *provider,
    char *name,
    object_t *config,
    object_t *projects,
    char *created_at,
    char *updated_at,
    char *created_by,
    char *updated_by
    ) {
    network_connection_t *network_connection_local_var = malloc(sizeof(network_connection_t));
    if (!network_connection_local_var) {
        return NULL;
    }
    network_connection_local_var->identifier = identifier;
    network_connection_local_var->provider = provider;
    network_connection_local_var->name = name;
    network_connection_local_var->config = config;
    network_connection_local_var->projects = projects;
    network_connection_local_var->created_at = created_at;
    network_connection_local_var->updated_at = updated_at;
    network_connection_local_var->created_by = created_by;
    network_connection_local_var->updated_by = updated_by;

    network_connection_local_var->_library_owned = 1;
    return network_connection_local_var;
}

__attribute__((deprecated)) network_connection_t *network_connection_create(
    char *identifier,
    char *provider,
    char *name,
    object_t *config,
    object_t *projects,
    char *created_at,
    char *updated_at,
    char *created_by,
    char *updated_by
    ) {
    return network_connection_create_internal (
        identifier,
        provider,
        name,
        config,
        projects,
        created_at,
        updated_at,
        created_by,
        updated_by
        );
}

void network_connection_free(network_connection_t *network_connection) {
    if(NULL == network_connection){
        return ;
    }
    if(network_connection->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "network_connection_free");
        return ;
    }
    listEntry_t *listEntry;
    if (network_connection->identifier) {
        free(network_connection->identifier);
        network_connection->identifier = NULL;
    }
    if (network_connection->provider) {
        free(network_connection->provider);
        network_connection->provider = NULL;
    }
    if (network_connection->name) {
        free(network_connection->name);
        network_connection->name = NULL;
    }
    if (network_connection->config) {
        object_free(network_connection->config);
        network_connection->config = NULL;
    }
    if (network_connection->projects) {
        object_free(network_connection->projects);
        network_connection->projects = NULL;
    }
    if (network_connection->created_at) {
        free(network_connection->created_at);
        network_connection->created_at = NULL;
    }
    if (network_connection->updated_at) {
        free(network_connection->updated_at);
        network_connection->updated_at = NULL;
    }
    if (network_connection->created_by) {
        free(network_connection->created_by);
        network_connection->created_by = NULL;
    }
    if (network_connection->updated_by) {
        free(network_connection->updated_by);
        network_connection->updated_by = NULL;
    }
    free(network_connection);
}

cJSON *network_connection_convertToJSON(network_connection_t *network_connection) {
    cJSON *item = cJSON_CreateObject();

    // network_connection->identifier
    if (!network_connection->identifier) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "identifier", network_connection->identifier) == NULL) {
    goto fail; //String
    }


    // network_connection->provider
    if (!network_connection->provider) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "provider", network_connection->provider) == NULL) {
    goto fail; //String
    }


    // network_connection->name
    if (!network_connection->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", network_connection->name) == NULL) {
    goto fail; //String
    }


    // network_connection->config
    if (!network_connection->config) {
        goto fail;
    }
    cJSON *config_object = object_convertToJSON(network_connection->config);
    if(config_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "config", config_object);
    if(item->child == NULL) {
    goto fail;
    }


    // network_connection->projects
    if(network_connection->projects) {
    cJSON *projects_object = object_convertToJSON(network_connection->projects);
    if(projects_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "projects", projects_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // network_connection->created_at
    if (!network_connection->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "createdAt", network_connection->created_at) == NULL) {
    goto fail; //String
    }


    // network_connection->updated_at
    if (!network_connection->updated_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "updatedAt", network_connection->updated_at) == NULL) {
    goto fail; //String
    }


    // network_connection->created_by
    if (!network_connection->created_by) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "createdBy", network_connection->created_by) == NULL) {
    goto fail; //String
    }


    // network_connection->updated_by
    if (!network_connection->updated_by) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "updatedBy", network_connection->updated_by) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

network_connection_t *network_connection_parseFromJSON(cJSON *network_connectionJSON){

    network_connection_t *network_connection_local_var = NULL;

    // network_connection->identifier
    cJSON *identifier = cJSON_GetObjectItemCaseSensitive(network_connectionJSON, "identifier");
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

    // network_connection->provider
    cJSON *provider = cJSON_GetObjectItemCaseSensitive(network_connectionJSON, "provider");
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

    // network_connection->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(network_connectionJSON, "name");
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

    // network_connection->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(network_connectionJSON, "config");
    if (cJSON_IsNull(config)) {
        config = NULL;
    }
    if (!config) {
        goto end;
    }

    object_t *config_local_object = NULL;
    
    config_local_object = object_parseFromJSON(config); //object

    // network_connection->projects
    cJSON *projects = cJSON_GetObjectItemCaseSensitive(network_connectionJSON, "projects");
    if (cJSON_IsNull(projects)) {
        projects = NULL;
    }
    object_t *projects_local_object = NULL;
    if (projects) { 
    projects_local_object = object_parseFromJSON(projects); //object
    }

    // network_connection->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(network_connectionJSON, "createdAt");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (!created_at) {
        goto end;
    }

    
    if(!cJSON_IsString(created_at))
    {
    goto end; //String
    }

    // network_connection->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(network_connectionJSON, "updatedAt");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (!updated_at) {
        goto end;
    }

    
    if(!cJSON_IsString(updated_at))
    {
    goto end; //String
    }

    // network_connection->created_by
    cJSON *created_by = cJSON_GetObjectItemCaseSensitive(network_connectionJSON, "createdBy");
    if (cJSON_IsNull(created_by)) {
        created_by = NULL;
    }
    if (!created_by) {
        goto end;
    }

    
    if(!cJSON_IsString(created_by))
    {
    goto end; //String
    }

    // network_connection->updated_by
    cJSON *updated_by = cJSON_GetObjectItemCaseSensitive(network_connectionJSON, "updatedBy");
    if (cJSON_IsNull(updated_by)) {
        updated_by = NULL;
    }
    if (!updated_by) {
        goto end;
    }

    
    if(!cJSON_IsString(updated_by))
    {
    goto end; //String
    }


    network_connection_local_var = network_connection_create_internal (
        strdup(identifier->valuestring),
        strdup(provider->valuestring),
        strdup(name->valuestring),
        config_local_object,
        projects ? projects_local_object : NULL,
        strdup(created_at->valuestring),
        strdup(updated_at->valuestring),
        strdup(created_by->valuestring),
        strdup(updated_by->valuestring)
        );

    return network_connection_local_var;
end:
    return NULL;

}
