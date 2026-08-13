# AuthenticationV1API

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**AuthenticationV1API_v1AuthLogin**](AuthenticationV1API.md#AuthenticationV1API_v1AuthLogin) | **POST** /v1/auth/login | Log In


# **AuthenticationV1API_v1AuthLogin**
```c
// Log In
//
token_v1_t* AuthenticationV1API_v1AuthLogin(apiClient_t *apiClient, object_t *body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**body** | **[object_t](object.md) \*** | Authorization data ( Credentials|ApiToken ) | 

### Return type

[token_v1_t](token_v1.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

