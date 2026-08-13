# ModelsV1API

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ModelsV1API_v1GetModelSoftware**](ModelsV1API.md#ModelsV1API_v1GetModelSoftware) | **GET** /v1/models/{model}/software | Get Software for Model
[**ModelsV1API_v1GetModels**](ModelsV1API.md#ModelsV1API_v1GetModels) | **GET** /v1/models | Get Supported Models


# **ModelsV1API_v1GetModelSoftware**
```c
// Get Software for Model
//
list_t* ModelsV1API_v1GetModelSoftware(apiClient_t *apiClient, char *model);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**model** | **char \*** | Model to list available software for | 

### Return type

[list_t](firmware_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ModelsV1API_v1GetModels**
```c
// Get Supported Models
//
list_t* ModelsV1API_v1GetModels(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[list_t](model_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

