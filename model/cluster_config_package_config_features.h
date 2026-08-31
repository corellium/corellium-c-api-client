/*
 * cluster_config_package_config_features.h
 *
 * 
 */

#ifndef _cluster_config_package_config_features_H_
#define _cluster_config_package_config_features_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cluster_config_package_config_features_t cluster_config_package_config_features_t;




typedef struct cluster_config_package_config_features_t {
    int net_mon_proc_map; //boolean
    int cellebrite_device_image; //boolean
    int custom_ramdisk; //boolean
    int injected_cdhashes; //boolean
    int custom_kernel; //boolean
    int custom_ramdom_seed; //boolean
    int disable_snapshot_mount; //boolean
    int tracing_tools; //boolean
    int sep_sim; //boolean
    int custom_boot_args; //boolean
    int netdump; //boolean
    int pac; //boolean
    int vstrm_on_compute_nodes; //boolean
    int aprr; //boolean
    int kernel_gdb; //boolean
    int kalloc_tracing; //boolean
    int track_project_instance_usage; //boolean
    int custom_device_tree; //boolean
    int custom_kernel_patches; //boolean
    int mast; //boolean
    int charm_modules; //boolean
    int netdump; //boolean
    int sep; //boolean
    int custom_boot_loader; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} cluster_config_package_config_features_t;

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
);

void cluster_config_package_config_features_free(cluster_config_package_config_features_t *cluster_config_package_config_features);

cluster_config_package_config_features_t *cluster_config_package_config_features_parseFromJSON(cJSON *cluster_config_package_config_featuresJSON);

cJSON *cluster_config_package_config_features_convertToJSON(cluster_config_package_config_features_t *cluster_config_package_config_features);

#endif /* _cluster_config_package_config_features_H_ */

