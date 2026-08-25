# SnapshotSharingAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**SnapshotSharingAPI_v3AcceptSharedSnapshot**](SnapshotSharingAPI.md#SnapshotSharingAPI_v3AcceptSharedSnapshot) | **POST** /v3/snapshots/accept | Accept a shared snapshot
[**SnapshotSharingAPI_v3DeleteSnapshotPermissions**](SnapshotSharingAPI.md#SnapshotSharingAPI_v3DeleteSnapshotPermissions) | **DELETE** /v3/snapshots/{snapshotId}/permissions | Delete member(s)
[**SnapshotSharingAPI_v3GetSharedSnapshots**](SnapshotSharingAPI.md#SnapshotSharingAPI_v3GetSharedSnapshots) | **GET** /v3/snapshots/shared | Fetch shared snapshots
[**SnapshotSharingAPI_v3SetSnapshotPermissions**](SnapshotSharingAPI.md#SnapshotSharingAPI_v3SetSnapshotPermissions) | **POST** /v3/snapshots/{snapshotId}/permissions | Set member list
[**SnapshotSharingAPI_v3ShareSnapshot**](SnapshotSharingAPI.md#SnapshotSharingAPI_v3ShareSnapshot) | **POST** /v3/snapshots/{snapshotId}/share | Share a snapshot


# **SnapshotSharingAPI_v3AcceptSharedSnapshot**
```c
// Accept a shared snapshot
//
snapshot_t* SnapshotSharingAPI_v3AcceptSharedSnapshot(apiClient_t *apiClient, accept_snapshot_body_t *accept_snapshot_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**accept_snapshot_body** | **[accept_snapshot_body_t](accept_snapshot_body.md) \*** |  | 

### Return type

[snapshot_t](snapshot.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SnapshotSharingAPI_v3DeleteSnapshotPermissions**
```c
// Delete member(s)
//
// Deletes one or more members from the list of members who have access to the snapshot.
//
snapshot_t* SnapshotSharingAPI_v3DeleteSnapshotPermissions(apiClient_t *apiClient, char *snapshotId, set_snapshot_permissions_body_t *set_snapshot_permissions_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**snapshotId** | **char \*** | Snapshot identifier. | 
**set_snapshot_permissions_body** | **[set_snapshot_permissions_body_t](set_snapshot_permissions_body.md) \*** |  | 

### Return type

[snapshot_t](snapshot.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SnapshotSharingAPI_v3GetSharedSnapshots**
```c
// Fetch shared snapshots
//
// Fetch snapshots shared with and shared by the requesting user.
//
shared_snapshots_response_t* SnapshotSharingAPI_v3GetSharedSnapshots(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[shared_snapshots_response_t](shared_snapshots_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SnapshotSharingAPI_v3SetSnapshotPermissions**
```c
// Set member list
//
// Sets the list of members who have access to the snapshot.
//
snapshot_t* SnapshotSharingAPI_v3SetSnapshotPermissions(apiClient_t *apiClient, char *snapshotId, set_snapshot_permissions_body_t *set_snapshot_permissions_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**snapshotId** | **char \*** | Snapshot identifier. | 
**set_snapshot_permissions_body** | **[set_snapshot_permissions_body_t](set_snapshot_permissions_body.md) \*** |  | 

### Return type

[snapshot_t](snapshot.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SnapshotSharingAPI_v3ShareSnapshot**
```c
// Share a snapshot
//
snapshot_t* SnapshotSharingAPI_v3ShareSnapshot(apiClient_t *apiClient, char *snapshotId, share_snapshot_body_t *share_snapshot_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**snapshotId** | **char \*** | Snapshot identifier. | 
**share_snapshot_body** | **[share_snapshot_body_t](share_snapshot_body.md) \*** |  | 

### Return type

[snapshot_t](snapshot.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

