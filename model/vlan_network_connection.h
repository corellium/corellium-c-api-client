/*
 * vlan_network_connection.h
 *
 * 
 */

#ifndef _vlan_network_connection_H_
#define _vlan_network_connection_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct vlan_network_connection_t vlan_network_connection_t;

#include "any_type.h"
#include "object.h"
#include "vlan_config.h"

// Enum PROVIDER for vlan_network_connection

typedef enum  { corellium_api_vlan_network_connection_PROVIDER_NULL = 0, corellium_api_vlan_network_connection_PROVIDER_vlan } corellium_api_vlan_network_connection_PROVIDER_e;

char* vlan_network_connection_provider_ToString(corellium_api_vlan_network_connection_PROVIDER_e provider);

corellium_api_vlan_network_connection_PROVIDER_e vlan_network_connection_provider_FromString(char* provider);



typedef struct vlan_network_connection_t {
    char *name; // string
    corellium_api_vlan_network_connection_PROVIDER_e provider; //enum
    struct vlan_config_t *config; //model
    char *identifier; // string
    object_t *projects; //object
    char *created_at; //date time
    char *updated_at; //date time
    char *created_by; // string
    char *updated_by; // string

    int _library_owned; // Is the library responsible for freeing this object?
} vlan_network_connection_t;

__attribute__((deprecated)) vlan_network_connection_t *vlan_network_connection_create(
    char *name,
    corellium_api_vlan_network_connection_PROVIDER_e provider,
    vlan_config_t *config,
    char *identifier,
    object_t *projects,
    char *created_at,
    char *updated_at,
    char *created_by,
    char *updated_by
);

void vlan_network_connection_free(vlan_network_connection_t *vlan_network_connection);

vlan_network_connection_t *vlan_network_connection_parseFromJSON(cJSON *vlan_network_connectionJSON);

cJSON *vlan_network_connection_convertToJSON(vlan_network_connection_t *vlan_network_connection);

#endif /* _vlan_network_connection_H_ */

