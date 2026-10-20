/*
 * create_vlan_network_connection_body_v1.h
 *
 * 
 */

#ifndef _create_vlan_network_connection_body_v1_H_
#define _create_vlan_network_connection_body_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_vlan_network_connection_body_v1_t create_vlan_network_connection_body_v1_t;

#include "vlan_config_v1.h"

// Enum PROVIDER for create_vlan_network_connection_body_v1

typedef enum  { corellium_api_create_vlan_network_connection_body_v1_PROVIDER_NULL = 0, corellium_api_create_vlan_network_connection_body_v1_PROVIDER_vlan } corellium_api_create_vlan_network_connection_body_v1_PROVIDER_e;

char* create_vlan_network_connection_body_v1_provider_ToString(corellium_api_create_vlan_network_connection_body_v1_PROVIDER_e provider);

corellium_api_create_vlan_network_connection_body_v1_PROVIDER_e create_vlan_network_connection_body_v1_provider_FromString(char* provider);



typedef struct create_vlan_network_connection_body_v1_t {
    char *name; // string
    corellium_api_create_vlan_network_connection_body_v1_PROVIDER_e provider; //enum
    struct vlan_config_v1_t *config; //model

    int _library_owned; // Is the library responsible for freeing this object?
} create_vlan_network_connection_body_v1_t;

__attribute__((deprecated)) create_vlan_network_connection_body_v1_t *create_vlan_network_connection_body_v1_create(
    char *name,
    corellium_api_create_vlan_network_connection_body_v1_PROVIDER_e provider,
    vlan_config_v1_t *config
);

void create_vlan_network_connection_body_v1_free(create_vlan_network_connection_body_v1_t *create_vlan_network_connection_body_v1);

create_vlan_network_connection_body_v1_t *create_vlan_network_connection_body_v1_parseFromJSON(cJSON *create_vlan_network_connection_body_v1JSON);

cJSON *create_vlan_network_connection_body_v1_convertToJSON(create_vlan_network_connection_body_v1_t *create_vlan_network_connection_body_v1);

#endif /* _create_vlan_network_connection_body_v1_H_ */

