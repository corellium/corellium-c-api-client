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
[**ProjectsAPI_v3PreauthVpnConfig**](ProjectsAPI.md#ProjectsAPI_v3PreauthVpnConfig) | **POST** /v3/projects/{projectId}/preauth-vpn-config/{filename} | Pre-authorize a VPN configuration download
[**ProjectsAPI_v3PutProjectImageUpload**](ProjectsAPI.md#ProjectsAPI_v3PutProjectImageUpload) | **PUT** /v3/projects/{projectId}/image-upload/{type}/{imageId}/{name} | Upload image chunk


# **ProjectsAPI_v3CreateProject**
```c
// Create a project
//
// **Required role:** Domain administrator.  Creates a new project in your domain. Requires a domain administrator.  **Give it quota, or it cannot run devices.** A new project created without `quotas` has zero quota. Quota is reserved out of your domain's total allowance, so if the whole allowance is already reserved by other projects, lower one of them with `v3PatchProject` first.  When you set `quotas`, `cores` is required. `instances` is derived from `cores` if you leave it out, and memory is always calculated from cores (6144 MiB per core); any `ram` you send is ignored.  Returns 201 with the new project, including its `id`.
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
// **Required role:** Domain administrator or project administrator.  Authorizes a public key on the project, so its holder can connect to the project's devices. Requires a domain or project administrator.  Set `kind` to `ssh` for SSH access or `adb` for Android Debug Bridge access, and put the public key (never the private key) in `key`, in the same one-line format as an OpenSSH `authorized_keys` entry. `label` is an optional note to help you recognise the key later. Returns 400 if the key cannot be parsed.
//
project_key_t* ProjectsAPI_v3CreateProjectKey(apiClient_t *apiClient, char *projectId, create_project_key_body_t *create_project_key_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | ID of the project. Get it from &#x60;v3ListProjects&#x60;, or from the &#x60;id&#x60; returned when the project was created. | 
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
// **Required role:** Domain administrator.  Deletes a project together with every file (image) uploaded to it. Requires a domain administrator.  The project must not contain any devices: if it does, the request fails with 409 and nothing is deleted. Delete the devices first with `DELETE /v3/instances/{instanceId}` and wait until they are gone.  Deletes are idempotent: an unknown `projectId`, or a project that was already deleted, is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing.
//
void ProjectsAPI_v3DeleteProject(apiClient_t *apiClient, char *projectId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | ID of the project. Get it from &#x60;v3ListProjects&#x60;, or from the &#x60;id&#x60; returned when the project was created. | 

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
// **Required role:** Domain administrator or project administrator.  Removes an authorized key from the project, so it can no longer be used to connect to the project's devices. Requires a domain or project administrator.  Deletes are idempotent: a `keyId` that is not present on the project, or an unknown `projectId`, is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing.
//
void ProjectsAPI_v3DeleteProjectKey(apiClient_t *apiClient, char *projectId, char *keyId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | ID of the project. Get it from &#x60;v3ListProjects&#x60;, or from the &#x60;id&#x60; returned when the project was created. | 
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
// Asks the platform to download firmware assets (for example the decryption keys some iOS versions need to boot) from the given URLs and store them for your domain. Use it when device creation reports that assets are missing: the missing asset URLs appear in that error and in each firmware entry. The response lists which URLs were newly stored, which were already present, and which failed and why. Returns 409 if downloading assets is turned off on this deployment (for example an air-gapped one); there, upload the assets as a file and install them with `POST /v3/images/install-firmware-assets` instead.
//
fetch_firmware_assets_response_t* ProjectsAPI_v3FetchProjectFirmwareAssets(apiClient_t *apiClient, char *projectId, fetch_firmware_assets_body_t *fetch_firmware_assets_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | ID of the project. Get it from &#x60;v3ListProjects&#x60;, or from the &#x60;id&#x60; returned when the project was created. | 
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
// Returns one project with its settings, quotas, and current resource usage (`quotasUsed`). Compare `quotas` with `quotasUsed` to see whether there is room for another device before creating one. Returns 404 if the project does not exist and 403 if you cannot access it.
//
project_t* ProjectsAPI_v3GetProject(apiClient_t *apiClient, char *projectId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | ID of the project. Get it from &#x60;v3ListProjects&#x60;, or from the &#x60;id&#x60; returned when the project was created. | 

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
// Checks the progress of a chunked upload made with `v3PutProjectImageUpload`, or downloads the finished file.  - **With chunk parameters** (`resumableChunkNumber` and friends): returns 200 if that chunk is already stored, or 204 if it still needs to be sent. Use this to resume an interrupted upload without re-sending data. - **Without them:** downloads the image file.
//
binary_t** ProjectsAPI_v3GetProjectImageUpload(apiClient_t *apiClient, char *projectId, char *type, char *imageId, char *name, double *resumableChunkNumber);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | ID of the project. Get it from &#x60;v3ListProjects&#x60;, or from the &#x60;id&#x60; returned when the project was created. | 
**type** | **char \*** | What kind of file this is, for example &#x60;fw&#x60; for firmware or &#x60;kernel&#x60;. Uses the same values as &#x60;type&#x60; on &#x60;POST /v3/images&#x60;; see &#x60;ImageType&#x60; for what each means. Types that need a license feature your license lacks are rejected with 403. | 
**imageId** | **char \*** | An ID you choose for the new image: generate a random UUID once per file and use the same value for every chunk of that file. The image record is created with this ID when the first chunk arrives. Use a new UUID for each new upload. | 
**name** | **char \*** | The file name to store, URL-encoded (for example &#x60;my%20firmware.ipsw&#x60;). Becomes the image &#x60;name&#x60;. | 
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
// Returns the log of the project's outbound VPN connection as plain text. Use it to diagnose a connection that will not come up.
//
char* ProjectsAPI_v3GetProjectNetworkLog(apiClient_t *apiClient, char *projectId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | ID of the project. Get it from &#x60;v3ListProjects&#x60;, or from the &#x60;id&#x60; returned when the project was created. | 

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
// Returns the state of the project's outbound VPN connection (the connection set in `settings.connection`), such as whether it is connected, and error details if it is not. Use it to check that device traffic is flowing through your VPN.
//
network_status_t* ProjectsAPI_v3GetProjectNetworkStatus(apiClient_t *apiClient, char *projectId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | ID of the project. Get it from &#x60;v3ListProjects&#x60;, or from the &#x60;id&#x60; returned when the project was created. | 

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
// Downloads a VPN configuration that lets your computer join the project's device network, so you can reach the devices directly (for example by SSH or a local debugger). Set `format` to 'ovpn' to get an OpenVPN profile to import into any OpenVPN client. Any other value returns a zip for the Tunnelblick client on macOS. Returns 400 if the project does not have a VPN endpoint yet.
//
char* ProjectsAPI_v3GetProjectVpnConfig(apiClient_t *apiClient, char *projectId, char *format);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | ID of the project. Get it from &#x60;v3ListProjects&#x60;, or from the &#x60;id&#x60; returned when the project was created. | 
**format** | **char \*** | VPN configuration format: &#39;ovpn&#39; for an OpenVPN profile; any other value returns a Tunnelblick zip. | 

### Return type

char*



### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/x-openvpn-profile, application/zip, application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProjectsAPI_v3ListProjectInstances**
```c
// List project instances
//
// Lists the devices (instances) in a project, with their ID, name and current state. Results are paginated with `limit` and `offset`; use `name` to find a device by its exact name. For full device details, call `GET /v3/instances/{instanceId}`.
//
project_instance_list_t* ProjectsAPI_v3ListProjectInstances(apiClient_t *apiClient, char *projectId, double *limit, double *offset, char *name);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | ID of the project. Get it from &#x60;v3ListProjects&#x60;, or from the &#x60;id&#x60; returned when the project was created. | 
**limit** | **double \*** | Most results to return in one page. Whole number from 1 to 1000; defaults to 100. A value outside that range is rejected with 400. | [optional] [default to 100]
**offset** | **double \*** | How many results to skip before this page starts; defaults to 0. To get the next page, add &#x60;limit&#x60; to the previous &#x60;offset&#x60;. | [optional] [default to 0]
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
// Lists the public keys authorized on this project. Keys let you connect to the project's devices over SSH, or to Android devices over ADB, without a password. Returns 403 if your deployment is not licensed for key pairing.
//
project_key_list_t* ProjectsAPI_v3ListProjectKeys(apiClient_t *apiClient, char *projectId, double *limit, double *offset);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | ID of the project. Get it from &#x60;v3ListProjects&#x60;, or from the &#x60;id&#x60; returned when the project was created. | 
**limit** | **double \*** | Most results to return in one page. Whole number from 1 to 1000; defaults to 100. A value outside that range is rejected with 400. | [optional] [default to 100]
**offset** | **double \*** | How many results to skip before this page starts; defaults to 0. To get the next page, add &#x60;limit&#x60; to the previous &#x60;offset&#x60;. | [optional] [default to 0]

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
// Lists the projects you can access. A project is a workspace that holds devices (instances), the files uploaded for them, and a share of your domain's resources (CPU cores, memory and device count). Almost every other call needs a project ID, so this is usually the first call after you sign in.  Results are paginated with `limit` and `offset`. Use `name` to find one project by its exact name (not case-sensitive). Each entry includes its quotas, current usage, and the number of authorized keys.
//
project_list_t* ProjectsAPI_v3ListProjects(apiClient_t *apiClient, double *limit, double *offset, char *name);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**limit** | **double \*** | Most results to return in one page. Whole number from 1 to 1000; defaults to 100. A value outside that range is rejected with 400. | [optional] [default to 100]
**offset** | **double \*** | How many results to skip before this page starts; defaults to 0. To get the next page, add &#x60;limit&#x60; to the previous &#x60;offset&#x60;. | [optional] [default to 0]
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
// Changes a project's name, settings or quotas. Send only the fields you want to change.  - `settings` is merged into the existing settings: fields you leave out keep their current values. - `quotas` follows the same rules as on create: `cores` is required, `instances` is derived when omitted, and memory is always calculated from cores. - Changing the network connection (`settings.connection`) is refused with 400 while any device in the project is running. Stop the devices first.  Returns the updated project.
//
project_t* ProjectsAPI_v3PatchProject(apiClient_t *apiClient, char *projectId, patch_project_body_t *patch_project_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | ID of the project. Get it from &#x60;v3ListProjects&#x60;, or from the &#x60;id&#x60; returned when the project was created. | 
**patch_project_body** | **[patch_project_body_t](patch_project_body.md) \*** | Fields to update. | 

### Return type

[project_t](project.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProjectsAPI_v3PreauthVpnConfig**
```c
// Pre-authorize a VPN configuration download
//
// Pre-authorize a VPN configuration download. Returns a short-lived signed token that authorizes the download without an Authorization header, so it can be embedded in a plain download URL: GET /v1/preauthed-vpn-configs/{token}/{filename}. The token carries the client identifier and the format, and expires with the calling session token.
//
vpn_config_preauthorization_t* ProjectsAPI_v3PreauthVpnConfig(apiClient_t *apiClient, char *projectId, char *filename);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | ID of the project. Get it from &#x60;v3ListProjects&#x60;, or from the &#x60;id&#x60; returned when the project was created. | 
**filename** | **char \*** | VPN configuration filename, as &#39;&lt;clientId&gt;.&lt;format&gt;&#39;. The client identifier becomes the common name of the issued client certificate; a format of &#39;ovpn&#39; yields an OpenVPN profile and any other value yields a Tunnelblick zip. | 

### Return type

[vpn_config_preauthorization_t](vpn_config_preauthorization.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProjectsAPI_v3PutProjectImageUpload**
```c
// Upload image chunk
//
// Uploads one chunk of a file into this project, using the same resumable protocol as `PUT /v3/images/{imageId}/file`. The difference is that you choose the image ID yourself (a new random UUID) and the image record is created automatically when the first chunk arrives, so no `POST /v3/images` call is needed. The `type` and `name` in the path set the image type and name. The image belongs to the project and is deleted with it. The web interface uses this route when uploading firmware while creating a device. For your own code, `POST /v3/images` followed by `PUT /v3/images/{imageId}/file` is easier to follow. Returns 200 with an empty object for each stored chunk. If an upload fails for a reason other than a network error, the partial image is deleted.
//
object_t* ProjectsAPI_v3PutProjectImageUpload(apiClient_t *apiClient, char *projectId, char *type, char *imageId, char *name, binary_t* body, double *resumableChunkNumber, double *resumableChunkSize, double *resumableCurrentChunkSize, double *resumableTotalSize, double *resumableTotalChunks, char *corelliumChecksum, char *flavor, char *x_corellium_image_encoding, int *x_corellium_image_encapsulated, double *x_corellium_total_file_size, char *x_corellium_image_password);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | ID of the project. Get it from &#x60;v3ListProjects&#x60;, or from the &#x60;id&#x60; returned when the project was created. | 
**type** | **char \*** | What kind of file this is, for example &#x60;fw&#x60; for firmware or &#x60;kernel&#x60;. Uses the same values as &#x60;type&#x60; on &#x60;POST /v3/images&#x60;; see &#x60;ImageType&#x60; for what each means. Types that need a license feature your license lacks are rejected with 403. | 
**imageId** | **char \*** | An ID you choose for the new image: generate a random UUID once per file and use the same value for every chunk of that file. The image record is created with this ID when the first chunk arrives. Use a new UUID for each new upload. | 
**name** | **char \*** | The file name to store, URL-encoded (for example &#x60;my%20firmware.ipsw&#x60;). Becomes the image &#x60;name&#x60;. | 
**body** | **binary_t*** |  | 
**resumableChunkNumber** | **double \*** | Which chunk this is, counting from 1. | [optional] 
**resumableChunkSize** | **double \*** | The size, in bytes, you split the file into. Use the same value for every chunk; only the last chunk may be smaller. If you send &#x60;corelliumChecksum&#x60;, this must equal the block size inside it. | [optional] 
**resumableCurrentChunkSize** | **double \*** | Actual size in bytes of this chunk&#39;s body. | [optional] 
**resumableTotalSize** | **double \*** | Size of the whole file in bytes. | [optional] 
**resumableTotalChunks** | **double \*** | How many chunks the whole file is split into. The upload completes when the last one arrives. | [optional] 
**corelliumChecksum** | **char \*** | Optional expected checksum of the whole file, formatted &#x60;algorithm$blockSize$hash&#x60;. When given, the finished upload is checked and rejected (and the image removed) if it does not match. Required for firmware (&#x60;fw&#x60;) uploads on air-gapped deployments. | [optional] 
**flavor** | **char \*** | Device model (&#x60;flavor&#x60; from &#x60;GET /v3/models&#x60;) the image is for. Needed for &#x60;partition&#x60; uploads when the image is not attached to a device, so the partition name can be checked against that model. | [optional] 
**x_corellium_image_encoding** | **char \*** | How the file is stored: &#x60;plain&#x60; (normal) or &#x60;encrypted&#x60;. Only read on the first chunk, when the image record is created; later chunks cannot change it. | [optional] 
**x_corellium_image_encapsulated** | **int \*** | Whether the uploaded file is a ZIP wrapper the platform should unpack. Send false to store the file exactly as uploaded. Only read on the first chunk, when the image record is created. | [optional] 
**x_corellium_total_file_size** | **double \*** | Size of the whole file in bytes. Send it on every chunk: the platform uses it to check up front that there is room for the entire file, and answers 507 if there is not, before storing any data. | [optional] 
**x_corellium_image_password** | **char \*** | Password of a password-protected file (for example encrypted firmware), used to check the file after upload. Leave out for normal files. | [optional] 

### Return type

[object_t](object.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/octet-stream
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

