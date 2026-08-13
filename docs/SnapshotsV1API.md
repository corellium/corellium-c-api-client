# SnapshotsV1API

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**SnapshotsV1API_v1CreateSnapshot**](SnapshotsV1API.md#SnapshotsV1API_v1CreateSnapshot) | **POST** /v1/instances/{instanceId}/snapshots | Create Instance Snapshot
[**SnapshotsV1API_v1DeleteInstanceSnapshot**](SnapshotsV1API.md#SnapshotsV1API_v1DeleteInstanceSnapshot) | **DELETE** /v1/instances/{instanceId}/snapshots/{snapshotId} | Delete an Instance Snapshot
[**SnapshotsV1API_v1DeleteSnapshot**](SnapshotsV1API.md#SnapshotsV1API_v1DeleteSnapshot) | **DELETE** /v1/snapshots/{snapshotId} | Delete a Snapshot
[**SnapshotsV1API_v1GetInstanceSnapshot**](SnapshotsV1API.md#SnapshotsV1API_v1GetInstanceSnapshot) | **GET** /v1/instances/{instanceId}/snapshots/{snapshotId} | Get Instance Snapshot
[**SnapshotsV1API_v1GetInstanceSnapshots**](SnapshotsV1API.md#SnapshotsV1API_v1GetInstanceSnapshots) | **GET** /v1/instances/{instanceId}/snapshots | Get Instance Snapshots
[**SnapshotsV1API_v1GetSnapshot**](SnapshotsV1API.md#SnapshotsV1API_v1GetSnapshot) | **GET** /v1/snapshots/{snapshotId} | Get Snapshot
[**SnapshotsV1API_v1RenameInstanceSnapshot**](SnapshotsV1API.md#SnapshotsV1API_v1RenameInstanceSnapshot) | **PATCH** /v1/instances/{instanceId}/snapshots/{snapshotId} | Rename an Instance Snapshot
[**SnapshotsV1API_v1RestoreInstanceSnapshot**](SnapshotsV1API.md#SnapshotsV1API_v1RestoreInstanceSnapshot) | **POST** /v1/instances/{instanceId}/snapshots/{snapshotId}/restore | Restore an Instance Snapshot
[**SnapshotsV1API_v1SnapshotRename**](SnapshotsV1API.md#SnapshotsV1API_v1SnapshotRename) | **PATCH** /v1/snapshots/{snapshotId} | Rename a Snapshot


# **SnapshotsV1API_v1CreateSnapshot**
```c
// Create Instance Snapshot
//
snapshot_v1_t* SnapshotsV1API_v1CreateSnapshot(apiClient_t *apiClient, char *instanceId, snapshot_creation_options_t *snapshot_creation_options);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 
**snapshot_creation_options** | **[snapshot_creation_options_t](snapshot_creation_options.md) \*** |  | 

### Return type

[snapshot_v1_t](snapshot_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SnapshotsV1API_v1DeleteInstanceSnapshot**
```c
// Delete an Instance Snapshot
//
void SnapshotsV1API_v1DeleteInstanceSnapshot(apiClient_t *apiClient, char *instanceId, char *snapshotId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 
**snapshotId** | **char \*** | Snapshot ID - uuid | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SnapshotsV1API_v1DeleteSnapshot**
```c
// Delete a Snapshot
//
void SnapshotsV1API_v1DeleteSnapshot(apiClient_t *apiClient, char *snapshotId);
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

# **SnapshotsV1API_v1GetInstanceSnapshot**
```c
// Get Instance Snapshot
//
snapshot_v1_t* SnapshotsV1API_v1GetInstanceSnapshot(apiClient_t *apiClient, char *instanceId, char *snapshotId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 
**snapshotId** | **char \*** | Snapshot ID - uuid | 

### Return type

[snapshot_v1_t](snapshot_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SnapshotsV1API_v1GetInstanceSnapshots**
```c
// Get Instance Snapshots
//
list_t* SnapshotsV1API_v1GetInstanceSnapshots(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 

### Return type

[list_t](snapshot_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SnapshotsV1API_v1GetSnapshot**
```c
// Get Snapshot
//
snapshot_v1_t* SnapshotsV1API_v1GetSnapshot(apiClient_t *apiClient, char *snapshotId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**snapshotId** | **char \*** | Snapshot ID - uuid | 

### Return type

[snapshot_v1_t](snapshot_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SnapshotsV1API_v1RenameInstanceSnapshot**
```c
// Rename an Instance Snapshot
//
snapshot_v1_t* SnapshotsV1API_v1RenameInstanceSnapshot(apiClient_t *apiClient, char *instanceId, char *snapshotId, snapshot_creation_options_t *snapshot_creation_options);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 
**snapshotId** | **char \*** | Snapshot ID - uuid | 
**snapshot_creation_options** | **[snapshot_creation_options_t](snapshot_creation_options.md) \*** |  | 

### Return type

[snapshot_v1_t](snapshot_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SnapshotsV1API_v1RestoreInstanceSnapshot**
```c
// Restore an Instance Snapshot
//
void SnapshotsV1API_v1RestoreInstanceSnapshot(apiClient_t *apiClient, char *instanceId, char *snapshotId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 
**snapshotId** | **char \*** | Snapshot ID - uuid | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SnapshotsV1API_v1SnapshotRename**
```c
// Rename a Snapshot
//
snapshot_v1_t* SnapshotsV1API_v1SnapshotRename(apiClient_t *apiClient, char *snapshotId, snapshot_creation_options_t *snapshot_creation_options);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**snapshotId** | **char \*** | Snapshot ID - uuid | 
**snapshot_creation_options** | **[snapshot_creation_options_t](snapshot_creation_options.md) \*** |  | 

### Return type

[snapshot_v1_t](snapshot_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

