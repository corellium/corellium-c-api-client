/*
 * auth_provider.h
 *
 * 
 */

#ifndef _auth_provider_H_
#define _auth_provider_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct auth_provider_t auth_provider_t;




typedef struct auth_provider_t {
    char *identifier; // string
    char *provider_type; // string
    int enabled; //boolean
    int _default; //boolean
    char *label; // string
    char *name; // string
    char *authorization_url; // string

    int _library_owned; // Is the library responsible for freeing this object?
} auth_provider_t;

__attribute__((deprecated)) auth_provider_t *auth_provider_create(
    char *identifier,
    char *provider_type,
    int enabled,
    int _default,
    char *label,
    char *name,
    char *authorization_url
);

void auth_provider_free(auth_provider_t *auth_provider);

auth_provider_t *auth_provider_parseFromJSON(cJSON *auth_providerJSON);

cJSON *auth_provider_convertToJSON(auth_provider_t *auth_provider);

#endif /* _auth_provider_H_ */

