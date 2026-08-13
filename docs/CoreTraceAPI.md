# CoreTraceAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**CoreTraceAPI_v3ClearCoreTrace**](CoreTraceAPI.md#CoreTraceAPI_v3ClearCoreTrace) | **DELETE** /v3/instances/{instanceId}/strace | Clear CoreTrace logs
[**CoreTraceAPI_v3ListThreads**](CoreTraceAPI.md#CoreTraceAPI_v3ListThreads) | **GET** /v3/instances/{instanceId}/strace/thread-list | Get Running Threads (CoreTrace)
[**CoreTraceAPI_v3StartCoreTrace**](CoreTraceAPI.md#CoreTraceAPI_v3StartCoreTrace) | **POST** /v3/instances/{instanceId}/strace/enable | Start CoreTrace on an instance
[**CoreTraceAPI_v3StopCoreTrace**](CoreTraceAPI.md#CoreTraceAPI_v3StopCoreTrace) | **POST** /v3/instances/{instanceId}/strace/disable | Stop CoreTrace on an instance.


# **CoreTraceAPI_v3ClearCoreTrace**
```c
// Clear CoreTrace logs
//
void CoreTraceAPI_v3ClearCoreTrace(apiClient_t *apiClient, char *instanceId);
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

# **CoreTraceAPI_v3ListThreads**
```c
// Get Running Threads (CoreTrace)
//
list_t* CoreTraceAPI_v3ListThreads(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 

### Return type

[list_t](kernel_task.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CoreTraceAPI_v3StartCoreTrace**
```c
// Start CoreTrace on an instance
//
void CoreTraceAPI_v3StartCoreTrace(apiClient_t *apiClient, char *instanceId);
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

# **CoreTraceAPI_v3StopCoreTrace**
```c
// Stop CoreTrace on an instance.
//
void CoreTraceAPI_v3StopCoreTrace(apiClient_t *apiClient, char *instanceId);
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

