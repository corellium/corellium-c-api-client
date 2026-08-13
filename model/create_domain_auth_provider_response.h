/*
 * create_domain_auth_provider_response.h
 *
 * 
 */

#ifndef _create_domain_auth_provider_response_H_
#define _create_domain_auth_provider_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_domain_auth_provider_response_t create_domain_auth_provider_response_t;

#include "create_domain_auth_provider_response_config.h"



typedef struct create_domain_auth_provider_response_t {
    char *identifier; // string
    struct create_domain_auth_provider_response_config_t *config; //model
    char *provider_type; // string
    char *label; // string
    int enabled; //boolean
    char *created_by; // string
    int _default; //boolean
    char *created_at; //date time
    char *updated_at; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} create_domain_auth_provider_response_t;

__attribute__((deprecated)) create_domain_auth_provider_response_t *create_domain_auth_provider_response_create(
    char *identifier,
    create_domain_auth_provider_response_config_t *config,
    char *provider_type,
    char *label,
    int enabled,
    char *created_by,
    int _default,
    char *created_at,
    char *updated_at
);

void create_domain_auth_provider_response_free(create_domain_auth_provider_response_t *create_domain_auth_provider_response);

create_domain_auth_provider_response_t *create_domain_auth_provider_response_parseFromJSON(cJSON *create_domain_auth_provider_responseJSON);

cJSON *create_domain_auth_provider_response_convertToJSON(create_domain_auth_provider_response_t *create_domain_auth_provider_response);

#endif /* _create_domain_auth_provider_response_H_ */

