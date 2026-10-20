/*
 * ldap_user_attribute_mapping.h
 *
 * 
 */

#ifndef _ldap_user_attribute_mapping_H_
#define _ldap_user_attribute_mapping_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ldap_user_attribute_mapping_t ldap_user_attribute_mapping_t;




typedef struct ldap_user_attribute_mapping_t {
    char *username_attribute; // string
    char *email_attribute; // string
    char *first_name_attribute; // string
    char *last_name_attribute; // string

    int _library_owned; // Is the library responsible for freeing this object?
} ldap_user_attribute_mapping_t;

__attribute__((deprecated)) ldap_user_attribute_mapping_t *ldap_user_attribute_mapping_create(
    char *username_attribute,
    char *email_attribute,
    char *first_name_attribute,
    char *last_name_attribute
);

void ldap_user_attribute_mapping_free(ldap_user_attribute_mapping_t *ldap_user_attribute_mapping);

ldap_user_attribute_mapping_t *ldap_user_attribute_mapping_parseFromJSON(cJSON *ldap_user_attribute_mappingJSON);

cJSON *ldap_user_attribute_mapping_convertToJSON(ldap_user_attribute_mapping_t *ldap_user_attribute_mapping);

#endif /* _ldap_user_attribute_mapping_H_ */

