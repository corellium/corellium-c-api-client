# HypervisorHooksAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**HypervisorHooksAPI_v3ClearHyperTraceHooks**](HypervisorHooksAPI.md#HypervisorHooksAPI_v3ClearHyperTraceHooks) | **POST** /v3/instances/{instanceId}/hooks/clear | Stop hypervisor hooks
[**HypervisorHooksAPI_v3CreateHook**](HypervisorHooksAPI.md#HypervisorHooksAPI_v3CreateHook) | **POST** /v3/instances/{instanceId}/hooks | Create a hypervisor hook for an instance
[**HypervisorHooksAPI_v3DeleteHook**](HypervisorHooksAPI.md#HypervisorHooksAPI_v3DeleteHook) | **DELETE** /v3/hooks/{hookId} | Delete a hypervisor hook
[**HypervisorHooksAPI_v3ExecuteHyperTraceHooks**](HypervisorHooksAPI.md#HypervisorHooksAPI_v3ExecuteHyperTraceHooks) | **POST** /v3/instances/{instanceId}/hooks/execute | Run hypervisor hooks
[**HypervisorHooksAPI_v3GetHook**](HypervisorHooksAPI.md#HypervisorHooksAPI_v3GetHook) | **GET** /v3/hooks/{hookId} | Get a hypervisor hook by ID
[**HypervisorHooksAPI_v3ListHooks**](HypervisorHooksAPI.md#HypervisorHooksAPI_v3ListHooks) | **GET** /v3/instances/{instanceId}/hooks | List hypervisor hooks for an instance
[**HypervisorHooksAPI_v3UpdateHook**](HypervisorHooksAPI.md#HypervisorHooksAPI_v3UpdateHook) | **PUT** /v3/hooks/{hookId} | Update a hypervisor hook


# **HypervisorHooksAPI_v3ClearHyperTraceHooks**
```c
// Stop hypervisor hooks
//
// Deactivates the hypervisor hooks on this device, so they stop running. The hook definitions are kept and can be activated again with `v3ExecuteHyperTraceHooks`.
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
// Adds a hypervisor hook to a device: the `patch` code runs each time the device executes `address`. Hooks are enabled by default. Activate the device's hooks with `POST /v3/instances/{instanceId}/hooks/execute` and deactivate them with `.../hooks/clear`. Returns 201 with the new hook.
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
// Deletes a hypervisor hook from its device.  Deletes are idempotent: an unknown `hookId`, or a hook that was already deleted, is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing.
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
// Run hypervisor hooks
//
// Activates the hypervisor hooks configured for this device. A hook is a small patch, written in a C-like (`csmfcc`) or assembly-like (`csmfvm`) language, that runs whenever the device executes a chosen memory address; create and manage hooks with the Hypervisor Hooks endpoints (`POST /v3/instances/{instanceId}/hooks`). Only hooks marked `enabled` run. Does nothing if no hooks are configured.
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
// Returns one hypervisor hook, including its address, patch code and whether it is enabled.
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
// Lists the hypervisor hooks set up on a device. A hook is a small piece of code, written in a C-like or assembly-like language, that the hypervisor runs whenever the device executes a chosen memory address, without changing the software on the device. Use hooks to log values, change behavior, or bypass checks while testing. Results are paginated; `sort` orders them by creation date.
//
hook_list_t* HypervisorHooksAPI_v3ListHooks(apiClient_t *apiClient, char *instanceId, double *limit, double *offset, char *sort);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance identifier. | 
**limit** | **double \*** | Most results to return in one page. Whole number from 1 to 1000; defaults to 100. A value outside that range is rejected with 400. | [optional] [default to 100]
**offset** | **double \*** | How many results to skip before this page starts; defaults to 0. To get the next page, add &#x60;limit&#x60; to the previous &#x60;offset&#x60;. | [optional] [default to 0]
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
// Changes a hypervisor hook. Send only the fields you want to change, for example `enabled: false` to switch it off without deleting it. Returns the updated hook.
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

