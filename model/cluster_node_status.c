#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cluster_node_status.h"



static cluster_node_status_t *cluster_node_status_create_internal(
    cluster_node_status_cluster_totals_t *cluster_totals,
    list_t *nodes
    ) {
    cluster_node_status_t *cluster_node_status_local_var = malloc(sizeof(cluster_node_status_t));
    if (!cluster_node_status_local_var) {
        return NULL;
    }
    cluster_node_status_local_var->cluster_totals = cluster_totals;
    cluster_node_status_local_var->nodes = nodes;

    cluster_node_status_local_var->_library_owned = 1;
    return cluster_node_status_local_var;
}

__attribute__((deprecated)) cluster_node_status_t *cluster_node_status_create(
    cluster_node_status_cluster_totals_t *cluster_totals,
    list_t *nodes
    ) {
    return cluster_node_status_create_internal (
        cluster_totals,
        nodes
        );
}

void cluster_node_status_free(cluster_node_status_t *cluster_node_status) {
    if(NULL == cluster_node_status){
        return ;
    }
    if(cluster_node_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cluster_node_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cluster_node_status->cluster_totals) {
        cluster_node_status_cluster_totals_free(cluster_node_status->cluster_totals);
        cluster_node_status->cluster_totals = NULL;
    }
    if (cluster_node_status->nodes) {
        list_ForEach(listEntry, cluster_node_status->nodes) {
            cluster_node_free(listEntry->data);
        }
        list_freeList(cluster_node_status->nodes);
        cluster_node_status->nodes = NULL;
    }
    free(cluster_node_status);
}

cJSON *cluster_node_status_convertToJSON(cluster_node_status_t *cluster_node_status) {
    cJSON *item = cJSON_CreateObject();

    // cluster_node_status->cluster_totals
    if (!cluster_node_status->cluster_totals) {
        goto fail;
    }
    cJSON *cluster_totals_local_JSON = cluster_node_status_cluster_totals_convertToJSON(cluster_node_status->cluster_totals);
    if(cluster_totals_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "clusterTotals", cluster_totals_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // cluster_node_status->nodes
    if (!cluster_node_status->nodes) {
        goto fail;
    }
    cJSON *nodes = cJSON_AddArrayToObject(item, "nodes");
    if(nodes == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *nodesListEntry;
    if (cluster_node_status->nodes) {
    list_ForEach(nodesListEntry, cluster_node_status->nodes) {
    cJSON *itemLocal = cluster_node_convertToJSON(nodesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(nodes, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

cluster_node_status_t *cluster_node_status_parseFromJSON(cJSON *cluster_node_statusJSON){

    cluster_node_status_t *cluster_node_status_local_var = NULL;

    // define the local variable for cluster_node_status->cluster_totals
    cluster_node_status_cluster_totals_t *cluster_totals_local_nonprim = NULL;

    // define the local list for cluster_node_status->nodes
    list_t *nodesList = NULL;

    // cluster_node_status->cluster_totals
    cJSON *cluster_totals = cJSON_GetObjectItemCaseSensitive(cluster_node_statusJSON, "clusterTotals");
    if (cJSON_IsNull(cluster_totals)) {
        cluster_totals = NULL;
    }
    if (!cluster_totals) {
        goto end;
    }

    
    cluster_totals_local_nonprim = cluster_node_status_cluster_totals_parseFromJSON(cluster_totals); //nonprimitive

    // cluster_node_status->nodes
    cJSON *nodes = cJSON_GetObjectItemCaseSensitive(cluster_node_statusJSON, "nodes");
    if (cJSON_IsNull(nodes)) {
        nodes = NULL;
    }
    if (!nodes) {
        goto end;
    }

    
    cJSON *nodes_local_nonprimitive = NULL;
    if(!cJSON_IsArray(nodes)){
        goto end; //nonprimitive container
    }

    nodesList = list_createList();

    cJSON_ArrayForEach(nodes_local_nonprimitive,nodes )
    {
        if(!cJSON_IsObject(nodes_local_nonprimitive)){
            goto end;
        }
        cluster_node_t *nodesItem = cluster_node_parseFromJSON(nodes_local_nonprimitive);

        list_addElement(nodesList, nodesItem);
    }


    cluster_node_status_local_var = cluster_node_status_create_internal (
        cluster_totals_local_nonprim,
        nodesList
        );

    return cluster_node_status_local_var;
end:
    if (cluster_totals_local_nonprim) {
        cluster_node_status_cluster_totals_free(cluster_totals_local_nonprim);
        cluster_totals_local_nonprim = NULL;
    }
    if (nodesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, nodesList) {
            cluster_node_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(nodesList);
        nodesList = NULL;
    }
    return NULL;

}
