# ClusterAdministrationConfigAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ClusterAdministrationConfigAPI_v1GetClusterConfig**](ClusterAdministrationConfigAPI.md#ClusterAdministrationConfigAPI_v1GetClusterConfig) | **GET** /v1/cluster/config | Get cluster configuration
[**ClusterAdministrationConfigAPI_v1PatchClusterConfig**](ClusterAdministrationConfigAPI.md#ClusterAdministrationConfigAPI_v1PatchClusterConfig) | **PATCH** /v1/cluster/config | Update cluster configuration


# **ClusterAdministrationConfigAPI_v1GetClusterConfig**
```c
// Get cluster configuration
//
object_t* ClusterAdministrationConfigAPI_v1GetClusterConfig(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[object_t](object.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ClusterAdministrationConfigAPI_v1PatchClusterConfig**
```c
// Update cluster configuration
//
void ClusterAdministrationConfigAPI_v1PatchClusterConfig(apiClient_t *apiClient, body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**body** |  | Cluster Configuration Payload | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

