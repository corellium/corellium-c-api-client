# StorageAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**StorageAPI_v3AttachClusterStorage**](StorageAPI.md#StorageAPI_v3AttachClusterStorage) | **POST** /v3/cluster/storage/{id}/attach | Attach storage device
[**StorageAPI_v3EjectClusterStorage**](StorageAPI.md#StorageAPI_v3EjectClusterStorage) | **POST** /v3/cluster/storage/{id}/eject | Eject storage device
[**StorageAPI_v3ListClusterStorage**](StorageAPI.md#StorageAPI_v3ListClusterStorage) | **GET** /v3/cluster/storage | List cluster storage devices
[**StorageAPI_v3ListStorage**](StorageAPI.md#StorageAPI_v3ListStorage) | **GET** /v3/storage | List storage devices
[**StorageAPI_v3ListStorageFiles**](StorageAPI.md#StorageAPI_v3ListStorageFiles) | **GET** /v3/storage/{id}/files/{path} | List storage files


# **StorageAPI_v3AttachClusterStorage**
```c
// Attach storage device
//
// Mounts a registered storage device. Returns 200 if already mounted, 202 if a mount job was queued. Requires cluster administrator permissions.
//
storage_already_mounted_response_t* StorageAPI_v3AttachClusterStorage(apiClient_t *apiClient, char *id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** | Storage device identifier. | 

### Return type

[storage_already_mounted_response_t](storage_already_mounted_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **StorageAPI_v3EjectClusterStorage**
```c
// Eject storage device
//
// Unmounts a registered storage device. Returns 200 if already unmounted, 202 if an unmount job was queued. Requires cluster administrator permissions.
//
storage_eject_already_unmounted_response_t* StorageAPI_v3EjectClusterStorage(apiClient_t *apiClient, char *id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** | Storage device identifier. | 

### Return type

[storage_eject_already_unmounted_response_t](storage_eject_already_unmounted_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **StorageAPI_v3ListClusterStorage**
```c
// List cluster storage devices
//
// Returns all attached storage devices. Requires cluster administrator permissions.
//
storage_device_list_t* StorageAPI_v3ListClusterStorage(apiClient_t *apiClient, double *limit, double *offset, char *id, char *device, char *fsType, char *fsUuid, char *label, char *serial, char *vendor, char *model, char *mountPolicy, char *status, char *sort);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**limit** | **double \*** | Maximum results to return. | [optional] [default to 100]
**offset** | **double \*** | Results to skip. | [optional] [default to 0]
**id** | **char \*** | Filter by identifier (comma-separated for multiple). | [optional] 
**device** | **char \*** | Filter by device name (partial match). | [optional] 
**fsType** | **char \*** | Filter by filesystem type (comma-separated). | [optional] 
**fsUuid** | **char \*** | Filter by filesystem UUID (partial match). | [optional] 
**label** | **char \*** | Filter by label (partial match). | [optional] 
**serial** | **char \*** | Filter by serial number (partial match). | [optional] 
**vendor** | **char \*** | Filter by vendor (partial match). | [optional] 
**model** | **char \*** | Filter by model (partial match). | [optional] 
**mountPolicy** | **char \*** | Filter by mount policy. | [optional] 
**status** | **char \*** | Filter by mount status. | [optional] 
**sort** | **char \*** | Sort order (e.g. &#39;device&#39; or &#39;-device&#39;). | [optional] 

### Return type

[storage_device_list_t](storage_device_list.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **StorageAPI_v3ListStorage**
```c
// List storage devices
//
// List all attached storage devices visible to the authenticated user.
//
storage_list_t* StorageAPI_v3ListStorage(apiClient_t *apiClient, double *limit, double *offset, char *sort, char *identifier, char *device, char *fsType, char *mountPolicy, char *status);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**limit** | **double \*** | Maximum number of results to return. | [optional] [default to 100]
**offset** | **double \*** | Number of results to skip. | [optional] [default to 0]
**sort** | **char \*** | Sort order (prefix a field with \&quot;-\&quot; for descending). | [optional] 
**identifier** | **char \*** | Filter by identifier (comma separated). | [optional] 
**device** | **char \*** | Filter by device name (partial match). | [optional] 
**fsType** | **char \*** | Filter by filesystem type (comma separated). | [optional] 
**mountPolicy** | **char \*** | Filter by mount policy. | [optional] 
**status** | **char \*** | Filter by mount status. | [optional] 

### Return type

[storage_list_t](storage_list.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **StorageAPI_v3ListStorageFiles**
```c
// List storage files
//
// List files at a path within an attached storage device. The device is resolved by identifier and the filesystem contents are listed at the given path within the mount point.
//
storage_file_list_t* StorageAPI_v3ListStorageFiles(apiClient_t *apiClient, char *id, char *path, double *limit, double *offset, char *sort, char *name, char *type);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** | Storage device identifier. | 
**path** | **char \*** | Path within the storage device to list. | 
**limit** | **double \*** | Maximum number of results to return. | [optional] [default to 100]
**offset** | **double \*** | Number of results to skip. | [optional] [default to 0]
**sort** | **char \*** | Sort order (prefix a field with \&quot;-\&quot; for descending). | [optional] 
**name** | **char \*** | Filter by name (case-insensitive exact match, comma separated). | [optional] 
**type** | **char \*** | Filter by type (case-insensitive partial match, e.g. \&quot;file\&quot; or \&quot;dir\&quot;). | [optional] 

### Return type

[storage_file_list_t](storage_file_list.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

