# StorageV1API

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**StorageV1API_v1AttachStorageCluster**](StorageV1API.md#StorageV1API_v1AttachStorageCluster) | **POST** /v1/cluster/storage/{id}/attach | Mount and attach a storage device
[**StorageV1API_v1EjectStorageCluster**](StorageV1API.md#StorageV1API_v1EjectStorageCluster) | **POST** /v1/cluster/storage/{id}/eject | Eject/Unmount removable media
[**StorageV1API_v1ListStorage**](StorageV1API.md#StorageV1API_v1ListStorage) | **GET** /v1/storage | Get storage devices
[**StorageV1API_v1ListStorageCluster**](StorageV1API.md#StorageV1API_v1ListStorageCluster) | **GET** /v1/cluster/storage | Get storage devices
[**StorageV1API_v1ListStorageFiles**](StorageV1API.md#StorageV1API_v1ListStorageFiles) | **GET** /v1/storage/{id}/files/{path} | List Storage Files


# **StorageV1API_v1AttachStorageCluster**
```c
// Mount and attach a storage device
//
// Initiates an asynchronous mount job for a registered storage device. If already mounted, returns status 200. If not, queues a background job and returns 202.
//
object_t* StorageV1API_v1AttachStorageCluster(apiClient_t *apiClient, char *id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** | The unique identifier of the storage media | 

### Return type

[object_t](object.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **StorageV1API_v1EjectStorageCluster**
```c
// Eject/Unmount removable media
//
// Initiates an asynchronous unmount job for the physical storage device. If the device is already unmounted, returns success. If mounted, creates a background job to safely unmount.
//
object_t* StorageV1API_v1EjectStorageCluster(apiClient_t *apiClient, char *id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** | Storage device identifier (UUID) | 

### Return type

[object_t](object.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **StorageV1API_v1ListStorage**
```c
// Get storage devices
//
// List all attached storage devices. This endpoint is only available to all authenticated users.
//
get_storage_response_t* StorageV1API_v1ListStorage(apiClient_t *apiClient, double limit, double offset, char *identifier, char *device, char *fsType, char *mountPolicy, char *status, char *sort);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**limit** | **double** | Maximum number of results to return (1–1000, default: 100) | [optional] 
**offset** | **double** | Number of results to skip (default: 0) | [optional] 
**identifier** | **char \*** | Filter by identifier (comma separated) | [optional] 
**device** | **char \*** | Filter by device name (partial match) | [optional] 
**fsType** | **char \*** | Filter by filesystem type (comma separated) | [optional] 
**mountPolicy** | **char \*** | Filter by mount policy (RO or RW) | [optional] 
**status** | **char \*** | Filter by status (unmounted or mounted) | [optional] 
**sort** | **char \*** | Sort order (e.g. \&quot;device\&quot; or \&quot;-device\&quot;) | [optional] 

### Return type

[get_storage_response_t](get_storage_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **StorageV1API_v1ListStorageCluster**
```c
// Get storage devices
//
// List all attached storage devices. This endpoint is only available to cluster administrators.
//
get_storage_response_t* StorageV1API_v1ListStorageCluster(apiClient_t *apiClient, double limit, double offset, char *device, char *fsType, char *fsUUID, char *label, char *serial, char *vendor, char *model, char *mountPolicy, char *status, char *sort);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**limit** | **double** | Maximum number of results to return (1–1000, default: 100) | [optional] 
**offset** | **double** | Number of results to skip (default: 0) | [optional] 
**device** | **char \*** | Filter by device name (partial match) | [optional] 
**fsType** | **char \*** | Filter by filesystem type (comma separated) | [optional] 
**fsUUID** | **char \*** | Filter by filesystem UUID (partial match) | [optional] 
**label** | **char \*** | Filter by label (partial match) | [optional] 
**serial** | **char \*** | Filter by serial number (partial match) | [optional] 
**vendor** | **char \*** | Filter by vendor (partial match) | [optional] 
**model** | **char \*** | Filter by model (partial match) | [optional] 
**mountPolicy** | **char \*** | Filter by mount policy (RO or RW) | [optional] 
**status** | **char \*** | Filter by status (unmounted or mounted) | [optional] 
**sort** | **char \*** | Sort order (e.g. \&quot;device\&quot; or \&quot;-device\&quot;) | [optional] 

### Return type

[get_storage_response_t](get_storage_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **StorageV1API_v1ListStorageFiles**
```c
// List Storage Files
//
// List files from attached storage devices. Looks up the storage device by identifier,   then lists filesystem contents at the given path within the device's mount point.   This endpoint is available to all authenticated users.
//
object_t* StorageV1API_v1ListStorageFiles(apiClient_t *apiClient, char *id, char *path, double limit, double offset, char *name, char *type, char *sort);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** | Storage device identifier (MediaStore identifier) | 
**path** | **char \*** | Path within the storage device to list | 
**limit** | **double** | Maximum number of results to return (1–1000, default: 100) | [optional] 
**offset** | **double** | Number of results to skip (default: 0) | [optional] 
**name** | **char \*** | Filter by name (case insensitive exact match, comma separated for multiple values) | [optional] 
**type** | **char \*** | Filter by type (case insensitive partial match, e.g. \&quot;file\&quot; or \&quot;dir\&quot;) | [optional] 
**sort** | **char \*** | Sort order (e.g., &#39;name&#39;, &#39;-name&#39;, &#39;type,-size,-lastModifiedTime&#39;). Prefix with &#39;-&#39; for descending. | [optional] 

### Return type

[object_t](object.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

