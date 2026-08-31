# SnapshotsAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**SnapshotsAPI_v3CreateInstanceSnapshot**](SnapshotsAPI.md#SnapshotsAPI_v3CreateInstanceSnapshot) | **POST** /v3/instances/{instanceId}/snapshots | Create instance snapshot
[**SnapshotsAPI_v3DeleteInstanceSnapshot**](SnapshotsAPI.md#SnapshotsAPI_v3DeleteInstanceSnapshot) | **DELETE** /v3/instances/{instanceId}/snapshots/{snapshotId} | Delete an instance snapshot
[**SnapshotsAPI_v3DeleteSnapshot**](SnapshotsAPI.md#SnapshotsAPI_v3DeleteSnapshot) | **DELETE** /v3/snapshots/{snapshotId} | Delete a snapshot
[**SnapshotsAPI_v3GetInstanceSnapshot**](SnapshotsAPI.md#SnapshotsAPI_v3GetInstanceSnapshot) | **GET** /v3/instances/{instanceId}/snapshots/{snapshotId} | Get instance snapshot
[**SnapshotsAPI_v3GetSnapshot**](SnapshotsAPI.md#SnapshotsAPI_v3GetSnapshot) | **GET** /v3/snapshots/{snapshotId} | Get snapshot
[**SnapshotsAPI_v3ListInstanceSnapshots**](SnapshotsAPI.md#SnapshotsAPI_v3ListInstanceSnapshots) | **GET** /v3/instances/{instanceId}/snapshots | List instance snapshots
[**SnapshotsAPI_v3PatchInstanceSnapshot**](SnapshotsAPI.md#SnapshotsAPI_v3PatchInstanceSnapshot) | **PATCH** /v3/instances/{instanceId}/snapshots/{snapshotId} | Update an instance snapshot
[**SnapshotsAPI_v3RestoreInstanceSnapshot**](SnapshotsAPI.md#SnapshotsAPI_v3RestoreInstanceSnapshot) | **POST** /v3/instances/{instanceId}/snapshots/{snapshotId}/restore | Restore instance snapshot
[**SnapshotsAPI_v3UpdateSnapshot**](SnapshotsAPI.md#SnapshotsAPI_v3UpdateSnapshot) | **PATCH** /v3/snapshots/{snapshotId} | Update snapshot name


# **SnapshotsAPI_v3CreateInstanceSnapshot**
```c
// Create instance snapshot
//
snapshot_t* SnapshotsAPI_v3CreateInstanceSnapshot(apiClient_t *apiClient, char *instanceId, create_snapshot_body_t *create_snapshot_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance identifier. | 
**create_snapshot_body** | **[create_snapshot_body_t](create_snapshot_body.md) \*** |  | [optional] 

### Return type

[snapshot_t](snapshot.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SnapshotsAPI_v3DeleteInstanceSnapshot**
```c
// Delete an instance snapshot
//
void SnapshotsAPI_v3DeleteInstanceSnapshot(apiClient_t *apiClient, char *instanceId, char *snapshotId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance identifier. | 
**snapshotId** | **char \*** | Snapshot identifier. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SnapshotsAPI_v3DeleteSnapshot**
```c
// Delete a snapshot
//
// Delete a snapshot by ID.
//
void SnapshotsAPI_v3DeleteSnapshot(apiClient_t *apiClient, char *snapshotId);
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

# **SnapshotsAPI_v3GetInstanceSnapshot**
```c
// Get instance snapshot
//
// Get instance snapshot by ID.
//
snapshot_t* SnapshotsAPI_v3GetInstanceSnapshot(apiClient_t *apiClient, char *instanceId, char *snapshotId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance identifier. | 
**snapshotId** | **char \*** | Snapshot identifier. | 

### Return type

[snapshot_t](snapshot.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SnapshotsAPI_v3GetSnapshot**
```c
// Get snapshot
//
// Get snapshot by ID.
//
snapshot_t* SnapshotsAPI_v3GetSnapshot(apiClient_t *apiClient, char *snapshotId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**snapshotId** | **char \*** | Snapshot identifier. | 

### Return type

[snapshot_t](snapshot.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SnapshotsAPI_v3ListInstanceSnapshots**
```c
// List instance snapshots
//
instance_snapshots_list_t* SnapshotsAPI_v3ListInstanceSnapshots(apiClient_t *apiClient, char *instanceId, double *limit, double *offset);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance identifier. | 
**limit** | **double \*** | Maximum number of results to return. | [optional] [default to 100]
**offset** | **double \*** | Number of results to skip. | [optional] [default to 0]

### Return type

[instance_snapshots_list_t](instance_snapshots_list.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SnapshotsAPI_v3PatchInstanceSnapshot**
```c
// Update an instance snapshot
//
snapshot_t* SnapshotsAPI_v3PatchInstanceSnapshot(apiClient_t *apiClient, char *instanceId, char *snapshotId, create_snapshot_body_t *create_snapshot_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance identifier. | 
**snapshotId** | **char \*** | Snapshot identifier. | 
**create_snapshot_body** | **[create_snapshot_body_t](create_snapshot_body.md) \*** |  | 

### Return type

[snapshot_t](snapshot.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SnapshotsAPI_v3RestoreInstanceSnapshot**
```c
// Restore instance snapshot
//
// Restore the specified instance to the given snapshot.
//
void SnapshotsAPI_v3RestoreInstanceSnapshot(apiClient_t *apiClient, char *instanceId, char *snapshotId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance identifier. | 
**snapshotId** | **char \*** | Snapshot identifier. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SnapshotsAPI_v3UpdateSnapshot**
```c
// Update snapshot name
//
snapshot_t* SnapshotsAPI_v3UpdateSnapshot(apiClient_t *apiClient, char *snapshotId, v3_update_snapshot_request_t *v3_update_snapshot_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**snapshotId** | **char \*** | Snapshot identifier. | 
**v3_update_snapshot_request** | **[v3_update_snapshot_request_t](v3_update_snapshot_request.md) \*** |  | 

### Return type

[snapshot_t](snapshot.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

