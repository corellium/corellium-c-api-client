# InstancesV1API

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**InstancesV1API_v1AttachInstanceInterface**](InstancesV1API.md#InstancesV1API_v1AttachInstanceInterface) | **POST** /v1/instances/{instanceId}/interfaces | Attach I/O Interface
[**InstancesV1API_v1ClearInstancePanics**](InstancesV1API.md#InstancesV1API_v1ClearInstancePanics) | **DELETE** /v1/instances/{instanceId}/panics | Clear Panics
[**InstancesV1API_v1CreateInstance**](InstancesV1API.md#InstancesV1API_v1CreateInstance) | **POST** /v1/instances | Create Instance
[**InstancesV1API_v1DeleteInstance**](InstancesV1API.md#InstancesV1API_v1DeleteInstance) | **DELETE** /v1/instances/{instanceId} | Remove Instance
[**InstancesV1API_v1DetachInstanceInterface**](InstancesV1API.md#InstancesV1API_v1DetachInstanceInterface) | **DELETE** /v1/instances/{instanceId}/interfaces/{interfaceId} | Detach I/O Interface
[**InstancesV1API_v1DisableExposePort**](InstancesV1API.md#InstancesV1API_v1DisableExposePort) | **POST** /v1/instances/{instanceId}/exposeport/disable | Disable an exposed port on an instance for device access.
[**InstancesV1API_v1DownloadNetdumpPcapInstances**](InstancesV1API.md#InstancesV1API_v1DownloadNetdumpPcapInstances) | **GET** /v1/instances/{instanceId}/netdump.pcap | Download a netdump pcap file
[**InstancesV1API_v1DownloadNetworkMonitorPcapInstances**](InstancesV1API.md#InstancesV1API_v1DownloadNetworkMonitorPcapInstances) | **GET** /v1/instances/{instanceId}/networkMonitor.pcap | Download a Network Monitor pcap file
[**InstancesV1API_v1EnableExposePort**](InstancesV1API.md#InstancesV1API_v1EnableExposePort) | **POST** /v1/instances/{instanceId}/exposeport/enable | Enable an exposed port on an instance for device access.
[**InstancesV1API_v1GetInstance**](InstancesV1API.md#InstancesV1API_v1GetInstance) | **GET** /v1/instances/{instanceId} | Get Instance
[**InstancesV1API_v1GetInstanceConsole**](InstancesV1API.md#InstancesV1API_v1GetInstanceConsole) | **GET** /v1/instances/{instanceId}/console | Get console websocket URL
[**InstancesV1API_v1GetInstanceConsoleLog**](InstancesV1API.md#InstancesV1API_v1GetInstanceConsoleLog) | **GET** /v1/instances/{instanceId}/consoleLog | Get Console Log
[**InstancesV1API_v1GetInstanceGpios**](InstancesV1API.md#InstancesV1API_v1GetInstanceGpios) | **GET** /v1/instances/{instanceId}/gpios | Get Instance GPIOs
[**InstancesV1API_v1GetInstancePanics**](InstancesV1API.md#InstancesV1API_v1GetInstancePanics) | **GET** /v1/instances/{instanceId}/panics | Get Panics
[**InstancesV1API_v1GetInstancePeripherals**](InstancesV1API.md#InstancesV1API_v1GetInstancePeripherals) | **GET** /v1/instances/{instanceId}/peripherals | Get Instance Peripherals
[**InstancesV1API_v1GetInstanceScreenshot**](InstancesV1API.md#InstancesV1API_v1GetInstanceScreenshot) | **GET** /v1/instances/{instanceId}/screenshot.{format} | Get Instance Screenshot
[**InstancesV1API_v1GetInstances**](InstancesV1API.md#InstancesV1API_v1GetInstances) | **GET** /v1/instances | Get Instances
[**InstancesV1API_v1InjectMessageInstances**](InstancesV1API.md#InstancesV1API_v1InjectMessageInstances) | **POST** /v1/instances/{instanceId}/message | Inject a message into an iOS VM
[**InstancesV1API_v1MediaPlay**](InstancesV1API.md#InstancesV1API_v1MediaPlay) | **POST** /v1/instances/{instanceId}/media/play | Start playing media
[**InstancesV1API_v1MediaStop**](InstancesV1API.md#InstancesV1API_v1MediaStop) | **POST** /v1/instances/{instanceId}/media/stop | Stop playing media
[**InstancesV1API_v1PatchInstance**](InstancesV1API.md#InstancesV1API_v1PatchInstance) | **PATCH** /v1/instances/{instanceId} | Update Instance
[**InstancesV1API_v1PatchInstanceReadOnly**](InstancesV1API.md#InstancesV1API_v1PatchInstanceReadOnly) | **PATCH** /v1/instances/{instanceId}/read-only | Update Instance Read Only
[**InstancesV1API_v1PauseInstance**](InstancesV1API.md#InstancesV1API_v1PauseInstance) | **POST** /v1/instances/{instanceId}/pause | Pause an Instance
[**InstancesV1API_v1PostInstanceInput**](InstancesV1API.md#InstancesV1API_v1PostInstanceInput) | **POST** /v1/instances/{instanceId}/input | Provide Instance Input
[**InstancesV1API_v1RebootInstance**](InstancesV1API.md#InstancesV1API_v1RebootInstance) | **POST** /v1/instances/{instanceId}/reboot | Reboot an Instance
[**InstancesV1API_v1RestoreBackup**](InstancesV1API.md#InstancesV1API_v1RestoreBackup) | **POST** /v1/instances/{instanceId}/restoreBackup | Restore backup
[**InstancesV1API_v1RotateInstance**](InstancesV1API.md#InstancesV1API_v1RotateInstance) | **POST** /v1/instances/{instanceId}/rotate | Rotate device to specified orientation
[**InstancesV1API_v1SetInstanceGpios**](InstancesV1API.md#InstancesV1API_v1SetInstanceGpios) | **PUT** /v1/instances/{instanceId}/gpios | Set Instance GPIOs
[**InstancesV1API_v1SetInstancePeripherals**](InstancesV1API.md#InstancesV1API_v1SetInstancePeripherals) | **PUT** /v1/instances/{instanceId}/peripherals | Set Instance Peripherals
[**InstancesV1API_v1SetInstanceState**](InstancesV1API.md#InstancesV1API_v1SetInstanceState) | **PUT** /v1/instances/{instanceId}/state | Set state of Instance
[**InstancesV1API_v1StartInstance**](InstancesV1API.md#InstancesV1API_v1StartInstance) | **POST** /v1/instances/{instanceId}/start | Start an Instance
[**InstancesV1API_v1StartNetdump**](InstancesV1API.md#InstancesV1API_v1StartNetdump) | **POST** /v1/instances/{instanceId}/netdump/enable | Start Enhanced Network Monitor on an instance.
[**InstancesV1API_v1StartNetworkMonitor**](InstancesV1API.md#InstancesV1API_v1StartNetworkMonitor) | **POST** /v1/instances/{instanceId}/sslsplit/enable | Start Network Monitor on an instance.
[**InstancesV1API_v1StopInstance**](InstancesV1API.md#InstancesV1API_v1StopInstance) | **POST** /v1/instances/{instanceId}/stop | Stop an Instance
[**InstancesV1API_v1StopNetdump**](InstancesV1API.md#InstancesV1API_v1StopNetdump) | **POST** /v1/instances/{instanceId}/netdump/disable | Stop Enhanced Network Monitor on an instance.
[**InstancesV1API_v1StopNetworkMonitor**](InstancesV1API.md#InstancesV1API_v1StopNetworkMonitor) | **POST** /v1/instances/{instanceId}/sslsplit/disable | Stop Network Monitor on an instance.
[**InstancesV1API_v1UnpauseInstance**](InstancesV1API.md#InstancesV1API_v1UnpauseInstance) | **POST** /v1/instances/{instanceId}/unpause | Unpause an Instance
[**InstancesV1API_v1UpgradeInstance**](InstancesV1API.md#InstancesV1API_v1UpgradeInstance) | **POST** /v1/instances/{instanceId}/upgrade | Upgrade iOS version


# **InstancesV1API_v1AttachInstanceInterface**
```c
// Attach I/O Interface
//
// Attach an I/O interface to an I/O interconnect for the specified instance identifier.
//
void InstancesV1API_v1AttachInstanceInterface(apiClient_t *apiClient, char *instanceId, attach_interface_request_t *attach_interface_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 
**attach_interface_request** | **[attach_interface_request_t](attach_interface_request.md) \*** | Interface attachment request | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesV1API_v1ClearInstancePanics**
```c
// Clear Panics
//
void InstancesV1API_v1ClearInstancePanics(apiClient_t *apiClient, char *instanceId);
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

# **InstancesV1API_v1CreateInstance**
```c
// Create Instance
//
instance_return_v1_t* InstancesV1API_v1CreateInstance(apiClient_t *apiClient, instance_create_options_t *instance_create_options);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instance_create_options** | **[instance_create_options_t](instance_create_options.md) \*** | The vm definition to create | 

### Return type

[instance_return_v1_t](instance_return_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesV1API_v1DeleteInstance**
```c
// Remove Instance
//
void InstancesV1API_v1DeleteInstance(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesV1API_v1DetachInstanceInterface**
```c
// Detach I/O Interface
//
// Detach an I/O interface from an I/O interconnect for the specified instance identifier.
//
void InstancesV1API_v1DetachInstanceInterface(apiClient_t *apiClient, char *instanceId, char *interfaceId, detach_interface_request_t *detach_interface_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 
**interfaceId** | **char \*** | Interface ID | 
**detach_interface_request** | **[detach_interface_request_t](detach_interface_request.md) \*** | Interface detachment request | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesV1API_v1DisableExposePort**
```c
// Disable an exposed port on an instance for device access.
//
void InstancesV1API_v1DisableExposePort(apiClient_t *apiClient, char *instanceId);
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

# **InstancesV1API_v1DownloadNetdumpPcapInstances**
```c
// Download a netdump pcap file
//
binary_t** InstancesV1API_v1DownloadNetdumpPcapInstances(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 

### Return type

binary_t**



### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/vnd.tcpdump.pcap, application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesV1API_v1DownloadNetworkMonitorPcapInstances**
```c
// Download a Network Monitor pcap file
//
binary_t** InstancesV1API_v1DownloadNetworkMonitorPcapInstances(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 

### Return type

binary_t**



### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/vnd.tcpdump.pcap, application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesV1API_v1EnableExposePort**
```c
// Enable an exposed port on an instance for device access.
//
void InstancesV1API_v1EnableExposePort(apiClient_t *apiClient, char *instanceId);
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

# **InstancesV1API_v1GetInstance**
```c
// Get Instance
//
instance_v1_t* InstancesV1API_v1GetInstance(apiClient_t *apiClient, char *instanceId, char *returnAttr);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID | 
**returnAttr** | **char \*** | Attributes to include in instance return | [optional] 

### Return type

[instance_v1_t](instance_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesV1API_v1GetInstanceConsole**
```c
// Get console websocket URL
//
instance_console_endpoint_v1_t* InstancesV1API_v1GetInstanceConsole(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 

### Return type

[instance_console_endpoint_v1_t](instance_console_endpoint_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesV1API_v1GetInstanceConsoleLog**
```c
// Get Console Log
//
char* InstancesV1API_v1GetInstanceConsoleLog(apiClient_t *apiClient, char *instanceId);
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
 - **Accept**: text/plain, application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesV1API_v1GetInstanceGpios**
```c
// Get Instance GPIOs
//
gpios_state_v1_t* InstancesV1API_v1GetInstanceGpios(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 

### Return type

[gpios_state_v1_t](gpios_state_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesV1API_v1GetInstancePanics**
```c
// Get Panics
//
list_t* InstancesV1API_v1GetInstancePanics(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 

### Return type

[list_t](object.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesV1API_v1GetInstancePeripherals**
```c
// Get Instance Peripherals
//
peripherals_data_v1_t* InstancesV1API_v1GetInstancePeripherals(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 

### Return type

[peripherals_data_v1_t](peripherals_data_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesV1API_v1GetInstanceScreenshot**
```c
// Get Instance Screenshot
//
binary_t** InstancesV1API_v1GetInstanceScreenshot(apiClient_t *apiClient, char *instanceId, char *format, double *scale);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 
**format** | **char \*** | New peripherals state | 
**scale** | **double \*** | Screenshot scale 1:N | [optional] 

### Return type

binary_t**



### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: image/png, image/jpeg, application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesV1API_v1GetInstances**
```c
// Get Instances
//
list_t* InstancesV1API_v1GetInstances(apiClient_t *apiClient, char *name, char *returnAttr);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**name** | **char \*** | Optionally filter by instance name | [optional] 
**returnAttr** | **char \*** | Attributes to include in instance return | [optional] 

### Return type

[list_t](instance_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesV1API_v1InjectMessageInstances**
```c
// Inject a message into an iOS VM
//
// Given a message and source phone number, place this message as an incoming SMS message on the iOS VM. For advanced usage, a raw message of bytes may be sent. In this case, the parameter should provide hex encoded bytes  (0x00 0x11 0x22 0x33 in the example below) which are sent verbatim.  The user must ensure that the body is the correct format for the underlying device stack.
//
void InstancesV1API_v1InjectMessageInstances(apiClient_t *apiClient, char *instanceId, object_t *body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 
**body** | **[object_t](object.md) \*** | Message data | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesV1API_v1MediaPlay**
```c
// Start playing media
//
void InstancesV1API_v1MediaPlay(apiClient_t *apiClient, char *instanceId, media_play_body_v1_t *media_play_body_v1);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 
**media_play_body_v1** | **[media_play_body_v1_t](media_play_body_v1.md) \*** | Request Body | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesV1API_v1MediaStop**
```c
// Stop playing media
//
void InstancesV1API_v1MediaStop(apiClient_t *apiClient, char *instanceId);
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

# **InstancesV1API_v1PatchInstance**
```c
// Update Instance
//
instance_v1_t* InstancesV1API_v1PatchInstance(apiClient_t *apiClient, char *instanceId, patch_instance_options_t *patch_instance_options);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID | 
**patch_instance_options** | **[patch_instance_options_t](patch_instance_options.md) \*** |  | 

### Return type

[instance_v1_t](instance_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesV1API_v1PatchInstanceReadOnly**
```c
// Update Instance Read Only
//
instance_v1_t* InstancesV1API_v1PatchInstanceReadOnly(apiClient_t *apiClient, char *instanceId, patch_instance_read_only_t *patch_instance_read_only);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID | 
**patch_instance_read_only** | **[patch_instance_read_only_t](patch_instance_read_only.md) \*** |  | 

### Return type

[instance_v1_t](instance_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesV1API_v1PauseInstance**
```c
// Pause an Instance
//
void InstancesV1API_v1PauseInstance(apiClient_t *apiClient, char *instanceId);
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

# **InstancesV1API_v1PostInstanceInput**
```c
// Provide Instance Input
//
// Sends a touch or button event to the VM.  - Buttons (or keys) to be held during the input are specified as an array of strings, each string must be either a single ascii character or one of the following keywords:   - VM Buttons: finger, homeButton, holdButton, volumeUp, volumeDown, ringerSwitch, backButton, overviewButton   - Keyboard Buttons: again, alt, alterase, apostrophe, back, backslash, backspace, bassboost, bookmarks, bsp, calc, camera, cancel, caps, capslock, chat, close, closecd, comma, compose, computer, config, connect, copy, ctrl, cut, cyclewindows, dashboard, del, delete, deletefile, dot, down, edit, eject, ejectclose, email, end, enter, equal, esc, escape, exit, f1, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f2, f20, f21, f22, f23, f24, f3, f4, f5, f6, f7, f8, f9, fastfwd, file, finance, find, forward, front, grave, hangeul, hanja, help, henkan, home, homepage, hp, hrgn, ins, insert, iso, k102, kp0, kp1, kp2, kp3, kp4, kp5, kp6, kp7, kp8, kp9, kpasterisk, kpcomma, kpdot, kpenter, kpequal, kpjpcomma, kpleftparen, kpminus, kpplus, kpplusminus, kprightparen, kpslash, ktkn, ktknhrgn, left, leftalt, leftbrace, leftctrl, leftmeta, leftshift, linefeed, macro, mail, menu, meta, minus, move, msdos, muhenkan, mute, new, next, numlock, open, pagedown, pageup, paste, pause, pausecd, pgdn, pgup, phone, play, playcd, playpause, power, previous, print, prog1, prog2, prog3, prog4, props, question, record, redo, refresh, return, rewind, right, rightalt, rightbrace, rightctrl, rightmeta, rightshift, ro, rotate, scale, screenlock, scrolldown, scrolllock, scrollup, search, semicolon, sendfile, setup, shift, shop, slash, sleep, sound, space, sport, stop, stopcd, suspend, sysrq, tab, undo, up, voldown, volup, wakeup, www, xfer, yen, zkhk
//
input_response_v1_t* InstancesV1API_v1PostInstanceInput(apiClient_t *apiClient, char *instanceId, list_t *instance_input_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 
**instance_input_request** | **[list_t](instance_input_request.md) \*** | The input to send to the VM | 

### Return type

[input_response_v1_t](input_response_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesV1API_v1RebootInstance**
```c
// Reboot an Instance
//
void InstancesV1API_v1RebootInstance(apiClient_t *apiClient, char *instanceId);
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

# **InstancesV1API_v1RestoreBackup**
```c
// Restore backup
//
void InstancesV1API_v1RestoreBackup(apiClient_t *apiClient, char *instanceId, restore_backup_data_t *restore_backup_data);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 
**restore_backup_data** | **[restore_backup_data_t](restore_backup_data.md) \*** | Restore backup data | [optional] 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesV1API_v1RotateInstance**
```c
// Rotate device to specified orientation
//
// Rotate device to orientation.  Accepted orientations: 1. Portrait 2. Portrait vertically inverted (up-side-down) 3. Landscape with top of the device to the left 4. Landscape with top of the device to the right
//
void InstancesV1API_v1RotateInstance(apiClient_t *apiClient, char *instanceId, rotate_body_v1_t *rotate_body_v1);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** |  | 
**rotate_body_v1** | **[rotate_body_v1_t](rotate_body_v1.md) \*** |  | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesV1API_v1SetInstanceGpios**
```c
// Set Instance GPIOs
//
gpios_state_v1_t* InstancesV1API_v1SetInstanceGpios(apiClient_t *apiClient, char *instanceId, gpios_state_v1_t *gpios_state_v1);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 
**gpios_state_v1** | **[gpios_state_v1_t](gpios_state_v1.md) \*** | New GPIO state | 

### Return type

[gpios_state_v1_t](gpios_state_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesV1API_v1SetInstancePeripherals**
```c
// Set Instance Peripherals
//
peripherals_data_v1_t* InstancesV1API_v1SetInstancePeripherals(apiClient_t *apiClient, char *instanceId, peripherals_data_v1_t *peripherals_data_v1);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 
**peripherals_data_v1** | **[peripherals_data_v1_t](peripherals_data_v1.md) \*** | New peripherals state | 

### Return type

[peripherals_data_v1_t](peripherals_data_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesV1API_v1SetInstanceState**
```c
// Set state of Instance
//
void InstancesV1API_v1SetInstanceState(apiClient_t *apiClient, char *instanceId, v1_set_state_body_t *v1_set_state_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 
**v1_set_state_body** | **[v1_set_state_body_t](v1_set_state_body.md) \*** | Desired State | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesV1API_v1StartInstance**
```c
// Start an Instance
//
void InstancesV1API_v1StartInstance(apiClient_t *apiClient, char *instanceId, instance_start_options_t *instance_start_options);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 
**instance_start_options** | **[instance_start_options_t](instance_start_options.md) \*** | Start options | [optional] 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesV1API_v1StartNetdump**
```c
// Start Enhanced Network Monitor on an instance.
//
void InstancesV1API_v1StartNetdump(apiClient_t *apiClient, char *instanceId, netdump_filter_t *netdump_filter);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 
**netdump_filter** | **[netdump_filter_t](netdump_filter.md) \*** |  | [optional] 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesV1API_v1StartNetworkMonitor**
```c
// Start Network Monitor on an instance.
//
void InstancesV1API_v1StartNetworkMonitor(apiClient_t *apiClient, char *instanceId, sslsplit_filter_t *sslsplit_filter);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 
**sslsplit_filter** | **[sslsplit_filter_t](sslsplit_filter.md) \*** |  | [optional] 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesV1API_v1StopInstance**
```c
// Stop an Instance
//
void InstancesV1API_v1StopInstance(apiClient_t *apiClient, char *instanceId, instance_stop_options_t *instance_stop_options);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 
**instance_stop_options** | **[instance_stop_options_t](instance_stop_options.md) \*** | Stop options | [optional] 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesV1API_v1StopNetdump**
```c
// Stop Enhanced Network Monitor on an instance.
//
void InstancesV1API_v1StopNetdump(apiClient_t *apiClient, char *instanceId);
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

# **InstancesV1API_v1StopNetworkMonitor**
```c
// Stop Network Monitor on an instance.
//
void InstancesV1API_v1StopNetworkMonitor(apiClient_t *apiClient, char *instanceId);
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

# **InstancesV1API_v1UnpauseInstance**
```c
// Unpause an Instance
//
void InstancesV1API_v1UnpauseInstance(apiClient_t *apiClient, char *instanceId);
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

# **InstancesV1API_v1UpgradeInstance**
```c
// Upgrade iOS version
//
void InstancesV1API_v1UpgradeInstance(apiClient_t *apiClient, char *instanceId, instance_upgrade_body_v1_t *instance_upgrade_body_v1);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** |  | 
**instance_upgrade_body_v1** | **[instance_upgrade_body_v1_t](instance_upgrade_body_v1.md) \*** |  | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

