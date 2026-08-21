/*
 * network_connection.h
 *
 * 
 */

#ifndef _network_connection_H_
#define _network_connection_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct network_connection_t network_connection_t;

#include "any_type.h"
#include "object.h"



typedef struct network_connection_t {
    char *identifier; // string
    char *provider; // string
    char *name; // string
    object_t *config; //object
    object_t *projects; //object
    char *created_at; // string
    char *updated_at; // string
    char *created_by; // string
    char *updated_by; // string

    int _library_owned; // Is the library responsible for freeing this object?
} network_connection_t;

__attribute__((deprecated)) network_connection_t *network_connection_create(
    char *identifier,
    char *provider,
    char *name,
    object_t *config,
    object_t *projects,
    char *created_at,
    char *updated_at,
    char *created_by,
    char *updated_by
);

void network_connection_free(network_connection_t *network_connection);

network_connection_t *network_connection_parseFromJSON(cJSON *network_connectionJSON);

cJSON *network_connection_convertToJSON(network_connection_t *network_connection);

#endif /* _network_connection_H_ */

