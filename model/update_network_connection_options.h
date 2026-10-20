/*
 * update_network_connection_options.h
 *
 * 
 */

#ifndef _update_network_connection_options_H_
#define _update_network_connection_options_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct update_network_connection_options_t update_network_connection_options_t;

#include "update_network_connection_options_config.h"



typedef struct update_network_connection_options_t {
    char *name; // string
    struct update_network_connection_options_config_t *config; //model
    int force; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} update_network_connection_options_t;

__attribute__((deprecated)) update_network_connection_options_t *update_network_connection_options_create(
    char *name,
    update_network_connection_options_config_t *config,
    int force
);

void update_network_connection_options_free(update_network_connection_options_t *update_network_connection_options);

update_network_connection_options_t *update_network_connection_options_parseFromJSON(cJSON *update_network_connection_optionsJSON);

cJSON *update_network_connection_options_convertToJSON(update_network_connection_options_t *update_network_connection_options);

#endif /* _update_network_connection_options_H_ */

