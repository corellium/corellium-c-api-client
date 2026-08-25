# ExtensionsV1API

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ExtensionsV1API_v1DeleteExtension**](ExtensionsV1API.md#ExtensionsV1API_v1DeleteExtension) | **DELETE** /v1/extensions/{extensionId} | Delete an existing extension
[**ExtensionsV1API_v1GetExtensionById**](ExtensionsV1API.md#ExtensionsV1API_v1GetExtensionById) | **GET** /v1/extensions/{extensionId} | Get extension by id
[**ExtensionsV1API_v1GetExtensions**](ExtensionsV1API.md#ExtensionsV1API_v1GetExtensions) | **GET** /v1/extensions | Get all extensions
[**ExtensionsV1API_v1LoadExtension**](ExtensionsV1API.md#ExtensionsV1API_v1LoadExtension) | **POST** /v1/extensions | Load an extension
[**ExtensionsV1API_v1ParseExtensionJson**](ExtensionsV1API.md#ExtensionsV1API_v1ParseExtensionJson) | **POST** /v1/extensions/parse/extension.json | Validates extension.json
[**ExtensionsV1API_v1UpdateExtension**](ExtensionsV1API.md#ExtensionsV1API_v1UpdateExtension) | **PUT** /v1/extensions/{extensionId} | Update an existing extension


# **ExtensionsV1API_v1DeleteExtension**
```c
// Delete an existing extension
//
void ExtensionsV1API_v1DeleteExtension(apiClient_t *apiClient, char *extensionId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**extensionId** | **char \*** | Extension ID | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ExtensionsV1API_v1GetExtensionById**
```c
// Get extension by id
//
extension_v1_t* ExtensionsV1API_v1GetExtensionById(apiClient_t *apiClient, char *extensionId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**extensionId** | **char \*** | Extension Id | 

### Return type

[extension_v1_t](extension_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ExtensionsV1API_v1GetExtensions**
```c
// Get all extensions
//
list_t* ExtensionsV1API_v1GetExtensions(apiClient_t *apiClient, double limit, double offset, char *if_none_match);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**limit** | **double** | limit for pagination results, defaults to 20 | [optional] 
**offset** | **double** | offset for pagination results, defaults to 0 | [optional] 
**if_none_match** | **char \*** | sha256sum of the last response with the same parameters (optional) | [optional] 

### Return type

[list_t](extension_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ExtensionsV1API_v1LoadExtension**
```c
// Load an extension
//
extension_v1_t* ExtensionsV1API_v1LoadExtension(apiClient_t *apiClient, v1_load_extension_parameters_t *v1_load_extension_parameters);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**v1_load_extension_parameters** | **[v1_load_extension_parameters_t](v1_load_extension_parameters.md) \*** | application/json | 

### Return type

[extension_v1_t](extension_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ExtensionsV1API_v1ParseExtensionJson**
```c
// Validates extension.json
//
object_t* ExtensionsV1API_v1ParseExtensionJson(apiClient_t *apiClient, extension_v1_t *extension_v1);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**extension_v1** | **[extension_v1_t](extension_v1.md) \*** | extension.json contents | 

### Return type

[object_t](object.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ExtensionsV1API_v1UpdateExtension**
```c
// Update an existing extension
//
void ExtensionsV1API_v1UpdateExtension(apiClient_t *apiClient, char *extensionId, update_extension_t *update_extension);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**extensionId** | **char \*** | Extension ID | 
**update_extension** | **[update_extension_t](update_extension.md) \*** | application/json | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

