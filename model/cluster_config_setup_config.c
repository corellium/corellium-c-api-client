#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cluster_config_setup_config.h"



static cluster_config_setup_config_t *cluster_config_setup_config_create_internal(
    int on_site,
    double artifacts_volume_size,
    double network_monitor_interval,
    char *max_network_monitor_file_size,
    char *ca_cert_file_src,
    char *local_ip,
    char *instance_ip_block_netmask,
    char *instance_gateway,
    list_t *instance_dns_servers,
    double report_interval,
    char *cert_key_file_data,
    char *default_ssid,
    int enable_experimental_devices,
    list_t *controller_nodes,
    char *domain,
    char *interface,
    char *virtual_device_interface,
    char *auto_approve_trials,
    double snapshot_limit,
    double max_download_agents_per_device,
    char *client_cert_file,
    char *docker_host_ip,
    char *domain_name,
    char *vpn_client_ip
    ) {
    cluster_config_setup_config_t *cluster_config_setup_config_local_var = malloc(sizeof(cluster_config_setup_config_t));
    if (!cluster_config_setup_config_local_var) {
        return NULL;
    }
    cluster_config_setup_config_local_var->on_site = on_site;
    cluster_config_setup_config_local_var->artifacts_volume_size = artifacts_volume_size;
    cluster_config_setup_config_local_var->network_monitor_interval = network_monitor_interval;
    cluster_config_setup_config_local_var->max_network_monitor_file_size = max_network_monitor_file_size;
    cluster_config_setup_config_local_var->ca_cert_file_src = ca_cert_file_src;
    cluster_config_setup_config_local_var->local_ip = local_ip;
    cluster_config_setup_config_local_var->instance_ip_block_netmask = instance_ip_block_netmask;
    cluster_config_setup_config_local_var->instance_gateway = instance_gateway;
    cluster_config_setup_config_local_var->instance_dns_servers = instance_dns_servers;
    cluster_config_setup_config_local_var->report_interval = report_interval;
    cluster_config_setup_config_local_var->cert_key_file_data = cert_key_file_data;
    cluster_config_setup_config_local_var->default_ssid = default_ssid;
    cluster_config_setup_config_local_var->enable_experimental_devices = enable_experimental_devices;
    cluster_config_setup_config_local_var->controller_nodes = controller_nodes;
    cluster_config_setup_config_local_var->domain = domain;
    cluster_config_setup_config_local_var->interface = interface;
    cluster_config_setup_config_local_var->virtual_device_interface = virtual_device_interface;
    cluster_config_setup_config_local_var->auto_approve_trials = auto_approve_trials;
    cluster_config_setup_config_local_var->snapshot_limit = snapshot_limit;
    cluster_config_setup_config_local_var->max_download_agents_per_device = max_download_agents_per_device;
    cluster_config_setup_config_local_var->client_cert_file = client_cert_file;
    cluster_config_setup_config_local_var->docker_host_ip = docker_host_ip;
    cluster_config_setup_config_local_var->domain_name = domain_name;
    cluster_config_setup_config_local_var->vpn_client_ip = vpn_client_ip;

    cluster_config_setup_config_local_var->_library_owned = 1;
    return cluster_config_setup_config_local_var;
}

__attribute__((deprecated)) cluster_config_setup_config_t *cluster_config_setup_config_create(
    int on_site,
    double artifacts_volume_size,
    double network_monitor_interval,
    char *max_network_monitor_file_size,
    char *ca_cert_file_src,
    char *local_ip,
    char *instance_ip_block_netmask,
    char *instance_gateway,
    list_t *instance_dns_servers,
    double report_interval,
    char *cert_key_file_data,
    char *default_ssid,
    int enable_experimental_devices,
    list_t *controller_nodes,
    char *domain,
    char *interface,
    char *virtual_device_interface,
    char *auto_approve_trials,
    double snapshot_limit,
    double max_download_agents_per_device,
    char *client_cert_file,
    char *docker_host_ip,
    char *domain_name,
    char *vpn_client_ip
    ) {
    return cluster_config_setup_config_create_internal (
        on_site,
        artifacts_volume_size,
        network_monitor_interval,
        max_network_monitor_file_size,
        ca_cert_file_src,
        local_ip,
        instance_ip_block_netmask,
        instance_gateway,
        instance_dns_servers,
        report_interval,
        cert_key_file_data,
        default_ssid,
        enable_experimental_devices,
        controller_nodes,
        domain,
        interface,
        virtual_device_interface,
        auto_approve_trials,
        snapshot_limit,
        max_download_agents_per_device,
        client_cert_file,
        docker_host_ip,
        domain_name,
        vpn_client_ip
        );
}

void cluster_config_setup_config_free(cluster_config_setup_config_t *cluster_config_setup_config) {
    if(NULL == cluster_config_setup_config){
        return ;
    }
    if(cluster_config_setup_config->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cluster_config_setup_config_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cluster_config_setup_config->max_network_monitor_file_size) {
        free(cluster_config_setup_config->max_network_monitor_file_size);
        cluster_config_setup_config->max_network_monitor_file_size = NULL;
    }
    if (cluster_config_setup_config->ca_cert_file_src) {
        free(cluster_config_setup_config->ca_cert_file_src);
        cluster_config_setup_config->ca_cert_file_src = NULL;
    }
    if (cluster_config_setup_config->local_ip) {
        free(cluster_config_setup_config->local_ip);
        cluster_config_setup_config->local_ip = NULL;
    }
    if (cluster_config_setup_config->instance_ip_block_netmask) {
        free(cluster_config_setup_config->instance_ip_block_netmask);
        cluster_config_setup_config->instance_ip_block_netmask = NULL;
    }
    if (cluster_config_setup_config->instance_gateway) {
        free(cluster_config_setup_config->instance_gateway);
        cluster_config_setup_config->instance_gateway = NULL;
    }
    if (cluster_config_setup_config->instance_dns_servers) {
        list_ForEach(listEntry, cluster_config_setup_config->instance_dns_servers) {
            free(listEntry->data);
        }
        list_freeList(cluster_config_setup_config->instance_dns_servers);
        cluster_config_setup_config->instance_dns_servers = NULL;
    }
    if (cluster_config_setup_config->cert_key_file_data) {
        free(cluster_config_setup_config->cert_key_file_data);
        cluster_config_setup_config->cert_key_file_data = NULL;
    }
    if (cluster_config_setup_config->default_ssid) {
        free(cluster_config_setup_config->default_ssid);
        cluster_config_setup_config->default_ssid = NULL;
    }
    if (cluster_config_setup_config->controller_nodes) {
        list_ForEach(listEntry, cluster_config_setup_config->controller_nodes) {
            free(listEntry->data);
        }
        list_freeList(cluster_config_setup_config->controller_nodes);
        cluster_config_setup_config->controller_nodes = NULL;
    }
    if (cluster_config_setup_config->domain) {
        free(cluster_config_setup_config->domain);
        cluster_config_setup_config->domain = NULL;
    }
    if (cluster_config_setup_config->interface) {
        free(cluster_config_setup_config->interface);
        cluster_config_setup_config->interface = NULL;
    }
    if (cluster_config_setup_config->virtual_device_interface) {
        free(cluster_config_setup_config->virtual_device_interface);
        cluster_config_setup_config->virtual_device_interface = NULL;
    }
    if (cluster_config_setup_config->auto_approve_trials) {
        free(cluster_config_setup_config->auto_approve_trials);
        cluster_config_setup_config->auto_approve_trials = NULL;
    }
    if (cluster_config_setup_config->client_cert_file) {
        free(cluster_config_setup_config->client_cert_file);
        cluster_config_setup_config->client_cert_file = NULL;
    }
    if (cluster_config_setup_config->docker_host_ip) {
        free(cluster_config_setup_config->docker_host_ip);
        cluster_config_setup_config->docker_host_ip = NULL;
    }
    if (cluster_config_setup_config->domain_name) {
        free(cluster_config_setup_config->domain_name);
        cluster_config_setup_config->domain_name = NULL;
    }
    if (cluster_config_setup_config->vpn_client_ip) {
        free(cluster_config_setup_config->vpn_client_ip);
        cluster_config_setup_config->vpn_client_ip = NULL;
    }
    free(cluster_config_setup_config);
}

cJSON *cluster_config_setup_config_convertToJSON(cluster_config_setup_config_t *cluster_config_setup_config) {
    cJSON *item = cJSON_CreateObject();

    // cluster_config_setup_config->on_site
    if (!cluster_config_setup_config->on_site) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "onSite", cluster_config_setup_config->on_site) == NULL) {
    goto fail; //Bool
    }


    // cluster_config_setup_config->artifacts_volume_size
    if(cluster_config_setup_config->artifacts_volume_size) {
    if(cJSON_AddNumberToObject(item, "artifactsVolumeSize", cluster_config_setup_config->artifacts_volume_size) == NULL) {
    goto fail; //Numeric
    }
    }


    // cluster_config_setup_config->network_monitor_interval
    if (!cluster_config_setup_config->network_monitor_interval) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "networkMonitorInterval", cluster_config_setup_config->network_monitor_interval) == NULL) {
    goto fail; //Numeric
    }


    // cluster_config_setup_config->max_network_monitor_file_size
    if (!cluster_config_setup_config->max_network_monitor_file_size) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "maxNetworkMonitorFileSize", cluster_config_setup_config->max_network_monitor_file_size) == NULL) {
    goto fail; //String
    }


    // cluster_config_setup_config->ca_cert_file_src
    if (!cluster_config_setup_config->ca_cert_file_src) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "caCertFileSrc", cluster_config_setup_config->ca_cert_file_src) == NULL) {
    goto fail; //String
    }


    // cluster_config_setup_config->local_ip
    if (!cluster_config_setup_config->local_ip) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "localIp", cluster_config_setup_config->local_ip) == NULL) {
    goto fail; //String
    }


    // cluster_config_setup_config->instance_ip_block_netmask
    if (!cluster_config_setup_config->instance_ip_block_netmask) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "instanceIpBlockNetmask", cluster_config_setup_config->instance_ip_block_netmask) == NULL) {
    goto fail; //String
    }


    // cluster_config_setup_config->instance_gateway
    if (!cluster_config_setup_config->instance_gateway) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "instanceGateway", cluster_config_setup_config->instance_gateway) == NULL) {
    goto fail; //String
    }


    // cluster_config_setup_config->instance_dns_servers
    if(cluster_config_setup_config->instance_dns_servers) {
    cJSON *instance_dns_servers = cJSON_AddArrayToObject(item, "instanceDNSServers");
    if(instance_dns_servers == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *instance_dns_serversListEntry;
    list_ForEach(instance_dns_serversListEntry, cluster_config_setup_config->instance_dns_servers) {
    if(cJSON_AddStringToObject(instance_dns_servers, "", instance_dns_serversListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // cluster_config_setup_config->report_interval
    if (!cluster_config_setup_config->report_interval) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "reportInterval", cluster_config_setup_config->report_interval) == NULL) {
    goto fail; //Numeric
    }


    // cluster_config_setup_config->cert_key_file_data
    if(cluster_config_setup_config->cert_key_file_data) {
    if(cJSON_AddStringToObject(item, "certKeyFileData", cluster_config_setup_config->cert_key_file_data) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config_setup_config->default_ssid
    if(cluster_config_setup_config->default_ssid) {
    if(cJSON_AddStringToObject(item, "defaultSsid", cluster_config_setup_config->default_ssid) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config_setup_config->enable_experimental_devices
    if(cluster_config_setup_config->enable_experimental_devices) {
    if(cJSON_AddBoolToObject(item, "enableExperimentalDevices", cluster_config_setup_config->enable_experimental_devices) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_setup_config->controller_nodes
    if(cluster_config_setup_config->controller_nodes) {
    cJSON *controller_nodes = cJSON_AddArrayToObject(item, "controllerNodes");
    if(controller_nodes == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *controller_nodesListEntry;
    list_ForEach(controller_nodesListEntry, cluster_config_setup_config->controller_nodes) {
    if(cJSON_AddStringToObject(controller_nodes, "", controller_nodesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // cluster_config_setup_config->domain
    if(cluster_config_setup_config->domain) {
    if(cJSON_AddStringToObject(item, "domain", cluster_config_setup_config->domain) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config_setup_config->interface
    if (!cluster_config_setup_config->interface) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "interface", cluster_config_setup_config->interface) == NULL) {
    goto fail; //String
    }


    // cluster_config_setup_config->virtual_device_interface
    if(cluster_config_setup_config->virtual_device_interface) {
    if(cJSON_AddStringToObject(item, "virtualDeviceInterface", cluster_config_setup_config->virtual_device_interface) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config_setup_config->auto_approve_trials
    if(cluster_config_setup_config->auto_approve_trials) {
    if(cJSON_AddStringToObject(item, "autoApproveTrials", cluster_config_setup_config->auto_approve_trials) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config_setup_config->snapshot_limit
    if(cluster_config_setup_config->snapshot_limit) {
    if(cJSON_AddNumberToObject(item, "snapshotLimit", cluster_config_setup_config->snapshot_limit) == NULL) {
    goto fail; //Numeric
    }
    }


    // cluster_config_setup_config->max_download_agents_per_device
    if(cluster_config_setup_config->max_download_agents_per_device) {
    if(cJSON_AddNumberToObject(item, "maxDownloadAgentsPerDevice", cluster_config_setup_config->max_download_agents_per_device) == NULL) {
    goto fail; //Numeric
    }
    }


    // cluster_config_setup_config->client_cert_file
    if(cluster_config_setup_config->client_cert_file) {
    if(cJSON_AddStringToObject(item, "clientCertFile", cluster_config_setup_config->client_cert_file) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config_setup_config->docker_host_ip
    if(cluster_config_setup_config->docker_host_ip) {
    if(cJSON_AddStringToObject(item, "dockerHostIp", cluster_config_setup_config->docker_host_ip) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config_setup_config->domain_name
    if(cluster_config_setup_config->domain_name) {
    if(cJSON_AddStringToObject(item, "domainName", cluster_config_setup_config->domain_name) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config_setup_config->vpn_client_ip
    if(cluster_config_setup_config->vpn_client_ip) {
    if(cJSON_AddStringToObject(item, "vpnClientIP", cluster_config_setup_config->vpn_client_ip) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

cluster_config_setup_config_t *cluster_config_setup_config_parseFromJSON(cJSON *cluster_config_setup_configJSON){

    cluster_config_setup_config_t *cluster_config_setup_config_local_var = NULL;

    // define the local list for cluster_config_setup_config->instance_dns_servers
    list_t *instance_dns_serversList = NULL;

    // define the local list for cluster_config_setup_config->controller_nodes
    list_t *controller_nodesList = NULL;

    // cluster_config_setup_config->on_site
    cJSON *on_site = cJSON_GetObjectItemCaseSensitive(cluster_config_setup_configJSON, "onSite");
    if (cJSON_IsNull(on_site)) {
        on_site = NULL;
    }
    if (!on_site) {
        goto end;
    }

    
    if(!cJSON_IsBool(on_site))
    {
    goto end; //Bool
    }

    // cluster_config_setup_config->artifacts_volume_size
    cJSON *artifacts_volume_size = cJSON_GetObjectItemCaseSensitive(cluster_config_setup_configJSON, "artifactsVolumeSize");
    if (cJSON_IsNull(artifacts_volume_size)) {
        artifacts_volume_size = NULL;
    }
    if (artifacts_volume_size) { 
    if(!cJSON_IsNumber(artifacts_volume_size))
    {
    goto end; //Numeric
    }
    }

    // cluster_config_setup_config->network_monitor_interval
    cJSON *network_monitor_interval = cJSON_GetObjectItemCaseSensitive(cluster_config_setup_configJSON, "networkMonitorInterval");
    if (cJSON_IsNull(network_monitor_interval)) {
        network_monitor_interval = NULL;
    }
    if (!network_monitor_interval) {
        goto end;
    }

    
    if(!cJSON_IsNumber(network_monitor_interval))
    {
    goto end; //Numeric
    }

    // cluster_config_setup_config->max_network_monitor_file_size
    cJSON *max_network_monitor_file_size = cJSON_GetObjectItemCaseSensitive(cluster_config_setup_configJSON, "maxNetworkMonitorFileSize");
    if (cJSON_IsNull(max_network_monitor_file_size)) {
        max_network_monitor_file_size = NULL;
    }
    if (!max_network_monitor_file_size) {
        goto end;
    }

    
    if(!cJSON_IsString(max_network_monitor_file_size))
    {
    goto end; //String
    }

    // cluster_config_setup_config->ca_cert_file_src
    cJSON *ca_cert_file_src = cJSON_GetObjectItemCaseSensitive(cluster_config_setup_configJSON, "caCertFileSrc");
    if (cJSON_IsNull(ca_cert_file_src)) {
        ca_cert_file_src = NULL;
    }
    if (!ca_cert_file_src) {
        goto end;
    }

    
    if(!cJSON_IsString(ca_cert_file_src))
    {
    goto end; //String
    }

    // cluster_config_setup_config->local_ip
    cJSON *local_ip = cJSON_GetObjectItemCaseSensitive(cluster_config_setup_configJSON, "localIp");
    if (cJSON_IsNull(local_ip)) {
        local_ip = NULL;
    }
    if (!local_ip) {
        goto end;
    }

    
    if(!cJSON_IsString(local_ip))
    {
    goto end; //String
    }

    // cluster_config_setup_config->instance_ip_block_netmask
    cJSON *instance_ip_block_netmask = cJSON_GetObjectItemCaseSensitive(cluster_config_setup_configJSON, "instanceIpBlockNetmask");
    if (cJSON_IsNull(instance_ip_block_netmask)) {
        instance_ip_block_netmask = NULL;
    }
    if (!instance_ip_block_netmask) {
        goto end;
    }

    
    if(!cJSON_IsString(instance_ip_block_netmask))
    {
    goto end; //String
    }

    // cluster_config_setup_config->instance_gateway
    cJSON *instance_gateway = cJSON_GetObjectItemCaseSensitive(cluster_config_setup_configJSON, "instanceGateway");
    if (cJSON_IsNull(instance_gateway)) {
        instance_gateway = NULL;
    }
    if (!instance_gateway) {
        goto end;
    }

    
    if(!cJSON_IsString(instance_gateway))
    {
    goto end; //String
    }

    // cluster_config_setup_config->instance_dns_servers
    cJSON *instance_dns_servers = cJSON_GetObjectItemCaseSensitive(cluster_config_setup_configJSON, "instanceDNSServers");
    if (cJSON_IsNull(instance_dns_servers)) {
        instance_dns_servers = NULL;
    }
    if (instance_dns_servers) { 
    cJSON *instance_dns_servers_local = NULL;
    if(!cJSON_IsArray(instance_dns_servers)) {
        goto end;//primitive container
    }
    instance_dns_serversList = list_createList();

    cJSON_ArrayForEach(instance_dns_servers_local, instance_dns_servers)
    {
        if(!cJSON_IsString(instance_dns_servers_local))
        {
            goto end;
        }
        list_addElement(instance_dns_serversList , strdup(instance_dns_servers_local->valuestring));
    }
    }

    // cluster_config_setup_config->report_interval
    cJSON *report_interval = cJSON_GetObjectItemCaseSensitive(cluster_config_setup_configJSON, "reportInterval");
    if (cJSON_IsNull(report_interval)) {
        report_interval = NULL;
    }
    if (!report_interval) {
        goto end;
    }

    
    if(!cJSON_IsNumber(report_interval))
    {
    goto end; //Numeric
    }

    // cluster_config_setup_config->cert_key_file_data
    cJSON *cert_key_file_data = cJSON_GetObjectItemCaseSensitive(cluster_config_setup_configJSON, "certKeyFileData");
    if (cJSON_IsNull(cert_key_file_data)) {
        cert_key_file_data = NULL;
    }
    if (cert_key_file_data) { 
    if(!cJSON_IsString(cert_key_file_data) && !cJSON_IsNull(cert_key_file_data))
    {
    goto end; //String
    }
    }

    // cluster_config_setup_config->default_ssid
    cJSON *default_ssid = cJSON_GetObjectItemCaseSensitive(cluster_config_setup_configJSON, "defaultSsid");
    if (cJSON_IsNull(default_ssid)) {
        default_ssid = NULL;
    }
    if (default_ssid) { 
    if(!cJSON_IsString(default_ssid) && !cJSON_IsNull(default_ssid))
    {
    goto end; //String
    }
    }

    // cluster_config_setup_config->enable_experimental_devices
    cJSON *enable_experimental_devices = cJSON_GetObjectItemCaseSensitive(cluster_config_setup_configJSON, "enableExperimentalDevices");
    if (cJSON_IsNull(enable_experimental_devices)) {
        enable_experimental_devices = NULL;
    }
    if (enable_experimental_devices) { 
    if(!cJSON_IsBool(enable_experimental_devices))
    {
    goto end; //Bool
    }
    }

    // cluster_config_setup_config->controller_nodes
    cJSON *controller_nodes = cJSON_GetObjectItemCaseSensitive(cluster_config_setup_configJSON, "controllerNodes");
    if (cJSON_IsNull(controller_nodes)) {
        controller_nodes = NULL;
    }
    if (controller_nodes) { 
    cJSON *controller_nodes_local = NULL;
    if(!cJSON_IsArray(controller_nodes)) {
        goto end;//primitive container
    }
    controller_nodesList = list_createList();

    cJSON_ArrayForEach(controller_nodes_local, controller_nodes)
    {
        if(!cJSON_IsString(controller_nodes_local))
        {
            goto end;
        }
        list_addElement(controller_nodesList , strdup(controller_nodes_local->valuestring));
    }
    }

    // cluster_config_setup_config->domain
    cJSON *domain = cJSON_GetObjectItemCaseSensitive(cluster_config_setup_configJSON, "domain");
    if (cJSON_IsNull(domain)) {
        domain = NULL;
    }
    if (domain) { 
    if(!cJSON_IsString(domain) && !cJSON_IsNull(domain))
    {
    goto end; //String
    }
    }

    // cluster_config_setup_config->interface
    cJSON *interface = cJSON_GetObjectItemCaseSensitive(cluster_config_setup_configJSON, "interface");
    if (cJSON_IsNull(interface)) {
        interface = NULL;
    }
    if (!interface) {
        goto end;
    }

    
    if(!cJSON_IsString(interface))
    {
    goto end; //String
    }

    // cluster_config_setup_config->virtual_device_interface
    cJSON *virtual_device_interface = cJSON_GetObjectItemCaseSensitive(cluster_config_setup_configJSON, "virtualDeviceInterface");
    if (cJSON_IsNull(virtual_device_interface)) {
        virtual_device_interface = NULL;
    }
    if (virtual_device_interface) { 
    if(!cJSON_IsString(virtual_device_interface) && !cJSON_IsNull(virtual_device_interface))
    {
    goto end; //String
    }
    }

    // cluster_config_setup_config->auto_approve_trials
    cJSON *auto_approve_trials = cJSON_GetObjectItemCaseSensitive(cluster_config_setup_configJSON, "autoApproveTrials");
    if (cJSON_IsNull(auto_approve_trials)) {
        auto_approve_trials = NULL;
    }
    if (auto_approve_trials) { 
    if(!cJSON_IsString(auto_approve_trials) && !cJSON_IsNull(auto_approve_trials))
    {
    goto end; //String
    }
    }

    // cluster_config_setup_config->snapshot_limit
    cJSON *snapshot_limit = cJSON_GetObjectItemCaseSensitive(cluster_config_setup_configJSON, "snapshotLimit");
    if (cJSON_IsNull(snapshot_limit)) {
        snapshot_limit = NULL;
    }
    if (snapshot_limit) { 
    if(!cJSON_IsNumber(snapshot_limit))
    {
    goto end; //Numeric
    }
    }

    // cluster_config_setup_config->max_download_agents_per_device
    cJSON *max_download_agents_per_device = cJSON_GetObjectItemCaseSensitive(cluster_config_setup_configJSON, "maxDownloadAgentsPerDevice");
    if (cJSON_IsNull(max_download_agents_per_device)) {
        max_download_agents_per_device = NULL;
    }
    if (max_download_agents_per_device) { 
    if(!cJSON_IsNumber(max_download_agents_per_device))
    {
    goto end; //Numeric
    }
    }

    // cluster_config_setup_config->client_cert_file
    cJSON *client_cert_file = cJSON_GetObjectItemCaseSensitive(cluster_config_setup_configJSON, "clientCertFile");
    if (cJSON_IsNull(client_cert_file)) {
        client_cert_file = NULL;
    }
    if (client_cert_file) { 
    if(!cJSON_IsString(client_cert_file) && !cJSON_IsNull(client_cert_file))
    {
    goto end; //String
    }
    }

    // cluster_config_setup_config->docker_host_ip
    cJSON *docker_host_ip = cJSON_GetObjectItemCaseSensitive(cluster_config_setup_configJSON, "dockerHostIp");
    if (cJSON_IsNull(docker_host_ip)) {
        docker_host_ip = NULL;
    }
    if (docker_host_ip) { 
    if(!cJSON_IsString(docker_host_ip) && !cJSON_IsNull(docker_host_ip))
    {
    goto end; //String
    }
    }

    // cluster_config_setup_config->domain_name
    cJSON *domain_name = cJSON_GetObjectItemCaseSensitive(cluster_config_setup_configJSON, "domainName");
    if (cJSON_IsNull(domain_name)) {
        domain_name = NULL;
    }
    if (domain_name) { 
    if(!cJSON_IsString(domain_name) && !cJSON_IsNull(domain_name))
    {
    goto end; //String
    }
    }

    // cluster_config_setup_config->vpn_client_ip
    cJSON *vpn_client_ip = cJSON_GetObjectItemCaseSensitive(cluster_config_setup_configJSON, "vpnClientIP");
    if (cJSON_IsNull(vpn_client_ip)) {
        vpn_client_ip = NULL;
    }
    if (vpn_client_ip) { 
    if(!cJSON_IsString(vpn_client_ip) && !cJSON_IsNull(vpn_client_ip))
    {
    goto end; //String
    }
    }


    cluster_config_setup_config_local_var = cluster_config_setup_config_create_internal (
        on_site->valueint,
        artifacts_volume_size ? artifacts_volume_size->valuedouble : 0,
        network_monitor_interval->valuedouble,
        strdup(max_network_monitor_file_size->valuestring),
        strdup(ca_cert_file_src->valuestring),
        strdup(local_ip->valuestring),
        strdup(instance_ip_block_netmask->valuestring),
        strdup(instance_gateway->valuestring),
        instance_dns_servers ? instance_dns_serversList : NULL,
        report_interval->valuedouble,
        cert_key_file_data && !cJSON_IsNull(cert_key_file_data) ? strdup(cert_key_file_data->valuestring) : NULL,
        default_ssid && !cJSON_IsNull(default_ssid) ? strdup(default_ssid->valuestring) : NULL,
        enable_experimental_devices ? enable_experimental_devices->valueint : 0,
        controller_nodes ? controller_nodesList : NULL,
        domain && !cJSON_IsNull(domain) ? strdup(domain->valuestring) : NULL,
        strdup(interface->valuestring),
        virtual_device_interface && !cJSON_IsNull(virtual_device_interface) ? strdup(virtual_device_interface->valuestring) : NULL,
        auto_approve_trials && !cJSON_IsNull(auto_approve_trials) ? strdup(auto_approve_trials->valuestring) : NULL,
        snapshot_limit ? snapshot_limit->valuedouble : 0,
        max_download_agents_per_device ? max_download_agents_per_device->valuedouble : 0,
        client_cert_file && !cJSON_IsNull(client_cert_file) ? strdup(client_cert_file->valuestring) : NULL,
        docker_host_ip && !cJSON_IsNull(docker_host_ip) ? strdup(docker_host_ip->valuestring) : NULL,
        domain_name && !cJSON_IsNull(domain_name) ? strdup(domain_name->valuestring) : NULL,
        vpn_client_ip && !cJSON_IsNull(vpn_client_ip) ? strdup(vpn_client_ip->valuestring) : NULL
        );

    return cluster_config_setup_config_local_var;
end:
    if (instance_dns_serversList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, instance_dns_serversList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(instance_dns_serversList);
        instance_dns_serversList = NULL;
    }
    if (controller_nodesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, controller_nodesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(controller_nodesList);
        controller_nodesList = NULL;
    }
    return NULL;

}
