/*
 * config_auth_provider.h
 *
 * 
 */

#ifndef _config_auth_provider_H_
#define _config_auth_provider_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct config_auth_provider_t config_auth_provider_t;




typedef struct config_auth_provider_t {
    char *name; // string
    char *provider_type; // string
    int _default; //boolean
    char *label; // string
    int enabled; //boolean
    char *authorization_url; // string
    char *identifier; // string
    char *provider; // string

    int _library_owned; // Is the library responsible for freeing this object?
} config_auth_provider_t;

__attribute__((deprecated)) config_auth_provider_t *config_auth_provider_create(
    char *name,
    char *provider_type,
    int _default,
    char *label,
    int enabled,
    char *authorization_url,
    char *identifier,
    char *provider
);

void config_auth_provider_free(config_auth_provider_t *config_auth_provider);

config_auth_provider_t *config_auth_provider_parseFromJSON(cJSON *config_auth_providerJSON);

cJSON *config_auth_provider_convertToJSON(config_auth_provider_t *config_auth_provider);

#endif /* _config_auth_provider_H_ */

