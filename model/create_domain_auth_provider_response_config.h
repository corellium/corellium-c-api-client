/*
 * create_domain_auth_provider_response_config.h
 *
 * Optional configuration.
 */

#ifndef _create_domain_auth_provider_response_config_H_
#define _create_domain_auth_provider_response_config_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_domain_auth_provider_response_config_t create_domain_auth_provider_response_config_t;




typedef struct create_domain_auth_provider_response_config_t {
    char *discovery_url; // string
    char *client_id; // string
    char *client_secret; // string
    int invited_only; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} create_domain_auth_provider_response_config_t;

__attribute__((deprecated)) create_domain_auth_provider_response_config_t *create_domain_auth_provider_response_config_create(
    char *discovery_url,
    char *client_id,
    char *client_secret,
    int invited_only
);

void create_domain_auth_provider_response_config_free(create_domain_auth_provider_response_config_t *create_domain_auth_provider_response_config);

create_domain_auth_provider_response_config_t *create_domain_auth_provider_response_config_parseFromJSON(cJSON *create_domain_auth_provider_response_configJSON);

cJSON *create_domain_auth_provider_response_config_convertToJSON(create_domain_auth_provider_response_config_t *create_domain_auth_provider_response_config);

#endif /* _create_domain_auth_provider_response_config_H_ */

