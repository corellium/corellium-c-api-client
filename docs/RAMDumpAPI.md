# RAMDumpAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**RAMDumpAPI_v3ClearRamDump**](RAMDumpAPI.md#RAMDumpAPI_v3ClearRamDump) | **DELETE** /v3/instances/{instanceId}/ramdump | Clear RAM Dump
[**RAMDumpAPI_v3RamDumpPreauthorize**](RAMDumpAPI.md#RAMDumpAPI_v3RamDumpPreauthorize) | **GET** /v3/instances/{instanceId}/ramdump-authorize | Pre-authorize a RAM Dump download
[**RAMDumpAPI_v3StartRamDump**](RAMDumpAPI.md#RAMDumpAPI_v3StartRamDump) | **POST** /v3/instances/{instanceId}/ramdump/start | Start a RAM Dump on an instance


# **RAMDumpAPI_v3ClearRamDump**
```c
// Clear RAM Dump
//
void RAMDumpAPI_v3ClearRamDump(apiClient_t *apiClient, char *instanceId);
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

# **RAMDumpAPI_v3RamDumpPreauthorize**
```c
// Pre-authorize a RAM Dump download
//
token_t* RAMDumpAPI_v3RamDumpPreauthorize(apiClient_t *apiClient, char *instanceId);
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

# **RAMDumpAPI_v3StartRamDump**
```c
// Start a RAM Dump on an instance
//
void RAMDumpAPI_v3StartRamDump(apiClient_t *apiClient, char *instanceId);
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

