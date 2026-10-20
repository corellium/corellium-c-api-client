/*
 * network_status.h
 *
 * Egress network connection status for the project. Omitted when the project has none.
 */

#ifndef _network_status_H_
#define _network_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct network_status_t network_status_t;

#include "any_type.h"
#include "object.h"

// Enum STATE for network_status

typedef enum  { corellium_api_network_status_STATE_NULL = 0, corellium_api_network_status_STATE_disconnected, corellium_api_network_status_STATE_disconnecting, corellium_api_network_status_STATE_connecting, corellium_api_network_status_STATE_connected, corellium_api_network_status_STATE_error } corellium_api_network_status_STATE_e;

char* network_status_state_ToString(corellium_api_network_status_STATE_e state);

corellium_api_network_status_STATE_e network_status_state_FromString(char* state);



typedef struct network_status_t {
    char *type; // string
    char *name; // string
    corellium_api_network_status_STATE_e state; //enum
    object_t *details; //object

    int _library_owned; // Is the library responsible for freeing this object?
} network_status_t;

__attribute__((deprecated)) network_status_t *network_status_create(
    char *type,
    char *name,
    corellium_api_network_status_STATE_e state,
    object_t *details
);

void network_status_free(network_status_t *network_status);

network_status_t *network_status_parseFromJSON(cJSON *network_statusJSON);

cJSON *network_status_convertToJSON(network_status_t *network_status);

#endif /* _network_status_H_ */

