#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cluster_node.h"



static cluster_node_t *cluster_node_create_internal(
    cluster_node_reserved_t *reserved,
    cluster_node_total_t *total,
    cluster_node_available_t *available,
    char *hostname,
    char *address,
    char *last_seen
    ) {
    cluster_node_t *cluster_node_local_var = malloc(sizeof(cluster_node_t));
    if (!cluster_node_local_var) {
        return NULL;
    }
    cluster_node_local_var->reserved = reserved;
    cluster_node_local_var->total = total;
    cluster_node_local_var->available = available;
    cluster_node_local_var->hostname = hostname;
    cluster_node_local_var->address = address;
    cluster_node_local_var->last_seen = last_seen;

    cluster_node_local_var->_library_owned = 1;
    return cluster_node_local_var;
}

__attribute__((deprecated)) cluster_node_t *cluster_node_create(
    cluster_node_reserved_t *reserved,
    cluster_node_total_t *total,
    cluster_node_available_t *available,
    char *hostname,
    char *address,
    char *last_seen
    ) {
    return cluster_node_create_internal (
        reserved,
        total,
        available,
        hostname,
        address,
        last_seen
        );
}

void cluster_node_free(cluster_node_t *cluster_node) {
    if(NULL == cluster_node){
        return ;
    }
    if(cluster_node->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cluster_node_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cluster_node->reserved) {
        cluster_node_reserved_free(cluster_node->reserved);
        cluster_node->reserved = NULL;
    }
    if (cluster_node->total) {
        cluster_node_total_free(cluster_node->total);
        cluster_node->total = NULL;
    }
    if (cluster_node->available) {
        cluster_node_available_free(cluster_node->available);
        cluster_node->available = NULL;
    }
    if (cluster_node->hostname) {
        free(cluster_node->hostname);
        cluster_node->hostname = NULL;
    }
    if (cluster_node->address) {
        free(cluster_node->address);
        cluster_node->address = NULL;
    }
    if (cluster_node->last_seen) {
        free(cluster_node->last_seen);
        cluster_node->last_seen = NULL;
    }
    free(cluster_node);
}

cJSON *cluster_node_convertToJSON(cluster_node_t *cluster_node) {
    cJSON *item = cJSON_CreateObject();

    // cluster_node->reserved
    if (!cluster_node->reserved) {
        goto fail;
    }
    cJSON *reserved_local_JSON = cluster_node_reserved_convertToJSON(cluster_node->reserved);
    if(reserved_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reserved", reserved_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // cluster_node->total
    if (!cluster_node->total) {
        goto fail;
    }
    cJSON *total_local_JSON = cluster_node_total_convertToJSON(cluster_node->total);
    if(total_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "total", total_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // cluster_node->available
    if (!cluster_node->available) {
        goto fail;
    }
    cJSON *available_local_JSON = cluster_node_available_convertToJSON(cluster_node->available);
    if(available_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "available", available_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // cluster_node->hostname
    if(cluster_node->hostname) {
    if(cJSON_AddStringToObject(item, "hostname", cluster_node->hostname) == NULL) {
    goto fail; //String
    }
    }


    // cluster_node->address
    if (!cluster_node->address) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "address", cluster_node->address) == NULL) {
    goto fail; //String
    }


    // cluster_node->last_seen
    if (!cluster_node->last_seen) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "lastSeen", cluster_node->last_seen) == NULL) {
    goto fail; //Date-Time
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

cluster_node_t *cluster_node_parseFromJSON(cJSON *cluster_nodeJSON){

    cluster_node_t *cluster_node_local_var = NULL;

    // define the local variable for cluster_node->reserved
    cluster_node_reserved_t *reserved_local_nonprim = NULL;

    // define the local variable for cluster_node->total
    cluster_node_total_t *total_local_nonprim = NULL;

    // define the local variable for cluster_node->available
    cluster_node_available_t *available_local_nonprim = NULL;

    // cluster_node->reserved
    cJSON *reserved = cJSON_GetObjectItemCaseSensitive(cluster_nodeJSON, "reserved");
    if (cJSON_IsNull(reserved)) {
        reserved = NULL;
    }
    if (!reserved) {
        goto end;
    }

    
    reserved_local_nonprim = cluster_node_reserved_parseFromJSON(reserved); //nonprimitive

    // cluster_node->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(cluster_nodeJSON, "total");
    if (cJSON_IsNull(total)) {
        total = NULL;
    }
    if (!total) {
        goto end;
    }

    
    total_local_nonprim = cluster_node_total_parseFromJSON(total); //nonprimitive

    // cluster_node->available
    cJSON *available = cJSON_GetObjectItemCaseSensitive(cluster_nodeJSON, "available");
    if (cJSON_IsNull(available)) {
        available = NULL;
    }
    if (!available) {
        goto end;
    }

    
    available_local_nonprim = cluster_node_available_parseFromJSON(available); //nonprimitive

    // cluster_node->hostname
    cJSON *hostname = cJSON_GetObjectItemCaseSensitive(cluster_nodeJSON, "hostname");
    if (cJSON_IsNull(hostname)) {
        hostname = NULL;
    }
    if (hostname) { 
    if(!cJSON_IsString(hostname) && !cJSON_IsNull(hostname))
    {
    goto end; //String
    }
    }

    // cluster_node->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(cluster_nodeJSON, "address");
    if (cJSON_IsNull(address)) {
        address = NULL;
    }
    if (!address) {
        goto end;
    }

    
    if(!cJSON_IsString(address))
    {
    goto end; //String
    }

    // cluster_node->last_seen
    cJSON *last_seen = cJSON_GetObjectItemCaseSensitive(cluster_nodeJSON, "lastSeen");
    if (cJSON_IsNull(last_seen)) {
        last_seen = NULL;
    }
    if (!last_seen) {
        goto end;
    }

    
    if(!cJSON_IsString(last_seen) && !cJSON_IsNull(last_seen))
    {
    goto end; //DateTime
    }


    cluster_node_local_var = cluster_node_create_internal (
        reserved_local_nonprim,
        total_local_nonprim,
        available_local_nonprim,
        hostname && !cJSON_IsNull(hostname) ? strdup(hostname->valuestring) : NULL,
        strdup(address->valuestring),
        strdup(last_seen->valuestring)
        );

    return cluster_node_local_var;
end:
    if (reserved_local_nonprim) {
        cluster_node_reserved_free(reserved_local_nonprim);
        reserved_local_nonprim = NULL;
    }
    if (total_local_nonprim) {
        cluster_node_total_free(total_local_nonprim);
        total_local_nonprim = NULL;
    }
    if (available_local_nonprim) {
        cluster_node_available_free(available_local_nonprim);
        available_local_nonprim = NULL;
    }
    return NULL;

}
