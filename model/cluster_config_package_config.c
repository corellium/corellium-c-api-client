#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cluster_config_package_config.h"


char* cluster_config_package_config_network_type_ToString(corellium_api_cluster_config_package_config_NETWORKTYPE_e network_type) {
    char* network_typeArray[] =  { "NULL", "bridged", "nat", "routed" };
    return network_typeArray[network_type];
}

corellium_api_cluster_config_package_config_NETWORKTYPE_e cluster_config_package_config_network_type_FromString(char* network_type){
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

static cluster_config_package_config_t *cluster_config_package_config_create_internal(
    char *license_type,
    char *cluster_id,
    corellium_api_cluster_config_package_config_NETWORKTYPE_e network_type,
    object_t *physical_interfaces,
    cluster_config_package_config_features_t *features,
    cluster_config_package_config_components_t *components,
    char *terms_of_service,
    int domain_authentication_providers,
    char *max_network_monitor_file_size,
    int combined,
    list_t *flavor_filters,
    int charm_sdk,
    int highly_available,
    char *node_version,
    int invalid_build,
    int sep_sim,
    int kernel_gdb,
    int android,
    int no_ios,
    int ios_betas,
    int charm_modules,
    int btrace,
    int strace,
    int game_streaming,
    char *container_template_generation,
    int s3_supported
    ) {
    cluster_config_package_config_t *cluster_config_package_config_local_var = malloc(sizeof(cluster_config_package_config_t));
    if (!cluster_config_package_config_local_var) {
        return NULL;
    }
    cluster_config_package_config_local_var->license_type = license_type;
    cluster_config_package_config_local_var->cluster_id = cluster_id;
    cluster_config_package_config_local_var->network_type = network_type;
    cluster_config_package_config_local_var->physical_interfaces = physical_interfaces;
    cluster_config_package_config_local_var->features = features;
    cluster_config_package_config_local_var->components = components;
    cluster_config_package_config_local_var->terms_of_service = terms_of_service;
    cluster_config_package_config_local_var->domain_authentication_providers = domain_authentication_providers;
    cluster_config_package_config_local_var->max_network_monitor_file_size = max_network_monitor_file_size;
    cluster_config_package_config_local_var->combined = combined;
    cluster_config_package_config_local_var->flavor_filters = flavor_filters;
    cluster_config_package_config_local_var->charm_sdk = charm_sdk;
    cluster_config_package_config_local_var->highly_available = highly_available;
    cluster_config_package_config_local_var->node_version = node_version;
    cluster_config_package_config_local_var->invalid_build = invalid_build;
    cluster_config_package_config_local_var->sep_sim = sep_sim;
    cluster_config_package_config_local_var->kernel_gdb = kernel_gdb;
    cluster_config_package_config_local_var->android = android;
    cluster_config_package_config_local_var->no_ios = no_ios;
    cluster_config_package_config_local_var->ios_betas = ios_betas;
    cluster_config_package_config_local_var->charm_modules = charm_modules;
    cluster_config_package_config_local_var->btrace = btrace;
    cluster_config_package_config_local_var->strace = strace;
    cluster_config_package_config_local_var->game_streaming = game_streaming;
    cluster_config_package_config_local_var->container_template_generation = container_template_generation;
    cluster_config_package_config_local_var->s3_supported = s3_supported;

    cluster_config_package_config_local_var->_library_owned = 1;
    return cluster_config_package_config_local_var;
}

__attribute__((deprecated)) cluster_config_package_config_t *cluster_config_package_config_create(
    char *license_type,
    char *cluster_id,
    corellium_api_cluster_config_package_config_NETWORKTYPE_e network_type,
    object_t *physical_interfaces,
    cluster_config_package_config_features_t *features,
    cluster_config_package_config_components_t *components,
    char *terms_of_service,
    int domain_authentication_providers,
    char *max_network_monitor_file_size,
    int combined,
    list_t *flavor_filters,
    int charm_sdk,
    int highly_available,
    char *node_version,
    int invalid_build,
    int sep_sim,
    int kernel_gdb,
    int android,
    int no_ios,
    int ios_betas,
    int charm_modules,
    int btrace,
    int strace,
    int game_streaming,
    char *container_template_generation,
    int s3_supported
    ) {
    return cluster_config_package_config_create_internal (
        license_type,
        cluster_id,
        network_type,
        physical_interfaces,
        features,
        components,
        terms_of_service,
        domain_authentication_providers,
        max_network_monitor_file_size,
        combined,
        flavor_filters,
        charm_sdk,
        highly_available,
        node_version,
        invalid_build,
        sep_sim,
        kernel_gdb,
        android,
        no_ios,
        ios_betas,
        charm_modules,
        btrace,
        strace,
        game_streaming,
        container_template_generation,
        s3_supported
        );
}

void cluster_config_package_config_free(cluster_config_package_config_t *cluster_config_package_config) {
    if(NULL == cluster_config_package_config){
        return ;
    }
    if(cluster_config_package_config->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cluster_config_package_config_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cluster_config_package_config->license_type) {
        free(cluster_config_package_config->license_type);
        cluster_config_package_config->license_type = NULL;
    }
    if (cluster_config_package_config->cluster_id) {
        free(cluster_config_package_config->cluster_id);
        cluster_config_package_config->cluster_id = NULL;
    }
    if (cluster_config_package_config->physical_interfaces) {
        object_free(cluster_config_package_config->physical_interfaces);
        cluster_config_package_config->physical_interfaces = NULL;
    }
    if (cluster_config_package_config->features) {
        cluster_config_package_config_features_free(cluster_config_package_config->features);
        cluster_config_package_config->features = NULL;
    }
    if (cluster_config_package_config->components) {
        cluster_config_package_config_components_free(cluster_config_package_config->components);
        cluster_config_package_config->components = NULL;
    }
    if (cluster_config_package_config->terms_of_service) {
        free(cluster_config_package_config->terms_of_service);
        cluster_config_package_config->terms_of_service = NULL;
    }
    if (cluster_config_package_config->max_network_monitor_file_size) {
        free(cluster_config_package_config->max_network_monitor_file_size);
        cluster_config_package_config->max_network_monitor_file_size = NULL;
    }
    if (cluster_config_package_config->flavor_filters) {
        list_ForEach(listEntry, cluster_config_package_config->flavor_filters) {
            cluster_config_package_config_flavor_filters_inner_free(listEntry->data);
        }
        list_freeList(cluster_config_package_config->flavor_filters);
        cluster_config_package_config->flavor_filters = NULL;
    }
    if (cluster_config_package_config->node_version) {
        free(cluster_config_package_config->node_version);
        cluster_config_package_config->node_version = NULL;
    }
    if (cluster_config_package_config->container_template_generation) {
        free(cluster_config_package_config->container_template_generation);
        cluster_config_package_config->container_template_generation = NULL;
    }
    free(cluster_config_package_config);
}

cJSON *cluster_config_package_config_convertToJSON(cluster_config_package_config_t *cluster_config_package_config) {
    cJSON *item = cJSON_CreateObject();

    // cluster_config_package_config->license_type
    if(cluster_config_package_config->license_type) {
    if(cJSON_AddStringToObject(item, "licenseType", cluster_config_package_config->license_type) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config_package_config->cluster_id
    if(cluster_config_package_config->cluster_id) {
    if(cJSON_AddStringToObject(item, "clusterId", cluster_config_package_config->cluster_id) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config_package_config->network_type
    if(cluster_config_package_config->network_type != corellium_api_cluster_config_package_config_NETWORKTYPE_NULL) {
    if(cJSON_AddStringToObject(item, "networkType", cluster_config_package_config_network_type_ToString(cluster_config_package_config->network_type)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // cluster_config_package_config->physical_interfaces
    if(cluster_config_package_config->physical_interfaces) {
    cJSON *physical_interfaces_object = object_convertToJSON(cluster_config_package_config->physical_interfaces);
    if(physical_interfaces_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "physicalInterfaces", physical_interfaces_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // cluster_config_package_config->features
    if(cluster_config_package_config->features) {
    cJSON *features_local_JSON = cluster_config_package_config_features_convertToJSON(cluster_config_package_config->features);
    if(features_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "features", features_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // cluster_config_package_config->components
    if(cluster_config_package_config->components) {
    cJSON *components_local_JSON = cluster_config_package_config_components_convertToJSON(cluster_config_package_config->components);
    if(components_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "components", components_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // cluster_config_package_config->terms_of_service
    if(cluster_config_package_config->terms_of_service) {
    if(cJSON_AddStringToObject(item, "termsOfService", cluster_config_package_config->terms_of_service) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config_package_config->domain_authentication_providers
    if(cluster_config_package_config->domain_authentication_providers) {
    if(cJSON_AddBoolToObject(item, "domainAuthenticationProviders", cluster_config_package_config->domain_authentication_providers) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_package_config->max_network_monitor_file_size
    if(cluster_config_package_config->max_network_monitor_file_size) {
    if(cJSON_AddStringToObject(item, "maxNetworkMonitorFileSize", cluster_config_package_config->max_network_monitor_file_size) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config_package_config->combined
    if(cluster_config_package_config->combined) {
    if(cJSON_AddBoolToObject(item, "combined", cluster_config_package_config->combined) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_package_config->flavor_filters
    if (!cluster_config_package_config->flavor_filters) {
        goto fail;
    }
    cJSON *flavor_filters = cJSON_AddArrayToObject(item, "flavorFilters");
    if(flavor_filters == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *flavor_filtersListEntry;
    if (cluster_config_package_config->flavor_filters) {
    list_ForEach(flavor_filtersListEntry, cluster_config_package_config->flavor_filters) {
    cJSON *itemLocal = cluster_config_package_config_flavor_filters_inner_convertToJSON(flavor_filtersListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(flavor_filters, itemLocal);
    }
    }


    // cluster_config_package_config->charm_sdk
    if(cluster_config_package_config->charm_sdk) {
    if(cJSON_AddBoolToObject(item, "charmSDK", cluster_config_package_config->charm_sdk) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_package_config->highly_available
    if(cluster_config_package_config->highly_available) {
    if(cJSON_AddBoolToObject(item, "highlyAvailable", cluster_config_package_config->highly_available) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_package_config->node_version
    if(cluster_config_package_config->node_version) {
    if(cJSON_AddStringToObject(item, "nodeVersion", cluster_config_package_config->node_version) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config_package_config->invalid_build
    if(cluster_config_package_config->invalid_build) {
    if(cJSON_AddBoolToObject(item, "invalidBuild", cluster_config_package_config->invalid_build) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_package_config->sep_sim
    if(cluster_config_package_config->sep_sim) {
    if(cJSON_AddBoolToObject(item, "sepSim", cluster_config_package_config->sep_sim) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_package_config->kernel_gdb
    if(cluster_config_package_config->kernel_gdb) {
    if(cJSON_AddBoolToObject(item, "kernelGDB", cluster_config_package_config->kernel_gdb) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_package_config->android
    if(cluster_config_package_config->android) {
    if(cJSON_AddBoolToObject(item, "android", cluster_config_package_config->android) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_package_config->no_ios
    if(cluster_config_package_config->no_ios) {
    if(cJSON_AddBoolToObject(item, "noIOS", cluster_config_package_config->no_ios) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_package_config->ios_betas
    if(cluster_config_package_config->ios_betas) {
    if(cJSON_AddBoolToObject(item, "iosBetas", cluster_config_package_config->ios_betas) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_package_config->charm_modules
    if(cluster_config_package_config->charm_modules) {
    if(cJSON_AddBoolToObject(item, "charmModules", cluster_config_package_config->charm_modules) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_package_config->btrace
    if(cluster_config_package_config->btrace) {
    if(cJSON_AddBoolToObject(item, "btrace", cluster_config_package_config->btrace) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_package_config->strace
    if(cluster_config_package_config->strace) {
    if(cJSON_AddBoolToObject(item, "strace", cluster_config_package_config->strace) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_package_config->game_streaming
    if(cluster_config_package_config->game_streaming) {
    if(cJSON_AddBoolToObject(item, "gameStreaming", cluster_config_package_config->game_streaming) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_package_config->container_template_generation
    if(cluster_config_package_config->container_template_generation) {
    if(cJSON_AddStringToObject(item, "containerTemplateGeneration", cluster_config_package_config->container_template_generation) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config_package_config->s3_supported
    if(cluster_config_package_config->s3_supported) {
    if(cJSON_AddBoolToObject(item, "s3Supported", cluster_config_package_config->s3_supported) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

cluster_config_package_config_t *cluster_config_package_config_parseFromJSON(cJSON *cluster_config_package_configJSON){

    cluster_config_package_config_t *cluster_config_package_config_local_var = NULL;

    // define the local variable for cluster_config_package_config->features
    cluster_config_package_config_features_t *features_local_nonprim = NULL;

    // define the local variable for cluster_config_package_config->components
    cluster_config_package_config_components_t *components_local_nonprim = NULL;

    // define the local list for cluster_config_package_config->flavor_filters
    list_t *flavor_filtersList = NULL;

    // cluster_config_package_config->license_type
    cJSON *license_type = cJSON_GetObjectItemCaseSensitive(cluster_config_package_configJSON, "licenseType");
    if (cJSON_IsNull(license_type)) {
        license_type = NULL;
    }
    if (license_type) { 
    if(!cJSON_IsString(license_type) && !cJSON_IsNull(license_type))
    {
    goto end; //String
    }
    }

    // cluster_config_package_config->cluster_id
    cJSON *cluster_id = cJSON_GetObjectItemCaseSensitive(cluster_config_package_configJSON, "clusterId");
    if (cJSON_IsNull(cluster_id)) {
        cluster_id = NULL;
    }
    if (cluster_id) { 
    if(!cJSON_IsString(cluster_id) && !cJSON_IsNull(cluster_id))
    {
    goto end; //String
    }
    }

    // cluster_config_package_config->network_type
    cJSON *network_type = cJSON_GetObjectItemCaseSensitive(cluster_config_package_configJSON, "networkType");
    if (cJSON_IsNull(network_type)) {
        network_type = NULL;
    }
    corellium_api_cluster_config_package_config_NETWORKTYPE_e network_typeVariable;
    if (network_type) { 
    if(!cJSON_IsString(network_type))
    {
    goto end; //Enum
    }
    network_typeVariable = cluster_config_package_config_network_type_FromString(network_type->valuestring);
    }

    // cluster_config_package_config->physical_interfaces
    cJSON *physical_interfaces = cJSON_GetObjectItemCaseSensitive(cluster_config_package_configJSON, "physicalInterfaces");
    if (cJSON_IsNull(physical_interfaces)) {
        physical_interfaces = NULL;
    }
    object_t *physical_interfaces_local_object = NULL;
    if (physical_interfaces) { 
    physical_interfaces_local_object = object_parseFromJSON(physical_interfaces); //object
    }

    // cluster_config_package_config->features
    cJSON *features = cJSON_GetObjectItemCaseSensitive(cluster_config_package_configJSON, "features");
    if (cJSON_IsNull(features)) {
        features = NULL;
    }
    if (features) { 
    features_local_nonprim = cluster_config_package_config_features_parseFromJSON(features); //nonprimitive
    }

    // cluster_config_package_config->components
    cJSON *components = cJSON_GetObjectItemCaseSensitive(cluster_config_package_configJSON, "components");
    if (cJSON_IsNull(components)) {
        components = NULL;
    }
    if (components) { 
    components_local_nonprim = cluster_config_package_config_components_parseFromJSON(components); //nonprimitive
    }

    // cluster_config_package_config->terms_of_service
    cJSON *terms_of_service = cJSON_GetObjectItemCaseSensitive(cluster_config_package_configJSON, "termsOfService");
    if (cJSON_IsNull(terms_of_service)) {
        terms_of_service = NULL;
    }
    if (terms_of_service) { 
    if(!cJSON_IsString(terms_of_service) && !cJSON_IsNull(terms_of_service))
    {
    goto end; //String
    }
    }

    // cluster_config_package_config->domain_authentication_providers
    cJSON *domain_authentication_providers = cJSON_GetObjectItemCaseSensitive(cluster_config_package_configJSON, "domainAuthenticationProviders");
    if (cJSON_IsNull(domain_authentication_providers)) {
        domain_authentication_providers = NULL;
    }
    if (domain_authentication_providers) { 
    if(!cJSON_IsBool(domain_authentication_providers))
    {
    goto end; //Bool
    }
    }

    // cluster_config_package_config->max_network_monitor_file_size
    cJSON *max_network_monitor_file_size = cJSON_GetObjectItemCaseSensitive(cluster_config_package_configJSON, "maxNetworkMonitorFileSize");
    if (cJSON_IsNull(max_network_monitor_file_size)) {
        max_network_monitor_file_size = NULL;
    }
    if (max_network_monitor_file_size) { 
    if(!cJSON_IsString(max_network_monitor_file_size) && !cJSON_IsNull(max_network_monitor_file_size))
    {
    goto end; //String
    }
    }

    // cluster_config_package_config->combined
    cJSON *combined = cJSON_GetObjectItemCaseSensitive(cluster_config_package_configJSON, "combined");
    if (cJSON_IsNull(combined)) {
        combined = NULL;
    }
    if (combined) { 
    if(!cJSON_IsBool(combined))
    {
    goto end; //Bool
    }
    }

    // cluster_config_package_config->flavor_filters
    cJSON *flavor_filters = cJSON_GetObjectItemCaseSensitive(cluster_config_package_configJSON, "flavorFilters");
    if (cJSON_IsNull(flavor_filters)) {
        flavor_filters = NULL;
    }
    if (!flavor_filters) {
        goto end;
    }

    
    cJSON *flavor_filters_local_nonprimitive = NULL;
    if(!cJSON_IsArray(flavor_filters)){
        goto end; //nonprimitive container
    }

    flavor_filtersList = list_createList();

    cJSON_ArrayForEach(flavor_filters_local_nonprimitive,flavor_filters )
    {
        if(!cJSON_IsObject(flavor_filters_local_nonprimitive)){
            goto end;
        }
        cluster_config_package_config_flavor_filters_inner_t *flavor_filtersItem = cluster_config_package_config_flavor_filters_inner_parseFromJSON(flavor_filters_local_nonprimitive);

        list_addElement(flavor_filtersList, flavor_filtersItem);
    }

    // cluster_config_package_config->charm_sdk
    cJSON *charm_sdk = cJSON_GetObjectItemCaseSensitive(cluster_config_package_configJSON, "charmSDK");
    if (cJSON_IsNull(charm_sdk)) {
        charm_sdk = NULL;
    }
    if (charm_sdk) { 
    if(!cJSON_IsBool(charm_sdk))
    {
    goto end; //Bool
    }
    }

    // cluster_config_package_config->highly_available
    cJSON *highly_available = cJSON_GetObjectItemCaseSensitive(cluster_config_package_configJSON, "highlyAvailable");
    if (cJSON_IsNull(highly_available)) {
        highly_available = NULL;
    }
    if (highly_available) { 
    if(!cJSON_IsBool(highly_available))
    {
    goto end; //Bool
    }
    }

    // cluster_config_package_config->node_version
    cJSON *node_version = cJSON_GetObjectItemCaseSensitive(cluster_config_package_configJSON, "nodeVersion");
    if (cJSON_IsNull(node_version)) {
        node_version = NULL;
    }
    if (node_version) { 
    if(!cJSON_IsString(node_version) && !cJSON_IsNull(node_version))
    {
    goto end; //String
    }
    }

    // cluster_config_package_config->invalid_build
    cJSON *invalid_build = cJSON_GetObjectItemCaseSensitive(cluster_config_package_configJSON, "invalidBuild");
    if (cJSON_IsNull(invalid_build)) {
        invalid_build = NULL;
    }
    if (invalid_build) { 
    if(!cJSON_IsBool(invalid_build))
    {
    goto end; //Bool
    }
    }

    // cluster_config_package_config->sep_sim
    cJSON *sep_sim = cJSON_GetObjectItemCaseSensitive(cluster_config_package_configJSON, "sepSim");
    if (cJSON_IsNull(sep_sim)) {
        sep_sim = NULL;
    }
    if (sep_sim) { 
    if(!cJSON_IsBool(sep_sim))
    {
    goto end; //Bool
    }
    }

    // cluster_config_package_config->kernel_gdb
    cJSON *kernel_gdb = cJSON_GetObjectItemCaseSensitive(cluster_config_package_configJSON, "kernelGDB");
    if (cJSON_IsNull(kernel_gdb)) {
        kernel_gdb = NULL;
    }
    if (kernel_gdb) { 
    if(!cJSON_IsBool(kernel_gdb))
    {
    goto end; //Bool
    }
    }

    // cluster_config_package_config->android
    cJSON *android = cJSON_GetObjectItemCaseSensitive(cluster_config_package_configJSON, "android");
    if (cJSON_IsNull(android)) {
        android = NULL;
    }
    if (android) { 
    if(!cJSON_IsBool(android))
    {
    goto end; //Bool
    }
    }

    // cluster_config_package_config->no_ios
    cJSON *no_ios = cJSON_GetObjectItemCaseSensitive(cluster_config_package_configJSON, "noIOS");
    if (cJSON_IsNull(no_ios)) {
        no_ios = NULL;
    }
    if (no_ios) { 
    if(!cJSON_IsBool(no_ios))
    {
    goto end; //Bool
    }
    }

    // cluster_config_package_config->ios_betas
    cJSON *ios_betas = cJSON_GetObjectItemCaseSensitive(cluster_config_package_configJSON, "iosBetas");
    if (cJSON_IsNull(ios_betas)) {
        ios_betas = NULL;
    }
    if (ios_betas) { 
    if(!cJSON_IsBool(ios_betas))
    {
    goto end; //Bool
    }
    }

    // cluster_config_package_config->charm_modules
    cJSON *charm_modules = cJSON_GetObjectItemCaseSensitive(cluster_config_package_configJSON, "charmModules");
    if (cJSON_IsNull(charm_modules)) {
        charm_modules = NULL;
    }
    if (charm_modules) { 
    if(!cJSON_IsBool(charm_modules))
    {
    goto end; //Bool
    }
    }

    // cluster_config_package_config->btrace
    cJSON *btrace = cJSON_GetObjectItemCaseSensitive(cluster_config_package_configJSON, "btrace");
    if (cJSON_IsNull(btrace)) {
        btrace = NULL;
    }
    if (btrace) { 
    if(!cJSON_IsBool(btrace))
    {
    goto end; //Bool
    }
    }

    // cluster_config_package_config->strace
    cJSON *strace = cJSON_GetObjectItemCaseSensitive(cluster_config_package_configJSON, "strace");
    if (cJSON_IsNull(strace)) {
        strace = NULL;
    }
    if (strace) { 
    if(!cJSON_IsBool(strace))
    {
    goto end; //Bool
    }
    }

    // cluster_config_package_config->game_streaming
    cJSON *game_streaming = cJSON_GetObjectItemCaseSensitive(cluster_config_package_configJSON, "gameStreaming");
    if (cJSON_IsNull(game_streaming)) {
        game_streaming = NULL;
    }
    if (game_streaming) { 
    if(!cJSON_IsBool(game_streaming))
    {
    goto end; //Bool
    }
    }

    // cluster_config_package_config->container_template_generation
    cJSON *container_template_generation = cJSON_GetObjectItemCaseSensitive(cluster_config_package_configJSON, "containerTemplateGeneration");
    if (cJSON_IsNull(container_template_generation)) {
        container_template_generation = NULL;
    }
    if (container_template_generation) { 
    if(!cJSON_IsString(container_template_generation) && !cJSON_IsNull(container_template_generation))
    {
    goto end; //String
    }
    }

    // cluster_config_package_config->s3_supported
    cJSON *s3_supported = cJSON_GetObjectItemCaseSensitive(cluster_config_package_configJSON, "s3Supported");
    if (cJSON_IsNull(s3_supported)) {
        s3_supported = NULL;
    }
    if (s3_supported) { 
    if(!cJSON_IsBool(s3_supported))
    {
    goto end; //Bool
    }
    }


    cluster_config_package_config_local_var = cluster_config_package_config_create_internal (
        license_type && !cJSON_IsNull(license_type) ? strdup(license_type->valuestring) : NULL,
        cluster_id && !cJSON_IsNull(cluster_id) ? strdup(cluster_id->valuestring) : NULL,
        network_type ? network_typeVariable : corellium_api_cluster_config_package_config_NETWORKTYPE_NULL,
        physical_interfaces ? physical_interfaces_local_object : NULL,
        features ? features_local_nonprim : NULL,
        components ? components_local_nonprim : NULL,
        terms_of_service && !cJSON_IsNull(terms_of_service) ? strdup(terms_of_service->valuestring) : NULL,
        domain_authentication_providers ? domain_authentication_providers->valueint : 0,
        max_network_monitor_file_size && !cJSON_IsNull(max_network_monitor_file_size) ? strdup(max_network_monitor_file_size->valuestring) : NULL,
        combined ? combined->valueint : 0,
        flavor_filtersList,
        charm_sdk ? charm_sdk->valueint : 0,
        highly_available ? highly_available->valueint : 0,
        node_version && !cJSON_IsNull(node_version) ? strdup(node_version->valuestring) : NULL,
        invalid_build ? invalid_build->valueint : 0,
        sep_sim ? sep_sim->valueint : 0,
        kernel_gdb ? kernel_gdb->valueint : 0,
        android ? android->valueint : 0,
        no_ios ? no_ios->valueint : 0,
        ios_betas ? ios_betas->valueint : 0,
        charm_modules ? charm_modules->valueint : 0,
        btrace ? btrace->valueint : 0,
        strace ? strace->valueint : 0,
        game_streaming ? game_streaming->valueint : 0,
        container_template_generation && !cJSON_IsNull(container_template_generation) ? strdup(container_template_generation->valuestring) : NULL,
        s3_supported ? s3_supported->valueint : 0
        );

    return cluster_config_package_config_local_var;
end:
    if (features_local_nonprim) {
        cluster_config_package_config_features_free(features_local_nonprim);
        features_local_nonprim = NULL;
    }
    if (components_local_nonprim) {
        cluster_config_package_config_components_free(components_local_nonprim);
        components_local_nonprim = NULL;
    }
    if (flavor_filtersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, flavor_filtersList) {
            cluster_config_package_config_flavor_filters_inner_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(flavor_filtersList);
        flavor_filtersList = NULL;
    }
    return NULL;

}
