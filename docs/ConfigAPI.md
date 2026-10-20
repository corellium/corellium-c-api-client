# ConfigAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ConfigAPI_v3GetConfig**](ConfigAPI.md#ConfigAPI_v3GetConfig) | **GET** /v3/config | Get deployment configuration
[**ConfigAPI_v3GetVersion**](ConfigAPI.md#ConfigAPI_v3GetVersion) | **GET** /v3/version | Get the platform version


# **ConfigAPI_v3GetConfig**
```c
// Get deployment configuration
//
// Returns how this Corellium deployment is set up: its version, whether it is on-site or cloud, whether it is air-gapped, the sign-in providers offered, limits such as the per-device snapshot limit (`snapshotLimit`) and the maximum kernel and ramdisk upload sizes, and which optional features are turned on. Needs no sign-in, so a client can call it first to adapt to the deployment before the user signs in. Build-time feature flags may add further boolean properties beyond those listed.
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
// Get the platform version
//
// Returns which version of the Corellium platform you are talking to: the product version (for example `7.4.0-28212`), plus the build it came from. Include it when reporting a problem to support, or check it to see whether a feature you need is available on this deployment.
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

