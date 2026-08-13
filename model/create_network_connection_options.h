/*
 * create_network_connection_options.h
 *
 * 
 */

#ifndef _create_network_connection_options_H_
#define _create_network_connection_options_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_network_connection_options_t create_network_connection_options_t;

#include "any_type.h"
#include "object.h"



typedef struct create_network_connection_options_t {
    char *identifier; // string
    char *name; // string
    char *provider; // string
    object_t *config; //object

    int _library_owned; // Is the library responsible for freeing this object?
} create_network_connection_options_t;

__attribute__((deprecated)) create_network_connection_options_t *create_network_connection_options_create(
    char *identifier,
    char *name,
    char *provider,
    object_t *config
);

void create_network_connection_options_free(create_network_connection_options_t *create_network_connection_options);

create_network_connection_options_t *create_network_connection_options_parseFromJSON(cJSON *create_network_connection_optionsJSON);

cJSON *create_network_connection_options_convertToJSON(create_network_connection_options_t *create_network_connection_options);

#endif /* _create_network_connection_options_H_ */

