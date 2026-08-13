#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cluster_config_update_error.h"



static cluster_config_update_error_t *cluster_config_update_error_create_internal(
    char *message,
    list_t *nodes
    ) {
    cluster_config_update_error_t *cluster_config_update_error_local_var = malloc(sizeof(cluster_config_update_error_t));
    if (!cluster_config_update_error_local_var) {
        return NULL;
    }
    cluster_config_update_error_local_var->message = message;
    cluster_config_update_error_local_var->nodes = nodes;

    cluster_config_update_error_local_var->_library_owned = 1;
    return cluster_config_update_error_local_var;
}

__attribute__((deprecated)) cluster_config_update_error_t *cluster_config_update_error_create(
    char *message,
    list_t *nodes
    ) {
    return cluster_config_update_error_create_internal (
        message,
        nodes
        );
}

void cluster_config_update_error_free(cluster_config_update_error_t *cluster_config_update_error) {
    if(NULL == cluster_config_update_error){
        return ;
    }
    if(cluster_config_update_error->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cluster_config_update_error_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cluster_config_update_error->message) {
        free(cluster_config_update_error->message);
        cluster_config_update_error->message = NULL;
    }
    if (cluster_config_update_error->nodes) {
        list_ForEach(listEntry, cluster_config_update_error->nodes) {
            node_information_free(listEntry->data);
        }
        list_freeList(cluster_config_update_error->nodes);
        cluster_config_update_error->nodes = NULL;
    }
    free(cluster_config_update_error);
}

cJSON *cluster_config_update_error_convertToJSON(cluster_config_update_error_t *cluster_config_update_error) {
    cJSON *item = cJSON_CreateObject();

    // cluster_config_update_error->message
    if (!cluster_config_update_error->message) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message", cluster_config_update_error->message) == NULL) {
    goto fail; //String
    }


    // cluster_config_update_error->nodes
    if(cluster_config_update_error->nodes) {
    cJSON *nodes = cJSON_AddArrayToObject(item, "nodes");
    if(nodes == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *nodesListEntry;
    if (cluster_config_update_error->nodes) {
    list_ForEach(nodesListEntry, cluster_config_update_error->nodes) {
    cJSON *itemLocal = node_information_convertToJSON(nodesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(nodes, itemLocal);
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

cluster_config_update_error_t *cluster_config_update_error_parseFromJSON(cJSON *cluster_config_update_errorJSON){

    cluster_config_update_error_t *cluster_config_update_error_local_var = NULL;

    // define the local list for cluster_config_update_error->nodes
    list_t *nodesList = NULL;

    // cluster_config_update_error->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(cluster_config_update_errorJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (!message) {
        goto end;
    }

    
    if(!cJSON_IsString(message))
    {
    goto end; //String
    }

    // cluster_config_update_error->nodes
    cJSON *nodes = cJSON_GetObjectItemCaseSensitive(cluster_config_update_errorJSON, "nodes");
    if (cJSON_IsNull(nodes)) {
        nodes = NULL;
    }
    if (nodes) { 
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
        node_information_t *nodesItem = node_information_parseFromJSON(nodes_local_nonprimitive);

        list_addElement(nodesList, nodesItem);
    }
    }


    cluster_config_update_error_local_var = cluster_config_update_error_create_internal (
        strdup(message->valuestring),
        nodes ? nodesList : NULL
        );

    return cluster_config_update_error_local_var;
end:
    if (nodesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, nodesList) {
            node_information_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(nodesList);
        nodesList = NULL;
    }
    return NULL;

}
