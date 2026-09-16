# DomainAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**DomainAPI_v3CreateDomainWelcomeMessage**](DomainAPI.md#DomainAPI_v3CreateDomainWelcomeMessage) | **POST** /v3/domain/welcome | Create a welcome message for a domain
[**DomainAPI_v3DeleteDomainWelcomeMessage**](DomainAPI.md#DomainAPI_v3DeleteDomainWelcomeMessage) | **DELETE** /v3/domain/welcome | Delete the welcome message for the authenticated user&#39;s domain
[**DomainAPI_v3GetDomainImageUpload**](DomainAPI.md#DomainAPI_v3GetDomainImageUpload) | **GET** /v3/domain/image-upload/{type}/{imageId}/{name} | Get image upload status
[**DomainAPI_v3GetDomainWelcomeMessage**](DomainAPI.md#DomainAPI_v3GetDomainWelcomeMessage) | **GET** /v3/domain/welcome | Get the welcome message for the authenticated user&#39;s domain
[**DomainAPI_v3PatchDomainWelcomeMessage**](DomainAPI.md#DomainAPI_v3PatchDomainWelcomeMessage) | **PATCH** /v3/domain/welcome | Update a welcome message for a domain
[**DomainAPI_v3PutDomainImageUpload**](DomainAPI.md#DomainAPI_v3PutDomainImageUpload) | **PUT** /v3/domain/image-upload/{type}/{imageId}/{name} | Upload image chunk


# **DomainAPI_v3CreateDomainWelcomeMessage**
```c
// Create a welcome message for a domain
//
// **Required role:** Domain administrator.  Creates a new welcome message for the authenticated user's domain admin, or updates the existing one. The message is sanitized to prevent XSS.
//
domain_welcome_message_response_t* DomainAPI_v3CreateDomainWelcomeMessage(apiClient_t *apiClient, set_domain_welcome_message_body_t *set_domain_welcome_message_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**set_domain_welcome_message_body** | **[set_domain_welcome_message_body_t](set_domain_welcome_message_body.md) \*** |  | 

### Return type

[domain_welcome_message_response_t](domain_welcome_message_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DomainAPI_v3DeleteDomainWelcomeMessage**
```c
// Delete the welcome message for the authenticated user's domain
//
// **Required role:** Domain administrator.  Delete the welcome message for the authenticated user's domain.
//
void DomainAPI_v3DeleteDomainWelcomeMessage(apiClient_t *apiClient);
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

# **DomainAPI_v3GetDomainImageUpload**
```c
// Get image upload status
//
// **Required role:** Domain administrator on on-site deployments; cloud administrator on cloud deployments.  Check resumable upload status for a domain-wide image or download the image file.
//
binary_t** DomainAPI_v3GetDomainImageUpload(apiClient_t *apiClient, char *type, char *imageId, char *name, double *resumableChunkNumber);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
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

# **DomainAPI_v3GetDomainWelcomeMessage**
```c
// Get the welcome message for the authenticated user's domain
//
// Retrieves the welcome message for the domain.
//
domain_welcome_message_response_t* DomainAPI_v3GetDomainWelcomeMessage(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[domain_welcome_message_response_t](domain_welcome_message_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DomainAPI_v3PatchDomainWelcomeMessage**
```c
// Update a welcome message for a domain
//
// **Required role:** Domain administrator.  Updates a new welcome message for the authenticated user's domain admin, or updates the existing one. The message is sanitized to prevent XSS.
//
domain_welcome_message_response_t* DomainAPI_v3PatchDomainWelcomeMessage(apiClient_t *apiClient, patch_domain_welcome_message_body_t *patch_domain_welcome_message_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**patch_domain_welcome_message_body** | **[patch_domain_welcome_message_body_t](patch_domain_welcome_message_body.md) \*** |  | [optional] 

### Return type

[domain_welcome_message_response_t](domain_welcome_message_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DomainAPI_v3PutDomainImageUpload**
```c
// Upload image chunk
//
// **Required role:** Domain administrator on on-site deployments; cloud administrator on cloud deployments.  Upload a chunk of a domain-wide image using the resumable upload protocol. Creates the image record on the first chunk if it does not yet exist.
//
object_t* DomainAPI_v3PutDomainImageUpload(apiClient_t *apiClient, char *type, char *imageId, char *name, binary_t* body, double *resumableChunkNumber, double *resumableChunkSize, double *resumableCurrentChunkSize, double *resumableTotalSize, double *resumableTotalChunks, char *corelliumChecksum, char *flavor, char *x_corellium_image_encoding, int *x_corellium_image_encapsulated, double *x_corellium_total_file_size, char *x_corellium_image_password);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**type** | **char \*** | Image type. | 
**imageId** | **char \*** | Client-generated image identifier. The image record is created on the first chunk. | 
**name** | **char \*** | URL-encoded image filename. | 
**body** | **binary_t*** |  | 
**resumableChunkNumber** | **double \*** | Chunk sequence number. | [optional] 
**resumableChunkSize** | **double \*** | Size of each chunk. | [optional] 
**resumableCurrentChunkSize** | **double \*** | Size of the current chunk. | [optional] 
**resumableTotalSize** | **double \*** | Total file size. | [optional] 
**resumableTotalChunks** | **double \*** | Total number of chunks. | [optional] 
**corelliumChecksum** | **char \*** | Corellium checksum. Required for firmware uploads in airgapped deployments. | [optional] 
**flavor** | **char \*** | Flavor identifier to associate with the image. | [optional] 
**x_corellium_image_encoding** | **char \*** | How the uploaded file is stored. Set on the first chunk, when the image record is created. | [optional] 
**x_corellium_image_encapsulated** | **int \*** | Whether the uploaded file is an archive the coordinator should unpack. Set false to store the file as uploaded. Set on the first chunk, when the image record is created. | [optional] 
**x_corellium_total_file_size** | **double \*** | Total size of the whole file in bytes. Preferred over Content-Length for the pre-flight image-pool space check on on-site clusters, which is what produces the 507 response. | [optional] 
**x_corellium_image_password** | **char \*** | Password used to open a password-protected image during post-upload validation. | [optional] 

### Return type

[object_t](object.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/octet-stream
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

