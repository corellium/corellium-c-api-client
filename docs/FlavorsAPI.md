# FlavorsAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**FlavorsAPI_v3GetFrame**](FlavorsAPI.md#FlavorsAPI_v3GetFrame) | **GET** /v3/flavors/{flavorId} | Get the device frame layout for a model
[**FlavorsAPI_v3GetFrameImage**](FlavorsAPI.md#FlavorsAPI_v3GetFrameImage) | **GET** /v3/flavors/{flavorId}/image | Get the device frame image for a model
[**FlavorsAPI_v3GetProductImage**](FlavorsAPI.md#FlavorsAPI_v3GetProductImage) | **GET** /v3/flavors/{flavorId}/productimage | Get the product image for a model


# **FlavorsAPI_v3GetFrame**
```c
// Get the device frame layout for a model
//
// Returns the layout of the on-screen device frame (the picture of the phone drawn around the screen) for a model: its size, where the screen sits inside it, and where the home button is. Use it to draw a device image around a screenshot or live display. `flavorId` is a model `flavor` from `GET /v3/models`. Returns 404 if the model has no frame.
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
// Get the device frame image for a model
//
// Downloads the picture of the device frame (the phone body drawn around the screen) for a model, to combine with the layout from `v3GetFrame`. Returns 404 if the model has no frame image.
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
// Get the product image for a model
//
// Downloads a product picture of the device model, for example to show in a model picker. Returns 404 if the model has no product image.
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

