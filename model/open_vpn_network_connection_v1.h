/*
 * open_vpn_network_connection_v1.h
 *
 * 
 */

#ifndef _open_vpn_network_connection_v1_H_
#define _open_vpn_network_connection_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct open_vpn_network_connection_v1_t open_vpn_network_connection_v1_t;

#include "any_type.h"
#include "object.h"
#include "open_vpn_config_v1.h"

// Enum PROVIDER for open_vpn_network_connection_v1

typedef enum  { corellium_api_open_vpn_network_connection_v1_PROVIDER_NULL = 0, corellium_api_open_vpn_network_connection_v1_PROVIDER_openvpn } corellium_api_open_vpn_network_connection_v1_PROVIDER_e;

char* open_vpn_network_connection_v1_provider_ToString(corellium_api_open_vpn_network_connection_v1_PROVIDER_e provider);

corellium_api_open_vpn_network_connection_v1_PROVIDER_e open_vpn_network_connection_v1_provider_FromString(char* provider);



typedef struct open_vpn_network_connection_v1_t {
    char *identifier; // string
    corellium_api_open_vpn_network_connection_v1_PROVIDER_e provider; //enum
    char *name; // string
    struct open_vpn_config_v1_t *config; //model
    object_t *projects; //object
    char *created_at; // string
    char *updated_at; // string
    char *created_by; // string
    char *updated_by; // string

    int _library_owned; // Is the library responsible for freeing this object?
} open_vpn_network_connection_v1_t;

__attribute__((deprecated)) open_vpn_network_connection_v1_t *open_vpn_network_connection_v1_create(
    char *identifier,
    corellium_api_open_vpn_network_connection_v1_PROVIDER_e provider,
    char *name,
    open_vpn_config_v1_t *config,
    object_t *projects,
    char *created_at,
    char *updated_at,
    char *created_by,
    char *updated_by
);

void open_vpn_network_connection_v1_free(open_vpn_network_connection_v1_t *open_vpn_network_connection_v1);

open_vpn_network_connection_v1_t *open_vpn_network_connection_v1_parseFromJSON(cJSON *open_vpn_network_connection_v1JSON);

cJSON *open_vpn_network_connection_v1_convertToJSON(open_vpn_network_connection_v1_t *open_vpn_network_connection_v1);

#endif /* _open_vpn_network_connection_v1_H_ */

