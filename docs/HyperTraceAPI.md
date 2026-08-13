# HyperTraceAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**HyperTraceAPI_v3BtracePreauthorize**](HyperTraceAPI.md#HyperTraceAPI_v3BtracePreauthorize) | **GET** /v3/instances/{instanceId}/btrace-authorize | Pre-authorize a btrace download
[**HyperTraceAPI_v3ClearHyperTrace**](HyperTraceAPI.md#HyperTraceAPI_v3ClearHyperTrace) | **DELETE** /v3/instances/{instanceId}/btrace | Clear HyperTrace logs
[**HyperTraceAPI_v3GetInstanceKcrange**](HyperTraceAPI.md#HyperTraceAPI_v3GetInstanceKcrange) | **GET** /v3/instances/{instanceId}/btrace-kcrange | Get Kernel extension ranges
[**HyperTraceAPI_v3StartHyperTrace**](HyperTraceAPI.md#HyperTraceAPI_v3StartHyperTrace) | **POST** /v3/instances/{instanceId}/btrace/enable | Start HyperTrace on an instance
[**HyperTraceAPI_v3StopHyperTrace**](HyperTraceAPI.md#HyperTraceAPI_v3StopHyperTrace) | **POST** /v3/instances/{instanceId}/btrace/disable | Stop HyperTrace on an instance.


# **HyperTraceAPI_v3BtracePreauthorize**
```c
// Pre-authorize a btrace download
//
token_t* HyperTraceAPI_v3BtracePreauthorize(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 

### Return type

[token_t](token.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **HyperTraceAPI_v3ClearHyperTrace**
```c
// Clear HyperTrace logs
//
void HyperTraceAPI_v3ClearHyperTrace(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **HyperTraceAPI_v3GetInstanceKcrange**
```c
// Get Kernel extension ranges
//
list_t* HyperTraceAPI_v3GetInstanceKcrange(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 

### Return type

[list_t](kcrange.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **HyperTraceAPI_v3StartHyperTrace**
```c
// Start HyperTrace on an instance
//
void HyperTraceAPI_v3StartHyperTrace(apiClient_t *apiClient, char *instanceId, enable_btrace_body_t *enable_btrace_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**enable_btrace_body** | **[enable_btrace_body_t](enable_btrace_body.md) \*** |  | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **HyperTraceAPI_v3StopHyperTrace**
```c
// Stop HyperTrace on an instance.
//
void HyperTraceAPI_v3StopHyperTrace(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

