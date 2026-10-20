/*
 * create_vlan_network_connection_body.h
 *
 * 
 */

#ifndef _create_vlan_network_connection_body_H_
#define _create_vlan_network_connection_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_vlan_network_connection_body_t create_vlan_network_connection_body_t;

#include "vlan_config.h"

// Enum PROVIDER for create_vlan_network_connection_body

typedef enum  { corellium_api_create_vlan_network_connection_body_PROVIDER_NULL = 0, corellium_api_create_vlan_network_connection_body_PROVIDER_vlan } corellium_api_create_vlan_network_connection_body_PROVIDER_e;

char* create_vlan_network_connection_body_provider_ToString(corellium_api_create_vlan_network_connection_body_PROVIDER_e provider);

corellium_api_create_vlan_network_connection_body_PROVIDER_e create_vlan_network_connection_body_provider_FromString(char* provider);



typedef struct create_vlan_network_connection_body_t {
    char *name; // string
    corellium_api_create_vlan_network_connection_body_PROVIDER_e provider; //enum
    struct vlan_config_t *config; //model

    int _library_owned; // Is the library responsible for freeing this object?
} create_vlan_network_connection_body_t;

__attribute__((deprecated)) create_vlan_network_connection_body_t *create_vlan_network_connection_body_create(
    char *name,
    corellium_api_create_vlan_network_connection_body_PROVIDER_e provider,
    vlan_config_t *config
);

void create_vlan_network_connection_body_free(create_vlan_network_connection_body_t *create_vlan_network_connection_body);

create_vlan_network_connection_body_t *create_vlan_network_connection_body_parseFromJSON(cJSON *create_vlan_network_connection_bodyJSON);

cJSON *create_vlan_network_connection_body_convertToJSON(create_vlan_network_connection_body_t *create_vlan_network_connection_body);

#endif /* _create_vlan_network_connection_body_H_ */

