/*
 * ldap_user_search_configuration.h
 *
 * 
 */

#ifndef _ldap_user_search_configuration_H_
#define _ldap_user_search_configuration_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ldap_user_search_configuration_t ldap_user_search_configuration_t;




typedef struct ldap_user_search_configuration_t {
    char *base_dn; // string
    char *user_search_base; // string
    char *user_search_filter; // string

    int _library_owned; // Is the library responsible for freeing this object?
} ldap_user_search_configuration_t;

__attribute__((deprecated)) ldap_user_search_configuration_t *ldap_user_search_configuration_create(
    char *base_dn,
    char *user_search_base,
    char *user_search_filter
);

void ldap_user_search_configuration_free(ldap_user_search_configuration_t *ldap_user_search_configuration);

ldap_user_search_configuration_t *ldap_user_search_configuration_parseFromJSON(cJSON *ldap_user_search_configurationJSON);

cJSON *ldap_user_search_configuration_convertToJSON(ldap_user_search_configuration_t *ldap_user_search_configuration);

#endif /* _ldap_user_search_configuration_H_ */

