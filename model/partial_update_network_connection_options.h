/*
 * partial_update_network_connection_options.h
 *
 * 
 */

#ifndef _partial_update_network_connection_options_H_
#define _partial_update_network_connection_options_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct partial_update_network_connection_options_t partial_update_network_connection_options_t;

#include "update_network_connection_options_config.h"



typedef struct partial_update_network_connection_options_t {
    char *name; // string
    struct update_network_connection_options_config_t *config; //model
    int force; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} partial_update_network_connection_options_t;

__attribute__((deprecated)) partial_update_network_connection_options_t *partial_update_network_connection_options_create(
    char *name,
    update_network_connection_options_config_t *config,
    int force
);

void partial_update_network_connection_options_free(partial_update_network_connection_options_t *partial_update_network_connection_options);

partial_update_network_connection_options_t *partial_update_network_connection_options_parseFromJSON(cJSON *partial_update_network_connection_optionsJSON);

cJSON *partial_update_network_connection_options_convertToJSON(partial_update_network_connection_options_t *partial_update_network_connection_options);

#endif /* _partial_update_network_connection_options_H_ */

