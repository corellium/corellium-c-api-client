/*
 * ldap_group_search_configuration.h
 *
 * 
 */

#ifndef _ldap_group_search_configuration_H_
#define _ldap_group_search_configuration_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ldap_group_search_configuration_t ldap_group_search_configuration_t;




typedef struct ldap_group_search_configuration_t {
    char *group_base_dn; // string
    char *group_search_filter; // string
    char *team_id; // string
    char *role; // string

    int _library_owned; // Is the library responsible for freeing this object?
} ldap_group_search_configuration_t;

__attribute__((deprecated)) ldap_group_search_configuration_t *ldap_group_search_configuration_create(
    char *group_base_dn,
    char *group_search_filter,
    char *team_id,
    char *role
);

void ldap_group_search_configuration_free(ldap_group_search_configuration_t *ldap_group_search_configuration);

ldap_group_search_configuration_t *ldap_group_search_configuration_parseFromJSON(cJSON *ldap_group_search_configurationJSON);

cJSON *ldap_group_search_configuration_convertToJSON(ldap_group_search_configuration_t *ldap_group_search_configuration);

#endif /* _ldap_group_search_configuration_H_ */

