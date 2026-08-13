# DomainAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**DomainAPI_v3CreateDomainWelcomeMessage**](DomainAPI.md#DomainAPI_v3CreateDomainWelcomeMessage) | **POST** /v3/domain/welcome | Create a welcome message for a domain
[**DomainAPI_v3DeleteDomainWelcomeMessage**](DomainAPI.md#DomainAPI_v3DeleteDomainWelcomeMessage) | **DELETE** /v3/domain/welcome | Delete the welcome message for the authenticated user&#39;s domain
[**DomainAPI_v3GetDomainImageUpload**](DomainAPI.md#DomainAPI_v3GetDomainImageUpload) | **GET** /v3/domain/image-upload/{type}/{imageId}/{name} | Get a domain-level image upload
[**DomainAPI_v3GetDomainWelcomeMessage**](DomainAPI.md#DomainAPI_v3GetDomainWelcomeMessage) | **GET** /v3/domain/welcome | Get the welcome message for the authenticated user&#39;s domain
[**DomainAPI_v3PatchDomainWelcomeMessage**](DomainAPI.md#DomainAPI_v3PatchDomainWelcomeMessage) | **PATCH** /v3/domain/welcome | Update a welcome message for a domain
[**DomainAPI_v3UploadDomainImage**](DomainAPI.md#DomainAPI_v3UploadDomainImage) | **PUT** /v3/domain/image-upload/{type}/{imageId}/{name} | Domain-wide file upload


# **DomainAPI_v3CreateDomainWelcomeMessage**
```c
// Create a welcome message for a domain
//
// Creates a new welcome message for the authenticated user's domain admin, or updates the existing one. The message is sanitized to prevent XSS.
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
// Get a domain-level image upload
//
binary_t** DomainAPI_v3GetDomainImageUpload(apiClient_t *apiClient, char *type, char *imageId, char *name, double *resumableChunkNumber);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**type** | **char \*** | Image type (e.g. extension, firmware). | 
**imageId** | **char \*** | Image identifier. | 
**name** | **char \*** | Image filename. | 
**resumableChunkNumber** | **double \*** | Resumable.js chunk number. When present, checks whether the chunk exists; returns 204 if not yet uploaded. | [optional] 

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
// Updates a new welcome message for the authenticated user's domain admin, or updates the existing one. The message is sanitized to prevent XSS.
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

# **DomainAPI_v3UploadDomainImage**
```c
// Domain-wide file upload
//
void DomainAPI_v3UploadDomainImage(apiClient_t *apiClient, char *type, char *imageId, char *name, char *flavor, double *resumableChunkNumber, double *resumableChunkSize, double *resumableCurrentChunkSize, double *resumableTotalSize, double *resumableTotalChunks, binary_t* body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**type** | **char \*** | Image type (e.g. extension, firmware). | 
**imageId** | **char \*** | Image identifier. | 
**name** | **char \*** | Image filename. | 
**flavor** | **char \*** | Flavor identifier. | [optional] 
**resumableChunkNumber** | **double \*** | Resumable.js chunk number (1-based). | [optional] 
**resumableChunkSize** | **double \*** | Resumable.js size of each chunk in bytes. | [optional] 
**resumableCurrentChunkSize** | **double \*** | Resumable.js size of the current chunk in bytes. | [optional] 
**resumableTotalSize** | **double \*** | Resumable.js total file size in bytes. | [optional] 
**resumableTotalChunks** | **double \*** | Resumable.js total number of chunks. | [optional] 
**body** | **binary_t*** |  | [optional] 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/octet-stream
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

