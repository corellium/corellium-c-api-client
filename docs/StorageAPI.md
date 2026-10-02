# StorageAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**StorageAPI_v3AttachClusterStorage**](StorageAPI.md#StorageAPI_v3AttachClusterStorage) | **POST** /v3/cluster/storage/{id}/attach | Attach storage device
[**StorageAPI_v3EjectClusterStorage**](StorageAPI.md#StorageAPI_v3EjectClusterStorage) | **POST** /v3/cluster/storage/{id}/eject | Eject storage device
[**StorageAPI_v3ListClusterStorage**](StorageAPI.md#StorageAPI_v3ListClusterStorage) | **GET** /v3/cluster/storage | List cluster storage devices
[**StorageAPI_v3ListStorage**](StorageAPI.md#StorageAPI_v3ListStorage) | **GET** /v3/storage | List server-attached storage devices
[**StorageAPI_v3ListStorageFiles**](StorageAPI.md#StorageAPI_v3ListStorageFiles) | **GET** /v3/storage/{id}/files/{path} | List storage files


# **StorageAPI_v3AttachClusterStorage**
```c
// Attach storage device
//
// **Required role:** Cluster administrator.  Mounts an attached storage device so its files can be used. Mounting runs in the background: returns 202 when the mount has been queued, or 200 if the device is already mounted. Browse its files with `GET /v3/storage/{id}/files/{path}`. Requires a cluster administrator. Requires the serverAttachedStorage feature. Not available on cloud installations.
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
// **Required role:** Cluster administrator.  Unmounts an attached storage device so it can be unplugged safely. Unmounting runs in the background: returns 202 when the unmount has been queued, or 200 if the device is already unmounted. Requires a cluster administrator. Requires the serverAttachedStorage feature. Not available on cloud installations.
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
// **Required role:** Cluster administrator.  Lists the physical storage devices (for example USB drives) attached to the cluster's servers, for cluster administrators. Requires a cluster administrator. Requires the serverAttachedStorage feature. Not available on cloud installations.
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
// List server-attached storage devices
//
// Lists the physical storage devices (for example USB drives or disks) plugged into an on-site Corellium server, with their name, filesystem, label, vendor, whether they are mounted, and whether they are mounted read-only (`RO`) or read-write (`RW`). Use a device's `id` with `v3ListStorageFiles` to browse its contents. For cluster administrators on on-site deployments; not available on cloud installations. Results are paginated and can be filtered and sorted with the query parameters.
//
storage_list_t* StorageAPI_v3ListStorage(apiClient_t *apiClient, double *limit, double *offset, char *sort, char *identifier, char *device, char *fsType, char *mountPolicy, char *status);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**limit** | **double \*** | Most results to return in one page. Whole number from 1 to 1000; defaults to 100. A value outside that range is rejected with 400. | [optional] [default to 100]
**offset** | **double \*** | How many results to skip before this page starts; defaults to 0. To get the next page, add &#x60;limit&#x60; to the previous &#x60;offset&#x60;. | [optional] [default to 0]
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
// Lists the files and folders at one path on a server-attached storage device (see `v3ListStorage`), with each entry's name, type, size and modification time. Use `/` to list the top level, then pass a folder's path to go deeper. The path must be a folder; a file path returns 400, and paths that try to leave the device (for example with `..`) are rejected. Returns 404 if the device or path does not exist.
//
storage_file_list_t* StorageAPI_v3ListStorageFiles(apiClient_t *apiClient, char *id, char *path, double *limit, double *offset, char *sort, char *name, char *type);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** | Storage device identifier. | 
**path** | **char \*** | Folder to list, relative to the top of the storage device. Slashes are kept as path separators. | 
**limit** | **double \*** | Most results to return in one page. Whole number from 1 to 1000; defaults to 100. A value outside that range is rejected with 400. | [optional] [default to 100]
**offset** | **double \*** | How many results to skip before this page starts; defaults to 0. To get the next page, add &#x60;limit&#x60; to the previous &#x60;offset&#x60;. | [optional] [default to 0]
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

