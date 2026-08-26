#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v3_update_network_connection_request_config.h"


char* v3_update_network_connection_request_config_dhcp_mode_ToString(corellium_api_v3_update_network_connection_request_config_DHCPMODE_e dhcp_mode) {
    char* dhcp_modeArray[] =  { "NULL", "internal", "external" };
    return dhcp_modeArray[dhcp_mode];
}

corellium_api_v3_update_network_connection_request_config_DHCPMODE_e v3_update_network_connection_request_config_dhcp_mode_FromString(char* dhcp_mode){
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

static v3_update_network_connection_request_config_t *v3_update_network_connection_request_config_create_internal(
    char *username,
    char *password,
    char *config,
    char *physical_interface,
    double vlan_id,
    corellium_api_v3_update_network_connection_request_config_DHCPMODE_e dhcp_mode,
    char *gateway,
    char *network,
    list_t *dns_servers
    ) {
    v3_update_network_connection_request_config_t *v3_update_network_connection_request_config_local_var = malloc(sizeof(v3_update_network_connection_request_config_t));
    if (!v3_update_network_connection_request_config_local_var) {
        return NULL;
    }
    v3_update_network_connection_request_config_local_var->username = username;
    v3_update_network_connection_request_config_local_var->password = password;
    v3_update_network_connection_request_config_local_var->config = config;
    v3_update_network_connection_request_config_local_var->physical_interface = physical_interface;
    v3_update_network_connection_request_config_local_var->vlan_id = vlan_id;
    v3_update_network_connection_request_config_local_var->dhcp_mode = dhcp_mode;
    v3_update_network_connection_request_config_local_var->gateway = gateway;
    v3_update_network_connection_request_config_local_var->network = network;
    v3_update_network_connection_request_config_local_var->dns_servers = dns_servers;

    v3_update_network_connection_request_config_local_var->_library_owned = 1;
    return v3_update_network_connection_request_config_local_var;
}

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
    ) {
    return v3_update_network_connection_request_config_create_internal (
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

void v3_update_network_connection_request_config_free(v3_update_network_connection_request_config_t *v3_update_network_connection_request_config) {
    if(NULL == v3_update_network_connection_request_config){
        return ;
    }
    if(v3_update_network_connection_request_config->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v3_update_network_connection_request_config_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v3_update_network_connection_request_config->username) {
        free(v3_update_network_connection_request_config->username);
        v3_update_network_connection_request_config->username = NULL;
    }
    if (v3_update_network_connection_request_config->password) {
        free(v3_update_network_connection_request_config->password);
        v3_update_network_connection_request_config->password = NULL;
    }
    if (v3_update_network_connection_request_config->config) {
        free(v3_update_network_connection_request_config->config);
        v3_update_network_connection_request_config->config = NULL;
    }
    if (v3_update_network_connection_request_config->physical_interface) {
        free(v3_update_network_connection_request_config->physical_interface);
        v3_update_network_connection_request_config->physical_interface = NULL;
    }
    if (v3_update_network_connection_request_config->gateway) {
        free(v3_update_network_connection_request_config->gateway);
        v3_update_network_connection_request_config->gateway = NULL;
    }
    if (v3_update_network_connection_request_config->network) {
        free(v3_update_network_connection_request_config->network);
        v3_update_network_connection_request_config->network = NULL;
    }
    if (v3_update_network_connection_request_config->dns_servers) {
        list_ForEach(listEntry, v3_update_network_connection_request_config->dns_servers) {
            free(listEntry->data);
        }
        list_freeList(v3_update_network_connection_request_config->dns_servers);
        v3_update_network_connection_request_config->dns_servers = NULL;
    }
    free(v3_update_network_connection_request_config);
}

cJSON *v3_update_network_connection_request_config_convertToJSON(v3_update_network_connection_request_config_t *v3_update_network_connection_request_config) {
    cJSON *item = cJSON_CreateObject();

    // v3_update_network_connection_request_config->username
    if(v3_update_network_connection_request_config->username) {
    if(cJSON_AddStringToObject(item, "username", v3_update_network_connection_request_config->username) == NULL) {
    goto fail; //String
    }
    }


    // v3_update_network_connection_request_config->password
    if(v3_update_network_connection_request_config->password) {
    if(cJSON_AddStringToObject(item, "password", v3_update_network_connection_request_config->password) == NULL) {
    goto fail; //String
    }
    }


    // v3_update_network_connection_request_config->config
    if (!v3_update_network_connection_request_config->config) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "config", v3_update_network_connection_request_config->config) == NULL) {
    goto fail; //String
    }


    // v3_update_network_connection_request_config->physical_interface
    if (!v3_update_network_connection_request_config->physical_interface) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "physicalInterface", v3_update_network_connection_request_config->physical_interface) == NULL) {
    goto fail; //String
    }


    // v3_update_network_connection_request_config->vlan_id
    if (!v3_update_network_connection_request_config->vlan_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "vlanId", v3_update_network_connection_request_config->vlan_id) == NULL) {
    goto fail; //Numeric
    }


    // v3_update_network_connection_request_config->dhcp_mode
    if (corellium_api_v3_update_network_connection_request_config_DHCPMODE_NULL == v3_update_network_connection_request_config->dhcp_mode) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "dhcpMode", v3_update_network_connection_request_config_dhcp_mode_ToString(v3_update_network_connection_request_config->dhcp_mode)) == NULL)
    {
    goto fail; //Enum
    }


    // v3_update_network_connection_request_config->gateway
    if(v3_update_network_connection_request_config->gateway) {
    if(cJSON_AddStringToObject(item, "gateway", v3_update_network_connection_request_config->gateway) == NULL) {
    goto fail; //String
    }
    }


    // v3_update_network_connection_request_config->network
    if(v3_update_network_connection_request_config->network) {
    if(cJSON_AddStringToObject(item, "network", v3_update_network_connection_request_config->network) == NULL) {
    goto fail; //String
    }
    }


    // v3_update_network_connection_request_config->dns_servers
    if(v3_update_network_connection_request_config->dns_servers) {
    cJSON *dns_servers = cJSON_AddArrayToObject(item, "dnsServers");
    if(dns_servers == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *dns_serversListEntry;
    list_ForEach(dns_serversListEntry, v3_update_network_connection_request_config->dns_servers) {
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

v3_update_network_connection_request_config_t *v3_update_network_connection_request_config_parseFromJSON(cJSON *v3_update_network_connection_request_configJSON){

    v3_update_network_connection_request_config_t *v3_update_network_connection_request_config_local_var = NULL;

    // define the local list for v3_update_network_connection_request_config->dns_servers
    list_t *dns_serversList = NULL;

    // v3_update_network_connection_request_config->username
    cJSON *username = cJSON_GetObjectItemCaseSensitive(v3_update_network_connection_request_configJSON, "username");
    if (cJSON_IsNull(username)) {
        username = NULL;
    }
    if (username) { 
    if(!cJSON_IsString(username) && !cJSON_IsNull(username))
    {
    goto end; //String
    }
    }

    // v3_update_network_connection_request_config->password
    cJSON *password = cJSON_GetObjectItemCaseSensitive(v3_update_network_connection_request_configJSON, "password");
    if (cJSON_IsNull(password)) {
        password = NULL;
    }
    if (password) { 
    if(!cJSON_IsString(password) && !cJSON_IsNull(password))
    {
    goto end; //String
    }
    }

    // v3_update_network_connection_request_config->config
    cJSON *config = cJSON_GetObjectItemCaseSensitive(v3_update_network_connection_request_configJSON, "config");
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

    // v3_update_network_connection_request_config->physical_interface
    cJSON *physical_interface = cJSON_GetObjectItemCaseSensitive(v3_update_network_connection_request_configJSON, "physicalInterface");
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

    // v3_update_network_connection_request_config->vlan_id
    cJSON *vlan_id = cJSON_GetObjectItemCaseSensitive(v3_update_network_connection_request_configJSON, "vlanId");
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

    // v3_update_network_connection_request_config->dhcp_mode
    cJSON *dhcp_mode = cJSON_GetObjectItemCaseSensitive(v3_update_network_connection_request_configJSON, "dhcpMode");
    if (cJSON_IsNull(dhcp_mode)) {
        dhcp_mode = NULL;
    }
    if (!dhcp_mode) {
        goto end;
    }

    corellium_api_v3_update_network_connection_request_config_DHCPMODE_e dhcp_modeVariable;
    
    if(!cJSON_IsString(dhcp_mode))
    {
    goto end; //Enum
    }
    dhcp_modeVariable = v3_update_network_connection_request_config_dhcp_mode_FromString(dhcp_mode->valuestring);

    // v3_update_network_connection_request_config->gateway
    cJSON *gateway = cJSON_GetObjectItemCaseSensitive(v3_update_network_connection_request_configJSON, "gateway");
    if (cJSON_IsNull(gateway)) {
        gateway = NULL;
    }
    if (gateway) { 
    if(!cJSON_IsString(gateway) && !cJSON_IsNull(gateway))
    {
    goto end; //String
    }
    }

    // v3_update_network_connection_request_config->network
    cJSON *network = cJSON_GetObjectItemCaseSensitive(v3_update_network_connection_request_configJSON, "network");
    if (cJSON_IsNull(network)) {
        network = NULL;
    }
    if (network) { 
    if(!cJSON_IsString(network) && !cJSON_IsNull(network))
    {
    goto end; //String
    }
    }

    // v3_update_network_connection_request_config->dns_servers
    cJSON *dns_servers = cJSON_GetObjectItemCaseSensitive(v3_update_network_connection_request_configJSON, "dnsServers");
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


    v3_update_network_connection_request_config_local_var = v3_update_network_connection_request_config_create_internal (
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

    return v3_update_network_connection_request_config_local_var;
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
