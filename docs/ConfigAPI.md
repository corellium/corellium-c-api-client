# ConfigAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ConfigAPI_v3GetConfig**](ConfigAPI.md#ConfigAPI_v3GetConfig) | **GET** /v3/config | Get all configs
[**ConfigAPI_v3GetVersion**](ConfigAPI.md#ConfigAPI_v3GetVersion) | **GET** /v3/version | Get Deployment Version


# **ConfigAPI_v3GetConfig**
```c
// Get all configs
//
config_response_t* ConfigAPI_v3GetConfig(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[config_response_t](config_response.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ConfigAPI_v3GetVersion**
```c
// Get Deployment Version
//
// Get the version and build identity of the running deployment.
//
deployment_version_t* ConfigAPI_v3GetVersion(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[deployment_version_t](deployment_version.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

