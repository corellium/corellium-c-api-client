#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cluster_snapshot_metadata.h"



static cluster_snapshot_metadata_t *cluster_snapshot_metadata_create_internal(
    int live,
    int fresh,
    double hw_pac,
    int springboard,
    object_t *boot_options,
    object_t *device,
    char *flavor,
    char *os_version,
    char *os_build,
    char *patches,
    double cpid
    ) {
    cluster_snapshot_metadata_t *cluster_snapshot_metadata_local_var = malloc(sizeof(cluster_snapshot_metadata_t));
    if (!cluster_snapshot_metadata_local_var) {
        return NULL;
    }
    cluster_snapshot_metadata_local_var->live = live;
    cluster_snapshot_metadata_local_var->fresh = fresh;
    cluster_snapshot_metadata_local_var->hw_pac = hw_pac;
    cluster_snapshot_metadata_local_var->springboard = springboard;
    cluster_snapshot_metadata_local_var->boot_options = boot_options;
    cluster_snapshot_metadata_local_var->device = device;
    cluster_snapshot_metadata_local_var->flavor = flavor;
    cluster_snapshot_metadata_local_var->os_version = os_version;
    cluster_snapshot_metadata_local_var->os_build = os_build;
    cluster_snapshot_metadata_local_var->patches = patches;
    cluster_snapshot_metadata_local_var->cpid = cpid;

    cluster_snapshot_metadata_local_var->_library_owned = 1;
    return cluster_snapshot_metadata_local_var;
}

__attribute__((deprecated)) cluster_snapshot_metadata_t *cluster_snapshot_metadata_create(
    int live,
    int fresh,
    double hw_pac,
    int springboard,
    object_t *boot_options,
    object_t *device,
    char *flavor,
    char *os_version,
    char *os_build,
    char *patches,
    double cpid
    ) {
    return cluster_snapshot_metadata_create_internal (
        live,
        fresh,
        hw_pac,
        springboard,
        boot_options,
        device,
        flavor,
        os_version,
        os_build,
        patches,
        cpid
        );
}

void cluster_snapshot_metadata_free(cluster_snapshot_metadata_t *cluster_snapshot_metadata) {
    if(NULL == cluster_snapshot_metadata){
        return ;
    }
    if(cluster_snapshot_metadata->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cluster_snapshot_metadata_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cluster_snapshot_metadata->boot_options) {
        object_free(cluster_snapshot_metadata->boot_options);
        cluster_snapshot_metadata->boot_options = NULL;
    }
    if (cluster_snapshot_metadata->device) {
        object_free(cluster_snapshot_metadata->device);
        cluster_snapshot_metadata->device = NULL;
    }
    if (cluster_snapshot_metadata->flavor) {
        free(cluster_snapshot_metadata->flavor);
        cluster_snapshot_metadata->flavor = NULL;
    }
    if (cluster_snapshot_metadata->os_version) {
        free(cluster_snapshot_metadata->os_version);
        cluster_snapshot_metadata->os_version = NULL;
    }
    if (cluster_snapshot_metadata->os_build) {
        free(cluster_snapshot_metadata->os_build);
        cluster_snapshot_metadata->os_build = NULL;
    }
    if (cluster_snapshot_metadata->patches) {
        free(cluster_snapshot_metadata->patches);
        cluster_snapshot_metadata->patches = NULL;
    }
    free(cluster_snapshot_metadata);
}

cJSON *cluster_snapshot_metadata_convertToJSON(cluster_snapshot_metadata_t *cluster_snapshot_metadata) {
    cJSON *item = cJSON_CreateObject();

    // cluster_snapshot_metadata->live
    if(cluster_snapshot_metadata->live) {
    if(cJSON_AddBoolToObject(item, "live", cluster_snapshot_metadata->live) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_snapshot_metadata->fresh
    if(cluster_snapshot_metadata->fresh) {
    if(cJSON_AddBoolToObject(item, "fresh", cluster_snapshot_metadata->fresh) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_snapshot_metadata->hw_pac
    if(cluster_snapshot_metadata->hw_pac) {
    if(cJSON_AddNumberToObject(item, "hwPac", cluster_snapshot_metadata->hw_pac) == NULL) {
    goto fail; //Numeric
    }
    }


    // cluster_snapshot_metadata->springboard
    if(cluster_snapshot_metadata->springboard) {
    if(cJSON_AddBoolToObject(item, "springboard", cluster_snapshot_metadata->springboard) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_snapshot_metadata->boot_options
    if(cluster_snapshot_metadata->boot_options) {
    cJSON *boot_options_object = object_convertToJSON(cluster_snapshot_metadata->boot_options);
    if(boot_options_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "bootOptions", boot_options_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // cluster_snapshot_metadata->device
    if(cluster_snapshot_metadata->device) {
    cJSON *device_object = object_convertToJSON(cluster_snapshot_metadata->device);
    if(device_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "device", device_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // cluster_snapshot_metadata->flavor
    if(cluster_snapshot_metadata->flavor) {
    if(cJSON_AddStringToObject(item, "flavor", cluster_snapshot_metadata->flavor) == NULL) {
    goto fail; //String
    }
    }


    // cluster_snapshot_metadata->os_version
    if(cluster_snapshot_metadata->os_version) {
    if(cJSON_AddStringToObject(item, "osVersion", cluster_snapshot_metadata->os_version) == NULL) {
    goto fail; //String
    }
    }


    // cluster_snapshot_metadata->os_build
    if(cluster_snapshot_metadata->os_build) {
    if(cJSON_AddStringToObject(item, "osBuild", cluster_snapshot_metadata->os_build) == NULL) {
    goto fail; //String
    }
    }


    // cluster_snapshot_metadata->patches
    if(cluster_snapshot_metadata->patches) {
    if(cJSON_AddStringToObject(item, "patches", cluster_snapshot_metadata->patches) == NULL) {
    goto fail; //String
    }
    }


    // cluster_snapshot_metadata->cpid
    if(cluster_snapshot_metadata->cpid) {
    if(cJSON_AddNumberToObject(item, "cpid", cluster_snapshot_metadata->cpid) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

cluster_snapshot_metadata_t *cluster_snapshot_metadata_parseFromJSON(cJSON *cluster_snapshot_metadataJSON){

    cluster_snapshot_metadata_t *cluster_snapshot_metadata_local_var = NULL;

    // cluster_snapshot_metadata->live
    cJSON *live = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_metadataJSON, "live");
    if (cJSON_IsNull(live)) {
        live = NULL;
    }
    if (live) { 
    if(!cJSON_IsBool(live))
    {
    goto end; //Bool
    }
    }

    // cluster_snapshot_metadata->fresh
    cJSON *fresh = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_metadataJSON, "fresh");
    if (cJSON_IsNull(fresh)) {
        fresh = NULL;
    }
    if (fresh) { 
    if(!cJSON_IsBool(fresh))
    {
    goto end; //Bool
    }
    }

    // cluster_snapshot_metadata->hw_pac
    cJSON *hw_pac = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_metadataJSON, "hwPac");
    if (cJSON_IsNull(hw_pac)) {
        hw_pac = NULL;
    }
    if (hw_pac) { 
    if(!cJSON_IsNumber(hw_pac))
    {
    goto end; //Numeric
    }
    }

    // cluster_snapshot_metadata->springboard
    cJSON *springboard = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_metadataJSON, "springboard");
    if (cJSON_IsNull(springboard)) {
        springboard = NULL;
    }
    if (springboard) { 
    if(!cJSON_IsBool(springboard))
    {
    goto end; //Bool
    }
    }

    // cluster_snapshot_metadata->boot_options
    cJSON *boot_options = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_metadataJSON, "bootOptions");
    if (cJSON_IsNull(boot_options)) {
        boot_options = NULL;
    }
    object_t *boot_options_local_object = NULL;
    if (boot_options) { 
    boot_options_local_object = object_parseFromJSON(boot_options); //object
    }

    // cluster_snapshot_metadata->device
    cJSON *device = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_metadataJSON, "device");
    if (cJSON_IsNull(device)) {
        device = NULL;
    }
    object_t *device_local_object = NULL;
    if (device) { 
    device_local_object = object_parseFromJSON(device); //object
    }

    // cluster_snapshot_metadata->flavor
    cJSON *flavor = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_metadataJSON, "flavor");
    if (cJSON_IsNull(flavor)) {
        flavor = NULL;
    }
    if (flavor) { 
    if(!cJSON_IsString(flavor) && !cJSON_IsNull(flavor))
    {
    goto end; //String
    }
    }

    // cluster_snapshot_metadata->os_version
    cJSON *os_version = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_metadataJSON, "osVersion");
    if (cJSON_IsNull(os_version)) {
        os_version = NULL;
    }
    if (os_version) { 
    if(!cJSON_IsString(os_version) && !cJSON_IsNull(os_version))
    {
    goto end; //String
    }
    }

    // cluster_snapshot_metadata->os_build
    cJSON *os_build = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_metadataJSON, "osBuild");
    if (cJSON_IsNull(os_build)) {
        os_build = NULL;
    }
    if (os_build) { 
    if(!cJSON_IsString(os_build) && !cJSON_IsNull(os_build))
    {
    goto end; //String
    }
    }

    // cluster_snapshot_metadata->patches
    cJSON *patches = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_metadataJSON, "patches");
    if (cJSON_IsNull(patches)) {
        patches = NULL;
    }
    if (patches) { 
    if(!cJSON_IsString(patches) && !cJSON_IsNull(patches))
    {
    goto end; //String
    }
    }

    // cluster_snapshot_metadata->cpid
    cJSON *cpid = cJSON_GetObjectItemCaseSensitive(cluster_snapshot_metadataJSON, "cpid");
    if (cJSON_IsNull(cpid)) {
        cpid = NULL;
    }
    if (cpid) { 
    if(!cJSON_IsNumber(cpid))
    {
    goto end; //Numeric
    }
    }


    cluster_snapshot_metadata_local_var = cluster_snapshot_metadata_create_internal (
        live ? live->valueint : 0,
        fresh ? fresh->valueint : 0,
        hw_pac ? hw_pac->valuedouble : 0,
        springboard ? springboard->valueint : 0,
        boot_options ? boot_options_local_object : NULL,
        device ? device_local_object : NULL,
        flavor && !cJSON_IsNull(flavor) ? strdup(flavor->valuestring) : NULL,
        os_version && !cJSON_IsNull(os_version) ? strdup(os_version->valuestring) : NULL,
        os_build && !cJSON_IsNull(os_build) ? strdup(os_build->valuestring) : NULL,
        patches && !cJSON_IsNull(patches) ? strdup(patches->valuestring) : NULL,
        cpid ? cpid->valuedouble : 0
        );

    return cluster_snapshot_metadata_local_var;
end:
    return NULL;

}
