/*
 * auth_provider_types_list_response.h
 *
 * 
 */

#ifndef _auth_provider_types_list_response_H_
#define _auth_provider_types_list_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct auth_provider_types_list_response_t auth_provider_types_list_response_t;

#include "auth_provider_type.h"



typedef struct auth_provider_types_list_response_t {
    list_t *results; //nonprimitive container
    double count; //numeric
    double total; //numeric
    double limit; //numeric
    double offset; //numeric
    int has_more; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} auth_provider_types_list_response_t;

__attribute__((deprecated)) auth_provider_types_list_response_t *auth_provider_types_list_response_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
);

void auth_provider_types_list_response_free(auth_provider_types_list_response_t *auth_provider_types_list_response);

auth_provider_types_list_response_t *auth_provider_types_list_response_parseFromJSON(cJSON *auth_provider_types_list_responseJSON);

cJSON *auth_provider_types_list_response_convertToJSON(auth_provider_types_list_response_t *auth_provider_types_list_response);

#endif /* _auth_provider_types_list_response_H_ */

