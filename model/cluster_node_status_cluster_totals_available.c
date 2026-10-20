#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cluster_node_status_cluster_totals_available.h"



static cluster_node_status_cluster_totals_available_t *cluster_node_status_cluster_totals_available_create_internal(
    double cores,
    double ram,
    double disk,
    double slot,
    double gpu
    ) {
    cluster_node_status_cluster_totals_available_t *cluster_node_status_cluster_totals_available_local_var = malloc(sizeof(cluster_node_status_cluster_totals_available_t));
    if (!cluster_node_status_cluster_totals_available_local_var) {
        return NULL;
    }
    cluster_node_status_cluster_totals_available_local_var->cores = cores;
    cluster_node_status_cluster_totals_available_local_var->ram = ram;
    cluster_node_status_cluster_totals_available_local_var->disk = disk;
    cluster_node_status_cluster_totals_available_local_var->slot = slot;
    cluster_node_status_cluster_totals_available_local_var->gpu = gpu;

    cluster_node_status_cluster_totals_available_local_var->_library_owned = 1;
    return cluster_node_status_cluster_totals_available_local_var;
}

__attribute__((deprecated)) cluster_node_status_cluster_totals_available_t *cluster_node_status_cluster_totals_available_create(
    double cores,
    double ram,
    double disk,
    double slot,
    double gpu
    ) {
    return cluster_node_status_cluster_totals_available_create_internal (
        cores,
        ram,
        disk,
        slot,
        gpu
        );
}

void cluster_node_status_cluster_totals_available_free(cluster_node_status_cluster_totals_available_t *cluster_node_status_cluster_totals_available) {
    if(NULL == cluster_node_status_cluster_totals_available){
        return ;
    }
    if(cluster_node_status_cluster_totals_available->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cluster_node_status_cluster_totals_available_free");
        return ;
    }
    listEntry_t *listEntry;
    free(cluster_node_status_cluster_totals_available);
}

cJSON *cluster_node_status_cluster_totals_available_convertToJSON(cluster_node_status_cluster_totals_available_t *cluster_node_status_cluster_totals_available) {
    cJSON *item = cJSON_CreateObject();

    // cluster_node_status_cluster_totals_available->cores
    if(cluster_node_status_cluster_totals_available->cores) {
    if(cJSON_AddNumberToObject(item, "cores", cluster_node_status_cluster_totals_available->cores) == NULL) {
    goto fail; //Numeric
    }
    }


    // cluster_node_status_cluster_totals_available->ram
    if(cluster_node_status_cluster_totals_available->ram) {
    if(cJSON_AddNumberToObject(item, "ram", cluster_node_status_cluster_totals_available->ram) == NULL) {
    goto fail; //Numeric
    }
    }


    // cluster_node_status_cluster_totals_available->disk
    if(cluster_node_status_cluster_totals_available->disk) {
    if(cJSON_AddNumberToObject(item, "disk", cluster_node_status_cluster_totals_available->disk) == NULL) {
    goto fail; //Numeric
    }
    }


    // cluster_node_status_cluster_totals_available->slot
    if(cluster_node_status_cluster_totals_available->slot) {
    if(cJSON_AddNumberToObject(item, "slot", cluster_node_status_cluster_totals_available->slot) == NULL) {
    goto fail; //Numeric
    }
    }


    // cluster_node_status_cluster_totals_available->gpu
    if(cluster_node_status_cluster_totals_available->gpu) {
    if(cJSON_AddNumberToObject(item, "gpu", cluster_node_status_cluster_totals_available->gpu) == NULL) {
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

cluster_node_status_cluster_totals_available_t *cluster_node_status_cluster_totals_available_parseFromJSON(cJSON *cluster_node_status_cluster_totals_availableJSON){

    cluster_node_status_cluster_totals_available_t *cluster_node_status_cluster_totals_available_local_var = NULL;

    // cluster_node_status_cluster_totals_available->cores
    cJSON *cores = cJSON_GetObjectItemCaseSensitive(cluster_node_status_cluster_totals_availableJSON, "cores");
    if (cJSON_IsNull(cores)) {
        cores = NULL;
    }
    if (cores) { 
    if(!cJSON_IsNumber(cores))
    {
    goto end; //Numeric
    }
    }

    // cluster_node_status_cluster_totals_available->ram
    cJSON *ram = cJSON_GetObjectItemCaseSensitive(cluster_node_status_cluster_totals_availableJSON, "ram");
    if (cJSON_IsNull(ram)) {
        ram = NULL;
    }
    if (ram) { 
    if(!cJSON_IsNumber(ram))
    {
    goto end; //Numeric
    }
    }

    // cluster_node_status_cluster_totals_available->disk
    cJSON *disk = cJSON_GetObjectItemCaseSensitive(cluster_node_status_cluster_totals_availableJSON, "disk");
    if (cJSON_IsNull(disk)) {
        disk = NULL;
    }
    if (disk) { 
    if(!cJSON_IsNumber(disk))
    {
    goto end; //Numeric
    }
    }

    // cluster_node_status_cluster_totals_available->slot
    cJSON *slot = cJSON_GetObjectItemCaseSensitive(cluster_node_status_cluster_totals_availableJSON, "slot");
    if (cJSON_IsNull(slot)) {
        slot = NULL;
    }
    if (slot) { 
    if(!cJSON_IsNumber(slot))
    {
    goto end; //Numeric
    }
    }

    // cluster_node_status_cluster_totals_available->gpu
    cJSON *gpu = cJSON_GetObjectItemCaseSensitive(cluster_node_status_cluster_totals_availableJSON, "gpu");
    if (cJSON_IsNull(gpu)) {
        gpu = NULL;
    }
    if (gpu) { 
    if(!cJSON_IsNumber(gpu))
    {
    goto end; //Numeric
    }
    }


    cluster_node_status_cluster_totals_available_local_var = cluster_node_status_cluster_totals_available_create_internal (
        cores ? cores->valuedouble : 0,
        ram ? ram->valuedouble : 0,
        disk ? disk->valuedouble : 0,
        slot ? slot->valuedouble : 0,
        gpu ? gpu->valuedouble : 0
        );

    return cluster_node_status_cluster_totals_available_local_var;
end:
    return NULL;

}
