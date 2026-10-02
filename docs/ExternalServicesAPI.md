# ExternalServicesAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ExternalServicesAPI_deleteExternalService**](ExternalServicesAPI.md#ExternalServicesAPI_deleteExternalService) | **DELETE** /{apiVersion}/external-services/{serviceName}/{path} | Proxy a DELETE request to an external service
[**ExternalServicesAPI_getExternalService**](ExternalServicesAPI.md#ExternalServicesAPI_getExternalService) | **GET** /{apiVersion}/external-services/{serviceName}/{path} | Proxy a GET request to an external service
[**ExternalServicesAPI_patchExternalService**](ExternalServicesAPI.md#ExternalServicesAPI_patchExternalService) | **PATCH** /{apiVersion}/external-services/{serviceName}/{path} | Proxy a PATCH request to an external service
[**ExternalServicesAPI_postExternalService**](ExternalServicesAPI.md#ExternalServicesAPI_postExternalService) | **POST** /{apiVersion}/external-services/{serviceName}/{path} | Proxy a POST request to an external service
[**ExternalServicesAPI_putExternalService**](ExternalServicesAPI.md#ExternalServicesAPI_putExternalService) | **PUT** /{apiVersion}/external-services/{serviceName}/{path} | Proxy a PUT request to an external service


# **ExternalServicesAPI_deleteExternalService**
```c
// Proxy a DELETE request to an external service
//
// Forwards this request to an optional external service connected to the platform (named by `serviceName`, for example `apps`), passing along the rest of the path, and returns that service's response unchanged. What each path does is defined by the external service, not by this API. Returns 503 if the service is not available on this deployment or cannot be reached.
//
void ExternalServicesAPI_deleteExternalService(apiClient_t *apiClient, char *apiVersion, char *serviceName, char *path);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**apiVersion** | **char \*** | API version (e.g. v1, v3). | 
**serviceName** | **char \*** | Target service name. | 
**path** | **char \*** | The path to call on the external service. Slashes are kept as path separators. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ExternalServicesAPI_getExternalService**
```c
// Proxy a GET request to an external service
//
// Forwards this request to an optional external service connected to the platform (named by `serviceName`, for example `apps`), passing along the rest of the path, and returns that service's response unchanged. What each path does is defined by the external service, not by this API. Returns 503 if the service is not available on this deployment or cannot be reached.
//
void ExternalServicesAPI_getExternalService(apiClient_t *apiClient, char *apiVersion, char *serviceName, char *path);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**apiVersion** | **char \*** | API version (e.g. v1, v3). | 
**serviceName** | **char \*** | Target service name. | 
**path** | **char \*** | The path to call on the external service. Slashes are kept as path separators. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ExternalServicesAPI_patchExternalService**
```c
// Proxy a PATCH request to an external service
//
// Forwards this request to an optional external service connected to the platform (named by `serviceName`, for example `apps`), passing along the rest of the path, and returns that service's response unchanged. What each path does is defined by the external service, not by this API. Returns 503 if the service is not available on this deployment or cannot be reached.
//
void ExternalServicesAPI_patchExternalService(apiClient_t *apiClient, char *apiVersion, char *serviceName, char *path);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**apiVersion** | **char \*** | API version (e.g. v1, v3). | 
**serviceName** | **char \*** | Target service name. | 
**path** | **char \*** | The path to call on the external service. Slashes are kept as path separators. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ExternalServicesAPI_postExternalService**
```c
// Proxy a POST request to an external service
//
// Forwards this request to an optional external service connected to the platform (named by `serviceName`, for example `apps`), passing along the rest of the path, and returns that service's response unchanged. What each path does is defined by the external service, not by this API. Returns 503 if the service is not available on this deployment or cannot be reached.
//
void ExternalServicesAPI_postExternalService(apiClient_t *apiClient, char *apiVersion, char *serviceName, char *path);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**apiVersion** | **char \*** | API version (e.g. v1, v3). | 
**serviceName** | **char \*** | Target service name. | 
**path** | **char \*** | The path to call on the external service. Slashes are kept as path separators. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ExternalServicesAPI_putExternalService**
```c
// Proxy a PUT request to an external service
//
// Forwards this request to an optional external service connected to the platform (named by `serviceName`, for example `apps`), passing along the rest of the path, and returns that service's response unchanged. What each path does is defined by the external service, not by this API. Returns 503 if the service is not available on this deployment or cannot be reached.
//
void ExternalServicesAPI_putExternalService(apiClient_t *apiClient, char *apiVersion, char *serviceName, char *path);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**apiVersion** | **char \*** | API version (e.g. v1, v3). | 
**serviceName** | **char \*** | Target service name. | 
**path** | **char \*** | The path to call on the external service. Slashes are kept as path separators. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

