# StatusAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**StatusAPI_v3Ready**](StatusAPI.md#StatusAPI_v3Ready) | **GET** /v3/ready | Check that the API is ready


# **StatusAPI_v3Ready**
```c
// Check that the API is ready
//
// Health check. Returns 204 (no body) when the API is up and accepting requests, and 503 while it is shutting down. Needs no sign-in, so monitoring tools and scripts can call it before doing real work, for example to wait for a deployment to come back after an upgrade.
//
void StatusAPI_v3Ready(apiClient_t *apiClient);
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

