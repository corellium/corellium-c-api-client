/*
 * update_network_connection_body.h
 *
 * 
 */

#ifndef _update_network_connection_body_H_
#define _update_network_connection_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct update_network_connection_body_t update_network_connection_body_t;

#include "network_connection_config.h"



typedef struct update_network_connection_body_t {
    char *name; // string
    struct network_connection_config_t *config; //model
    int force; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} update_network_connection_body_t;

__attribute__((deprecated)) update_network_connection_body_t *update_network_connection_body_create(
    char *name,
    network_connection_config_t *config,
    int force
);

void update_network_connection_body_free(update_network_connection_body_t *update_network_connection_body);

update_network_connection_body_t *update_network_connection_body_parseFromJSON(cJSON *update_network_connection_bodyJSON);

cJSON *update_network_connection_body_convertToJSON(update_network_connection_body_t *update_network_connection_body);

#endif /* _update_network_connection_body_H_ */

