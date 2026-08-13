/*
 * network_status_response.h
 *
 * 
 */

#ifndef _network_status_response_H_
#define _network_status_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct network_status_response_t network_status_response_t;

#include "any_type.h"
#include "object.h"

// Enum STATE for network_status_response

typedef enum  { corellium_api_network_status_response_STATE_NULL = 0, corellium_api_network_status_response_STATE_inactive, corellium_api_network_status_response_STATE_disconnected, corellium_api_network_status_response_STATE_disconnecting, corellium_api_network_status_response_STATE_connecting, corellium_api_network_status_response_STATE_connected, corellium_api_network_status_response_STATE_error } corellium_api_network_status_response_STATE_e;

char* network_status_response_state_ToString(corellium_api_network_status_response_STATE_e state);

corellium_api_network_status_response_STATE_e network_status_response_state_FromString(char* state);



typedef struct network_status_response_t {
    char *type; // string
    char *name; // string
    corellium_api_network_status_response_STATE_e state; //enum
    object_t *params; //object

    int _library_owned; // Is the library responsible for freeing this object?
} network_status_response_t;

__attribute__((deprecated)) network_status_response_t *network_status_response_create(
    char *type,
    char *name,
    corellium_api_network_status_response_STATE_e state,
    object_t *params
);

void network_status_response_free(network_status_response_t *network_status_response);

network_status_response_t *network_status_response_parseFromJSON(cJSON *network_status_responseJSON);

cJSON *network_status_response_convertToJSON(network_status_response_t *network_status_response);

#endif /* _network_status_response_H_ */

