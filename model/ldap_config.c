#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ldap_config.h"



static ldap_config_t *ldap_config_create_internal(
    ldap_server_connection_details_t *server_connection_details,
    ldap_authentication_credentials_t *authentication_credentials,
    ldap_user_search_configuration_t *user_search_configuration,
    ldap_user_attribute_mapping_t *user_attribute_mapping,
    list_t *group_search_configuration
    ) {
    ldap_config_t *ldap_config_local_var = malloc(sizeof(ldap_config_t));
    if (!ldap_config_local_var) {
        return NULL;
    }
    ldap_config_local_var->server_connection_details = server_connection_details;
    ldap_config_local_var->authentication_credentials = authentication_credentials;
    ldap_config_local_var->user_search_configuration = user_search_configuration;
    ldap_config_local_var->user_attribute_mapping = user_attribute_mapping;
    ldap_config_local_var->group_search_configuration = group_search_configuration;

    ldap_config_local_var->_library_owned = 1;
    return ldap_config_local_var;
}

__attribute__((deprecated)) ldap_config_t *ldap_config_create(
    ldap_server_connection_details_t *server_connection_details,
    ldap_authentication_credentials_t *authentication_credentials,
    ldap_user_search_configuration_t *user_search_configuration,
    ldap_user_attribute_mapping_t *user_attribute_mapping,
    list_t *group_search_configuration
    ) {
    return ldap_config_create_internal (
        server_connection_details,
        authentication_credentials,
        user_search_configuration,
        user_attribute_mapping,
        group_search_configuration
        );
}

void ldap_config_free(ldap_config_t *ldap_config) {
    if(NULL == ldap_config){
        return ;
    }
    if(ldap_config->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ldap_config_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ldap_config->server_connection_details) {
        ldap_server_connection_details_free(ldap_config->server_connection_details);
        ldap_config->server_connection_details = NULL;
    }
    if (ldap_config->authentication_credentials) {
        ldap_authentication_credentials_free(ldap_config->authentication_credentials);
        ldap_config->authentication_credentials = NULL;
    }
    if (ldap_config->user_search_configuration) {
        ldap_user_search_configuration_free(ldap_config->user_search_configuration);
        ldap_config->user_search_configuration = NULL;
    }
    if (ldap_config->user_attribute_mapping) {
        ldap_user_attribute_mapping_free(ldap_config->user_attribute_mapping);
        ldap_config->user_attribute_mapping = NULL;
    }
    if (ldap_config->group_search_configuration) {
        list_ForEach(listEntry, ldap_config->group_search_configuration) {
            ldap_group_search_configuration_free(listEntry->data);
        }
        list_freeList(ldap_config->group_search_configuration);
        ldap_config->group_search_configuration = NULL;
    }
    free(ldap_config);
}

cJSON *ldap_config_convertToJSON(ldap_config_t *ldap_config) {
    cJSON *item = cJSON_CreateObject();

    // ldap_config->server_connection_details
    if (!ldap_config->server_connection_details) {
        goto fail;
    }
    cJSON *server_connection_details_local_JSON = ldap_server_connection_details_convertToJSON(ldap_config->server_connection_details);
    if(server_connection_details_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "serverConnectionDetails", server_connection_details_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // ldap_config->authentication_credentials
    if (!ldap_config->authentication_credentials) {
        goto fail;
    }
    cJSON *authentication_credentials_local_JSON = ldap_authentication_credentials_convertToJSON(ldap_config->authentication_credentials);
    if(authentication_credentials_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "authenticationCredentials", authentication_credentials_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // ldap_config->user_search_configuration
    if (!ldap_config->user_search_configuration) {
        goto fail;
    }
    cJSON *user_search_configuration_local_JSON = ldap_user_search_configuration_convertToJSON(ldap_config->user_search_configuration);
    if(user_search_configuration_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "userSearchConfiguration", user_search_configuration_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // ldap_config->user_attribute_mapping
    if(ldap_config->user_attribute_mapping) {
    cJSON *user_attribute_mapping_local_JSON = ldap_user_attribute_mapping_convertToJSON(ldap_config->user_attribute_mapping);
    if(user_attribute_mapping_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "userAttributeMapping", user_attribute_mapping_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // ldap_config->group_search_configuration
    if(ldap_config->group_search_configuration) {
    cJSON *group_search_configuration = cJSON_AddArrayToObject(item, "groupSearchConfiguration");
    if(group_search_configuration == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *group_search_configurationListEntry;
    if (ldap_config->group_search_configuration) {
    list_ForEach(group_search_configurationListEntry, ldap_config->group_search_configuration) {
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

ldap_config_t *ldap_config_parseFromJSON(cJSON *ldap_configJSON){

    ldap_config_t *ldap_config_local_var = NULL;

    // define the local variable for ldap_config->server_connection_details
    ldap_server_connection_details_t *server_connection_details_local_nonprim = NULL;

    // define the local variable for ldap_config->authentication_credentials
    ldap_authentication_credentials_t *authentication_credentials_local_nonprim = NULL;

    // define the local variable for ldap_config->user_search_configuration
    ldap_user_search_configuration_t *user_search_configuration_local_nonprim = NULL;

    // define the local variable for ldap_config->user_attribute_mapping
    ldap_user_attribute_mapping_t *user_attribute_mapping_local_nonprim = NULL;

    // define the local list for ldap_config->group_search_configuration
    list_t *group_search_configurationList = NULL;

    // ldap_config->server_connection_details
    cJSON *server_connection_details = cJSON_GetObjectItemCaseSensitive(ldap_configJSON, "serverConnectionDetails");
    if (cJSON_IsNull(server_connection_details)) {
        server_connection_details = NULL;
    }
    if (!server_connection_details) {
        goto end;
    }

    
    server_connection_details_local_nonprim = ldap_server_connection_details_parseFromJSON(server_connection_details); //nonprimitive

    // ldap_config->authentication_credentials
    cJSON *authentication_credentials = cJSON_GetObjectItemCaseSensitive(ldap_configJSON, "authenticationCredentials");
    if (cJSON_IsNull(authentication_credentials)) {
        authentication_credentials = NULL;
    }
    if (!authentication_credentials) {
        goto end;
    }

    
    authentication_credentials_local_nonprim = ldap_authentication_credentials_parseFromJSON(authentication_credentials); //nonprimitive

    // ldap_config->user_search_configuration
    cJSON *user_search_configuration = cJSON_GetObjectItemCaseSensitive(ldap_configJSON, "userSearchConfiguration");
    if (cJSON_IsNull(user_search_configuration)) {
        user_search_configuration = NULL;
    }
    if (!user_search_configuration) {
        goto end;
    }

    
    user_search_configuration_local_nonprim = ldap_user_search_configuration_parseFromJSON(user_search_configuration); //nonprimitive

    // ldap_config->user_attribute_mapping
    cJSON *user_attribute_mapping = cJSON_GetObjectItemCaseSensitive(ldap_configJSON, "userAttributeMapping");
    if (cJSON_IsNull(user_attribute_mapping)) {
        user_attribute_mapping = NULL;
    }
    if (user_attribute_mapping) { 
    user_attribute_mapping_local_nonprim = ldap_user_attribute_mapping_parseFromJSON(user_attribute_mapping); //nonprimitive
    }

    // ldap_config->group_search_configuration
    cJSON *group_search_configuration = cJSON_GetObjectItemCaseSensitive(ldap_configJSON, "groupSearchConfiguration");
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


    ldap_config_local_var = ldap_config_create_internal (
        server_connection_details_local_nonprim,
        authentication_credentials_local_nonprim,
        user_search_configuration_local_nonprim,
        user_attribute_mapping ? user_attribute_mapping_local_nonprim : NULL,
        group_search_configuration ? group_search_configurationList : NULL
        );

    return ldap_config_local_var;
end:
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
    if (user_attribute_mapping_local_nonprim) {
        ldap_user_attribute_mapping_free(user_attribute_mapping_local_nonprim);
        user_attribute_mapping_local_nonprim = NULL;
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
