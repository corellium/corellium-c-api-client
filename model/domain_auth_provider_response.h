/*
 * domain_auth_provider_response.h
 *
 * 
 */

#ifndef _domain_auth_provider_response_H_
#define _domain_auth_provider_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct domain_auth_provider_response_t domain_auth_provider_response_t;

#include "create_domain_auth_provider_response_config.h"



typedef struct domain_auth_provider_response_t {
    char *identifier; // string
    struct create_domain_auth_provider_response_config_t *config; //model
    char *provider_type; // string
    char *label; // string
    int enabled; //boolean
    char *created_by; // string
    int _default; //boolean
    char *authorization_url; // string
    char *name; // string
    char *created_at; //date time
    char *updated_at; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} domain_auth_provider_response_t;

__attribute__((deprecated)) domain_auth_provider_response_t *domain_auth_provider_response_create(
    char *identifier,
    create_domain_auth_provider_response_config_t *config,
    char *provider_type,
    char *label,
    int enabled,
    char *created_by,
    int _default,
    char *authorization_url,
    char *name,
    char *created_at,
    char *updated_at
);

void domain_auth_provider_response_free(domain_auth_provider_response_t *domain_auth_provider_response);

domain_auth_provider_response_t *domain_auth_provider_response_parseFromJSON(cJSON *domain_auth_provider_responseJSON);

cJSON *domain_auth_provider_response_convertToJSON(domain_auth_provider_response_t *domain_auth_provider_response);

#endif /* _domain_auth_provider_response_H_ */

