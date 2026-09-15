/*
 * cluster_config.h
 *
 * 
 */

#ifndef _cluster_config_H_
#define _cluster_config_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cluster_config_t cluster_config_t;

#include "any_type.h"
#include "cluster_config_coordinator_config.h"
#include "cluster_config_coordinator_config_auth_providers_inner.h"
#include "cluster_config_firmware_service_config.h"
#include "cluster_config_ipsw_filters_inner.h"
#include "cluster_config_maintenance.h"
#include "cluster_config_net_mon_ca.h"
#include "cluster_config_node_specific_config.h"
#include "cluster_config_package_config.h"
#include "cluster_config_setup_config.h"
#include "cluster_config_stripe.h"
#include "object.h"

// Enum NETWORKTYPE for cluster_config

typedef enum  { corellium_api_cluster_config_NETWORKTYPE_NULL = 0, corellium_api_cluster_config_NETWORKTYPE_bridged, corellium_api_cluster_config_NETWORKTYPE_nat, corellium_api_cluster_config_NETWORKTYPE_routed } corellium_api_cluster_config_NETWORKTYPE_e;

char* cluster_config_network_type_ToString(corellium_api_cluster_config_NETWORKTYPE_e network_type);

corellium_api_cluster_config_NETWORKTYPE_e cluster_config_network_type_FromString(char* network_type);



typedef struct cluster_config_t {
    list_t *last_config_keys; //primitive container
    char *local_ip; // string
    char *ip_block_netmask; // string
    char *instance_gateway; // string
    list_t *instance_dns_servers; //primitive container
    char *coordinator; // string
    int on_site; //boolean
    char *cloud_provider; // string
    list_t *network_types; //primitive container
    corellium_api_cluster_config_NETWORKTYPE_e network_type; //enum
    int show_domain_settings; //boolean
    char *version; // string
    char *ipsw_url; // string
    char *coreimg_url; // string
    char *fw_service_url; // string
    char *service_password; // string
    int invalid_build; //boolean
    int sep_sim; //boolean
    int installer_available; //boolean
    struct cluster_config_stripe_t *stripe; //model
    char *intercom_id; // string
    char *aux_webhook; // string
    char *gtm_id; // string
    char *zapier_feedback_webhook; // string
    char *zapier_bugs_webhook; // string
    char *billing_backend; // string
    struct cluster_config_maintenance_t *maintenance; //model
    char *cloud_domain; // string
    int development; //boolean
    char *billing_domain; // string
    char *app_domain; // string
    int enable_firmware_image_upload; //boolean
    struct cluster_config_net_mon_ca_t *net_mon_ca; //model
    double snapshot_limit; //numeric
    double max_kernel_size; //numeric
    double max_ramdisk_size; //numeric
    int charm_sdk; //boolean
    char *sentry_url; // string
    int remote_gpu; //boolean
    int rate_limit; //boolean
    char *cert_file_data; // string
    char *ca_cert_file_src; // string
    int vstrm_on_compute_nodes; //boolean
    object_t *charm; //object
    char *c3po_path_prefix; // string
    char *branding; // string
    char *open_g_apps_binary; // string
    int airgapped; //boolean
    double node_stale_timeout; //numeric
    double report_interval; //numeric
    struct cluster_config_coordinator_config_t *coordinator_config; //model
    struct cluster_config_setup_config_t *setup_config; //model
    struct cluster_config_node_specific_config_t *node_specific_config; //model
    struct cluster_config_package_config_t *package_config; //model
    double monitor_interval; //numeric
    int csp; //boolean
    int cdk; //boolean
    list_t *charm_extension_paths; //primitive container
    char *firmware_cache; // string
    char *vstrm; // string
    char *console; // string
    int fetch_firmware_assets; //boolean
    int cluster_firmware_assets; //boolean
    list_t *auth_providers; //nonprimitive container
    char *domain; // string
    char *service_domain; // string
    char *service_user; // string
    double domain_image_upload_quota; //numeric
    list_t *ipsw_filters; //nonprimitive container
    struct cluster_config_firmware_service_config_t *firmware_service_config; //model

    int _library_owned; // Is the library responsible for freeing this object?
} cluster_config_t;

__attribute__((deprecated)) cluster_config_t *cluster_config_create(
    list_t *last_config_keys,
    char *local_ip,
    char *ip_block_netmask,
    char *instance_gateway,
    list_t *instance_dns_servers,
    char *coordinator,
    int on_site,
    char *cloud_provider,
    list_t *network_types,
    corellium_api_cluster_config_NETWORKTYPE_e network_type,
    int show_domain_settings,
    char *version,
    char *ipsw_url,
    char *coreimg_url,
    char *fw_service_url,
    char *service_password,
    int invalid_build,
    int sep_sim,
    int installer_available,
    cluster_config_stripe_t *stripe,
    char *intercom_id,
    char *aux_webhook,
    char *gtm_id,
    char *zapier_feedback_webhook,
    char *zapier_bugs_webhook,
    char *billing_backend,
    cluster_config_maintenance_t *maintenance,
    char *cloud_domain,
    int development,
    char *billing_domain,
    char *app_domain,
    int enable_firmware_image_upload,
    cluster_config_net_mon_ca_t *net_mon_ca,
    double snapshot_limit,
    double max_kernel_size,
    double max_ramdisk_size,
    int charm_sdk,
    char *sentry_url,
    int remote_gpu,
    int rate_limit,
    char *cert_file_data,
    char *ca_cert_file_src,
    int vstrm_on_compute_nodes,
    object_t *charm,
    char *c3po_path_prefix,
    char *branding,
    char *open_g_apps_binary,
    int airgapped,
    double node_stale_timeout,
    double report_interval,
    cluster_config_coordinator_config_t *coordinator_config,
    cluster_config_setup_config_t *setup_config,
    cluster_config_node_specific_config_t *node_specific_config,
    cluster_config_package_config_t *package_config,
    double monitor_interval,
    int csp,
    int cdk,
    list_t *charm_extension_paths,
    char *firmware_cache,
    char *vstrm,
    char *console,
    int fetch_firmware_assets,
    int cluster_firmware_assets,
    list_t *auth_providers,
    char *domain,
    char *service_domain,
    char *service_user,
    double domain_image_upload_quota,
    list_t *ipsw_filters,
    cluster_config_firmware_service_config_t *firmware_service_config
);

void cluster_config_free(cluster_config_t *cluster_config);

cluster_config_t *cluster_config_parseFromJSON(cJSON *cluster_configJSON);

cJSON *cluster_config_convertToJSON(cluster_config_t *cluster_config);

#endif /* _cluster_config_H_ */

