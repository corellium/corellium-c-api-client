# ImagesV1API

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ImagesV1API_v1GetImage**](ImagesV1API.md#ImagesV1API_v1GetImage) | **GET** /v1/images/{imageId} | Get Image Metadata
[**ImagesV1API_v1GetImages**](ImagesV1API.md#ImagesV1API_v1GetImages) | **GET** /v1/images | Get all Images Metadata


# **ImagesV1API_v1GetImage**
```c
// Get Image Metadata
//
image_v1_t* ImagesV1API_v1GetImage(apiClient_t *apiClient, char *imageId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**imageId** | **char \*** | Image ID - uuid | 

### Return type

[image_v1_t](image_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ImagesV1API_v1GetImages**
```c
// Get all Images Metadata
//
list_t* ImagesV1API_v1GetImages(apiClient_t *apiClient, char *project);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**project** | **char \*** | Optionally filter by project - uuid | [optional] 

### Return type

[list_t](image_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

