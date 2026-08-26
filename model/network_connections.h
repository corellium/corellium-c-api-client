/*
 * network_connections.h
 *
 * 
 */

#ifndef _network_connections_H_
#define _network_connections_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct network_connections_t network_connections_t;

#include "any_type.h"
#include "object.h"



typedef struct network_connections_t {
    list_t *results; //nonprimitive container
    double count; //numeric
    double total; //numeric
    double limit; //numeric
    double offset; //numeric
    int has_more; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} network_connections_t;

__attribute__((deprecated)) network_connections_t *network_connections_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
);

void network_connections_free(network_connections_t *network_connections);

network_connections_t *network_connections_parseFromJSON(cJSON *network_connectionsJSON);

cJSON *network_connections_convertToJSON(network_connections_t *network_connections);

#endif /* _network_connections_H_ */

