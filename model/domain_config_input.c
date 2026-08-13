#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "domain_config_input.h"



static domain_config_input_t *domain_config_input_create_internal(
    int android,
    int billing,
    char *organization_name,
    char *license_type,
    char *signup_email,
    char *coupon_code,
    domain_config_input_trial_t *trial,
    int no_ios,
    int device_dhcp_server,
    int files,
    int files_only,
    int remote_gpu,
    list_t *prioritized_nodes,
    int enable_netgear_devices,
    int enable_amazon_devices,
    int enable_arm_devices,
    int enable_devices,
    domain_config_input_webplayer_t *webplayer,
    domain_config_input_snapshot_sharing_permissions_t *snapshot_sharing_permissions
    ) {
    domain_config_input_t *domain_config_input_local_var = malloc(sizeof(domain_config_input_t));
    if (!domain_config_input_local_var) {
        return NULL;
    }
    domain_config_input_local_var->android = android;
    domain_config_input_local_var->billing = billing;
    domain_config_input_local_var->organization_name = organization_name;
    domain_config_input_local_var->license_type = license_type;
    domain_config_input_local_var->signup_email = signup_email;
    domain_config_input_local_var->coupon_code = coupon_code;
    domain_config_input_local_var->trial = trial;
    domain_config_input_local_var->no_ios = no_ios;
    domain_config_input_local_var->device_dhcp_server = device_dhcp_server;
    domain_config_input_local_var->files = files;
    domain_config_input_local_var->files_only = files_only;
    domain_config_input_local_var->remote_gpu = remote_gpu;
    domain_config_input_local_var->prioritized_nodes = prioritized_nodes;
    domain_config_input_local_var->enable_netgear_devices = enable_netgear_devices;
    domain_config_input_local_var->enable_amazon_devices = enable_amazon_devices;
    domain_config_input_local_var->enable_arm_devices = enable_arm_devices;
    domain_config_input_local_var->enable_devices = enable_devices;
    domain_config_input_local_var->webplayer = webplayer;
    domain_config_input_local_var->snapshot_sharing_permissions = snapshot_sharing_permissions;

    domain_config_input_local_var->_library_owned = 1;
    return domain_config_input_local_var;
}

__attribute__((deprecated)) domain_config_input_t *domain_config_input_create(
    int android,
    int billing,
    char *organization_name,
    char *license_type,
    char *signup_email,
    char *coupon_code,
    domain_config_input_trial_t *trial,
    int no_ios,
    int device_dhcp_server,
    int files,
    int files_only,
    int remote_gpu,
    list_t *prioritized_nodes,
    int enable_netgear_devices,
    int enable_amazon_devices,
    int enable_arm_devices,
    int enable_devices,
    domain_config_input_webplayer_t *webplayer,
    domain_config_input_snapshot_sharing_permissions_t *snapshot_sharing_permissions
    ) {
    return domain_config_input_create_internal (
        android,
        billing,
        organization_name,
        license_type,
        signup_email,
        coupon_code,
        trial,
        no_ios,
        device_dhcp_server,
        files,
        files_only,
        remote_gpu,
        prioritized_nodes,
        enable_netgear_devices,
        enable_amazon_devices,
        enable_arm_devices,
        enable_devices,
        webplayer,
        snapshot_sharing_permissions
        );
}

void domain_config_input_free(domain_config_input_t *domain_config_input) {
    if(NULL == domain_config_input){
        return ;
    }
    if(domain_config_input->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "domain_config_input_free");
        return ;
    }
    listEntry_t *listEntry;
    if (domain_config_input->organization_name) {
        free(domain_config_input->organization_name);
        domain_config_input->organization_name = NULL;
    }
    if (domain_config_input->license_type) {
        free(domain_config_input->license_type);
        domain_config_input->license_type = NULL;
    }
    if (domain_config_input->signup_email) {
        free(domain_config_input->signup_email);
        domain_config_input->signup_email = NULL;
    }
    if (domain_config_input->coupon_code) {
        free(domain_config_input->coupon_code);
        domain_config_input->coupon_code = NULL;
    }
    if (domain_config_input->trial) {
        domain_config_input_trial_free(domain_config_input->trial);
        domain_config_input->trial = NULL;
    }
    if (domain_config_input->prioritized_nodes) {
        list_ForEach(listEntry, domain_config_input->prioritized_nodes) {
            free(listEntry->data);
        }
        list_freeList(domain_config_input->prioritized_nodes);
        domain_config_input->prioritized_nodes = NULL;
    }
    if (domain_config_input->webplayer) {
        domain_config_input_webplayer_free(domain_config_input->webplayer);
        domain_config_input->webplayer = NULL;
    }
    if (domain_config_input->snapshot_sharing_permissions) {
        domain_config_input_snapshot_sharing_permissions_free(domain_config_input->snapshot_sharing_permissions);
        domain_config_input->snapshot_sharing_permissions = NULL;
    }
    free(domain_config_input);
}

cJSON *domain_config_input_convertToJSON(domain_config_input_t *domain_config_input) {
    cJSON *item = cJSON_CreateObject();

    // domain_config_input->android
    if(domain_config_input->android) {
    if(cJSON_AddBoolToObject(item, "android", domain_config_input->android) == NULL) {
    goto fail; //Bool
    }
    }


    // domain_config_input->billing
    if(domain_config_input->billing) {
    if(cJSON_AddBoolToObject(item, "billing", domain_config_input->billing) == NULL) {
    goto fail; //Bool
    }
    }


    // domain_config_input->organization_name
    if(domain_config_input->organization_name) {
    if(cJSON_AddStringToObject(item, "organizationName", domain_config_input->organization_name) == NULL) {
    goto fail; //String
    }
    }


    // domain_config_input->license_type
    if(domain_config_input->license_type) {
    if(cJSON_AddStringToObject(item, "licenseType", domain_config_input->license_type) == NULL) {
    goto fail; //String
    }
    }


    // domain_config_input->signup_email
    if(domain_config_input->signup_email) {
    if(cJSON_AddStringToObject(item, "signupEmail", domain_config_input->signup_email) == NULL) {
    goto fail; //String
    }
    }


    // domain_config_input->coupon_code
    if(domain_config_input->coupon_code) {
    if(cJSON_AddStringToObject(item, "couponCode", domain_config_input->coupon_code) == NULL) {
    goto fail; //String
    }
    }


    // domain_config_input->trial
    if(domain_config_input->trial) {
    cJSON *trial_local_JSON = domain_config_input_trial_convertToJSON(domain_config_input->trial);
    if(trial_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "trial", trial_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // domain_config_input->no_ios
    if(domain_config_input->no_ios) {
    if(cJSON_AddBoolToObject(item, "noIos", domain_config_input->no_ios) == NULL) {
    goto fail; //Bool
    }
    }


    // domain_config_input->device_dhcp_server
    if(domain_config_input->device_dhcp_server) {
    if(cJSON_AddBoolToObject(item, "deviceDhcpServer", domain_config_input->device_dhcp_server) == NULL) {
    goto fail; //Bool
    }
    }


    // domain_config_input->files
    if(domain_config_input->files) {
    if(cJSON_AddBoolToObject(item, "files", domain_config_input->files) == NULL) {
    goto fail; //Bool
    }
    }


    // domain_config_input->files_only
    if(domain_config_input->files_only) {
    if(cJSON_AddBoolToObject(item, "filesOnly", domain_config_input->files_only) == NULL) {
    goto fail; //Bool
    }
    }


    // domain_config_input->remote_gpu
    if(domain_config_input->remote_gpu) {
    if(cJSON_AddBoolToObject(item, "remoteGpu", domain_config_input->remote_gpu) == NULL) {
    goto fail; //Bool
    }
    }


    // domain_config_input->prioritized_nodes
    if(domain_config_input->prioritized_nodes) {
    cJSON *prioritized_nodes = cJSON_AddArrayToObject(item, "prioritizedNodes");
    if(prioritized_nodes == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *prioritized_nodesListEntry;
    list_ForEach(prioritized_nodesListEntry, domain_config_input->prioritized_nodes) {
    if(cJSON_AddStringToObject(prioritized_nodes, "", prioritized_nodesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // domain_config_input->enable_netgear_devices
    if(domain_config_input->enable_netgear_devices) {
    if(cJSON_AddBoolToObject(item, "enableNetgearDevices", domain_config_input->enable_netgear_devices) == NULL) {
    goto fail; //Bool
    }
    }


    // domain_config_input->enable_amazon_devices
    if(domain_config_input->enable_amazon_devices) {
    if(cJSON_AddBoolToObject(item, "enableAmazonDevices", domain_config_input->enable_amazon_devices) == NULL) {
    goto fail; //Bool
    }
    }


    // domain_config_input->enable_arm_devices
    if(domain_config_input->enable_arm_devices) {
    if(cJSON_AddBoolToObject(item, "enableArmDevices", domain_config_input->enable_arm_devices) == NULL) {
    goto fail; //Bool
    }
    }


    // domain_config_input->enable_devices
    if(domain_config_input->enable_devices) {
    if(cJSON_AddBoolToObject(item, "enableDevices", domain_config_input->enable_devices) == NULL) {
    goto fail; //Bool
    }
    }


    // domain_config_input->webplayer
    if(domain_config_input->webplayer) {
    cJSON *webplayer_local_JSON = domain_config_input_webplayer_convertToJSON(domain_config_input->webplayer);
    if(webplayer_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "webplayer", webplayer_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // domain_config_input->snapshot_sharing_permissions
    if(domain_config_input->snapshot_sharing_permissions) {
    cJSON *snapshot_sharing_permissions_local_JSON = domain_config_input_snapshot_sharing_permissions_convertToJSON(domain_config_input->snapshot_sharing_permissions);
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

domain_config_input_t *domain_config_input_parseFromJSON(cJSON *domain_config_inputJSON){

    domain_config_input_t *domain_config_input_local_var = NULL;

    // define the local variable for domain_config_input->trial
    domain_config_input_trial_t *trial_local_nonprim = NULL;

    // define the local list for domain_config_input->prioritized_nodes
    list_t *prioritized_nodesList = NULL;

    // define the local variable for domain_config_input->webplayer
    domain_config_input_webplayer_t *webplayer_local_nonprim = NULL;

    // define the local variable for domain_config_input->snapshot_sharing_permissions
    domain_config_input_snapshot_sharing_permissions_t *snapshot_sharing_permissions_local_nonprim = NULL;

    // domain_config_input->android
    cJSON *android = cJSON_GetObjectItemCaseSensitive(domain_config_inputJSON, "android");
    if (cJSON_IsNull(android)) {
        android = NULL;
    }
    if (android) { 
    if(!cJSON_IsBool(android))
    {
    goto end; //Bool
    }
    }

    // domain_config_input->billing
    cJSON *billing = cJSON_GetObjectItemCaseSensitive(domain_config_inputJSON, "billing");
    if (cJSON_IsNull(billing)) {
        billing = NULL;
    }
    if (billing) { 
    if(!cJSON_IsBool(billing))
    {
    goto end; //Bool
    }
    }

    // domain_config_input->organization_name
    cJSON *organization_name = cJSON_GetObjectItemCaseSensitive(domain_config_inputJSON, "organizationName");
    if (cJSON_IsNull(organization_name)) {
        organization_name = NULL;
    }
    if (organization_name) { 
    if(!cJSON_IsString(organization_name) && !cJSON_IsNull(organization_name))
    {
    goto end; //String
    }
    }

    // domain_config_input->license_type
    cJSON *license_type = cJSON_GetObjectItemCaseSensitive(domain_config_inputJSON, "licenseType");
    if (cJSON_IsNull(license_type)) {
        license_type = NULL;
    }
    if (license_type) { 
    if(!cJSON_IsString(license_type) && !cJSON_IsNull(license_type))
    {
    goto end; //String
    }
    }

    // domain_config_input->signup_email
    cJSON *signup_email = cJSON_GetObjectItemCaseSensitive(domain_config_inputJSON, "signupEmail");
    if (cJSON_IsNull(signup_email)) {
        signup_email = NULL;
    }
    if (signup_email) { 
    if(!cJSON_IsString(signup_email) && !cJSON_IsNull(signup_email))
    {
    goto end; //String
    }
    }

    // domain_config_input->coupon_code
    cJSON *coupon_code = cJSON_GetObjectItemCaseSensitive(domain_config_inputJSON, "couponCode");
    if (cJSON_IsNull(coupon_code)) {
        coupon_code = NULL;
    }
    if (coupon_code) { 
    if(!cJSON_IsString(coupon_code) && !cJSON_IsNull(coupon_code))
    {
    goto end; //String
    }
    }

    // domain_config_input->trial
    cJSON *trial = cJSON_GetObjectItemCaseSensitive(domain_config_inputJSON, "trial");
    if (cJSON_IsNull(trial)) {
        trial = NULL;
    }
    if (trial) { 
    trial_local_nonprim = domain_config_input_trial_parseFromJSON(trial); //nonprimitive
    }

    // domain_config_input->no_ios
    cJSON *no_ios = cJSON_GetObjectItemCaseSensitive(domain_config_inputJSON, "noIos");
    if (cJSON_IsNull(no_ios)) {
        no_ios = NULL;
    }
    if (no_ios) { 
    if(!cJSON_IsBool(no_ios))
    {
    goto end; //Bool
    }
    }

    // domain_config_input->device_dhcp_server
    cJSON *device_dhcp_server = cJSON_GetObjectItemCaseSensitive(domain_config_inputJSON, "deviceDhcpServer");
    if (cJSON_IsNull(device_dhcp_server)) {
        device_dhcp_server = NULL;
    }
    if (device_dhcp_server) { 
    if(!cJSON_IsBool(device_dhcp_server))
    {
    goto end; //Bool
    }
    }

    // domain_config_input->files
    cJSON *files = cJSON_GetObjectItemCaseSensitive(domain_config_inputJSON, "files");
    if (cJSON_IsNull(files)) {
        files = NULL;
    }
    if (files) { 
    if(!cJSON_IsBool(files))
    {
    goto end; //Bool
    }
    }

    // domain_config_input->files_only
    cJSON *files_only = cJSON_GetObjectItemCaseSensitive(domain_config_inputJSON, "filesOnly");
    if (cJSON_IsNull(files_only)) {
        files_only = NULL;
    }
    if (files_only) { 
    if(!cJSON_IsBool(files_only))
    {
    goto end; //Bool
    }
    }

    // domain_config_input->remote_gpu
    cJSON *remote_gpu = cJSON_GetObjectItemCaseSensitive(domain_config_inputJSON, "remoteGpu");
    if (cJSON_IsNull(remote_gpu)) {
        remote_gpu = NULL;
    }
    if (remote_gpu) { 
    if(!cJSON_IsBool(remote_gpu))
    {
    goto end; //Bool
    }
    }

    // domain_config_input->prioritized_nodes
    cJSON *prioritized_nodes = cJSON_GetObjectItemCaseSensitive(domain_config_inputJSON, "prioritizedNodes");
    if (cJSON_IsNull(prioritized_nodes)) {
        prioritized_nodes = NULL;
    }
    if (prioritized_nodes) { 
    cJSON *prioritized_nodes_local = NULL;
    if(!cJSON_IsArray(prioritized_nodes)) {
        goto end;//primitive container
    }
    prioritized_nodesList = list_createList();

    cJSON_ArrayForEach(prioritized_nodes_local, prioritized_nodes)
    {
        if(!cJSON_IsString(prioritized_nodes_local))
        {
            goto end;
        }
        list_addElement(prioritized_nodesList , strdup(prioritized_nodes_local->valuestring));
    }
    }

    // domain_config_input->enable_netgear_devices
    cJSON *enable_netgear_devices = cJSON_GetObjectItemCaseSensitive(domain_config_inputJSON, "enableNetgearDevices");
    if (cJSON_IsNull(enable_netgear_devices)) {
        enable_netgear_devices = NULL;
    }
    if (enable_netgear_devices) { 
    if(!cJSON_IsBool(enable_netgear_devices))
    {
    goto end; //Bool
    }
    }

    // domain_config_input->enable_amazon_devices
    cJSON *enable_amazon_devices = cJSON_GetObjectItemCaseSensitive(domain_config_inputJSON, "enableAmazonDevices");
    if (cJSON_IsNull(enable_amazon_devices)) {
        enable_amazon_devices = NULL;
    }
    if (enable_amazon_devices) { 
    if(!cJSON_IsBool(enable_amazon_devices))
    {
    goto end; //Bool
    }
    }

    // domain_config_input->enable_arm_devices
    cJSON *enable_arm_devices = cJSON_GetObjectItemCaseSensitive(domain_config_inputJSON, "enableArmDevices");
    if (cJSON_IsNull(enable_arm_devices)) {
        enable_arm_devices = NULL;
    }
    if (enable_arm_devices) { 
    if(!cJSON_IsBool(enable_arm_devices))
    {
    goto end; //Bool
    }
    }

    // domain_config_input->enable_devices
    cJSON *enable_devices = cJSON_GetObjectItemCaseSensitive(domain_config_inputJSON, "enableDevices");
    if (cJSON_IsNull(enable_devices)) {
        enable_devices = NULL;
    }
    if (enable_devices) { 
    if(!cJSON_IsBool(enable_devices))
    {
    goto end; //Bool
    }
    }

    // domain_config_input->webplayer
    cJSON *webplayer = cJSON_GetObjectItemCaseSensitive(domain_config_inputJSON, "webplayer");
    if (cJSON_IsNull(webplayer)) {
        webplayer = NULL;
    }
    if (webplayer) { 
    webplayer_local_nonprim = domain_config_input_webplayer_parseFromJSON(webplayer); //nonprimitive
    }

    // domain_config_input->snapshot_sharing_permissions
    cJSON *snapshot_sharing_permissions = cJSON_GetObjectItemCaseSensitive(domain_config_inputJSON, "snapshotSharingPermissions");
    if (cJSON_IsNull(snapshot_sharing_permissions)) {
        snapshot_sharing_permissions = NULL;
    }
    if (snapshot_sharing_permissions) { 
    snapshot_sharing_permissions_local_nonprim = domain_config_input_snapshot_sharing_permissions_parseFromJSON(snapshot_sharing_permissions); //nonprimitive
    }


    domain_config_input_local_var = domain_config_input_create_internal (
        android ? android->valueint : 0,
        billing ? billing->valueint : 0,
        organization_name && !cJSON_IsNull(organization_name) ? strdup(organization_name->valuestring) : NULL,
        license_type && !cJSON_IsNull(license_type) ? strdup(license_type->valuestring) : NULL,
        signup_email && !cJSON_IsNull(signup_email) ? strdup(signup_email->valuestring) : NULL,
        coupon_code && !cJSON_IsNull(coupon_code) ? strdup(coupon_code->valuestring) : NULL,
        trial ? trial_local_nonprim : NULL,
        no_ios ? no_ios->valueint : 0,
        device_dhcp_server ? device_dhcp_server->valueint : 0,
        files ? files->valueint : 0,
        files_only ? files_only->valueint : 0,
        remote_gpu ? remote_gpu->valueint : 0,
        prioritized_nodes ? prioritized_nodesList : NULL,
        enable_netgear_devices ? enable_netgear_devices->valueint : 0,
        enable_amazon_devices ? enable_amazon_devices->valueint : 0,
        enable_arm_devices ? enable_arm_devices->valueint : 0,
        enable_devices ? enable_devices->valueint : 0,
        webplayer ? webplayer_local_nonprim : NULL,
        snapshot_sharing_permissions ? snapshot_sharing_permissions_local_nonprim : NULL
        );

    return domain_config_input_local_var;
end:
    if (trial_local_nonprim) {
        domain_config_input_trial_free(trial_local_nonprim);
        trial_local_nonprim = NULL;
    }
    if (prioritized_nodesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, prioritized_nodesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(prioritized_nodesList);
        prioritized_nodesList = NULL;
    }
    if (webplayer_local_nonprim) {
        domain_config_input_webplayer_free(webplayer_local_nonprim);
        webplayer_local_nonprim = NULL;
    }
    if (snapshot_sharing_permissions_local_nonprim) {
        domain_config_input_snapshot_sharing_permissions_free(snapshot_sharing_permissions_local_nonprim);
        snapshot_sharing_permissions_local_nonprim = NULL;
    }
    return NULL;

}
