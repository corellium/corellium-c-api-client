# ImagesAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ImagesAPI_v3CreateImage**](ImagesAPI.md#ImagesAPI_v3CreateImage) | **POST** /v3/images | Create an image
[**ImagesAPI_v3DeleteImage**](ImagesAPI.md#ImagesAPI_v3DeleteImage) | **DELETE** /v3/images/{imageId} | Delete an image
[**ImagesAPI_v3GetImage**](ImagesAPI.md#ImagesAPI_v3GetImage) | **GET** /v3/images/{imageId} | Get image metadata
[**ImagesAPI_v3GetImageChunk**](ImagesAPI.md#ImagesAPI_v3GetImageChunk) | **GET** /v3/images/{imageId}/file | Check whether an image chunk was already uploaded
[**ImagesAPI_v3GetImageFirmwareInfo**](ImagesAPI.md#ImagesAPI_v3GetImageFirmwareInfo) | **POST** /v3/images/{imageId}/fwinfo | Get firmware info embedded in an image
[**ImagesAPI_v3GetInstallFirmwareStatus**](ImagesAPI.md#ImagesAPI_v3GetInstallFirmwareStatus) | **GET** /v3/images/install-firmware/{taskId} | Get install-firmware task status
[**ImagesAPI_v3InstallFirmware**](ImagesAPI.md#ImagesAPI_v3InstallFirmware) | **POST** /v3/images/install-firmware | Install firmware cluster-wide
[**ImagesAPI_v3InstallFirmwareAssets**](ImagesAPI.md#ImagesAPI_v3InstallFirmwareAssets) | **POST** /v3/images/install-firmware-assets | Install firmware assets cluster-wide
[**ImagesAPI_v3ListImages**](ImagesAPI.md#ImagesAPI_v3ListImages) | **GET** /v3/images | List image metadata
[**ImagesAPI_v3UploadImageChunk**](ImagesAPI.md#ImagesAPI_v3UploadImageChunk) | **PUT** /v3/images/{imageId}/file | Upload one chunk of an image file
[**ImagesAPI_v3UploadImageData**](ImagesAPI.md#ImagesAPI_v3UploadImageData) | **POST** /v3/images/{imageId} | Upload image file contents


# **ImagesAPI_v3CreateImage**
```c
// Create an image
//
// Creates a new Image record, optionally uploading file contents in the same request.   Two content types are supported:   - `application/json`: creates metadata only. The caller subsequently uploads the file via     [`uploadImageData`](#tag/images/POST/v3/images/{imageId}). Returns 201.   - `multipart/form-data`: creates metadata and uploads the file in a single request. Returns 200.   The `fullPath` field references a file already present on the server's local filesystem and bypasses the upload step entirely; this is intended for cluster-internal use.   For firmware images, this is step 1 of the install workflow — see [`installFirmware`](#tag/images/POST/v3/images/install-firmware) or [`installFirmwareAssets`](#tag/images/POST/v3/images/install-firmware-assets).
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
// Permanently deletes the image. This action cannot be undone. Deleting an already-deleted image returns 204.
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
// Returns metadata for a single image. File contents are not returned by this endpoint.
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

# **ImagesAPI_v3GetImageChunk**
```c
// Check whether an image chunk was already uploaded
//
// Probes whether a single chunk of a chunked upload is already stored, so an interrupted upload can resume without re-sending data. Used together with [`uploadImageChunk`](#tag/images/PUT/v3/images/{imageId}/file).   Returns 200 when the chunk is present and 204 when it still needs to be uploaded. The chunk is identified exactly as in the upload request, by `resumableChunkNumber`, `resumableChunkSize` and `resumableCurrentChunkSize`, all of which are required. The image must already exist; an unknown `imageId` is a 404 rather than a 204.
//
object_t* ImagesAPI_v3GetImageChunk(apiClient_t *apiClient, char *imageId, double *resumableChunkNumber, double *resumableChunkSize, double *resumableCurrentChunkSize);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**imageId** | **char \*** |  | 
**resumableChunkNumber** | **double \*** | Chunk sequence number. | 
**resumableChunkSize** | **double \*** | Size of each chunk. | 
**resumableCurrentChunkSize** | **double \*** | Size of the current chunk. | 

### Return type

[object_t](object.md) *


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
// Returns the current status of a firmware installation task previously created via [`installFirmware`](#tag/images/POST/v3/images/install-firmware). Clients should poll this endpoint until `status` is `complete` or `error`.
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
// Installs an uploaded firmware image for cluster-wide use. On success the source Image is deleted from the Images store, since ownership transfers to the firmware service. Installation runs asynchronously; this endpoint returns a `taskId` that callers must poll via [`getInstallFirmwareStatus`](#tag/images/GET/v3/images/install-firmware/{taskId}).   **This is step 3 of the firmware-install workflow:**   1. [`createImage`](#tag/images/POST/v3/images) with `{ name, type: 'fw' }` → returns an `imageId`.   2. [`uploadImageData`](#tag/images/POST/v3/images/{imageId}) with the firmware file → uploads contents.   3. **`installFirmware`** with `{ imageId }` → returns a `taskId`.   4. [`getInstallFirmwareStatus`](#tag/images/GET/v3/images/install-firmware/{taskId}) → poll until `status` is `complete` or `error`.   Large firmware blobs (~10 GB) are supported; installation has a 45-minute server-side timeout.
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
// Installs an uploaded firmware-assets JSON blob for cluster-wide use. On success the source Image is deleted from the Images store. The blob is forwarded to the firmware service, which merges it into the cluster-wide firmware-assets manifest.   **This is step 3 of the firmware-assets-install workflow:**   1. [`createImage`](#tag/images/POST/v3/images) with `{ name: 'fcs-keys.json', type: 'fwasset' }` → returns an `imageId`.   2. [`uploadImageData`](#tag/images/POST/v3/images/{imageId}) with the assets file → uploads contents.   3. **`installFirmwareAssets`** with `{ imageId }` → installs the assets.   Unlike [`installFirmware`](#tag/images/POST/v3/images/install-firmware), this endpoint completes synchronously and returns the firmware service's response message directly; there is no task to poll.
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
// Returns metadata for all authenticated user images. Optionally filtered by project. File contents are not returned by this endpoint.
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

# **ImagesAPI_v3UploadImageChunk**
```c
// Upload one chunk of an image file
//
// Uploads a single chunk of an Image previously created via [`createImage`](#tag/images/POST/v3/images), using the resumable upload protocol. This is the recommended way to upload large images: the transfer survives interruptions, because any chunk can be re-sent and already-stored chunks can be skipped.   **Chunked upload workflow:**   1. [`createImage`](#tag/images/POST/v3/images) with `{ name, type, encoding }` → returns an `imageId`.   2. Split the file into fixed-size chunks and **`uploadImageChunk`** each one with the      `resumable*` query parameters describing it. Chunks may be uploaded in any order and      concurrently.   3. Optionally probe a chunk with [`getImageChunk`](#tag/images/GET/v3/images/{imageId}/file) before      (re-)sending it, so an interrupted upload only re-sends what is missing.   The image is finalized automatically by the request that completes the chunk set, so the last chunk to arrive also validates `corelliumChecksum` (when supplied) and runs the firmware post-processing. Re-sending a chunk that was already stored is safe. If the upload fails for any reason other than a retryable transport error, the partially uploaded image is deleted, so the client must create a new image record before retrying.   The image's `encoding` and `encapsulated` settings are fixed when the record is created by [`createImage`](#tag/images/POST/v3/images) and cannot be changed by a chunk request.
//
void ImagesAPI_v3UploadImageChunk(apiClient_t *apiClient, char *imageId, double *resumableChunkNumber, double *resumableChunkSize, double *resumableCurrentChunkSize, double *resumableTotalSize, double *resumableTotalChunks, binary_t* body, char *resumableIdentifier, char *resumableFilename, char *resumableRelativePath, char *resumableType, char *corelliumChecksum, char *x_corellium_total_file_size);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**imageId** | **char \*** |  | 
**resumableChunkNumber** | **double \*** | Chunk sequence number. | 
**resumableChunkSize** | **double \*** | Size of each chunk. | 
**resumableCurrentChunkSize** | **double \*** | Size of the current chunk. | 
**resumableTotalSize** | **double \*** | Total file size. | 
**resumableTotalChunks** | **double \*** | Total number of chunks. | 
**body** | **binary_t*** |  | 
**resumableIdentifier** | **char \*** | Client-side identifier of the file being uploaded. | [optional] 
**resumableFilename** | **char \*** | Original filename. | [optional] 
**resumableRelativePath** | **char \*** | Relative path. | [optional] 
**resumableType** | **char \*** | MIME type. | [optional] 
**corelliumChecksum** | **char \*** | Expected Corellium checksum of the complete file, formatted &#x60;algorithm$blockSize$hash&#x60;. When supplied, every chunk is re-hashed and the upload is rejected (and the image removed) unless the recomputed checksum matches. The chunk size used for the upload must equal the block size embedded in the checksum. Required for &#x60;fw&#x60; uploads on airgapped deployments. | [optional] 
**x_corellium_total_file_size** | **char \*** | Total size of the whole file in bytes. Send it on every chunk so the image-pool pre-flight check sees the full upload size rather than the size of a single chunk. | [optional] 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/octet-stream
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ImagesAPI_v3UploadImageData**
```c
// Upload image file contents
//
// Uploads file contents into an Image previously created via [`createImage`](#tag/images/POST/v3/images). The image's owning project must have sufficient remaining quota. Accepts multipart/form-data; the optional `corelliumChecksum` query parameter, when supplied, is verified against the upload.   This endpoint uploads the whole file in a single request. For large images (firmware in particular) upload the file in chunks instead — see [`uploadImageChunk`](#tag/images/PUT/v3/images/{imageId}/file).
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

