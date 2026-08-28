# ClusterAdministrationFirmwareServiceAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ClusterAdministrationFirmwareServiceAPI_v1CreateAssetsFirmwareService**](ClusterAdministrationFirmwareServiceAPI.md#ClusterAdministrationFirmwareServiceAPI_v1CreateAssetsFirmwareService) | **POST** /v1/cluster/firmware-service/firmware-assets | Add firmware assets via the firmware service
[**ClusterAdministrationFirmwareServiceAPI_v1CreateImage**](ClusterAdministrationFirmwareServiceAPI.md#ClusterAdministrationFirmwareServiceAPI_v1CreateImage) | **POST** /v1/images | Create a new Image
[**ClusterAdministrationFirmwareServiceAPI_v1DeleteAssetFirmwareService**](ClusterAdministrationFirmwareServiceAPI.md#ClusterAdministrationFirmwareServiceAPI_v1DeleteAssetFirmwareService) | **DELETE** /v1/cluster/firmware-service/firmware-assets/{assetURL} | Delete a firmware asset by its URL
[**ClusterAdministrationFirmwareServiceAPI_v1DeleteFirmwareFirmwareService**](ClusterAdministrationFirmwareServiceAPI.md#ClusterAdministrationFirmwareServiceAPI_v1DeleteFirmwareFirmwareService) | **DELETE** /v1/cluster/firmware-service/firmwares/{filename} | Delete a firmware by filename from the firmware service
[**ClusterAdministrationFirmwareServiceAPI_v1GetAssetExtendedFirmwareService**](ClusterAdministrationFirmwareServiceAPI.md#ClusterAdministrationFirmwareServiceAPI_v1GetAssetExtendedFirmwareService) | **GET** /v1/cluster/firmware-service/firmware-assets/{assetURL}/extended | Fetch extended firmware-asset details including instances and associated IPSWs
[**ClusterAdministrationFirmwareServiceAPI_v1GetConfigFirmwareService**](ClusterAdministrationFirmwareServiceAPI.md#ClusterAdministrationFirmwareServiceAPI_v1GetConfigFirmwareService) | **GET** /v1/cluster/firmware-service/config | Fetch firmware service configuration
[**ClusterAdministrationFirmwareServiceAPI_v1GetInstallFirmwareStatus**](ClusterAdministrationFirmwareServiceAPI.md#ClusterAdministrationFirmwareServiceAPI_v1GetInstallFirmwareStatus) | **GET** /v1/images/install-firmware/{taskId} | Query install firmware request status.
[**ClusterAdministrationFirmwareServiceAPI_v1InstallFirmware**](ClusterAdministrationFirmwareServiceAPI.md#ClusterAdministrationFirmwareServiceAPI_v1InstallFirmware) | **POST** /v1/images/install-firmware | Installs a firmware for cluster-wide use
[**ClusterAdministrationFirmwareServiceAPI_v1InstallFirmwareAssets**](ClusterAdministrationFirmwareServiceAPI.md#ClusterAdministrationFirmwareServiceAPI_v1InstallFirmwareAssets) | **POST** /v1/images/install-firmware-assets | Installs firmware assets for cluster-wide use
[**ClusterAdministrationFirmwareServiceAPI_v1ListAssetsFirmwareService**](ClusterAdministrationFirmwareServiceAPI.md#ClusterAdministrationFirmwareServiceAPI_v1ListAssetsFirmwareService) | **GET** /v1/cluster/firmware-service/firmware-assets | Fetch firmware assets from the firmware service
[**ClusterAdministrationFirmwareServiceAPI_v1ListDevicesFirmwareService**](ClusterAdministrationFirmwareServiceAPI.md#ClusterAdministrationFirmwareServiceAPI_v1ListDevicesFirmwareService) | **GET** /v1/cluster/firmware-service/devices | Fetch devices from the firmware service
[**ClusterAdministrationFirmwareServiceAPI_v1ListFirmwaresFirmwareService**](ClusterAdministrationFirmwareServiceAPI.md#ClusterAdministrationFirmwareServiceAPI_v1ListFirmwaresFirmwareService) | **GET** /v1/cluster/firmware-service/firmwares | Fetch firmwares from the firmware service
[**ClusterAdministrationFirmwareServiceAPI_v1PatchConfigFirmwareService**](ClusterAdministrationFirmwareServiceAPI.md#ClusterAdministrationFirmwareServiceAPI_v1PatchConfigFirmwareService) | **PATCH** /v1/cluster/firmware-service/config | Update firmware service configuration
[**ClusterAdministrationFirmwareServiceAPI_v1UploadImageData**](ClusterAdministrationFirmwareServiceAPI.md#ClusterAdministrationFirmwareServiceAPI_v1UploadImageData) | **POST** /v1/images/{imageId} | Upload Image Data


# **ClusterAdministrationFirmwareServiceAPI_v1CreateAssetsFirmwareService**
```c
// Add firmware assets via the firmware service
//
// Proxies a request to the firmware service to add firmware assets.
//
char* ClusterAdministrationFirmwareServiceAPI_v1CreateAssetsFirmwareService(apiClient_t *apiClient, object_t *body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**body** | **[object_t](object.md) \*** | Firmware assets payload | 

### Return type

char*



### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: text/html, application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ClusterAdministrationFirmwareServiceAPI_v1CreateImage**
```c
// Create a new Image
//
// Create a new Image. Accepts multipart/form-data (with optional file upload) or application/json (metadata only).
//
image_v1_t* ClusterAdministrationFirmwareServiceAPI_v1CreateImage(apiClient_t *apiClient, image_creation_options_t *image_creation_options);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**image_creation_options** | **[image_creation_options_t](image_creation_options.md) \*** | Image data | 

### Return type

[image_v1_t](image_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ClusterAdministrationFirmwareServiceAPI_v1DeleteAssetFirmwareService**
```c
// Delete a firmware asset by its URL
//
// Proxies a request to the firmware service to delete a firmware asset by URL.
//
void ClusterAdministrationFirmwareServiceAPI_v1DeleteAssetFirmwareService(apiClient_t *apiClient, char *assetURL);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**assetURL** | **char \*** | The raw firmware asset URL. Percent-encode it once when composing the request path by hand. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ClusterAdministrationFirmwareServiceAPI_v1DeleteFirmwareFirmwareService**
```c
// Delete a firmware by filename from the firmware service
//
// Proxies a request to the firmware service to delete a firmware by filename.
//
void ClusterAdministrationFirmwareServiceAPI_v1DeleteFirmwareFirmwareService(apiClient_t *apiClient, char *filename);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**filename** | **char \*** | The filename of the firmware to delete | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ClusterAdministrationFirmwareServiceAPI_v1GetAssetExtendedFirmwareService**
```c
// Fetch extended firmware-asset details including instances and associated IPSWs
//
// Retrieves extended information about a firmware including all instances using it and associated firmware assets.
//
extended_firmware_asset_info_v1_t* ClusterAdministrationFirmwareServiceAPI_v1GetAssetExtendedFirmwareService(apiClient_t *apiClient, char *assetURL);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**assetURL** | **char \*** | The raw firmware asset URL. Percent-encode it once when composing the request path by hand. | 

### Return type

[extended_firmware_asset_info_v1_t](extended_firmware_asset_info_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ClusterAdministrationFirmwareServiceAPI_v1GetConfigFirmwareService**
```c
// Fetch firmware service configuration
//
// Returns a firmware service configuration object
//
void ClusterAdministrationFirmwareServiceAPI_v1GetConfigFirmwareService(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ClusterAdministrationFirmwareServiceAPI_v1GetInstallFirmwareStatus**
```c
// Query install firmware request status.
//
// Returns the status of an install firmware request.
//
install_firmware_response_v1_t* ClusterAdministrationFirmwareServiceAPI_v1GetInstallFirmwareStatus(apiClient_t *apiClient, char *taskId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**taskId** | **char \*** | Task ID - uuid | 

### Return type

[install_firmware_response_v1_t](install_firmware_response_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ClusterAdministrationFirmwareServiceAPI_v1InstallFirmware**
```c
// Installs a firmware for cluster-wide use
//
// Takes an uploaded firmware image and installs it for cluster-wide use.  The firmware is then removed from Images.  In order to install a firmware, you need to follow a 4-step process. First, POST /v1/images/ with { name: string, type: 'fw' } using content-type application/json to acquire an imageId.  Second, upload the firmware file via a multipart/form-data POST to /v1/images/:imageId.  Third, POST /v1/images/install-firmware with { imageId: string; filename: string } using content-type application/json to acquire a taskId.    The 'filename' must be an exact match for the filename in the firmware service that you're uploading this image for.  Fourth, you can poll the state of the installation via GET /v1/images/install-firmware/:taskId.
//
install_firmware_response_v1_t* ClusterAdministrationFirmwareServiceAPI_v1InstallFirmware(apiClient_t *apiClient, install_firmware_body_v1_t *install_firmware_body_v1);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**install_firmware_body_v1** | **[install_firmware_body_v1_t](install_firmware_body_v1.md) \*** | User data | 

### Return type

[install_firmware_response_v1_t](install_firmware_response_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ClusterAdministrationFirmwareServiceAPI_v1InstallFirmwareAssets**
```c
// Installs firmware assets for cluster-wide use
//
// Takes an uploaded firmware assets blob image and installs it for cluster-wide use.  The image is then removed from Images.  This endpoint is synchronous: it forwards the asset JSON to the firmware service and returns the firmware service's response message directly. There is no task ID and no polling endpoint.  Installing firmware assets is a 3-step process. First, POST /v1/images/ with { name: string, type: 'fwasset' } using content-type application/json to acquire an imageId. name should be something like 'fcs-keys.json'  Second, upload the firmware assets file via a multipart/form-data POST to /v1/images/:imageId.  Third, POST /v1/images/install-firmware-assets with { imageId: string; } using content-type application/json. The response body is `{ message: string }` describing what the firmware service did with the assets.
//
install_firmware_assets_response_v1_t* ClusterAdministrationFirmwareServiceAPI_v1InstallFirmwareAssets(apiClient_t *apiClient, install_firmware_assets_body_v1_t *install_firmware_assets_body_v1);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**install_firmware_assets_body_v1** | **[install_firmware_assets_body_v1_t](install_firmware_assets_body_v1.md) \*** | User data | 

### Return type

[install_firmware_assets_response_v1_t](install_firmware_assets_response_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ClusterAdministrationFirmwareServiceAPI_v1ListAssetsFirmwareService**
```c
// Fetch firmware assets from the firmware service
//
// Proxies a request to the firmware service to retrieve a list of firmware assets.
//
list_t* ClusterAdministrationFirmwareServiceAPI_v1ListAssetsFirmwareService(apiClient_t *apiClient, double limit, double offset, char *order, char *search);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**limit** | **double** | Number of results to return (min: 1, max: 10000, default: 100) | [optional] 
**offset** | **double** | Index of the first row to return (default: 0) | [optional] 
**order** | **char \*** | Comma-separated field names for sorting. Prefix with &#39;-&#39; for descending order (e.g., &#39;url,-domain&#39;). | [optional] 
**search** | **char \*** | Case-insensitive partial match across url, domain | [optional] 

### Return type

[list_t](firmware_asset_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ClusterAdministrationFirmwareServiceAPI_v1ListDevicesFirmwareService**
```c
// Fetch devices from the firmware service
//
// Proxies a request to the firmware service to retrieve a list of devices.
//
list_t* ClusterAdministrationFirmwareServiceAPI_v1ListDevicesFirmwareService(apiClient_t *apiClient, double limit, double offset, char *search, char *order, char *type, char *model, char *name, char *platform);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**limit** | **double** | Number of results to return (min: 1, max: 10000, default: 100) | [optional] 
**offset** | **double** | Index of the first row to return (default: 0) | [optional] 
**search** | **char \*** | Case-insensitive partial match across name, model, platform, and hwmodel fields | [optional] 
**order** | **char \*** | Comma-separated field names for sorting. Prefix with &#39;-&#39; for descending order (e.g., &#39;name,-platform&#39;). Allowed fields: name, model, type, platform, hwmodel  Filtering options: | [optional] 
**type** | **char \*** | Filter by exact type. Example: coreimg | [optional] 
**model** | **char \*** | Filter by exact model. Example: Example: iPhone8,1 | [optional] 
**name** | **char \*** | Filter by exact name. Example: iPhone6s | [optional] 
**platform** | **char \*** | Filter by exact platform. Example: s5l8960x | [optional] 

### Return type

[list_t](device.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ClusterAdministrationFirmwareServiceAPI_v1ListFirmwaresFirmwareService**
```c
// Fetch firmwares from the firmware service
//
// Proxies a request to the firmware service to retrieve a list of firmwares.
//
list_t* ClusterAdministrationFirmwareServiceAPI_v1ListFirmwaresFirmwareService(apiClient_t *apiClient, double limit, double offset, char *search, char *order, char *filename, char *model, char *type, char *version, char *buildid, char *firmware_assets, int *installed);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**limit** | **double** | Number of results to return (min: 1, max: 10000, default: 100) | [optional] 
**offset** | **double** | Index of the first row to return (default: 0) | [optional] 
**search** | **char \*** | Case-insensitive partial match across filename, model, type, version and buildid fields | [optional] 
**order** | **char \*** | Comma-separated field names for sorting. Prefix with &#39;-&#39; for descending order (e.g., &#39;name,-platform&#39;). Allowed fields: filename, model, type, version, buildid  Filtering options: | [optional] 
**filename** | **char \*** | Filter by exact filename. Example: iPhone_4.7_P3_12.1.4_16D57_Restore.ipsw | [optional] 
**model** | **char \*** | Filter by exact model. Example: iPhone10,4 | [optional] 
**type** | **char \*** | Filter by exact type. Example: ipsw | [optional] 
**version** | **char \*** | Filter by exact version. Example: 12.1.4 | [optional] 
**buildid** | **char \*** | Filter by exact buildid. Example: 16D57 | [optional] 
**firmware_assets** | **char \*** | Filter by exact asset URL/ID. Example: https://wkms-public.apple.com/fcs-keys/rl_td3o_0EtXT8t6HvVJoeWXnoBuzumHyUTD8-MUaF8&#x3D; -OR- rl_td3o_0EtXT8t6HvVJoeWXnoBuzumHyUTD8-MUaF8&#x3D; | [optional] 
**installed** | **int \*** | Filter by installed status | [optional] 

### Return type

[list_t](firmware_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ClusterAdministrationFirmwareServiceAPI_v1PatchConfigFirmwareService**
```c
// Update firmware service configuration
//
// Updates firmware service configuration
//
void ClusterAdministrationFirmwareServiceAPI_v1PatchConfigFirmwareService(apiClient_t *apiClient, firmware_service_configuration_t *firmware_service_configuration);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**firmware_service_configuration** | **[firmware_service_configuration_t](firmware_service_configuration.md) \*** | Firmware configuration payload | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ClusterAdministrationFirmwareServiceAPI_v1UploadImageData**
```c
// Upload Image Data
//
// If the active project has enough remaining quota, updates an Image with the contents of the request body.
//
image_v1_t* ClusterAdministrationFirmwareServiceAPI_v1UploadImageData(apiClient_t *apiClient, char *imageId, char *corelliumChecksum, binary_t* file);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**imageId** | **char \*** | Image ID - uuid | 
**corelliumChecksum** | **char \*** | Corellium Checksum of the uploaded firmware | [optional] 
**file** | **binary_t*** | Optionally the actual file | [optional] 

### Return type

[image_v1_t](image_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: multipart/form-data
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

