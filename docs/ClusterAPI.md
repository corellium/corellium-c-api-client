# ClusterAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ClusterAPI_v3DeleteClusterSnapshot**](ClusterAPI.md#ClusterAPI_v3DeleteClusterSnapshot) | **DELETE** /v3/cluster/snapshots/{snapshotId} | Delete cluster snapshot
[**ClusterAPI_v3GetClusterConfig**](ClusterAPI.md#ClusterAPI_v3GetClusterConfig) | **GET** /v3/cluster/config | Get cluster configuration
[**ClusterAPI_v3GetClusterNode**](ClusterAPI.md#ClusterAPI_v3GetClusterNode) | **GET** /v3/cluster/nodes/{nodeId} | Get cluster node
[**ClusterAPI_v3GetClusterNodeConsole**](ClusterAPI.md#ClusterAPI_v3GetClusterNodeConsole) | **GET** /v3/cluster/nodes/{nodeId}/console | Get node console websocket URL
[**ClusterAPI_v3GetClusterSnapshot**](ClusterAPI.md#ClusterAPI_v3GetClusterSnapshot) | **GET** /v3/cluster/snapshots/{snapshotId} | Get cluster snapshot
[**ClusterAPI_v3ListClusterNodes**](ClusterAPI.md#ClusterAPI_v3ListClusterNodes) | **GET** /v3/cluster/nodes | List cluster nodes
[**ClusterAPI_v3ListClusterSnapshots**](ClusterAPI.md#ClusterAPI_v3ListClusterSnapshots) | **GET** /v3/cluster/snapshots | List cluster snapshots
[**ClusterAPI_v3PatchClusterConfig**](ClusterAPI.md#ClusterAPI_v3PatchClusterConfig) | **PATCH** /v3/cluster/config | Update cluster configuration


# **ClusterAPI_v3DeleteClusterSnapshot**
```c
// Delete cluster snapshot
//
// **Required role:** Cluster administrator.  Deletes a snapshot from the cluster, for example to free storage. Snapshots that are in use, still being created, or were just restored cannot be deleted (400). Requires a cluster administrator and the cluster snapshot management feature (`clusterSnapshotMgmt`).  Deletes are idempotent: an unknown `snapshotId`, or a snapshot that was already deleted, is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing.
//
void ClusterAPI_v3DeleteClusterSnapshot(apiClient_t *apiClient, char *snapshotId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**snapshotId** | **char \*** | Snapshot identifier. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ClusterAPI_v3GetClusterConfig**
```c
// Get cluster configuration
//
// **Required role:** Cluster administrator.  Returns the settings that apply to the whole cluster. Requires a cluster administrator.
//
cluster_config_t* ClusterAPI_v3GetClusterConfig(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[cluster_config_t](cluster_config.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ClusterAPI_v3GetClusterNode**
```c
// Get cluster node
//
// **Required role:** Cluster administrator.  Returns details for one server (node) in the cluster, identified by the ID from `v3ListClusterNodes`. Requires a cluster administrator.
//
node_information_t* ClusterAPI_v3GetClusterNode(apiClient_t *apiClient, char *nodeId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**nodeId** | **char \*** | Node identifier. | 

### Return type

[node_information_t](node_information.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ClusterAPI_v3GetClusterNodeConsole**
```c
// Get node console websocket URL
//
// **Required role:** Cluster administrator.  Returns a WebSocket URL for a terminal session on one cluster server (node), for maintenance and troubleshooting. Open the URL with a WebSocket client to get the console stream. Requires a cluster administrator.
//
node_console_endpoint_t* ClusterAPI_v3GetClusterNodeConsole(apiClient_t *apiClient, char *nodeId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**nodeId** | **char \*** | Node identifier. | 

### Return type

[node_console_endpoint_t](node_console_endpoint.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ClusterAPI_v3GetClusterSnapshot**
```c
// Get cluster snapshot
//
// **Required role:** Cluster administrator.  Returns one snapshot from the cluster-wide list. Requires a cluster administrator and the cluster snapshot management feature (`clusterSnapshotMgmt`).
//
cluster_snapshot_t* ClusterAPI_v3GetClusterSnapshot(apiClient_t *apiClient, char *snapshotId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**snapshotId** | **char \*** | Snapshot identifier. | 

### Return type

[cluster_snapshot_t](cluster_snapshot.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ClusterAPI_v3ListClusterNodes**
```c
// List cluster nodes
//
// **Required role:** Cluster administrator.  Lists the servers (nodes) that make up this Corellium cluster, with their status and resources. Use it to check cluster health or find a node before opening its console. Requires a cluster administrator. Results are paginated.
//
node_list_t* ClusterAPI_v3ListClusterNodes(apiClient_t *apiClient, double *limit, double *offset);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**limit** | **double \*** | Most results to return in one page. Whole number from 1 to 1000; defaults to 100. A value outside that range is rejected with 400. | [optional] [default to 100]
**offset** | **double \*** | How many results to skip before this page starts; defaults to 0. To get the next page, add &#x60;limit&#x60; to the previous &#x60;offset&#x60;. | [optional] [default to 0]

### Return type

[node_list_t](node_list.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ClusterAPI_v3ListClusterSnapshots**
```c
// List cluster snapshots
//
// **Required role:** Cluster administrator.  Lists device snapshots across the whole cluster, for administrators managing storage. Requires a cluster administrator and the cluster snapshot management feature (`clusterSnapshotMgmt`). Results are paginated. For one device's snapshots, use `GET /v3/instances/{instanceId}/snapshots` instead.
//
cluster_snapshot_list_t* ClusterAPI_v3ListClusterSnapshots(apiClient_t *apiClient, double *limit, double *offset, char *springboard, char *live, char *fresh, char *deviceName, char *task, char *search, char to, char from, char *orderBy);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**limit** | **double \*** | Number of entries to return. | [optional] [default to 100]
**offset** | **double \*** | Number of rows to skip. | [optional] [default to 0]
**springboard** | **char \*** | Filter by springboard snapshot flag. | [optional] 
**live** | **char \*** | Filter by live snapshot flag. | [optional] 
**fresh** | **char \*** | Filter by fresh snapshot flag. | [optional] 
**deviceName** | **char \*** | Filter by device name. | [optional] 
**task** | **char \*** | Filter by task being executed on the snapshot. | [optional] 
**search** | **char \*** | Fuzzy search on snapshot and instance name or ID. | [optional] 
**to** | **char** | Filter to this date (based on createdAt). | [optional] 
**from** | **char** | Filter from this date (based on createdAt). | [optional] 
**orderBy** | **char \*** | Sort field and direction. | [optional] [default to &#39;-createdAt&#39;]

### Return type

[cluster_snapshot_list_t](cluster_snapshot_list.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ClusterAPI_v3PatchClusterConfig**
```c
// Update cluster configuration
//
// **Required role:** Cluster administrator.  Changes cluster-wide settings and applies them on every controller node. Send only the settings you want to change. Requires a cluster administrator.
//
void ClusterAPI_v3PatchClusterConfig(apiClient_t *apiClient, patch_cluster_config_body_t *patch_cluster_config_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**patch_cluster_config_body** | **[patch_cluster_config_body_t](patch_cluster_config_body.md) \*** |  | [optional] 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

