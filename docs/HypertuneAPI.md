# HypertuneAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**HypertuneAPI_v3HypertuneHash**](HypertuneAPI.md#HypertuneAPI_v3HypertuneHash) | **GET** /v3/hypertune/hash | Get Hypertune state hash
[**HypertuneAPI_v3HypertuneInit**](HypertuneAPI.md#HypertuneAPI_v3HypertuneInit) | **GET** /v3/hypertune/init | Get Hypertune initialization data


# **HypertuneAPI_v3HypertuneHash**
```c
// Get Hypertune state hash
//
// Returns the current Hypertune state hash for the cluster.
//
hypertune_hash_response_t* HypertuneAPI_v3HypertuneHash(apiClient_t *apiClient, char *token, char *branch, char *body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**token** | **char \*** | Hypertune access token. | [optional] 
**branch** | **char \*** | Hypertune branch name. | [optional] 
**body** | **char \*** | URL-encoded Hypertune SDK request body. | [optional] 

### Return type

[hypertune_hash_response_t](hypertune_hash_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **HypertuneAPI_v3HypertuneInit**
```c
// Get Hypertune initialization data
//
// Returns the Hypertune initialization data used by the SDK.
//
hypertune_init_response_t* HypertuneAPI_v3HypertuneInit(apiClient_t *apiClient, char *token, char *branch, char *body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**token** | **char \*** | Hypertune access token. | [optional] 
**branch** | **char \*** | Hypertune branch name. | [optional] 
**body** | **char \*** | URL-encoded Hypertune SDK request body. | [optional] 

### Return type

[hypertune_init_response_t](hypertune_init_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

