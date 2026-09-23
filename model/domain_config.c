#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "domain_config.h"



static domain_config_t *domain_config_create_internal(
    int android,
    int billing,
    char *license_type,
    char *signup_email,
    domain_config_trial_t *trial,
    int usage_based,
    int enable_netgear_devices,
    int no_ios,
    int enable_amazon_devices,
    int device_dhcp_server,
    int enable_arm_devices,
    int enable_devices,
    domain_config_webplayer_t *webplayer,
    domain_config_snapshot_sharing_permissions_t *snapshot_sharing_permissions
    ) {
    domain_config_t *domain_config_local_var = malloc(sizeof(domain_config_t));
    if (!domain_config_local_var) {
        return NULL;
    }
    domain_config_local_var->android = android;
    domain_config_local_var->billing = billing;
    domain_config_local_var->license_type = license_type;
    domain_config_local_var->signup_email = signup_email;
    domain_config_local_var->trial = trial;
    domain_config_local_var->usage_based = usage_based;
    domain_config_local_var->enable_netgear_devices = enable_netgear_devices;
    domain_config_local_var->no_ios = no_ios;
    domain_config_local_var->enable_amazon_devices = enable_amazon_devices;
    domain_config_local_var->device_dhcp_server = device_dhcp_server;
    domain_config_local_var->enable_arm_devices = enable_arm_devices;
    domain_config_local_var->enable_devices = enable_devices;
    domain_config_local_var->webplayer = webplayer;
    domain_config_local_var->snapshot_sharing_permissions = snapshot_sharing_permissions;

    domain_config_local_var->_library_owned = 1;
    return domain_config_local_var;
}

__attribute__((deprecated)) domain_config_t *domain_config_create(
    int android,
    int billing,
    char *license_type,
    char *signup_email,
    domain_config_trial_t *trial,
    int usage_based,
    int enable_netgear_devices,
    int no_ios,
    int enable_amazon_devices,
    int device_dhcp_server,
    int enable_arm_devices,
    int enable_devices,
    domain_config_webplayer_t *webplayer,
    domain_config_snapshot_sharing_permissions_t *snapshot_sharing_permissions
    ) {
    return domain_config_create_internal (
        android,
        billing,
        license_type,
        signup_email,
        trial,
        usage_based,
        enable_netgear_devices,
        no_ios,
        enable_amazon_devices,
        device_dhcp_server,
        enable_arm_devices,
        enable_devices,
        webplayer,
        snapshot_sharing_permissions
        );
}

void domain_config_free(domain_config_t *domain_config) {
    if(NULL == domain_config){
        return ;
    }
    if(domain_config->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "domain_config_free");
        return ;
    }
    listEntry_t *listEntry;
    if (domain_config->license_type) {
        free(domain_config->license_type);
        domain_config->license_type = NULL;
    }
    if (domain_config->signup_email) {
        free(domain_config->signup_email);
        domain_config->signup_email = NULL;
    }
    if (domain_config->trial) {
        domain_config_trial_free(domain_config->trial);
        domain_config->trial = NULL;
    }
    if (domain_config->webplayer) {
        domain_config_webplayer_free(domain_config->webplayer);
        domain_config->webplayer = NULL;
    }
    if (domain_config->snapshot_sharing_permissions) {
        domain_config_snapshot_sharing_permissions_free(domain_config->snapshot_sharing_permissions);
        domain_config->snapshot_sharing_permissions = NULL;
    }
    free(domain_config);
}

cJSON *domain_config_convertToJSON(domain_config_t *domain_config) {
    cJSON *item = cJSON_CreateObject();

    // domain_config->android
    if(domain_config->android) {
    if(cJSON_AddBoolToObject(item, "android", domain_config->android) == NULL) {
    goto fail; //Bool
    }
    }


    // domain_config->billing
    if(domain_config->billing) {
    if(cJSON_AddBoolToObject(item, "billing", domain_config->billing) == NULL) {
    goto fail; //Bool
    }
    }


    // domain_config->license_type
    if(domain_config->license_type) {
    if(cJSON_AddStringToObject(item, "licenseType", domain_config->license_type) == NULL) {
    goto fail; //String
    }
    }


    // domain_config->signup_email
    if(domain_config->signup_email) {
    if(cJSON_AddStringToObject(item, "signupEmail", domain_config->signup_email) == NULL) {
    goto fail; //String
    }
    }


    // domain_config->trial
    if(domain_config->trial) {
    cJSON *trial_local_JSON = domain_config_trial_convertToJSON(domain_config->trial);
    if(trial_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "trial", trial_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // domain_config->usage_based
    if(domain_config->usage_based) {
    if(cJSON_AddBoolToObject(item, "usageBased", domain_config->usage_based) == NULL) {
    goto fail; //Bool
    }
    }


    // domain_config->enable_netgear_devices
    if(domain_config->enable_netgear_devices) {
    if(cJSON_AddBoolToObject(item, "enableNetgearDevices", domain_config->enable_netgear_devices) == NULL) {
    goto fail; //Bool
    }
    }


    // domain_config->no_ios
    if(domain_config->no_ios) {
    if(cJSON_AddBoolToObject(item, "noIos", domain_config->no_ios) == NULL) {
    goto fail; //Bool
    }
    }


    // domain_config->enable_amazon_devices
    if(domain_config->enable_amazon_devices) {
    if(cJSON_AddBoolToObject(item, "enableAmazonDevices", domain_config->enable_amazon_devices) == NULL) {
    goto fail; //Bool
    }
    }


    // domain_config->device_dhcp_server
    if(domain_config->device_dhcp_server) {
    if(cJSON_AddBoolToObject(item, "deviceDhcpServer", domain_config->device_dhcp_server) == NULL) {
    goto fail; //Bool
    }
    }


    // domain_config->enable_arm_devices
    if(domain_config->enable_arm_devices) {
    if(cJSON_AddBoolToObject(item, "enableArmDevices", domain_config->enable_arm_devices) == NULL) {
    goto fail; //Bool
    }
    }


    // domain_config->enable_devices
    if(domain_config->enable_devices) {
    if(cJSON_AddBoolToObject(item, "enableDevices", domain_config->enable_devices) == NULL) {
    goto fail; //Bool
    }
    }


    // domain_config->webplayer
    if(domain_config->webplayer) {
    cJSON *webplayer_local_JSON = domain_config_webplayer_convertToJSON(domain_config->webplayer);
    if(webplayer_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "webplayer", webplayer_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // domain_config->snapshot_sharing_permissions
    if(domain_config->snapshot_sharing_permissions) {
    cJSON *snapshot_sharing_permissions_local_JSON = domain_config_snapshot_sharing_permissions_convertToJSON(domain_config->snapshot_sharing_permissions);
    if(snapshot_sharing_permissions_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "snapshotSharingPermissions", snapshot_sharing_permissions_local_JSON);
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

domain_config_t *domain_config_parseFromJSON(cJSON *domain_configJSON){

    domain_config_t *domain_config_local_var = NULL;

    // define the local variable for domain_config->trial
    domain_config_trial_t *trial_local_nonprim = NULL;

    // define the local variable for domain_config->webplayer
    domain_config_webplayer_t *webplayer_local_nonprim = NULL;

    // define the local variable for domain_config->snapshot_sharing_permissions
    domain_config_snapshot_sharing_permissions_t *snapshot_sharing_permissions_local_nonprim = NULL;

    // domain_config->android
    cJSON *android = cJSON_GetObjectItemCaseSensitive(domain_configJSON, "android");
    if (cJSON_IsNull(android)) {
        android = NULL;
    }
    if (android) { 
    if(!cJSON_IsBool(android))
    {
    goto end; //Bool
    }
    }

    // domain_config->billing
    cJSON *billing = cJSON_GetObjectItemCaseSensitive(domain_configJSON, "billing");
    if (cJSON_IsNull(billing)) {
        billing = NULL;
    }
    if (billing) { 
    if(!cJSON_IsBool(billing))
    {
    goto end; //Bool
    }
    }

    // domain_config->license_type
    cJSON *license_type = cJSON_GetObjectItemCaseSensitive(domain_configJSON, "licenseType");
    if (cJSON_IsNull(license_type)) {
        license_type = NULL;
    }
    if (license_type) { 
    if(!cJSON_IsString(license_type) && !cJSON_IsNull(license_type))
    {
    goto end; //String
    }
    }

    // domain_config->signup_email
    cJSON *signup_email = cJSON_GetObjectItemCaseSensitive(domain_configJSON, "signupEmail");
    if (cJSON_IsNull(signup_email)) {
        signup_email = NULL;
    }
    if (signup_email) { 
    if(!cJSON_IsString(signup_email) && !cJSON_IsNull(signup_email))
    {
    goto end; //String
    }
    }

    // domain_config->trial
    cJSON *trial = cJSON_GetObjectItemCaseSensitive(domain_configJSON, "trial");
    if (cJSON_IsNull(trial)) {
        trial = NULL;
    }
    if (trial) { 
    trial_local_nonprim = domain_config_trial_parseFromJSON(trial); //nonprimitive
    }

    // domain_config->usage_based
    cJSON *usage_based = cJSON_GetObjectItemCaseSensitive(domain_configJSON, "usageBased");
    if (cJSON_IsNull(usage_based)) {
        usage_based = NULL;
    }
    if (usage_based) { 
    if(!cJSON_IsBool(usage_based))
    {
    goto end; //Bool
    }
    }

    // domain_config->enable_netgear_devices
    cJSON *enable_netgear_devices = cJSON_GetObjectItemCaseSensitive(domain_configJSON, "enableNetgearDevices");
    if (cJSON_IsNull(enable_netgear_devices)) {
        enable_netgear_devices = NULL;
    }
    if (enable_netgear_devices) { 
    if(!cJSON_IsBool(enable_netgear_devices))
    {
    goto end; //Bool
    }
    }

    // domain_config->no_ios
    cJSON *no_ios = cJSON_GetObjectItemCaseSensitive(domain_configJSON, "noIos");
    if (cJSON_IsNull(no_ios)) {
        no_ios = NULL;
    }
    if (no_ios) { 
    if(!cJSON_IsBool(no_ios))
    {
    goto end; //Bool
    }
    }

    // domain_config->enable_amazon_devices
    cJSON *enable_amazon_devices = cJSON_GetObjectItemCaseSensitive(domain_configJSON, "enableAmazonDevices");
    if (cJSON_IsNull(enable_amazon_devices)) {
        enable_amazon_devices = NULL;
    }
    if (enable_amazon_devices) { 
    if(!cJSON_IsBool(enable_amazon_devices))
    {
    goto end; //Bool
    }
    }

    // domain_config->device_dhcp_server
    cJSON *device_dhcp_server = cJSON_GetObjectItemCaseSensitive(domain_configJSON, "deviceDhcpServer");
    if (cJSON_IsNull(device_dhcp_server)) {
        device_dhcp_server = NULL;
    }
    if (device_dhcp_server) { 
    if(!cJSON_IsBool(device_dhcp_server))
    {
    goto end; //Bool
    }
    }

    // domain_config->enable_arm_devices
    cJSON *enable_arm_devices = cJSON_GetObjectItemCaseSensitive(domain_configJSON, "enableArmDevices");
    if (cJSON_IsNull(enable_arm_devices)) {
        enable_arm_devices = NULL;
    }
    if (enable_arm_devices) { 
    if(!cJSON_IsBool(enable_arm_devices))
    {
    goto end; //Bool
    }
    }

    // domain_config->enable_devices
    cJSON *enable_devices = cJSON_GetObjectItemCaseSensitive(domain_configJSON, "enableDevices");
    if (cJSON_IsNull(enable_devices)) {
        enable_devices = NULL;
    }
    if (enable_devices) { 
    if(!cJSON_IsBool(enable_devices))
    {
    goto end; //Bool
    }
    }

    // domain_config->webplayer
    cJSON *webplayer = cJSON_GetObjectItemCaseSensitive(domain_configJSON, "webplayer");
    if (cJSON_IsNull(webplayer)) {
        webplayer = NULL;
    }
    if (webplayer) { 
    webplayer_local_nonprim = domain_config_webplayer_parseFromJSON(webplayer); //nonprimitive
    }

    // domain_config->snapshot_sharing_permissions
    cJSON *snapshot_sharing_permissions = cJSON_GetObjectItemCaseSensitive(domain_configJSON, "snapshotSharingPermissions");
    if (cJSON_IsNull(snapshot_sharing_permissions)) {
        snapshot_sharing_permissions = NULL;
    }
    if (snapshot_sharing_permissions) { 
    snapshot_sharing_permissions_local_nonprim = domain_config_snapshot_sharing_permissions_parseFromJSON(snapshot_sharing_permissions); //nonprimitive
    }


    domain_config_local_var = domain_config_create_internal (
        android ? android->valueint : 0,
        billing ? billing->valueint : 0,
        license_type && !cJSON_IsNull(license_type) ? strdup(license_type->valuestring) : NULL,
        signup_email && !cJSON_IsNull(signup_email) ? strdup(signup_email->valuestring) : NULL,
        trial ? trial_local_nonprim : NULL,
        usage_based ? usage_based->valueint : 0,
        enable_netgear_devices ? enable_netgear_devices->valueint : 0,
        no_ios ? no_ios->valueint : 0,
        enable_amazon_devices ? enable_amazon_devices->valueint : 0,
        device_dhcp_server ? device_dhcp_server->valueint : 0,
        enable_arm_devices ? enable_arm_devices->valueint : 0,
        enable_devices ? enable_devices->valueint : 0,
        webplayer ? webplayer_local_nonprim : NULL,
        snapshot_sharing_permissions ? snapshot_sharing_permissions_local_nonprim : NULL
        );

    return domain_config_local_var;
end:
    if (trial_local_nonprim) {
        domain_config_trial_free(trial_local_nonprim);
        trial_local_nonprim = NULL;
    }
    if (webplayer_local_nonprim) {
        domain_config_webplayer_free(webplayer_local_nonprim);
        webplayer_local_nonprim = NULL;
    }
    if (snapshot_sharing_permissions_local_nonprim) {
        domain_config_snapshot_sharing_permissions_free(snapshot_sharing_permissions_local_nonprim);
        snapshot_sharing_permissions_local_nonprim = NULL;
    }
    return NULL;

}
