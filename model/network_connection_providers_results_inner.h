/*
 * network_connection_providers_results_inner.h
 *
 * 
 */

#ifndef _network_connection_providers_results_inner_H_
#define _network_connection_providers_results_inner_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct network_connection_providers_results_inner_t network_connection_providers_results_inner_t;




typedef struct network_connection_providers_results_inner_t {
    char *name; // string
    char *type; // string

    int _library_owned; // Is the library responsible for freeing this object?
} network_connection_providers_results_inner_t;

__attribute__((deprecated)) network_connection_providers_results_inner_t *network_connection_providers_results_inner_create(
    char *name,
    char *type
);

void network_connection_providers_results_inner_free(network_connection_providers_results_inner_t *network_connection_providers_results_inner);

network_connection_providers_results_inner_t *network_connection_providers_results_inner_parseFromJSON(cJSON *network_connection_providers_results_innerJSON);

cJSON *network_connection_providers_results_inner_convertToJSON(network_connection_providers_results_inner_t *network_connection_providers_results_inner);

#endif /* _network_connection_providers_results_inner_H_ */

