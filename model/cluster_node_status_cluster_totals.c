#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cluster_node_status_cluster_totals.h"



static cluster_node_status_cluster_totals_t *cluster_node_status_cluster_totals_create_internal(
    cluster_node_status_cluster_totals_reserved_t *reserved,
    cluster_node_status_cluster_totals_total_t *total,
    cluster_node_status_cluster_totals_available_t *available
    ) {
    cluster_node_status_cluster_totals_t *cluster_node_status_cluster_totals_local_var = malloc(sizeof(cluster_node_status_cluster_totals_t));
    if (!cluster_node_status_cluster_totals_local_var) {
        return NULL;
    }
    cluster_node_status_cluster_totals_local_var->reserved = reserved;
    cluster_node_status_cluster_totals_local_var->total = total;
    cluster_node_status_cluster_totals_local_var->available = available;

    cluster_node_status_cluster_totals_local_var->_library_owned = 1;
    return cluster_node_status_cluster_totals_local_var;
}

__attribute__((deprecated)) cluster_node_status_cluster_totals_t *cluster_node_status_cluster_totals_create(
    cluster_node_status_cluster_totals_reserved_t *reserved,
    cluster_node_status_cluster_totals_total_t *total,
    cluster_node_status_cluster_totals_available_t *available
    ) {
    return cluster_node_status_cluster_totals_create_internal (
        reserved,
        total,
        available
        );
}

void cluster_node_status_cluster_totals_free(cluster_node_status_cluster_totals_t *cluster_node_status_cluster_totals) {
    if(NULL == cluster_node_status_cluster_totals){
        return ;
    }
    if(cluster_node_status_cluster_totals->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cluster_node_status_cluster_totals_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cluster_node_status_cluster_totals->reserved) {
        cluster_node_status_cluster_totals_reserved_free(cluster_node_status_cluster_totals->reserved);
        cluster_node_status_cluster_totals->reserved = NULL;
    }
    if (cluster_node_status_cluster_totals->total) {
        cluster_node_status_cluster_totals_total_free(cluster_node_status_cluster_totals->total);
        cluster_node_status_cluster_totals->total = NULL;
    }
    if (cluster_node_status_cluster_totals->available) {
        cluster_node_status_cluster_totals_available_free(cluster_node_status_cluster_totals->available);
        cluster_node_status_cluster_totals->available = NULL;
    }
    free(cluster_node_status_cluster_totals);
}

cJSON *cluster_node_status_cluster_totals_convertToJSON(cluster_node_status_cluster_totals_t *cluster_node_status_cluster_totals) {
    cJSON *item = cJSON_CreateObject();

    // cluster_node_status_cluster_totals->reserved
    if (!cluster_node_status_cluster_totals->reserved) {
        goto fail;
    }
    cJSON *reserved_local_JSON = cluster_node_status_cluster_totals_reserved_convertToJSON(cluster_node_status_cluster_totals->reserved);
    if(reserved_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reserved", reserved_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // cluster_node_status_cluster_totals->total
    if (!cluster_node_status_cluster_totals->total) {
        goto fail;
    }
    cJSON *total_local_JSON = cluster_node_status_cluster_totals_total_convertToJSON(cluster_node_status_cluster_totals->total);
    if(total_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "total", total_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // cluster_node_status_cluster_totals->available
    if (!cluster_node_status_cluster_totals->available) {
        goto fail;
    }
    cJSON *available_local_JSON = cluster_node_status_cluster_totals_available_convertToJSON(cluster_node_status_cluster_totals->available);
    if(available_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "available", available_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

cluster_node_status_cluster_totals_t *cluster_node_status_cluster_totals_parseFromJSON(cJSON *cluster_node_status_cluster_totalsJSON){

    cluster_node_status_cluster_totals_t *cluster_node_status_cluster_totals_local_var = NULL;

    // define the local variable for cluster_node_status_cluster_totals->reserved
    cluster_node_status_cluster_totals_reserved_t *reserved_local_nonprim = NULL;

    // define the local variable for cluster_node_status_cluster_totals->total
    cluster_node_status_cluster_totals_total_t *total_local_nonprim = NULL;

    // define the local variable for cluster_node_status_cluster_totals->available
    cluster_node_status_cluster_totals_available_t *available_local_nonprim = NULL;

    // cluster_node_status_cluster_totals->reserved
    cJSON *reserved = cJSON_GetObjectItemCaseSensitive(cluster_node_status_cluster_totalsJSON, "reserved");
    if (cJSON_IsNull(reserved)) {
        reserved = NULL;
    }
    if (!reserved) {
        goto end;
    }

    
    reserved_local_nonprim = cluster_node_status_cluster_totals_reserved_parseFromJSON(reserved); //nonprimitive

    // cluster_node_status_cluster_totals->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(cluster_node_status_cluster_totalsJSON, "total");
    if (cJSON_IsNull(total)) {
        total = NULL;
    }
    if (!total) {
        goto end;
    }

    
    total_local_nonprim = cluster_node_status_cluster_totals_total_parseFromJSON(total); //nonprimitive

    // cluster_node_status_cluster_totals->available
    cJSON *available = cJSON_GetObjectItemCaseSensitive(cluster_node_status_cluster_totalsJSON, "available");
    if (cJSON_IsNull(available)) {
        available = NULL;
    }
    if (!available) {
        goto end;
    }

    
    available_local_nonprim = cluster_node_status_cluster_totals_available_parseFromJSON(available); //nonprimitive


    cluster_node_status_cluster_totals_local_var = cluster_node_status_cluster_totals_create_internal (
        reserved_local_nonprim,
        total_local_nonprim,
        available_local_nonprim
        );

    return cluster_node_status_cluster_totals_local_var;
end:
    if (reserved_local_nonprim) {
        cluster_node_status_cluster_totals_reserved_free(reserved_local_nonprim);
        reserved_local_nonprim = NULL;
    }
    if (total_local_nonprim) {
        cluster_node_status_cluster_totals_total_free(total_local_nonprim);
        total_local_nonprim = NULL;
    }
    if (available_local_nonprim) {
        cluster_node_status_cluster_totals_available_free(available_local_nonprim);
        available_local_nonprim = NULL;
    }
    return NULL;

}
