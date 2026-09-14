#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "domain_auth_provider_config.h"



static domain_auth_provider_config_t *domain_auth_provider_config_create_internal(
    saml_identity_provider_config_t *identity_provider_config,
    saml_service_provider_config_t *service_provider_config,
    ldap_user_attribute_mapping_t *user_attribute_mapping,
    list_t *group_mapping,
    char *discovery_url,
    char *client_id,
    char *client_secret,
    int invited_only,
    ldap_server_connection_details_t *server_connection_details,
    ldap_authentication_credentials_t *authentication_credentials,
    ldap_user_search_configuration_t *user_search_configuration,
    list_t *group_search_configuration
    ) {
    domain_auth_provider_config_t *domain_auth_provider_config_local_var = malloc(sizeof(domain_auth_provider_config_t));
    if (!domain_auth_provider_config_local_var) {
        return NULL;
    }
    domain_auth_provider_config_local_var->identity_provider_config = identity_provider_config;
    domain_auth_provider_config_local_var->service_provider_config = service_provider_config;
    domain_auth_provider_config_local_var->user_attribute_mapping = user_attribute_mapping;
    domain_auth_provider_config_local_var->group_mapping = group_mapping;
    domain_auth_provider_config_local_var->discovery_url = discovery_url;
    domain_auth_provider_config_local_var->client_id = client_id;
    domain_auth_provider_config_local_var->client_secret = client_secret;
    domain_auth_provider_config_local_var->invited_only = invited_only;
    domain_auth_provider_config_local_var->server_connection_details = server_connection_details;
    domain_auth_provider_config_local_var->authentication_credentials = authentication_credentials;
    domain_auth_provider_config_local_var->user_search_configuration = user_search_configuration;
    domain_auth_provider_config_local_var->group_search_configuration = group_search_configuration;

    domain_auth_provider_config_local_var->_library_owned = 1;
    return domain_auth_provider_config_local_var;
}

__attribute__((deprecated)) domain_auth_provider_config_t *domain_auth_provider_config_create(
    saml_identity_provider_config_t *identity_provider_config,
    saml_service_provider_config_t *service_provider_config,
    ldap_user_attribute_mapping_t *user_attribute_mapping,
    list_t *group_mapping,
    char *discovery_url,
    char *client_id,
    char *client_secret,
    int invited_only,
    ldap_server_connection_details_t *server_connection_details,
    ldap_authentication_credentials_t *authentication_credentials,
    ldap_user_search_configuration_t *user_search_configuration,
    list_t *group_search_configuration
    ) {
    return domain_auth_provider_config_create_internal (
        identity_provider_config,
        service_provider_config,
        user_attribute_mapping,
        group_mapping,
        discovery_url,
        client_id,
        client_secret,
        invited_only,
        server_connection_details,
        authentication_credentials,
        user_search_configuration,
        group_search_configuration
        );
}

void domain_auth_provider_config_free(domain_auth_provider_config_t *domain_auth_provider_config) {
    if(NULL == domain_auth_provider_config){
        return ;
    }
    if(domain_auth_provider_config->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "domain_auth_provider_config_free");
        return ;
    }
    listEntry_t *listEntry;
    if (domain_auth_provider_config->identity_provider_config) {
        saml_identity_provider_config_free(domain_auth_provider_config->identity_provider_config);
        domain_auth_provider_config->identity_provider_config = NULL;
    }
    if (domain_auth_provider_config->service_provider_config) {
        saml_service_provider_config_free(domain_auth_provider_config->service_provider_config);
        domain_auth_provider_config->service_provider_config = NULL;
    }
    if (domain_auth_provider_config->user_attribute_mapping) {
        ldap_user_attribute_mapping_free(domain_auth_provider_config->user_attribute_mapping);
        domain_auth_provider_config->user_attribute_mapping = NULL;
    }
    if (domain_auth_provider_config->group_mapping) {
        list_ForEach(listEntry, domain_auth_provider_config->group_mapping) {
            saml_group_mapping_free(listEntry->data);
        }
        list_freeList(domain_auth_provider_config->group_mapping);
        domain_auth_provider_config->group_mapping = NULL;
    }
    if (domain_auth_provider_config->discovery_url) {
        free(domain_auth_provider_config->discovery_url);
        domain_auth_provider_config->discovery_url = NULL;
    }
    if (domain_auth_provider_config->client_id) {
        free(domain_auth_provider_config->client_id);
        domain_auth_provider_config->client_id = NULL;
    }
    if (domain_auth_provider_config->client_secret) {
        free(domain_auth_provider_config->client_secret);
        domain_auth_provider_config->client_secret = NULL;
    }
    if (domain_auth_provider_config->server_connection_details) {
        ldap_server_connection_details_free(domain_auth_provider_config->server_connection_details);
        domain_auth_provider_config->server_connection_details = NULL;
    }
    if (domain_auth_provider_config->authentication_credentials) {
        ldap_authentication_credentials_free(domain_auth_provider_config->authentication_credentials);
        domain_auth_provider_config->authentication_credentials = NULL;
    }
    if (domain_auth_provider_config->user_search_configuration) {
        ldap_user_search_configuration_free(domain_auth_provider_config->user_search_configuration);
        domain_auth_provider_config->user_search_configuration = NULL;
    }
    if (domain_auth_provider_config->group_search_configuration) {
        list_ForEach(listEntry, domain_auth_provider_config->group_search_configuration) {
            ldap_group_search_configuration_free(listEntry->data);
        }
        list_freeList(domain_auth_provider_config->group_search_configuration);
        domain_auth_provider_config->group_search_configuration = NULL;
    }
    free(domain_auth_provider_config);
}

cJSON *domain_auth_provider_config_convertToJSON(domain_auth_provider_config_t *domain_auth_provider_config) {
    cJSON *item = cJSON_CreateObject();

    // domain_auth_provider_config->identity_provider_config
    if (!domain_auth_provider_config->identity_provider_config) {
        goto fail;
    }
    cJSON *identity_provider_config_local_JSON = saml_identity_provider_config_convertToJSON(domain_auth_provider_config->identity_provider_config);
    if(identity_provider_config_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "identityProviderConfig", identity_provider_config_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // domain_auth_provider_config->service_provider_config
    if(domain_auth_provider_config->service_provider_config) {
    cJSON *service_provider_config_local_JSON = saml_service_provider_config_convertToJSON(domain_auth_provider_config->service_provider_config);
    if(service_provider_config_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "serviceProviderConfig", service_provider_config_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // domain_auth_provider_config->user_attribute_mapping
    if(domain_auth_provider_config->user_attribute_mapping) {
    cJSON *user_attribute_mapping_local_JSON = ldap_user_attribute_mapping_convertToJSON(domain_auth_provider_config->user_attribute_mapping);
    if(user_attribute_mapping_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "userAttributeMapping", user_attribute_mapping_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // domain_auth_provider_config->group_mapping
    if(domain_auth_provider_config->group_mapping) {
    cJSON *group_mapping = cJSON_AddArrayToObject(item, "groupMapping");
    if(group_mapping == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *group_mappingListEntry;
    if (domain_auth_provider_config->group_mapping) {
    list_ForEach(group_mappingListEntry, domain_auth_provider_config->group_mapping) {
    cJSON *itemLocal = saml_group_mapping_convertToJSON(group_mappingListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(group_mapping, itemLocal);
    }
    }
    }


    // domain_auth_provider_config->discovery_url
    if (!domain_auth_provider_config->discovery_url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "discoveryUrl", domain_auth_provider_config->discovery_url) == NULL) {
    goto fail; //String
    }


    // domain_auth_provider_config->client_id
    if (!domain_auth_provider_config->client_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "clientId", domain_auth_provider_config->client_id) == NULL) {
    goto fail; //String
    }


    // domain_auth_provider_config->client_secret
    if (!domain_auth_provider_config->client_secret) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "clientSecret", domain_auth_provider_config->client_secret) == NULL) {
    goto fail; //String
    }


    // domain_auth_provider_config->invited_only
    if(domain_auth_provider_config->invited_only) {
    if(cJSON_AddBoolToObject(item, "invitedOnly", domain_auth_provider_config->invited_only) == NULL) {
    goto fail; //Bool
    }
    }


    // domain_auth_provider_config->server_connection_details
    if (!domain_auth_provider_config->server_connection_details) {
        goto fail;
    }
    cJSON *server_connection_details_local_JSON = ldap_server_connection_details_convertToJSON(domain_auth_provider_config->server_connection_details);
    if(server_connection_details_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "serverConnectionDetails", server_connection_details_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // domain_auth_provider_config->authentication_credentials
    if (!domain_auth_provider_config->authentication_credentials) {
        goto fail;
    }
    cJSON *authentication_credentials_local_JSON = ldap_authentication_credentials_convertToJSON(domain_auth_provider_config->authentication_credentials);
    if(authentication_credentials_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "authenticationCredentials", authentication_credentials_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // domain_auth_provider_config->user_search_configuration
    if (!domain_auth_provider_config->user_search_configuration) {
        goto fail;
    }
    cJSON *user_search_configuration_local_JSON = ldap_user_search_configuration_convertToJSON(domain_auth_provider_config->user_search_configuration);
    if(user_search_configuration_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "userSearchConfiguration", user_search_configuration_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // domain_auth_provider_config->group_search_configuration
    if(domain_auth_provider_config->group_search_configuration) {
    cJSON *group_search_configuration = cJSON_AddArrayToObject(item, "groupSearchConfiguration");
    if(group_search_configuration == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *group_search_configurationListEntry;
    if (domain_auth_provider_config->group_search_configuration) {
    list_ForEach(group_search_configurationListEntry, domain_auth_provider_config->group_search_configuration) {
    cJSON *itemLocal = ldap_group_search_configuration_convertToJSON(group_search_configurationListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(group_search_configuration, itemLocal);
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

domain_auth_provider_config_t *domain_auth_provider_config_parseFromJSON(cJSON *domain_auth_provider_configJSON){

    domain_auth_provider_config_t *domain_auth_provider_config_local_var = NULL;

    // define the local variable for domain_auth_provider_config->identity_provider_config
    saml_identity_provider_config_t *identity_provider_config_local_nonprim = NULL;

    // define the local variable for domain_auth_provider_config->service_provider_config
    saml_service_provider_config_t *service_provider_config_local_nonprim = NULL;

    // define the local variable for domain_auth_provider_config->user_attribute_mapping
    ldap_user_attribute_mapping_t *user_attribute_mapping_local_nonprim = NULL;

    // define the local list for domain_auth_provider_config->group_mapping
    list_t *group_mappingList = NULL;

    // define the local variable for domain_auth_provider_config->server_connection_details
    ldap_server_connection_details_t *server_connection_details_local_nonprim = NULL;

    // define the local variable for domain_auth_provider_config->authentication_credentials
    ldap_authentication_credentials_t *authentication_credentials_local_nonprim = NULL;

    // define the local variable for domain_auth_provider_config->user_search_configuration
    ldap_user_search_configuration_t *user_search_configuration_local_nonprim = NULL;

    // define the local list for domain_auth_provider_config->group_search_configuration
    list_t *group_search_configurationList = NULL;

    // domain_auth_provider_config->identity_provider_config
    cJSON *identity_provider_config = cJSON_GetObjectItemCaseSensitive(domain_auth_provider_configJSON, "identityProviderConfig");
    if (cJSON_IsNull(identity_provider_config)) {
        identity_provider_config = NULL;
    }
    if (!identity_provider_config) {
        goto end;
    }

    
    identity_provider_config_local_nonprim = saml_identity_provider_config_parseFromJSON(identity_provider_config); //nonprimitive

    // domain_auth_provider_config->service_provider_config
    cJSON *service_provider_config = cJSON_GetObjectItemCaseSensitive(domain_auth_provider_configJSON, "serviceProviderConfig");
    if (cJSON_IsNull(service_provider_config)) {
        service_provider_config = NULL;
    }
    if (service_provider_config) { 
    service_provider_config_local_nonprim = saml_service_provider_config_parseFromJSON(service_provider_config); //nonprimitive
    }

    // domain_auth_provider_config->user_attribute_mapping
    cJSON *user_attribute_mapping = cJSON_GetObjectItemCaseSensitive(domain_auth_provider_configJSON, "userAttributeMapping");
    if (cJSON_IsNull(user_attribute_mapping)) {
        user_attribute_mapping = NULL;
    }
    if (user_attribute_mapping) { 
    user_attribute_mapping_local_nonprim = ldap_user_attribute_mapping_parseFromJSON(user_attribute_mapping); //nonprimitive
    }

    // domain_auth_provider_config->group_mapping
    cJSON *group_mapping = cJSON_GetObjectItemCaseSensitive(domain_auth_provider_configJSON, "groupMapping");
    if (cJSON_IsNull(group_mapping)) {
        group_mapping = NULL;
    }
    if (group_mapping) { 
    cJSON *group_mapping_local_nonprimitive = NULL;
    if(!cJSON_IsArray(group_mapping)){
        goto end; //nonprimitive container
    }

    group_mappingList = list_createList();

    cJSON_ArrayForEach(group_mapping_local_nonprimitive,group_mapping )
    {
        if(!cJSON_IsObject(group_mapping_local_nonprimitive)){
            goto end;
        }
        saml_group_mapping_t *group_mappingItem = saml_group_mapping_parseFromJSON(group_mapping_local_nonprimitive);

        list_addElement(group_mappingList, group_mappingItem);
    }
    }

    // domain_auth_provider_config->discovery_url
    cJSON *discovery_url = cJSON_GetObjectItemCaseSensitive(domain_auth_provider_configJSON, "discoveryUrl");
    if (cJSON_IsNull(discovery_url)) {
        discovery_url = NULL;
    }
    if (!discovery_url) {
        goto end;
    }

    
    if(!cJSON_IsString(discovery_url))
    {
    goto end; //String
    }

    // domain_auth_provider_config->client_id
    cJSON *client_id = cJSON_GetObjectItemCaseSensitive(domain_auth_provider_configJSON, "clientId");
    if (cJSON_IsNull(client_id)) {
        client_id = NULL;
    }
    if (!client_id) {
        goto end;
    }

    
    if(!cJSON_IsString(client_id))
    {
    goto end; //String
    }

    // domain_auth_provider_config->client_secret
    cJSON *client_secret = cJSON_GetObjectItemCaseSensitive(domain_auth_provider_configJSON, "clientSecret");
    if (cJSON_IsNull(client_secret)) {
        client_secret = NULL;
    }
    if (!client_secret) {
        goto end;
    }

    
    if(!cJSON_IsString(client_secret))
    {
    goto end; //String
    }

    // domain_auth_provider_config->invited_only
    cJSON *invited_only = cJSON_GetObjectItemCaseSensitive(domain_auth_provider_configJSON, "invitedOnly");
    if (cJSON_IsNull(invited_only)) {
        invited_only = NULL;
    }
    if (invited_only) { 
    if(!cJSON_IsBool(invited_only))
    {
    goto end; //Bool
    }
    }

    // domain_auth_provider_config->server_connection_details
    cJSON *server_connection_details = cJSON_GetObjectItemCaseSensitive(domain_auth_provider_configJSON, "serverConnectionDetails");
    if (cJSON_IsNull(server_connection_details)) {
        server_connection_details = NULL;
    }
    if (!server_connection_details) {
        goto end;
    }

    
    server_connection_details_local_nonprim = ldap_server_connection_details_parseFromJSON(server_connection_details); //nonprimitive

    // domain_auth_provider_config->authentication_credentials
    cJSON *authentication_credentials = cJSON_GetObjectItemCaseSensitive(domain_auth_provider_configJSON, "authenticationCredentials");
    if (cJSON_IsNull(authentication_credentials)) {
        authentication_credentials = NULL;
    }
    if (!authentication_credentials) {
        goto end;
    }

    
    authentication_credentials_local_nonprim = ldap_authentication_credentials_parseFromJSON(authentication_credentials); //nonprimitive

    // domain_auth_provider_config->user_search_configuration
    cJSON *user_search_configuration = cJSON_GetObjectItemCaseSensitive(domain_auth_provider_configJSON, "userSearchConfiguration");
    if (cJSON_IsNull(user_search_configuration)) {
        user_search_configuration = NULL;
    }
    if (!user_search_configuration) {
        goto end;
    }

    
    user_search_configuration_local_nonprim = ldap_user_search_configuration_parseFromJSON(user_search_configuration); //nonprimitive

    // domain_auth_provider_config->group_search_configuration
    cJSON *group_search_configuration = cJSON_GetObjectItemCaseSensitive(domain_auth_provider_configJSON, "groupSearchConfiguration");
    if (cJSON_IsNull(group_search_configuration)) {
        group_search_configuration = NULL;
    }
    if (group_search_configuration) { 
    cJSON *group_search_configuration_local_nonprimitive = NULL;
    if(!cJSON_IsArray(group_search_configuration)){
        goto end; //nonprimitive container
    }

    group_search_configurationList = list_createList();

    cJSON_ArrayForEach(group_search_configuration_local_nonprimitive,group_search_configuration )
    {
        if(!cJSON_IsObject(group_search_configuration_local_nonprimitive)){
            goto end;
        }
        ldap_group_search_configuration_t *group_search_configurationItem = ldap_group_search_configuration_parseFromJSON(group_search_configuration_local_nonprimitive);

        list_addElement(group_search_configurationList, group_search_configurationItem);
    }
    }


    domain_auth_provider_config_local_var = domain_auth_provider_config_create_internal (
        identity_provider_config_local_nonprim,
        service_provider_config ? service_provider_config_local_nonprim : NULL,
        user_attribute_mapping ? user_attribute_mapping_local_nonprim : NULL,
        group_mapping ? group_mappingList : NULL,
        strdup(discovery_url->valuestring),
        strdup(client_id->valuestring),
        strdup(client_secret->valuestring),
        invited_only ? invited_only->valueint : 0,
        server_connection_details_local_nonprim,
        authentication_credentials_local_nonprim,
        user_search_configuration_local_nonprim,
        group_search_configuration ? group_search_configurationList : NULL
        );

    return domain_auth_provider_config_local_var;
end:
    if (identity_provider_config_local_nonprim) {
        saml_identity_provider_config_free(identity_provider_config_local_nonprim);
        identity_provider_config_local_nonprim = NULL;
    }
    if (service_provider_config_local_nonprim) {
        saml_service_provider_config_free(service_provider_config_local_nonprim);
        service_provider_config_local_nonprim = NULL;
    }
    if (user_attribute_mapping_local_nonprim) {
        ldap_user_attribute_mapping_free(user_attribute_mapping_local_nonprim);
        user_attribute_mapping_local_nonprim = NULL;
    }
    if (group_mappingList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, group_mappingList) {
            saml_group_mapping_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(group_mappingList);
        group_mappingList = NULL;
    }
    if (server_connection_details_local_nonprim) {
        ldap_server_connection_details_free(server_connection_details_local_nonprim);
        server_connection_details_local_nonprim = NULL;
    }
    if (authentication_credentials_local_nonprim) {
        ldap_authentication_credentials_free(authentication_credentials_local_nonprim);
        authentication_credentials_local_nonprim = NULL;
    }
    if (user_search_configuration_local_nonprim) {
        ldap_user_search_configuration_free(user_search_configuration_local_nonprim);
        user_search_configuration_local_nonprim = NULL;
    }
    if (group_search_configurationList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, group_search_configurationList) {
            ldap_group_search_configuration_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(group_search_configurationList);
        group_search_configurationList = NULL;
    }
    return NULL;

}
