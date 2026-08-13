#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "config_response_v1.h"



static config_response_v1_t *config_response_v1_create_internal(
    int on_site,
    list_t *network_types,
    char *network_type,
    int show_domain_settings,
    char *version,
    int invalid_build,
    int sep_sim,
    int installer_available,
    char *invoiced_publishable_key,
    char *stripe_public_key,
    char *intercom_id,
    char *aux_webhook,
    char *gtm_id,
    char *zapier_feedback_webhook,
    char *zapier_bugs_webhook,
    char *billing_backend,
    object_t *maintenance,
    logging_v1_t *logging,
    char *cloud_admin,
    char *files_admin,
    char *cloud_domain,
    char *billing_domain,
    char *app_domain,
    char *max_network_monitor_file_size,
    int enable_firmware_image_upload,
    list_t *auth_providers,
    double snapshot_limit,
    double max_kernel_size,
    double max_ramdisk_size,
    int charm_sdk,
    trial_v1_t *trial,
    char *sentry_url,
    int domain_authentication_providers,
    char *default_ssid,
    coordinator_config_v1_t *coordinator_config
    ) {
    config_response_v1_t *config_response_v1_local_var = malloc(sizeof(config_response_v1_t));
    if (!config_response_v1_local_var) {
        return NULL;
    }
    config_response_v1_local_var->on_site = on_site;
    config_response_v1_local_var->network_types = network_types;
    config_response_v1_local_var->network_type = network_type;
    config_response_v1_local_var->show_domain_settings = show_domain_settings;
    config_response_v1_local_var->version = version;
    config_response_v1_local_var->invalid_build = invalid_build;
    config_response_v1_local_var->sep_sim = sep_sim;
    config_response_v1_local_var->installer_available = installer_available;
    config_response_v1_local_var->invoiced_publishable_key = invoiced_publishable_key;
    config_response_v1_local_var->stripe_public_key = stripe_public_key;
    config_response_v1_local_var->intercom_id = intercom_id;
    config_response_v1_local_var->aux_webhook = aux_webhook;
    config_response_v1_local_var->gtm_id = gtm_id;
    config_response_v1_local_var->zapier_feedback_webhook = zapier_feedback_webhook;
    config_response_v1_local_var->zapier_bugs_webhook = zapier_bugs_webhook;
    config_response_v1_local_var->billing_backend = billing_backend;
    config_response_v1_local_var->maintenance = maintenance;
    config_response_v1_local_var->logging = logging;
    config_response_v1_local_var->cloud_admin = cloud_admin;
    config_response_v1_local_var->files_admin = files_admin;
    config_response_v1_local_var->cloud_domain = cloud_domain;
    config_response_v1_local_var->billing_domain = billing_domain;
    config_response_v1_local_var->app_domain = app_domain;
    config_response_v1_local_var->max_network_monitor_file_size = max_network_monitor_file_size;
    config_response_v1_local_var->enable_firmware_image_upload = enable_firmware_image_upload;
    config_response_v1_local_var->auth_providers = auth_providers;
    config_response_v1_local_var->snapshot_limit = snapshot_limit;
    config_response_v1_local_var->max_kernel_size = max_kernel_size;
    config_response_v1_local_var->max_ramdisk_size = max_ramdisk_size;
    config_response_v1_local_var->charm_sdk = charm_sdk;
    config_response_v1_local_var->trial = trial;
    config_response_v1_local_var->sentry_url = sentry_url;
    config_response_v1_local_var->domain_authentication_providers = domain_authentication_providers;
    config_response_v1_local_var->default_ssid = default_ssid;
    config_response_v1_local_var->coordinator_config = coordinator_config;

    config_response_v1_local_var->_library_owned = 1;
    return config_response_v1_local_var;
}

__attribute__((deprecated)) config_response_v1_t *config_response_v1_create(
    int on_site,
    list_t *network_types,
    char *network_type,
    int show_domain_settings,
    char *version,
    int invalid_build,
    int sep_sim,
    int installer_available,
    char *invoiced_publishable_key,
    char *stripe_public_key,
    char *intercom_id,
    char *aux_webhook,
    char *gtm_id,
    char *zapier_feedback_webhook,
    char *zapier_bugs_webhook,
    char *billing_backend,
    object_t *maintenance,
    logging_v1_t *logging,
    char *cloud_admin,
    char *files_admin,
    char *cloud_domain,
    char *billing_domain,
    char *app_domain,
    char *max_network_monitor_file_size,
    int enable_firmware_image_upload,
    list_t *auth_providers,
    double snapshot_limit,
    double max_kernel_size,
    double max_ramdisk_size,
    int charm_sdk,
    trial_v1_t *trial,
    char *sentry_url,
    int domain_authentication_providers,
    char *default_ssid,
    coordinator_config_v1_t *coordinator_config
    ) {
    return config_response_v1_create_internal (
        on_site,
        network_types,
        network_type,
        show_domain_settings,
        version,
        invalid_build,
        sep_sim,
        installer_available,
        invoiced_publishable_key,
        stripe_public_key,
        intercom_id,
        aux_webhook,
        gtm_id,
        zapier_feedback_webhook,
        zapier_bugs_webhook,
        billing_backend,
        maintenance,
        logging,
        cloud_admin,
        files_admin,
        cloud_domain,
        billing_domain,
        app_domain,
        max_network_monitor_file_size,
        enable_firmware_image_upload,
        auth_providers,
        snapshot_limit,
        max_kernel_size,
        max_ramdisk_size,
        charm_sdk,
        trial,
        sentry_url,
        domain_authentication_providers,
        default_ssid,
        coordinator_config
        );
}

void config_response_v1_free(config_response_v1_t *config_response_v1) {
    if(NULL == config_response_v1){
        return ;
    }
    if(config_response_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "config_response_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (config_response_v1->network_types) {
        list_ForEach(listEntry, config_response_v1->network_types) {
            free(listEntry->data);
        }
        list_freeList(config_response_v1->network_types);
        config_response_v1->network_types = NULL;
    }
    if (config_response_v1->network_type) {
        free(config_response_v1->network_type);
        config_response_v1->network_type = NULL;
    }
    if (config_response_v1->version) {
        free(config_response_v1->version);
        config_response_v1->version = NULL;
    }
    if (config_response_v1->invoiced_publishable_key) {
        free(config_response_v1->invoiced_publishable_key);
        config_response_v1->invoiced_publishable_key = NULL;
    }
    if (config_response_v1->stripe_public_key) {
        free(config_response_v1->stripe_public_key);
        config_response_v1->stripe_public_key = NULL;
    }
    if (config_response_v1->intercom_id) {
        free(config_response_v1->intercom_id);
        config_response_v1->intercom_id = NULL;
    }
    if (config_response_v1->aux_webhook) {
        free(config_response_v1->aux_webhook);
        config_response_v1->aux_webhook = NULL;
    }
    if (config_response_v1->gtm_id) {
        free(config_response_v1->gtm_id);
        config_response_v1->gtm_id = NULL;
    }
    if (config_response_v1->zapier_feedback_webhook) {
        free(config_response_v1->zapier_feedback_webhook);
        config_response_v1->zapier_feedback_webhook = NULL;
    }
    if (config_response_v1->zapier_bugs_webhook) {
        free(config_response_v1->zapier_bugs_webhook);
        config_response_v1->zapier_bugs_webhook = NULL;
    }
    if (config_response_v1->billing_backend) {
        free(config_response_v1->billing_backend);
        config_response_v1->billing_backend = NULL;
    }
    if (config_response_v1->maintenance) {
        object_free(config_response_v1->maintenance);
        config_response_v1->maintenance = NULL;
    }
    if (config_response_v1->logging) {
        logging_v1_free(config_response_v1->logging);
        config_response_v1->logging = NULL;
    }
    if (config_response_v1->cloud_admin) {
        free(config_response_v1->cloud_admin);
        config_response_v1->cloud_admin = NULL;
    }
    if (config_response_v1->files_admin) {
        free(config_response_v1->files_admin);
        config_response_v1->files_admin = NULL;
    }
    if (config_response_v1->cloud_domain) {
        free(config_response_v1->cloud_domain);
        config_response_v1->cloud_domain = NULL;
    }
    if (config_response_v1->billing_domain) {
        free(config_response_v1->billing_domain);
        config_response_v1->billing_domain = NULL;
    }
    if (config_response_v1->app_domain) {
        free(config_response_v1->app_domain);
        config_response_v1->app_domain = NULL;
    }
    if (config_response_v1->max_network_monitor_file_size) {
        free(config_response_v1->max_network_monitor_file_size);
        config_response_v1->max_network_monitor_file_size = NULL;
    }
    if (config_response_v1->auth_providers) {
        list_ForEach(listEntry, config_response_v1->auth_providers) {
            auth_provider_v1_free(listEntry->data);
        }
        list_freeList(config_response_v1->auth_providers);
        config_response_v1->auth_providers = NULL;
    }
    if (config_response_v1->trial) {
        trial_v1_free(config_response_v1->trial);
        config_response_v1->trial = NULL;
    }
    if (config_response_v1->sentry_url) {
        free(config_response_v1->sentry_url);
        config_response_v1->sentry_url = NULL;
    }
    if (config_response_v1->default_ssid) {
        free(config_response_v1->default_ssid);
        config_response_v1->default_ssid = NULL;
    }
    if (config_response_v1->coordinator_config) {
        coordinator_config_v1_free(config_response_v1->coordinator_config);
        config_response_v1->coordinator_config = NULL;
    }
    free(config_response_v1);
}

cJSON *config_response_v1_convertToJSON(config_response_v1_t *config_response_v1) {
    cJSON *item = cJSON_CreateObject();

    // config_response_v1->on_site
    if(config_response_v1->on_site) {
    if(cJSON_AddBoolToObject(item, "onSite", config_response_v1->on_site) == NULL) {
    goto fail; //Bool
    }
    }


    // config_response_v1->network_types
    if(config_response_v1->network_types) {
    cJSON *network_types = cJSON_AddArrayToObject(item, "networkTypes");
    if(network_types == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *network_typesListEntry;
    list_ForEach(network_typesListEntry, config_response_v1->network_types) {
    if(cJSON_AddStringToObject(network_types, "", network_typesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // config_response_v1->network_type
    if(config_response_v1->network_type) {
    if(cJSON_AddStringToObject(item, "networkType", config_response_v1->network_type) == NULL) {
    goto fail; //String
    }
    }


    // config_response_v1->show_domain_settings
    if(config_response_v1->show_domain_settings) {
    if(cJSON_AddBoolToObject(item, "showDomainSettings", config_response_v1->show_domain_settings) == NULL) {
    goto fail; //Bool
    }
    }


    // config_response_v1->version
    if(config_response_v1->version) {
    if(cJSON_AddStringToObject(item, "version", config_response_v1->version) == NULL) {
    goto fail; //String
    }
    }


    // config_response_v1->invalid_build
    if(config_response_v1->invalid_build) {
    if(cJSON_AddBoolToObject(item, "invalidBuild", config_response_v1->invalid_build) == NULL) {
    goto fail; //Bool
    }
    }


    // config_response_v1->sep_sim
    if(config_response_v1->sep_sim) {
    if(cJSON_AddBoolToObject(item, "sepSim", config_response_v1->sep_sim) == NULL) {
    goto fail; //Bool
    }
    }


    // config_response_v1->installer_available
    if(config_response_v1->installer_available) {
    if(cJSON_AddBoolToObject(item, "installerAvailable", config_response_v1->installer_available) == NULL) {
    goto fail; //Bool
    }
    }


    // config_response_v1->invoiced_publishable_key
    if(config_response_v1->invoiced_publishable_key) {
    if(cJSON_AddStringToObject(item, "invoicedPublishableKey", config_response_v1->invoiced_publishable_key) == NULL) {
    goto fail; //String
    }
    }


    // config_response_v1->stripe_public_key
    if(config_response_v1->stripe_public_key) {
    if(cJSON_AddStringToObject(item, "stripePublicKey", config_response_v1->stripe_public_key) == NULL) {
    goto fail; //String
    }
    }


    // config_response_v1->intercom_id
    if(config_response_v1->intercom_id) {
    if(cJSON_AddStringToObject(item, "intercomId", config_response_v1->intercom_id) == NULL) {
    goto fail; //String
    }
    }


    // config_response_v1->aux_webhook
    if(config_response_v1->aux_webhook) {
    if(cJSON_AddStringToObject(item, "auxWebhook", config_response_v1->aux_webhook) == NULL) {
    goto fail; //String
    }
    }


    // config_response_v1->gtm_id
    if(config_response_v1->gtm_id) {
    if(cJSON_AddStringToObject(item, "gtmId", config_response_v1->gtm_id) == NULL) {
    goto fail; //String
    }
    }


    // config_response_v1->zapier_feedback_webhook
    if(config_response_v1->zapier_feedback_webhook) {
    if(cJSON_AddStringToObject(item, "zapierFeedbackWebhook", config_response_v1->zapier_feedback_webhook) == NULL) {
    goto fail; //String
    }
    }


    // config_response_v1->zapier_bugs_webhook
    if(config_response_v1->zapier_bugs_webhook) {
    if(cJSON_AddStringToObject(item, "zapierBugsWebhook", config_response_v1->zapier_bugs_webhook) == NULL) {
    goto fail; //String
    }
    }


    // config_response_v1->billing_backend
    if(config_response_v1->billing_backend) {
    if(cJSON_AddStringToObject(item, "billingBackend", config_response_v1->billing_backend) == NULL) {
    goto fail; //String
    }
    }


    // config_response_v1->maintenance
    if(config_response_v1->maintenance) {
    cJSON *maintenance_object = object_convertToJSON(config_response_v1->maintenance);
    if(maintenance_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "maintenance", maintenance_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // config_response_v1->logging
    if(config_response_v1->logging) {
    cJSON *logging_local_JSON = logging_v1_convertToJSON(config_response_v1->logging);
    if(logging_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "logging", logging_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // config_response_v1->cloud_admin
    if(config_response_v1->cloud_admin) {
    if(cJSON_AddStringToObject(item, "cloudAdmin", config_response_v1->cloud_admin) == NULL) {
    goto fail; //String
    }
    }


    // config_response_v1->files_admin
    if(config_response_v1->files_admin) {
    if(cJSON_AddStringToObject(item, "filesAdmin", config_response_v1->files_admin) == NULL) {
    goto fail; //String
    }
    }


    // config_response_v1->cloud_domain
    if(config_response_v1->cloud_domain) {
    if(cJSON_AddStringToObject(item, "cloudDomain", config_response_v1->cloud_domain) == NULL) {
    goto fail; //String
    }
    }


    // config_response_v1->billing_domain
    if(config_response_v1->billing_domain) {
    if(cJSON_AddStringToObject(item, "billingDomain", config_response_v1->billing_domain) == NULL) {
    goto fail; //String
    }
    }


    // config_response_v1->app_domain
    if(config_response_v1->app_domain) {
    if(cJSON_AddStringToObject(item, "appDomain", config_response_v1->app_domain) == NULL) {
    goto fail; //String
    }
    }


    // config_response_v1->max_network_monitor_file_size
    if(config_response_v1->max_network_monitor_file_size) {
    if(cJSON_AddStringToObject(item, "maxNetworkMonitorFileSize", config_response_v1->max_network_monitor_file_size) == NULL) {
    goto fail; //String
    }
    }


    // config_response_v1->enable_firmware_image_upload
    if(config_response_v1->enable_firmware_image_upload) {
    if(cJSON_AddBoolToObject(item, "enableFirmwareImageUpload", config_response_v1->enable_firmware_image_upload) == NULL) {
    goto fail; //Bool
    }
    }


    // config_response_v1->auth_providers
    if(config_response_v1->auth_providers) {
    cJSON *auth_providers = cJSON_AddArrayToObject(item, "authProviders");
    if(auth_providers == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *auth_providersListEntry;
    if (config_response_v1->auth_providers) {
    list_ForEach(auth_providersListEntry, config_response_v1->auth_providers) {
    cJSON *itemLocal = auth_provider_v1_convertToJSON(auth_providersListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(auth_providers, itemLocal);
    }
    }
    }


    // config_response_v1->snapshot_limit
    if(config_response_v1->snapshot_limit) {
    if(cJSON_AddNumberToObject(item, "snapshotLimit", config_response_v1->snapshot_limit) == NULL) {
    goto fail; //Numeric
    }
    }


    // config_response_v1->max_kernel_size
    if(config_response_v1->max_kernel_size) {
    if(cJSON_AddNumberToObject(item, "maxKernelSize", config_response_v1->max_kernel_size) == NULL) {
    goto fail; //Numeric
    }
    }


    // config_response_v1->max_ramdisk_size
    if(config_response_v1->max_ramdisk_size) {
    if(cJSON_AddNumberToObject(item, "maxRamdiskSize", config_response_v1->max_ramdisk_size) == NULL) {
    goto fail; //Numeric
    }
    }


    // config_response_v1->charm_sdk
    if(config_response_v1->charm_sdk) {
    if(cJSON_AddBoolToObject(item, "charmSDK", config_response_v1->charm_sdk) == NULL) {
    goto fail; //Bool
    }
    }


    // config_response_v1->trial
    if(config_response_v1->trial) {
    cJSON *trial_local_JSON = trial_v1_convertToJSON(config_response_v1->trial);
    if(trial_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "trial", trial_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // config_response_v1->sentry_url
    if(config_response_v1->sentry_url) {
    if(cJSON_AddStringToObject(item, "sentryUrl", config_response_v1->sentry_url) == NULL) {
    goto fail; //String
    }
    }


    // config_response_v1->domain_authentication_providers
    if(config_response_v1->domain_authentication_providers) {
    if(cJSON_AddBoolToObject(item, "domainAuthenticationProviders", config_response_v1->domain_authentication_providers) == NULL) {
    goto fail; //Bool
    }
    }


    // config_response_v1->default_ssid
    if(config_response_v1->default_ssid) {
    if(cJSON_AddStringToObject(item, "defaultSsid", config_response_v1->default_ssid) == NULL) {
    goto fail; //String
    }
    }


    // config_response_v1->coordinator_config
    if(config_response_v1->coordinator_config) {
    cJSON *coordinator_config_local_JSON = coordinator_config_v1_convertToJSON(config_response_v1->coordinator_config);
    if(coordinator_config_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "coordinatorConfig", coordinator_config_local_JSON);
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

config_response_v1_t *config_response_v1_parseFromJSON(cJSON *config_response_v1JSON){

    config_response_v1_t *config_response_v1_local_var = NULL;

    // define the local list for config_response_v1->network_types
    list_t *network_typesList = NULL;

    // define the local variable for config_response_v1->logging
    logging_v1_t *logging_local_nonprim = NULL;

    // define the local list for config_response_v1->auth_providers
    list_t *auth_providersList = NULL;

    // define the local variable for config_response_v1->trial
    trial_v1_t *trial_local_nonprim = NULL;

    // define the local variable for config_response_v1->coordinator_config
    coordinator_config_v1_t *coordinator_config_local_nonprim = NULL;

    // config_response_v1->on_site
    cJSON *on_site = cJSON_GetObjectItemCaseSensitive(config_response_v1JSON, "onSite");
    if (cJSON_IsNull(on_site)) {
        on_site = NULL;
    }
    if (on_site) { 
    if(!cJSON_IsBool(on_site))
    {
    goto end; //Bool
    }
    }

    // config_response_v1->network_types
    cJSON *network_types = cJSON_GetObjectItemCaseSensitive(config_response_v1JSON, "networkTypes");
    if (cJSON_IsNull(network_types)) {
        network_types = NULL;
    }
    if (network_types) { 
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
    }

    // config_response_v1->network_type
    cJSON *network_type = cJSON_GetObjectItemCaseSensitive(config_response_v1JSON, "networkType");
    if (cJSON_IsNull(network_type)) {
        network_type = NULL;
    }
    if (network_type) { 
    if(!cJSON_IsString(network_type) && !cJSON_IsNull(network_type))
    {
    goto end; //String
    }
    }

    // config_response_v1->show_domain_settings
    cJSON *show_domain_settings = cJSON_GetObjectItemCaseSensitive(config_response_v1JSON, "showDomainSettings");
    if (cJSON_IsNull(show_domain_settings)) {
        show_domain_settings = NULL;
    }
    if (show_domain_settings) { 
    if(!cJSON_IsBool(show_domain_settings))
    {
    goto end; //Bool
    }
    }

    // config_response_v1->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(config_response_v1JSON, "version");
    if (cJSON_IsNull(version)) {
        version = NULL;
    }
    if (version) { 
    if(!cJSON_IsString(version) && !cJSON_IsNull(version))
    {
    goto end; //String
    }
    }

    // config_response_v1->invalid_build
    cJSON *invalid_build = cJSON_GetObjectItemCaseSensitive(config_response_v1JSON, "invalidBuild");
    if (cJSON_IsNull(invalid_build)) {
        invalid_build = NULL;
    }
    if (invalid_build) { 
    if(!cJSON_IsBool(invalid_build))
    {
    goto end; //Bool
    }
    }

    // config_response_v1->sep_sim
    cJSON *sep_sim = cJSON_GetObjectItemCaseSensitive(config_response_v1JSON, "sepSim");
    if (cJSON_IsNull(sep_sim)) {
        sep_sim = NULL;
    }
    if (sep_sim) { 
    if(!cJSON_IsBool(sep_sim))
    {
    goto end; //Bool
    }
    }

    // config_response_v1->installer_available
    cJSON *installer_available = cJSON_GetObjectItemCaseSensitive(config_response_v1JSON, "installerAvailable");
    if (cJSON_IsNull(installer_available)) {
        installer_available = NULL;
    }
    if (installer_available) { 
    if(!cJSON_IsBool(installer_available))
    {
    goto end; //Bool
    }
    }

    // config_response_v1->invoiced_publishable_key
    cJSON *invoiced_publishable_key = cJSON_GetObjectItemCaseSensitive(config_response_v1JSON, "invoicedPublishableKey");
    if (cJSON_IsNull(invoiced_publishable_key)) {
        invoiced_publishable_key = NULL;
    }
    if (invoiced_publishable_key) { 
    if(!cJSON_IsString(invoiced_publishable_key) && !cJSON_IsNull(invoiced_publishable_key))
    {
    goto end; //String
    }
    }

    // config_response_v1->stripe_public_key
    cJSON *stripe_public_key = cJSON_GetObjectItemCaseSensitive(config_response_v1JSON, "stripePublicKey");
    if (cJSON_IsNull(stripe_public_key)) {
        stripe_public_key = NULL;
    }
    if (stripe_public_key) { 
    if(!cJSON_IsString(stripe_public_key) && !cJSON_IsNull(stripe_public_key))
    {
    goto end; //String
    }
    }

    // config_response_v1->intercom_id
    cJSON *intercom_id = cJSON_GetObjectItemCaseSensitive(config_response_v1JSON, "intercomId");
    if (cJSON_IsNull(intercom_id)) {
        intercom_id = NULL;
    }
    if (intercom_id) { 
    if(!cJSON_IsString(intercom_id) && !cJSON_IsNull(intercom_id))
    {
    goto end; //String
    }
    }

    // config_response_v1->aux_webhook
    cJSON *aux_webhook = cJSON_GetObjectItemCaseSensitive(config_response_v1JSON, "auxWebhook");
    if (cJSON_IsNull(aux_webhook)) {
        aux_webhook = NULL;
    }
    if (aux_webhook) { 
    if(!cJSON_IsString(aux_webhook) && !cJSON_IsNull(aux_webhook))
    {
    goto end; //String
    }
    }

    // config_response_v1->gtm_id
    cJSON *gtm_id = cJSON_GetObjectItemCaseSensitive(config_response_v1JSON, "gtmId");
    if (cJSON_IsNull(gtm_id)) {
        gtm_id = NULL;
    }
    if (gtm_id) { 
    if(!cJSON_IsString(gtm_id) && !cJSON_IsNull(gtm_id))
    {
    goto end; //String
    }
    }

    // config_response_v1->zapier_feedback_webhook
    cJSON *zapier_feedback_webhook = cJSON_GetObjectItemCaseSensitive(config_response_v1JSON, "zapierFeedbackWebhook");
    if (cJSON_IsNull(zapier_feedback_webhook)) {
        zapier_feedback_webhook = NULL;
    }
    if (zapier_feedback_webhook) { 
    if(!cJSON_IsString(zapier_feedback_webhook) && !cJSON_IsNull(zapier_feedback_webhook))
    {
    goto end; //String
    }
    }

    // config_response_v1->zapier_bugs_webhook
    cJSON *zapier_bugs_webhook = cJSON_GetObjectItemCaseSensitive(config_response_v1JSON, "zapierBugsWebhook");
    if (cJSON_IsNull(zapier_bugs_webhook)) {
        zapier_bugs_webhook = NULL;
    }
    if (zapier_bugs_webhook) { 
    if(!cJSON_IsString(zapier_bugs_webhook) && !cJSON_IsNull(zapier_bugs_webhook))
    {
    goto end; //String
    }
    }

    // config_response_v1->billing_backend
    cJSON *billing_backend = cJSON_GetObjectItemCaseSensitive(config_response_v1JSON, "billingBackend");
    if (cJSON_IsNull(billing_backend)) {
        billing_backend = NULL;
    }
    if (billing_backend) { 
    if(!cJSON_IsString(billing_backend) && !cJSON_IsNull(billing_backend))
    {
    goto end; //String
    }
    }

    // config_response_v1->maintenance
    cJSON *maintenance = cJSON_GetObjectItemCaseSensitive(config_response_v1JSON, "maintenance");
    if (cJSON_IsNull(maintenance)) {
        maintenance = NULL;
    }
    object_t *maintenance_local_object = NULL;
    if (maintenance) { 
    maintenance_local_object = object_parseFromJSON(maintenance); //object
    }

    // config_response_v1->logging
    cJSON *logging = cJSON_GetObjectItemCaseSensitive(config_response_v1JSON, "logging");
    if (cJSON_IsNull(logging)) {
        logging = NULL;
    }
    if (logging) { 
    logging_local_nonprim = logging_v1_parseFromJSON(logging); //nonprimitive
    }

    // config_response_v1->cloud_admin
    cJSON *cloud_admin = cJSON_GetObjectItemCaseSensitive(config_response_v1JSON, "cloudAdmin");
    if (cJSON_IsNull(cloud_admin)) {
        cloud_admin = NULL;
    }
    if (cloud_admin) { 
    if(!cJSON_IsString(cloud_admin) && !cJSON_IsNull(cloud_admin))
    {
    goto end; //String
    }
    }

    // config_response_v1->files_admin
    cJSON *files_admin = cJSON_GetObjectItemCaseSensitive(config_response_v1JSON, "filesAdmin");
    if (cJSON_IsNull(files_admin)) {
        files_admin = NULL;
    }
    if (files_admin) { 
    if(!cJSON_IsString(files_admin) && !cJSON_IsNull(files_admin))
    {
    goto end; //String
    }
    }

    // config_response_v1->cloud_domain
    cJSON *cloud_domain = cJSON_GetObjectItemCaseSensitive(config_response_v1JSON, "cloudDomain");
    if (cJSON_IsNull(cloud_domain)) {
        cloud_domain = NULL;
    }
    if (cloud_domain) { 
    if(!cJSON_IsString(cloud_domain) && !cJSON_IsNull(cloud_domain))
    {
    goto end; //String
    }
    }

    // config_response_v1->billing_domain
    cJSON *billing_domain = cJSON_GetObjectItemCaseSensitive(config_response_v1JSON, "billingDomain");
    if (cJSON_IsNull(billing_domain)) {
        billing_domain = NULL;
    }
    if (billing_domain) { 
    if(!cJSON_IsString(billing_domain) && !cJSON_IsNull(billing_domain))
    {
    goto end; //String
    }
    }

    // config_response_v1->app_domain
    cJSON *app_domain = cJSON_GetObjectItemCaseSensitive(config_response_v1JSON, "appDomain");
    if (cJSON_IsNull(app_domain)) {
        app_domain = NULL;
    }
    if (app_domain) { 
    if(!cJSON_IsString(app_domain) && !cJSON_IsNull(app_domain))
    {
    goto end; //String
    }
    }

    // config_response_v1->max_network_monitor_file_size
    cJSON *max_network_monitor_file_size = cJSON_GetObjectItemCaseSensitive(config_response_v1JSON, "maxNetworkMonitorFileSize");
    if (cJSON_IsNull(max_network_monitor_file_size)) {
        max_network_monitor_file_size = NULL;
    }
    if (max_network_monitor_file_size) { 
    if(!cJSON_IsString(max_network_monitor_file_size) && !cJSON_IsNull(max_network_monitor_file_size))
    {
    goto end; //String
    }
    }

    // config_response_v1->enable_firmware_image_upload
    cJSON *enable_firmware_image_upload = cJSON_GetObjectItemCaseSensitive(config_response_v1JSON, "enableFirmwareImageUpload");
    if (cJSON_IsNull(enable_firmware_image_upload)) {
        enable_firmware_image_upload = NULL;
    }
    if (enable_firmware_image_upload) { 
    if(!cJSON_IsBool(enable_firmware_image_upload))
    {
    goto end; //Bool
    }
    }

    // config_response_v1->auth_providers
    cJSON *auth_providers = cJSON_GetObjectItemCaseSensitive(config_response_v1JSON, "authProviders");
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
        auth_provider_v1_t *auth_providersItem = auth_provider_v1_parseFromJSON(auth_providers_local_nonprimitive);

        list_addElement(auth_providersList, auth_providersItem);
    }
    }

    // config_response_v1->snapshot_limit
    cJSON *snapshot_limit = cJSON_GetObjectItemCaseSensitive(config_response_v1JSON, "snapshotLimit");
    if (cJSON_IsNull(snapshot_limit)) {
        snapshot_limit = NULL;
    }
    if (snapshot_limit) { 
    if(!cJSON_IsNumber(snapshot_limit))
    {
    goto end; //Numeric
    }
    }

    // config_response_v1->max_kernel_size
    cJSON *max_kernel_size = cJSON_GetObjectItemCaseSensitive(config_response_v1JSON, "maxKernelSize");
    if (cJSON_IsNull(max_kernel_size)) {
        max_kernel_size = NULL;
    }
    if (max_kernel_size) { 
    if(!cJSON_IsNumber(max_kernel_size))
    {
    goto end; //Numeric
    }
    }

    // config_response_v1->max_ramdisk_size
    cJSON *max_ramdisk_size = cJSON_GetObjectItemCaseSensitive(config_response_v1JSON, "maxRamdiskSize");
    if (cJSON_IsNull(max_ramdisk_size)) {
        max_ramdisk_size = NULL;
    }
    if (max_ramdisk_size) { 
    if(!cJSON_IsNumber(max_ramdisk_size))
    {
    goto end; //Numeric
    }
    }

    // config_response_v1->charm_sdk
    cJSON *charm_sdk = cJSON_GetObjectItemCaseSensitive(config_response_v1JSON, "charmSDK");
    if (cJSON_IsNull(charm_sdk)) {
        charm_sdk = NULL;
    }
    if (charm_sdk) { 
    if(!cJSON_IsBool(charm_sdk))
    {
    goto end; //Bool
    }
    }

    // config_response_v1->trial
    cJSON *trial = cJSON_GetObjectItemCaseSensitive(config_response_v1JSON, "trial");
    if (cJSON_IsNull(trial)) {
        trial = NULL;
    }
    if (trial) { 
    trial_local_nonprim = trial_v1_parseFromJSON(trial); //nonprimitive
    }

    // config_response_v1->sentry_url
    cJSON *sentry_url = cJSON_GetObjectItemCaseSensitive(config_response_v1JSON, "sentryUrl");
    if (cJSON_IsNull(sentry_url)) {
        sentry_url = NULL;
    }
    if (sentry_url) { 
    if(!cJSON_IsString(sentry_url) && !cJSON_IsNull(sentry_url))
    {
    goto end; //String
    }
    }

    // config_response_v1->domain_authentication_providers
    cJSON *domain_authentication_providers = cJSON_GetObjectItemCaseSensitive(config_response_v1JSON, "domainAuthenticationProviders");
    if (cJSON_IsNull(domain_authentication_providers)) {
        domain_authentication_providers = NULL;
    }
    if (domain_authentication_providers) { 
    if(!cJSON_IsBool(domain_authentication_providers))
    {
    goto end; //Bool
    }
    }

    // config_response_v1->default_ssid
    cJSON *default_ssid = cJSON_GetObjectItemCaseSensitive(config_response_v1JSON, "defaultSsid");
    if (cJSON_IsNull(default_ssid)) {
        default_ssid = NULL;
    }
    if (default_ssid) { 
    if(!cJSON_IsString(default_ssid) && !cJSON_IsNull(default_ssid))
    {
    goto end; //String
    }
    }

    // config_response_v1->coordinator_config
    cJSON *coordinator_config = cJSON_GetObjectItemCaseSensitive(config_response_v1JSON, "coordinatorConfig");
    if (cJSON_IsNull(coordinator_config)) {
        coordinator_config = NULL;
    }
    if (coordinator_config) { 
    coordinator_config_local_nonprim = coordinator_config_v1_parseFromJSON(coordinator_config); //nonprimitive
    }


    config_response_v1_local_var = config_response_v1_create_internal (
        on_site ? on_site->valueint : 0,
        network_types ? network_typesList : NULL,
        network_type && !cJSON_IsNull(network_type) ? strdup(network_type->valuestring) : NULL,
        show_domain_settings ? show_domain_settings->valueint : 0,
        version && !cJSON_IsNull(version) ? strdup(version->valuestring) : NULL,
        invalid_build ? invalid_build->valueint : 0,
        sep_sim ? sep_sim->valueint : 0,
        installer_available ? installer_available->valueint : 0,
        invoiced_publishable_key && !cJSON_IsNull(invoiced_publishable_key) ? strdup(invoiced_publishable_key->valuestring) : NULL,
        stripe_public_key && !cJSON_IsNull(stripe_public_key) ? strdup(stripe_public_key->valuestring) : NULL,
        intercom_id && !cJSON_IsNull(intercom_id) ? strdup(intercom_id->valuestring) : NULL,
        aux_webhook && !cJSON_IsNull(aux_webhook) ? strdup(aux_webhook->valuestring) : NULL,
        gtm_id && !cJSON_IsNull(gtm_id) ? strdup(gtm_id->valuestring) : NULL,
        zapier_feedback_webhook && !cJSON_IsNull(zapier_feedback_webhook) ? strdup(zapier_feedback_webhook->valuestring) : NULL,
        zapier_bugs_webhook && !cJSON_IsNull(zapier_bugs_webhook) ? strdup(zapier_bugs_webhook->valuestring) : NULL,
        billing_backend && !cJSON_IsNull(billing_backend) ? strdup(billing_backend->valuestring) : NULL,
        maintenance ? maintenance_local_object : NULL,
        logging ? logging_local_nonprim : NULL,
        cloud_admin && !cJSON_IsNull(cloud_admin) ? strdup(cloud_admin->valuestring) : NULL,
        files_admin && !cJSON_IsNull(files_admin) ? strdup(files_admin->valuestring) : NULL,
        cloud_domain && !cJSON_IsNull(cloud_domain) ? strdup(cloud_domain->valuestring) : NULL,
        billing_domain && !cJSON_IsNull(billing_domain) ? strdup(billing_domain->valuestring) : NULL,
        app_domain && !cJSON_IsNull(app_domain) ? strdup(app_domain->valuestring) : NULL,
        max_network_monitor_file_size && !cJSON_IsNull(max_network_monitor_file_size) ? strdup(max_network_monitor_file_size->valuestring) : NULL,
        enable_firmware_image_upload ? enable_firmware_image_upload->valueint : 0,
        auth_providers ? auth_providersList : NULL,
        snapshot_limit ? snapshot_limit->valuedouble : 0,
        max_kernel_size ? max_kernel_size->valuedouble : 0,
        max_ramdisk_size ? max_ramdisk_size->valuedouble : 0,
        charm_sdk ? charm_sdk->valueint : 0,
        trial ? trial_local_nonprim : NULL,
        sentry_url && !cJSON_IsNull(sentry_url) ? strdup(sentry_url->valuestring) : NULL,
        domain_authentication_providers ? domain_authentication_providers->valueint : 0,
        default_ssid && !cJSON_IsNull(default_ssid) ? strdup(default_ssid->valuestring) : NULL,
        coordinator_config ? coordinator_config_local_nonprim : NULL
        );

    return config_response_v1_local_var;
end:
    if (network_typesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, network_typesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(network_typesList);
        network_typesList = NULL;
    }
    if (logging_local_nonprim) {
        logging_v1_free(logging_local_nonprim);
        logging_local_nonprim = NULL;
    }
    if (auth_providersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, auth_providersList) {
            auth_provider_v1_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(auth_providersList);
        auth_providersList = NULL;
    }
    if (trial_local_nonprim) {
        trial_v1_free(trial_local_nonprim);
        trial_local_nonprim = NULL;
    }
    if (coordinator_config_local_nonprim) {
        coordinator_config_v1_free(coordinator_config_local_nonprim);
        coordinator_config_local_nonprim = NULL;
    }
    return NULL;

}
