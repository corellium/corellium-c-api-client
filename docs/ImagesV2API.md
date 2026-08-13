# ImagesV2API

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ImagesV2API_v1DeleteImage**](ImagesV2API.md#ImagesV2API_v1DeleteImage) | **DELETE** /v2/images/{imageId} | Delete Image


# **ImagesV2API_v1DeleteImage**
```c
// Delete Image
//
void ImagesV2API_v1DeleteImage(apiClient_t *apiClient, char *imageId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**imageId** | **char \*** | Image ID - uuid | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

