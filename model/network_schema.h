/*
 * network_schema.h
 *
 * Network configuration for this node.
 */

#ifndef _network_schema_H_
#define _network_schema_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct network_schema_t network_schema_t;

#include "vpn_schema.h"



typedef struct network_schema_t {
    list_t *physical_interfaces; //primitive container
    list_t *vpns; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} network_schema_t;

__attribute__((deprecated)) network_schema_t *network_schema_create(
    list_t *physical_interfaces,
    list_t *vpns
);

void network_schema_free(network_schema_t *network_schema);

network_schema_t *network_schema_parseFromJSON(cJSON *network_schemaJSON);

cJSON *network_schema_convertToJSON(network_schema_t *network_schema);

#endif /* _network_schema_H_ */

