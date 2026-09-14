/*
 * saml_identity_provider_config.h
 *
 * 
 */

#ifndef _saml_identity_provider_config_H_
#define _saml_identity_provider_config_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct saml_identity_provider_config_t saml_identity_provider_config_t;




typedef struct saml_identity_provider_config_t {
    char *login_url; // string
    char *public_certificate; // string
    char *issuer_url; // string
    char *logout_url; // string

    int _library_owned; // Is the library responsible for freeing this object?
} saml_identity_provider_config_t;

__attribute__((deprecated)) saml_identity_provider_config_t *saml_identity_provider_config_create(
    char *login_url,
    char *public_certificate,
    char *issuer_url,
    char *logout_url
);

void saml_identity_provider_config_free(saml_identity_provider_config_t *saml_identity_provider_config);

saml_identity_provider_config_t *saml_identity_provider_config_parseFromJSON(cJSON *saml_identity_provider_configJSON);

cJSON *saml_identity_provider_config_convertToJSON(saml_identity_provider_config_t *saml_identity_provider_config);

#endif /* _saml_identity_provider_config_H_ */

