/*
 * partial_update_network_connection_body.h
 *
 * 
 */

#ifndef _partial_update_network_connection_body_H_
#define _partial_update_network_connection_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct partial_update_network_connection_body_t partial_update_network_connection_body_t;

#include "network_connection_config.h"



typedef struct partial_update_network_connection_body_t {
    char *name; // string
    struct network_connection_config_t *config; //model
    int force; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} partial_update_network_connection_body_t;

__attribute__((deprecated)) partial_update_network_connection_body_t *partial_update_network_connection_body_create(
    char *name,
    network_connection_config_t *config,
    int force
);

void partial_update_network_connection_body_free(partial_update_network_connection_body_t *partial_update_network_connection_body);

partial_update_network_connection_body_t *partial_update_network_connection_body_parseFromJSON(cJSON *partial_update_network_connection_bodyJSON);

cJSON *partial_update_network_connection_body_convertToJSON(partial_update_network_connection_body_t *partial_update_network_connection_body);

#endif /* _partial_update_network_connection_body_H_ */

