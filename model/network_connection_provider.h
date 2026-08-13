/*
 * network_connection_provider.h
 *
 * 
 */

#ifndef _network_connection_provider_H_
#define _network_connection_provider_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct network_connection_provider_t network_connection_provider_t;




typedef struct network_connection_provider_t {
    char *name; // string
    char *type; // string

    int _library_owned; // Is the library responsible for freeing this object?
} network_connection_provider_t;

__attribute__((deprecated)) network_connection_provider_t *network_connection_provider_create(
    char *name,
    char *type
);

void network_connection_provider_free(network_connection_provider_t *network_connection_provider);

network_connection_provider_t *network_connection_provider_parseFromJSON(cJSON *network_connection_providerJSON);

cJSON *network_connection_provider_convertToJSON(network_connection_provider_t *network_connection_provider);

#endif /* _network_connection_provider_H_ */

