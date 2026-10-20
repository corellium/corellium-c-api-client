/*
 * update_network_connection_options_config.h
 *
 * An object containing network connection configuration data. Will vary based on network provider type. See examples.
 */

#ifndef _update_network_connection_options_config_H_
#define _update_network_connection_options_config_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct update_network_connection_options_config_t update_network_connection_options_config_t;

#include "open_vpn_config_v1.h"
#include "vlan_config_v1.h"

// Enum DHCPMODE for update_network_connection_options_config

typedef enum  { corellium_api_update_network_connection_options_config_DHCPMODE_NULL = 0, corellium_api_update_network_connection_options_config_DHCPMODE_internal, corellium_api_update_network_connection_options_config_DHCPMODE_external } corellium_api_update_network_connection_options_config_DHCPMODE_e;

char* update_network_connection_options_config_dhcp_mode_ToString(corellium_api_update_network_connection_options_config_DHCPMODE_e dhcp_mode);

corellium_api_update_network_connection_options_config_DHCPMODE_e update_network_connection_options_config_dhcp_mode_FromString(char* dhcp_mode);



typedef struct update_network_connection_options_config_t {
    char *username; // string
    char *password; // string
    char *config; // string
    char *physical_interface; // string
    double vlan_id; //numeric
    corellium_api_update_network_connection_options_config_DHCPMODE_e dhcp_mode; //enum
    char *gateway; // string
    char *network; // string
    list_t *dns_servers; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} update_network_connection_options_config_t;

__attribute__((deprecated)) update_network_connection_options_config_t *update_network_connection_options_config_create(
    char *username,
    char *password,
    char *config,
    char *physical_interface,
    double vlan_id,
    corellium_api_update_network_connection_options_config_DHCPMODE_e dhcp_mode,
    char *gateway,
    char *network,
    list_t *dns_servers
);

void update_network_connection_options_config_free(update_network_connection_options_config_t *update_network_connection_options_config);

update_network_connection_options_config_t *update_network_connection_options_config_parseFromJSON(cJSON *update_network_connection_options_configJSON);

cJSON *update_network_connection_options_config_convertToJSON(update_network_connection_options_config_t *update_network_connection_options_config);

#endif /* _update_network_connection_options_config_H_ */

