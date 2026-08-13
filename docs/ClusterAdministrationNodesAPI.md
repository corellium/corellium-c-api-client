# ClusterAdministrationNodesAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ClusterAdministrationNodesAPI_v1GetClusterNodes**](ClusterAdministrationNodesAPI.md#ClusterAdministrationNodesAPI_v1GetClusterNodes) | **GET** /v1/cluster/nodes/{nodeId} | Get node details by ID
[**ClusterAdministrationNodesAPI_v1GetConsoleClusterNodes**](ClusterAdministrationNodesAPI.md#ClusterAdministrationNodesAPI_v1GetConsoleClusterNodes) | **GET** /v1/cluster/nodes/{nodeId}/console | Access node console via SSH
[**ClusterAdministrationNodesAPI_v1ListClusterNodes**](ClusterAdministrationNodesAPI.md#ClusterAdministrationNodesAPI_v1ListClusterNodes) | **GET** /v1/cluster/nodes | List servers in the cluster


# **ClusterAdministrationNodesAPI_v1GetClusterNodes**
```c
// Get node details by ID
//
node_information_v1_t* ClusterAdministrationNodesAPI_v1GetClusterNodes(apiClient_t *apiClient, char *nodeId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**nodeId** | **char \*** | Node ID | 

### Return type

[node_information_v1_t](node_information_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ClusterAdministrationNodesAPI_v1GetConsoleClusterNodes**
```c
// Access node console via SSH
//
// Access node console via SSH (WebSocket upgrade)
//
void ClusterAdministrationNodesAPI_v1GetConsoleClusterNodes(apiClient_t *apiClient, char *nodeId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**nodeId** | **char \*** | Node ID | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ClusterAdministrationNodesAPI_v1ListClusterNodes**
```c
// List servers in the cluster
//
list_t* ClusterAdministrationNodesAPI_v1ListClusterNodes(apiClient_t *apiClient, double limit, double offset);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**limit** | **double** | limit for pagination results, defaults to 100 | [optional] 
**offset** | **double** | offset for pagination results, defaults to 0 | [optional] 

### Return type

[list_t](node_information_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

