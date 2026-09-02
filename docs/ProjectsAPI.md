# ProjectsAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ProjectsAPI_v3CreateProject**](ProjectsAPI.md#ProjectsAPI_v3CreateProject) | **POST** /v3/projects | Create a project
[**ProjectsAPI_v3CreateProjectKey**](ProjectsAPI.md#ProjectsAPI_v3CreateProjectKey) | **POST** /v3/projects/{projectId}/keys | Add a project key
[**ProjectsAPI_v3DeleteProject**](ProjectsAPI.md#ProjectsAPI_v3DeleteProject) | **DELETE** /v3/projects/{projectId} | Delete a project
[**ProjectsAPI_v3DeleteProjectKey**](ProjectsAPI.md#ProjectsAPI_v3DeleteProjectKey) | **DELETE** /v3/projects/{projectId}/keys/{keyId} | Delete a project key
[**ProjectsAPI_v3FetchProjectFirmwareAssets**](ProjectsAPI.md#ProjectsAPI_v3FetchProjectFirmwareAssets) | **POST** /v3/projects/{projectId}/firmware-assets | Fetch firmware assets for a project
[**ProjectsAPI_v3GetProject**](ProjectsAPI.md#ProjectsAPI_v3GetProject) | **GET** /v3/projects/{projectId} | Get a project
[**ProjectsAPI_v3GetProjectImageUpload**](ProjectsAPI.md#ProjectsAPI_v3GetProjectImageUpload) | **GET** /v3/projects/{projectId}/image-upload/{type}/{imageId}/{name} | Get image upload status
[**ProjectsAPI_v3GetProjectNetworkLog**](ProjectsAPI.md#ProjectsAPI_v3GetProjectNetworkLog) | **GET** /v3/projects/{projectId}/network/log | Get project network log
[**ProjectsAPI_v3GetProjectNetworkStatus**](ProjectsAPI.md#ProjectsAPI_v3GetProjectNetworkStatus) | **GET** /v3/projects/{projectId}/network/status | Get project network status
[**ProjectsAPI_v3GetProjectVpnConfig**](ProjectsAPI.md#ProjectsAPI_v3GetProjectVpnConfig) | **GET** /v3/projects/{projectId}/vpnconfig/{format} | Get project VPN configuration
[**ProjectsAPI_v3ListProjectInstances**](ProjectsAPI.md#ProjectsAPI_v3ListProjectInstances) | **GET** /v3/projects/{projectId}/instances | List project instances
[**ProjectsAPI_v3ListProjectKeys**](ProjectsAPI.md#ProjectsAPI_v3ListProjectKeys) | **GET** /v3/projects/{projectId}/keys | List project keys
[**ProjectsAPI_v3ListProjects**](ProjectsAPI.md#ProjectsAPI_v3ListProjects) | **GET** /v3/projects | List projects
[**ProjectsAPI_v3PatchProject**](ProjectsAPI.md#ProjectsAPI_v3PatchProject) | **PATCH** /v3/projects/{projectId} | Update a project
[**ProjectsAPI_v3PutProjectImageUpload**](ProjectsAPI.md#ProjectsAPI_v3PutProjectImageUpload) | **PUT** /v3/projects/{projectId}/image-upload/{type}/{imageId}/{name} | Upload image chunk


# **ProjectsAPI_v3CreateProject**
```c
// Create a project
//
// **Required role:** Domain administrator.  Create a new project in the authenticated user's domain.
//
project_t* ProjectsAPI_v3CreateProject(apiClient_t *apiClient, create_project_body_t *create_project_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**create_project_body** | **[create_project_body_t](create_project_body.md) \*** | Project to create. | 

### Return type

[project_t](project.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProjectsAPI_v3CreateProjectKey**
```c
// Add a project key
//
// **Required role:** Domain administrator or project administrator.  Add an authorized key to a project.
//
project_key_t* ProjectsAPI_v3CreateProjectKey(apiClient_t *apiClient, char *projectId, create_project_key_body_t *create_project_key_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | Project identifier. | 
**create_project_key_body** | **[create_project_key_body_t](create_project_key_body.md) \*** | Key to add. | 

### Return type

[project_key_t](project_key.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProjectsAPI_v3DeleteProject**
```c
// Delete a project
//
// **Required role:** Domain administrator.  Delete a project. The project must contain no devices.
//
void ProjectsAPI_v3DeleteProject(apiClient_t *apiClient, char *projectId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | Project identifier. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProjectsAPI_v3DeleteProjectKey**
```c
// Delete a project key
//
// **Required role:** Domain administrator or project administrator.  Remove an authorized key from a project.
//
void ProjectsAPI_v3DeleteProjectKey(apiClient_t *apiClient, char *projectId, char *keyId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | Project identifier. | 
**keyId** | **char \*** | Project key identifier. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProjectsAPI_v3FetchProjectFirmwareAssets**
```c
// Fetch firmware assets for a project
//
// Relays a set of firmware asset URLs to the firmware service, which downloads the assets server-side and stores them for the project's domain.
//
fetch_firmware_assets_response_t* ProjectsAPI_v3FetchProjectFirmwareAssets(apiClient_t *apiClient, char *projectId, fetch_firmware_assets_body_t *fetch_firmware_assets_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | Project identifier. | 
**fetch_firmware_assets_body** | **[fetch_firmware_assets_body_t](fetch_firmware_assets_body.md) \*** | Firmware asset URLs to fetch. | 

### Return type

[fetch_firmware_assets_response_t](fetch_firmware_assets_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProjectsAPI_v3GetProject**
```c
// Get a project
//
// Retrieve a single project by identifier.
//
project_t* ProjectsAPI_v3GetProject(apiClient_t *apiClient, char *projectId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | Project identifier. | 

### Return type

[project_t](project.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProjectsAPI_v3GetProjectImageUpload**
```c
// Get image upload status
//
// Check resumable upload status for a project image or download the image file.
//
binary_t** ProjectsAPI_v3GetProjectImageUpload(apiClient_t *apiClient, char *projectId, char *type, char *imageId, char *name, double *resumableChunkNumber);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | Project identifier. | 
**type** | **char \*** | Image type. | 
**imageId** | **char \*** | Client-generated image identifier. The image record is created on the first chunk. | 
**name** | **char \*** | URL-encoded image filename. | 
**resumableChunkNumber** | **double \*** | Chunk number. When present the response reports whether that chunk was already stored (200) or still needs to be uploaded (204) instead of returning the image file. | [optional] 

### Return type

binary_t**



### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/octet-stream, application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProjectsAPI_v3GetProjectNetworkLog**
```c
// Get project network log
//
// Retrieve the egress network connection log for a project as plain text.
//
char* ProjectsAPI_v3GetProjectNetworkLog(apiClient_t *apiClient, char *projectId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | Project identifier. | 

### Return type

char*



### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: text/plain, application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProjectsAPI_v3GetProjectNetworkStatus**
```c
// Get project network status
//
// Retrieve the egress network connection status for a project.
//
network_status_t* ProjectsAPI_v3GetProjectNetworkStatus(apiClient_t *apiClient, char *projectId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | Project identifier. | 

### Return type

[network_status_t](network_status.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProjectsAPI_v3GetProjectVpnConfig**
```c
// Get project VPN configuration
//
// Retrieve the project VPN configuration. A project VPN allows a client (e.g. a researcher's computer) to connect into the virtual devices within the project.
//
char* ProjectsAPI_v3GetProjectVpnConfig(apiClient_t *apiClient, char *projectId, char *format);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | Project identifier. | 
**format** | **char \*** | VPN configuration format: &#39;ovpn&#39; for an OpenVPN profile; any other value returns a Tunnelblick zip. | 

### Return type

char*



### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: text/plain, application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProjectsAPI_v3ListProjectInstances**
```c
// List project instances
//
// List the instances belonging to a project.
//
project_instance_list_t* ProjectsAPI_v3ListProjectInstances(apiClient_t *apiClient, char *projectId, double *limit, double *offset, char *name);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | Project identifier. | 
**limit** | **double \*** | Maximum number of results to return. | [optional] [default to 100]
**offset** | **double \*** | Number of results to skip. | [optional] [default to 0]
**name** | **char \*** | Filter by exact instance name. | [optional] 

### Return type

[project_instance_list_t](project_instance_list.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProjectsAPI_v3ListProjectKeys**
```c
// List project keys
//
// List the authorized keys for a project.
//
project_key_list_t* ProjectsAPI_v3ListProjectKeys(apiClient_t *apiClient, char *projectId, double *limit, double *offset);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | Project identifier. | 
**limit** | **double \*** | Maximum number of results to return. | [optional] [default to 100]
**offset** | **double \*** | Number of results to skip. | [optional] [default to 0]

### Return type

[project_key_list_t](project_key_list.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProjectsAPI_v3ListProjects**
```c
// List projects
//
// List the projects the authenticated user can access.
//
project_list_t* ProjectsAPI_v3ListProjects(apiClient_t *apiClient, double *limit, double *offset, char *name);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**limit** | **double \*** | Maximum number of results to return. | [optional] [default to 100]
**offset** | **double \*** | Number of results to skip. | [optional] [default to 0]
**name** | **char \*** | Filter by exact project name (case-insensitive). | [optional] 

### Return type

[project_list_t](project_list.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProjectsAPI_v3PatchProject**
```c
// Update a project
//
// Update a project's name, settings, or quotas. This is the single canonical way to change project settings: fields provided in `settings` are merged into the project's existing settings, so omitted fields are preserved.
//
project_t* ProjectsAPI_v3PatchProject(apiClient_t *apiClient, char *projectId, patch_project_body_t *patch_project_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | Project identifier. | 
**patch_project_body** | **[patch_project_body_t](patch_project_body.md) \*** | Fields to update. | 

### Return type

[project_t](project.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProjectsAPI_v3PutProjectImageUpload**
```c
// Upload image chunk
//
// Upload a chunk of a project image using the resumable upload protocol. Creates the image record on the first chunk if it does not yet exist. This is the upload used while creating a device, before any instance exists to own the image.
//
void ProjectsAPI_v3PutProjectImageUpload(apiClient_t *apiClient, char *projectId, char *type, char *imageId, char *name, binary_t* body, double *resumableChunkNumber, double *resumableChunkSize, double *resumableCurrentChunkSize, double *resumableTotalSize, double *resumableTotalChunks, char *corelliumChecksum, char *flavor, char *x_corellium_image_encoding, int *x_corellium_image_encapsulated, double *x_corellium_total_file_size, char *x_corellium_image_password);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | Project identifier. | 
**type** | **char \*** | Image type. | 
**imageId** | **char \*** | Client-generated image identifier. The image record is created on the first chunk. | 
**name** | **char \*** | URL-encoded image filename. | 
**body** | **binary_t*** |  | 
**resumableChunkNumber** | **double \*** | chunk sequence number. | [optional] 
**resumableChunkSize** | **double \*** | size of each chunk. | [optional] 
**resumableCurrentChunkSize** | **double \*** | size of the chunk in this request. | [optional] 
**resumableTotalSize** | **double \*** | total file size. | [optional] 
**resumableTotalChunks** | **double \*** | total number of chunks. | [optional] 
**corelliumChecksum** | **char \*** | Corellium chunked checksum of the whole file. When supplied, each chunk is re-hashed and the upload is rejected on mismatch. Required for firmware uploads in airgapped deployments. | [optional] 
**flavor** | **char \*** | Flavor identifier to associate with the image. | [optional] 
**x_corellium_image_encoding** | **char \*** | How the uploaded file is stored. Set on the first chunk, when the image record is created. | [optional] 
**x_corellium_image_encapsulated** | **int \*** | Whether the uploaded file is an archive the coordinator should unpack. Set false to store the file as uploaded. Set on the first chunk, when the image record is created. | [optional] 
**x_corellium_total_file_size** | **double \*** | Total size of the whole file in bytes. Preferred over Content-Length for the pre-flight image-pool space check on on-site clusters, which is what produces the 507 response. | [optional] 
**x_corellium_image_password** | **char \*** | Password used to open a password-protected image during post-upload validation. | [optional] 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/octet-stream
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

