# DomainAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**DomainAPI_v3CreateDomainWelcomeMessage**](DomainAPI.md#DomainAPI_v3CreateDomainWelcomeMessage) | **POST** /v3/domain/welcome | Create a welcome message for a domain
[**DomainAPI_v3DeleteDomainWelcomeMessage**](DomainAPI.md#DomainAPI_v3DeleteDomainWelcomeMessage) | **DELETE** /v3/domain/welcome | Delete the welcome message for the authenticated user&#39;s domain
[**DomainAPI_v3GetDomainImageUpload**](DomainAPI.md#DomainAPI_v3GetDomainImageUpload) | **GET** /v3/domain/image-upload/{type}/{imageId}/{name} | Get image upload status
[**DomainAPI_v3GetDomainWelcomeMessage**](DomainAPI.md#DomainAPI_v3GetDomainWelcomeMessage) | **GET** /v3/domain/welcome | Get the welcome message for the authenticated user&#39;s domain
[**DomainAPI_v3ListDomainSoftware**](DomainAPI.md#DomainAPI_v3ListDomainSoftware) | **GET** /v3/domain/software | List domain-level firmware images
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
// **Required role:** Domain administrator.  Delete the welcome message for the authenticated user's domain.  Deletes are idempotent: a domain with no welcome message is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing.
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
// **Required role:** Domain administrator on on-site deployments; cloud administrator on cloud deployments.  Checks the progress of a chunked upload made with `v3PutDomainImageUpload`, or downloads the finished file. With chunk parameters (`resumableChunkNumber` and friends) it returns 200 if that chunk is already stored and 204 if it still needs to be sent; without them it downloads the image file.
//
binary_t** DomainAPI_v3GetDomainImageUpload(apiClient_t *apiClient, char *type, char *imageId, char *name, double *resumableChunkNumber);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
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

# **DomainAPI_v3ListDomainSoftware**
```c
// List domain-level firmware images
//
// **Required role:** Domain administrator.  Lists the firmware images uploaded at domain level (not in a project or instance), one entry per device model. Requires a domain administrator. Use it to find the `imageId` of a domain firmware upload, for example to delete it with `DELETE /v3/images/{imageId}`. These images also appear in `GET /v3/models/{model}/software` for the matching model.
//
domain_software_list_t* DomainAPI_v3ListDomainSoftware(apiClient_t *apiClient, double *limit, double *offset);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**limit** | **double \*** | Most results to return in one page. Whole number from 1 to 1000; defaults to 100. A value outside that range is rejected with 400. | [optional] [default to 100]
**offset** | **double \*** | How many results to skip before this page starts; defaults to 0. To get the next page, add &#x60;limit&#x60; to the previous &#x60;offset&#x60;. | [optional] [default to 0]

### Return type

[domain_software_list_t](domain_software_list.md) *


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
// **Required role:** Domain administrator on on-site deployments; cloud administrator on cloud deployments.  Uploads one chunk of a file as a domain-level image: one that belongs to no project or instance and is available across your domain. Requires a domain administrator (on-site) or cloud administrator. Works like `v3PutProjectImageUpload`: you choose the image ID (a new random UUID), the record is created on the first chunk, and `type` and `name` in the path set the image type and name. A domain-level `fw` image is offered as a choice when anyone in the domain creates a device of the matching model, without an install step. The result is the same as `POST /v3/images` with no `projectId` or `instanceId` followed by `PUT /v3/images/{imageId}/file`, which applies the same administrator rule to chunk uploads.
//
object_t* DomainAPI_v3PutDomainImageUpload(apiClient_t *apiClient, char *type, char *imageId, char *name, binary_t* body, double *resumableChunkNumber, double *resumableChunkSize, double *resumableCurrentChunkSize, double *resumableTotalSize, double *resumableTotalChunks, char *corelliumChecksum, char *flavor, char *x_corellium_image_encoding, int *x_corellium_image_encapsulated, double *x_corellium_total_file_size, char *x_corellium_image_password);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
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

