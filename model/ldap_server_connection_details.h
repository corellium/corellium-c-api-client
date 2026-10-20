/*
 * ldap_server_connection_details.h
 *
 * 
 */

#ifndef _ldap_server_connection_details_H_
#define _ldap_server_connection_details_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ldap_server_connection_details_t ldap_server_connection_details_t;




typedef struct ldap_server_connection_details_t {
    char *server_url; // string
    char *port; // string
    char *connection_timeout; // string
    int enable_ldaps; //boolean
    char *ca_cert; // string
    int ca_verify; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} ldap_server_connection_details_t;

__attribute__((deprecated)) ldap_server_connection_details_t *ldap_server_connection_details_create(
    char *server_url,
    char *port,
    char *connection_timeout,
    int enable_ldaps,
    char *ca_cert,
    int ca_verify
);

void ldap_server_connection_details_free(ldap_server_connection_details_t *ldap_server_connection_details);

ldap_server_connection_details_t *ldap_server_connection_details_parseFromJSON(cJSON *ldap_server_connection_detailsJSON);

cJSON *ldap_server_connection_details_convertToJSON(ldap_server_connection_details_t *ldap_server_connection_details);

#endif /* _ldap_server_connection_details_H_ */

