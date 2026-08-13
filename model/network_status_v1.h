/*
 * network_status_v1.h
 *
 * 
 */

#ifndef _network_status_v1_H_
#define _network_status_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct network_status_v1_t network_status_v1_t;


// Enum STATE for network_status_v1

typedef enum  { corellium_api_network_status_v1_STATE_NULL = 0, corellium_api_network_status_v1_STATE_disconnected, corellium_api_network_status_v1_STATE_disconnecting, corellium_api_network_status_v1_STATE_connecting, corellium_api_network_status_v1_STATE_connected, corellium_api_network_status_v1_STATE_error } corellium_api_network_status_v1_STATE_e;

char* network_status_v1_state_ToString(corellium_api_network_status_v1_STATE_e state);

corellium_api_network_status_v1_STATE_e network_status_v1_state_FromString(char* state);



typedef struct network_status_v1_t {
    char *type; // string
    char *name; // string
    corellium_api_network_status_v1_STATE_e state; //enum

    int _library_owned; // Is the library responsible for freeing this object?
} network_status_v1_t;

__attribute__((deprecated)) network_status_v1_t *network_status_v1_create(
    char *type,
    char *name,
    corellium_api_network_status_v1_STATE_e state
);

void network_status_v1_free(network_status_v1_t *network_status_v1);

network_status_v1_t *network_status_v1_parseFromJSON(cJSON *network_status_v1JSON);

cJSON *network_status_v1_convertToJSON(network_status_v1_t *network_status_v1);

#endif /* _network_status_v1_H_ */

