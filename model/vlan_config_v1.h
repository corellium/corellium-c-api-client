/*
 * vlan_config_v1.h
 *
 * 
 */

#ifndef _vlan_config_v1_H_
#define _vlan_config_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct vlan_config_v1_t vlan_config_v1_t;


// Enum DHCPMODE for vlan_config_v1

typedef enum  { corellium_api_vlan_config_v1_DHCPMODE_NULL = 0, corellium_api_vlan_config_v1_DHCPMODE_internal, corellium_api_vlan_config_v1_DHCPMODE_external } corellium_api_vlan_config_v1_DHCPMODE_e;

char* vlan_config_v1_dhcp_mode_ToString(corellium_api_vlan_config_v1_DHCPMODE_e dhcp_mode);

corellium_api_vlan_config_v1_DHCPMODE_e vlan_config_v1_dhcp_mode_FromString(char* dhcp_mode);



typedef struct vlan_config_v1_t {
    char *physical_interface; // string
    double vlan_id; //numeric
    corellium_api_vlan_config_v1_DHCPMODE_e dhcp_mode; //enum
    char *gateway; // string
    char *network; // string
    list_t *dns_servers; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} vlan_config_v1_t;

__attribute__((deprecated)) vlan_config_v1_t *vlan_config_v1_create(
    char *physical_interface,
    double vlan_id,
    corellium_api_vlan_config_v1_DHCPMODE_e dhcp_mode,
    char *gateway,
    char *network,
    list_t *dns_servers
);

void vlan_config_v1_free(vlan_config_v1_t *vlan_config_v1);

vlan_config_v1_t *vlan_config_v1_parseFromJSON(cJSON *vlan_config_v1JSON);

cJSON *vlan_config_v1_convertToJSON(vlan_config_v1_t *vlan_config_v1);

#endif /* _vlan_config_v1_H_ */

