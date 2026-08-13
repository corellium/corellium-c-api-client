/*
 * delete_network_connection_options.h
 *
 * 
 */

#ifndef _delete_network_connection_options_H_
#define _delete_network_connection_options_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct delete_network_connection_options_t delete_network_connection_options_t;




typedef struct delete_network_connection_options_t {
    int force; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} delete_network_connection_options_t;

__attribute__((deprecated)) delete_network_connection_options_t *delete_network_connection_options_create(
    int force
);

void delete_network_connection_options_free(delete_network_connection_options_t *delete_network_connection_options);

delete_network_connection_options_t *delete_network_connection_options_parseFromJSON(cJSON *delete_network_connection_optionsJSON);

cJSON *delete_network_connection_options_convertToJSON(delete_network_connection_options_t *delete_network_connection_options);

#endif /* _delete_network_connection_options_H_ */

