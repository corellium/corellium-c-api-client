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

#include "any_type.h"
#include "object.h"



typedef struct update_network_connection_options_t {
    char *name; // string
    object_t *config; //object
    int force; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} update_network_connection_options_t;

__attribute__((deprecated)) update_network_connection_options_t *update_network_connection_options_create(
    char *name,
    object_t *config,
    int force
);

void update_network_connection_options_free(update_network_connection_options_t *update_network_connection_options);

update_network_connection_options_t *update_network_connection_options_parseFromJSON(cJSON *update_network_connection_optionsJSON);

cJSON *update_network_connection_options_convertToJSON(update_network_connection_options_t *update_network_connection_options);

#endif /* _update_network_connection_options_H_ */

