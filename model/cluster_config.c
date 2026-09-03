#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cluster_config.h"


char* cluster_config_network_type_ToString(corellium_api_cluster_config_NETWORKTYPE_e network_type) {
    char* network_typeArray[] =  { "NULL", "bridged", "nat", "routed" };
    return network_typeArray[network_type];
}

corellium_api_cluster_config_NETWORKTYPE_e cluster_config_network_type_FromString(char* network_type){
    int stringToReturn = 0;
    char *network_typeArray[] =  { "NULL", "bridged", "nat", "routed" };
    size_t sizeofArray = sizeof(network_typeArray) / sizeof(network_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(network_type, network_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static cluster_config_t *cluster_config_create_internal(
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
    cluster_config_firmware_service_config_t *firmware_service_config,
    cluster_config_ai_tools_config_t *ai_tools_config
    ) {
    cluster_config_t *cluster_config_local_var = malloc(sizeof(cluster_config_t));
    if (!cluster_config_local_var) {
        return NULL;
    }
    cluster_config_local_var->last_config_keys = last_config_keys;
    cluster_config_local_var->local_ip = local_ip;
    cluster_config_local_var->ip_block_netmask = ip_block_netmask;
    cluster_config_local_var->instance_gateway = instance_gateway;
    cluster_config_local_var->instance_dns_servers = instance_dns_servers;
    cluster_config_local_var->coordinator = coordinator;
    cluster_config_local_var->on_site = on_site;
    cluster_config_local_var->cloud_provider = cloud_provider;
    cluster_config_local_var->network_types = network_types;
    cluster_config_local_var->network_type = network_type;
    cluster_config_local_var->show_domain_settings = show_domain_settings;
    cluster_config_local_var->version = version;
    cluster_config_local_var->ipsw_url = ipsw_url;
    cluster_config_local_var->coreimg_url = coreimg_url;
    cluster_config_local_var->fw_service_url = fw_service_url;
    cluster_config_local_var->service_password = service_password;
    cluster_config_local_var->invalid_build = invalid_build;
    cluster_config_local_var->sep_sim = sep_sim;
    cluster_config_local_var->installer_available = installer_available;
    cluster_config_local_var->stripe = stripe;
    cluster_config_local_var->intercom_id = intercom_id;
    cluster_config_local_var->aux_webhook = aux_webhook;
    cluster_config_local_var->gtm_id = gtm_id;
    cluster_config_local_var->zapier_feedback_webhook = zapier_feedback_webhook;
    cluster_config_local_var->zapier_bugs_webhook = zapier_bugs_webhook;
    cluster_config_local_var->billing_backend = billing_backend;
    cluster_config_local_var->maintenance = maintenance;
    cluster_config_local_var->cloud_domain = cloud_domain;
    cluster_config_local_var->development = development;
    cluster_config_local_var->billing_domain = billing_domain;
    cluster_config_local_var->app_domain = app_domain;
    cluster_config_local_var->enable_firmware_image_upload = enable_firmware_image_upload;
    cluster_config_local_var->net_mon_ca = net_mon_ca;
    cluster_config_local_var->snapshot_limit = snapshot_limit;
    cluster_config_local_var->max_kernel_size = max_kernel_size;
    cluster_config_local_var->max_ramdisk_size = max_ramdisk_size;
    cluster_config_local_var->charm_sdk = charm_sdk;
    cluster_config_local_var->sentry_url = sentry_url;
    cluster_config_local_var->remote_gpu = remote_gpu;
    cluster_config_local_var->rate_limit = rate_limit;
    cluster_config_local_var->cert_file_data = cert_file_data;
    cluster_config_local_var->ca_cert_file_src = ca_cert_file_src;
    cluster_config_local_var->vstrm_on_compute_nodes = vstrm_on_compute_nodes;
    cluster_config_local_var->charm = charm;
    cluster_config_local_var->c3po_path_prefix = c3po_path_prefix;
    cluster_config_local_var->branding = branding;
    cluster_config_local_var->open_g_apps_binary = open_g_apps_binary;
    cluster_config_local_var->airgapped = airgapped;
    cluster_config_local_var->node_stale_timeout = node_stale_timeout;
    cluster_config_local_var->report_interval = report_interval;
    cluster_config_local_var->coordinator_config = coordinator_config;
    cluster_config_local_var->setup_config = setup_config;
    cluster_config_local_var->node_specific_config = node_specific_config;
    cluster_config_local_var->package_config = package_config;
    cluster_config_local_var->monitor_interval = monitor_interval;
    cluster_config_local_var->csp = csp;
    cluster_config_local_var->cdk = cdk;
    cluster_config_local_var->charm_extension_paths = charm_extension_paths;
    cluster_config_local_var->firmware_cache = firmware_cache;
    cluster_config_local_var->vstrm = vstrm;
    cluster_config_local_var->console = console;
    cluster_config_local_var->fetch_firmware_assets = fetch_firmware_assets;
    cluster_config_local_var->cluster_firmware_assets = cluster_firmware_assets;
    cluster_config_local_var->auth_providers = auth_providers;
    cluster_config_local_var->domain = domain;
    cluster_config_local_var->service_domain = service_domain;
    cluster_config_local_var->service_user = service_user;
    cluster_config_local_var->domain_image_upload_quota = domain_image_upload_quota;
    cluster_config_local_var->ipsw_filters = ipsw_filters;
    cluster_config_local_var->firmware_service_config = firmware_service_config;
    cluster_config_local_var->ai_tools_config = ai_tools_config;

    cluster_config_local_var->_library_owned = 1;
    return cluster_config_local_var;
}

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
    cluster_config_firmware_service_config_t *firmware_service_config,
    cluster_config_ai_tools_config_t *ai_tools_config
    ) {
    return cluster_config_create_internal (
        last_config_keys,
        local_ip,
        ip_block_netmask,
        instance_gateway,
        instance_dns_servers,
        coordinator,
        on_site,
        cloud_provider,
        network_types,
        network_type,
        show_domain_settings,
        version,
        ipsw_url,
        coreimg_url,
        fw_service_url,
        service_password,
        invalid_build,
        sep_sim,
        installer_available,
        stripe,
        intercom_id,
        aux_webhook,
        gtm_id,
        zapier_feedback_webhook,
        zapier_bugs_webhook,
        billing_backend,
        maintenance,
        cloud_domain,
        development,
        billing_domain,
        app_domain,
        enable_firmware_image_upload,
        net_mon_ca,
        snapshot_limit,
        max_kernel_size,
        max_ramdisk_size,
        charm_sdk,
        sentry_url,
        remote_gpu,
        rate_limit,
        cert_file_data,
        ca_cert_file_src,
        vstrm_on_compute_nodes,
        charm,
        c3po_path_prefix,
        branding,
        open_g_apps_binary,
        airgapped,
        node_stale_timeout,
        report_interval,
        coordinator_config,
        setup_config,
        node_specific_config,
        package_config,
        monitor_interval,
        csp,
        cdk,
        charm_extension_paths,
        firmware_cache,
        vstrm,
        console,
        fetch_firmware_assets,
        cluster_firmware_assets,
        auth_providers,
        domain,
        service_domain,
        service_user,
        domain_image_upload_quota,
        ipsw_filters,
        firmware_service_config,
        ai_tools_config
        );
}

void cluster_config_free(cluster_config_t *cluster_config) {
    if(NULL == cluster_config){
        return ;
    }
    if(cluster_config->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cluster_config_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cluster_config->last_config_keys) {
        list_ForEach(listEntry, cluster_config->last_config_keys) {
            free(listEntry->data);
        }
        list_freeList(cluster_config->last_config_keys);
        cluster_config->last_config_keys = NULL;
    }
    if (cluster_config->local_ip) {
        free(cluster_config->local_ip);
        cluster_config->local_ip = NULL;
    }
    if (cluster_config->ip_block_netmask) {
        free(cluster_config->ip_block_netmask);
        cluster_config->ip_block_netmask = NULL;
    }
    if (cluster_config->instance_gateway) {
        free(cluster_config->instance_gateway);
        cluster_config->instance_gateway = NULL;
    }
    if (cluster_config->instance_dns_servers) {
        list_ForEach(listEntry, cluster_config->instance_dns_servers) {
            free(listEntry->data);
        }
        list_freeList(cluster_config->instance_dns_servers);
        cluster_config->instance_dns_servers = NULL;
    }
    if (cluster_config->coordinator) {
        free(cluster_config->coordinator);
        cluster_config->coordinator = NULL;
    }
    if (cluster_config->cloud_provider) {
        free(cluster_config->cloud_provider);
        cluster_config->cloud_provider = NULL;
    }
    if (cluster_config->network_types) {
        list_ForEach(listEntry, cluster_config->network_types) {
            free(listEntry->data);
        }
        list_freeList(cluster_config->network_types);
        cluster_config->network_types = NULL;
    }
    if (cluster_config->version) {
        free(cluster_config->version);
        cluster_config->version = NULL;
    }
    if (cluster_config->ipsw_url) {
        free(cluster_config->ipsw_url);
        cluster_config->ipsw_url = NULL;
    }
    if (cluster_config->coreimg_url) {
        free(cluster_config->coreimg_url);
        cluster_config->coreimg_url = NULL;
    }
    if (cluster_config->fw_service_url) {
        free(cluster_config->fw_service_url);
        cluster_config->fw_service_url = NULL;
    }
    if (cluster_config->service_password) {
        free(cluster_config->service_password);
        cluster_config->service_password = NULL;
    }
    if (cluster_config->stripe) {
        cluster_config_stripe_free(cluster_config->stripe);
        cluster_config->stripe = NULL;
    }
    if (cluster_config->intercom_id) {
        free(cluster_config->intercom_id);
        cluster_config->intercom_id = NULL;
    }
    if (cluster_config->aux_webhook) {
        free(cluster_config->aux_webhook);
        cluster_config->aux_webhook = NULL;
    }
    if (cluster_config->gtm_id) {
        free(cluster_config->gtm_id);
        cluster_config->gtm_id = NULL;
    }
    if (cluster_config->zapier_feedback_webhook) {
        free(cluster_config->zapier_feedback_webhook);
        cluster_config->zapier_feedback_webhook = NULL;
    }
    if (cluster_config->zapier_bugs_webhook) {
        free(cluster_config->zapier_bugs_webhook);
        cluster_config->zapier_bugs_webhook = NULL;
    }
    if (cluster_config->billing_backend) {
        free(cluster_config->billing_backend);
        cluster_config->billing_backend = NULL;
    }
    if (cluster_config->maintenance) {
        cluster_config_maintenance_free(cluster_config->maintenance);
        cluster_config->maintenance = NULL;
    }
    if (cluster_config->cloud_domain) {
        free(cluster_config->cloud_domain);
        cluster_config->cloud_domain = NULL;
    }
    if (cluster_config->billing_domain) {
        free(cluster_config->billing_domain);
        cluster_config->billing_domain = NULL;
    }
    if (cluster_config->app_domain) {
        free(cluster_config->app_domain);
        cluster_config->app_domain = NULL;
    }
    if (cluster_config->net_mon_ca) {
        cluster_config_net_mon_ca_free(cluster_config->net_mon_ca);
        cluster_config->net_mon_ca = NULL;
    }
    if (cluster_config->sentry_url) {
        free(cluster_config->sentry_url);
        cluster_config->sentry_url = NULL;
    }
    if (cluster_config->cert_file_data) {
        free(cluster_config->cert_file_data);
        cluster_config->cert_file_data = NULL;
    }
    if (cluster_config->ca_cert_file_src) {
        free(cluster_config->ca_cert_file_src);
        cluster_config->ca_cert_file_src = NULL;
    }
    if (cluster_config->charm) {
        object_free(cluster_config->charm);
        cluster_config->charm = NULL;
    }
    if (cluster_config->c3po_path_prefix) {
        free(cluster_config->c3po_path_prefix);
        cluster_config->c3po_path_prefix = NULL;
    }
    if (cluster_config->branding) {
        free(cluster_config->branding);
        cluster_config->branding = NULL;
    }
    if (cluster_config->open_g_apps_binary) {
        free(cluster_config->open_g_apps_binary);
        cluster_config->open_g_apps_binary = NULL;
    }
    if (cluster_config->coordinator_config) {
        cluster_config_coordinator_config_free(cluster_config->coordinator_config);
        cluster_config->coordinator_config = NULL;
    }
    if (cluster_config->setup_config) {
        cluster_config_setup_config_free(cluster_config->setup_config);
        cluster_config->setup_config = NULL;
    }
    if (cluster_config->node_specific_config) {
        cluster_config_node_specific_config_free(cluster_config->node_specific_config);
        cluster_config->node_specific_config = NULL;
    }
    if (cluster_config->package_config) {
        cluster_config_package_config_free(cluster_config->package_config);
        cluster_config->package_config = NULL;
    }
    if (cluster_config->charm_extension_paths) {
        list_ForEach(listEntry, cluster_config->charm_extension_paths) {
            free(listEntry->data);
        }
        list_freeList(cluster_config->charm_extension_paths);
        cluster_config->charm_extension_paths = NULL;
    }
    if (cluster_config->firmware_cache) {
        free(cluster_config->firmware_cache);
        cluster_config->firmware_cache = NULL;
    }
    if (cluster_config->vstrm) {
        free(cluster_config->vstrm);
        cluster_config->vstrm = NULL;
    }
    if (cluster_config->console) {
        free(cluster_config->console);
        cluster_config->console = NULL;
    }
    if (cluster_config->auth_providers) {
        list_ForEach(listEntry, cluster_config->auth_providers) {
            cluster_config_coordinator_config_auth_providers_inner_free(listEntry->data);
        }
        list_freeList(cluster_config->auth_providers);
        cluster_config->auth_providers = NULL;
    }
    if (cluster_config->domain) {
        free(cluster_config->domain);
        cluster_config->domain = NULL;
    }
    if (cluster_config->service_domain) {
        free(cluster_config->service_domain);
        cluster_config->service_domain = NULL;
    }
    if (cluster_config->service_user) {
        free(cluster_config->service_user);
        cluster_config->service_user = NULL;
    }
    if (cluster_config->ipsw_filters) {
        list_ForEach(listEntry, cluster_config->ipsw_filters) {
            cluster_config_ipsw_filters_inner_free(listEntry->data);
        }
        list_freeList(cluster_config->ipsw_filters);
        cluster_config->ipsw_filters = NULL;
    }
    if (cluster_config->firmware_service_config) {
        cluster_config_firmware_service_config_free(cluster_config->firmware_service_config);
        cluster_config->firmware_service_config = NULL;
    }
    if (cluster_config->ai_tools_config) {
        cluster_config_ai_tools_config_free(cluster_config->ai_tools_config);
        cluster_config->ai_tools_config = NULL;
    }
    free(cluster_config);
}

cJSON *cluster_config_convertToJSON(cluster_config_t *cluster_config) {
    cJSON *item = cJSON_CreateObject();

    // cluster_config->last_config_keys
    if (!cluster_config->last_config_keys) {
        goto fail;
    }
    cJSON *last_config_keys = cJSON_AddArrayToObject(item, "lastConfigKeys");
    if(last_config_keys == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *last_config_keysListEntry;
    list_ForEach(last_config_keysListEntry, cluster_config->last_config_keys) {
    if(cJSON_AddStringToObject(last_config_keys, "", last_config_keysListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // cluster_config->local_ip
    if (!cluster_config->local_ip) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "localIp", cluster_config->local_ip) == NULL) {
    goto fail; //String
    }


    // cluster_config->ip_block_netmask
    if (!cluster_config->ip_block_netmask) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "ipBlockNetmask", cluster_config->ip_block_netmask) == NULL) {
    goto fail; //String
    }


    // cluster_config->instance_gateway
    if (!cluster_config->instance_gateway) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "instanceGateway", cluster_config->instance_gateway) == NULL) {
    goto fail; //String
    }


    // cluster_config->instance_dns_servers
    if(cluster_config->instance_dns_servers) {
    cJSON *instance_dns_servers = cJSON_AddArrayToObject(item, "instanceDNSServers");
    if(instance_dns_servers == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *instance_dns_serversListEntry;
    list_ForEach(instance_dns_serversListEntry, cluster_config->instance_dns_servers) {
    if(cJSON_AddStringToObject(instance_dns_servers, "", instance_dns_serversListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // cluster_config->coordinator
    if(cluster_config->coordinator) {
    if(cJSON_AddStringToObject(item, "coordinator", cluster_config->coordinator) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config->on_site
    if(cluster_config->on_site) {
    if(cJSON_AddBoolToObject(item, "onSite", cluster_config->on_site) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config->cloud_provider
    if(cluster_config->cloud_provider) {
    if(cJSON_AddStringToObject(item, "cloudProvider", cluster_config->cloud_provider) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config->network_types
    if (!cluster_config->network_types) {
        goto fail;
    }
    cJSON *network_types = cJSON_AddArrayToObject(item, "networkTypes");
    if(network_types == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *network_typesListEntry;
    list_ForEach(network_typesListEntry, cluster_config->network_types) {
    if(cJSON_AddStringToObject(network_types, "", network_typesListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // cluster_config->network_type
    if(cluster_config->network_type != corellium_api_cluster_config_NETWORKTYPE_NULL) {
    if(cJSON_AddStringToObject(item, "networkType", cluster_config_network_type_ToString(cluster_config->network_type)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // cluster_config->show_domain_settings
    if(cluster_config->show_domain_settings) {
    if(cJSON_AddBoolToObject(item, "showDomainSettings", cluster_config->show_domain_settings) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config->version
    if(cluster_config->version) {
    if(cJSON_AddStringToObject(item, "version", cluster_config->version) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config->ipsw_url
    if(cluster_config->ipsw_url) {
    if(cJSON_AddStringToObject(item, "ipswUrl", cluster_config->ipsw_url) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config->coreimg_url
    if(cluster_config->coreimg_url) {
    if(cJSON_AddStringToObject(item, "coreimgUrl", cluster_config->coreimg_url) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config->fw_service_url
    if(cluster_config->fw_service_url) {
    if(cJSON_AddStringToObject(item, "fwServiceUrl", cluster_config->fw_service_url) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config->service_password
    if(cluster_config->service_password) {
    if(cJSON_AddStringToObject(item, "servicePassword", cluster_config->service_password) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config->invalid_build
    if(cluster_config->invalid_build) {
    if(cJSON_AddBoolToObject(item, "invalidBuild", cluster_config->invalid_build) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config->sep_sim
    if(cluster_config->sep_sim) {
    if(cJSON_AddBoolToObject(item, "sepSim", cluster_config->sep_sim) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config->installer_available
    if(cluster_config->installer_available) {
    if(cJSON_AddBoolToObject(item, "installerAvailable", cluster_config->installer_available) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config->stripe
    if(cluster_config->stripe) {
    cJSON *stripe_local_JSON = cluster_config_stripe_convertToJSON(cluster_config->stripe);
    if(stripe_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "stripe", stripe_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // cluster_config->intercom_id
    if(cluster_config->intercom_id) {
    if(cJSON_AddStringToObject(item, "intercomId", cluster_config->intercom_id) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config->aux_webhook
    if(cluster_config->aux_webhook) {
    if(cJSON_AddStringToObject(item, "auxWebhook", cluster_config->aux_webhook) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config->gtm_id
    if(cluster_config->gtm_id) {
    if(cJSON_AddStringToObject(item, "gtmId", cluster_config->gtm_id) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config->zapier_feedback_webhook
    if(cluster_config->zapier_feedback_webhook) {
    if(cJSON_AddStringToObject(item, "zapierFeedbackWebhook", cluster_config->zapier_feedback_webhook) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config->zapier_bugs_webhook
    if(cluster_config->zapier_bugs_webhook) {
    if(cJSON_AddStringToObject(item, "zapierBugsWebhook", cluster_config->zapier_bugs_webhook) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config->billing_backend
    if(cluster_config->billing_backend) {
    if(cJSON_AddStringToObject(item, "billingBackend", cluster_config->billing_backend) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config->maintenance
    if(cluster_config->maintenance) {
    cJSON *maintenance_local_JSON = cluster_config_maintenance_convertToJSON(cluster_config->maintenance);
    if(maintenance_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "maintenance", maintenance_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // cluster_config->cloud_domain
    if(cluster_config->cloud_domain) {
    if(cJSON_AddStringToObject(item, "cloudDomain", cluster_config->cloud_domain) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config->development
    if(cluster_config->development) {
    if(cJSON_AddBoolToObject(item, "development", cluster_config->development) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config->billing_domain
    if(cluster_config->billing_domain) {
    if(cJSON_AddStringToObject(item, "billingDomain", cluster_config->billing_domain) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config->app_domain
    if(cluster_config->app_domain) {
    if(cJSON_AddStringToObject(item, "appDomain", cluster_config->app_domain) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config->enable_firmware_image_upload
    if(cluster_config->enable_firmware_image_upload) {
    if(cJSON_AddBoolToObject(item, "enableFirmwareImageUpload", cluster_config->enable_firmware_image_upload) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config->net_mon_ca
    if(cluster_config->net_mon_ca) {
    cJSON *net_mon_ca_local_JSON = cluster_config_net_mon_ca_convertToJSON(cluster_config->net_mon_ca);
    if(net_mon_ca_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "netMonCA", net_mon_ca_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // cluster_config->snapshot_limit
    if(cluster_config->snapshot_limit) {
    if(cJSON_AddNumberToObject(item, "snapshotLimit", cluster_config->snapshot_limit) == NULL) {
    goto fail; //Numeric
    }
    }


    // cluster_config->max_kernel_size
    if (!cluster_config->max_kernel_size) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "maxKernelSize", cluster_config->max_kernel_size) == NULL) {
    goto fail; //Numeric
    }


    // cluster_config->max_ramdisk_size
    if (!cluster_config->max_ramdisk_size) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "maxRamdiskSize", cluster_config->max_ramdisk_size) == NULL) {
    goto fail; //Numeric
    }


    // cluster_config->charm_sdk
    if(cluster_config->charm_sdk) {
    if(cJSON_AddBoolToObject(item, "charmSDK", cluster_config->charm_sdk) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config->sentry_url
    if(cluster_config->sentry_url) {
    if(cJSON_AddStringToObject(item, "sentryUrl", cluster_config->sentry_url) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config->remote_gpu
    if(cluster_config->remote_gpu) {
    if(cJSON_AddBoolToObject(item, "remoteGpu", cluster_config->remote_gpu) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config->rate_limit
    if(cluster_config->rate_limit) {
    if(cJSON_AddBoolToObject(item, "rateLimit", cluster_config->rate_limit) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config->cert_file_data
    if(cluster_config->cert_file_data) {
    if(cJSON_AddStringToObject(item, "certFileData", cluster_config->cert_file_data) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config->ca_cert_file_src
    if (!cluster_config->ca_cert_file_src) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "caCertFileSrc", cluster_config->ca_cert_file_src) == NULL) {
    goto fail; //String
    }


    // cluster_config->vstrm_on_compute_nodes
    if(cluster_config->vstrm_on_compute_nodes) {
    if(cJSON_AddBoolToObject(item, "vstrmOnComputeNodes", cluster_config->vstrm_on_compute_nodes) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config->charm
    if(cluster_config->charm) {
    cJSON *charm_object = object_convertToJSON(cluster_config->charm);
    if(charm_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "charm", charm_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // cluster_config->c3po_path_prefix
    if(cluster_config->c3po_path_prefix) {
    if(cJSON_AddStringToObject(item, "c3poPathPrefix", cluster_config->c3po_path_prefix) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config->branding
    if (!cluster_config->branding) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "branding", cluster_config->branding) == NULL) {
    goto fail; //String
    }


    // cluster_config->open_g_apps_binary
    if (!cluster_config->open_g_apps_binary) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "openGAppsBinary", cluster_config->open_g_apps_binary) == NULL) {
    goto fail; //String
    }


    // cluster_config->airgapped
    if (!cluster_config->airgapped) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "airgapped", cluster_config->airgapped) == NULL) {
    goto fail; //Bool
    }


    // cluster_config->node_stale_timeout
    if(cluster_config->node_stale_timeout) {
    if(cJSON_AddNumberToObject(item, "nodeStaleTimeout", cluster_config->node_stale_timeout) == NULL) {
    goto fail; //Numeric
    }
    }


    // cluster_config->report_interval
    if(cluster_config->report_interval) {
    if(cJSON_AddNumberToObject(item, "reportInterval", cluster_config->report_interval) == NULL) {
    goto fail; //Numeric
    }
    }


    // cluster_config->coordinator_config
    if(cluster_config->coordinator_config) {
    cJSON *coordinator_config_local_JSON = cluster_config_coordinator_config_convertToJSON(cluster_config->coordinator_config);
    if(coordinator_config_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "coordinatorConfig", coordinator_config_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // cluster_config->setup_config
    if(cluster_config->setup_config) {
    cJSON *setup_config_local_JSON = cluster_config_setup_config_convertToJSON(cluster_config->setup_config);
    if(setup_config_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "setupConfig", setup_config_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // cluster_config->node_specific_config
    if(cluster_config->node_specific_config) {
    cJSON *node_specific_config_local_JSON = cluster_config_node_specific_config_convertToJSON(cluster_config->node_specific_config);
    if(node_specific_config_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "nodeSpecificConfig", node_specific_config_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // cluster_config->package_config
    if(cluster_config->package_config) {
    cJSON *package_config_local_JSON = cluster_config_package_config_convertToJSON(cluster_config->package_config);
    if(package_config_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "packageConfig", package_config_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // cluster_config->monitor_interval
    if(cluster_config->monitor_interval) {
    if(cJSON_AddNumberToObject(item, "monitorInterval", cluster_config->monitor_interval) == NULL) {
    goto fail; //Numeric
    }
    }


    // cluster_config->csp
    if(cluster_config->csp) {
    if(cJSON_AddBoolToObject(item, "csp", cluster_config->csp) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config->cdk
    if(cluster_config->cdk) {
    if(cJSON_AddBoolToObject(item, "cdk", cluster_config->cdk) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config->charm_extension_paths
    if(cluster_config->charm_extension_paths) {
    cJSON *charm_extension_paths = cJSON_AddArrayToObject(item, "charmExtensionPaths");
    if(charm_extension_paths == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *charm_extension_pathsListEntry;
    list_ForEach(charm_extension_pathsListEntry, cluster_config->charm_extension_paths) {
    if(cJSON_AddStringToObject(charm_extension_paths, "", charm_extension_pathsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // cluster_config->firmware_cache
    if(cluster_config->firmware_cache) {
    if(cJSON_AddStringToObject(item, "firmwareCache", cluster_config->firmware_cache) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config->vstrm
    if(cluster_config->vstrm) {
    if(cJSON_AddStringToObject(item, "vstrm", cluster_config->vstrm) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config->console
    if(cluster_config->console) {
    if(cJSON_AddStringToObject(item, "console", cluster_config->console) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config->fetch_firmware_assets
    if(cluster_config->fetch_firmware_assets) {
    if(cJSON_AddBoolToObject(item, "fetchFirmwareAssets", cluster_config->fetch_firmware_assets) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config->cluster_firmware_assets
    if(cluster_config->cluster_firmware_assets) {
    if(cJSON_AddBoolToObject(item, "clusterFirmwareAssets", cluster_config->cluster_firmware_assets) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config->auth_providers
    if(cluster_config->auth_providers) {
    cJSON *auth_providers = cJSON_AddArrayToObject(item, "authProviders");
    if(auth_providers == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *auth_providersListEntry;
    if (cluster_config->auth_providers) {
    list_ForEach(auth_providersListEntry, cluster_config->auth_providers) {
    cJSON *itemLocal = cluster_config_coordinator_config_auth_providers_inner_convertToJSON(auth_providersListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(auth_providers, itemLocal);
    }
    }
    }


    // cluster_config->domain
    if(cluster_config->domain) {
    if(cJSON_AddStringToObject(item, "domain", cluster_config->domain) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config->service_domain
    if(cluster_config->service_domain) {
    if(cJSON_AddStringToObject(item, "serviceDomain", cluster_config->service_domain) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config->service_user
    if(cluster_config->service_user) {
    if(cJSON_AddStringToObject(item, "serviceUser", cluster_config->service_user) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config->domain_image_upload_quota
    if(cluster_config->domain_image_upload_quota) {
    if(cJSON_AddNumberToObject(item, "domainImageUploadQuota", cluster_config->domain_image_upload_quota) == NULL) {
    goto fail; //Numeric
    }
    }


    // cluster_config->ipsw_filters
    if(cluster_config->ipsw_filters) {
    cJSON *ipsw_filters = cJSON_AddArrayToObject(item, "ipswFilters");
    if(ipsw_filters == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *ipsw_filtersListEntry;
    if (cluster_config->ipsw_filters) {
    list_ForEach(ipsw_filtersListEntry, cluster_config->ipsw_filters) {
    cJSON *itemLocal = cluster_config_ipsw_filters_inner_convertToJSON(ipsw_filtersListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(ipsw_filters, itemLocal);
    }
    }
    }


    // cluster_config->firmware_service_config
    if(cluster_config->firmware_service_config) {
    cJSON *firmware_service_config_local_JSON = cluster_config_firmware_service_config_convertToJSON(cluster_config->firmware_service_config);
    if(firmware_service_config_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "firmwareServiceConfig", firmware_service_config_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // cluster_config->ai_tools_config
    if(cluster_config->ai_tools_config) {
    cJSON *ai_tools_config_local_JSON = cluster_config_ai_tools_config_convertToJSON(cluster_config->ai_tools_config);
    if(ai_tools_config_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "aiToolsConfig", ai_tools_config_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

cluster_config_t *cluster_config_parseFromJSON(cJSON *cluster_configJSON){

    cluster_config_t *cluster_config_local_var = NULL;

    // define the local list for cluster_config->last_config_keys
    list_t *last_config_keysList = NULL;

    // define the local list for cluster_config->instance_dns_servers
    list_t *instance_dns_serversList = NULL;

    // define the local list for cluster_config->network_types
    list_t *network_typesList = NULL;

    // define the local variable for cluster_config->stripe
    cluster_config_stripe_t *stripe_local_nonprim = NULL;

    // define the local variable for cluster_config->maintenance
    cluster_config_maintenance_t *maintenance_local_nonprim = NULL;

    // define the local variable for cluster_config->net_mon_ca
    cluster_config_net_mon_ca_t *net_mon_ca_local_nonprim = NULL;

    // define the local variable for cluster_config->coordinator_config
    cluster_config_coordinator_config_t *coordinator_config_local_nonprim = NULL;

    // define the local variable for cluster_config->setup_config
    cluster_config_setup_config_t *setup_config_local_nonprim = NULL;

    // define the local variable for cluster_config->node_specific_config
    cluster_config_node_specific_config_t *node_specific_config_local_nonprim = NULL;

    // define the local variable for cluster_config->package_config
    cluster_config_package_config_t *package_config_local_nonprim = NULL;

    // define the local list for cluster_config->charm_extension_paths
    list_t *charm_extension_pathsList = NULL;

    // define the local list for cluster_config->auth_providers
    list_t *auth_providersList = NULL;

    // define the local list for cluster_config->ipsw_filters
    list_t *ipsw_filtersList = NULL;

    // define the local variable for cluster_config->firmware_service_config
    cluster_config_firmware_service_config_t *firmware_service_config_local_nonprim = NULL;

    // define the local variable for cluster_config->ai_tools_config
    cluster_config_ai_tools_config_t *ai_tools_config_local_nonprim = NULL;

    // cluster_config->last_config_keys
    cJSON *last_config_keys = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "lastConfigKeys");
    if (cJSON_IsNull(last_config_keys)) {
        last_config_keys = NULL;
    }
    if (!last_config_keys) {
        goto end;
    }

    
    cJSON *last_config_keys_local = NULL;
    if(!cJSON_IsArray(last_config_keys)) {
        goto end;//primitive container
    }
    last_config_keysList = list_createList();

    cJSON_ArrayForEach(last_config_keys_local, last_config_keys)
    {
        if(!cJSON_IsString(last_config_keys_local))
        {
            goto end;
        }
        list_addElement(last_config_keysList , strdup(last_config_keys_local->valuestring));
    }

    // cluster_config->local_ip
    cJSON *local_ip = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "localIp");
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

    // cluster_config->ip_block_netmask
    cJSON *ip_block_netmask = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "ipBlockNetmask");
    if (cJSON_IsNull(ip_block_netmask)) {
        ip_block_netmask = NULL;
    }
    if (!ip_block_netmask) {
        goto end;
    }

    
    if(!cJSON_IsString(ip_block_netmask))
    {
    goto end; //String
    }

    // cluster_config->instance_gateway
    cJSON *instance_gateway = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "instanceGateway");
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

    // cluster_config->instance_dns_servers
    cJSON *instance_dns_servers = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "instanceDNSServers");
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

    // cluster_config->coordinator
    cJSON *coordinator = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "coordinator");
    if (cJSON_IsNull(coordinator)) {
        coordinator = NULL;
    }
    if (coordinator) { 
    if(!cJSON_IsString(coordinator) && !cJSON_IsNull(coordinator))
    {
    goto end; //String
    }
    }

    // cluster_config->on_site
    cJSON *on_site = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "onSite");
    if (cJSON_IsNull(on_site)) {
        on_site = NULL;
    }
    if (on_site) { 
    if(!cJSON_IsBool(on_site))
    {
    goto end; //Bool
    }
    }

    // cluster_config->cloud_provider
    cJSON *cloud_provider = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "cloudProvider");
    if (cJSON_IsNull(cloud_provider)) {
        cloud_provider = NULL;
    }
    if (cloud_provider) { 
    if(!cJSON_IsString(cloud_provider) && !cJSON_IsNull(cloud_provider))
    {
    goto end; //String
    }
    }

    // cluster_config->network_types
    cJSON *network_types = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "networkTypes");
    if (cJSON_IsNull(network_types)) {
        network_types = NULL;
    }
    if (!network_types) {
        goto end;
    }

    
    cJSON *network_types_local = NULL;
    if(!cJSON_IsArray(network_types)) {
        goto end;//primitive container
    }
    network_typesList = list_createList();

    cJSON_ArrayForEach(network_types_local, network_types)
    {
        if(!cJSON_IsString(network_types_local))
        {
            goto end;
        }
        list_addElement(network_typesList , strdup(network_types_local->valuestring));
    }

    // cluster_config->network_type
    cJSON *network_type = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "networkType");
    if (cJSON_IsNull(network_type)) {
        network_type = NULL;
    }
    corellium_api_cluster_config_NETWORKTYPE_e network_typeVariable;
    if (network_type) { 
    if(!cJSON_IsString(network_type))
    {
    goto end; //Enum
    }
    network_typeVariable = cluster_config_network_type_FromString(network_type->valuestring);
    }

    // cluster_config->show_domain_settings
    cJSON *show_domain_settings = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "showDomainSettings");
    if (cJSON_IsNull(show_domain_settings)) {
        show_domain_settings = NULL;
    }
    if (show_domain_settings) { 
    if(!cJSON_IsBool(show_domain_settings))
    {
    goto end; //Bool
    }
    }

    // cluster_config->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "version");
    if (cJSON_IsNull(version)) {
        version = NULL;
    }
    if (version) { 
    if(!cJSON_IsString(version) && !cJSON_IsNull(version))
    {
    goto end; //String
    }
    }

    // cluster_config->ipsw_url
    cJSON *ipsw_url = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "ipswUrl");
    if (cJSON_IsNull(ipsw_url)) {
        ipsw_url = NULL;
    }
    if (ipsw_url) { 
    if(!cJSON_IsString(ipsw_url) && !cJSON_IsNull(ipsw_url))
    {
    goto end; //String
    }
    }

    // cluster_config->coreimg_url
    cJSON *coreimg_url = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "coreimgUrl");
    if (cJSON_IsNull(coreimg_url)) {
        coreimg_url = NULL;
    }
    if (coreimg_url) { 
    if(!cJSON_IsString(coreimg_url) && !cJSON_IsNull(coreimg_url))
    {
    goto end; //String
    }
    }

    // cluster_config->fw_service_url
    cJSON *fw_service_url = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "fwServiceUrl");
    if (cJSON_IsNull(fw_service_url)) {
        fw_service_url = NULL;
    }
    if (fw_service_url) { 
    if(!cJSON_IsString(fw_service_url) && !cJSON_IsNull(fw_service_url))
    {
    goto end; //String
    }
    }

    // cluster_config->service_password
    cJSON *service_password = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "servicePassword");
    if (cJSON_IsNull(service_password)) {
        service_password = NULL;
    }
    if (service_password) { 
    if(!cJSON_IsString(service_password) && !cJSON_IsNull(service_password))
    {
    goto end; //String
    }
    }

    // cluster_config->invalid_build
    cJSON *invalid_build = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "invalidBuild");
    if (cJSON_IsNull(invalid_build)) {
        invalid_build = NULL;
    }
    if (invalid_build) { 
    if(!cJSON_IsBool(invalid_build))
    {
    goto end; //Bool
    }
    }

    // cluster_config->sep_sim
    cJSON *sep_sim = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "sepSim");
    if (cJSON_IsNull(sep_sim)) {
        sep_sim = NULL;
    }
    if (sep_sim) { 
    if(!cJSON_IsBool(sep_sim))
    {
    goto end; //Bool
    }
    }

    // cluster_config->installer_available
    cJSON *installer_available = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "installerAvailable");
    if (cJSON_IsNull(installer_available)) {
        installer_available = NULL;
    }
    if (installer_available) { 
    if(!cJSON_IsBool(installer_available))
    {
    goto end; //Bool
    }
    }

    // cluster_config->stripe
    cJSON *stripe = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "stripe");
    if (cJSON_IsNull(stripe)) {
        stripe = NULL;
    }
    if (stripe) { 
    stripe_local_nonprim = cluster_config_stripe_parseFromJSON(stripe); //nonprimitive
    }

    // cluster_config->intercom_id
    cJSON *intercom_id = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "intercomId");
    if (cJSON_IsNull(intercom_id)) {
        intercom_id = NULL;
    }
    if (intercom_id) { 
    if(!cJSON_IsString(intercom_id) && !cJSON_IsNull(intercom_id))
    {
    goto end; //String
    }
    }

    // cluster_config->aux_webhook
    cJSON *aux_webhook = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "auxWebhook");
    if (cJSON_IsNull(aux_webhook)) {
        aux_webhook = NULL;
    }
    if (aux_webhook) { 
    if(!cJSON_IsString(aux_webhook) && !cJSON_IsNull(aux_webhook))
    {
    goto end; //String
    }
    }

    // cluster_config->gtm_id
    cJSON *gtm_id = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "gtmId");
    if (cJSON_IsNull(gtm_id)) {
        gtm_id = NULL;
    }
    if (gtm_id) { 
    if(!cJSON_IsString(gtm_id) && !cJSON_IsNull(gtm_id))
    {
    goto end; //String
    }
    }

    // cluster_config->zapier_feedback_webhook
    cJSON *zapier_feedback_webhook = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "zapierFeedbackWebhook");
    if (cJSON_IsNull(zapier_feedback_webhook)) {
        zapier_feedback_webhook = NULL;
    }
    if (zapier_feedback_webhook) { 
    if(!cJSON_IsString(zapier_feedback_webhook) && !cJSON_IsNull(zapier_feedback_webhook))
    {
    goto end; //String
    }
    }

    // cluster_config->zapier_bugs_webhook
    cJSON *zapier_bugs_webhook = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "zapierBugsWebhook");
    if (cJSON_IsNull(zapier_bugs_webhook)) {
        zapier_bugs_webhook = NULL;
    }
    if (zapier_bugs_webhook) { 
    if(!cJSON_IsString(zapier_bugs_webhook) && !cJSON_IsNull(zapier_bugs_webhook))
    {
    goto end; //String
    }
    }

    // cluster_config->billing_backend
    cJSON *billing_backend = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "billingBackend");
    if (cJSON_IsNull(billing_backend)) {
        billing_backend = NULL;
    }
    if (billing_backend) { 
    if(!cJSON_IsString(billing_backend) && !cJSON_IsNull(billing_backend))
    {
    goto end; //String
    }
    }

    // cluster_config->maintenance
    cJSON *maintenance = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "maintenance");
    if (cJSON_IsNull(maintenance)) {
        maintenance = NULL;
    }
    if (maintenance) { 
    maintenance_local_nonprim = cluster_config_maintenance_parseFromJSON(maintenance); //nonprimitive
    }

    // cluster_config->cloud_domain
    cJSON *cloud_domain = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "cloudDomain");
    if (cJSON_IsNull(cloud_domain)) {
        cloud_domain = NULL;
    }
    if (cloud_domain) { 
    if(!cJSON_IsString(cloud_domain) && !cJSON_IsNull(cloud_domain))
    {
    goto end; //String
    }
    }

    // cluster_config->development
    cJSON *development = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "development");
    if (cJSON_IsNull(development)) {
        development = NULL;
    }
    if (development) { 
    if(!cJSON_IsBool(development))
    {
    goto end; //Bool
    }
    }

    // cluster_config->billing_domain
    cJSON *billing_domain = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "billingDomain");
    if (cJSON_IsNull(billing_domain)) {
        billing_domain = NULL;
    }
    if (billing_domain) { 
    if(!cJSON_IsString(billing_domain) && !cJSON_IsNull(billing_domain))
    {
    goto end; //String
    }
    }

    // cluster_config->app_domain
    cJSON *app_domain = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "appDomain");
    if (cJSON_IsNull(app_domain)) {
        app_domain = NULL;
    }
    if (app_domain) { 
    if(!cJSON_IsString(app_domain) && !cJSON_IsNull(app_domain))
    {
    goto end; //String
    }
    }

    // cluster_config->enable_firmware_image_upload
    cJSON *enable_firmware_image_upload = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "enableFirmwareImageUpload");
    if (cJSON_IsNull(enable_firmware_image_upload)) {
        enable_firmware_image_upload = NULL;
    }
    if (enable_firmware_image_upload) { 
    if(!cJSON_IsBool(enable_firmware_image_upload))
    {
    goto end; //Bool
    }
    }

    // cluster_config->net_mon_ca
    cJSON *net_mon_ca = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "netMonCA");
    if (cJSON_IsNull(net_mon_ca)) {
        net_mon_ca = NULL;
    }
    if (net_mon_ca) { 
    net_mon_ca_local_nonprim = cluster_config_net_mon_ca_parseFromJSON(net_mon_ca); //nonprimitive
    }

    // cluster_config->snapshot_limit
    cJSON *snapshot_limit = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "snapshotLimit");
    if (cJSON_IsNull(snapshot_limit)) {
        snapshot_limit = NULL;
    }
    if (snapshot_limit) { 
    if(!cJSON_IsNumber(snapshot_limit))
    {
    goto end; //Numeric
    }
    }

    // cluster_config->max_kernel_size
    cJSON *max_kernel_size = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "maxKernelSize");
    if (cJSON_IsNull(max_kernel_size)) {
        max_kernel_size = NULL;
    }
    if (!max_kernel_size) {
        goto end;
    }

    
    if(!cJSON_IsNumber(max_kernel_size))
    {
    goto end; //Numeric
    }

    // cluster_config->max_ramdisk_size
    cJSON *max_ramdisk_size = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "maxRamdiskSize");
    if (cJSON_IsNull(max_ramdisk_size)) {
        max_ramdisk_size = NULL;
    }
    if (!max_ramdisk_size) {
        goto end;
    }

    
    if(!cJSON_IsNumber(max_ramdisk_size))
    {
    goto end; //Numeric
    }

    // cluster_config->charm_sdk
    cJSON *charm_sdk = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "charmSDK");
    if (cJSON_IsNull(charm_sdk)) {
        charm_sdk = NULL;
    }
    if (charm_sdk) { 
    if(!cJSON_IsBool(charm_sdk))
    {
    goto end; //Bool
    }
    }

    // cluster_config->sentry_url
    cJSON *sentry_url = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "sentryUrl");
    if (cJSON_IsNull(sentry_url)) {
        sentry_url = NULL;
    }
    if (sentry_url) { 
    if(!cJSON_IsString(sentry_url) && !cJSON_IsNull(sentry_url))
    {
    goto end; //String
    }
    }

    // cluster_config->remote_gpu
    cJSON *remote_gpu = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "remoteGpu");
    if (cJSON_IsNull(remote_gpu)) {
        remote_gpu = NULL;
    }
    if (remote_gpu) { 
    if(!cJSON_IsBool(remote_gpu))
    {
    goto end; //Bool
    }
    }

    // cluster_config->rate_limit
    cJSON *rate_limit = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "rateLimit");
    if (cJSON_IsNull(rate_limit)) {
        rate_limit = NULL;
    }
    if (rate_limit) { 
    if(!cJSON_IsBool(rate_limit))
    {
    goto end; //Bool
    }
    }

    // cluster_config->cert_file_data
    cJSON *cert_file_data = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "certFileData");
    if (cJSON_IsNull(cert_file_data)) {
        cert_file_data = NULL;
    }
    if (cert_file_data) { 
    if(!cJSON_IsString(cert_file_data) && !cJSON_IsNull(cert_file_data))
    {
    goto end; //String
    }
    }

    // cluster_config->ca_cert_file_src
    cJSON *ca_cert_file_src = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "caCertFileSrc");
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

    // cluster_config->vstrm_on_compute_nodes
    cJSON *vstrm_on_compute_nodes = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "vstrmOnComputeNodes");
    if (cJSON_IsNull(vstrm_on_compute_nodes)) {
        vstrm_on_compute_nodes = NULL;
    }
    if (vstrm_on_compute_nodes) { 
    if(!cJSON_IsBool(vstrm_on_compute_nodes))
    {
    goto end; //Bool
    }
    }

    // cluster_config->charm
    cJSON *charm = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "charm");
    if (cJSON_IsNull(charm)) {
        charm = NULL;
    }
    object_t *charm_local_object = NULL;
    if (charm) { 
    charm_local_object = object_parseFromJSON(charm); //object
    }

    // cluster_config->c3po_path_prefix
    cJSON *c3po_path_prefix = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "c3poPathPrefix");
    if (cJSON_IsNull(c3po_path_prefix)) {
        c3po_path_prefix = NULL;
    }
    if (c3po_path_prefix) { 
    if(!cJSON_IsString(c3po_path_prefix) && !cJSON_IsNull(c3po_path_prefix))
    {
    goto end; //String
    }
    }

    // cluster_config->branding
    cJSON *branding = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "branding");
    if (cJSON_IsNull(branding)) {
        branding = NULL;
    }
    if (!branding) {
        goto end;
    }

    
    if(!cJSON_IsString(branding))
    {
    goto end; //String
    }

    // cluster_config->open_g_apps_binary
    cJSON *open_g_apps_binary = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "openGAppsBinary");
    if (cJSON_IsNull(open_g_apps_binary)) {
        open_g_apps_binary = NULL;
    }
    if (!open_g_apps_binary) {
        goto end;
    }

    
    if(!cJSON_IsString(open_g_apps_binary))
    {
    goto end; //String
    }

    // cluster_config->airgapped
    cJSON *airgapped = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "airgapped");
    if (cJSON_IsNull(airgapped)) {
        airgapped = NULL;
    }
    if (!airgapped) {
        goto end;
    }

    
    if(!cJSON_IsBool(airgapped))
    {
    goto end; //Bool
    }

    // cluster_config->node_stale_timeout
    cJSON *node_stale_timeout = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "nodeStaleTimeout");
    if (cJSON_IsNull(node_stale_timeout)) {
        node_stale_timeout = NULL;
    }
    if (node_stale_timeout) { 
    if(!cJSON_IsNumber(node_stale_timeout))
    {
    goto end; //Numeric
    }
    }

    // cluster_config->report_interval
    cJSON *report_interval = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "reportInterval");
    if (cJSON_IsNull(report_interval)) {
        report_interval = NULL;
    }
    if (report_interval) { 
    if(!cJSON_IsNumber(report_interval))
    {
    goto end; //Numeric
    }
    }

    // cluster_config->coordinator_config
    cJSON *coordinator_config = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "coordinatorConfig");
    if (cJSON_IsNull(coordinator_config)) {
        coordinator_config = NULL;
    }
    if (coordinator_config) { 
    coordinator_config_local_nonprim = cluster_config_coordinator_config_parseFromJSON(coordinator_config); //nonprimitive
    }

    // cluster_config->setup_config
    cJSON *setup_config = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "setupConfig");
    if (cJSON_IsNull(setup_config)) {
        setup_config = NULL;
    }
    if (setup_config) { 
    setup_config_local_nonprim = cluster_config_setup_config_parseFromJSON(setup_config); //nonprimitive
    }

    // cluster_config->node_specific_config
    cJSON *node_specific_config = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "nodeSpecificConfig");
    if (cJSON_IsNull(node_specific_config)) {
        node_specific_config = NULL;
    }
    if (node_specific_config) { 
    node_specific_config_local_nonprim = cluster_config_node_specific_config_parseFromJSON(node_specific_config); //nonprimitive
    }

    // cluster_config->package_config
    cJSON *package_config = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "packageConfig");
    if (cJSON_IsNull(package_config)) {
        package_config = NULL;
    }
    if (package_config) { 
    package_config_local_nonprim = cluster_config_package_config_parseFromJSON(package_config); //nonprimitive
    }

    // cluster_config->monitor_interval
    cJSON *monitor_interval = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "monitorInterval");
    if (cJSON_IsNull(monitor_interval)) {
        monitor_interval = NULL;
    }
    if (monitor_interval) { 
    if(!cJSON_IsNumber(monitor_interval))
    {
    goto end; //Numeric
    }
    }

    // cluster_config->csp
    cJSON *csp = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "csp");
    if (cJSON_IsNull(csp)) {
        csp = NULL;
    }
    if (csp) { 
    if(!cJSON_IsBool(csp))
    {
    goto end; //Bool
    }
    }

    // cluster_config->cdk
    cJSON *cdk = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "cdk");
    if (cJSON_IsNull(cdk)) {
        cdk = NULL;
    }
    if (cdk) { 
    if(!cJSON_IsBool(cdk))
    {
    goto end; //Bool
    }
    }

    // cluster_config->charm_extension_paths
    cJSON *charm_extension_paths = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "charmExtensionPaths");
    if (cJSON_IsNull(charm_extension_paths)) {
        charm_extension_paths = NULL;
    }
    if (charm_extension_paths) { 
    cJSON *charm_extension_paths_local = NULL;
    if(!cJSON_IsArray(charm_extension_paths)) {
        goto end;//primitive container
    }
    charm_extension_pathsList = list_createList();

    cJSON_ArrayForEach(charm_extension_paths_local, charm_extension_paths)
    {
        if(!cJSON_IsString(charm_extension_paths_local))
        {
            goto end;
        }
        list_addElement(charm_extension_pathsList , strdup(charm_extension_paths_local->valuestring));
    }
    }

    // cluster_config->firmware_cache
    cJSON *firmware_cache = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "firmwareCache");
    if (cJSON_IsNull(firmware_cache)) {
        firmware_cache = NULL;
    }
    if (firmware_cache) { 
    if(!cJSON_IsString(firmware_cache) && !cJSON_IsNull(firmware_cache))
    {
    goto end; //String
    }
    }

    // cluster_config->vstrm
    cJSON *vstrm = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "vstrm");
    if (cJSON_IsNull(vstrm)) {
        vstrm = NULL;
    }
    if (vstrm) { 
    if(!cJSON_IsString(vstrm) && !cJSON_IsNull(vstrm))
    {
    goto end; //String
    }
    }

    // cluster_config->console
    cJSON *console = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "console");
    if (cJSON_IsNull(console)) {
        console = NULL;
    }
    if (console) { 
    if(!cJSON_IsString(console) && !cJSON_IsNull(console))
    {
    goto end; //String
    }
    }

    // cluster_config->fetch_firmware_assets
    cJSON *fetch_firmware_assets = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "fetchFirmwareAssets");
    if (cJSON_IsNull(fetch_firmware_assets)) {
        fetch_firmware_assets = NULL;
    }
    if (fetch_firmware_assets) { 
    if(!cJSON_IsBool(fetch_firmware_assets))
    {
    goto end; //Bool
    }
    }

    // cluster_config->cluster_firmware_assets
    cJSON *cluster_firmware_assets = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "clusterFirmwareAssets");
    if (cJSON_IsNull(cluster_firmware_assets)) {
        cluster_firmware_assets = NULL;
    }
    if (cluster_firmware_assets) { 
    if(!cJSON_IsBool(cluster_firmware_assets))
    {
    goto end; //Bool
    }
    }

    // cluster_config->auth_providers
    cJSON *auth_providers = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "authProviders");
    if (cJSON_IsNull(auth_providers)) {
        auth_providers = NULL;
    }
    if (auth_providers) { 
    cJSON *auth_providers_local_nonprimitive = NULL;
    if(!cJSON_IsArray(auth_providers)){
        goto end; //nonprimitive container
    }

    auth_providersList = list_createList();

    cJSON_ArrayForEach(auth_providers_local_nonprimitive,auth_providers )
    {
        if(!cJSON_IsObject(auth_providers_local_nonprimitive)){
            goto end;
        }
        cluster_config_coordinator_config_auth_providers_inner_t *auth_providersItem = cluster_config_coordinator_config_auth_providers_inner_parseFromJSON(auth_providers_local_nonprimitive);

        list_addElement(auth_providersList, auth_providersItem);
    }
    }

    // cluster_config->domain
    cJSON *domain = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "domain");
    if (cJSON_IsNull(domain)) {
        domain = NULL;
    }
    if (domain) { 
    if(!cJSON_IsString(domain) && !cJSON_IsNull(domain))
    {
    goto end; //String
    }
    }

    // cluster_config->service_domain
    cJSON *service_domain = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "serviceDomain");
    if (cJSON_IsNull(service_domain)) {
        service_domain = NULL;
    }
    if (service_domain) { 
    if(!cJSON_IsString(service_domain) && !cJSON_IsNull(service_domain))
    {
    goto end; //String
    }
    }

    // cluster_config->service_user
    cJSON *service_user = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "serviceUser");
    if (cJSON_IsNull(service_user)) {
        service_user = NULL;
    }
    if (service_user) { 
    if(!cJSON_IsString(service_user) && !cJSON_IsNull(service_user))
    {
    goto end; //String
    }
    }

    // cluster_config->domain_image_upload_quota
    cJSON *domain_image_upload_quota = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "domainImageUploadQuota");
    if (cJSON_IsNull(domain_image_upload_quota)) {
        domain_image_upload_quota = NULL;
    }
    if (domain_image_upload_quota) { 
    if(!cJSON_IsNumber(domain_image_upload_quota))
    {
    goto end; //Numeric
    }
    }

    // cluster_config->ipsw_filters
    cJSON *ipsw_filters = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "ipswFilters");
    if (cJSON_IsNull(ipsw_filters)) {
        ipsw_filters = NULL;
    }
    if (ipsw_filters) { 
    cJSON *ipsw_filters_local_nonprimitive = NULL;
    if(!cJSON_IsArray(ipsw_filters)){
        goto end; //nonprimitive container
    }

    ipsw_filtersList = list_createList();

    cJSON_ArrayForEach(ipsw_filters_local_nonprimitive,ipsw_filters )
    {
        if(!cJSON_IsObject(ipsw_filters_local_nonprimitive)){
            goto end;
        }
        cluster_config_ipsw_filters_inner_t *ipsw_filtersItem = cluster_config_ipsw_filters_inner_parseFromJSON(ipsw_filters_local_nonprimitive);

        list_addElement(ipsw_filtersList, ipsw_filtersItem);
    }
    }

    // cluster_config->firmware_service_config
    cJSON *firmware_service_config = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "firmwareServiceConfig");
    if (cJSON_IsNull(firmware_service_config)) {
        firmware_service_config = NULL;
    }
    if (firmware_service_config) { 
    firmware_service_config_local_nonprim = cluster_config_firmware_service_config_parseFromJSON(firmware_service_config); //nonprimitive
    }

    // cluster_config->ai_tools_config
    cJSON *ai_tools_config = cJSON_GetObjectItemCaseSensitive(cluster_configJSON, "aiToolsConfig");
    if (cJSON_IsNull(ai_tools_config)) {
        ai_tools_config = NULL;
    }
    if (ai_tools_config) { 
    ai_tools_config_local_nonprim = cluster_config_ai_tools_config_parseFromJSON(ai_tools_config); //nonprimitive
    }


    cluster_config_local_var = cluster_config_create_internal (
        last_config_keysList,
        strdup(local_ip->valuestring),
        strdup(ip_block_netmask->valuestring),
        strdup(instance_gateway->valuestring),
        instance_dns_servers ? instance_dns_serversList : NULL,
        coordinator && !cJSON_IsNull(coordinator) ? strdup(coordinator->valuestring) : NULL,
        on_site ? on_site->valueint : 0,
        cloud_provider && !cJSON_IsNull(cloud_provider) ? strdup(cloud_provider->valuestring) : NULL,
        network_typesList,
        network_type ? network_typeVariable : corellium_api_cluster_config_NETWORKTYPE_NULL,
        show_domain_settings ? show_domain_settings->valueint : 0,
        version && !cJSON_IsNull(version) ? strdup(version->valuestring) : NULL,
        ipsw_url && !cJSON_IsNull(ipsw_url) ? strdup(ipsw_url->valuestring) : NULL,
        coreimg_url && !cJSON_IsNull(coreimg_url) ? strdup(coreimg_url->valuestring) : NULL,
        fw_service_url && !cJSON_IsNull(fw_service_url) ? strdup(fw_service_url->valuestring) : NULL,
        service_password && !cJSON_IsNull(service_password) ? strdup(service_password->valuestring) : NULL,
        invalid_build ? invalid_build->valueint : 0,
        sep_sim ? sep_sim->valueint : 0,
        installer_available ? installer_available->valueint : 0,
        stripe ? stripe_local_nonprim : NULL,
        intercom_id && !cJSON_IsNull(intercom_id) ? strdup(intercom_id->valuestring) : NULL,
        aux_webhook && !cJSON_IsNull(aux_webhook) ? strdup(aux_webhook->valuestring) : NULL,
        gtm_id && !cJSON_IsNull(gtm_id) ? strdup(gtm_id->valuestring) : NULL,
        zapier_feedback_webhook && !cJSON_IsNull(zapier_feedback_webhook) ? strdup(zapier_feedback_webhook->valuestring) : NULL,
        zapier_bugs_webhook && !cJSON_IsNull(zapier_bugs_webhook) ? strdup(zapier_bugs_webhook->valuestring) : NULL,
        billing_backend && !cJSON_IsNull(billing_backend) ? strdup(billing_backend->valuestring) : NULL,
        maintenance ? maintenance_local_nonprim : NULL,
        cloud_domain && !cJSON_IsNull(cloud_domain) ? strdup(cloud_domain->valuestring) : NULL,
        development ? development->valueint : 0,
        billing_domain && !cJSON_IsNull(billing_domain) ? strdup(billing_domain->valuestring) : NULL,
        app_domain && !cJSON_IsNull(app_domain) ? strdup(app_domain->valuestring) : NULL,
        enable_firmware_image_upload ? enable_firmware_image_upload->valueint : 0,
        net_mon_ca ? net_mon_ca_local_nonprim : NULL,
        snapshot_limit ? snapshot_limit->valuedouble : 0,
        max_kernel_size->valuedouble,
        max_ramdisk_size->valuedouble,
        charm_sdk ? charm_sdk->valueint : 0,
        sentry_url && !cJSON_IsNull(sentry_url) ? strdup(sentry_url->valuestring) : NULL,
        remote_gpu ? remote_gpu->valueint : 0,
        rate_limit ? rate_limit->valueint : 0,
        cert_file_data && !cJSON_IsNull(cert_file_data) ? strdup(cert_file_data->valuestring) : NULL,
        strdup(ca_cert_file_src->valuestring),
        vstrm_on_compute_nodes ? vstrm_on_compute_nodes->valueint : 0,
        charm ? charm_local_object : NULL,
        c3po_path_prefix && !cJSON_IsNull(c3po_path_prefix) ? strdup(c3po_path_prefix->valuestring) : NULL,
        strdup(branding->valuestring),
        strdup(open_g_apps_binary->valuestring),
        airgapped->valueint,
        node_stale_timeout ? node_stale_timeout->valuedouble : 0,
        report_interval ? report_interval->valuedouble : 0,
        coordinator_config ? coordinator_config_local_nonprim : NULL,
        setup_config ? setup_config_local_nonprim : NULL,
        node_specific_config ? node_specific_config_local_nonprim : NULL,
        package_config ? package_config_local_nonprim : NULL,
        monitor_interval ? monitor_interval->valuedouble : 0,
        csp ? csp->valueint : 0,
        cdk ? cdk->valueint : 0,
        charm_extension_paths ? charm_extension_pathsList : NULL,
        firmware_cache && !cJSON_IsNull(firmware_cache) ? strdup(firmware_cache->valuestring) : NULL,
        vstrm && !cJSON_IsNull(vstrm) ? strdup(vstrm->valuestring) : NULL,
        console && !cJSON_IsNull(console) ? strdup(console->valuestring) : NULL,
        fetch_firmware_assets ? fetch_firmware_assets->valueint : 0,
        cluster_firmware_assets ? cluster_firmware_assets->valueint : 0,
        auth_providers ? auth_providersList : NULL,
        domain && !cJSON_IsNull(domain) ? strdup(domain->valuestring) : NULL,
        service_domain && !cJSON_IsNull(service_domain) ? strdup(service_domain->valuestring) : NULL,
        service_user && !cJSON_IsNull(service_user) ? strdup(service_user->valuestring) : NULL,
        domain_image_upload_quota ? domain_image_upload_quota->valuedouble : 0,
        ipsw_filters ? ipsw_filtersList : NULL,
        firmware_service_config ? firmware_service_config_local_nonprim : NULL,
        ai_tools_config ? ai_tools_config_local_nonprim : NULL
        );

    return cluster_config_local_var;
end:
    if (last_config_keysList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, last_config_keysList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(last_config_keysList);
        last_config_keysList = NULL;
    }
    if (instance_dns_serversList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, instance_dns_serversList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(instance_dns_serversList);
        instance_dns_serversList = NULL;
    }
    if (network_typesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, network_typesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(network_typesList);
        network_typesList = NULL;
    }
    if (stripe_local_nonprim) {
        cluster_config_stripe_free(stripe_local_nonprim);
        stripe_local_nonprim = NULL;
    }
    if (maintenance_local_nonprim) {
        cluster_config_maintenance_free(maintenance_local_nonprim);
        maintenance_local_nonprim = NULL;
    }
    if (net_mon_ca_local_nonprim) {
        cluster_config_net_mon_ca_free(net_mon_ca_local_nonprim);
        net_mon_ca_local_nonprim = NULL;
    }
    if (coordinator_config_local_nonprim) {
        cluster_config_coordinator_config_free(coordinator_config_local_nonprim);
        coordinator_config_local_nonprim = NULL;
    }
    if (setup_config_local_nonprim) {
        cluster_config_setup_config_free(setup_config_local_nonprim);
        setup_config_local_nonprim = NULL;
    }
    if (node_specific_config_local_nonprim) {
        cluster_config_node_specific_config_free(node_specific_config_local_nonprim);
        node_specific_config_local_nonprim = NULL;
    }
    if (package_config_local_nonprim) {
        cluster_config_package_config_free(package_config_local_nonprim);
        package_config_local_nonprim = NULL;
    }
    if (charm_extension_pathsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, charm_extension_pathsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(charm_extension_pathsList);
        charm_extension_pathsList = NULL;
    }
    if (auth_providersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, auth_providersList) {
            cluster_config_coordinator_config_auth_providers_inner_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(auth_providersList);
        auth_providersList = NULL;
    }
    if (ipsw_filtersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, ipsw_filtersList) {
            cluster_config_ipsw_filters_inner_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(ipsw_filtersList);
        ipsw_filtersList = NULL;
    }
    if (firmware_service_config_local_nonprim) {
        cluster_config_firmware_service_config_free(firmware_service_config_local_nonprim);
        firmware_service_config_local_nonprim = NULL;
    }
    if (ai_tools_config_local_nonprim) {
        cluster_config_ai_tools_config_free(ai_tools_config_local_nonprim);
        ai_tools_config_local_nonprim = NULL;
    }
    return NULL;

}
