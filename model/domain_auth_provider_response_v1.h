/*
 * domain_auth_provider_response_v1.h
 *
 * 
 */

#ifndef _domain_auth_provider_response_v1_H_
#define _domain_auth_provider_response_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct domain_auth_provider_response_v1_t domain_auth_provider_response_v1_t;

#include "open_id_config_v1.h"



typedef struct domain_auth_provider_response_v1_t {
    char *identifier; // string
    char *id; // string
    char *provider_type; // string
    char *provider; // string
    char *label; // string
    char *name; // string
    char *authorization_url; // string
    int _default; //boolean
    int enabled; //boolean
    struct open_id_config_v1_t *config; //model
    char *created_by; // string
    char *created_at; // string
    char *updated_at; // string

    int _library_owned; // Is the library responsible for freeing this object?
} domain_auth_provider_response_v1_t;

__attribute__((deprecated)) domain_auth_provider_response_v1_t *domain_auth_provider_response_v1_create(
    char *identifier,
    char *id,
    char *provider_type,
    char *provider,
    char *label,
    char *name,
    char *authorization_url,
    int _default,
    int enabled,
    open_id_config_v1_t *config,
    char *created_by,
    char *created_at,
    char *updated_at
);

void domain_auth_provider_response_v1_free(domain_auth_provider_response_v1_t *domain_auth_provider_response_v1);

domain_auth_provider_response_v1_t *domain_auth_provider_response_v1_parseFromJSON(cJSON *domain_auth_provider_response_v1JSON);

cJSON *domain_auth_provider_response_v1_convertToJSON(domain_auth_provider_response_v1_t *domain_auth_provider_response_v1);

#endif /* _domain_auth_provider_response_v1_H_ */

