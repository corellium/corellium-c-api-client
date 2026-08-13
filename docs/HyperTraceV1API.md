# HyperTraceV1API

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**HyperTraceV1API_v1BtracePreauthorize**](HyperTraceV1API.md#HyperTraceV1API_v1BtracePreauthorize) | **GET** /v1/instances/{instanceId}/btrace-authorize | Pre-authorize an btrace download
[**HyperTraceV1API_v1ClearHyperTrace**](HyperTraceV1API.md#HyperTraceV1API_v1ClearHyperTrace) | **DELETE** /v1/instances/{instanceId}/btrace | Clear HyperTrace logs
[**HyperTraceV1API_v1Kcrange**](HyperTraceV1API.md#HyperTraceV1API_v1Kcrange) | **GET** /v1/instances/{instanceId}/btrace-kcrange | Get Kernel extension ranges
[**HyperTraceV1API_v1StartHyperTrace**](HyperTraceV1API.md#HyperTraceV1API_v1StartHyperTrace) | **POST** /v1/instances/{instanceId}/btrace/enable | Start HyperTrace on an instance
[**HyperTraceV1API_v1StopHyperTrace**](HyperTraceV1API.md#HyperTraceV1API_v1StopHyperTrace) | **POST** /v1/instances/{instanceId}/btrace/disable | Stop HyperTrace on an instance.


# **HyperTraceV1API_v1BtracePreauthorize**
```c
// Pre-authorize an btrace download
//
token_v1_t* HyperTraceV1API_v1BtracePreauthorize(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 

### Return type

[token_v1_t](token_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **HyperTraceV1API_v1ClearHyperTrace**
```c
// Clear HyperTrace logs
//
void HyperTraceV1API_v1ClearHyperTrace(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **HyperTraceV1API_v1Kcrange**
```c
// Get Kernel extension ranges
//
list_t* HyperTraceV1API_v1Kcrange(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 

### Return type

[list_t](kcrange_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **HyperTraceV1API_v1StartHyperTrace**
```c
// Start HyperTrace on an instance
//
void HyperTraceV1API_v1StartHyperTrace(apiClient_t *apiClient, char *instanceId, btrace_enable_options_t *btrace_enable_options);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 
**btrace_enable_options** | **[btrace_enable_options_t](btrace_enable_options.md) \*** |  | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **HyperTraceV1API_v1StopHyperTrace**
```c
// Stop HyperTrace on an instance.
//
void HyperTraceV1API_v1StopHyperTrace(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

