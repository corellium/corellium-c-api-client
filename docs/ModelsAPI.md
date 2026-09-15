# ModelsAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ModelsAPI_v3GetModelSoftware**](ModelsAPI.md#ModelsAPI_v3GetModelSoftware) | **GET** /v3/models/{model}/software | Get Software for Model
[**ModelsAPI_v3GetModels**](ModelsAPI.md#ModelsAPI_v3GetModels) | **GET** /v3/models | Get Supported Models


# **ModelsAPI_v3GetModelSoftware**
```c
// Get Software for Model
//
// Get software for model. The `model` path parameter is resolved as a flavor ID first and as a product identifier second. Addressing a flavor ID additionally returns `springboardSnapshot` for the builds that have a rapid-start snapshot, which a product identifier cannot report because several flavors can share one product.
//
list_t* ModelsAPI_v3GetModelSoftware(apiClient_t *apiClient, char *model);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**model** | **char \*** | Model to list available software for. Accepts either a flavor ID (as published by &#x60;GET /v3/models&#x60; as &#x60;flavor&#x60;) or a product identifier; the flavor ID is resolved first. | 

### Return type

[list_t](model_firmware.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ModelsAPI_v3GetModels**
```c
// Get Supported Models
//
// Get supported models. The response carries an `ETag`; repeating the request with that value in `If-None-Match` returns 304 when the catalog is unchanged.
//
list_t* ModelsAPI_v3GetModels(apiClient_t *apiClient, char *if_none_match);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**if_none_match** | **char \*** | An ETag a previous response carried, quotes included. | [optional] 

### Return type

[list_t](model.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

