/*
 * ldap_config.h
 *
 * LDAP provider configuration.
 */

#ifndef _ldap_config_H_
#define _ldap_config_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ldap_config_t ldap_config_t;

#include "ldap_authentication_credentials.h"
#include "ldap_group_search_configuration.h"
#include "ldap_server_connection_details.h"
#include "ldap_user_attribute_mapping.h"
#include "ldap_user_search_configuration.h"



typedef struct ldap_config_t {
    struct ldap_server_connection_details_t *server_connection_details; //model
    struct ldap_authentication_credentials_t *authentication_credentials; //model
    struct ldap_user_search_configuration_t *user_search_configuration; //model
    struct ldap_user_attribute_mapping_t *user_attribute_mapping; //model
    list_t *group_search_configuration; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} ldap_config_t;

__attribute__((deprecated)) ldap_config_t *ldap_config_create(
    ldap_server_connection_details_t *server_connection_details,
    ldap_authentication_credentials_t *authentication_credentials,
    ldap_user_search_configuration_t *user_search_configuration,
    ldap_user_attribute_mapping_t *user_attribute_mapping,
    list_t *group_search_configuration
);

void ldap_config_free(ldap_config_t *ldap_config);

ldap_config_t *ldap_config_parseFromJSON(cJSON *ldap_configJSON);

cJSON *ldap_config_convertToJSON(ldap_config_t *ldap_config);

#endif /* _ldap_config_H_ */

