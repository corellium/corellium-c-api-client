#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cluster_config_package_config_features.h"



static cluster_config_package_config_features_t *cluster_config_package_config_features_create_internal(
    int net_mon_proc_map,
    int cellebrite_device_image,
    int custom_ramdisk,
    int injected_cdhashes,
    int custom_kernel,
    int custom_ramdom_seed,
    int disable_snapshot_mount,
    int tracing_tools,
    int sep_sim,
    int custom_boot_args,
    int netdump,
    int pac,
    int vstrm_on_compute_nodes,
    int aprr,
    int kernel_gdb,
    int kalloc_tracing,
    int track_project_instance_usage,
    int custom_device_tree,
    int custom_kernel_patches,
    int mast,
    int charm_modules,
    int netdump,
    int sep,
    int custom_boot_loader
    ) {
    cluster_config_package_config_features_t *cluster_config_package_config_features_local_var = malloc(sizeof(cluster_config_package_config_features_t));
    if (!cluster_config_package_config_features_local_var) {
        return NULL;
    }
    cluster_config_package_config_features_local_var->net_mon_proc_map = net_mon_proc_map;
    cluster_config_package_config_features_local_var->cellebrite_device_image = cellebrite_device_image;
    cluster_config_package_config_features_local_var->custom_ramdisk = custom_ramdisk;
    cluster_config_package_config_features_local_var->injected_cdhashes = injected_cdhashes;
    cluster_config_package_config_features_local_var->custom_kernel = custom_kernel;
    cluster_config_package_config_features_local_var->custom_ramdom_seed = custom_ramdom_seed;
    cluster_config_package_config_features_local_var->disable_snapshot_mount = disable_snapshot_mount;
    cluster_config_package_config_features_local_var->tracing_tools = tracing_tools;
    cluster_config_package_config_features_local_var->sep_sim = sep_sim;
    cluster_config_package_config_features_local_var->custom_boot_args = custom_boot_args;
    cluster_config_package_config_features_local_var->netdump = netdump;
    cluster_config_package_config_features_local_var->pac = pac;
    cluster_config_package_config_features_local_var->vstrm_on_compute_nodes = vstrm_on_compute_nodes;
    cluster_config_package_config_features_local_var->aprr = aprr;
    cluster_config_package_config_features_local_var->kernel_gdb = kernel_gdb;
    cluster_config_package_config_features_local_var->kalloc_tracing = kalloc_tracing;
    cluster_config_package_config_features_local_var->track_project_instance_usage = track_project_instance_usage;
    cluster_config_package_config_features_local_var->custom_device_tree = custom_device_tree;
    cluster_config_package_config_features_local_var->custom_kernel_patches = custom_kernel_patches;
    cluster_config_package_config_features_local_var->mast = mast;
    cluster_config_package_config_features_local_var->charm_modules = charm_modules;
    cluster_config_package_config_features_local_var->netdump = netdump;
    cluster_config_package_config_features_local_var->sep = sep;
    cluster_config_package_config_features_local_var->custom_boot_loader = custom_boot_loader;

    cluster_config_package_config_features_local_var->_library_owned = 1;
    return cluster_config_package_config_features_local_var;
}

__attribute__((deprecated)) cluster_config_package_config_features_t *cluster_config_package_config_features_create(
    int net_mon_proc_map,
    int cellebrite_device_image,
    int custom_ramdisk,
    int injected_cdhashes,
    int custom_kernel,
    int custom_ramdom_seed,
    int disable_snapshot_mount,
    int tracing_tools,
    int sep_sim,
    int custom_boot_args,
    int netdump,
    int pac,
    int vstrm_on_compute_nodes,
    int aprr,
    int kernel_gdb,
    int kalloc_tracing,
    int track_project_instance_usage,
    int custom_device_tree,
    int custom_kernel_patches,
    int mast,
    int charm_modules,
    int netdump,
    int sep,
    int custom_boot_loader
    ) {
    return cluster_config_package_config_features_create_internal (
        net_mon_proc_map,
        cellebrite_device_image,
        custom_ramdisk,
        injected_cdhashes,
        custom_kernel,
        custom_ramdom_seed,
        disable_snapshot_mount,
        tracing_tools,
        sep_sim,
        custom_boot_args,
        netdump,
        pac,
        vstrm_on_compute_nodes,
        aprr,
        kernel_gdb,
        kalloc_tracing,
        track_project_instance_usage,
        custom_device_tree,
        custom_kernel_patches,
        mast,
        charm_modules,
        netdump,
        sep,
        custom_boot_loader
        );
}

void cluster_config_package_config_features_free(cluster_config_package_config_features_t *cluster_config_package_config_features) {
    if(NULL == cluster_config_package_config_features){
        return ;
    }
    if(cluster_config_package_config_features->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cluster_config_package_config_features_free");
        return ;
    }
    listEntry_t *listEntry;
    free(cluster_config_package_config_features);
}

cJSON *cluster_config_package_config_features_convertToJSON(cluster_config_package_config_features_t *cluster_config_package_config_features) {
    cJSON *item = cJSON_CreateObject();

    // cluster_config_package_config_features->net_mon_proc_map
    if(cluster_config_package_config_features->net_mon_proc_map) {
    if(cJSON_AddBoolToObject(item, "netMonProcMap", cluster_config_package_config_features->net_mon_proc_map) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_package_config_features->cellebrite_device_image
    if(cluster_config_package_config_features->cellebrite_device_image) {
    if(cJSON_AddBoolToObject(item, "CellebriteDeviceImage", cluster_config_package_config_features->cellebrite_device_image) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_package_config_features->custom_ramdisk
    if(cluster_config_package_config_features->custom_ramdisk) {
    if(cJSON_AddBoolToObject(item, "CustomRamdisk", cluster_config_package_config_features->custom_ramdisk) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_package_config_features->injected_cdhashes
    if(cluster_config_package_config_features->injected_cdhashes) {
    if(cJSON_AddBoolToObject(item, "InjectedCdhashes", cluster_config_package_config_features->injected_cdhashes) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_package_config_features->custom_kernel
    if(cluster_config_package_config_features->custom_kernel) {
    if(cJSON_AddBoolToObject(item, "CustomKernel", cluster_config_package_config_features->custom_kernel) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_package_config_features->custom_ramdom_seed
    if(cluster_config_package_config_features->custom_ramdom_seed) {
    if(cJSON_AddBoolToObject(item, "CustomRamdomSeed", cluster_config_package_config_features->custom_ramdom_seed) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_package_config_features->disable_snapshot_mount
    if(cluster_config_package_config_features->disable_snapshot_mount) {
    if(cJSON_AddBoolToObject(item, "DisableSnapshotMount", cluster_config_package_config_features->disable_snapshot_mount) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_package_config_features->tracing_tools
    if(cluster_config_package_config_features->tracing_tools) {
    if(cJSON_AddBoolToObject(item, "TracingTools", cluster_config_package_config_features->tracing_tools) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_package_config_features->sep_sim
    if(cluster_config_package_config_features->sep_sim) {
    if(cJSON_AddBoolToObject(item, "SepSim", cluster_config_package_config_features->sep_sim) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_package_config_features->custom_boot_args
    if(cluster_config_package_config_features->custom_boot_args) {
    if(cJSON_AddBoolToObject(item, "CustomBootArgs", cluster_config_package_config_features->custom_boot_args) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_package_config_features->netdump
    if(cluster_config_package_config_features->netdump) {
    if(cJSON_AddBoolToObject(item, "netdump", cluster_config_package_config_features->netdump) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_package_config_features->pac
    if(cluster_config_package_config_features->pac) {
    if(cJSON_AddBoolToObject(item, "PAC", cluster_config_package_config_features->pac) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_package_config_features->vstrm_on_compute_nodes
    if(cluster_config_package_config_features->vstrm_on_compute_nodes) {
    if(cJSON_AddBoolToObject(item, "VstrmOnComputeNodes", cluster_config_package_config_features->vstrm_on_compute_nodes) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_package_config_features->aprr
    if(cluster_config_package_config_features->aprr) {
    if(cJSON_AddBoolToObject(item, "APRR", cluster_config_package_config_features->aprr) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_package_config_features->kernel_gdb
    if(cluster_config_package_config_features->kernel_gdb) {
    if(cJSON_AddBoolToObject(item, "KernelGDB", cluster_config_package_config_features->kernel_gdb) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_package_config_features->kalloc_tracing
    if(cluster_config_package_config_features->kalloc_tracing) {
    if(cJSON_AddBoolToObject(item, "KallocTracing", cluster_config_package_config_features->kalloc_tracing) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_package_config_features->track_project_instance_usage
    if(cluster_config_package_config_features->track_project_instance_usage) {
    if(cJSON_AddBoolToObject(item, "trackProjectInstanceUsage", cluster_config_package_config_features->track_project_instance_usage) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_package_config_features->custom_device_tree
    if(cluster_config_package_config_features->custom_device_tree) {
    if(cJSON_AddBoolToObject(item, "CustomDeviceTree", cluster_config_package_config_features->custom_device_tree) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_package_config_features->custom_kernel_patches
    if(cluster_config_package_config_features->custom_kernel_patches) {
    if(cJSON_AddBoolToObject(item, "CustomKernelPatches", cluster_config_package_config_features->custom_kernel_patches) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_package_config_features->mast
    if(cluster_config_package_config_features->mast) {
    if(cJSON_AddBoolToObject(item, "Mast", cluster_config_package_config_features->mast) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_package_config_features->charm_modules
    if(cluster_config_package_config_features->charm_modules) {
    if(cJSON_AddBoolToObject(item, "CharmModules", cluster_config_package_config_features->charm_modules) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_package_config_features->netdump
    if(cluster_config_package_config_features->netdump) {
    if(cJSON_AddBoolToObject(item, "Netdump", cluster_config_package_config_features->netdump) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_package_config_features->sep
    if(cluster_config_package_config_features->sep) {
    if(cJSON_AddBoolToObject(item, "SEP", cluster_config_package_config_features->sep) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_package_config_features->custom_boot_loader
    if(cluster_config_package_config_features->custom_boot_loader) {
    if(cJSON_AddBoolToObject(item, "CustomBootLoader", cluster_config_package_config_features->custom_boot_loader) == NULL) {
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

cluster_config_package_config_features_t *cluster_config_package_config_features_parseFromJSON(cJSON *cluster_config_package_config_featuresJSON){

    cluster_config_package_config_features_t *cluster_config_package_config_features_local_var = NULL;

    // cluster_config_package_config_features->net_mon_proc_map
    cJSON *net_mon_proc_map = cJSON_GetObjectItemCaseSensitive(cluster_config_package_config_featuresJSON, "netMonProcMap");
    if (cJSON_IsNull(net_mon_proc_map)) {
        net_mon_proc_map = NULL;
    }
    if (net_mon_proc_map) { 
    if(!cJSON_IsBool(net_mon_proc_map))
    {
    goto end; //Bool
    }
    }

    // cluster_config_package_config_features->cellebrite_device_image
    cJSON *cellebrite_device_image = cJSON_GetObjectItemCaseSensitive(cluster_config_package_config_featuresJSON, "CellebriteDeviceImage");
    if (cJSON_IsNull(cellebrite_device_image)) {
        cellebrite_device_image = NULL;
    }
    if (cellebrite_device_image) { 
    if(!cJSON_IsBool(cellebrite_device_image))
    {
    goto end; //Bool
    }
    }

    // cluster_config_package_config_features->custom_ramdisk
    cJSON *custom_ramdisk = cJSON_GetObjectItemCaseSensitive(cluster_config_package_config_featuresJSON, "CustomRamdisk");
    if (cJSON_IsNull(custom_ramdisk)) {
        custom_ramdisk = NULL;
    }
    if (custom_ramdisk) { 
    if(!cJSON_IsBool(custom_ramdisk))
    {
    goto end; //Bool
    }
    }

    // cluster_config_package_config_features->injected_cdhashes
    cJSON *injected_cdhashes = cJSON_GetObjectItemCaseSensitive(cluster_config_package_config_featuresJSON, "InjectedCdhashes");
    if (cJSON_IsNull(injected_cdhashes)) {
        injected_cdhashes = NULL;
    }
    if (injected_cdhashes) { 
    if(!cJSON_IsBool(injected_cdhashes))
    {
    goto end; //Bool
    }
    }

    // cluster_config_package_config_features->custom_kernel
    cJSON *custom_kernel = cJSON_GetObjectItemCaseSensitive(cluster_config_package_config_featuresJSON, "CustomKernel");
    if (cJSON_IsNull(custom_kernel)) {
        custom_kernel = NULL;
    }
    if (custom_kernel) { 
    if(!cJSON_IsBool(custom_kernel))
    {
    goto end; //Bool
    }
    }

    // cluster_config_package_config_features->custom_ramdom_seed
    cJSON *custom_ramdom_seed = cJSON_GetObjectItemCaseSensitive(cluster_config_package_config_featuresJSON, "CustomRamdomSeed");
    if (cJSON_IsNull(custom_ramdom_seed)) {
        custom_ramdom_seed = NULL;
    }
    if (custom_ramdom_seed) { 
    if(!cJSON_IsBool(custom_ramdom_seed))
    {
    goto end; //Bool
    }
    }

    // cluster_config_package_config_features->disable_snapshot_mount
    cJSON *disable_snapshot_mount = cJSON_GetObjectItemCaseSensitive(cluster_config_package_config_featuresJSON, "DisableSnapshotMount");
    if (cJSON_IsNull(disable_snapshot_mount)) {
        disable_snapshot_mount = NULL;
    }
    if (disable_snapshot_mount) { 
    if(!cJSON_IsBool(disable_snapshot_mount))
    {
    goto end; //Bool
    }
    }

    // cluster_config_package_config_features->tracing_tools
    cJSON *tracing_tools = cJSON_GetObjectItemCaseSensitive(cluster_config_package_config_featuresJSON, "TracingTools");
    if (cJSON_IsNull(tracing_tools)) {
        tracing_tools = NULL;
    }
    if (tracing_tools) { 
    if(!cJSON_IsBool(tracing_tools))
    {
    goto end; //Bool
    }
    }

    // cluster_config_package_config_features->sep_sim
    cJSON *sep_sim = cJSON_GetObjectItemCaseSensitive(cluster_config_package_config_featuresJSON, "SepSim");
    if (cJSON_IsNull(sep_sim)) {
        sep_sim = NULL;
    }
    if (sep_sim) { 
    if(!cJSON_IsBool(sep_sim))
    {
    goto end; //Bool
    }
    }

    // cluster_config_package_config_features->custom_boot_args
    cJSON *custom_boot_args = cJSON_GetObjectItemCaseSensitive(cluster_config_package_config_featuresJSON, "CustomBootArgs");
    if (cJSON_IsNull(custom_boot_args)) {
        custom_boot_args = NULL;
    }
    if (custom_boot_args) { 
    if(!cJSON_IsBool(custom_boot_args))
    {
    goto end; //Bool
    }
    }

    // cluster_config_package_config_features->netdump
    cJSON *netdump = cJSON_GetObjectItemCaseSensitive(cluster_config_package_config_featuresJSON, "netdump");
    if (cJSON_IsNull(netdump)) {
        netdump = NULL;
    }
    if (netdump) { 
    if(!cJSON_IsBool(netdump))
    {
    goto end; //Bool
    }
    }

    // cluster_config_package_config_features->pac
    cJSON *pac = cJSON_GetObjectItemCaseSensitive(cluster_config_package_config_featuresJSON, "PAC");
    if (cJSON_IsNull(pac)) {
        pac = NULL;
    }
    if (pac) { 
    if(!cJSON_IsBool(pac))
    {
    goto end; //Bool
    }
    }

    // cluster_config_package_config_features->vstrm_on_compute_nodes
    cJSON *vstrm_on_compute_nodes = cJSON_GetObjectItemCaseSensitive(cluster_config_package_config_featuresJSON, "VstrmOnComputeNodes");
    if (cJSON_IsNull(vstrm_on_compute_nodes)) {
        vstrm_on_compute_nodes = NULL;
    }
    if (vstrm_on_compute_nodes) { 
    if(!cJSON_IsBool(vstrm_on_compute_nodes))
    {
    goto end; //Bool
    }
    }

    // cluster_config_package_config_features->aprr
    cJSON *aprr = cJSON_GetObjectItemCaseSensitive(cluster_config_package_config_featuresJSON, "APRR");
    if (cJSON_IsNull(aprr)) {
        aprr = NULL;
    }
    if (aprr) { 
    if(!cJSON_IsBool(aprr))
    {
    goto end; //Bool
    }
    }

    // cluster_config_package_config_features->kernel_gdb
    cJSON *kernel_gdb = cJSON_GetObjectItemCaseSensitive(cluster_config_package_config_featuresJSON, "KernelGDB");
    if (cJSON_IsNull(kernel_gdb)) {
        kernel_gdb = NULL;
    }
    if (kernel_gdb) { 
    if(!cJSON_IsBool(kernel_gdb))
    {
    goto end; //Bool
    }
    }

    // cluster_config_package_config_features->kalloc_tracing
    cJSON *kalloc_tracing = cJSON_GetObjectItemCaseSensitive(cluster_config_package_config_featuresJSON, "KallocTracing");
    if (cJSON_IsNull(kalloc_tracing)) {
        kalloc_tracing = NULL;
    }
    if (kalloc_tracing) { 
    if(!cJSON_IsBool(kalloc_tracing))
    {
    goto end; //Bool
    }
    }

    // cluster_config_package_config_features->track_project_instance_usage
    cJSON *track_project_instance_usage = cJSON_GetObjectItemCaseSensitive(cluster_config_package_config_featuresJSON, "trackProjectInstanceUsage");
    if (cJSON_IsNull(track_project_instance_usage)) {
        track_project_instance_usage = NULL;
    }
    if (track_project_instance_usage) { 
    if(!cJSON_IsBool(track_project_instance_usage))
    {
    goto end; //Bool
    }
    }

    // cluster_config_package_config_features->custom_device_tree
    cJSON *custom_device_tree = cJSON_GetObjectItemCaseSensitive(cluster_config_package_config_featuresJSON, "CustomDeviceTree");
    if (cJSON_IsNull(custom_device_tree)) {
        custom_device_tree = NULL;
    }
    if (custom_device_tree) { 
    if(!cJSON_IsBool(custom_device_tree))
    {
    goto end; //Bool
    }
    }

    // cluster_config_package_config_features->custom_kernel_patches
    cJSON *custom_kernel_patches = cJSON_GetObjectItemCaseSensitive(cluster_config_package_config_featuresJSON, "CustomKernelPatches");
    if (cJSON_IsNull(custom_kernel_patches)) {
        custom_kernel_patches = NULL;
    }
    if (custom_kernel_patches) { 
    if(!cJSON_IsBool(custom_kernel_patches))
    {
    goto end; //Bool
    }
    }

    // cluster_config_package_config_features->mast
    cJSON *mast = cJSON_GetObjectItemCaseSensitive(cluster_config_package_config_featuresJSON, "Mast");
    if (cJSON_IsNull(mast)) {
        mast = NULL;
    }
    if (mast) { 
    if(!cJSON_IsBool(mast))
    {
    goto end; //Bool
    }
    }

    // cluster_config_package_config_features->charm_modules
    cJSON *charm_modules = cJSON_GetObjectItemCaseSensitive(cluster_config_package_config_featuresJSON, "CharmModules");
    if (cJSON_IsNull(charm_modules)) {
        charm_modules = NULL;
    }
    if (charm_modules) { 
    if(!cJSON_IsBool(charm_modules))
    {
    goto end; //Bool
    }
    }

    // cluster_config_package_config_features->netdump
    cJSON *netdump = cJSON_GetObjectItemCaseSensitive(cluster_config_package_config_featuresJSON, "Netdump");
    if (cJSON_IsNull(netdump)) {
        netdump = NULL;
    }
    if (netdump) { 
    if(!cJSON_IsBool(netdump))
    {
    goto end; //Bool
    }
    }

    // cluster_config_package_config_features->sep
    cJSON *sep = cJSON_GetObjectItemCaseSensitive(cluster_config_package_config_featuresJSON, "SEP");
    if (cJSON_IsNull(sep)) {
        sep = NULL;
    }
    if (sep) { 
    if(!cJSON_IsBool(sep))
    {
    goto end; //Bool
    }
    }

    // cluster_config_package_config_features->custom_boot_loader
    cJSON *custom_boot_loader = cJSON_GetObjectItemCaseSensitive(cluster_config_package_config_featuresJSON, "CustomBootLoader");
    if (cJSON_IsNull(custom_boot_loader)) {
        custom_boot_loader = NULL;
    }
    if (custom_boot_loader) { 
    if(!cJSON_IsBool(custom_boot_loader))
    {
    goto end; //Bool
    }
    }


    cluster_config_package_config_features_local_var = cluster_config_package_config_features_create_internal (
        net_mon_proc_map ? net_mon_proc_map->valueint : 0,
        cellebrite_device_image ? cellebrite_device_image->valueint : 0,
        custom_ramdisk ? custom_ramdisk->valueint : 0,
        injected_cdhashes ? injected_cdhashes->valueint : 0,
        custom_kernel ? custom_kernel->valueint : 0,
        custom_ramdom_seed ? custom_ramdom_seed->valueint : 0,
        disable_snapshot_mount ? disable_snapshot_mount->valueint : 0,
        tracing_tools ? tracing_tools->valueint : 0,
        sep_sim ? sep_sim->valueint : 0,
        custom_boot_args ? custom_boot_args->valueint : 0,
        netdump ? netdump->valueint : 0,
        pac ? pac->valueint : 0,
        vstrm_on_compute_nodes ? vstrm_on_compute_nodes->valueint : 0,
        aprr ? aprr->valueint : 0,
        kernel_gdb ? kernel_gdb->valueint : 0,
        kalloc_tracing ? kalloc_tracing->valueint : 0,
        track_project_instance_usage ? track_project_instance_usage->valueint : 0,
        custom_device_tree ? custom_device_tree->valueint : 0,
        custom_kernel_patches ? custom_kernel_patches->valueint : 0,
        mast ? mast->valueint : 0,
        charm_modules ? charm_modules->valueint : 0,
        netdump ? netdump->valueint : 0,
        sep ? sep->valueint : 0,
        custom_boot_loader ? custom_boot_loader->valueint : 0
        );

    return cluster_config_package_config_features_local_var;
end:
    return NULL;

}
