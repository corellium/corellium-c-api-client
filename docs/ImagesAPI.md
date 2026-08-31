# ImagesAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ImagesAPI_v3CreateImage**](ImagesAPI.md#ImagesAPI_v3CreateImage) | **POST** /v3/images | Create an image
[**ImagesAPI_v3DeleteImage**](ImagesAPI.md#ImagesAPI_v3DeleteImage) | **DELETE** /v3/images/{imageId} | Delete an image
[**ImagesAPI_v3GetImage**](ImagesAPI.md#ImagesAPI_v3GetImage) | **GET** /v3/images/{imageId} | Get image metadata
[**ImagesAPI_v3GetImageFirmwareInfo**](ImagesAPI.md#ImagesAPI_v3GetImageFirmwareInfo) | **POST** /v3/images/{imageId}/fwinfo | Get firmware info embedded in an image
[**ImagesAPI_v3GetInstallFirmwareStatus**](ImagesAPI.md#ImagesAPI_v3GetInstallFirmwareStatus) | **GET** /v3/images/install-firmware/{taskId} | Get install-firmware task status
[**ImagesAPI_v3InstallFirmware**](ImagesAPI.md#ImagesAPI_v3InstallFirmware) | **POST** /v3/images/install-firmware | Install firmware cluster-wide
[**ImagesAPI_v3InstallFirmwareAssets**](ImagesAPI.md#ImagesAPI_v3InstallFirmwareAssets) | **POST** /v3/images/install-firmware-assets | Install firmware assets cluster-wide
[**ImagesAPI_v3ListImages**](ImagesAPI.md#ImagesAPI_v3ListImages) | **GET** /v3/images | List image metadata
[**ImagesAPI_v3UploadImageData**](ImagesAPI.md#ImagesAPI_v3UploadImageData) | **POST** /v3/images/{imageId} | Upload image file contents


# **ImagesAPI_v3CreateImage**
```c
// Create an image
//
// Creates a new Image record, optionally uploading file contents in the same request.   Two content types are supported:   - `application/json`: creates metadata only. The caller subsequently uploads the file via     [`uploadImageData`](#operation/uploadImageData). Returns 201.   - `multipart/form-data`: creates metadata and uploads the file in a single request. Returns 200.   The `fullPath` field references a file already present on the server's local filesystem and bypasses the upload step entirely; this is intended for cluster-internal use.   For firmware images, this is step 1 of the install workflow — see [`installFirmware`](#operation/installFirmware) or [`installFirmwareAssets`](#operation/installFirmwareAssets).
//
image_t* ImagesAPI_v3CreateImage(apiClient_t *apiClient, create_image_body_t *create_image_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**create_image_body** | **[create_image_body_t](create_image_body.md) \*** |  | 

### Return type

[image_t](image.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ImagesAPI_v3DeleteImage**
```c
// Delete an image
//
// Permanently deletes the image. This action cannot be undone. Deleting an already-deleted image returns 404.
//
void ImagesAPI_v3DeleteImage(apiClient_t *apiClient, char *imageId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**imageId** | **char \*** |  | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ImagesAPI_v3GetImage**
```c
// Get image metadata
//
// Returns metadata for a single image. File contents are not returned; use [`downloadImageFile`](#operation/downloadImageFile) to fetch contents.
//
image_t* ImagesAPI_v3GetImage(apiClient_t *apiClient, char *imageId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**imageId** | **char \*** |  | 

### Return type

[image_t](image.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ImagesAPI_v3GetImageFirmwareInfo**
```c
// Get firmware info embedded in an image
//
// Extracts and returns the firmware metadata embedded in an uploaded image (IPSW, COREIMG, CLBI, UFD, or extension). For an encrypted image, supply `password` to decrypt it. Set `extended` to also resolve the matching supported device model.
//
image_firmware_info_t* ImagesAPI_v3GetImageFirmwareInfo(apiClient_t *apiClient, char *imageId, get_firmware_info_body_t *get_firmware_info_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**imageId** | **char \*** |  | 
**get_firmware_info_body** | **[get_firmware_info_body_t](get_firmware_info_body.md) \*** | Optional decryption password and extended-info flag. | [optional] 

### Return type

[image_firmware_info_t](image_firmware_info.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ImagesAPI_v3GetInstallFirmwareStatus**
```c
// Get install-firmware task status
//
// Returns the current status of a firmware installation task previously created via [`installFirmware`](#operation/installFirmware). Clients should poll this endpoint until `status` is `complete` or `error`.
//
install_firmware_status_response_t* ImagesAPI_v3GetInstallFirmwareStatus(apiClient_t *apiClient, char *taskId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**taskId** | **char \*** |  | 

### Return type

[install_firmware_status_response_t](install_firmware_status_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ImagesAPI_v3InstallFirmware**
```c
// Install firmware cluster-wide
//
// Installs an uploaded firmware image for cluster-wide use. On success the source Image is deleted from the Images store, since ownership transfers to the firmware service. Installation runs asynchronously; this endpoint returns a `taskId` that callers must poll via [`getInstallFirmwareStatus`](#operation/getInstallFirmwareStatus).   **This is step 3 of the firmware-install workflow:**   1. [`createImage`](#operation/createImage) with `{ name, type: 'fw' }` → returns an `imageId`.   2. [`uploadImageData`](#operation/uploadImageData) with the firmware file → uploads contents.   3. **`installFirmware`** with `{ imageId }` → returns a `taskId`.   4. [`getInstallFirmwareStatus`](#operation/getInstallFirmwareStatus) → poll until `status` is `complete` or `error`.   Large firmware blobs (~10 GB) are supported; installation has a 45-minute server-side timeout.
//
install_firmware_response_t* ImagesAPI_v3InstallFirmware(apiClient_t *apiClient, install_firmware_body_t *install_firmware_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**install_firmware_body** | **[install_firmware_body_t](install_firmware_body.md) \*** |  | 

### Return type

[install_firmware_response_t](install_firmware_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ImagesAPI_v3InstallFirmwareAssets**
```c
// Install firmware assets cluster-wide
//
// Installs an uploaded firmware-assets JSON blob for cluster-wide use. On success the source Image is deleted from the Images store. The blob is forwarded to the firmware service, which merges it into the cluster-wide firmware-assets manifest.   **This is step 3 of the firmware-assets-install workflow:**   1. [`createImage`](#operation/createImage) with `{ name: 'fcs-keys.json', type: 'fwasset' }` → returns an `imageId`.   2. [`uploadImageData`](#operation/uploadImageData) with the assets file → uploads contents.   3. **`installFirmwareAssets`** with `{ imageId }` → installs the assets.   Unlike [`installFirmware`](#operation/installFirmware), this endpoint completes synchronously and returns the firmware service's response message directly; there is no task to poll.
//
install_firmware_assets_response_t* ImagesAPI_v3InstallFirmwareAssets(apiClient_t *apiClient, install_firmware_assets_body_t *install_firmware_assets_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**install_firmware_assets_body** | **[install_firmware_assets_body_t](install_firmware_assets_body.md) \*** |  | 

### Return type

[install_firmware_assets_response_t](install_firmware_assets_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ImagesAPI_v3ListImages**
```c
// List image metadata
//
// Returns metadata for all authenticated user images. Optionally filtered by project. File contents are not returned; use [`downloadImageFile`](#operation/downloadImageFile) to fetch contents.
//
image_list_t* ImagesAPI_v3ListImages(apiClient_t *apiClient, double *limit, double *offset, char *projectId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**limit** | **double \*** | Maximum number of results to return. | [optional] [default to 100]
**offset** | **double \*** | Number of results to skip. | [optional] [default to 0]
**projectId** | **char \*** | Filter results to a single project. | [optional] 

### Return type

[image_list_t](image_list.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ImagesAPI_v3UploadImageData**
```c
// Upload image file contents
//
// Uploads file contents into an Image previously created via [`createImage`](#operation/createImage). The image's owning project must have sufficient remaining quota. Accepts multipart/form-data; the optional `corelliumChecksum` query parameter, when supplied, is verified against the upload.
//
image_t* ImagesAPI_v3UploadImageData(apiClient_t *apiClient, char *imageId, binary_t* file, char *corelliumChecksum);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**imageId** | **char \*** |  | 
**file** | **binary_t*** |  | 
**corelliumChecksum** | **char \*** | Expected Corellium hash checksum of the upload. | [optional] 

### Return type

[image_t](image.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: multipart/form-data
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

