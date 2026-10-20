# CoreTraceV1API

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**CoreTraceV1API_v1ClearCoreTrace**](CoreTraceV1API.md#CoreTraceV1API_v1ClearCoreTrace) | **DELETE** /v1/instances/{instanceId}/strace | Clear CoreTrace logs
[**CoreTraceV1API_v1ListThreads**](CoreTraceV1API.md#CoreTraceV1API_v1ListThreads) | **GET** /v1/instances/{instanceId}/strace/thread-list | Get Running Threads (CoreTrace)
[**CoreTraceV1API_v1StartCoreTrace**](CoreTraceV1API.md#CoreTraceV1API_v1StartCoreTrace) | **POST** /v1/instances/{instanceId}/strace/enable | Start CoreTrace on an instance
[**CoreTraceV1API_v1StopCoreTrace**](CoreTraceV1API.md#CoreTraceV1API_v1StopCoreTrace) | **POST** /v1/instances/{instanceId}/strace/disable | Stop CoreTrace on an instance.


# **CoreTraceV1API_v1ClearCoreTrace**
```c
// Clear CoreTrace logs
//
void CoreTraceV1API_v1ClearCoreTrace(apiClient_t *apiClient, char *instanceId);
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

# **CoreTraceV1API_v1ListThreads**
```c
// Get Running Threads (CoreTrace)
//
list_t* CoreTraceV1API_v1ListThreads(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 

### Return type

[list_t](kernel_task_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CoreTraceV1API_v1StartCoreTrace**
```c
// Start CoreTrace on an instance
//
void CoreTraceV1API_v1StartCoreTrace(apiClient_t *apiClient, char *instanceId);
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

# **CoreTraceV1API_v1StopCoreTrace**
```c
// Stop CoreTrace on an instance.
//
void CoreTraceV1API_v1StopCoreTrace(apiClient_t *apiClient, char *instanceId);
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

