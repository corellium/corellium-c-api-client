#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "node_updates_failed.h"



static node_updates_failed_t *node_updates_failed_create_internal(
    char *message,
    list_t *nodes
    ) {
    node_updates_failed_t *node_updates_failed_local_var = malloc(sizeof(node_updates_failed_t));
    if (!node_updates_failed_local_var) {
        return NULL;
    }
    node_updates_failed_local_var->message = message;
    node_updates_failed_local_var->nodes = nodes;

    node_updates_failed_local_var->_library_owned = 1;
    return node_updates_failed_local_var;
}

__attribute__((deprecated)) node_updates_failed_t *node_updates_failed_create(
    char *message,
    list_t *nodes
    ) {
    return node_updates_failed_create_internal (
        message,
        nodes
        );
}

void node_updates_failed_free(node_updates_failed_t *node_updates_failed) {
    if(NULL == node_updates_failed){
        return ;
    }
    if(node_updates_failed->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "node_updates_failed_free");
        return ;
    }
    listEntry_t *listEntry;
    if (node_updates_failed->message) {
        free(node_updates_failed->message);
        node_updates_failed->message = NULL;
    }
    if (node_updates_failed->nodes) {
        list_ForEach(listEntry, node_updates_failed->nodes) {
            node_information_v1_free(listEntry->data);
        }
        list_freeList(node_updates_failed->nodes);
        node_updates_failed->nodes = NULL;
    }
    free(node_updates_failed);
}

cJSON *node_updates_failed_convertToJSON(node_updates_failed_t *node_updates_failed) {
    cJSON *item = cJSON_CreateObject();

    // node_updates_failed->message
    if(node_updates_failed->message) {
    if(cJSON_AddStringToObject(item, "message", node_updates_failed->message) == NULL) {
    goto fail; //String
    }
    }


    // node_updates_failed->nodes
    if(node_updates_failed->nodes) {
    cJSON *nodes = cJSON_AddArrayToObject(item, "nodes");
    if(nodes == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *nodesListEntry;
    if (node_updates_failed->nodes) {
    list_ForEach(nodesListEntry, node_updates_failed->nodes) {
    cJSON *itemLocal = node_information_v1_convertToJSON(nodesListEntry->data);
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

node_updates_failed_t *node_updates_failed_parseFromJSON(cJSON *node_updates_failedJSON){

    node_updates_failed_t *node_updates_failed_local_var = NULL;

    // define the local list for node_updates_failed->nodes
    list_t *nodesList = NULL;

    // node_updates_failed->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(node_updates_failedJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (message) { 
    if(!cJSON_IsString(message) && !cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // node_updates_failed->nodes
    cJSON *nodes = cJSON_GetObjectItemCaseSensitive(node_updates_failedJSON, "nodes");
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
        node_information_v1_t *nodesItem = node_information_v1_parseFromJSON(nodes_local_nonprimitive);

        list_addElement(nodesList, nodesItem);
    }
    }


    node_updates_failed_local_var = node_updates_failed_create_internal (
        message && !cJSON_IsNull(message) ? strdup(message->valuestring) : NULL,
        nodes ? nodesList : NULL
        );

    return node_updates_failed_local_var;
end:
    if (nodesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, nodesList) {
            node_information_v1_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(nodesList);
        nodesList = NULL;
    }
    return NULL;

}
