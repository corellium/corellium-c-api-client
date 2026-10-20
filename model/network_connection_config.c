#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "network_connection_config.h"


char* network_connection_config_dhcp_mode_ToString(corellium_api_network_connection_config_DHCPMODE_e dhcp_mode) {
    char* dhcp_modeArray[] =  { "NULL", "internal", "external" };
    return dhcp_modeArray[dhcp_mode];
}

corellium_api_network_connection_config_DHCPMODE_e network_connection_config_dhcp_mode_FromString(char* dhcp_mode){
    int stringToReturn = 0;
    char *dhcp_modeArray[] =  { "NULL", "internal", "external" };
    size_t sizeofArray = sizeof(dhcp_modeArray) / sizeof(dhcp_modeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(dhcp_mode, dhcp_modeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static network_connection_config_t *network_connection_config_create_internal(
    char *username,
    char *password,
    char *config,
    char *physical_interface,
    double vlan_id,
    corellium_api_network_connection_config_DHCPMODE_e dhcp_mode,
    char *gateway,
    char *network,
    list_t *dns_servers
    ) {
    network_connection_config_t *network_connection_config_local_var = malloc(sizeof(network_connection_config_t));
    if (!network_connection_config_local_var) {
        return NULL;
    }
    network_connection_config_local_var->username = username;
    network_connection_config_local_var->password = password;
    network_connection_config_local_var->config = config;
    network_connection_config_local_var->physical_interface = physical_interface;
    network_connection_config_local_var->vlan_id = vlan_id;
    network_connection_config_local_var->dhcp_mode = dhcp_mode;
    network_connection_config_local_var->gateway = gateway;
    network_connection_config_local_var->network = network;
    network_connection_config_local_var->dns_servers = dns_servers;

    network_connection_config_local_var->_library_owned = 1;
    return network_connection_config_local_var;
}

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
    ) {
    return network_connection_config_create_internal (
        username,
        password,
        config,
        physical_interface,
        vlan_id,
        dhcp_mode,
        gateway,
        network,
        dns_servers
        );
}

void network_connection_config_free(network_connection_config_t *network_connection_config) {
    if(NULL == network_connection_config){
        return ;
    }
    if(network_connection_config->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "network_connection_config_free");
        return ;
    }
    listEntry_t *listEntry;
    if (network_connection_config->username) {
        free(network_connection_config->username);
        network_connection_config->username = NULL;
    }
    if (network_connection_config->password) {
        free(network_connection_config->password);
        network_connection_config->password = NULL;
    }
    if (network_connection_config->config) {
        free(network_connection_config->config);
        network_connection_config->config = NULL;
    }
    if (network_connection_config->physical_interface) {
        free(network_connection_config->physical_interface);
        network_connection_config->physical_interface = NULL;
    }
    if (network_connection_config->gateway) {
        free(network_connection_config->gateway);
        network_connection_config->gateway = NULL;
    }
    if (network_connection_config->network) {
        free(network_connection_config->network);
        network_connection_config->network = NULL;
    }
    if (network_connection_config->dns_servers) {
        list_ForEach(listEntry, network_connection_config->dns_servers) {
            free(listEntry->data);
        }
        list_freeList(network_connection_config->dns_servers);
        network_connection_config->dns_servers = NULL;
    }
    free(network_connection_config);
}

cJSON *network_connection_config_convertToJSON(network_connection_config_t *network_connection_config) {
    cJSON *item = cJSON_CreateObject();

    // network_connection_config->username
    if(network_connection_config->username) {
    if(cJSON_AddStringToObject(item, "username", network_connection_config->username) == NULL) {
    goto fail; //String
    }
    }


    // network_connection_config->password
    if(network_connection_config->password) {
    if(cJSON_AddStringToObject(item, "password", network_connection_config->password) == NULL) {
    goto fail; //String
    }
    }


    // network_connection_config->config
    if (!network_connection_config->config) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "config", network_connection_config->config) == NULL) {
    goto fail; //String
    }


    // network_connection_config->physical_interface
    if (!network_connection_config->physical_interface) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "physicalInterface", network_connection_config->physical_interface) == NULL) {
    goto fail; //String
    }


    // network_connection_config->vlan_id
    if (!network_connection_config->vlan_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "vlanId", network_connection_config->vlan_id) == NULL) {
    goto fail; //Numeric
    }


    // network_connection_config->dhcp_mode
    if (corellium_api_network_connection_config_DHCPMODE_NULL == network_connection_config->dhcp_mode) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "dhcpMode", network_connection_config_dhcp_mode_ToString(network_connection_config->dhcp_mode)) == NULL)
    {
    goto fail; //Enum
    }


    // network_connection_config->gateway
    if(network_connection_config->gateway) {
    if(cJSON_AddStringToObject(item, "gateway", network_connection_config->gateway) == NULL) {
    goto fail; //String
    }
    }


    // network_connection_config->network
    if(network_connection_config->network) {
    if(cJSON_AddStringToObject(item, "network", network_connection_config->network) == NULL) {
    goto fail; //String
    }
    }


    // network_connection_config->dns_servers
    if(network_connection_config->dns_servers) {
    cJSON *dns_servers = cJSON_AddArrayToObject(item, "dnsServers");
    if(dns_servers == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *dns_serversListEntry;
    list_ForEach(dns_serversListEntry, network_connection_config->dns_servers) {
    if(cJSON_AddStringToObject(dns_servers, "", dns_serversListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

network_connection_config_t *network_connection_config_parseFromJSON(cJSON *network_connection_configJSON){

    network_connection_config_t *network_connection_config_local_var = NULL;

    // define the local list for network_connection_config->dns_servers
    list_t *dns_serversList = NULL;

    // network_connection_config->username
    cJSON *username = cJSON_GetObjectItemCaseSensitive(network_connection_configJSON, "username");
    if (cJSON_IsNull(username)) {
        username = NULL;
    }
    if (username) { 
    if(!cJSON_IsString(username) && !cJSON_IsNull(username))
    {
    goto end; //String
    }
    }

    // network_connection_config->password
    cJSON *password = cJSON_GetObjectItemCaseSensitive(network_connection_configJSON, "password");
    if (cJSON_IsNull(password)) {
        password = NULL;
    }
    if (password) { 
    if(!cJSON_IsString(password) && !cJSON_IsNull(password))
    {
    goto end; //String
    }
    }

    // network_connection_config->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(network_connection_configJSON, "config");
    if (cJSON_IsNull(config)) {
        config = NULL;
    }
    if (!config) {
        goto end;
    }

    
    if(!cJSON_IsString(config))
    {
    goto end; //String
    }

    // network_connection_config->physical_interface
    cJSON *physical_interface = cJSON_GetObjectItemCaseSensitive(network_connection_configJSON, "physicalInterface");
    if (cJSON_IsNull(physical_interface)) {
        physical_interface = NULL;
    }
    if (!physical_interface) {
        goto end;
    }

    
    if(!cJSON_IsString(physical_interface))
    {
    goto end; //String
    }

    // network_connection_config->vlan_id
    cJSON *vlan_id = cJSON_GetObjectItemCaseSensitive(network_connection_configJSON, "vlanId");
    if (cJSON_IsNull(vlan_id)) {
        vlan_id = NULL;
    }
    if (!vlan_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(vlan_id))
    {
    goto end; //Numeric
    }

    // network_connection_config->dhcp_mode
    cJSON *dhcp_mode = cJSON_GetObjectItemCaseSensitive(network_connection_configJSON, "dhcpMode");
    if (cJSON_IsNull(dhcp_mode)) {
        dhcp_mode = NULL;
    }
    if (!dhcp_mode) {
        goto end;
    }

    corellium_api_network_connection_config_DHCPMODE_e dhcp_modeVariable;
    
    if(!cJSON_IsString(dhcp_mode))
    {
    goto end; //Enum
    }
    dhcp_modeVariable = network_connection_config_dhcp_mode_FromString(dhcp_mode->valuestring);

    // network_connection_config->gateway
    cJSON *gateway = cJSON_GetObjectItemCaseSensitive(network_connection_configJSON, "gateway");
    if (cJSON_IsNull(gateway)) {
        gateway = NULL;
    }
    if (gateway) { 
    if(!cJSON_IsString(gateway) && !cJSON_IsNull(gateway))
    {
    goto end; //String
    }
    }

    // network_connection_config->network
    cJSON *network = cJSON_GetObjectItemCaseSensitive(network_connection_configJSON, "network");
    if (cJSON_IsNull(network)) {
        network = NULL;
    }
    if (network) { 
    if(!cJSON_IsString(network) && !cJSON_IsNull(network))
    {
    goto end; //String
    }
    }

    // network_connection_config->dns_servers
    cJSON *dns_servers = cJSON_GetObjectItemCaseSensitive(network_connection_configJSON, "dnsServers");
    if (cJSON_IsNull(dns_servers)) {
        dns_servers = NULL;
    }
    if (dns_servers) { 
    cJSON *dns_servers_local = NULL;
    if(!cJSON_IsArray(dns_servers)) {
        goto end;//primitive container
    }
    dns_serversList = list_createList();

    cJSON_ArrayForEach(dns_servers_local, dns_servers)
    {
        if(!cJSON_IsString(dns_servers_local))
        {
            goto end;
        }
        list_addElement(dns_serversList , strdup(dns_servers_local->valuestring));
    }
    }


    network_connection_config_local_var = network_connection_config_create_internal (
        username && !cJSON_IsNull(username) ? strdup(username->valuestring) : NULL,
        password && !cJSON_IsNull(password) ? strdup(password->valuestring) : NULL,
        strdup(config->valuestring),
        strdup(physical_interface->valuestring),
        vlan_id->valuedouble,
        dhcp_modeVariable,
        gateway && !cJSON_IsNull(gateway) ? strdup(gateway->valuestring) : NULL,
        network && !cJSON_IsNull(network) ? strdup(network->valuestring) : NULL,
        dns_servers ? dns_serversList : NULL
        );

    return network_connection_config_local_var;
end:
    if (dns_serversList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, dns_serversList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(dns_serversList);
        dns_serversList = NULL;
    }
    return NULL;

}
