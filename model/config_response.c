#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "config_response.h"


char* config_response_network_type_ToString(corellium_api_config_response_NETWORKTYPE_e network_type) {
    char* network_typeArray[] =  { "NULL", "bridged", "nat", "routed" };
    return network_typeArray[network_type];
}

corellium_api_config_response_NETWORKTYPE_e config_response_network_type_FromString(char* network_type){
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

static config_response_t *config_response_create_internal(
    int on_site,
    list_t *network_types,
    corellium_api_config_response_NETWORKTYPE_e network_type,
    int show_domain_settings,
    char *version,
    int invalid_build,
    int sep_sim,
    int installer_available,
    char *invoiced_publishable_key,
    char *stripe_public_key,
    char *intercom_id,
    char *gtm_id,
    char *billing_backend,
    config_response_maintenance_t *maintenance,
    logging_t *logging,
    char *cloud_admin,
    char *files_admin,
    char *cloud_domain,
    char *billing_domain,
    char *app_domain,
    char *max_network_monitor_file_size,
    int enable_firmware_image_upload,
    list_t *auth_providers,
    char *welcome_message,
    double snapshot_limit,
    double max_kernel_size,
    double max_ramdisk_size,
    int charm_sdk,
    trial_t *trial,
    char *sentry_url,
    int domain_authentication_providers,
    int remote_gpu,
    char *default_ssid,
    int aws_marketplace,
    char *open_g_apps_binary,
    int air_gapped,
    config_response_coordinator_config_t *coordinator_config
    ) {
    config_response_t *config_response_local_var = malloc(sizeof(config_response_t));
    if (!config_response_local_var) {
        return NULL;
    }
    config_response_local_var->on_site = on_site;
    config_response_local_var->network_types = network_types;
    config_response_local_var->network_type = network_type;
    config_response_local_var->show_domain_settings = show_domain_settings;
    config_response_local_var->version = version;
    config_response_local_var->invalid_build = invalid_build;
    config_response_local_var->sep_sim = sep_sim;
    config_response_local_var->installer_available = installer_available;
    config_response_local_var->invoiced_publishable_key = invoiced_publishable_key;
    config_response_local_var->stripe_public_key = stripe_public_key;
    config_response_local_var->intercom_id = intercom_id;
    config_response_local_var->gtm_id = gtm_id;
    config_response_local_var->billing_backend = billing_backend;
    config_response_local_var->maintenance = maintenance;
    config_response_local_var->logging = logging;
    config_response_local_var->cloud_admin = cloud_admin;
    config_response_local_var->files_admin = files_admin;
    config_response_local_var->cloud_domain = cloud_domain;
    config_response_local_var->billing_domain = billing_domain;
    config_response_local_var->app_domain = app_domain;
    config_response_local_var->max_network_monitor_file_size = max_network_monitor_file_size;
    config_response_local_var->enable_firmware_image_upload = enable_firmware_image_upload;
    config_response_local_var->auth_providers = auth_providers;
    config_response_local_var->welcome_message = welcome_message;
    config_response_local_var->snapshot_limit = snapshot_limit;
    config_response_local_var->max_kernel_size = max_kernel_size;
    config_response_local_var->max_ramdisk_size = max_ramdisk_size;
    config_response_local_var->charm_sdk = charm_sdk;
    config_response_local_var->trial = trial;
    config_response_local_var->sentry_url = sentry_url;
    config_response_local_var->domain_authentication_providers = domain_authentication_providers;
    config_response_local_var->remote_gpu = remote_gpu;
    config_response_local_var->default_ssid = default_ssid;
    config_response_local_var->aws_marketplace = aws_marketplace;
    config_response_local_var->open_g_apps_binary = open_g_apps_binary;
    config_response_local_var->air_gapped = air_gapped;
    config_response_local_var->coordinator_config = coordinator_config;

    config_response_local_var->_library_owned = 1;
    return config_response_local_var;
}

__attribute__((deprecated)) config_response_t *config_response_create(
    int on_site,
    list_t *network_types,
    corellium_api_config_response_NETWORKTYPE_e network_type,
    int show_domain_settings,
    char *version,
    int invalid_build,
    int sep_sim,
    int installer_available,
    char *invoiced_publishable_key,
    char *stripe_public_key,
    char *intercom_id,
    char *gtm_id,
    char *billing_backend,
    config_response_maintenance_t *maintenance,
    logging_t *logging,
    char *cloud_admin,
    char *files_admin,
    char *cloud_domain,
    char *billing_domain,
    char *app_domain,
    char *max_network_monitor_file_size,
    int enable_firmware_image_upload,
    list_t *auth_providers,
    char *welcome_message,
    double snapshot_limit,
    double max_kernel_size,
    double max_ramdisk_size,
    int charm_sdk,
    trial_t *trial,
    char *sentry_url,
    int domain_authentication_providers,
    int remote_gpu,
    char *default_ssid,
    int aws_marketplace,
    char *open_g_apps_binary,
    int air_gapped,
    config_response_coordinator_config_t *coordinator_config
    ) {
    return config_response_create_internal (
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
        gtm_id,
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
        welcome_message,
        snapshot_limit,
        max_kernel_size,
        max_ramdisk_size,
        charm_sdk,
        trial,
        sentry_url,
        domain_authentication_providers,
        remote_gpu,
        default_ssid,
        aws_marketplace,
        open_g_apps_binary,
        air_gapped,
        coordinator_config
        );
}

void config_response_free(config_response_t *config_response) {
    if(NULL == config_response){
        return ;
    }
    if(config_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "config_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (config_response->network_types) {
        list_ForEach(listEntry, config_response->network_types) {
            free(listEntry->data);
        }
        list_freeList(config_response->network_types);
        config_response->network_types = NULL;
    }
    if (config_response->version) {
        free(config_response->version);
        config_response->version = NULL;
    }
    if (config_response->invoiced_publishable_key) {
        free(config_response->invoiced_publishable_key);
        config_response->invoiced_publishable_key = NULL;
    }
    if (config_response->stripe_public_key) {
        free(config_response->stripe_public_key);
        config_response->stripe_public_key = NULL;
    }
    if (config_response->intercom_id) {
        free(config_response->intercom_id);
        config_response->intercom_id = NULL;
    }
    if (config_response->gtm_id) {
        free(config_response->gtm_id);
        config_response->gtm_id = NULL;
    }
    if (config_response->billing_backend) {
        free(config_response->billing_backend);
        config_response->billing_backend = NULL;
    }
    if (config_response->maintenance) {
        config_response_maintenance_free(config_response->maintenance);
        config_response->maintenance = NULL;
    }
    if (config_response->logging) {
        logging_free(config_response->logging);
        config_response->logging = NULL;
    }
    if (config_response->cloud_admin) {
        free(config_response->cloud_admin);
        config_response->cloud_admin = NULL;
    }
    if (config_response->files_admin) {
        free(config_response->files_admin);
        config_response->files_admin = NULL;
    }
    if (config_response->cloud_domain) {
        free(config_response->cloud_domain);
        config_response->cloud_domain = NULL;
    }
    if (config_response->billing_domain) {
        free(config_response->billing_domain);
        config_response->billing_domain = NULL;
    }
    if (config_response->app_domain) {
        free(config_response->app_domain);
        config_response->app_domain = NULL;
    }
    if (config_response->max_network_monitor_file_size) {
        free(config_response->max_network_monitor_file_size);
        config_response->max_network_monitor_file_size = NULL;
    }
    if (config_response->auth_providers) {
        list_ForEach(listEntry, config_response->auth_providers) {
            config_auth_provider_free(listEntry->data);
        }
        list_freeList(config_response->auth_providers);
        config_response->auth_providers = NULL;
    }
    if (config_response->welcome_message) {
        free(config_response->welcome_message);
        config_response->welcome_message = NULL;
    }
    if (config_response->trial) {
        trial_free(config_response->trial);
        config_response->trial = NULL;
    }
    if (config_response->sentry_url) {
        free(config_response->sentry_url);
        config_response->sentry_url = NULL;
    }
    if (config_response->default_ssid) {
        free(config_response->default_ssid);
        config_response->default_ssid = NULL;
    }
    if (config_response->open_g_apps_binary) {
        free(config_response->open_g_apps_binary);
        config_response->open_g_apps_binary = NULL;
    }
    if (config_response->coordinator_config) {
        config_response_coordinator_config_free(config_response->coordinator_config);
        config_response->coordinator_config = NULL;
    }
    free(config_response);
}

cJSON *config_response_convertToJSON(config_response_t *config_response) {
    cJSON *item = cJSON_CreateObject();

    // config_response->on_site
    if (!config_response->on_site) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "onSite", config_response->on_site) == NULL) {
    goto fail; //Bool
    }


    // config_response->network_types
    if(config_response->network_types) {
    cJSON *network_types = cJSON_AddArrayToObject(item, "networkTypes");
    if(network_types == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *network_typesListEntry;
    list_ForEach(network_typesListEntry, config_response->network_types) {
    if(cJSON_AddStringToObject(network_types, "", network_typesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // config_response->network_type
    if (corellium_api_config_response_NETWORKTYPE_NULL == config_response->network_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "networkType", config_response_network_type_ToString(config_response->network_type)) == NULL)
    {
    goto fail; //Enum
    }


    // config_response->show_domain_settings
    if (!config_response->show_domain_settings) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "showDomainSettings", config_response->show_domain_settings) == NULL) {
    goto fail; //Bool
    }


    // config_response->version
    if (!config_response->version) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "version", config_response->version) == NULL) {
    goto fail; //String
    }


    // config_response->invalid_build
    if(config_response->invalid_build) {
    if(cJSON_AddBoolToObject(item, "invalidBuild", config_response->invalid_build) == NULL) {
    goto fail; //Bool
    }
    }


    // config_response->sep_sim
    if (!config_response->sep_sim) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "sepSim", config_response->sep_sim) == NULL) {
    goto fail; //Bool
    }


    // config_response->installer_available
    if (!config_response->installer_available) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "installerAvailable", config_response->installer_available) == NULL) {
    goto fail; //Bool
    }


    // config_response->invoiced_publishable_key
    if(config_response->invoiced_publishable_key) {
    if(cJSON_AddStringToObject(item, "invoicedPublishableKey", config_response->invoiced_publishable_key) == NULL) {
    goto fail; //String
    }
    }


    // config_response->stripe_public_key
    if(config_response->stripe_public_key) {
    if(cJSON_AddStringToObject(item, "stripePublicKey", config_response->stripe_public_key) == NULL) {
    goto fail; //String
    }
    }


    // config_response->intercom_id
    if(config_response->intercom_id) {
    if(cJSON_AddStringToObject(item, "intercomId", config_response->intercom_id) == NULL) {
    goto fail; //String
    }
    }


    // config_response->gtm_id
    if(config_response->gtm_id) {
    if(cJSON_AddStringToObject(item, "gtmId", config_response->gtm_id) == NULL) {
    goto fail; //String
    }
    }


    // config_response->billing_backend
    if(config_response->billing_backend) {
    if(cJSON_AddStringToObject(item, "billingBackend", config_response->billing_backend) == NULL) {
    goto fail; //String
    }
    }


    // config_response->maintenance
    if(config_response->maintenance) {
    cJSON *maintenance_local_JSON = config_response_maintenance_convertToJSON(config_response->maintenance);
    if(maintenance_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "maintenance", maintenance_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // config_response->logging
    if(config_response->logging) {
    cJSON *logging_local_JSON = logging_convertToJSON(config_response->logging);
    if(logging_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "logging", logging_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // config_response->cloud_admin
    if (!config_response->cloud_admin) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "cloudAdmin", config_response->cloud_admin) == NULL) {
    goto fail; //String
    }


    // config_response->files_admin
    if (!config_response->files_admin) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "filesAdmin", config_response->files_admin) == NULL) {
    goto fail; //String
    }


    // config_response->cloud_domain
    if(config_response->cloud_domain) {
    if(cJSON_AddStringToObject(item, "cloudDomain", config_response->cloud_domain) == NULL) {
    goto fail; //String
    }
    }


    // config_response->billing_domain
    if(config_response->billing_domain) {
    if(cJSON_AddStringToObject(item, "billingDomain", config_response->billing_domain) == NULL) {
    goto fail; //String
    }
    }


    // config_response->app_domain
    if(config_response->app_domain) {
    if(cJSON_AddStringToObject(item, "appDomain", config_response->app_domain) == NULL) {
    goto fail; //String
    }
    }


    // config_response->max_network_monitor_file_size
    if (!config_response->max_network_monitor_file_size) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "maxNetworkMonitorFileSize", config_response->max_network_monitor_file_size) == NULL) {
    goto fail; //String
    }


    // config_response->enable_firmware_image_upload
    if (!config_response->enable_firmware_image_upload) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "enableFirmwareImageUpload", config_response->enable_firmware_image_upload) == NULL) {
    goto fail; //Bool
    }


    // config_response->auth_providers
    if (!config_response->auth_providers) {
        goto fail;
    }
    cJSON *auth_providers = cJSON_AddArrayToObject(item, "authProviders");
    if(auth_providers == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *auth_providersListEntry;
    if (config_response->auth_providers) {
    list_ForEach(auth_providersListEntry, config_response->auth_providers) {
    cJSON *itemLocal = config_auth_provider_convertToJSON(auth_providersListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(auth_providers, itemLocal);
    }
    }


    // config_response->welcome_message
    if(config_response->welcome_message) {
    if(cJSON_AddStringToObject(item, "welcomeMessage", config_response->welcome_message) == NULL) {
    goto fail; //String
    }
    }


    // config_response->snapshot_limit
    if (!config_response->snapshot_limit) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "snapshotLimit", config_response->snapshot_limit) == NULL) {
    goto fail; //Numeric
    }


    // config_response->max_kernel_size
    if (!config_response->max_kernel_size) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "maxKernelSize", config_response->max_kernel_size) == NULL) {
    goto fail; //Numeric
    }


    // config_response->max_ramdisk_size
    if (!config_response->max_ramdisk_size) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "maxRamdiskSize", config_response->max_ramdisk_size) == NULL) {
    goto fail; //Numeric
    }


    // config_response->charm_sdk
    if(config_response->charm_sdk) {
    if(cJSON_AddBoolToObject(item, "charmSdk", config_response->charm_sdk) == NULL) {
    goto fail; //Bool
    }
    }


    // config_response->trial
    if (!config_response->trial) {
        goto fail;
    }
    cJSON *trial_local_JSON = trial_convertToJSON(config_response->trial);
    if(trial_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "trial", trial_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // config_response->sentry_url
    if(config_response->sentry_url) {
    if(cJSON_AddStringToObject(item, "sentryUrl", config_response->sentry_url) == NULL) {
    goto fail; //String
    }
    }


    // config_response->domain_authentication_providers
    if(config_response->domain_authentication_providers) {
    if(cJSON_AddBoolToObject(item, "domainAuthenticationProviders", config_response->domain_authentication_providers) == NULL) {
    goto fail; //Bool
    }
    }


    // config_response->remote_gpu
    if(config_response->remote_gpu) {
    if(cJSON_AddBoolToObject(item, "remoteGpu", config_response->remote_gpu) == NULL) {
    goto fail; //Bool
    }
    }


    // config_response->default_ssid
    if (!config_response->default_ssid) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "defaultSsid", config_response->default_ssid) == NULL) {
    goto fail; //String
    }


    // config_response->aws_marketplace
    if(config_response->aws_marketplace) {
    if(cJSON_AddBoolToObject(item, "awsMarketplace", config_response->aws_marketplace) == NULL) {
    goto fail; //Bool
    }
    }


    // config_response->open_g_apps_binary
    if(config_response->open_g_apps_binary) {
    if(cJSON_AddStringToObject(item, "openGAppsBinary", config_response->open_g_apps_binary) == NULL) {
    goto fail; //String
    }
    }


    // config_response->air_gapped
    if(config_response->air_gapped) {
    if(cJSON_AddBoolToObject(item, "airGapped", config_response->air_gapped) == NULL) {
    goto fail; //Bool
    }
    }


    // config_response->coordinator_config
    if (!config_response->coordinator_config) {
        goto fail;
    }
    cJSON *coordinator_config_local_JSON = config_response_coordinator_config_convertToJSON(config_response->coordinator_config);
    if(coordinator_config_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "coordinatorConfig", coordinator_config_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

config_response_t *config_response_parseFromJSON(cJSON *config_responseJSON){

    config_response_t *config_response_local_var = NULL;

    // define the local list for config_response->network_types
    list_t *network_typesList = NULL;

    // define the local variable for config_response->maintenance
    config_response_maintenance_t *maintenance_local_nonprim = NULL;

    // define the local variable for config_response->logging
    logging_t *logging_local_nonprim = NULL;

    // define the local list for config_response->auth_providers
    list_t *auth_providersList = NULL;

    // define the local variable for config_response->trial
    trial_t *trial_local_nonprim = NULL;

    // define the local variable for config_response->coordinator_config
    config_response_coordinator_config_t *coordinator_config_local_nonprim = NULL;

    // config_response->on_site
    cJSON *on_site = cJSON_GetObjectItemCaseSensitive(config_responseJSON, "onSite");
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

    // config_response->network_types
    cJSON *network_types = cJSON_GetObjectItemCaseSensitive(config_responseJSON, "networkTypes");
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

    // config_response->network_type
    cJSON *network_type = cJSON_GetObjectItemCaseSensitive(config_responseJSON, "networkType");
    if (cJSON_IsNull(network_type)) {
        network_type = NULL;
    }
    if (!network_type) {
        goto end;
    }

    corellium_api_config_response_NETWORKTYPE_e network_typeVariable;
    
    if(!cJSON_IsString(network_type))
    {
    goto end; //Enum
    }
    network_typeVariable = config_response_network_type_FromString(network_type->valuestring);

    // config_response->show_domain_settings
    cJSON *show_domain_settings = cJSON_GetObjectItemCaseSensitive(config_responseJSON, "showDomainSettings");
    if (cJSON_IsNull(show_domain_settings)) {
        show_domain_settings = NULL;
    }
    if (!show_domain_settings) {
        goto end;
    }

    
    if(!cJSON_IsBool(show_domain_settings))
    {
    goto end; //Bool
    }

    // config_response->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(config_responseJSON, "version");
    if (cJSON_IsNull(version)) {
        version = NULL;
    }
    if (!version) {
        goto end;
    }

    
    if(!cJSON_IsString(version))
    {
    goto end; //String
    }

    // config_response->invalid_build
    cJSON *invalid_build = cJSON_GetObjectItemCaseSensitive(config_responseJSON, "invalidBuild");
    if (cJSON_IsNull(invalid_build)) {
        invalid_build = NULL;
    }
    if (invalid_build) { 
    if(!cJSON_IsBool(invalid_build))
    {
    goto end; //Bool
    }
    }

    // config_response->sep_sim
    cJSON *sep_sim = cJSON_GetObjectItemCaseSensitive(config_responseJSON, "sepSim");
    if (cJSON_IsNull(sep_sim)) {
        sep_sim = NULL;
    }
    if (!sep_sim) {
        goto end;
    }

    
    if(!cJSON_IsBool(sep_sim))
    {
    goto end; //Bool
    }

    // config_response->installer_available
    cJSON *installer_available = cJSON_GetObjectItemCaseSensitive(config_responseJSON, "installerAvailable");
    if (cJSON_IsNull(installer_available)) {
        installer_available = NULL;
    }
    if (!installer_available) {
        goto end;
    }

    
    if(!cJSON_IsBool(installer_available))
    {
    goto end; //Bool
    }

    // config_response->invoiced_publishable_key
    cJSON *invoiced_publishable_key = cJSON_GetObjectItemCaseSensitive(config_responseJSON, "invoicedPublishableKey");
    if (cJSON_IsNull(invoiced_publishable_key)) {
        invoiced_publishable_key = NULL;
    }
    if (invoiced_publishable_key) { 
    if(!cJSON_IsString(invoiced_publishable_key) && !cJSON_IsNull(invoiced_publishable_key))
    {
    goto end; //String
    }
    }

    // config_response->stripe_public_key
    cJSON *stripe_public_key = cJSON_GetObjectItemCaseSensitive(config_responseJSON, "stripePublicKey");
    if (cJSON_IsNull(stripe_public_key)) {
        stripe_public_key = NULL;
    }
    if (stripe_public_key) { 
    if(!cJSON_IsString(stripe_public_key) && !cJSON_IsNull(stripe_public_key))
    {
    goto end; //String
    }
    }

    // config_response->intercom_id
    cJSON *intercom_id = cJSON_GetObjectItemCaseSensitive(config_responseJSON, "intercomId");
    if (cJSON_IsNull(intercom_id)) {
        intercom_id = NULL;
    }
    if (intercom_id) { 
    if(!cJSON_IsString(intercom_id) && !cJSON_IsNull(intercom_id))
    {
    goto end; //String
    }
    }

    // config_response->gtm_id
    cJSON *gtm_id = cJSON_GetObjectItemCaseSensitive(config_responseJSON, "gtmId");
    if (cJSON_IsNull(gtm_id)) {
        gtm_id = NULL;
    }
    if (gtm_id) { 
    if(!cJSON_IsString(gtm_id) && !cJSON_IsNull(gtm_id))
    {
    goto end; //String
    }
    }

    // config_response->billing_backend
    cJSON *billing_backend = cJSON_GetObjectItemCaseSensitive(config_responseJSON, "billingBackend");
    if (cJSON_IsNull(billing_backend)) {
        billing_backend = NULL;
    }
    if (billing_backend) { 
    if(!cJSON_IsString(billing_backend) && !cJSON_IsNull(billing_backend))
    {
    goto end; //String
    }
    }

    // config_response->maintenance
    cJSON *maintenance = cJSON_GetObjectItemCaseSensitive(config_responseJSON, "maintenance");
    if (cJSON_IsNull(maintenance)) {
        maintenance = NULL;
    }
    if (maintenance) { 
    maintenance_local_nonprim = config_response_maintenance_parseFromJSON(maintenance); //nonprimitive
    }

    // config_response->logging
    cJSON *logging = cJSON_GetObjectItemCaseSensitive(config_responseJSON, "logging");
    if (cJSON_IsNull(logging)) {
        logging = NULL;
    }
    if (logging) { 
    logging_local_nonprim = logging_parseFromJSON(logging); //nonprimitive
    }

    // config_response->cloud_admin
    cJSON *cloud_admin = cJSON_GetObjectItemCaseSensitive(config_responseJSON, "cloudAdmin");
    if (cJSON_IsNull(cloud_admin)) {
        cloud_admin = NULL;
    }
    if (!cloud_admin) {
        goto end;
    }

    
    if(!cJSON_IsString(cloud_admin))
    {
    goto end; //String
    }

    // config_response->files_admin
    cJSON *files_admin = cJSON_GetObjectItemCaseSensitive(config_responseJSON, "filesAdmin");
    if (cJSON_IsNull(files_admin)) {
        files_admin = NULL;
    }
    if (!files_admin) {
        goto end;
    }

    
    if(!cJSON_IsString(files_admin))
    {
    goto end; //String
    }

    // config_response->cloud_domain
    cJSON *cloud_domain = cJSON_GetObjectItemCaseSensitive(config_responseJSON, "cloudDomain");
    if (cJSON_IsNull(cloud_domain)) {
        cloud_domain = NULL;
    }
    if (cloud_domain) { 
    if(!cJSON_IsString(cloud_domain) && !cJSON_IsNull(cloud_domain))
    {
    goto end; //String
    }
    }

    // config_response->billing_domain
    cJSON *billing_domain = cJSON_GetObjectItemCaseSensitive(config_responseJSON, "billingDomain");
    if (cJSON_IsNull(billing_domain)) {
        billing_domain = NULL;
    }
    if (billing_domain) { 
    if(!cJSON_IsString(billing_domain) && !cJSON_IsNull(billing_domain))
    {
    goto end; //String
    }
    }

    // config_response->app_domain
    cJSON *app_domain = cJSON_GetObjectItemCaseSensitive(config_responseJSON, "appDomain");
    if (cJSON_IsNull(app_domain)) {
        app_domain = NULL;
    }
    if (app_domain) { 
    if(!cJSON_IsString(app_domain) && !cJSON_IsNull(app_domain))
    {
    goto end; //String
    }
    }

    // config_response->max_network_monitor_file_size
    cJSON *max_network_monitor_file_size = cJSON_GetObjectItemCaseSensitive(config_responseJSON, "maxNetworkMonitorFileSize");
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

    // config_response->enable_firmware_image_upload
    cJSON *enable_firmware_image_upload = cJSON_GetObjectItemCaseSensitive(config_responseJSON, "enableFirmwareImageUpload");
    if (cJSON_IsNull(enable_firmware_image_upload)) {
        enable_firmware_image_upload = NULL;
    }
    if (!enable_firmware_image_upload) {
        goto end;
    }

    
    if(!cJSON_IsBool(enable_firmware_image_upload))
    {
    goto end; //Bool
    }

    // config_response->auth_providers
    cJSON *auth_providers = cJSON_GetObjectItemCaseSensitive(config_responseJSON, "authProviders");
    if (cJSON_IsNull(auth_providers)) {
        auth_providers = NULL;
    }
    if (!auth_providers) {
        goto end;
    }

    
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
        config_auth_provider_t *auth_providersItem = config_auth_provider_parseFromJSON(auth_providers_local_nonprimitive);

        list_addElement(auth_providersList, auth_providersItem);
    }

    // config_response->welcome_message
    cJSON *welcome_message = cJSON_GetObjectItemCaseSensitive(config_responseJSON, "welcomeMessage");
    if (cJSON_IsNull(welcome_message)) {
        welcome_message = NULL;
    }
    if (welcome_message) { 
    if(!cJSON_IsString(welcome_message) && !cJSON_IsNull(welcome_message))
    {
    goto end; //String
    }
    }

    // config_response->snapshot_limit
    cJSON *snapshot_limit = cJSON_GetObjectItemCaseSensitive(config_responseJSON, "snapshotLimit");
    if (cJSON_IsNull(snapshot_limit)) {
        snapshot_limit = NULL;
    }
    if (!snapshot_limit) {
        goto end;
    }

    
    if(!cJSON_IsNumber(snapshot_limit))
    {
    goto end; //Numeric
    }

    // config_response->max_kernel_size
    cJSON *max_kernel_size = cJSON_GetObjectItemCaseSensitive(config_responseJSON, "maxKernelSize");
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

    // config_response->max_ramdisk_size
    cJSON *max_ramdisk_size = cJSON_GetObjectItemCaseSensitive(config_responseJSON, "maxRamdiskSize");
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

    // config_response->charm_sdk
    cJSON *charm_sdk = cJSON_GetObjectItemCaseSensitive(config_responseJSON, "charmSdk");
    if (cJSON_IsNull(charm_sdk)) {
        charm_sdk = NULL;
    }
    if (charm_sdk) { 
    if(!cJSON_IsBool(charm_sdk))
    {
    goto end; //Bool
    }
    }

    // config_response->trial
    cJSON *trial = cJSON_GetObjectItemCaseSensitive(config_responseJSON, "trial");
    if (cJSON_IsNull(trial)) {
        trial = NULL;
    }
    if (!trial) {
        goto end;
    }

    
    trial_local_nonprim = trial_parseFromJSON(trial); //nonprimitive

    // config_response->sentry_url
    cJSON *sentry_url = cJSON_GetObjectItemCaseSensitive(config_responseJSON, "sentryUrl");
    if (cJSON_IsNull(sentry_url)) {
        sentry_url = NULL;
    }
    if (sentry_url) { 
    if(!cJSON_IsString(sentry_url) && !cJSON_IsNull(sentry_url))
    {
    goto end; //String
    }
    }

    // config_response->domain_authentication_providers
    cJSON *domain_authentication_providers = cJSON_GetObjectItemCaseSensitive(config_responseJSON, "domainAuthenticationProviders");
    if (cJSON_IsNull(domain_authentication_providers)) {
        domain_authentication_providers = NULL;
    }
    if (domain_authentication_providers) { 
    if(!cJSON_IsBool(domain_authentication_providers))
    {
    goto end; //Bool
    }
    }

    // config_response->remote_gpu
    cJSON *remote_gpu = cJSON_GetObjectItemCaseSensitive(config_responseJSON, "remoteGpu");
    if (cJSON_IsNull(remote_gpu)) {
        remote_gpu = NULL;
    }
    if (remote_gpu) { 
    if(!cJSON_IsBool(remote_gpu))
    {
    goto end; //Bool
    }
    }

    // config_response->default_ssid
    cJSON *default_ssid = cJSON_GetObjectItemCaseSensitive(config_responseJSON, "defaultSsid");
    if (cJSON_IsNull(default_ssid)) {
        default_ssid = NULL;
    }
    if (!default_ssid) {
        goto end;
    }

    
    if(!cJSON_IsString(default_ssid))
    {
    goto end; //String
    }

    // config_response->aws_marketplace
    cJSON *aws_marketplace = cJSON_GetObjectItemCaseSensitive(config_responseJSON, "awsMarketplace");
    if (cJSON_IsNull(aws_marketplace)) {
        aws_marketplace = NULL;
    }
    if (aws_marketplace) { 
    if(!cJSON_IsBool(aws_marketplace))
    {
    goto end; //Bool
    }
    }

    // config_response->open_g_apps_binary
    cJSON *open_g_apps_binary = cJSON_GetObjectItemCaseSensitive(config_responseJSON, "openGAppsBinary");
    if (cJSON_IsNull(open_g_apps_binary)) {
        open_g_apps_binary = NULL;
    }
    if (open_g_apps_binary) { 
    if(!cJSON_IsString(open_g_apps_binary) && !cJSON_IsNull(open_g_apps_binary))
    {
    goto end; //String
    }
    }

    // config_response->air_gapped
    cJSON *air_gapped = cJSON_GetObjectItemCaseSensitive(config_responseJSON, "airGapped");
    if (cJSON_IsNull(air_gapped)) {
        air_gapped = NULL;
    }
    if (air_gapped) { 
    if(!cJSON_IsBool(air_gapped))
    {
    goto end; //Bool
    }
    }

    // config_response->coordinator_config
    cJSON *coordinator_config = cJSON_GetObjectItemCaseSensitive(config_responseJSON, "coordinatorConfig");
    if (cJSON_IsNull(coordinator_config)) {
        coordinator_config = NULL;
    }
    if (!coordinator_config) {
        goto end;
    }

    
    coordinator_config_local_nonprim = config_response_coordinator_config_parseFromJSON(coordinator_config); //nonprimitive


    config_response_local_var = config_response_create_internal (
        on_site->valueint,
        network_types ? network_typesList : NULL,
        network_typeVariable,
        show_domain_settings->valueint,
        strdup(version->valuestring),
        invalid_build ? invalid_build->valueint : 0,
        sep_sim->valueint,
        installer_available->valueint,
        invoiced_publishable_key && !cJSON_IsNull(invoiced_publishable_key) ? strdup(invoiced_publishable_key->valuestring) : NULL,
        stripe_public_key && !cJSON_IsNull(stripe_public_key) ? strdup(stripe_public_key->valuestring) : NULL,
        intercom_id && !cJSON_IsNull(intercom_id) ? strdup(intercom_id->valuestring) : NULL,
        gtm_id && !cJSON_IsNull(gtm_id) ? strdup(gtm_id->valuestring) : NULL,
        billing_backend && !cJSON_IsNull(billing_backend) ? strdup(billing_backend->valuestring) : NULL,
        maintenance ? maintenance_local_nonprim : NULL,
        logging ? logging_local_nonprim : NULL,
        strdup(cloud_admin->valuestring),
        strdup(files_admin->valuestring),
        cloud_domain && !cJSON_IsNull(cloud_domain) ? strdup(cloud_domain->valuestring) : NULL,
        billing_domain && !cJSON_IsNull(billing_domain) ? strdup(billing_domain->valuestring) : NULL,
        app_domain && !cJSON_IsNull(app_domain) ? strdup(app_domain->valuestring) : NULL,
        strdup(max_network_monitor_file_size->valuestring),
        enable_firmware_image_upload->valueint,
        auth_providersList,
        welcome_message && !cJSON_IsNull(welcome_message) ? strdup(welcome_message->valuestring) : NULL,
        snapshot_limit->valuedouble,
        max_kernel_size->valuedouble,
        max_ramdisk_size->valuedouble,
        charm_sdk ? charm_sdk->valueint : 0,
        trial_local_nonprim,
        sentry_url && !cJSON_IsNull(sentry_url) ? strdup(sentry_url->valuestring) : NULL,
        domain_authentication_providers ? domain_authentication_providers->valueint : 0,
        remote_gpu ? remote_gpu->valueint : 0,
        strdup(default_ssid->valuestring),
        aws_marketplace ? aws_marketplace->valueint : 0,
        open_g_apps_binary && !cJSON_IsNull(open_g_apps_binary) ? strdup(open_g_apps_binary->valuestring) : NULL,
        air_gapped ? air_gapped->valueint : 0,
        coordinator_config_local_nonprim
        );

    return config_response_local_var;
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
    if (maintenance_local_nonprim) {
        config_response_maintenance_free(maintenance_local_nonprim);
        maintenance_local_nonprim = NULL;
    }
    if (logging_local_nonprim) {
        logging_free(logging_local_nonprim);
        logging_local_nonprim = NULL;
    }
    if (auth_providersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, auth_providersList) {
            config_auth_provider_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(auth_providersList);
        auth_providersList = NULL;
    }
    if (trial_local_nonprim) {
        trial_free(trial_local_nonprim);
        trial_local_nonprim = NULL;
    }
    if (coordinator_config_local_nonprim) {
        config_response_coordinator_config_free(coordinator_config_local_nonprim);
        coordinator_config_local_nonprim = NULL;
    }
    return NULL;

}
