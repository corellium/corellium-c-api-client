# InstancesAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**InstancesAPI_v3AttachInstanceInterface**](InstancesAPI.md#InstancesAPI_v3AttachInstanceInterface) | **POST** /v3/instances/{instanceId}/interfaces | Attach I/O Interface
[**InstancesAPI_v3ClearInstancePanics**](InstancesAPI.md#InstancesAPI_v3ClearInstancePanics) | **DELETE** /v3/instances/{instanceId}/panics | Clear Panics
[**InstancesAPI_v3CreateInstance**](InstancesAPI.md#InstancesAPI_v3CreateInstance) | **POST** /v3/instances | Create Instance
[**InstancesAPI_v3DeleteInstance**](InstancesAPI.md#InstancesAPI_v3DeleteInstance) | **DELETE** /v3/instances/{instanceId} | Remove Instance
[**InstancesAPI_v3DetachInstanceInterface**](InstancesAPI.md#InstancesAPI_v3DetachInstanceInterface) | **DELETE** /v3/instances/{instanceId}/interfaces/{interfaceId} | Detach I/O Interface
[**InstancesAPI_v3DisableExposePort**](InstancesAPI.md#InstancesAPI_v3DisableExposePort) | **POST** /v3/instances/{instanceId}/exposeport/disable | Disable an exposed port on an instance for device access.
[**InstancesAPI_v3DownloadNetdumpPcap**](InstancesAPI.md#InstancesAPI_v3DownloadNetdumpPcap) | **GET** /v3/instances/{instanceId}/netdump.pcap | Download a netdump pcap file
[**InstancesAPI_v3DownloadNetworkMonitorPcap**](InstancesAPI.md#InstancesAPI_v3DownloadNetworkMonitorPcap) | **GET** /v3/instances/{instanceId}/networkMonitor.pcap | Download a Network Monitor pcap file
[**InstancesAPI_v3EnableExposePort**](InstancesAPI.md#InstancesAPI_v3EnableExposePort) | **POST** /v3/instances/{instanceId}/exposeport/enable | Enable an exposed port on an instance for device access.
[**InstancesAPI_v3GetImageUpload**](InstancesAPI.md#InstancesAPI_v3GetImageUpload) | **GET** /v3/instances/{instance}/image-upload/{type}/{image}/{name} | Get resumable image upload offset
[**InstancesAPI_v3GetInstance**](InstancesAPI.md#InstancesAPI_v3GetInstance) | **GET** /v3/instances/{instanceId} | Get Instance
[**InstancesAPI_v3GetInstanceConsole**](InstancesAPI.md#InstancesAPI_v3GetInstanceConsole) | **GET** /v3/instances/{instanceId}/console | Get console websocket URL
[**InstancesAPI_v3GetInstanceConsoleLog**](InstancesAPI.md#InstancesAPI_v3GetInstanceConsoleLog) | **GET** /v3/instances/{instanceId}/consoleLog | Get Console Log
[**InstancesAPI_v3GetInstanceGpios**](InstancesAPI.md#InstancesAPI_v3GetInstanceGpios) | **GET** /v3/instances/{instanceId}/gpios | Get Instance GPIOs
[**InstancesAPI_v3GetInstancePanics**](InstancesAPI.md#InstancesAPI_v3GetInstancePanics) | **GET** /v3/instances/{instanceId}/panics | Get Panics
[**InstancesAPI_v3GetInstancePeripherals**](InstancesAPI.md#InstancesAPI_v3GetInstancePeripherals) | **GET** /v3/instances/{instanceId}/peripherals | Get Instance Peripherals
[**InstancesAPI_v3GetInstanceQuickConnectCommand**](InstancesAPI.md#InstancesAPI_v3GetInstanceQuickConnectCommand) | **GET** /v3/instances/{instanceId}/quickConnectCommand | Recommended SSH Command for Quick Connect
[**InstancesAPI_v3GetInstanceScreenshot**](InstancesAPI.md#InstancesAPI_v3GetInstanceScreenshot) | **GET** /v3/instances/{instanceId}/screenshot.{format} | Get Instance Screenshot
[**InstancesAPI_v3GetInstanceState**](InstancesAPI.md#InstancesAPI_v3GetInstanceState) | **GET** /v3/instances/{instanceId}/state | Get state of Instance
[**InstancesAPI_v3InjectMessage**](InstancesAPI.md#InstancesAPI_v3InjectMessage) | **POST** /v3/instances/{instanceId}/message | Inject a message into an iOS VM
[**InstancesAPI_v3ListInstances**](InstancesAPI.md#InstancesAPI_v3ListInstances) | **GET** /v3/instances | List Instances
[**InstancesAPI_v3MediaPlay**](InstancesAPI.md#InstancesAPI_v3MediaPlay) | **POST** /v3/instances/{instanceId}/media/play | Start playing media
[**InstancesAPI_v3MediaStop**](InstancesAPI.md#InstancesAPI_v3MediaStop) | **POST** /v3/instances/{instanceId}/media/stop | Stop playing media
[**InstancesAPI_v3PatchInstance**](InstancesAPI.md#InstancesAPI_v3PatchInstance) | **PATCH** /v3/instances/{instanceId} | Update Instance
[**InstancesAPI_v3PatchInstanceReadOnly**](InstancesAPI.md#InstancesAPI_v3PatchInstanceReadOnly) | **PATCH** /v3/instances/{instanceId}/read-only | Update Instance Read Only
[**InstancesAPI_v3PauseInstance**](InstancesAPI.md#InstancesAPI_v3PauseInstance) | **POST** /v3/instances/{instanceId}/pause | Pause an Instance
[**InstancesAPI_v3PostInstanceInput**](InstancesAPI.md#InstancesAPI_v3PostInstanceInput) | **POST** /v3/instances/{instanceId}/input | Provide Instance Input
[**InstancesAPI_v3PutImageUpload**](InstancesAPI.md#InstancesAPI_v3PutImageUpload) | **PUT** /v3/instances/{instance}/image-upload/{type}/{image}/{name} | Upload an image chunk
[**InstancesAPI_v3RebootInstance**](InstancesAPI.md#InstancesAPI_v3RebootInstance) | **POST** /v3/instances/{instanceId}/reboot | Reboot an Instance
[**InstancesAPI_v3RestoreBackup**](InstancesAPI.md#InstancesAPI_v3RestoreBackup) | **POST** /v3/instances/{instanceId}/restoreBackup | Restore backup
[**InstancesAPI_v3RotateInstance**](InstancesAPI.md#InstancesAPI_v3RotateInstance) | **POST** /v3/instances/{instanceId}/rotate | Rotate device to specified orientation
[**InstancesAPI_v3SetInstanceGpios**](InstancesAPI.md#InstancesAPI_v3SetInstanceGpios) | **PUT** /v3/instances/{instanceId}/gpios | Set Instance GPIOs
[**InstancesAPI_v3SetInstancePeripherals**](InstancesAPI.md#InstancesAPI_v3SetInstancePeripherals) | **PUT** /v3/instances/{instanceId}/peripherals | Set Instance Peripherals
[**InstancesAPI_v3StartInstance**](InstancesAPI.md#InstancesAPI_v3StartInstance) | **POST** /v3/instances/{instanceId}/start | Start an Instance
[**InstancesAPI_v3StartNetdump**](InstancesAPI.md#InstancesAPI_v3StartNetdump) | **POST** /v3/instances/{instanceId}/netdump/enable | Start Enhanced Network Monitor on an instance.
[**InstancesAPI_v3StartNetworkMonitor**](InstancesAPI.md#InstancesAPI_v3StartNetworkMonitor) | **POST** /v3/instances/{instanceId}/sslsplit/enable | Start Network Monitor on an instance.
[**InstancesAPI_v3StopInstance**](InstancesAPI.md#InstancesAPI_v3StopInstance) | **POST** /v3/instances/{instanceId}/stop | Stop an Instance
[**InstancesAPI_v3StopNetdump**](InstancesAPI.md#InstancesAPI_v3StopNetdump) | **POST** /v3/instances/{instanceId}/netdump/disable | Stop Enhanced Network Monitor on an instance.
[**InstancesAPI_v3StopNetworkMonitor**](InstancesAPI.md#InstancesAPI_v3StopNetworkMonitor) | **POST** /v3/instances/{instanceId}/sslsplit/disable | Stop Network Monitor on an instance.
[**InstancesAPI_v3UnpauseInstance**](InstancesAPI.md#InstancesAPI_v3UnpauseInstance) | **POST** /v3/instances/{instanceId}/unpause | Unpause an Instance
[**InstancesAPI_v3UpgradeInstance**](InstancesAPI.md#InstancesAPI_v3UpgradeInstance) | **POST** /v3/instances/{instanceId}/upgrade | Upgrade iOS version
[**InstancesAPI_v3ValidateInstanceToken**](InstancesAPI.md#InstancesAPI_v3ValidateInstanceToken) | **POST** /v3/instances/{instanceId}/token/validate | Validate instance token


# **InstancesAPI_v3AttachInstanceInterface**
```c
// Attach I/O Interface
//
// Attach an I/O interface to an I/O interconnect for the specified instance identifier.
//
void InstancesAPI_v3AttachInstanceInterface(apiClient_t *apiClient, char *instanceId, attach_interface_body_t *attach_interface_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**attach_interface_body** | **[attach_interface_body_t](attach_interface_body.md) \*** | Interface attachment request. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesAPI_v3ClearInstancePanics**
```c
// Clear Panics
//
void InstancesAPI_v3ClearInstancePanics(apiClient_t *apiClient, char *instanceId);
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

# **InstancesAPI_v3CreateInstance**
```c
// Create Instance
//
create_instance_response_t* InstancesAPI_v3CreateInstance(apiClient_t *apiClient, create_instance_body_t *create_instance_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**create_instance_body** | **[create_instance_body_t](create_instance_body.md) \*** | The VM definition to create. | 

### Return type

[create_instance_response_t](create_instance_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesAPI_v3DeleteInstance**
```c
// Remove Instance
//
void InstancesAPI_v3DeleteInstance(apiClient_t *apiClient, char *instanceId);
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

# **InstancesAPI_v3DetachInstanceInterface**
```c
// Detach I/O Interface
//
// Detach an I/O interface from an I/O interconnect for the specified instance identifier.
//
void InstancesAPI_v3DetachInstanceInterface(apiClient_t *apiClient, char *instanceId, char *interfaceId, detach_interface_body_t *detach_interface_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**interfaceId** | **char \*** | Interface ID. | 
**detach_interface_body** | **[detach_interface_body_t](detach_interface_body.md) \*** | Interface detachment request. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesAPI_v3DisableExposePort**
```c
// Disable an exposed port on an instance for device access.
//
void InstancesAPI_v3DisableExposePort(apiClient_t *apiClient, char *instanceId);
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

# **InstancesAPI_v3DownloadNetdumpPcap**
```c
// Download a netdump pcap file
//
binary_t** InstancesAPI_v3DownloadNetdumpPcap(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 

### Return type

binary_t**



### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/vnd.tcpdump.pcap, application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesAPI_v3DownloadNetworkMonitorPcap**
```c
// Download a Network Monitor pcap file
//
// Downloads the Network Monitor capture for the instance as a pcap file.
//
binary_t** InstancesAPI_v3DownloadNetworkMonitorPcap(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 

### Return type

binary_t**



### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/vnd.tcpdump.pcap, application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesAPI_v3EnableExposePort**
```c
// Enable an exposed port on an instance for device access.
//
void InstancesAPI_v3EnableExposePort(apiClient_t *apiClient, char *instanceId);
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

# **InstancesAPI_v3GetImageUpload**
```c
// Get resumable image upload offset
//
// Returns the current offset for a resumable image upload so the client knows where to continue.
//
object_t* InstancesAPI_v3GetImageUpload(apiClient_t *apiClient, char *instance, char *type, char *image, char *name);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instance** | **char \*** | Instance ID. | 
**type** | **char \*** | Image type. | 
**image** | **char \*** | Image identifier. | 
**name** | **char \*** | File name. | 

### Return type

[object_t](object.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesAPI_v3GetInstance**
```c
// Get Instance
//
instance_t* InstancesAPI_v3GetInstance(apiClient_t *apiClient, char *instanceId, char *returnAttr);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**returnAttr** | **char \*** | Attributes to include in instance return. | [optional] 

### Return type

[instance_t](instance.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesAPI_v3GetInstanceConsole**
```c
// Get console websocket URL
//
instance_console_endpoint_t* InstancesAPI_v3GetInstanceConsole(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 

### Return type

[instance_console_endpoint_t](instance_console_endpoint.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesAPI_v3GetInstanceConsoleLog**
```c
// Get Console Log
//
char* InstancesAPI_v3GetInstanceConsoleLog(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 

### Return type

char*



### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: text/plain, application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesAPI_v3GetInstanceGpios**
```c
// Get Instance GPIOs
//
gpios_state_t* InstancesAPI_v3GetInstanceGpios(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 

### Return type

[gpios_state_t](gpios_state.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesAPI_v3GetInstancePanics**
```c
// Get Panics
//
list_t* InstancesAPI_v3GetInstancePanics(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 

### Return type

[list_t](object.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesAPI_v3GetInstancePeripherals**
```c
// Get Instance Peripherals
//
peripherals_data_t* InstancesAPI_v3GetInstancePeripherals(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 

### Return type

[peripherals_data_t](peripherals_data.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesAPI_v3GetInstanceQuickConnectCommand**
```c
// Recommended SSH Command for Quick Connect
//
char* InstancesAPI_v3GetInstanceQuickConnectCommand(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 

### Return type

char*



### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesAPI_v3GetInstanceScreenshot**
```c
// Get Instance Screenshot
//
binary_t** InstancesAPI_v3GetInstanceScreenshot(apiClient_t *apiClient, char *instanceId, char *format, double *scale);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**format** | **char \*** | Screenshot format. | 
**scale** | **double \*** | Screenshot scale 1:N. | [optional] 

### Return type

binary_t**



### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: image/png, image/jpeg, application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesAPI_v3GetInstanceState**
```c
// Get state of Instance
//
instance_state_t* InstancesAPI_v3GetInstanceState(apiClient_t *apiClient, char *instanceId, char *returnAttr);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**returnAttr** | **char \*** | The attributes to return. | [optional] 

### Return type

[instance_state_t](instance_state.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesAPI_v3InjectMessage**
```c
// Inject a message into an iOS VM
//
// Given a message and source phone number, place this message as an incoming SMS message on the iOS VM. A raw hex-encoded message body may also be sent.
//
void InstancesAPI_v3InjectMessage(apiClient_t *apiClient, char *instanceId, message_body_t *message_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**message_body** | **[message_body_t](message_body.md) \*** | Message data. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesAPI_v3ListInstances**
```c
// List Instances
//
instance_list_t* InstancesAPI_v3ListInstances(apiClient_t *apiClient, double *limit, double *offset, char *name, char *returnAttr);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**limit** | **double \*** | Maximum number of results to return. | [optional] [default to 100]
**offset** | **double \*** | Number of results to skip. | [optional] [default to 0]
**name** | **char \*** | Optionally filter by instance name. | [optional] 
**returnAttr** | **char \*** | Attributes to include in instance return. | [optional] 

### Return type

[instance_list_t](instance_list.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesAPI_v3MediaPlay**
```c
// Start playing media
//
void InstancesAPI_v3MediaPlay(apiClient_t *apiClient, char *instanceId, media_play_body_t *media_play_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**media_play_body** | **[media_play_body_t](media_play_body.md) \*** |  | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesAPI_v3MediaStop**
```c
// Stop playing media
//
void InstancesAPI_v3MediaStop(apiClient_t *apiClient, char *instanceId);
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

# **InstancesAPI_v3PatchInstance**
```c
// Update Instance
//
// Update instance configuration such as name, boot options, and proxy settings. To change an instance run state, use the start, stop, reboot, pause, and unpause action endpoints.
//
instance_t* InstancesAPI_v3PatchInstance(apiClient_t *apiClient, char *instanceId, patch_instance_body_t *patch_instance_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**patch_instance_body** | **[patch_instance_body_t](patch_instance_body.md) \*** |  | 

### Return type

[instance_t](instance.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesAPI_v3PatchInstanceReadOnly**
```c
// Update Instance Read Only
//
// Updates the read-only state of the instance.
//
instance_t* InstancesAPI_v3PatchInstanceReadOnly(apiClient_t *apiClient, char *instanceId, patch_instance_read_only_body_t *patch_instance_read_only_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**patch_instance_read_only_body** | **[patch_instance_read_only_body_t](patch_instance_read_only_body.md) \*** |  | 

### Return type

[instance_t](instance.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesAPI_v3PauseInstance**
```c
// Pause an Instance
//
void InstancesAPI_v3PauseInstance(apiClient_t *apiClient, char *instanceId);
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

# **InstancesAPI_v3PostInstanceInput**
```c
// Provide Instance Input
//
// Sends a touch or button event to the VM.
//
input_response_t* InstancesAPI_v3PostInstanceInput(apiClient_t *apiClient, char *instanceId, list_t *instance_input_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**instance_input_body** | **[list_t](instance_input_body.md) \*** | The input to send to the VM. | 

### Return type

[input_response_t](input_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesAPI_v3PutImageUpload**
```c
// Upload an image chunk
//
// Uploads a chunk of image data as part of a resumable image upload.
//
object_t* InstancesAPI_v3PutImageUpload(apiClient_t *apiClient, char *instance, char *type, char *image, char *name, binary_t* body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instance** | **char \*** | Instance ID. | 
**type** | **char \*** | Image type. | 
**image** | **char \*** | Image identifier. | 
**name** | **char \*** | File name. | 
**body** | **binary_t*** |  | 

### Return type

[object_t](object.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/octet-stream
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesAPI_v3RebootInstance**
```c
// Reboot an Instance
//
void InstancesAPI_v3RebootInstance(apiClient_t *apiClient, char *instanceId);
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

# **InstancesAPI_v3RestoreBackup**
```c
// Restore backup
//
void InstancesAPI_v3RestoreBackup(apiClient_t *apiClient, char *instanceId, restore_backup_body_t *restore_backup_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**restore_backup_body** | **[restore_backup_body_t](restore_backup_body.md) \*** | Restore backup data. | [optional] 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesAPI_v3RotateInstance**
```c
// Rotate device to specified orientation
//
// Rotate device to orientation. 1=Portrait, 2=Portrait inverted, 3=Landscape (top left), 4=Landscape (top right).
//
void InstancesAPI_v3RotateInstance(apiClient_t *apiClient, char *instanceId, rotate_body_t *rotate_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**rotate_body** | **[rotate_body_t](rotate_body.md) \*** |  | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesAPI_v3SetInstanceGpios**
```c
// Set Instance GPIOs
//
gpios_state_t* InstancesAPI_v3SetInstanceGpios(apiClient_t *apiClient, char *instanceId, gpios_state_t *gpios_state);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**gpios_state** | **[gpios_state_t](gpios_state.md) \*** | New GPIO state. | 

### Return type

[gpios_state_t](gpios_state.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesAPI_v3SetInstancePeripherals**
```c
// Set Instance Peripherals
//
peripherals_data_t* InstancesAPI_v3SetInstancePeripherals(apiClient_t *apiClient, char *instanceId, peripherals_data_t *peripherals_data);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**peripherals_data** | **[peripherals_data_t](peripherals_data.md) \*** | New peripherals state. | 

### Return type

[peripherals_data_t](peripherals_data.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesAPI_v3StartInstance**
```c
// Start an Instance
//
void InstancesAPI_v3StartInstance(apiClient_t *apiClient, char *instanceId, start_instance_body_t *start_instance_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**start_instance_body** | **[start_instance_body_t](start_instance_body.md) \*** | Start options. | [optional] 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesAPI_v3StartNetdump**
```c
// Start Enhanced Network Monitor on an instance.
//
void InstancesAPI_v3StartNetdump(apiClient_t *apiClient, char *instanceId, enable_netdump_body_t *enable_netdump_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**enable_netdump_body** | **[enable_netdump_body_t](enable_netdump_body.md) \*** |  | [optional] 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesAPI_v3StartNetworkMonitor**
```c
// Start Network Monitor on an instance.
//
void InstancesAPI_v3StartNetworkMonitor(apiClient_t *apiClient, char *instanceId, enable_sslsplit_body_t *enable_sslsplit_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**enable_sslsplit_body** | **[enable_sslsplit_body_t](enable_sslsplit_body.md) \*** |  | [optional] 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesAPI_v3StopInstance**
```c
// Stop an Instance
//
void InstancesAPI_v3StopInstance(apiClient_t *apiClient, char *instanceId, stop_instance_body_t *stop_instance_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**stop_instance_body** | **[stop_instance_body_t](stop_instance_body.md) \*** | Stop options. | [optional] 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesAPI_v3StopNetdump**
```c
// Stop Enhanced Network Monitor on an instance.
//
void InstancesAPI_v3StopNetdump(apiClient_t *apiClient, char *instanceId);
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

# **InstancesAPI_v3StopNetworkMonitor**
```c
// Stop Network Monitor on an instance.
//
void InstancesAPI_v3StopNetworkMonitor(apiClient_t *apiClient, char *instanceId);
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

# **InstancesAPI_v3UnpauseInstance**
```c
// Unpause an Instance
//
void InstancesAPI_v3UnpauseInstance(apiClient_t *apiClient, char *instanceId);
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

# **InstancesAPI_v3UpgradeInstance**
```c
// Upgrade iOS version
//
instance_upgrade_response_t* InstancesAPI_v3UpgradeInstance(apiClient_t *apiClient, char *instanceId, instance_upgrade_body_t *instance_upgrade_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**instance_upgrade_body** | **[instance_upgrade_body_t](instance_upgrade_body.md) \*** |  | 

### Return type

[instance_upgrade_response_t](instance_upgrade_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesAPI_v3ValidateInstanceToken**
```c
// Validate instance token
//
// Validates a connection token for the instance.
//
void InstancesAPI_v3ValidateInstanceToken(apiClient_t *apiClient, char *instanceId, token_validate_body_t *token_validate_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**token_validate_body** | **[token_validate_body_t](token_validate_body.md) \*** |  | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

