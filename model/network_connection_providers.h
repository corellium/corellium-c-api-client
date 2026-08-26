/*
 * network_connection_providers.h
 *
 * 
 */

#ifndef _network_connection_providers_H_
#define _network_connection_providers_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct network_connection_providers_t network_connection_providers_t;

#include "network_connection_providers_results_inner.h"



typedef struct network_connection_providers_t {
    list_t *results; //nonprimitive container
    double count; //numeric
    double total; //numeric
    double limit; //numeric
    double offset; //numeric
    int has_more; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} network_connection_providers_t;

__attribute__((deprecated)) network_connection_providers_t *network_connection_providers_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
);

void network_connection_providers_free(network_connection_providers_t *network_connection_providers);

network_connection_providers_t *network_connection_providers_parseFromJSON(cJSON *network_connection_providersJSON);

cJSON *network_connection_providers_convertToJSON(network_connection_providers_t *network_connection_providers);

#endif /* _network_connection_providers_H_ */

