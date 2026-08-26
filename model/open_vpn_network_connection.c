#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "open_vpn_network_connection.h"


char* open_vpn_network_connection_provider_ToString(corellium_api_open_vpn_network_connection_PROVIDER_e provider) {
    char* providerArray[] =  { "NULL", "openvpn" };
    return providerArray[provider];
}

corellium_api_open_vpn_network_connection_PROVIDER_e open_vpn_network_connection_provider_FromString(char* provider){
    int stringToReturn = 0;
    char *providerArray[] =  { "NULL", "openvpn" };
    size_t sizeofArray = sizeof(providerArray) / sizeof(providerArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(provider, providerArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static open_vpn_network_connection_t *open_vpn_network_connection_create_internal(
    char *name,
    corellium_api_open_vpn_network_connection_PROVIDER_e provider,
    open_vpn_config_t *config,
    char *identifier,
    object_t *projects,
    char *created_at,
    char *updated_at,
    char *created_by,
    char *updated_by
    ) {
    open_vpn_network_connection_t *open_vpn_network_connection_local_var = malloc(sizeof(open_vpn_network_connection_t));
    if (!open_vpn_network_connection_local_var) {
        return NULL;
    }
    open_vpn_network_connection_local_var->name = name;
    open_vpn_network_connection_local_var->provider = provider;
    open_vpn_network_connection_local_var->config = config;
    open_vpn_network_connection_local_var->identifier = identifier;
    open_vpn_network_connection_local_var->projects = projects;
    open_vpn_network_connection_local_var->created_at = created_at;
    open_vpn_network_connection_local_var->updated_at = updated_at;
    open_vpn_network_connection_local_var->created_by = created_by;
    open_vpn_network_connection_local_var->updated_by = updated_by;

    open_vpn_network_connection_local_var->_library_owned = 1;
    return open_vpn_network_connection_local_var;
}

__attribute__((deprecated)) open_vpn_network_connection_t *open_vpn_network_connection_create(
    char *name,
    corellium_api_open_vpn_network_connection_PROVIDER_e provider,
    open_vpn_config_t *config,
    char *identifier,
    object_t *projects,
    char *created_at,
    char *updated_at,
    char *created_by,
    char *updated_by
    ) {
    return open_vpn_network_connection_create_internal (
        name,
        provider,
        config,
        identifier,
        projects,
        created_at,
        updated_at,
        created_by,
        updated_by
        );
}

void open_vpn_network_connection_free(open_vpn_network_connection_t *open_vpn_network_connection) {
    if(NULL == open_vpn_network_connection){
        return ;
    }
    if(open_vpn_network_connection->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "open_vpn_network_connection_free");
        return ;
    }
    listEntry_t *listEntry;
    if (open_vpn_network_connection->name) {
        free(open_vpn_network_connection->name);
        open_vpn_network_connection->name = NULL;
    }
    if (open_vpn_network_connection->config) {
        open_vpn_config_free(open_vpn_network_connection->config);
        open_vpn_network_connection->config = NULL;
    }
    if (open_vpn_network_connection->identifier) {
        free(open_vpn_network_connection->identifier);
        open_vpn_network_connection->identifier = NULL;
    }
    if (open_vpn_network_connection->projects) {
        object_free(open_vpn_network_connection->projects);
        open_vpn_network_connection->projects = NULL;
    }
    if (open_vpn_network_connection->created_at) {
        free(open_vpn_network_connection->created_at);
        open_vpn_network_connection->created_at = NULL;
    }
    if (open_vpn_network_connection->updated_at) {
        free(open_vpn_network_connection->updated_at);
        open_vpn_network_connection->updated_at = NULL;
    }
    if (open_vpn_network_connection->created_by) {
        free(open_vpn_network_connection->created_by);
        open_vpn_network_connection->created_by = NULL;
    }
    if (open_vpn_network_connection->updated_by) {
        free(open_vpn_network_connection->updated_by);
        open_vpn_network_connection->updated_by = NULL;
    }
    free(open_vpn_network_connection);
}

cJSON *open_vpn_network_connection_convertToJSON(open_vpn_network_connection_t *open_vpn_network_connection) {
    cJSON *item = cJSON_CreateObject();

    // open_vpn_network_connection->name
    if (!open_vpn_network_connection->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", open_vpn_network_connection->name) == NULL) {
    goto fail; //String
    }


    // open_vpn_network_connection->provider
    if (corellium_api_open_vpn_network_connection_PROVIDER_NULL == open_vpn_network_connection->provider) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "provider", open_vpn_network_connection_provider_ToString(open_vpn_network_connection->provider)) == NULL)
    {
    goto fail; //Enum
    }


    // open_vpn_network_connection->config
    if(open_vpn_network_connection->config) {
    cJSON *config_local_JSON = open_vpn_config_convertToJSON(open_vpn_network_connection->config);
    if(config_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "config", config_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // open_vpn_network_connection->identifier
    if (!open_vpn_network_connection->identifier) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "identifier", open_vpn_network_connection->identifier) == NULL) {
    goto fail; //String
    }


    // open_vpn_network_connection->projects
    if(open_vpn_network_connection->projects) {
    cJSON *projects_object = object_convertToJSON(open_vpn_network_connection->projects);
    if(projects_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "projects", projects_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // open_vpn_network_connection->created_at
    if (!open_vpn_network_connection->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "createdAt", open_vpn_network_connection->created_at) == NULL) {
    goto fail; //Date-Time
    }


    // open_vpn_network_connection->updated_at
    if (!open_vpn_network_connection->updated_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "updatedAt", open_vpn_network_connection->updated_at) == NULL) {
    goto fail; //Date-Time
    }


    // open_vpn_network_connection->created_by
    if (!open_vpn_network_connection->created_by) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "createdBy", open_vpn_network_connection->created_by) == NULL) {
    goto fail; //String
    }


    // open_vpn_network_connection->updated_by
    if (!open_vpn_network_connection->updated_by) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "updatedBy", open_vpn_network_connection->updated_by) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

open_vpn_network_connection_t *open_vpn_network_connection_parseFromJSON(cJSON *open_vpn_network_connectionJSON){

    open_vpn_network_connection_t *open_vpn_network_connection_local_var = NULL;

    // define the local variable for open_vpn_network_connection->config
    open_vpn_config_t *config_local_nonprim = NULL;

    // open_vpn_network_connection->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(open_vpn_network_connectionJSON, "name");
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

    // open_vpn_network_connection->provider
    cJSON *provider = cJSON_GetObjectItemCaseSensitive(open_vpn_network_connectionJSON, "provider");
    if (cJSON_IsNull(provider)) {
        provider = NULL;
    }
    if (!provider) {
        goto end;
    }

    corellium_api_open_vpn_network_connection_PROVIDER_e providerVariable;
    
    if(!cJSON_IsString(provider))
    {
    goto end; //Enum
    }
    providerVariable = open_vpn_network_connection_provider_FromString(provider->valuestring);

    // open_vpn_network_connection->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(open_vpn_network_connectionJSON, "config");
    if (cJSON_IsNull(config)) {
        config = NULL;
    }
    if (config) { 
    config_local_nonprim = open_vpn_config_parseFromJSON(config); //nonprimitive
    }

    // open_vpn_network_connection->identifier
    cJSON *identifier = cJSON_GetObjectItemCaseSensitive(open_vpn_network_connectionJSON, "identifier");
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

    // open_vpn_network_connection->projects
    cJSON *projects = cJSON_GetObjectItemCaseSensitive(open_vpn_network_connectionJSON, "projects");
    if (cJSON_IsNull(projects)) {
        projects = NULL;
    }
    object_t *projects_local_object = NULL;
    if (projects) { 
    projects_local_object = object_parseFromJSON(projects); //object
    }

    // open_vpn_network_connection->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(open_vpn_network_connectionJSON, "createdAt");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (!created_at) {
        goto end;
    }

    
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //DateTime
    }

    // open_vpn_network_connection->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(open_vpn_network_connectionJSON, "updatedAt");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (!updated_at) {
        goto end;
    }

    
    if(!cJSON_IsString(updated_at) && !cJSON_IsNull(updated_at))
    {
    goto end; //DateTime
    }

    // open_vpn_network_connection->created_by
    cJSON *created_by = cJSON_GetObjectItemCaseSensitive(open_vpn_network_connectionJSON, "createdBy");
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

    // open_vpn_network_connection->updated_by
    cJSON *updated_by = cJSON_GetObjectItemCaseSensitive(open_vpn_network_connectionJSON, "updatedBy");
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


    open_vpn_network_connection_local_var = open_vpn_network_connection_create_internal (
        strdup(name->valuestring),
        providerVariable,
        config ? config_local_nonprim : NULL,
        strdup(identifier->valuestring),
        projects ? projects_local_object : NULL,
        strdup(created_at->valuestring),
        strdup(updated_at->valuestring),
        strdup(created_by->valuestring),
        strdup(updated_by->valuestring)
        );

    return open_vpn_network_connection_local_var;
end:
    if (config_local_nonprim) {
        open_vpn_config_free(config_local_nonprim);
        config_local_nonprim = NULL;
    }
    return NULL;

}
