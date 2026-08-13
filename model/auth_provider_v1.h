/*
 * auth_provider_v1.h
 *
 * 
 */

#ifndef _auth_provider_v1_H_
#define _auth_provider_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct auth_provider_v1_t auth_provider_v1_t;




typedef struct auth_provider_v1_t {
    char *name; // string
    char *identifier; // string
    char *provider_type; // string
    int _default; //boolean
    char *label; // string
    int enabled; //boolean
    char *authorization_url; // string
    char *id; // string
    char *provider; // string

    int _library_owned; // Is the library responsible for freeing this object?
} auth_provider_v1_t;

__attribute__((deprecated)) auth_provider_v1_t *auth_provider_v1_create(
    char *name,
    char *identifier,
    char *provider_type,
    int _default,
    char *label,
    int enabled,
    char *authorization_url,
    char *id,
    char *provider
);

void auth_provider_v1_free(auth_provider_v1_t *auth_provider_v1);

auth_provider_v1_t *auth_provider_v1_parseFromJSON(cJSON *auth_provider_v1JSON);

cJSON *auth_provider_v1_convertToJSON(auth_provider_v1_t *auth_provider_v1);

#endif /* _auth_provider_v1_H_ */

