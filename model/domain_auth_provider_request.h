/*
 * domain_auth_provider_request.h
 *
 * 
 */

#ifndef _domain_auth_provider_request_H_
#define _domain_auth_provider_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct domain_auth_provider_request_t domain_auth_provider_request_t;

#include "open_id_config_v1.h"



typedef struct domain_auth_provider_request_t {
    char *provider_type; // string
    int enabled; //boolean
    char *label; // string
    struct open_id_config_v1_t *config; //model

    int _library_owned; // Is the library responsible for freeing this object?
} domain_auth_provider_request_t;

__attribute__((deprecated)) domain_auth_provider_request_t *domain_auth_provider_request_create(
    char *provider_type,
    int enabled,
    char *label,
    open_id_config_v1_t *config
);

void domain_auth_provider_request_free(domain_auth_provider_request_t *domain_auth_provider_request);

domain_auth_provider_request_t *domain_auth_provider_request_parseFromJSON(cJSON *domain_auth_provider_requestJSON);

cJSON *domain_auth_provider_request_convertToJSON(domain_auth_provider_request_t *domain_auth_provider_request);

#endif /* _domain_auth_provider_request_H_ */

