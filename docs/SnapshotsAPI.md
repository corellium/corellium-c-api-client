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
// Saves a snapshot of the device's current state, so you can return to it later with `v3RestoreInstanceSnapshot`. Take one before a risky change (an app install, a jailbreak step, an OS change) to be able to undo it.  **Running or off.** A device that is off can always be snapshotted. A running device can only be snapshotted if its model supports live snapshots; otherwise the request fails with 400, so stop the device first (`v3StopInstance`).  The snapshot is saved in the background: the response is the new snapshot with status `creating`. Poll `v3GetInstanceSnapshot` until it is ready. Each device can keep a limited number of snapshots (`snapshotLimit` in `GET /v3/config`); at the limit, delete an old one first.
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
// Delete an instance snapshot. Deletion is asynchronous: the snapshot is marked `deleting` and the call returns 204 before the underlying storage has been reclaimed.  Deletes are idempotent: an unknown `snapshotId`, or an unknown `instanceId`, is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing. A repeat therefore returns 204 both while the snapshot is still present in the `deleting` state and after it has disappeared.
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
// Delete a snapshot by ID. Deletion is asynchronous: the snapshot is marked `deleting` and the call returns 204 before the underlying storage has been reclaimed.  Deletes are idempotent: an unknown `snapshotId`, or a snapshot that was already deleted, is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing. A repeat therefore returns 204 both while the snapshot is still present in the `deleting` state and after it has disappeared.
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
// Returns one snapshot of this device, including its status. Poll it after `v3CreateInstanceSnapshot` until the snapshot has finished `creating`.
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
// Returns one snapshot by its ID, including its status and sharing details. Works for snapshots of your devices; use `v3AcceptSharedSnapshot` for snapshots shared with you.
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
// Lists the snapshots saved for one device, with each snapshot's ID, name and status. A snapshot is a saved copy of the device's storage at a moment in time; restore it with `v3RestoreInstanceSnapshot` to put the device back to that state. Results are paginated with `limit` and `offset`.
//
instance_snapshots_list_t* SnapshotsAPI_v3ListInstanceSnapshots(apiClient_t *apiClient, char *instanceId, double *limit, double *offset);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance identifier. | 
**limit** | **double \*** | Most results to return in one page. Whole number from 1 to 1000; defaults to 100. A value outside that range is rejected with 400. | [optional] [default to 100]
**offset** | **double \*** | How many results to skip before this page starts; defaults to 0. To get the next page, add &#x60;limit&#x60; to the previous &#x60;offset&#x60;. | [optional] [default to 0]

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
// Renames a snapshot. Send the new `name`. Returns the updated snapshot.
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
// Puts the device back to the state saved in a snapshot, replacing its current storage. Anything changed since the snapshot was taken is lost; take a new snapshot first if you want to keep it. The restore runs in the background and starts the device from the snapshot; returns 204 once it has been accepted. Poll `v3GetInstanceState` until the device is `on`.
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
// Renames a snapshot. Send the new `name`. Returns the updated snapshot.
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

