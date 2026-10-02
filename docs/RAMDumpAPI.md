# RAMDumpAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**RAMDumpAPI_v3ClearRamDump**](RAMDumpAPI.md#RAMDumpAPI_v3ClearRamDump) | **DELETE** /v3/instances/{instanceId}/ramdump | Delete a RAM dump
[**RAMDumpAPI_v3RamDumpPreauthorize**](RAMDumpAPI.md#RAMDumpAPI_v3RamDumpPreauthorize) | **GET** /v3/instances/{instanceId}/ramdump-authorize | Get a RAM dump download token
[**RAMDumpAPI_v3StartRamDump**](RAMDumpAPI.md#RAMDumpAPI_v3StartRamDump) | **POST** /v3/instances/{instanceId}/ramdump/start | Start a RAM dump


# **RAMDumpAPI_v3ClearRamDump**
```c
// Delete a RAM dump
//
// Deletes this device's RAM dump file. Returns 204 whether or not a dump existed. Requires the RAM dump license feature. An unknown `instanceId` is a successful no-op that returns 204.
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
// Get a RAM dump download token
//
// Returns a short-lived token that authorizes downloading this device's RAM dump without an `Authorization` header, so you can hand the link to a download manager or browser. Download with `GET /v1/preauthed/{token}/{filename}`. The token works only for this device's RAM dump and expires when your current session token expires. Requires the RAM dump license feature.
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
// Start a RAM dump
//
// Captures the full contents of the device's memory to a file, for offline analysis with memory forensics tools. Returns 202 as soon as the dump has started; it is written in the background, and large memory sizes take a while. Download it with `v3RamDumpPreauthorize` when it is done, and delete it with `v3ClearRamDump`. Requires the RAM dump license feature (403 otherwise).
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

