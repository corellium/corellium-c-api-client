# HyperTraceAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**HyperTraceAPI_v3BtracePreauthorize**](HyperTraceAPI.md#HyperTraceAPI_v3BtracePreauthorize) | **GET** /v3/instances/{instanceId}/btrace-authorize | Get a HyperTrace download token
[**HyperTraceAPI_v3ClearHyperTrace**](HyperTraceAPI.md#HyperTraceAPI_v3ClearHyperTrace) | **DELETE** /v3/instances/{instanceId}/btrace | Clear HyperTrace output
[**HyperTraceAPI_v3GetInstanceKcrange**](HyperTraceAPI.md#HyperTraceAPI_v3GetInstanceKcrange) | **GET** /v3/instances/{instanceId}/btrace-kcrange | List kernel extension address ranges
[**HyperTraceAPI_v3StartHyperTrace**](HyperTraceAPI.md#HyperTraceAPI_v3StartHyperTrace) | **POST** /v3/instances/{instanceId}/btrace/enable | Start HyperTrace
[**HyperTraceAPI_v3StopHyperTrace**](HyperTraceAPI.md#HyperTraceAPI_v3StopHyperTrace) | **POST** /v3/instances/{instanceId}/btrace/disable | Stop HyperTrace


# **HyperTraceAPI_v3BtracePreauthorize**
```c
// Get a HyperTrace download token
//
// Returns a short-lived token that authorizes downloading this device's HyperTrace output without an `Authorization` header. Download with `GET /v1/preauthed/{token}/{filename}`. The token works only for this device's trace and expires when your current session token expires.
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
// Clear HyperTrace output
//
// Deletes the HyperTrace output recorded so far on this device. An unknown `instanceId` is a successful no-op that returns 204.
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
// List kernel extension address ranges
//
// Lists the kernel extensions loaded on the device with the memory address range each occupies. Pass a `range` to `v3StartHyperTrace` to trace code in just that extension. The device must be running.
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
// Start HyperTrace
//
// Starts HyperTrace on a running device. HyperTrace records which kernel code runs inside the address ranges you choose, without changing the device's software, so you can measure kernel code coverage.  **Workflow:** list kernel extensions with `v3GetInstanceKcrange`, start tracing with the `ranges` you want (this call), exercise the device, stop with `v3StopHyperTrace`, then download with `v3BtracePreauthorize`. Clear old output with `v3ClearHyperTrace`.
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
// Stop HyperTrace
//
// Stops HyperTrace on this device. The trace recorded so far is kept for download with `v3BtracePreauthorize`.
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

