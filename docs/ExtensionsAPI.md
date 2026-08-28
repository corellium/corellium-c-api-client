# ExtensionsAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ExtensionsAPI_v3DeleteExtension**](ExtensionsAPI.md#ExtensionsAPI_v3DeleteExtension) | **DELETE** /v3/extensions/{extensionId} | Delete an existing extension
[**ExtensionsAPI_v3GetExtensionById**](ExtensionsAPI.md#ExtensionsAPI_v3GetExtensionById) | **GET** /v3/extensions/{extensionId} | Get extension by ID
[**ExtensionsAPI_v3ListExtensions**](ExtensionsAPI.md#ExtensionsAPI_v3ListExtensions) | **GET** /v3/extensions | List all extensions
[**ExtensionsAPI_v3LoadExtension**](ExtensionsAPI.md#ExtensionsAPI_v3LoadExtension) | **POST** /v3/extensions | Load an extension
[**ExtensionsAPI_v3ParseExtensionJson**](ExtensionsAPI.md#ExtensionsAPI_v3ParseExtensionJson) | **POST** /v3/extensions/parse/extension.json | Validates extension.json
[**ExtensionsAPI_v3UpdateExtension**](ExtensionsAPI.md#ExtensionsAPI_v3UpdateExtension) | **PUT** /v3/extensions/{extensionId} | Update an existing extension


# **ExtensionsAPI_v3DeleteExtension**
```c
// Delete an existing extension
//
// **Required role:** Domain administrator.  Deletes the extension identified by the given extension ID. Available on on-site deployments only.
//
void ExtensionsAPI_v3DeleteExtension(apiClient_t *apiClient, char *extensionId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**extensionId** | **char \*** | Extension ID. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ExtensionsAPI_v3GetExtensionById**
```c
// Get extension by ID
//
// **Required role:** Domain administrator.  Returns the extension identified by the given extension ID. Available on on-site deployments only.
//
extension_t* ExtensionsAPI_v3GetExtensionById(apiClient_t *apiClient, char *extensionId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**extensionId** | **char \*** | Extension ID. | 

### Return type

[extension_t](extension.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ExtensionsAPI_v3ListExtensions**
```c
// List all extensions
//
// **Required role:** Domain administrator.  Returns a paginated list of extensions available to the authenticated user. Available on on-site deployments only.
//
extension_list_t* ExtensionsAPI_v3ListExtensions(apiClient_t *apiClient, double *limit, double *offset, char *if_none_match);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**limit** | **double \*** | Maximum number of results to return. | [optional] [default to 100]
**offset** | **double \*** | Number of results to skip. | [optional] [default to 0]
**if_none_match** | **char \*** | SHA-256 sum of the last response with the same parameters. | [optional] 

### Return type

[extension_list_t](extension_list.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ExtensionsAPI_v3LoadExtension**
```c
// Load an extension
//
// **Required role:** Domain administrator.  Loads an extension from a previously uploaded image, identified by its image ID. The extension definition is read from the image (its extension.json), so only the image ID is supplied. Available on on-site deployments only.
//
extension_t* ExtensionsAPI_v3LoadExtension(apiClient_t *apiClient, load_extension_body_t *load_extension_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**load_extension_body** | **[load_extension_body_t](load_extension_body.md) \*** |  | 

### Return type

[extension_t](extension.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ExtensionsAPI_v3ParseExtensionJson**
```c
// Validates extension.json
//
// **Required role:** Domain administrator.  Validates and normalises an extension.json document, returning the parsed extension definition. Available on on-site deployments only.
//
object_t* ExtensionsAPI_v3ParseExtensionJson(apiClient_t *apiClient, object_t *body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**body** | **[object_t](object.md) \*** | Contents of the extension.json file. | 

### Return type

[object_t](object.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ExtensionsAPI_v3UpdateExtension**
```c
// Update an existing extension
//
// **Required role:** Domain administrator.  Updates the extension identified by the given extension ID with the supplied definition. Available on on-site deployments only.
//
extension_t* ExtensionsAPI_v3UpdateExtension(apiClient_t *apiClient, char *extensionId, update_extension_body_t *update_extension_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**extensionId** | **char \*** | Extension ID. | 
**update_extension_body** | **[update_extension_body_t](update_extension_body.md) \*** |  | 

### Return type

[extension_t](extension.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

