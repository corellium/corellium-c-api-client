# HypervisorHooksV1API

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**HypervisorHooksV1API_v1ClearHyperTraceHooks**](HypervisorHooksV1API.md#HypervisorHooksV1API_v1ClearHyperTraceHooks) | **POST** /v1/instances/{instanceId}/hooks/clear | Clear Hooks on an instance
[**HypervisorHooksV1API_v1CreateHook**](HypervisorHooksV1API.md#HypervisorHooksV1API_v1CreateHook) | **POST** /v1/instances/{instanceId}/hooks | Create hypervisor hook for Instance
[**HypervisorHooksV1API_v1DeleteHook**](HypervisorHooksV1API.md#HypervisorHooksV1API_v1DeleteHook) | **DELETE** /v1/hooks/{hookId} | Delete an existing hypervisor hook
[**HypervisorHooksV1API_v1ExecuteHyperTraceHooks**](HypervisorHooksV1API.md#HypervisorHooksV1API_v1ExecuteHyperTraceHooks) | **POST** /v1/instances/{instanceId}/hooks/execute | Execute Hooks on an instance
[**HypervisorHooksV1API_v1GetHookById**](HypervisorHooksV1API.md#HypervisorHooksV1API_v1GetHookById) | **GET** /v1/hooks/{hookId} | Get hypervisor hook by id
[**HypervisorHooksV1API_v1GetHooks**](HypervisorHooksV1API.md#HypervisorHooksV1API_v1GetHooks) | **GET** /v1/instances/{instanceId}/hooks | Get all hypervisor hooks for Instance
[**HypervisorHooksV1API_v1UpdateHook**](HypervisorHooksV1API.md#HypervisorHooksV1API_v1UpdateHook) | **PUT** /v1/hooks/{hookId} | Update an existing hypervisor hook


# **HypervisorHooksV1API_v1ClearHyperTraceHooks**
```c
// Clear Hooks on an instance
//
void HypervisorHooksV1API_v1ClearHyperTraceHooks(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **HypervisorHooksV1API_v1CreateHook**
```c
// Create hypervisor hook for Instance
//
hook_v1_t* HypervisorHooksV1API_v1CreateHook(apiClient_t *apiClient, char *instanceId, v1_create_hook_parameters_t *v1_create_hook_parameters);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 
**v1_create_hook_parameters** | **[v1_create_hook_parameters_t](v1_create_hook_parameters.md) \*** | application/json | 

### Return type

[hook_v1_t](hook_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **HypervisorHooksV1API_v1DeleteHook**
```c
// Delete an existing hypervisor hook
//
void HypervisorHooksV1API_v1DeleteHook(apiClient_t *apiClient, char *hookId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**hookId** | **char \*** | Hook ID | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **HypervisorHooksV1API_v1ExecuteHyperTraceHooks**
```c
// Execute Hooks on an instance
//
void HypervisorHooksV1API_v1ExecuteHyperTraceHooks(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **HypervisorHooksV1API_v1GetHookById**
```c
// Get hypervisor hook by id
//
hook_v1_t* HypervisorHooksV1API_v1GetHookById(apiClient_t *apiClient, char *hookId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**hookId** | **char \*** | Hook Id | 

### Return type

[hook_v1_t](hook_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **HypervisorHooksV1API_v1GetHooks**
```c
// Get all hypervisor hooks for Instance
//
list_t* HypervisorHooksV1API_v1GetHooks(apiClient_t *apiClient, char *instanceId, double limit, double offset, char *sort);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 
**limit** | **double** | limit for pagination results, defaults to 20 | [optional] 
**offset** | **double** | offset for pagination results, defaults to 0 | [optional] 
**sort** | **char \*** | sort ASC or DESC, defaults to DESC | [optional] 

### Return type

[list_t](hook_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **HypervisorHooksV1API_v1UpdateHook**
```c
// Update an existing hypervisor hook
//
hook_v1_t* HypervisorHooksV1API_v1UpdateHook(apiClient_t *apiClient, char *hookId, v1_update_hook_parameters_t *v1_update_hook_parameters);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**hookId** | **char \*** | Hook ID | 
**v1_update_hook_parameters** | **[v1_update_hook_parameters_t](v1_update_hook_parameters.md) \*** | application/json | 

### Return type

[hook_v1_t](hook_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

