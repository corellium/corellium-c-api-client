# FlavorsAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**FlavorsAPI_v3GetFrame**](FlavorsAPI.md#FlavorsAPI_v3GetFrame) | **GET** /v3/flavors/{flavorId} | Get frame for flavor
[**FlavorsAPI_v3GetFrameImage**](FlavorsAPI.md#FlavorsAPI_v3GetFrameImage) | **GET** /v3/flavors/{flavorId}/image | Get frame image for flavor
[**FlavorsAPI_v3GetProductImage**](FlavorsAPI.md#FlavorsAPI_v3GetProductImage) | **GET** /v3/flavors/{flavorId}/productimage | Get product image for flavor


# **FlavorsAPI_v3GetFrame**
```c
// Get frame for flavor
//
// Get frame for the given flavor ID.
//
flavor_frame_t* FlavorsAPI_v3GetFrame(apiClient_t *apiClient, char *flavorId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**flavorId** | **char \*** | Flavor ID. | 

### Return type

[flavor_frame_t](flavor_frame.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **FlavorsAPI_v3GetFrameImage**
```c
// Get frame image for flavor
//
// Get frame image for the given flavor ID.
//
binary_t** FlavorsAPI_v3GetFrameImage(apiClient_t *apiClient, char *flavorId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**flavorId** | **char \*** | Flavor ID. | 

### Return type

binary_t**



### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/octet-stream, application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **FlavorsAPI_v3GetProductImage**
```c
// Get product image for flavor
//
// Get product image for the given flavor ID.
//
binary_t** FlavorsAPI_v3GetProductImage(apiClient_t *apiClient, char *flavorId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**flavorId** | **char \*** | Flavor ID. | 

### Return type

binary_t**



### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/octet-stream, application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

