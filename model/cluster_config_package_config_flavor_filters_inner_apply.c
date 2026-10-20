#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cluster_config_package_config_flavor_filters_inner_apply.h"



static cluster_config_package_config_flavor_filters_inner_apply_t *cluster_config_package_config_flavor_filters_inner_apply_create_internal(
    int supports_core_trace,
    int supports_port_frida,
    int supports_custom_firmware,
    int supports_custom_kernel,
    int supports_gdb,
    int supports_custom_devicetree,
    int supports_network_monitor
    ) {
    cluster_config_package_config_flavor_filters_inner_apply_t *cluster_config_package_config_flavor_filters_inner_apply_local_var = malloc(sizeof(cluster_config_package_config_flavor_filters_inner_apply_t));
    if (!cluster_config_package_config_flavor_filters_inner_apply_local_var) {
        return NULL;
    }
    cluster_config_package_config_flavor_filters_inner_apply_local_var->supports_core_trace = supports_core_trace;
    cluster_config_package_config_flavor_filters_inner_apply_local_var->supports_port_frida = supports_port_frida;
    cluster_config_package_config_flavor_filters_inner_apply_local_var->supports_custom_firmware = supports_custom_firmware;
    cluster_config_package_config_flavor_filters_inner_apply_local_var->supports_custom_kernel = supports_custom_kernel;
    cluster_config_package_config_flavor_filters_inner_apply_local_var->supports_gdb = supports_gdb;
    cluster_config_package_config_flavor_filters_inner_apply_local_var->supports_custom_devicetree = supports_custom_devicetree;
    cluster_config_package_config_flavor_filters_inner_apply_local_var->supports_network_monitor = supports_network_monitor;

    cluster_config_package_config_flavor_filters_inner_apply_local_var->_library_owned = 1;
    return cluster_config_package_config_flavor_filters_inner_apply_local_var;
}

__attribute__((deprecated)) cluster_config_package_config_flavor_filters_inner_apply_t *cluster_config_package_config_flavor_filters_inner_apply_create(
    int supports_core_trace,
    int supports_port_frida,
    int supports_custom_firmware,
    int supports_custom_kernel,
    int supports_gdb,
    int supports_custom_devicetree,
    int supports_network_monitor
    ) {
    return cluster_config_package_config_flavor_filters_inner_apply_create_internal (
        supports_core_trace,
        supports_port_frida,
        supports_custom_firmware,
        supports_custom_kernel,
        supports_gdb,
        supports_custom_devicetree,
        supports_network_monitor
        );
}

void cluster_config_package_config_flavor_filters_inner_apply_free(cluster_config_package_config_flavor_filters_inner_apply_t *cluster_config_package_config_flavor_filters_inner_apply) {
    if(NULL == cluster_config_package_config_flavor_filters_inner_apply){
        return ;
    }
    if(cluster_config_package_config_flavor_filters_inner_apply->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cluster_config_package_config_flavor_filters_inner_apply_free");
        return ;
    }
    listEntry_t *listEntry;
    free(cluster_config_package_config_flavor_filters_inner_apply);
}

cJSON *cluster_config_package_config_flavor_filters_inner_apply_convertToJSON(cluster_config_package_config_flavor_filters_inner_apply_t *cluster_config_package_config_flavor_filters_inner_apply) {
    cJSON *item = cJSON_CreateObject();

    // cluster_config_package_config_flavor_filters_inner_apply->supports_core_trace
    if(cluster_config_package_config_flavor_filters_inner_apply->supports_core_trace) {
    if(cJSON_AddBoolToObject(item, "supportsCoreTrace", cluster_config_package_config_flavor_filters_inner_apply->supports_core_trace) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_package_config_flavor_filters_inner_apply->supports_port_frida
    if(cluster_config_package_config_flavor_filters_inner_apply->supports_port_frida) {
    if(cJSON_AddBoolToObject(item, "supportsPortFrida", cluster_config_package_config_flavor_filters_inner_apply->supports_port_frida) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_package_config_flavor_filters_inner_apply->supports_custom_firmware
    if(cluster_config_package_config_flavor_filters_inner_apply->supports_custom_firmware) {
    if(cJSON_AddBoolToObject(item, "supportsCustomFirmware", cluster_config_package_config_flavor_filters_inner_apply->supports_custom_firmware) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_package_config_flavor_filters_inner_apply->supports_custom_kernel
    if(cluster_config_package_config_flavor_filters_inner_apply->supports_custom_kernel) {
    if(cJSON_AddBoolToObject(item, "supportsCustomKernel", cluster_config_package_config_flavor_filters_inner_apply->supports_custom_kernel) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_package_config_flavor_filters_inner_apply->supports_gdb
    if(cluster_config_package_config_flavor_filters_inner_apply->supports_gdb) {
    if(cJSON_AddBoolToObject(item, "supportsGDB", cluster_config_package_config_flavor_filters_inner_apply->supports_gdb) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_package_config_flavor_filters_inner_apply->supports_custom_devicetree
    if(cluster_config_package_config_flavor_filters_inner_apply->supports_custom_devicetree) {
    if(cJSON_AddBoolToObject(item, "supportsCustomDevicetree", cluster_config_package_config_flavor_filters_inner_apply->supports_custom_devicetree) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_package_config_flavor_filters_inner_apply->supports_network_monitor
    if(cluster_config_package_config_flavor_filters_inner_apply->supports_network_monitor) {
    if(cJSON_AddBoolToObject(item, "supportsNetworkMonitor", cluster_config_package_config_flavor_filters_inner_apply->supports_network_monitor) == NULL) {
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

cluster_config_package_config_flavor_filters_inner_apply_t *cluster_config_package_config_flavor_filters_inner_apply_parseFromJSON(cJSON *cluster_config_package_config_flavor_filters_inner_applyJSON){

    cluster_config_package_config_flavor_filters_inner_apply_t *cluster_config_package_config_flavor_filters_inner_apply_local_var = NULL;

    // cluster_config_package_config_flavor_filters_inner_apply->supports_core_trace
    cJSON *supports_core_trace = cJSON_GetObjectItemCaseSensitive(cluster_config_package_config_flavor_filters_inner_applyJSON, "supportsCoreTrace");
    if (cJSON_IsNull(supports_core_trace)) {
        supports_core_trace = NULL;
    }
    if (supports_core_trace) { 
    if(!cJSON_IsBool(supports_core_trace))
    {
    goto end; //Bool
    }
    }

    // cluster_config_package_config_flavor_filters_inner_apply->supports_port_frida
    cJSON *supports_port_frida = cJSON_GetObjectItemCaseSensitive(cluster_config_package_config_flavor_filters_inner_applyJSON, "supportsPortFrida");
    if (cJSON_IsNull(supports_port_frida)) {
        supports_port_frida = NULL;
    }
    if (supports_port_frida) { 
    if(!cJSON_IsBool(supports_port_frida))
    {
    goto end; //Bool
    }
    }

    // cluster_config_package_config_flavor_filters_inner_apply->supports_custom_firmware
    cJSON *supports_custom_firmware = cJSON_GetObjectItemCaseSensitive(cluster_config_package_config_flavor_filters_inner_applyJSON, "supportsCustomFirmware");
    if (cJSON_IsNull(supports_custom_firmware)) {
        supports_custom_firmware = NULL;
    }
    if (supports_custom_firmware) { 
    if(!cJSON_IsBool(supports_custom_firmware))
    {
    goto end; //Bool
    }
    }

    // cluster_config_package_config_flavor_filters_inner_apply->supports_custom_kernel
    cJSON *supports_custom_kernel = cJSON_GetObjectItemCaseSensitive(cluster_config_package_config_flavor_filters_inner_applyJSON, "supportsCustomKernel");
    if (cJSON_IsNull(supports_custom_kernel)) {
        supports_custom_kernel = NULL;
    }
    if (supports_custom_kernel) { 
    if(!cJSON_IsBool(supports_custom_kernel))
    {
    goto end; //Bool
    }
    }

    // cluster_config_package_config_flavor_filters_inner_apply->supports_gdb
    cJSON *supports_gdb = cJSON_GetObjectItemCaseSensitive(cluster_config_package_config_flavor_filters_inner_applyJSON, "supportsGDB");
    if (cJSON_IsNull(supports_gdb)) {
        supports_gdb = NULL;
    }
    if (supports_gdb) { 
    if(!cJSON_IsBool(supports_gdb))
    {
    goto end; //Bool
    }
    }

    // cluster_config_package_config_flavor_filters_inner_apply->supports_custom_devicetree
    cJSON *supports_custom_devicetree = cJSON_GetObjectItemCaseSensitive(cluster_config_package_config_flavor_filters_inner_applyJSON, "supportsCustomDevicetree");
    if (cJSON_IsNull(supports_custom_devicetree)) {
        supports_custom_devicetree = NULL;
    }
    if (supports_custom_devicetree) { 
    if(!cJSON_IsBool(supports_custom_devicetree))
    {
    goto end; //Bool
    }
    }

    // cluster_config_package_config_flavor_filters_inner_apply->supports_network_monitor
    cJSON *supports_network_monitor = cJSON_GetObjectItemCaseSensitive(cluster_config_package_config_flavor_filters_inner_applyJSON, "supportsNetworkMonitor");
    if (cJSON_IsNull(supports_network_monitor)) {
        supports_network_monitor = NULL;
    }
    if (supports_network_monitor) { 
    if(!cJSON_IsBool(supports_network_monitor))
    {
    goto end; //Bool
    }
    }


    cluster_config_package_config_flavor_filters_inner_apply_local_var = cluster_config_package_config_flavor_filters_inner_apply_create_internal (
        supports_core_trace ? supports_core_trace->valueint : 0,
        supports_port_frida ? supports_port_frida->valueint : 0,
        supports_custom_firmware ? supports_custom_firmware->valueint : 0,
        supports_custom_kernel ? supports_custom_kernel->valueint : 0,
        supports_gdb ? supports_gdb->valueint : 0,
        supports_custom_devicetree ? supports_custom_devicetree->valueint : 0,
        supports_network_monitor ? supports_network_monitor->valueint : 0
        );

    return cluster_config_package_config_flavor_filters_inner_apply_local_var;
end:
    return NULL;

}
