# InstancesV2API

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**InstancesV2API_v2GetInstanceQuickConnectCommand**](InstancesV2API.md#InstancesV2API_v2GetInstanceQuickConnectCommand) | **GET** /v2/instances/{instanceId}/quickConnectCommand | Recommended SSH Command for Quick Connect
[**InstancesV2API_v2GetInstanceState**](InstancesV2API.md#InstancesV2API_v2GetInstanceState) | **GET** /v2/instances/{instanceId}/state | Get state of Instance


# **InstancesV2API_v2GetInstanceQuickConnectCommand**
```c
// Recommended SSH Command for Quick Connect
//
char* InstancesV2API_v2GetInstanceQuickConnectCommand(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 

### Return type

char*



### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesV2API_v2GetInstanceState**
```c
// Get state of Instance
//
instance_state_v1_t* InstancesV2API_v2GetInstanceState(apiClient_t *apiClient, char *instanceId, char *returnAttr);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 
**returnAttr** | **char \*** | The attributes to return. | [optional] 

### Return type

[instance_state_v1_t](instance_state_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

