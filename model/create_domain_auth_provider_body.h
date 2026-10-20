/*
 * create_domain_auth_provider_body.h
 *
 * 
 */

#ifndef _create_domain_auth_provider_body_H_
#define _create_domain_auth_provider_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_domain_auth_provider_body_t create_domain_auth_provider_body_t;

#include "domain_auth_provider_config.h"



typedef struct create_domain_auth_provider_body_t {
    char *provider_type; // string
    int enabled; //boolean
    char *label; // string
    struct domain_auth_provider_config_t *config; //model

    int _library_owned; // Is the library responsible for freeing this object?
} create_domain_auth_provider_body_t;

__attribute__((deprecated)) create_domain_auth_provider_body_t *create_domain_auth_provider_body_create(
    char *provider_type,
    int enabled,
    char *label,
    domain_auth_provider_config_t *config
);

void create_domain_auth_provider_body_free(create_domain_auth_provider_body_t *create_domain_auth_provider_body);

create_domain_auth_provider_body_t *create_domain_auth_provider_body_parseFromJSON(cJSON *create_domain_auth_provider_bodyJSON);

cJSON *create_domain_auth_provider_body_convertToJSON(create_domain_auth_provider_body_t *create_domain_auth_provider_body);

#endif /* _create_domain_auth_provider_body_H_ */

