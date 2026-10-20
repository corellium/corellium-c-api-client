/*
 * ldap_authentication_credentials.h
 *
 * 
 */

#ifndef _ldap_authentication_credentials_H_
#define _ldap_authentication_credentials_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ldap_authentication_credentials_t ldap_authentication_credentials_t;




typedef struct ldap_authentication_credentials_t {
    char *bind_dn; // string
    char *bind_password; // string

    int _library_owned; // Is the library responsible for freeing this object?
} ldap_authentication_credentials_t;

__attribute__((deprecated)) ldap_authentication_credentials_t *ldap_authentication_credentials_create(
    char *bind_dn,
    char *bind_password
);

void ldap_authentication_credentials_free(ldap_authentication_credentials_t *ldap_authentication_credentials);

ldap_authentication_credentials_t *ldap_authentication_credentials_parseFromJSON(cJSON *ldap_authentication_credentialsJSON);

cJSON *ldap_authentication_credentials_convertToJSON(ldap_authentication_credentials_t *ldap_authentication_credentials);

#endif /* _ldap_authentication_credentials_H_ */

