#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "login_result_domain.h"



static login_result_domain_t *login_result_domain_create_internal(
    char *name,
    char *label,
    char *terms_policy,
    double cores,
    int individual,
    int totp_required,
    object_t *subscription,
    char *license_type,
    int android,
    int no_ios,
    int files_only,
    int device_dhcp_server,
    int enable_arm_devices,
    int use_device_accounting,
    int single_project,
    char *terms_updated,
    login_result_domain_trial_t *trial,
    login_result_domain_webplayer_t *webplayer,
    login_result_domain_snapshot_sharing_permissions_t *snapshot_sharing_permissions,
    login_result_domain_device_auto_shutdown_t *device_auto_shutdown,
    login_result_domain_disabled_t *disabled
    ) {
    login_result_domain_t *login_result_domain_local_var = malloc(sizeof(login_result_domain_t));
    if (!login_result_domain_local_var) {
        return NULL;
    }
    login_result_domain_local_var->name = name;
    login_result_domain_local_var->label = label;
    login_result_domain_local_var->terms_policy = terms_policy;
    login_result_domain_local_var->cores = cores;
    login_result_domain_local_var->individual = individual;
    login_result_domain_local_var->totp_required = totp_required;
    login_result_domain_local_var->subscription = subscription;
    login_result_domain_local_var->license_type = license_type;
    login_result_domain_local_var->android = android;
    login_result_domain_local_var->no_ios = no_ios;
    login_result_domain_local_var->files_only = files_only;
    login_result_domain_local_var->device_dhcp_server = device_dhcp_server;
    login_result_domain_local_var->enable_arm_devices = enable_arm_devices;
    login_result_domain_local_var->use_device_accounting = use_device_accounting;
    login_result_domain_local_var->single_project = single_project;
    login_result_domain_local_var->terms_updated = terms_updated;
    login_result_domain_local_var->trial = trial;
    login_result_domain_local_var->webplayer = webplayer;
    login_result_domain_local_var->snapshot_sharing_permissions = snapshot_sharing_permissions;
    login_result_domain_local_var->device_auto_shutdown = device_auto_shutdown;
    login_result_domain_local_var->disabled = disabled;

    login_result_domain_local_var->_library_owned = 1;
    return login_result_domain_local_var;
}

__attribute__((deprecated)) login_result_domain_t *login_result_domain_create(
    char *name,
    char *label,
    char *terms_policy,
    double cores,
    int individual,
    int totp_required,
    object_t *subscription,
    char *license_type,
    int android,
    int no_ios,
    int files_only,
    int device_dhcp_server,
    int enable_arm_devices,
    int use_device_accounting,
    int single_project,
    char *terms_updated,
    login_result_domain_trial_t *trial,
    login_result_domain_webplayer_t *webplayer,
    login_result_domain_snapshot_sharing_permissions_t *snapshot_sharing_permissions,
    login_result_domain_device_auto_shutdown_t *device_auto_shutdown,
    login_result_domain_disabled_t *disabled
    ) {
    return login_result_domain_create_internal (
        name,
        label,
        terms_policy,
        cores,
        individual,
        totp_required,
        subscription,
        license_type,
        android,
        no_ios,
        files_only,
        device_dhcp_server,
        enable_arm_devices,
        use_device_accounting,
        single_project,
        terms_updated,
        trial,
        webplayer,
        snapshot_sharing_permissions,
        device_auto_shutdown,
        disabled
        );
}

void login_result_domain_free(login_result_domain_t *login_result_domain) {
    if(NULL == login_result_domain){
        return ;
    }
    if(login_result_domain->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "login_result_domain_free");
        return ;
    }
    listEntry_t *listEntry;
    if (login_result_domain->name) {
        free(login_result_domain->name);
        login_result_domain->name = NULL;
    }
    if (login_result_domain->label) {
        free(login_result_domain->label);
        login_result_domain->label = NULL;
    }
    if (login_result_domain->terms_policy) {
        free(login_result_domain->terms_policy);
        login_result_domain->terms_policy = NULL;
    }
    if (login_result_domain->subscription) {
        object_free(login_result_domain->subscription);
        login_result_domain->subscription = NULL;
    }
    if (login_result_domain->license_type) {
        free(login_result_domain->license_type);
        login_result_domain->license_type = NULL;
    }
    if (login_result_domain->terms_updated) {
        free(login_result_domain->terms_updated);
        login_result_domain->terms_updated = NULL;
    }
    if (login_result_domain->trial) {
        login_result_domain_trial_free(login_result_domain->trial);
        login_result_domain->trial = NULL;
    }
    if (login_result_domain->webplayer) {
        login_result_domain_webplayer_free(login_result_domain->webplayer);
        login_result_domain->webplayer = NULL;
    }
    if (login_result_domain->snapshot_sharing_permissions) {
        login_result_domain_snapshot_sharing_permissions_free(login_result_domain->snapshot_sharing_permissions);
        login_result_domain->snapshot_sharing_permissions = NULL;
    }
    if (login_result_domain->device_auto_shutdown) {
        login_result_domain_device_auto_shutdown_free(login_result_domain->device_auto_shutdown);
        login_result_domain->device_auto_shutdown = NULL;
    }
    if (login_result_domain->disabled) {
        login_result_domain_disabled_free(login_result_domain->disabled);
        login_result_domain->disabled = NULL;
    }
    free(login_result_domain);
}

cJSON *login_result_domain_convertToJSON(login_result_domain_t *login_result_domain) {
    cJSON *item = cJSON_CreateObject();

    // login_result_domain->name
    if(login_result_domain->name) {
    if(cJSON_AddStringToObject(item, "name", login_result_domain->name) == NULL) {
    goto fail; //String
    }
    }


    // login_result_domain->label
    if(login_result_domain->label) {
    if(cJSON_AddStringToObject(item, "label", login_result_domain->label) == NULL) {
    goto fail; //String
    }
    }


    // login_result_domain->terms_policy
    if(login_result_domain->terms_policy) {
    if(cJSON_AddStringToObject(item, "termsPolicy", login_result_domain->terms_policy) == NULL) {
    goto fail; //String
    }
    }


    // login_result_domain->cores
    if (!login_result_domain->cores) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "cores", login_result_domain->cores) == NULL) {
    goto fail; //Numeric
    }


    // login_result_domain->individual
    if (!login_result_domain->individual) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "individual", login_result_domain->individual) == NULL) {
    goto fail; //Bool
    }


    // login_result_domain->totp_required
    if(login_result_domain->totp_required) {
    if(cJSON_AddBoolToObject(item, "totpRequired", login_result_domain->totp_required) == NULL) {
    goto fail; //Bool
    }
    }


    // login_result_domain->subscription
    if(login_result_domain->subscription) {
    cJSON *subscription_object = object_convertToJSON(login_result_domain->subscription);
    if(subscription_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "subscription", subscription_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // login_result_domain->license_type
    if(login_result_domain->license_type) {
    if(cJSON_AddStringToObject(item, "licenseType", login_result_domain->license_type) == NULL) {
    goto fail; //String
    }
    }


    // login_result_domain->android
    if(login_result_domain->android) {
    if(cJSON_AddBoolToObject(item, "android", login_result_domain->android) == NULL) {
    goto fail; //Bool
    }
    }


    // login_result_domain->no_ios
    if(login_result_domain->no_ios) {
    if(cJSON_AddBoolToObject(item, "noIOS", login_result_domain->no_ios) == NULL) {
    goto fail; //Bool
    }
    }


    // login_result_domain->files_only
    if(login_result_domain->files_only) {
    if(cJSON_AddBoolToObject(item, "filesOnly", login_result_domain->files_only) == NULL) {
    goto fail; //Bool
    }
    }


    // login_result_domain->device_dhcp_server
    if(login_result_domain->device_dhcp_server) {
    if(cJSON_AddBoolToObject(item, "deviceDHCPServer", login_result_domain->device_dhcp_server) == NULL) {
    goto fail; //Bool
    }
    }


    // login_result_domain->enable_arm_devices
    if(login_result_domain->enable_arm_devices) {
    if(cJSON_AddBoolToObject(item, "enableArmDevices", login_result_domain->enable_arm_devices) == NULL) {
    goto fail; //Bool
    }
    }


    // login_result_domain->use_device_accounting
    if(login_result_domain->use_device_accounting) {
    if(cJSON_AddBoolToObject(item, "useDeviceAccounting", login_result_domain->use_device_accounting) == NULL) {
    goto fail; //Bool
    }
    }


    // login_result_domain->single_project
    if(login_result_domain->single_project) {
    if(cJSON_AddBoolToObject(item, "singleProject", login_result_domain->single_project) == NULL) {
    goto fail; //Bool
    }
    }


    // login_result_domain->terms_updated
    if(login_result_domain->terms_updated) {
    if(cJSON_AddStringToObject(item, "termsUpdated", login_result_domain->terms_updated) == NULL) {
    goto fail; //String
    }
    }


    // login_result_domain->trial
    if(login_result_domain->trial) {
    cJSON *trial_local_JSON = login_result_domain_trial_convertToJSON(login_result_domain->trial);
    if(trial_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "trial", trial_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // login_result_domain->webplayer
    if(login_result_domain->webplayer) {
    cJSON *webplayer_local_JSON = login_result_domain_webplayer_convertToJSON(login_result_domain->webplayer);
    if(webplayer_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "webplayer", webplayer_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // login_result_domain->snapshot_sharing_permissions
    if(login_result_domain->snapshot_sharing_permissions) {
    cJSON *snapshot_sharing_permissions_local_JSON = login_result_domain_snapshot_sharing_permissions_convertToJSON(login_result_domain->snapshot_sharing_permissions);
    if(snapshot_sharing_permissions_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "snapshotSharingPermissions", snapshot_sharing_permissions_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // login_result_domain->device_auto_shutdown
    if(login_result_domain->device_auto_shutdown) {
    cJSON *device_auto_shutdown_local_JSON = login_result_domain_device_auto_shutdown_convertToJSON(login_result_domain->device_auto_shutdown);
    if(device_auto_shutdown_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "deviceAutoShutdown", device_auto_shutdown_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // login_result_domain->disabled
    if(login_result_domain->disabled) {
    cJSON *disabled_local_JSON = login_result_domain_disabled_convertToJSON(login_result_domain->disabled);
    if(disabled_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "disabled", disabled_local_JSON);
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

login_result_domain_t *login_result_domain_parseFromJSON(cJSON *login_result_domainJSON){

    login_result_domain_t *login_result_domain_local_var = NULL;

    // define the local variable for login_result_domain->trial
    login_result_domain_trial_t *trial_local_nonprim = NULL;

    // define the local variable for login_result_domain->webplayer
    login_result_domain_webplayer_t *webplayer_local_nonprim = NULL;

    // define the local variable for login_result_domain->snapshot_sharing_permissions
    login_result_domain_snapshot_sharing_permissions_t *snapshot_sharing_permissions_local_nonprim = NULL;

    // define the local variable for login_result_domain->device_auto_shutdown
    login_result_domain_device_auto_shutdown_t *device_auto_shutdown_local_nonprim = NULL;

    // define the local variable for login_result_domain->disabled
    login_result_domain_disabled_t *disabled_local_nonprim = NULL;

    // login_result_domain->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(login_result_domainJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // login_result_domain->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(login_result_domainJSON, "label");
    if (cJSON_IsNull(label)) {
        label = NULL;
    }
    if (label) { 
    if(!cJSON_IsString(label) && !cJSON_IsNull(label))
    {
    goto end; //String
    }
    }

    // login_result_domain->terms_policy
    cJSON *terms_policy = cJSON_GetObjectItemCaseSensitive(login_result_domainJSON, "termsPolicy");
    if (cJSON_IsNull(terms_policy)) {
        terms_policy = NULL;
    }
    if (terms_policy) { 
    if(!cJSON_IsString(terms_policy) && !cJSON_IsNull(terms_policy))
    {
    goto end; //String
    }
    }

    // login_result_domain->cores
    cJSON *cores = cJSON_GetObjectItemCaseSensitive(login_result_domainJSON, "cores");
    if (cJSON_IsNull(cores)) {
        cores = NULL;
    }
    if (!cores) {
        goto end;
    }

    
    if(!cJSON_IsNumber(cores))
    {
    goto end; //Numeric
    }

    // login_result_domain->individual
    cJSON *individual = cJSON_GetObjectItemCaseSensitive(login_result_domainJSON, "individual");
    if (cJSON_IsNull(individual)) {
        individual = NULL;
    }
    if (!individual) {
        goto end;
    }

    
    if(!cJSON_IsBool(individual))
    {
    goto end; //Bool
    }

    // login_result_domain->totp_required
    cJSON *totp_required = cJSON_GetObjectItemCaseSensitive(login_result_domainJSON, "totpRequired");
    if (cJSON_IsNull(totp_required)) {
        totp_required = NULL;
    }
    if (totp_required) { 
    if(!cJSON_IsBool(totp_required))
    {
    goto end; //Bool
    }
    }

    // login_result_domain->subscription
    cJSON *subscription = cJSON_GetObjectItemCaseSensitive(login_result_domainJSON, "subscription");
    if (cJSON_IsNull(subscription)) {
        subscription = NULL;
    }
    object_t *subscription_local_object = NULL;
    if (subscription) { 
    subscription_local_object = object_parseFromJSON(subscription); //object
    }

    // login_result_domain->license_type
    cJSON *license_type = cJSON_GetObjectItemCaseSensitive(login_result_domainJSON, "licenseType");
    if (cJSON_IsNull(license_type)) {
        license_type = NULL;
    }
    if (license_type) { 
    if(!cJSON_IsString(license_type) && !cJSON_IsNull(license_type))
    {
    goto end; //String
    }
    }

    // login_result_domain->android
    cJSON *android = cJSON_GetObjectItemCaseSensitive(login_result_domainJSON, "android");
    if (cJSON_IsNull(android)) {
        android = NULL;
    }
    if (android) { 
    if(!cJSON_IsBool(android))
    {
    goto end; //Bool
    }
    }

    // login_result_domain->no_ios
    cJSON *no_ios = cJSON_GetObjectItemCaseSensitive(login_result_domainJSON, "noIOS");
    if (cJSON_IsNull(no_ios)) {
        no_ios = NULL;
    }
    if (no_ios) { 
    if(!cJSON_IsBool(no_ios))
    {
    goto end; //Bool
    }
    }

    // login_result_domain->files_only
    cJSON *files_only = cJSON_GetObjectItemCaseSensitive(login_result_domainJSON, "filesOnly");
    if (cJSON_IsNull(files_only)) {
        files_only = NULL;
    }
    if (files_only) { 
    if(!cJSON_IsBool(files_only))
    {
    goto end; //Bool
    }
    }

    // login_result_domain->device_dhcp_server
    cJSON *device_dhcp_server = cJSON_GetObjectItemCaseSensitive(login_result_domainJSON, "deviceDHCPServer");
    if (cJSON_IsNull(device_dhcp_server)) {
        device_dhcp_server = NULL;
    }
    if (device_dhcp_server) { 
    if(!cJSON_IsBool(device_dhcp_server))
    {
    goto end; //Bool
    }
    }

    // login_result_domain->enable_arm_devices
    cJSON *enable_arm_devices = cJSON_GetObjectItemCaseSensitive(login_result_domainJSON, "enableArmDevices");
    if (cJSON_IsNull(enable_arm_devices)) {
        enable_arm_devices = NULL;
    }
    if (enable_arm_devices) { 
    if(!cJSON_IsBool(enable_arm_devices))
    {
    goto end; //Bool
    }
    }

    // login_result_domain->use_device_accounting
    cJSON *use_device_accounting = cJSON_GetObjectItemCaseSensitive(login_result_domainJSON, "useDeviceAccounting");
    if (cJSON_IsNull(use_device_accounting)) {
        use_device_accounting = NULL;
    }
    if (use_device_accounting) { 
    if(!cJSON_IsBool(use_device_accounting))
    {
    goto end; //Bool
    }
    }

    // login_result_domain->single_project
    cJSON *single_project = cJSON_GetObjectItemCaseSensitive(login_result_domainJSON, "singleProject");
    if (cJSON_IsNull(single_project)) {
        single_project = NULL;
    }
    if (single_project) { 
    if(!cJSON_IsBool(single_project))
    {
    goto end; //Bool
    }
    }

    // login_result_domain->terms_updated
    cJSON *terms_updated = cJSON_GetObjectItemCaseSensitive(login_result_domainJSON, "termsUpdated");
    if (cJSON_IsNull(terms_updated)) {
        terms_updated = NULL;
    }
    if (terms_updated) { 
    if(!cJSON_IsString(terms_updated) && !cJSON_IsNull(terms_updated))
    {
    goto end; //String
    }
    }

    // login_result_domain->trial
    cJSON *trial = cJSON_GetObjectItemCaseSensitive(login_result_domainJSON, "trial");
    if (cJSON_IsNull(trial)) {
        trial = NULL;
    }
    if (trial) { 
    trial_local_nonprim = login_result_domain_trial_parseFromJSON(trial); //nonprimitive
    }

    // login_result_domain->webplayer
    cJSON *webplayer = cJSON_GetObjectItemCaseSensitive(login_result_domainJSON, "webplayer");
    if (cJSON_IsNull(webplayer)) {
        webplayer = NULL;
    }
    if (webplayer) { 
    webplayer_local_nonprim = login_result_domain_webplayer_parseFromJSON(webplayer); //nonprimitive
    }

    // login_result_domain->snapshot_sharing_permissions
    cJSON *snapshot_sharing_permissions = cJSON_GetObjectItemCaseSensitive(login_result_domainJSON, "snapshotSharingPermissions");
    if (cJSON_IsNull(snapshot_sharing_permissions)) {
        snapshot_sharing_permissions = NULL;
    }
    if (snapshot_sharing_permissions) { 
    snapshot_sharing_permissions_local_nonprim = login_result_domain_snapshot_sharing_permissions_parseFromJSON(snapshot_sharing_permissions); //nonprimitive
    }

    // login_result_domain->device_auto_shutdown
    cJSON *device_auto_shutdown = cJSON_GetObjectItemCaseSensitive(login_result_domainJSON, "deviceAutoShutdown");
    if (cJSON_IsNull(device_auto_shutdown)) {
        device_auto_shutdown = NULL;
    }
    if (device_auto_shutdown) { 
    device_auto_shutdown_local_nonprim = login_result_domain_device_auto_shutdown_parseFromJSON(device_auto_shutdown); //nonprimitive
    }

    // login_result_domain->disabled
    cJSON *disabled = cJSON_GetObjectItemCaseSensitive(login_result_domainJSON, "disabled");
    if (cJSON_IsNull(disabled)) {
        disabled = NULL;
    }
    if (disabled) { 
    disabled_local_nonprim = login_result_domain_disabled_parseFromJSON(disabled); //nonprimitive
    }


    login_result_domain_local_var = login_result_domain_create_internal (
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        label && !cJSON_IsNull(label) ? strdup(label->valuestring) : NULL,
        terms_policy && !cJSON_IsNull(terms_policy) ? strdup(terms_policy->valuestring) : NULL,
        cores->valuedouble,
        individual->valueint,
        totp_required ? totp_required->valueint : 0,
        subscription ? subscription_local_object : NULL,
        license_type && !cJSON_IsNull(license_type) ? strdup(license_type->valuestring) : NULL,
        android ? android->valueint : 0,
        no_ios ? no_ios->valueint : 0,
        files_only ? files_only->valueint : 0,
        device_dhcp_server ? device_dhcp_server->valueint : 0,
        enable_arm_devices ? enable_arm_devices->valueint : 0,
        use_device_accounting ? use_device_accounting->valueint : 0,
        single_project ? single_project->valueint : 0,
        terms_updated && !cJSON_IsNull(terms_updated) ? strdup(terms_updated->valuestring) : NULL,
        trial ? trial_local_nonprim : NULL,
        webplayer ? webplayer_local_nonprim : NULL,
        snapshot_sharing_permissions ? snapshot_sharing_permissions_local_nonprim : NULL,
        device_auto_shutdown ? device_auto_shutdown_local_nonprim : NULL,
        disabled ? disabled_local_nonprim : NULL
        );

    return login_result_domain_local_var;
end:
    if (trial_local_nonprim) {
        login_result_domain_trial_free(trial_local_nonprim);
        trial_local_nonprim = NULL;
    }
    if (webplayer_local_nonprim) {
        login_result_domain_webplayer_free(webplayer_local_nonprim);
        webplayer_local_nonprim = NULL;
    }
    if (snapshot_sharing_permissions_local_nonprim) {
        login_result_domain_snapshot_sharing_permissions_free(snapshot_sharing_permissions_local_nonprim);
        snapshot_sharing_permissions_local_nonprim = NULL;
    }
    if (device_auto_shutdown_local_nonprim) {
        login_result_domain_device_auto_shutdown_free(device_auto_shutdown_local_nonprim);
        device_auto_shutdown_local_nonprim = NULL;
    }
    if (disabled_local_nonprim) {
        login_result_domain_disabled_free(disabled_local_nonprim);
        disabled_local_nonprim = NULL;
    }
    return NULL;

}
