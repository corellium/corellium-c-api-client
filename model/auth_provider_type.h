/*
 * auth_provider_type.h
 *
 * 
 */

#ifndef _auth_provider_type_H_
#define _auth_provider_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct auth_provider_type_t auth_provider_type_t;

#include "any_type.h"
#include "object.h"



typedef struct auth_provider_type_t {
    char *provider_type; // string
    object_t *schema; //object

    int _library_owned; // Is the library responsible for freeing this object?
} auth_provider_type_t;

__attribute__((deprecated)) auth_provider_type_t *auth_provider_type_create(
    char *provider_type,
    object_t *schema
);

void auth_provider_type_free(auth_provider_type_t *auth_provider_type);

auth_provider_type_t *auth_provider_type_parseFromJSON(cJSON *auth_provider_typeJSON);

cJSON *auth_provider_type_convertToJSON(auth_provider_type_t *auth_provider_type);

#endif /* _auth_provider_type_H_ */

