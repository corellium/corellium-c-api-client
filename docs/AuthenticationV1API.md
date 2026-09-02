# AuthenticationV1API

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**AuthenticationV1API_v1AuthLogin**](AuthenticationV1API.md#AuthenticationV1API_v1AuthLogin) | **POST** /v1/auth/login | Log In
[**AuthenticationV1API_v1DeleteApiToken**](AuthenticationV1API.md#AuthenticationV1API_v1DeleteApiToken) | **DELETE** /v1/auth/apitoken | Delete API token
[**AuthenticationV1API_v1GenerateApiToken**](AuthenticationV1API.md#AuthenticationV1API_v1GenerateApiToken) | **POST** /v1/auth/apitoken | Generate API token


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

# **AuthenticationV1API_v1DeleteApiToken**
```c
// Delete API token
//
// Delete the authenticated user's currently saved API token.
//
void AuthenticationV1API_v1DeleteApiToken(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AuthenticationV1API_v1GenerateApiToken**
```c
// Generate API token
//
// Generate a new API token for the authenticated user. The token is returned once and replaces any previously issued token.
//
api_token_t* AuthenticationV1API_v1GenerateApiToken(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[api_token_t](api_token.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

