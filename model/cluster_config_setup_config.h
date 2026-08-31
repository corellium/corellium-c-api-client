/*
 * cluster_config_setup_config.h
 *
 * 
 */

#ifndef _cluster_config_setup_config_H_
#define _cluster_config_setup_config_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cluster_config_setup_config_t cluster_config_setup_config_t;




typedef struct cluster_config_setup_config_t {
    int on_site; //boolean
    double artifacts_volume_size; //numeric
    double network_monitor_interval; //numeric
    char *max_network_monitor_file_size; // string
    char *ca_cert_file_src; // string
    char *local_ip; // string
    char *instance_ip_block_netmask; // string
    char *instance_gateway; // string
    list_t *instance_dns_servers; //primitive container
    double report_interval; //numeric
    char *cert_key_file_data; // string
    char *default_ssid; // string
    int enable_experimental_devices; //boolean
    list_t *controller_nodes; //primitive container
    char *domain; // string
    char *interface; // string
    char *virtual_device_interface; // string
    char *auto_approve_trials; // string
    double snapshot_limit; //numeric
    double max_download_agents_per_device; //numeric
    char *client_cert_file; // string
    char *docker_host_ip; // string
    char *domain_name; // string
    char *vpn_client_ip; // string

    int _library_owned; // Is the library responsible for freeing this object?
} cluster_config_setup_config_t;

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
);

void cluster_config_setup_config_free(cluster_config_setup_config_t *cluster_config_setup_config);

cluster_config_setup_config_t *cluster_config_setup_config_parseFromJSON(cJSON *cluster_config_setup_configJSON);

cJSON *cluster_config_setup_config_convertToJSON(cluster_config_setup_config_t *cluster_config_setup_config);

#endif /* _cluster_config_setup_config_H_ */

