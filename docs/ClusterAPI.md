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
// Deletes a cluster snapshot by ID. Requires cluster administrator permissions and the clusterSnapshotMgmt feature.
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
// Returns the current cluster configuration. Requires cluster administrator permissions.
//
object_t* ClusterAPI_v3GetClusterConfig(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[object_t](object.md) *


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
// Returns details for a specific node by ID. Requires cluster administrator permissions.
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
// Returns the WebSocket URL for accessing the node console via SSH. Connect to the returned URL to open the console stream. Requires cluster administrator permissions.
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
// Returns details for a specific cluster snapshot. Requires cluster administrator permissions and the clusterSnapshotMgmt feature.
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
// Returns information about all nodes in the cluster. Requires cluster administrator permissions.
//
node_list_t* ClusterAPI_v3ListClusterNodes(apiClient_t *apiClient, double *limit, double *offset);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**limit** | **double \*** | Maximum number of results to return. | [optional] [default to 100]
**offset** | **double \*** | Number of results to skip. | [optional] [default to 0]

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
// Returns a paginated list of cluster volume snapshots. Requires cluster administrator permissions and the clusterSnapshotMgmt feature.
//
cluster_snapshot_list_t* ClusterAPI_v3ListClusterSnapshots(apiClient_t *apiClient, double *limit, double *offset, char *springboard, char *live, char *fresh, char *deviceName, char *task, char *search, char *to, char *from, char *orderBy);
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
**to** | **char \*** | Filter to this date (based on createdAt). | [optional] 
**from** | **char \*** | Filter from this date (based on createdAt). | [optional] 
**orderBy** | **char \*** | Sort order, e.g. &#39;-createdAt&#39; or &#39;createdAt&#39;. | [optional] [default to &#39;-createdAt&#39;]

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
// Applies configuration changes across all controller nodes. Requires cluster administrator permissions.
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

