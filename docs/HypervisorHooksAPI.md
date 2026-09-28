# HypervisorHooksAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**HypervisorHooksAPI_v3ClearHyperTraceHooks**](HypervisorHooksAPI.md#HypervisorHooksAPI_v3ClearHyperTraceHooks) | **POST** /v3/instances/{instanceId}/hooks/clear | Clear Hooks on an instance
[**HypervisorHooksAPI_v3CreateHook**](HypervisorHooksAPI.md#HypervisorHooksAPI_v3CreateHook) | **POST** /v3/instances/{instanceId}/hooks | Create a hypervisor hook for an instance
[**HypervisorHooksAPI_v3DeleteHook**](HypervisorHooksAPI.md#HypervisorHooksAPI_v3DeleteHook) | **DELETE** /v3/hooks/{hookId} | Delete a hypervisor hook
[**HypervisorHooksAPI_v3ExecuteHyperTraceHooks**](HypervisorHooksAPI.md#HypervisorHooksAPI_v3ExecuteHyperTraceHooks) | **POST** /v3/instances/{instanceId}/hooks/execute | Execute Hooks on an instance
[**HypervisorHooksAPI_v3GetHook**](HypervisorHooksAPI.md#HypervisorHooksAPI_v3GetHook) | **GET** /v3/hooks/{hookId} | Get a hypervisor hook by ID
[**HypervisorHooksAPI_v3ListHooks**](HypervisorHooksAPI.md#HypervisorHooksAPI_v3ListHooks) | **GET** /v3/instances/{instanceId}/hooks | List hypervisor hooks for an instance
[**HypervisorHooksAPI_v3UpdateHook**](HypervisorHooksAPI.md#HypervisorHooksAPI_v3UpdateHook) | **PUT** /v3/hooks/{hookId} | Update a hypervisor hook


# **HypervisorHooksAPI_v3ClearHyperTraceHooks**
```c
// Clear Hooks on an instance
//
void HypervisorHooksAPI_v3ClearHyperTraceHooks(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **HypervisorHooksAPI_v3CreateHook**
```c
// Create a hypervisor hook for an instance
//
// Creates a new hypervisor hook for the given instance.
//
hook_t* HypervisorHooksAPI_v3CreateHook(apiClient_t *apiClient, char *instanceId, create_hook_body_t *create_hook_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance identifier. | 
**create_hook_body** | **[create_hook_body_t](create_hook_body.md) \*** |  | 

### Return type

[hook_t](hook.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **HypervisorHooksAPI_v3DeleteHook**
```c
// Delete a hypervisor hook
//
// Deletes the hypervisor hook identified by the given hookId.  Deletes are idempotent: an unknown `hookId`, or a hook that was already deleted, is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing.
//
void HypervisorHooksAPI_v3DeleteHook(apiClient_t *apiClient, char *hookId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**hookId** | **char \*** | Hook identifier. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **HypervisorHooksAPI_v3ExecuteHyperTraceHooks**
```c
// Execute Hooks on an instance
//
void HypervisorHooksAPI_v3ExecuteHyperTraceHooks(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **HypervisorHooksAPI_v3GetHook**
```c
// Get a hypervisor hook by ID
//
// Returns the hypervisor hook identified by the given hookId.
//
hook_t* HypervisorHooksAPI_v3GetHook(apiClient_t *apiClient, char *hookId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**hookId** | **char \*** | Hook identifier. | 

### Return type

[hook_t](hook.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **HypervisorHooksAPI_v3ListHooks**
```c
// List hypervisor hooks for an instance
//
// Returns a paginated list of hypervisor hooks configured for the given instance.
//
hook_list_t* HypervisorHooksAPI_v3ListHooks(apiClient_t *apiClient, char *instanceId, double *limit, double *offset, char *sort);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance identifier. | 
**limit** | **double \*** | Maximum number of results to return. | [optional] [default to 100]
**offset** | **double \*** | Number of results to skip. | [optional] [default to 0]
**sort** | **char \*** | Sort order by creation date. | [optional] [default to &#39;DESC&#39;]

### Return type

[hook_list_t](hook_list.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **HypervisorHooksAPI_v3UpdateHook**
```c
// Update a hypervisor hook
//
// Updates the hypervisor hook identified by the given hookId.
//
hook_t* HypervisorHooksAPI_v3UpdateHook(apiClient_t *apiClient, char *hookId, update_hook_body_t *update_hook_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**hookId** | **char \*** | Hook identifier. | 
**update_hook_body** | **[update_hook_body_t](update_hook_body.md) \*** |  | [optional] 

### Return type

[hook_t](hook.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

