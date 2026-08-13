/*
 * patch_domain_auth_provider_body.h
 *
 * 
 */

#ifndef _patch_domain_auth_provider_body_H_
#define _patch_domain_auth_provider_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct patch_domain_auth_provider_body_t patch_domain_auth_provider_body_t;

#include "open_id_config.h"



typedef struct patch_domain_auth_provider_body_t {
    char *provider_type; // string
    int enabled; //boolean
    char *label; // string
    struct open_id_config_t *config; //model

    int _library_owned; // Is the library responsible for freeing this object?
} patch_domain_auth_provider_body_t;

__attribute__((deprecated)) patch_domain_auth_provider_body_t *patch_domain_auth_provider_body_create(
    char *provider_type,
    int enabled,
    char *label,
    open_id_config_t *config
);

void patch_domain_auth_provider_body_free(patch_domain_auth_provider_body_t *patch_domain_auth_provider_body);

patch_domain_auth_provider_body_t *patch_domain_auth_provider_body_parseFromJSON(cJSON *patch_domain_auth_provider_bodyJSON);

cJSON *patch_domain_auth_provider_body_convertToJSON(patch_domain_auth_provider_body_t *patch_domain_auth_provider_body);

#endif /* _patch_domain_auth_provider_body_H_ */

