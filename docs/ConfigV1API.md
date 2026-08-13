# ConfigV1API

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ConfigV1API_v1GetConfig**](ConfigV1API.md#ConfigV1API_v1GetConfig) | **GET** /v1/config | Get all configs


# **ConfigV1API_v1GetConfig**
```c
// Get all configs
//
config_response_v1_t* ConfigV1API_v1GetConfig(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[config_response_v1_t](config_response_v1.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

