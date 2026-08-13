# ClusterSnapshotsAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ClusterSnapshotsAPI_v1DeleteClusterSnapshot**](ClusterSnapshotsAPI.md#ClusterSnapshotsAPI_v1DeleteClusterSnapshot) | **DELETE** /v1/cluster/snapshots/{snapshotId} | Delete a Cluster Snapshot
[**ClusterSnapshotsAPI_v1GetClusterSnapshot**](ClusterSnapshotsAPI.md#ClusterSnapshotsAPI_v1GetClusterSnapshot) | **GET** /v1/cluster/snapshots/{snapshotId} | Get Cluster Snapshot
[**ClusterSnapshotsAPI_v1GetClusterSnapshots**](ClusterSnapshotsAPI.md#ClusterSnapshotsAPI_v1GetClusterSnapshots) | **GET** /v1/cluster/snapshots | Get Cluster Snapshots


# **ClusterSnapshotsAPI_v1DeleteClusterSnapshot**
```c
// Delete a Cluster Snapshot
//
void ClusterSnapshotsAPI_v1DeleteClusterSnapshot(apiClient_t *apiClient, char *snapshotId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**snapshotId** | **char \*** | Snapshot ID - uuid | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ClusterSnapshotsAPI_v1GetClusterSnapshot**
```c
// Get Cluster Snapshot
//
cluster_snapshot_v1_t* ClusterSnapshotsAPI_v1GetClusterSnapshot(apiClient_t *apiClient, char *snapshotId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**snapshotId** | **char \*** | Snapshot ID - uuid | 

### Return type

[cluster_snapshot_v1_t](cluster_snapshot_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ClusterSnapshotsAPI_v1GetClusterSnapshots**
```c
// Get Cluster Snapshots
//
snapshot_list_t* ClusterSnapshotsAPI_v1GetClusterSnapshots(apiClient_t *apiClient, snapshot_request_t *request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**request** | **[snapshot_request_t](.md) \*** |  | [optional] 

### Return type

[snapshot_list_t](snapshot_list.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

