/*
 * vlan_network_connection_v1.h
 *
 * 
 */

#ifndef _vlan_network_connection_v1_H_
#define _vlan_network_connection_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct vlan_network_connection_v1_t vlan_network_connection_v1_t;

#include "any_type.h"
#include "object.h"
#include "vlan_config_v1.h"

// Enum PROVIDER for vlan_network_connection_v1

typedef enum  { corellium_api_vlan_network_connection_v1_PROVIDER_NULL = 0, corellium_api_vlan_network_connection_v1_PROVIDER_vlan } corellium_api_vlan_network_connection_v1_PROVIDER_e;

char* vlan_network_connection_v1_provider_ToString(corellium_api_vlan_network_connection_v1_PROVIDER_e provider);

corellium_api_vlan_network_connection_v1_PROVIDER_e vlan_network_connection_v1_provider_FromString(char* provider);



typedef struct vlan_network_connection_v1_t {
    char *identifier; // string
    corellium_api_vlan_network_connection_v1_PROVIDER_e provider; //enum
    char *name; // string
    struct vlan_config_v1_t *config; //model
    object_t *projects; //object
    char *created_at; // string
    char *updated_at; // string
    char *created_by; // string
    char *updated_by; // string

    int _library_owned; // Is the library responsible for freeing this object?
} vlan_network_connection_v1_t;

__attribute__((deprecated)) vlan_network_connection_v1_t *vlan_network_connection_v1_create(
    char *identifier,
    corellium_api_vlan_network_connection_v1_PROVIDER_e provider,
    char *name,
    vlan_config_v1_t *config,
    object_t *projects,
    char *created_at,
    char *updated_at,
    char *created_by,
    char *updated_by
);

void vlan_network_connection_v1_free(vlan_network_connection_v1_t *vlan_network_connection_v1);

vlan_network_connection_v1_t *vlan_network_connection_v1_parseFromJSON(cJSON *vlan_network_connection_v1JSON);

cJSON *vlan_network_connection_v1_convertToJSON(vlan_network_connection_v1_t *vlan_network_connection_v1);

#endif /* _vlan_network_connection_v1_H_ */

