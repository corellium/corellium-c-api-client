# SnapshotSharingV1API

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**SnapshotSharingV1API_v1AcceptSharedSnapshot**](SnapshotSharingV1API.md#SnapshotSharingV1API_v1AcceptSharedSnapshot) | **POST** /v1/snapshots/accept | Accept a snapshot shared with you
[**SnapshotSharingV1API_v1DeleteSnapshotPermissions**](SnapshotSharingV1API.md#SnapshotSharingV1API_v1DeleteSnapshotPermissions) | **DELETE** /v1/snapshots/{snapshotId}/permissions | Delete member(s)
[**SnapshotSharingV1API_v1GetSharedSnapshots**](SnapshotSharingV1API.md#SnapshotSharingV1API_v1GetSharedSnapshots) | **GET** /v1/snapshots/shared | Fetch shared snapshots
[**SnapshotSharingV1API_v1SetSnapshotPermissions**](SnapshotSharingV1API.md#SnapshotSharingV1API_v1SetSnapshotPermissions) | **POST** /v1/snapshots/{snapshotId}/permissions | Set member list
[**SnapshotSharingV1API_v1ShareSnapshot**](SnapshotSharingV1API.md#SnapshotSharingV1API_v1ShareSnapshot) | **POST** /v1/snapshots/{snapshotId}/share | Share snapshot


# **SnapshotSharingV1API_v1AcceptSharedSnapshot**
```c
// Accept a snapshot shared with you
//
snapshot_v1_t* SnapshotSharingV1API_v1AcceptSharedSnapshot(apiClient_t *apiClient, accept_snapshot_request_payload_t *accept_snapshot_request_payload);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**accept_snapshot_request_payload** | **[accept_snapshot_request_payload_t](accept_snapshot_request_payload.md) \*** |  | 

### Return type

[snapshot_v1_t](snapshot_v1.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SnapshotSharingV1API_v1DeleteSnapshotPermissions**
```c
// Delete member(s)
//
// Deletes one or more members from the list of members who have access to the snapshot
//
snapshot_v1_t* SnapshotSharingV1API_v1DeleteSnapshotPermissions(apiClient_t *apiClient, char *snapshotId, snapshot_permissions_request_payload_t *snapshot_permissions_request_payload);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**snapshotId** | **char \*** | Snapshot ID - uuid | 
**snapshot_permissions_request_payload** | **[snapshot_permissions_request_payload_t](snapshot_permissions_request_payload.md) \*** |  | 

### Return type

[snapshot_v1_t](snapshot_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SnapshotSharingV1API_v1GetSharedSnapshots**
```c
// Fetch shared snapshots
//
// Fetch snapshots shared with and shared by the requesting user
//
user_snapshots_t* SnapshotSharingV1API_v1GetSharedSnapshots(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[user_snapshots_t](user_snapshots.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SnapshotSharingV1API_v1SetSnapshotPermissions**
```c
// Set member list
//
// Sets the list of members who have access to the snapshot
//
snapshot_v1_t* SnapshotSharingV1API_v1SetSnapshotPermissions(apiClient_t *apiClient, char *snapshotId, snapshot_permissions_request_payload_t *snapshot_permissions_request_payload);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**snapshotId** | **char \*** | Snapshot ID - uuid | 
**snapshot_permissions_request_payload** | **[snapshot_permissions_request_payload_t](snapshot_permissions_request_payload.md) \*** |  | 

### Return type

[snapshot_v1_t](snapshot_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SnapshotSharingV1API_v1ShareSnapshot**
```c
// Share snapshot
//
// Share a snapshot
//
snapshot_v1_t* SnapshotSharingV1API_v1ShareSnapshot(apiClient_t *apiClient, char *snapshotId, post_share_snapshot_request_payload_t *post_share_snapshot_request_payload);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**snapshotId** | **char \*** | Snapshot ID - uuid | 
**post_share_snapshot_request_payload** | **[post_share_snapshot_request_payload_t](post_share_snapshot_request_payload.md) \*** |  | 

### Return type

[snapshot_v1_t](snapshot_v1.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

