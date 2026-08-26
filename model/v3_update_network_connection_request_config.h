/*
 * v3_update_network_connection_request_config.h
 *
 * Additional network configuration based on selected provider.
 */

#ifndef _v3_update_network_connection_request_config_H_
#define _v3_update_network_connection_request_config_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v3_update_network_connection_request_config_t v3_update_network_connection_request_config_t;

#include "open_vpn_config.h"
#include "vlan_config.h"

// Enum DHCPMODE for v3_update_network_connection_request_config

typedef enum  { corellium_api_v3_update_network_connection_request_config_DHCPMODE_NULL = 0, corellium_api_v3_update_network_connection_request_config_DHCPMODE_internal, corellium_api_v3_update_network_connection_request_config_DHCPMODE_external } corellium_api_v3_update_network_connection_request_config_DHCPMODE_e;

char* v3_update_network_connection_request_config_dhcp_mode_ToString(corellium_api_v3_update_network_connection_request_config_DHCPMODE_e dhcp_mode);

corellium_api_v3_update_network_connection_request_config_DHCPMODE_e v3_update_network_connection_request_config_dhcp_mode_FromString(char* dhcp_mode);



typedef struct v3_update_network_connection_request_config_t {
    char *username; // string
    char *password; // string
    char *config; // string
    char *physical_interface; // string
    double vlan_id; //numeric
    corellium_api_v3_update_network_connection_request_config_DHCPMODE_e dhcp_mode; //enum
    char *gateway; // string
    char *network; // string
    list_t *dns_servers; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v3_update_network_connection_request_config_t;

__attribute__((deprecated)) v3_update_network_connection_request_config_t *v3_update_network_connection_request_config_create(
    char *username,
    char *password,
    char *config,
    char *physical_interface,
    double vlan_id,
    corellium_api_v3_update_network_connection_request_config_DHCPMODE_e dhcp_mode,
    char *gateway,
    char *network,
    list_t *dns_servers
);

void v3_update_network_connection_request_config_free(v3_update_network_connection_request_config_t *v3_update_network_connection_request_config);

v3_update_network_connection_request_config_t *v3_update_network_connection_request_config_parseFromJSON(cJSON *v3_update_network_connection_request_configJSON);

cJSON *v3_update_network_connection_request_config_convertToJSON(v3_update_network_connection_request_config_t *v3_update_network_connection_request_config);

#endif /* _v3_update_network_connection_request_config_H_ */

