/*
 * domain_auth_provider_config.h
 *
 * Optional configuration.
 */

#ifndef _domain_auth_provider_config_H_
#define _domain_auth_provider_config_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct domain_auth_provider_config_t domain_auth_provider_config_t;

#include "ldap_authentication_credentials.h"
#include "ldap_config.h"
#include "ldap_group_search_configuration.h"
#include "ldap_server_connection_details.h"
#include "ldap_user_attribute_mapping.h"
#include "ldap_user_search_configuration.h"
#include "open_id_config.h"
#include "saml_config.h"
#include "saml_group_mapping.h"
#include "saml_identity_provider_config.h"
#include "saml_service_provider_config.h"



typedef struct domain_auth_provider_config_t {
    struct saml_identity_provider_config_t *identity_provider_config; //model
    struct saml_service_provider_config_t *service_provider_config; //model
    struct ldap_user_attribute_mapping_t *user_attribute_mapping; //model
    list_t *group_mapping; //nonprimitive container
    char *discovery_url; // string
    char *client_id; // string
    char *client_secret; // string
    int invited_only; //boolean
    struct ldap_server_connection_details_t *server_connection_details; //model
    struct ldap_authentication_credentials_t *authentication_credentials; //model
    struct ldap_user_search_configuration_t *user_search_configuration; //model
    list_t *group_search_configuration; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} domain_auth_provider_config_t;

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
);

void domain_auth_provider_config_free(domain_auth_provider_config_t *domain_auth_provider_config);

domain_auth_provider_config_t *domain_auth_provider_config_parseFromJSON(cJSON *domain_auth_provider_configJSON);

cJSON *domain_auth_provider_config_convertToJSON(domain_auth_provider_config_t *domain_auth_provider_config);

#endif /* _domain_auth_provider_config_H_ */

