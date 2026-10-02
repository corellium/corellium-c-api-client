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
// **Required role:** Domain administrator.  Deletes the extension identified by the given extension ID. Available on on-site deployments only. Deletion is asynchronous: the extension is marked `deleting` and the call returns 204 before removal completes.  Deletes are idempotent: an unknown extension ID, or an extension that was already deleted, is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing. A repeat therefore returns 204 both while the record is still present in the `deleting` state and after it has disappeared.
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
// **Required role:** Domain administrator.  Returns one installed extension, including whether it is enabled and the device models (flavors) it adds. Requires a domain administrator. Available on on-site deployments only.
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
// **Required role:** Domain administrator.  Lists the extensions installed on this deployment. An extension adds new device models (for example an IoT board such as a Raspberry Pi 4) that you can then create devices from; each one is defined by an `extension.json` file listing its models, CPU cores, memory and boot options. Requires a domain administrator. Available on on-site deployments only. The response carries an ETag; send it back as `If-None-Match` to get 304 when nothing changed.
//
extension_list_t* ExtensionsAPI_v3ListExtensions(apiClient_t *apiClient, double *limit, double *offset, char *if_none_match);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**limit** | **double \*** | Most results to return in one page. Whole number from 1 to 1000; defaults to 100. A value outside that range is rejected with 400. | [optional] [default to 100]
**offset** | **double \*** | How many results to skip before this page starts; defaults to 0. To get the next page, add &#x60;limit&#x60; to the previous &#x60;offset&#x60;. | [optional] [default to 0]
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
// **Required role:** Domain administrator.  Installs an extension so its device models become available. **Steps:** (1) optionally check your `extension.json` with `v3ParseExtensionJson`; (2) upload the extension file with `POST /v3/images` using `type: \"extension\"`; (3) call this with the returned `imageId`. The definition is read from the uploaded file, so only the image ID is sent. The new models then appear in `GET /v3/models`. Requires a domain administrator. Available on on-site deployments only.
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
// **Required role:** Domain administrator.  Checks an `extension.json` document before you upload it, and returns the normalised definition the platform would use (with defaults filled in). Returns 400 with the problem if the document is invalid. Nothing is installed. Requires a domain administrator. Available on on-site deployments only.
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
// **Required role:** Domain administrator.  Turns an installed extension on or off with `enabled`. While it is off, devices that use its models cannot be created or started. Requires a domain administrator. Available on on-site deployments only.
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

