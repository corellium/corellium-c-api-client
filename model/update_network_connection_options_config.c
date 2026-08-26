#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "update_network_connection_options_config.h"


char* update_network_connection_options_config_dhcp_mode_ToString(corellium_api_update_network_connection_options_config_DHCPMODE_e dhcp_mode) {
    char* dhcp_modeArray[] =  { "NULL", "internal", "external" };
    return dhcp_modeArray[dhcp_mode];
}

corellium_api_update_network_connection_options_config_DHCPMODE_e update_network_connection_options_config_dhcp_mode_FromString(char* dhcp_mode){
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

static update_network_connection_options_config_t *update_network_connection_options_config_create_internal(
    char *username,
    char *password,
    char *config,
    char *physical_interface,
    double vlan_id,
    corellium_api_update_network_connection_options_config_DHCPMODE_e dhcp_mode,
    char *gateway,
    char *network,
    list_t *dns_servers
    ) {
    update_network_connection_options_config_t *update_network_connection_options_config_local_var = malloc(sizeof(update_network_connection_options_config_t));
    if (!update_network_connection_options_config_local_var) {
        return NULL;
    }
    update_network_connection_options_config_local_var->username = username;
    update_network_connection_options_config_local_var->password = password;
    update_network_connection_options_config_local_var->config = config;
    update_network_connection_options_config_local_var->physical_interface = physical_interface;
    update_network_connection_options_config_local_var->vlan_id = vlan_id;
    update_network_connection_options_config_local_var->dhcp_mode = dhcp_mode;
    update_network_connection_options_config_local_var->gateway = gateway;
    update_network_connection_options_config_local_var->network = network;
    update_network_connection_options_config_local_var->dns_servers = dns_servers;

    update_network_connection_options_config_local_var->_library_owned = 1;
    return update_network_connection_options_config_local_var;
}

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
    ) {
    return update_network_connection_options_config_create_internal (
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

void update_network_connection_options_config_free(update_network_connection_options_config_t *update_network_connection_options_config) {
    if(NULL == update_network_connection_options_config){
        return ;
    }
    if(update_network_connection_options_config->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "update_network_connection_options_config_free");
        return ;
    }
    listEntry_t *listEntry;
    if (update_network_connection_options_config->username) {
        free(update_network_connection_options_config->username);
        update_network_connection_options_config->username = NULL;
    }
    if (update_network_connection_options_config->password) {
        free(update_network_connection_options_config->password);
        update_network_connection_options_config->password = NULL;
    }
    if (update_network_connection_options_config->config) {
        free(update_network_connection_options_config->config);
        update_network_connection_options_config->config = NULL;
    }
    if (update_network_connection_options_config->physical_interface) {
        free(update_network_connection_options_config->physical_interface);
        update_network_connection_options_config->physical_interface = NULL;
    }
    if (update_network_connection_options_config->gateway) {
        free(update_network_connection_options_config->gateway);
        update_network_connection_options_config->gateway = NULL;
    }
    if (update_network_connection_options_config->network) {
        free(update_network_connection_options_config->network);
        update_network_connection_options_config->network = NULL;
    }
    if (update_network_connection_options_config->dns_servers) {
        list_ForEach(listEntry, update_network_connection_options_config->dns_servers) {
            free(listEntry->data);
        }
        list_freeList(update_network_connection_options_config->dns_servers);
        update_network_connection_options_config->dns_servers = NULL;
    }
    free(update_network_connection_options_config);
}

cJSON *update_network_connection_options_config_convertToJSON(update_network_connection_options_config_t *update_network_connection_options_config) {
    cJSON *item = cJSON_CreateObject();

    // update_network_connection_options_config->username
    if(update_network_connection_options_config->username) {
    if(cJSON_AddStringToObject(item, "username", update_network_connection_options_config->username) == NULL) {
    goto fail; //String
    }
    }


    // update_network_connection_options_config->password
    if(update_network_connection_options_config->password) {
    if(cJSON_AddStringToObject(item, "password", update_network_connection_options_config->password) == NULL) {
    goto fail; //String
    }
    }


    // update_network_connection_options_config->config
    if (!update_network_connection_options_config->config) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "config", update_network_connection_options_config->config) == NULL) {
    goto fail; //String
    }


    // update_network_connection_options_config->physical_interface
    if (!update_network_connection_options_config->physical_interface) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "physicalInterface", update_network_connection_options_config->physical_interface) == NULL) {
    goto fail; //String
    }


    // update_network_connection_options_config->vlan_id
    if (!update_network_connection_options_config->vlan_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "vlanId", update_network_connection_options_config->vlan_id) == NULL) {
    goto fail; //Numeric
    }


    // update_network_connection_options_config->dhcp_mode
    if (corellium_api_update_network_connection_options_config_DHCPMODE_NULL == update_network_connection_options_config->dhcp_mode) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "dhcpMode", update_network_connection_options_config_dhcp_mode_ToString(update_network_connection_options_config->dhcp_mode)) == NULL)
    {
    goto fail; //Enum
    }


    // update_network_connection_options_config->gateway
    if(update_network_connection_options_config->gateway) {
    if(cJSON_AddStringToObject(item, "gateway", update_network_connection_options_config->gateway) == NULL) {
    goto fail; //String
    }
    }


    // update_network_connection_options_config->network
    if(update_network_connection_options_config->network) {
    if(cJSON_AddStringToObject(item, "network", update_network_connection_options_config->network) == NULL) {
    goto fail; //String
    }
    }


    // update_network_connection_options_config->dns_servers
    if(update_network_connection_options_config->dns_servers) {
    cJSON *dns_servers = cJSON_AddArrayToObject(item, "dnsServers");
    if(dns_servers == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *dns_serversListEntry;
    list_ForEach(dns_serversListEntry, update_network_connection_options_config->dns_servers) {
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

update_network_connection_options_config_t *update_network_connection_options_config_parseFromJSON(cJSON *update_network_connection_options_configJSON){

    update_network_connection_options_config_t *update_network_connection_options_config_local_var = NULL;

    // define the local list for update_network_connection_options_config->dns_servers
    list_t *dns_serversList = NULL;

    // update_network_connection_options_config->username
    cJSON *username = cJSON_GetObjectItemCaseSensitive(update_network_connection_options_configJSON, "username");
    if (cJSON_IsNull(username)) {
        username = NULL;
    }
    if (username) { 
    if(!cJSON_IsString(username) && !cJSON_IsNull(username))
    {
    goto end; //String
    }
    }

    // update_network_connection_options_config->password
    cJSON *password = cJSON_GetObjectItemCaseSensitive(update_network_connection_options_configJSON, "password");
    if (cJSON_IsNull(password)) {
        password = NULL;
    }
    if (password) { 
    if(!cJSON_IsString(password) && !cJSON_IsNull(password))
    {
    goto end; //String
    }
    }

    // update_network_connection_options_config->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(update_network_connection_options_configJSON, "config");
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

    // update_network_connection_options_config->physical_interface
    cJSON *physical_interface = cJSON_GetObjectItemCaseSensitive(update_network_connection_options_configJSON, "physicalInterface");
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

    // update_network_connection_options_config->vlan_id
    cJSON *vlan_id = cJSON_GetObjectItemCaseSensitive(update_network_connection_options_configJSON, "vlanId");
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

    // update_network_connection_options_config->dhcp_mode
    cJSON *dhcp_mode = cJSON_GetObjectItemCaseSensitive(update_network_connection_options_configJSON, "dhcpMode");
    if (cJSON_IsNull(dhcp_mode)) {
        dhcp_mode = NULL;
    }
    if (!dhcp_mode) {
        goto end;
    }

    corellium_api_update_network_connection_options_config_DHCPMODE_e dhcp_modeVariable;
    
    if(!cJSON_IsString(dhcp_mode))
    {
    goto end; //Enum
    }
    dhcp_modeVariable = update_network_connection_options_config_dhcp_mode_FromString(dhcp_mode->valuestring);

    // update_network_connection_options_config->gateway
    cJSON *gateway = cJSON_GetObjectItemCaseSensitive(update_network_connection_options_configJSON, "gateway");
    if (cJSON_IsNull(gateway)) {
        gateway = NULL;
    }
    if (gateway) { 
    if(!cJSON_IsString(gateway) && !cJSON_IsNull(gateway))
    {
    goto end; //String
    }
    }

    // update_network_connection_options_config->network
    cJSON *network = cJSON_GetObjectItemCaseSensitive(update_network_connection_options_configJSON, "network");
    if (cJSON_IsNull(network)) {
        network = NULL;
    }
    if (network) { 
    if(!cJSON_IsString(network) && !cJSON_IsNull(network))
    {
    goto end; //String
    }
    }

    // update_network_connection_options_config->dns_servers
    cJSON *dns_servers = cJSON_GetObjectItemCaseSensitive(update_network_connection_options_configJSON, "dnsServers");
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


    update_network_connection_options_config_local_var = update_network_connection_options_config_create_internal (
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

    return update_network_connection_options_config_local_var;
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
