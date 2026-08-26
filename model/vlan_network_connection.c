#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "vlan_network_connection.h"


char* vlan_network_connection_provider_ToString(corellium_api_vlan_network_connection_PROVIDER_e provider) {
    char* providerArray[] =  { "NULL", "vlan" };
    return providerArray[provider];
}

corellium_api_vlan_network_connection_PROVIDER_e vlan_network_connection_provider_FromString(char* provider){
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

static vlan_network_connection_t *vlan_network_connection_create_internal(
    char *name,
    corellium_api_vlan_network_connection_PROVIDER_e provider,
    vlan_config_t *config,
    char *identifier,
    object_t *projects,
    char *created_at,
    char *updated_at,
    char *created_by,
    char *updated_by
    ) {
    vlan_network_connection_t *vlan_network_connection_local_var = malloc(sizeof(vlan_network_connection_t));
    if (!vlan_network_connection_local_var) {
        return NULL;
    }
    vlan_network_connection_local_var->name = name;
    vlan_network_connection_local_var->provider = provider;
    vlan_network_connection_local_var->config = config;
    vlan_network_connection_local_var->identifier = identifier;
    vlan_network_connection_local_var->projects = projects;
    vlan_network_connection_local_var->created_at = created_at;
    vlan_network_connection_local_var->updated_at = updated_at;
    vlan_network_connection_local_var->created_by = created_by;
    vlan_network_connection_local_var->updated_by = updated_by;

    vlan_network_connection_local_var->_library_owned = 1;
    return vlan_network_connection_local_var;
}

__attribute__((deprecated)) vlan_network_connection_t *vlan_network_connection_create(
    char *name,
    corellium_api_vlan_network_connection_PROVIDER_e provider,
    vlan_config_t *config,
    char *identifier,
    object_t *projects,
    char *created_at,
    char *updated_at,
    char *created_by,
    char *updated_by
    ) {
    return vlan_network_connection_create_internal (
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

void vlan_network_connection_free(vlan_network_connection_t *vlan_network_connection) {
    if(NULL == vlan_network_connection){
        return ;
    }
    if(vlan_network_connection->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "vlan_network_connection_free");
        return ;
    }
    listEntry_t *listEntry;
    if (vlan_network_connection->name) {
        free(vlan_network_connection->name);
        vlan_network_connection->name = NULL;
    }
    if (vlan_network_connection->config) {
        vlan_config_free(vlan_network_connection->config);
        vlan_network_connection->config = NULL;
    }
    if (vlan_network_connection->identifier) {
        free(vlan_network_connection->identifier);
        vlan_network_connection->identifier = NULL;
    }
    if (vlan_network_connection->projects) {
        object_free(vlan_network_connection->projects);
        vlan_network_connection->projects = NULL;
    }
    if (vlan_network_connection->created_at) {
        free(vlan_network_connection->created_at);
        vlan_network_connection->created_at = NULL;
    }
    if (vlan_network_connection->updated_at) {
        free(vlan_network_connection->updated_at);
        vlan_network_connection->updated_at = NULL;
    }
    if (vlan_network_connection->created_by) {
        free(vlan_network_connection->created_by);
        vlan_network_connection->created_by = NULL;
    }
    if (vlan_network_connection->updated_by) {
        free(vlan_network_connection->updated_by);
        vlan_network_connection->updated_by = NULL;
    }
    free(vlan_network_connection);
}

cJSON *vlan_network_connection_convertToJSON(vlan_network_connection_t *vlan_network_connection) {
    cJSON *item = cJSON_CreateObject();

    // vlan_network_connection->name
    if (!vlan_network_connection->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", vlan_network_connection->name) == NULL) {
    goto fail; //String
    }


    // vlan_network_connection->provider
    if (corellium_api_vlan_network_connection_PROVIDER_NULL == vlan_network_connection->provider) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "provider", vlan_network_connection_provider_ToString(vlan_network_connection->provider)) == NULL)
    {
    goto fail; //Enum
    }


    // vlan_network_connection->config
    if(vlan_network_connection->config) {
    cJSON *config_local_JSON = vlan_config_convertToJSON(vlan_network_connection->config);
    if(config_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "config", config_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // vlan_network_connection->identifier
    if (!vlan_network_connection->identifier) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "identifier", vlan_network_connection->identifier) == NULL) {
    goto fail; //String
    }


    // vlan_network_connection->projects
    if(vlan_network_connection->projects) {
    cJSON *projects_object = object_convertToJSON(vlan_network_connection->projects);
    if(projects_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "projects", projects_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // vlan_network_connection->created_at
    if (!vlan_network_connection->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "createdAt", vlan_network_connection->created_at) == NULL) {
    goto fail; //Date-Time
    }


    // vlan_network_connection->updated_at
    if (!vlan_network_connection->updated_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "updatedAt", vlan_network_connection->updated_at) == NULL) {
    goto fail; //Date-Time
    }


    // vlan_network_connection->created_by
    if (!vlan_network_connection->created_by) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "createdBy", vlan_network_connection->created_by) == NULL) {
    goto fail; //String
    }


    // vlan_network_connection->updated_by
    if (!vlan_network_connection->updated_by) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "updatedBy", vlan_network_connection->updated_by) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

vlan_network_connection_t *vlan_network_connection_parseFromJSON(cJSON *vlan_network_connectionJSON){

    vlan_network_connection_t *vlan_network_connection_local_var = NULL;

    // define the local variable for vlan_network_connection->config
    vlan_config_t *config_local_nonprim = NULL;

    // vlan_network_connection->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(vlan_network_connectionJSON, "name");
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

    // vlan_network_connection->provider
    cJSON *provider = cJSON_GetObjectItemCaseSensitive(vlan_network_connectionJSON, "provider");
    if (cJSON_IsNull(provider)) {
        provider = NULL;
    }
    if (!provider) {
        goto end;
    }

    corellium_api_vlan_network_connection_PROVIDER_e providerVariable;
    
    if(!cJSON_IsString(provider))
    {
    goto end; //Enum
    }
    providerVariable = vlan_network_connection_provider_FromString(provider->valuestring);

    // vlan_network_connection->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(vlan_network_connectionJSON, "config");
    if (cJSON_IsNull(config)) {
        config = NULL;
    }
    if (config) { 
    config_local_nonprim = vlan_config_parseFromJSON(config); //nonprimitive
    }

    // vlan_network_connection->identifier
    cJSON *identifier = cJSON_GetObjectItemCaseSensitive(vlan_network_connectionJSON, "identifier");
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

    // vlan_network_connection->projects
    cJSON *projects = cJSON_GetObjectItemCaseSensitive(vlan_network_connectionJSON, "projects");
    if (cJSON_IsNull(projects)) {
        projects = NULL;
    }
    object_t *projects_local_object = NULL;
    if (projects) { 
    projects_local_object = object_parseFromJSON(projects); //object
    }

    // vlan_network_connection->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(vlan_network_connectionJSON, "createdAt");
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

    // vlan_network_connection->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(vlan_network_connectionJSON, "updatedAt");
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

    // vlan_network_connection->created_by
    cJSON *created_by = cJSON_GetObjectItemCaseSensitive(vlan_network_connectionJSON, "createdBy");
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

    // vlan_network_connection->updated_by
    cJSON *updated_by = cJSON_GetObjectItemCaseSensitive(vlan_network_connectionJSON, "updatedBy");
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


    vlan_network_connection_local_var = vlan_network_connection_create_internal (
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

    return vlan_network_connection_local_var;
end:
    if (config_local_nonprim) {
        vlan_config_free(config_local_nonprim);
        config_local_nonprim = NULL;
    }
    return NULL;

}
