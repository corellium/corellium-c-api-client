/*
 * roles_list_response.h
 *
 * 
 */

#ifndef _roles_list_response_H_
#define _roles_list_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct roles_list_response_t roles_list_response_t;

#include "role.h"



typedef struct roles_list_response_t {
    list_t *results; //nonprimitive container
    double count; //numeric
    double total; //numeric
    double limit; //numeric
    double offset; //numeric
    int has_more; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} roles_list_response_t;

__attribute__((deprecated)) roles_list_response_t *roles_list_response_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
);

void roles_list_response_free(roles_list_response_t *roles_list_response);

roles_list_response_t *roles_list_response_parseFromJSON(cJSON *roles_list_responseJSON);

cJSON *roles_list_response_convertToJSON(roles_list_response_t *roles_list_response);

#endif /* _roles_list_response_H_ */

