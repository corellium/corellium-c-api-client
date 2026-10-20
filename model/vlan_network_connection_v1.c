#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "vlan_network_connection_v1.h"


char* vlan_network_connection_v1_provider_ToString(corellium_api_vlan_network_connection_v1_PROVIDER_e provider) {
    char* providerArray[] =  { "NULL", "vlan" };
    return providerArray[provider];
}

corellium_api_vlan_network_connection_v1_PROVIDER_e vlan_network_connection_v1_provider_FromString(char* provider){
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

static vlan_network_connection_v1_t *vlan_network_connection_v1_create_internal(
    char *identifier,
    corellium_api_vlan_network_connection_v1_PROVIDER_e provider,
    char *name,
    vlan_config_v1_t *config,
    object_t *projects,
    char *created_at,
    char *updated_at,
    char *created_by,
    char *updated_by
    ) {
    vlan_network_connection_v1_t *vlan_network_connection_v1_local_var = malloc(sizeof(vlan_network_connection_v1_t));
    if (!vlan_network_connection_v1_local_var) {
        return NULL;
    }
    vlan_network_connection_v1_local_var->identifier = identifier;
    vlan_network_connection_v1_local_var->provider = provider;
    vlan_network_connection_v1_local_var->name = name;
    vlan_network_connection_v1_local_var->config = config;
    vlan_network_connection_v1_local_var->projects = projects;
    vlan_network_connection_v1_local_var->created_at = created_at;
    vlan_network_connection_v1_local_var->updated_at = updated_at;
    vlan_network_connection_v1_local_var->created_by = created_by;
    vlan_network_connection_v1_local_var->updated_by = updated_by;

    vlan_network_connection_v1_local_var->_library_owned = 1;
    return vlan_network_connection_v1_local_var;
}

__attribute__((deprecated)) vlan_network_connection_v1_t *vlan_network_connection_v1_create(
    char *identifier,
    corellium_api_vlan_network_connection_v1_PROVIDER_e provider,
    char *name,
    vlan_config_v1_t *config,
    object_t *projects,
    char *created_at,
    char *updated_at,
    char *created_by,
    char *updated_by
    ) {
    return vlan_network_connection_v1_create_internal (
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

void vlan_network_connection_v1_free(vlan_network_connection_v1_t *vlan_network_connection_v1) {
    if(NULL == vlan_network_connection_v1){
        return ;
    }
    if(vlan_network_connection_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "vlan_network_connection_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (vlan_network_connection_v1->identifier) {
        free(vlan_network_connection_v1->identifier);
        vlan_network_connection_v1->identifier = NULL;
    }
    if (vlan_network_connection_v1->name) {
        free(vlan_network_connection_v1->name);
        vlan_network_connection_v1->name = NULL;
    }
    if (vlan_network_connection_v1->config) {
        vlan_config_v1_free(vlan_network_connection_v1->config);
        vlan_network_connection_v1->config = NULL;
    }
    if (vlan_network_connection_v1->projects) {
        object_free(vlan_network_connection_v1->projects);
        vlan_network_connection_v1->projects = NULL;
    }
    if (vlan_network_connection_v1->created_at) {
        free(vlan_network_connection_v1->created_at);
        vlan_network_connection_v1->created_at = NULL;
    }
    if (vlan_network_connection_v1->updated_at) {
        free(vlan_network_connection_v1->updated_at);
        vlan_network_connection_v1->updated_at = NULL;
    }
    if (vlan_network_connection_v1->created_by) {
        free(vlan_network_connection_v1->created_by);
        vlan_network_connection_v1->created_by = NULL;
    }
    if (vlan_network_connection_v1->updated_by) {
        free(vlan_network_connection_v1->updated_by);
        vlan_network_connection_v1->updated_by = NULL;
    }
    free(vlan_network_connection_v1);
}

cJSON *vlan_network_connection_v1_convertToJSON(vlan_network_connection_v1_t *vlan_network_connection_v1) {
    cJSON *item = cJSON_CreateObject();

    // vlan_network_connection_v1->identifier
    if (!vlan_network_connection_v1->identifier) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "identifier", vlan_network_connection_v1->identifier) == NULL) {
    goto fail; //String
    }


    // vlan_network_connection_v1->provider
    if (corellium_api_vlan_network_connection_v1_PROVIDER_NULL == vlan_network_connection_v1->provider) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "provider", vlan_network_connection_v1_provider_ToString(vlan_network_connection_v1->provider)) == NULL)
    {
    goto fail; //Enum
    }


    // vlan_network_connection_v1->name
    if (!vlan_network_connection_v1->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", vlan_network_connection_v1->name) == NULL) {
    goto fail; //String
    }


    // vlan_network_connection_v1->config
    if(vlan_network_connection_v1->config) {
    cJSON *config_local_JSON = vlan_config_v1_convertToJSON(vlan_network_connection_v1->config);
    if(config_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "config", config_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // vlan_network_connection_v1->projects
    if(vlan_network_connection_v1->projects) {
    cJSON *projects_object = object_convertToJSON(vlan_network_connection_v1->projects);
    if(projects_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "projects", projects_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // vlan_network_connection_v1->created_at
    if (!vlan_network_connection_v1->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "createdAt", vlan_network_connection_v1->created_at) == NULL) {
    goto fail; //String
    }


    // vlan_network_connection_v1->updated_at
    if (!vlan_network_connection_v1->updated_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "updatedAt", vlan_network_connection_v1->updated_at) == NULL) {
    goto fail; //String
    }


    // vlan_network_connection_v1->created_by
    if (!vlan_network_connection_v1->created_by) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "createdBy", vlan_network_connection_v1->created_by) == NULL) {
    goto fail; //String
    }


    // vlan_network_connection_v1->updated_by
    if (!vlan_network_connection_v1->updated_by) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "updatedBy", vlan_network_connection_v1->updated_by) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

vlan_network_connection_v1_t *vlan_network_connection_v1_parseFromJSON(cJSON *vlan_network_connection_v1JSON){

    vlan_network_connection_v1_t *vlan_network_connection_v1_local_var = NULL;

    // define the local variable for vlan_network_connection_v1->config
    vlan_config_v1_t *config_local_nonprim = NULL;

    // vlan_network_connection_v1->identifier
    cJSON *identifier = cJSON_GetObjectItemCaseSensitive(vlan_network_connection_v1JSON, "identifier");
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

    // vlan_network_connection_v1->provider
    cJSON *provider = cJSON_GetObjectItemCaseSensitive(vlan_network_connection_v1JSON, "provider");
    if (cJSON_IsNull(provider)) {
        provider = NULL;
    }
    if (!provider) {
        goto end;
    }

    corellium_api_vlan_network_connection_v1_PROVIDER_e providerVariable;
    
    if(!cJSON_IsString(provider))
    {
    goto end; //Enum
    }
    providerVariable = vlan_network_connection_v1_provider_FromString(provider->valuestring);

    // vlan_network_connection_v1->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(vlan_network_connection_v1JSON, "name");
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

    // vlan_network_connection_v1->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(vlan_network_connection_v1JSON, "config");
    if (cJSON_IsNull(config)) {
        config = NULL;
    }
    if (config) { 
    config_local_nonprim = vlan_config_v1_parseFromJSON(config); //nonprimitive
    }

    // vlan_network_connection_v1->projects
    cJSON *projects = cJSON_GetObjectItemCaseSensitive(vlan_network_connection_v1JSON, "projects");
    if (cJSON_IsNull(projects)) {
        projects = NULL;
    }
    object_t *projects_local_object = NULL;
    if (projects) { 
    projects_local_object = object_parseFromJSON(projects); //object
    }

    // vlan_network_connection_v1->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(vlan_network_connection_v1JSON, "createdAt");
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

    // vlan_network_connection_v1->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(vlan_network_connection_v1JSON, "updatedAt");
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

    // vlan_network_connection_v1->created_by
    cJSON *created_by = cJSON_GetObjectItemCaseSensitive(vlan_network_connection_v1JSON, "createdBy");
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

    // vlan_network_connection_v1->updated_by
    cJSON *updated_by = cJSON_GetObjectItemCaseSensitive(vlan_network_connection_v1JSON, "updatedBy");
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


    vlan_network_connection_v1_local_var = vlan_network_connection_v1_create_internal (
        strdup(identifier->valuestring),
        providerVariable,
        strdup(name->valuestring),
        config ? config_local_nonprim : NULL,
        projects ? projects_local_object : NULL,
        strdup(created_at->valuestring),
        strdup(updated_at->valuestring),
        strdup(created_by->valuestring),
        strdup(updated_by->valuestring)
        );

    return vlan_network_connection_v1_local_var;
end:
    if (config_local_nonprim) {
        vlan_config_v1_free(config_local_nonprim);
        config_local_nonprim = NULL;
    }
    return NULL;

}
