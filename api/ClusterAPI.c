#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "ClusterAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096


// Delete cluster snapshot
//
// **Required role:** Cluster administrator.  Deletes a cluster snapshot by ID. Requires the clusterSnapshotMgmt feature.  Deletes are idempotent: an unknown `snapshotId`, or a snapshot that was already deleted, is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing.
//
void
ClusterAPI_v3DeleteClusterSnapshot(apiClient_t *apiClient, char *snapshotId)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v3/cluster/snapshots/{snapshotId}");

    if(!snapshotId)
        goto end;


    // Path Params
    long sizeOfPathParams_snapshotId = strlen(snapshotId)+3 + sizeof("{ snapshotId }") - 1;
    if(snapshotId == NULL) {
        goto end;
    }
    char* localVarToReplace_snapshotId = malloc(sizeOfPathParams_snapshotId);
    sprintf(localVarToReplace_snapshotId, "{%s}", "snapshotId");

    localVarPath = strReplace(localVarPath, localVarToReplace_snapshotId, snapshotId);


    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "DELETE");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 204) {
    //    printf("%s\n","Snapshot deleted.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Snapshot cannot be deleted (in use, still creating, or freshly restored).");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Authentication required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Cluster administrator permissions required. The clusterSnapshotMgmt feature must be enabled.");
    //}
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_snapshotId);

}

// Get cluster configuration
//
// **Required role:** Cluster administrator.  Returns the current cluster configuration.
//
cluster_config_t*
ClusterAPI_v3GetClusterConfig(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v3/cluster/config");




    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Cluster configuration object.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Authentication required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Cluster administrator permissions required.");
    //}
    //nonprimitive not container
    cluster_config_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ClusterAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = cluster_config_parseFromJSON(ClusterAPIlocalVarJSON);
        cJSON_Delete(ClusterAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get cluster node
//
// **Required role:** Cluster administrator.  Returns details for a specific node by ID.
//
node_information_t*
ClusterAPI_v3GetClusterNode(apiClient_t *apiClient, char *nodeId)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v3/cluster/nodes/{nodeId}");

    if(!nodeId)
        goto end;


    // Path Params
    long sizeOfPathParams_nodeId = strlen(nodeId)+3 + sizeof("{ nodeId }") - 1;
    if(nodeId == NULL) {
        goto end;
    }
    char* localVarToReplace_nodeId = malloc(sizeOfPathParams_nodeId);
    sprintf(localVarToReplace_nodeId, "{%s}", "nodeId");

    localVarPath = strReplace(localVarPath, localVarToReplace_nodeId, nodeId);


    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Node details.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Authentication required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Cluster administrator permissions required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Node not found.");
    //}
    //nonprimitive not container
    node_information_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ClusterAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = node_information_parseFromJSON(ClusterAPIlocalVarJSON);
        cJSON_Delete(ClusterAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_nodeId);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get node console websocket URL
//
// **Required role:** Cluster administrator.  Returns the WebSocket URL for accessing the node console via SSH. Connect to the returned URL to open the console stream.
//
node_console_endpoint_t*
ClusterAPI_v3GetClusterNodeConsole(apiClient_t *apiClient, char *nodeId)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v3/cluster/nodes/{nodeId}/console");

    if(!nodeId)
        goto end;


    // Path Params
    long sizeOfPathParams_nodeId = strlen(nodeId)+3 + sizeof("{ nodeId }") - 1;
    if(nodeId == NULL) {
        goto end;
    }
    char* localVarToReplace_nodeId = malloc(sizeOfPathParams_nodeId);
    sprintf(localVarToReplace_nodeId, "{%s}", "nodeId");

    localVarPath = strReplace(localVarPath, localVarToReplace_nodeId, nodeId);


    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Console WebSocket URL.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Authentication required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Cluster administrator permissions required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Node not found.");
    //}
    //nonprimitive not container
    node_console_endpoint_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ClusterAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = node_console_endpoint_parseFromJSON(ClusterAPIlocalVarJSON);
        cJSON_Delete(ClusterAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_nodeId);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get cluster snapshot
//
// **Required role:** Cluster administrator.  Returns details for a specific cluster snapshot. Requires the clusterSnapshotMgmt feature.
//
cluster_snapshot_t*
ClusterAPI_v3GetClusterSnapshot(apiClient_t *apiClient, char *snapshotId)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v3/cluster/snapshots/{snapshotId}");

    if(!snapshotId)
        goto end;


    // Path Params
    long sizeOfPathParams_snapshotId = strlen(snapshotId)+3 + sizeof("{ snapshotId }") - 1;
    if(snapshotId == NULL) {
        goto end;
    }
    char* localVarToReplace_snapshotId = malloc(sizeOfPathParams_snapshotId);
    sprintf(localVarToReplace_snapshotId, "{%s}", "snapshotId");

    localVarPath = strReplace(localVarPath, localVarToReplace_snapshotId, snapshotId);


    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Cluster snapshot details.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid snapshot ID.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Authentication required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Cluster administrator permissions required. The clusterSnapshotMgmt feature must be enabled.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Snapshot not found.");
    //}
    //nonprimitive not container
    cluster_snapshot_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ClusterAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = cluster_snapshot_parseFromJSON(ClusterAPIlocalVarJSON);
        cJSON_Delete(ClusterAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_snapshotId);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// List cluster nodes
//
// **Required role:** Cluster administrator.  Returns information about all nodes in the cluster.
//
node_list_t*
ClusterAPI_v3ListClusterNodes(apiClient_t *apiClient, double *limit, double *offset)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v3/cluster/nodes");





    // query parameters
    char *keyQuery_limit = NULL;
    char * valueQuery_limit = NULL;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_limit, MAX_NUMBER_LENGTH, "%d", *limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
    }

    // query parameters
    char *keyQuery_offset = NULL;
    char * valueQuery_offset = NULL;
    keyValuePair_t *keyPairQuery_offset = 0;
    if (offset)
    {
        keyQuery_offset = strdup("offset");
        valueQuery_offset = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_offset, MAX_NUMBER_LENGTH, "%d", *offset);
        keyPairQuery_offset = keyValuePair_create(keyQuery_offset, valueQuery_offset);
        list_addElement(localVarQueryParameters,keyPairQuery_offset);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Paginated list of cluster nodes.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Authentication required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Cluster administrator permissions required.");
    //}
    //nonprimitive not container
    node_list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ClusterAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = node_list_parseFromJSON(ClusterAPIlocalVarJSON);
        cJSON_Delete(ClusterAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    if(keyQuery_limit){
        free(keyQuery_limit);
        keyQuery_limit = NULL;
    }
    if(valueQuery_limit){
        free(valueQuery_limit);
        valueQuery_limit = NULL;
    }
    if(keyPairQuery_limit){
        keyValuePair_free(keyPairQuery_limit);
        keyPairQuery_limit = NULL;
    }
    if(keyQuery_offset){
        free(keyQuery_offset);
        keyQuery_offset = NULL;
    }
    if(valueQuery_offset){
        free(valueQuery_offset);
        valueQuery_offset = NULL;
    }
    if(keyPairQuery_offset){
        keyValuePair_free(keyPairQuery_offset);
        keyPairQuery_offset = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// List cluster snapshots
//
// **Required role:** Cluster administrator.  Returns a paginated list of cluster volume snapshots. Requires the clusterSnapshotMgmt feature.
//
cluster_snapshot_list_t*
ClusterAPI_v3ListClusterSnapshots(apiClient_t *apiClient, double *limit, double *offset, char *springboard, char *live, char *fresh, char *deviceName, char *task, char *search, char to, char from, char *orderBy)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v3/cluster/snapshots");





    // query parameters
    char *keyQuery_limit = NULL;
    char * valueQuery_limit = NULL;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_limit, MAX_NUMBER_LENGTH, "%d", *limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
    }

    // query parameters
    char *keyQuery_offset = NULL;
    char * valueQuery_offset = NULL;
    keyValuePair_t *keyPairQuery_offset = 0;
    if (offset)
    {
        keyQuery_offset = strdup("offset");
        valueQuery_offset = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_offset, MAX_NUMBER_LENGTH, "%d", *offset);
        keyPairQuery_offset = keyValuePair_create(keyQuery_offset, valueQuery_offset);
        list_addElement(localVarQueryParameters,keyPairQuery_offset);
    }

    // query parameters
    char *keyQuery_springboard = NULL;
    char * valueQuery_springboard = NULL;
    keyValuePair_t *keyPairQuery_springboard = 0;
    if (springboard)
    {
        keyQuery_springboard = strdup("springboard");
        valueQuery_springboard = strdup((springboard));
        keyPairQuery_springboard = keyValuePair_create(keyQuery_springboard, valueQuery_springboard);
        list_addElement(localVarQueryParameters,keyPairQuery_springboard);
    }

    // query parameters
    char *keyQuery_live = NULL;
    char * valueQuery_live = NULL;
    keyValuePair_t *keyPairQuery_live = 0;
    if (live)
    {
        keyQuery_live = strdup("live");
        valueQuery_live = strdup((live));
        keyPairQuery_live = keyValuePair_create(keyQuery_live, valueQuery_live);
        list_addElement(localVarQueryParameters,keyPairQuery_live);
    }

    // query parameters
    char *keyQuery_fresh = NULL;
    char * valueQuery_fresh = NULL;
    keyValuePair_t *keyPairQuery_fresh = 0;
    if (fresh)
    {
        keyQuery_fresh = strdup("fresh");
        valueQuery_fresh = strdup((fresh));
        keyPairQuery_fresh = keyValuePair_create(keyQuery_fresh, valueQuery_fresh);
        list_addElement(localVarQueryParameters,keyPairQuery_fresh);
    }

    // query parameters
    char *keyQuery_deviceName = NULL;
    char * valueQuery_deviceName = NULL;
    keyValuePair_t *keyPairQuery_deviceName = 0;
    if (deviceName)
    {
        keyQuery_deviceName = strdup("deviceName");
        valueQuery_deviceName = strdup((deviceName));
        keyPairQuery_deviceName = keyValuePair_create(keyQuery_deviceName, valueQuery_deviceName);
        list_addElement(localVarQueryParameters,keyPairQuery_deviceName);
    }

    // query parameters
    char *keyQuery_task = NULL;
    char * valueQuery_task = NULL;
    keyValuePair_t *keyPairQuery_task = 0;
    if (task)
    {
        keyQuery_task = strdup("task");
        valueQuery_task = strdup((task));
        keyPairQuery_task = keyValuePair_create(keyQuery_task, valueQuery_task);
        list_addElement(localVarQueryParameters,keyPairQuery_task);
    }

    // query parameters
    char *keyQuery_search = NULL;
    char * valueQuery_search = NULL;
    keyValuePair_t *keyPairQuery_search = 0;
    if (search)
    {
        keyQuery_search = strdup("search");
        valueQuery_search = strdup((search));
        keyPairQuery_search = keyValuePair_create(keyQuery_search, valueQuery_search);
        list_addElement(localVarQueryParameters,keyPairQuery_search);
    }

    // query parameters
    char *keyQuery_to = NULL;
    char valueQuery_to ;
    keyValuePair_t *keyPairQuery_to = 0;
    if (to)
    {
        keyQuery_to = strdup("to");
        valueQuery_to = (to);
        keyPairQuery_to = keyValuePair_create(keyQuery_to, &valueQuery_to);
        list_addElement(localVarQueryParameters,keyPairQuery_to);
    }

    // query parameters
    char *keyQuery_from = NULL;
    char valueQuery_from ;
    keyValuePair_t *keyPairQuery_from = 0;
    if (from)
    {
        keyQuery_from = strdup("from");
        valueQuery_from = (from);
        keyPairQuery_from = keyValuePair_create(keyQuery_from, &valueQuery_from);
        list_addElement(localVarQueryParameters,keyPairQuery_from);
    }

    // query parameters
    char *keyQuery_orderBy = NULL;
    char * valueQuery_orderBy = NULL;
    keyValuePair_t *keyPairQuery_orderBy = 0;
    if (orderBy)
    {
        keyQuery_orderBy = strdup("orderBy");
        valueQuery_orderBy = strdup((orderBy));
        keyPairQuery_orderBy = keyValuePair_create(keyQuery_orderBy, valueQuery_orderBy);
        list_addElement(localVarQueryParameters,keyPairQuery_orderBy);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Paginated list of cluster snapshots.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid query parameter(s).");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Authentication required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Cluster administrator permissions required. The clusterSnapshotMgmt feature must be enabled.");
    //}
    //nonprimitive not container
    cluster_snapshot_list_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ClusterAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = cluster_snapshot_list_parseFromJSON(ClusterAPIlocalVarJSON);
        cJSON_Delete(ClusterAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    if(keyQuery_limit){
        free(keyQuery_limit);
        keyQuery_limit = NULL;
    }
    if(valueQuery_limit){
        free(valueQuery_limit);
        valueQuery_limit = NULL;
    }
    if(keyPairQuery_limit){
        keyValuePair_free(keyPairQuery_limit);
        keyPairQuery_limit = NULL;
    }
    if(keyQuery_offset){
        free(keyQuery_offset);
        keyQuery_offset = NULL;
    }
    if(valueQuery_offset){
        free(valueQuery_offset);
        valueQuery_offset = NULL;
    }
    if(keyPairQuery_offset){
        keyValuePair_free(keyPairQuery_offset);
        keyPairQuery_offset = NULL;
    }
    if(keyQuery_springboard){
        free(keyQuery_springboard);
        keyQuery_springboard = NULL;
    }
    if(valueQuery_springboard){
        free(valueQuery_springboard);
        valueQuery_springboard = NULL;
    }
    if(keyPairQuery_springboard){
        keyValuePair_free(keyPairQuery_springboard);
        keyPairQuery_springboard = NULL;
    }
    if(keyQuery_live){
        free(keyQuery_live);
        keyQuery_live = NULL;
    }
    if(valueQuery_live){
        free(valueQuery_live);
        valueQuery_live = NULL;
    }
    if(keyPairQuery_live){
        keyValuePair_free(keyPairQuery_live);
        keyPairQuery_live = NULL;
    }
    if(keyQuery_fresh){
        free(keyQuery_fresh);
        keyQuery_fresh = NULL;
    }
    if(valueQuery_fresh){
        free(valueQuery_fresh);
        valueQuery_fresh = NULL;
    }
    if(keyPairQuery_fresh){
        keyValuePair_free(keyPairQuery_fresh);
        keyPairQuery_fresh = NULL;
    }
    if(keyQuery_deviceName){
        free(keyQuery_deviceName);
        keyQuery_deviceName = NULL;
    }
    if(valueQuery_deviceName){
        free(valueQuery_deviceName);
        valueQuery_deviceName = NULL;
    }
    if(keyPairQuery_deviceName){
        keyValuePair_free(keyPairQuery_deviceName);
        keyPairQuery_deviceName = NULL;
    }
    if(keyQuery_task){
        free(keyQuery_task);
        keyQuery_task = NULL;
    }
    if(valueQuery_task){
        free(valueQuery_task);
        valueQuery_task = NULL;
    }
    if(keyPairQuery_task){
        keyValuePair_free(keyPairQuery_task);
        keyPairQuery_task = NULL;
    }
    if(keyQuery_search){
        free(keyQuery_search);
        keyQuery_search = NULL;
    }
    if(valueQuery_search){
        free(valueQuery_search);
        valueQuery_search = NULL;
    }
    if(keyPairQuery_search){
        keyValuePair_free(keyPairQuery_search);
        keyPairQuery_search = NULL;
    }
    if(keyQuery_to){
        free(keyQuery_to);
        keyQuery_to = NULL;
    }
    if(keyPairQuery_to){
        keyValuePair_free(keyPairQuery_to);
        keyPairQuery_to = NULL;
    }
    if(keyQuery_from){
        free(keyQuery_from);
        keyQuery_from = NULL;
    }
    if(keyPairQuery_from){
        keyValuePair_free(keyPairQuery_from);
        keyPairQuery_from = NULL;
    }
    if(keyQuery_orderBy){
        free(keyQuery_orderBy);
        keyQuery_orderBy = NULL;
    }
    if(valueQuery_orderBy){
        free(valueQuery_orderBy);
        valueQuery_orderBy = NULL;
    }
    if(keyPairQuery_orderBy){
        keyValuePair_free(keyPairQuery_orderBy);
        keyPairQuery_orderBy = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Update cluster configuration
//
// **Required role:** Cluster administrator.  Applies configuration changes across all controller nodes.
//
void
ClusterAPI_v3PatchClusterConfig(apiClient_t *apiClient, patch_cluster_config_body_t *patch_cluster_config_body)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v3/cluster/config");





    // Body Param
    cJSON *localVarSingleItemJSON_patch_cluster_config_body = NULL;
    if (patch_cluster_config_body != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_patch_cluster_config_body = patch_cluster_config_body_convertToJSON(patch_cluster_config_body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_patch_cluster_config_body);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "PATCH");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Configuration updated successfully.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Invalid request body.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Authentication required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Cluster administrator permissions required.");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Configuration update failed on one or more nodes.");
    //}
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (localVarSingleItemJSON_patch_cluster_config_body) {
        cJSON_Delete(localVarSingleItemJSON_patch_cluster_config_body);
        localVarSingleItemJSON_patch_cluster_config_body = NULL;
    }
    free(localVarBodyParameters);

}

