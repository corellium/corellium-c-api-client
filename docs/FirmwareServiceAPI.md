# FirmwareServiceAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**FirmwareServiceAPI_v3CreateFirmwareAssets**](FirmwareServiceAPI.md#FirmwareServiceAPI_v3CreateFirmwareAssets) | **POST** /v3/cluster/firmware-service/firmware-assets | Add firmware assets
[**FirmwareServiceAPI_v3DeleteFirmware**](FirmwareServiceAPI.md#FirmwareServiceAPI_v3DeleteFirmware) | **DELETE** /v3/cluster/firmware-service/firmwares/{filename} | Delete a firmware
[**FirmwareServiceAPI_v3DeleteFirmwareAsset**](FirmwareServiceAPI.md#FirmwareServiceAPI_v3DeleteFirmwareAsset) | **DELETE** /v3/cluster/firmware-service/firmware-assets/{assetUrl} | Delete a firmware asset
[**FirmwareServiceAPI_v3GetFirmwareAssetExtended**](FirmwareServiceAPI.md#FirmwareServiceAPI_v3GetFirmwareAssetExtended) | **GET** /v3/cluster/firmware-service/firmware-assets/{assetUrl}/extended | Get extended firmware asset info
[**FirmwareServiceAPI_v3GetFirmwareServiceConfig**](FirmwareServiceAPI.md#FirmwareServiceAPI_v3GetFirmwareServiceConfig) | **GET** /v3/cluster/firmware-service/config | Get firmware service configuration
[**FirmwareServiceAPI_v3ListFirmwareAssets**](FirmwareServiceAPI.md#FirmwareServiceAPI_v3ListFirmwareAssets) | **GET** /v3/cluster/firmware-service/firmware-assets | List firmware assets
[**FirmwareServiceAPI_v3ListFirmwareDevices**](FirmwareServiceAPI.md#FirmwareServiceAPI_v3ListFirmwareDevices) | **GET** /v3/cluster/firmware-service/devices | List firmware service devices
[**FirmwareServiceAPI_v3ListFirmwares**](FirmwareServiceAPI.md#FirmwareServiceAPI_v3ListFirmwares) | **GET** /v3/cluster/firmware-service/firmwares | List firmwares
[**FirmwareServiceAPI_v3PatchFirmwareServiceConfig**](FirmwareServiceAPI.md#FirmwareServiceAPI_v3PatchFirmwareServiceConfig) | **PATCH** /v3/cluster/firmware-service/config | Update firmware service configuration


# **FirmwareServiceAPI_v3CreateFirmwareAssets**
```c
// Add firmware assets
//
// **Required role:** Cluster administrator.  Adds firmware assets to the cluster firmware service.
//
char* FirmwareServiceAPI_v3CreateFirmwareAssets(apiClient_t *apiClient, object_t *body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**body** | **[object_t](object.md) \*** |  | [optional] 

### Return type

char*



### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **FirmwareServiceAPI_v3DeleteFirmware**
```c
// Delete a firmware
//
// **Required role:** Cluster administrator.  Deletes the firmware identified by the given filename from the cluster firmware service.  This endpoint proxies the request to the firmware service. A filename the service no longer has is a successful no-op: both a successful upstream delete and an upstream \"not there\" answer 204, and repeated calls return 204 as well. A firmware-service outage or refusal is still reported as a failure.
//
void FirmwareServiceAPI_v3DeleteFirmware(apiClient_t *apiClient, char *filename);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**filename** | **char \*** | Firmware filename. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **FirmwareServiceAPI_v3DeleteFirmwareAsset**
```c
// Delete a firmware asset
//
// **Required role:** Cluster administrator.  Deletes the firmware asset identified by the given asset URL from the cluster firmware service.  This endpoint proxies the request to the firmware service. An asset the service no longer has is a successful no-op: both a successful upstream delete and an upstream \"not there\" answer 204, and repeated calls return 204 as well. A firmware-service outage or refusal is still reported as a failure.
//
void FirmwareServiceAPI_v3DeleteFirmwareAsset(apiClient_t *apiClient, char *assetUrl);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**assetUrl** | **char \*** | Firmware asset URL, passed as the raw (un-encoded) value. Generated SDK clients percent-encode it into the request path automatically; only when composing the HTTP request path by hand (e.g. curl) does the caller percent-encode it, once, like any path segment. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **FirmwareServiceAPI_v3GetFirmwareAssetExtended**
```c
// Get extended firmware asset info
//
// **Required role:** Cluster administrator.  Returns the firmwares and instances associated with a firmware asset.
//
extended_firmware_asset_info_t* FirmwareServiceAPI_v3GetFirmwareAssetExtended(apiClient_t *apiClient, char *assetUrl);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**assetUrl** | **char \*** | Firmware asset URL, passed as the raw (un-encoded) value. Generated SDK clients percent-encode it into the request path automatically; only when composing the HTTP request path by hand (e.g. curl) does the caller percent-encode it, once, like any path segment. | 

### Return type

[extended_firmware_asset_info_t](extended_firmware_asset_info.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **FirmwareServiceAPI_v3GetFirmwareServiceConfig**
```c
// Get firmware service configuration
//
// **Required role:** Cluster administrator.  Returns the current configuration of the cluster firmware service.
//
firmware_service_config_t* FirmwareServiceAPI_v3GetFirmwareServiceConfig(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[firmware_service_config_t](firmware_service_config.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **FirmwareServiceAPI_v3ListFirmwareAssets**
```c
// List firmware assets
//
// **Required role:** Cluster administrator.  Returns a paginated list of firmware assets available in the cluster firmware service.
//
firmware_asset_list_t* FirmwareServiceAPI_v3ListFirmwareAssets(apiClient_t *apiClient, double *limit, double *offset, char *search, char *order, firmware_asset_filter_t *filter);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**limit** | **double \*** | Number of results to return. | [optional] [default to 100]
**offset** | **double \*** | Index of the first row to return. | [optional] [default to 0]
**search** | **char \*** | Case-insensitive partial match across key fields. | [optional] 
**order** | **char \*** | Comma-separated sort fields; prefix with \&quot;-\&quot; for descending order. | [optional] 
**filter** | **[firmware_asset_filter_t](.md) \*** | Exact-match filters (filter[url], filter[domain]). | [optional] 

### Return type

[firmware_asset_list_t](firmware_asset_list.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **FirmwareServiceAPI_v3ListFirmwareDevices**
```c
// List firmware service devices
//
// **Required role:** Cluster administrator.  Returns a paginated list of devices known to the cluster firmware service.
//
firmware_device_list_t* FirmwareServiceAPI_v3ListFirmwareDevices(apiClient_t *apiClient, double *limit, double *offset, char *search, char *order, char *type, char *model, char *name, char *platform, char *hwModel);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**limit** | **double \*** | Number of results to return. | [optional] [default to 100]
**offset** | **double \*** | Index of the first row to return. | [optional] [default to 0]
**search** | **char \*** | Case-insensitive partial match across key fields. | [optional] 
**order** | **char \*** | Comma-separated sort fields; prefix with \&quot;-\&quot; for descending order. | [optional] 
**type** | **char \*** | Filter by exact type. | [optional] 
**model** | **char \*** | Filter by exact model. | [optional] 
**name** | **char \*** | Filter by exact name. | [optional] 
**platform** | **char \*** | Filter by exact platform. | [optional] 
**hwModel** | **char \*** | Filter by exact hardware model. | [optional] 

### Return type

[firmware_device_list_t](firmware_device_list.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **FirmwareServiceAPI_v3ListFirmwares**
```c
// List firmwares
//
// **Required role:** Cluster administrator.  Returns a paginated list of firmwares available in the cluster firmware service.
//
firmware_list_t* FirmwareServiceAPI_v3ListFirmwares(apiClient_t *apiClient, double *limit, double *offset, char *search, char *order, char *filename, char *model, char *type, char *version, char *buildId, char *firmwareAssets, char *corelliumChecksum, int *installed);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**limit** | **double \*** | Number of results to return. | [optional] [default to 100]
**offset** | **double \*** | Index of the first row to return. | [optional] [default to 0]
**search** | **char \*** | Case-insensitive partial match across key fields. | [optional] 
**order** | **char \*** | Comma-separated sort fields; prefix with \&quot;-\&quot; for descending order. | [optional] 
**filename** | **char \*** | Filter by exact filename. | [optional] 
**model** | **char \*** | Filter by exact model. | [optional] 
**type** | **char \*** | Filter by exact type. | [optional] 
**version** | **char \*** | Filter by exact version. | [optional] 
**buildId** | **char \*** | Filter by exact build ID. | [optional] 
**firmwareAssets** | **char \*** | Filter by exact asset URL/ID. | [optional] 
**corelliumChecksum** | **char \*** | Filter by exact Corellium checksum (upload preflight). | [optional] 
**installed** | **int \*** | Filter by installed status. | [optional] 

### Return type

[firmware_list_t](firmware_list.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **FirmwareServiceAPI_v3PatchFirmwareServiceConfig**
```c
// Update firmware service configuration
//
// **Required role:** Cluster administrator.  Updates the cluster firmware service configuration and returns the merged result.
//
firmware_service_settings_t* FirmwareServiceAPI_v3PatchFirmwareServiceConfig(apiClient_t *apiClient, patch_firmware_service_config_body_t *patch_firmware_service_config_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**patch_firmware_service_config_body** | **[patch_firmware_service_config_body_t](patch_firmware_service_config_body.md) \*** |  | [optional] 

### Return type

[firmware_service_settings_t](firmware_service_settings.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

