#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "vlan_config.h"


char* vlan_config_dhcp_mode_ToString(corellium_api_vlan_config_DHCPMODE_e dhcp_mode) {
    char* dhcp_modeArray[] =  { "NULL", "internal", "external" };
    return dhcp_modeArray[dhcp_mode];
}

corellium_api_vlan_config_DHCPMODE_e vlan_config_dhcp_mode_FromString(char* dhcp_mode){
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

static vlan_config_t *vlan_config_create_internal(
    char *physical_interface,
    double vlan_id,
    corellium_api_vlan_config_DHCPMODE_e dhcp_mode,
    char *gateway,
    char *network,
    list_t *dns_servers
    ) {
    vlan_config_t *vlan_config_local_var = malloc(sizeof(vlan_config_t));
    if (!vlan_config_local_var) {
        return NULL;
    }
    vlan_config_local_var->physical_interface = physical_interface;
    vlan_config_local_var->vlan_id = vlan_id;
    vlan_config_local_var->dhcp_mode = dhcp_mode;
    vlan_config_local_var->gateway = gateway;
    vlan_config_local_var->network = network;
    vlan_config_local_var->dns_servers = dns_servers;

    vlan_config_local_var->_library_owned = 1;
    return vlan_config_local_var;
}

__attribute__((deprecated)) vlan_config_t *vlan_config_create(
    char *physical_interface,
    double vlan_id,
    corellium_api_vlan_config_DHCPMODE_e dhcp_mode,
    char *gateway,
    char *network,
    list_t *dns_servers
    ) {
    return vlan_config_create_internal (
        physical_interface,
        vlan_id,
        dhcp_mode,
        gateway,
        network,
        dns_servers
        );
}

void vlan_config_free(vlan_config_t *vlan_config) {
    if(NULL == vlan_config){
        return ;
    }
    if(vlan_config->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "vlan_config_free");
        return ;
    }
    listEntry_t *listEntry;
    if (vlan_config->physical_interface) {
        free(vlan_config->physical_interface);
        vlan_config->physical_interface = NULL;
    }
    if (vlan_config->gateway) {
        free(vlan_config->gateway);
        vlan_config->gateway = NULL;
    }
    if (vlan_config->network) {
        free(vlan_config->network);
        vlan_config->network = NULL;
    }
    if (vlan_config->dns_servers) {
        list_ForEach(listEntry, vlan_config->dns_servers) {
            free(listEntry->data);
        }
        list_freeList(vlan_config->dns_servers);
        vlan_config->dns_servers = NULL;
    }
    free(vlan_config);
}

cJSON *vlan_config_convertToJSON(vlan_config_t *vlan_config) {
    cJSON *item = cJSON_CreateObject();

    // vlan_config->physical_interface
    if (!vlan_config->physical_interface) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "physicalInterface", vlan_config->physical_interface) == NULL) {
    goto fail; //String
    }


    // vlan_config->vlan_id
    if (!vlan_config->vlan_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "vlanId", vlan_config->vlan_id) == NULL) {
    goto fail; //Numeric
    }


    // vlan_config->dhcp_mode
    if (corellium_api_vlan_config_DHCPMODE_NULL == vlan_config->dhcp_mode) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "dhcpMode", vlan_config_dhcp_mode_ToString(vlan_config->dhcp_mode)) == NULL)
    {
    goto fail; //Enum
    }


    // vlan_config->gateway
    if(vlan_config->gateway) {
    if(cJSON_AddStringToObject(item, "gateway", vlan_config->gateway) == NULL) {
    goto fail; //String
    }
    }


    // vlan_config->network
    if(vlan_config->network) {
    if(cJSON_AddStringToObject(item, "network", vlan_config->network) == NULL) {
    goto fail; //String
    }
    }


    // vlan_config->dns_servers
    if(vlan_config->dns_servers) {
    cJSON *dns_servers = cJSON_AddArrayToObject(item, "dnsServers");
    if(dns_servers == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *dns_serversListEntry;
    list_ForEach(dns_serversListEntry, vlan_config->dns_servers) {
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

vlan_config_t *vlan_config_parseFromJSON(cJSON *vlan_configJSON){

    vlan_config_t *vlan_config_local_var = NULL;

    // define the local list for vlan_config->dns_servers
    list_t *dns_serversList = NULL;

    // vlan_config->physical_interface
    cJSON *physical_interface = cJSON_GetObjectItemCaseSensitive(vlan_configJSON, "physicalInterface");
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

    // vlan_config->vlan_id
    cJSON *vlan_id = cJSON_GetObjectItemCaseSensitive(vlan_configJSON, "vlanId");
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

    // vlan_config->dhcp_mode
    cJSON *dhcp_mode = cJSON_GetObjectItemCaseSensitive(vlan_configJSON, "dhcpMode");
    if (cJSON_IsNull(dhcp_mode)) {
        dhcp_mode = NULL;
    }
    if (!dhcp_mode) {
        goto end;
    }

    corellium_api_vlan_config_DHCPMODE_e dhcp_modeVariable;
    
    if(!cJSON_IsString(dhcp_mode))
    {
    goto end; //Enum
    }
    dhcp_modeVariable = vlan_config_dhcp_mode_FromString(dhcp_mode->valuestring);

    // vlan_config->gateway
    cJSON *gateway = cJSON_GetObjectItemCaseSensitive(vlan_configJSON, "gateway");
    if (cJSON_IsNull(gateway)) {
        gateway = NULL;
    }
    if (gateway) { 
    if(!cJSON_IsString(gateway) && !cJSON_IsNull(gateway))
    {
    goto end; //String
    }
    }

    // vlan_config->network
    cJSON *network = cJSON_GetObjectItemCaseSensitive(vlan_configJSON, "network");
    if (cJSON_IsNull(network)) {
        network = NULL;
    }
    if (network) { 
    if(!cJSON_IsString(network) && !cJSON_IsNull(network))
    {
    goto end; //String
    }
    }

    // vlan_config->dns_servers
    cJSON *dns_servers = cJSON_GetObjectItemCaseSensitive(vlan_configJSON, "dnsServers");
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


    vlan_config_local_var = vlan_config_create_internal (
        strdup(physical_interface->valuestring),
        vlan_id->valuedouble,
        dhcp_modeVariable,
        gateway && !cJSON_IsNull(gateway) ? strdup(gateway->valuestring) : NULL,
        network && !cJSON_IsNull(network) ? strdup(network->valuestring) : NULL,
        dns_servers ? dns_serversList : NULL
        );

    return vlan_config_local_var;
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
