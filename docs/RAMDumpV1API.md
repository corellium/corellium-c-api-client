# RAMDumpV1API

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**RAMDumpV1API_v1ClearRamDump**](RAMDumpV1API.md#RAMDumpV1API_v1ClearRamDump) | **DELETE** /v1/instances/{instanceId}/ramdump | Clear RAM Dump
[**RAMDumpV1API_v1RAMDumpPreauthorize**](RAMDumpV1API.md#RAMDumpV1API_v1RAMDumpPreauthorize) | **GET** /v1/instances/{instanceId}/ramdump-authorize | Pre-authorize a RAM Dump download
[**RAMDumpV1API_v1StartRamDump**](RAMDumpV1API.md#RAMDumpV1API_v1StartRamDump) | **POST** /v1/instances/{instanceId}/ramdump/start | Start a RAM Dump on an instance


# **RAMDumpV1API_v1ClearRamDump**
```c
// Clear RAM Dump
//
void RAMDumpV1API_v1ClearRamDump(apiClient_t *apiClient, char *instanceId);
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

# **RAMDumpV1API_v1RAMDumpPreauthorize**
```c
// Pre-authorize a RAM Dump download
//
token_v1_t* RAMDumpV1API_v1RAMDumpPreauthorize(apiClient_t *apiClient, char *instanceId);
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

# **RAMDumpV1API_v1StartRamDump**
```c
// Start a RAM Dump on an instance
//
void RAMDumpV1API_v1StartRamDump(apiClient_t *apiClient, char *instanceId);
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

