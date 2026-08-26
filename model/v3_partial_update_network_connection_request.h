/*
 * v3_partial_update_network_connection_request.h
 *
 * 
 */

#ifndef _v3_partial_update_network_connection_request_H_
#define _v3_partial_update_network_connection_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v3_partial_update_network_connection_request_t v3_partial_update_network_connection_request_t;

#include "v3_update_network_connection_request_config.h"



typedef struct v3_partial_update_network_connection_request_t {
    char *name; // string
    struct v3_update_network_connection_request_config_t *config; //model
    int force; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} v3_partial_update_network_connection_request_t;

__attribute__((deprecated)) v3_partial_update_network_connection_request_t *v3_partial_update_network_connection_request_create(
    char *name,
    v3_update_network_connection_request_config_t *config,
    int force
);

void v3_partial_update_network_connection_request_free(v3_partial_update_network_connection_request_t *v3_partial_update_network_connection_request);

v3_partial_update_network_connection_request_t *v3_partial_update_network_connection_request_parseFromJSON(cJSON *v3_partial_update_network_connection_requestJSON);

cJSON *v3_partial_update_network_connection_request_convertToJSON(v3_partial_update_network_connection_request_t *v3_partial_update_network_connection_request);

#endif /* _v3_partial_update_network_connection_request_H_ */

