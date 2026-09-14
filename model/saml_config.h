/*
 * saml_config.h
 *
 * SAML provider configuration.
 */

#ifndef _saml_config_H_
#define _saml_config_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct saml_config_t saml_config_t;

#include "saml_group_mapping.h"
#include "saml_identity_provider_config.h"
#include "saml_service_provider_config.h"
#include "saml_user_attribute_mapping.h"



typedef struct saml_config_t {
    struct saml_identity_provider_config_t *identity_provider_config; //model
    struct saml_service_provider_config_t *service_provider_config; //model
    struct saml_user_attribute_mapping_t *user_attribute_mapping; //model
    list_t *group_mapping; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} saml_config_t;

__attribute__((deprecated)) saml_config_t *saml_config_create(
    saml_identity_provider_config_t *identity_provider_config,
    saml_service_provider_config_t *service_provider_config,
    saml_user_attribute_mapping_t *user_attribute_mapping,
    list_t *group_mapping
);

void saml_config_free(saml_config_t *saml_config);

saml_config_t *saml_config_parseFromJSON(cJSON *saml_configJSON);

cJSON *saml_config_convertToJSON(saml_config_t *saml_config);

#endif /* _saml_config_H_ */

