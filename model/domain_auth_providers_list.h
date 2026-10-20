/*
 * domain_auth_providers_list.h
 *
 * 
 */

#ifndef _domain_auth_providers_list_H_
#define _domain_auth_providers_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct domain_auth_providers_list_t domain_auth_providers_list_t;

#include "domain_auth_provider_response.h"



typedef struct domain_auth_providers_list_t {
    list_t *results; //nonprimitive container
    double count; //numeric
    double total; //numeric
    double limit; //numeric
    double offset; //numeric
    int has_more; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} domain_auth_providers_list_t;

__attribute__((deprecated)) domain_auth_providers_list_t *domain_auth_providers_list_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
);

void domain_auth_providers_list_free(domain_auth_providers_list_t *domain_auth_providers_list);

domain_auth_providers_list_t *domain_auth_providers_list_parseFromJSON(cJSON *domain_auth_providers_listJSON);

cJSON *domain_auth_providers_list_convertToJSON(domain_auth_providers_list_t *domain_auth_providers_list);

#endif /* _domain_auth_providers_list_H_ */

