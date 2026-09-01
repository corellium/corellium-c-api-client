/*
 * network_connection_config.h
 *
 * Additional network configuration based on selected provider.
 */

#ifndef _network_connection_config_H_
#define _network_connection_config_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct network_connection_config_t network_connection_config_t;

#include "open_vpn_config.h"
#include "vlan_config.h"

// Enum DHCPMODE for network_connection_config

typedef enum  { corellium_api_network_connection_config_DHCPMODE_NULL = 0, corellium_api_network_connection_config_DHCPMODE_internal, corellium_api_network_connection_config_DHCPMODE_external } corellium_api_network_connection_config_DHCPMODE_e;

char* network_connection_config_dhcp_mode_ToString(corellium_api_network_connection_config_DHCPMODE_e dhcp_mode);

corellium_api_network_connection_config_DHCPMODE_e network_connection_config_dhcp_mode_FromString(char* dhcp_mode);



typedef struct network_connection_config_t {
    char *username; // string
    char *password; // string
    char *config; // string
    char *physical_interface; // string
    double vlan_id; //numeric
    corellium_api_network_connection_config_DHCPMODE_e dhcp_mode; //enum
    char *gateway; // string
    char *network; // string
    list_t *dns_servers; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} network_connection_config_t;

__attribute__((deprecated)) network_connection_config_t *network_connection_config_create(
    char *username,
    char *password,
    char *config,
    char *physical_interface,
    double vlan_id,
    corellium_api_network_connection_config_DHCPMODE_e dhcp_mode,
    char *gateway,
    char *network,
    list_t *dns_servers
);

void network_connection_config_free(network_connection_config_t *network_connection_config);

network_connection_config_t *network_connection_config_parseFromJSON(cJSON *network_connection_configJSON);

cJSON *network_connection_config_convertToJSON(network_connection_config_t *network_connection_config);

#endif /* _network_connection_config_H_ */

