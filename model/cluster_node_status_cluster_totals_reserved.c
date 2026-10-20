#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cluster_node_status_cluster_totals_reserved.h"



static cluster_node_status_cluster_totals_reserved_t *cluster_node_status_cluster_totals_reserved_create_internal(
    double cores,
    double ram,
    double disk,
    double slot,
    double gpu
    ) {
    cluster_node_status_cluster_totals_reserved_t *cluster_node_status_cluster_totals_reserved_local_var = malloc(sizeof(cluster_node_status_cluster_totals_reserved_t));
    if (!cluster_node_status_cluster_totals_reserved_local_var) {
        return NULL;
    }
    cluster_node_status_cluster_totals_reserved_local_var->cores = cores;
    cluster_node_status_cluster_totals_reserved_local_var->ram = ram;
    cluster_node_status_cluster_totals_reserved_local_var->disk = disk;
    cluster_node_status_cluster_totals_reserved_local_var->slot = slot;
    cluster_node_status_cluster_totals_reserved_local_var->gpu = gpu;

    cluster_node_status_cluster_totals_reserved_local_var->_library_owned = 1;
    return cluster_node_status_cluster_totals_reserved_local_var;
}

__attribute__((deprecated)) cluster_node_status_cluster_totals_reserved_t *cluster_node_status_cluster_totals_reserved_create(
    double cores,
    double ram,
    double disk,
    double slot,
    double gpu
    ) {
    return cluster_node_status_cluster_totals_reserved_create_internal (
        cores,
        ram,
        disk,
        slot,
        gpu
        );
}

void cluster_node_status_cluster_totals_reserved_free(cluster_node_status_cluster_totals_reserved_t *cluster_node_status_cluster_totals_reserved) {
    if(NULL == cluster_node_status_cluster_totals_reserved){
        return ;
    }
    if(cluster_node_status_cluster_totals_reserved->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cluster_node_status_cluster_totals_reserved_free");
        return ;
    }
    listEntry_t *listEntry;
    free(cluster_node_status_cluster_totals_reserved);
}

cJSON *cluster_node_status_cluster_totals_reserved_convertToJSON(cluster_node_status_cluster_totals_reserved_t *cluster_node_status_cluster_totals_reserved) {
    cJSON *item = cJSON_CreateObject();

    // cluster_node_status_cluster_totals_reserved->cores
    if(cluster_node_status_cluster_totals_reserved->cores) {
    if(cJSON_AddNumberToObject(item, "cores", cluster_node_status_cluster_totals_reserved->cores) == NULL) {
    goto fail; //Numeric
    }
    }


    // cluster_node_status_cluster_totals_reserved->ram
    if(cluster_node_status_cluster_totals_reserved->ram) {
    if(cJSON_AddNumberToObject(item, "ram", cluster_node_status_cluster_totals_reserved->ram) == NULL) {
    goto fail; //Numeric
    }
    }


    // cluster_node_status_cluster_totals_reserved->disk
    if(cluster_node_status_cluster_totals_reserved->disk) {
    if(cJSON_AddNumberToObject(item, "disk", cluster_node_status_cluster_totals_reserved->disk) == NULL) {
    goto fail; //Numeric
    }
    }


    // cluster_node_status_cluster_totals_reserved->slot
    if(cluster_node_status_cluster_totals_reserved->slot) {
    if(cJSON_AddNumberToObject(item, "slot", cluster_node_status_cluster_totals_reserved->slot) == NULL) {
    goto fail; //Numeric
    }
    }


    // cluster_node_status_cluster_totals_reserved->gpu
    if(cluster_node_status_cluster_totals_reserved->gpu) {
    if(cJSON_AddNumberToObject(item, "gpu", cluster_node_status_cluster_totals_reserved->gpu) == NULL) {
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

cluster_node_status_cluster_totals_reserved_t *cluster_node_status_cluster_totals_reserved_parseFromJSON(cJSON *cluster_node_status_cluster_totals_reservedJSON){

    cluster_node_status_cluster_totals_reserved_t *cluster_node_status_cluster_totals_reserved_local_var = NULL;

    // cluster_node_status_cluster_totals_reserved->cores
    cJSON *cores = cJSON_GetObjectItemCaseSensitive(cluster_node_status_cluster_totals_reservedJSON, "cores");
    if (cJSON_IsNull(cores)) {
        cores = NULL;
    }
    if (cores) { 
    if(!cJSON_IsNumber(cores))
    {
    goto end; //Numeric
    }
    }

    // cluster_node_status_cluster_totals_reserved->ram
    cJSON *ram = cJSON_GetObjectItemCaseSensitive(cluster_node_status_cluster_totals_reservedJSON, "ram");
    if (cJSON_IsNull(ram)) {
        ram = NULL;
    }
    if (ram) { 
    if(!cJSON_IsNumber(ram))
    {
    goto end; //Numeric
    }
    }

    // cluster_node_status_cluster_totals_reserved->disk
    cJSON *disk = cJSON_GetObjectItemCaseSensitive(cluster_node_status_cluster_totals_reservedJSON, "disk");
    if (cJSON_IsNull(disk)) {
        disk = NULL;
    }
    if (disk) { 
    if(!cJSON_IsNumber(disk))
    {
    goto end; //Numeric
    }
    }

    // cluster_node_status_cluster_totals_reserved->slot
    cJSON *slot = cJSON_GetObjectItemCaseSensitive(cluster_node_status_cluster_totals_reservedJSON, "slot");
    if (cJSON_IsNull(slot)) {
        slot = NULL;
    }
    if (slot) { 
    if(!cJSON_IsNumber(slot))
    {
    goto end; //Numeric
    }
    }

    // cluster_node_status_cluster_totals_reserved->gpu
    cJSON *gpu = cJSON_GetObjectItemCaseSensitive(cluster_node_status_cluster_totals_reservedJSON, "gpu");
    if (cJSON_IsNull(gpu)) {
        gpu = NULL;
    }
    if (gpu) { 
    if(!cJSON_IsNumber(gpu))
    {
    goto end; //Numeric
    }
    }


    cluster_node_status_cluster_totals_reserved_local_var = cluster_node_status_cluster_totals_reserved_create_internal (
        cores ? cores->valuedouble : 0,
        ram ? ram->valuedouble : 0,
        disk ? disk->valuedouble : 0,
        slot ? slot->valuedouble : 0,
        gpu ? gpu->valuedouble : 0
        );

    return cluster_node_status_cluster_totals_reserved_local_var;
end:
    return NULL;

}
