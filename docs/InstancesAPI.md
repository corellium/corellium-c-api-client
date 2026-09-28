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
[**InstancesAPI_v3GetInstance**](InstancesAPI.md#InstancesAPI_v3GetInstance) | **GET** /v3/instances/{instanceId} | Get Instance
[**InstancesAPI_v3GetInstanceConsole**](InstancesAPI.md#InstancesAPI_v3GetInstanceConsole) | **GET** /v3/instances/{instanceId}/console | Get console websocket URL
[**InstancesAPI_v3GetInstanceConsoleLog**](InstancesAPI.md#InstancesAPI_v3GetInstanceConsoleLog) | **GET** /v3/instances/{instanceId}/consoleLog | Get Console Log
[**InstancesAPI_v3GetInstanceGpios**](InstancesAPI.md#InstancesAPI_v3GetInstanceGpios) | **GET** /v3/instances/{instanceId}/gpios | Get Instance GPIOs
[**InstancesAPI_v3GetInstanceImageUpload**](InstancesAPI.md#InstancesAPI_v3GetInstanceImageUpload) | **GET** /v3/instances/{instance}/image-upload/{type}/{imageId}/{name} | Get image upload status
[**InstancesAPI_v3GetInstancePanics**](InstancesAPI.md#InstancesAPI_v3GetInstancePanics) | **GET** /v3/instances/{instanceId}/panics | Get Panics
[**InstancesAPI_v3GetInstancePeripherals**](InstancesAPI.md#InstancesAPI_v3GetInstancePeripherals) | **GET** /v3/instances/{instanceId}/peripherals | Get Instance Peripherals
[**InstancesAPI_v3GetInstanceQuickConnectCommand**](InstancesAPI.md#InstancesAPI_v3GetInstanceQuickConnectCommand) | **GET** /v3/instances/{instanceId}/quickConnectCommand | Recommended SSH Command for Quick Connect
[**InstancesAPI_v3GetInstanceScreenshot**](InstancesAPI.md#InstancesAPI_v3GetInstanceScreenshot) | **GET** /v3/instances/{instanceId}/screenshot.{format} | Get Instance Screenshot
[**InstancesAPI_v3GetInstanceState**](InstancesAPI.md#InstancesAPI_v3GetInstanceState) | **GET** /v3/instances/{instanceId}/state | Get state of Instance
[**InstancesAPI_v3InjectMessage**](InstancesAPI.md#InstancesAPI_v3InjectMessage) | **POST** /v3/instances/{instanceId}/message | Inject a message into an iOS VM
[**InstancesAPI_v3KernelPreauthorize**](InstancesAPI.md#InstancesAPI_v3KernelPreauthorize) | **GET** /v3/instances/{instanceId}/kernel-authorize | Pre-authorize a kernel download
[**InstancesAPI_v3ListInstances**](InstancesAPI.md#InstancesAPI_v3ListInstances) | **GET** /v3/instances | List Instances
[**InstancesAPI_v3MediaPlay**](InstancesAPI.md#InstancesAPI_v3MediaPlay) | **POST** /v3/instances/{instanceId}/media/play | Start playing media
[**InstancesAPI_v3MediaStop**](InstancesAPI.md#InstancesAPI_v3MediaStop) | **POST** /v3/instances/{instanceId}/media/stop | Stop playing media
[**InstancesAPI_v3PatchInstance**](InstancesAPI.md#InstancesAPI_v3PatchInstance) | **PATCH** /v3/instances/{instanceId} | Update Instance
[**InstancesAPI_v3PatchInstanceReadOnly**](InstancesAPI.md#InstancesAPI_v3PatchInstanceReadOnly) | **PATCH** /v3/instances/{instanceId}/read-only | Update Instance Read Only
[**InstancesAPI_v3PauseInstance**](InstancesAPI.md#InstancesAPI_v3PauseInstance) | **POST** /v3/instances/{instanceId}/pause | Pause an Instance
[**InstancesAPI_v3PostInstanceInput**](InstancesAPI.md#InstancesAPI_v3PostInstanceInput) | **POST** /v3/instances/{instanceId}/input | Provide Instance Input
[**InstancesAPI_v3PutInstanceImageUpload**](InstancesAPI.md#InstancesAPI_v3PutInstanceImageUpload) | **PUT** /v3/instances/{instance}/image-upload/{type}/{imageId}/{name} | Upload image chunk
[**InstancesAPI_v3RebootInstance**](InstancesAPI.md#InstancesAPI_v3RebootInstance) | **POST** /v3/instances/{instanceId}/reboot | Reboot an Instance
[**InstancesAPI_v3RestoreBackup**](InstancesAPI.md#InstancesAPI_v3RestoreBackup) | **POST** /v3/instances/{instanceId}/restoreBackup | Restore backup
[**InstancesAPI_v3RotateInstance**](InstancesAPI.md#InstancesAPI_v3RotateInstance) | **POST** /v3/instances/{instanceId}/rotate | Rotate device to specified orientation
[**InstancesAPI_v3SetInstanceGpios**](InstancesAPI.md#InstancesAPI_v3SetInstanceGpios) | **PUT** /v3/instances/{instanceId}/gpios | Set Instance GPIOs
[**InstancesAPI_v3SetInstancePeripherals**](InstancesAPI.md#InstancesAPI_v3SetInstancePeripherals) | **PUT** /v3/instances/{instanceId}/peripherals | Update Instance Peripherals
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
// Clear panics. An unknown `instanceId` is a successful no-op that returns 204.
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
// Removes the instance. Deletion is asynchronous: the call schedules the teardown and returns 204 immediately, while the instance remains visible in a `deleting` state until teardown completes.  An `instanceId` that does not exist also returns 204. The API cannot tell a call with an invalid ID apart from a second call made to confirm an earlier delete succeeded, so both succeed. Repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing. A repeat therefore returns 204 both while the record is still present in the `deleting` state and after it has disappeared.
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
// Detach an I/O interface from an I/O interconnect for the specified instance identifier.  Deletes are idempotent: an unknown instance, interconnect or interface, including one that was already detached, is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing.
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

# **InstancesAPI_v3GetInstanceImageUpload**
```c
// Get image upload status
//
// Check resumable upload status for an instance image or download the image file.
//
binary_t** InstancesAPI_v3GetInstanceImageUpload(apiClient_t *apiClient, char *instance, char *type, char *imageId, char *name, double *resumableChunkNumber);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instance** | **char \*** | Instance ID. | 
**type** | **char \*** | Image type. | 
**imageId** | **char \*** | Client-generated image identifier. The image record is created on the first chunk. | 
**name** | **char \*** | URL-encoded image filename. | 
**resumableChunkNumber** | **double \*** | Chunk number. When present the response reports whether that chunk was already stored (200) or still needs to be uploaded (204) instead of returning the image file. | [optional] 

### Return type

binary_t**



### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/octet-stream, application/json

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

# **InstancesAPI_v3KernelPreauthorize**
```c
// Pre-authorize a kernel download
//
// Pre-authorize a kernel download. Returns a token that authorizes the kernel download request.
//
token_t* InstancesAPI_v3KernelPreauthorize(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 

### Return type

[token_t](token.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
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
// Sends a touch or button event to the VM. Events in the request array are processed in order.  Each element of the request array is one of: - **TouchInputRequest** – holds buttons (or keys) and/or touches at a screen position.   - Set `buttons` to `[\"finger\"]` to press down and `[]` to release all buttons.   - Omit `buttons` to leave the current press state unchanged.   - `position` is an array of per-finger `[x, y]` coordinates. May be omitted for button-only input. - **TouchCurveInputRequest** – animates a drag/swipe from `start` to `end` over `duration` ms.   - Optional `bezierPoints` shape the path; omit for a straight-line drag. - **TextInputRequest** – types the given text.  Buttons (or keys) accepted by `buttons` / `startButtons` / `endButtons` are an array of strings, each either a single ASCII character or one of the following keywords: - VM buttons (case-insensitive): `finger`, `homeButton`, `holdButton` (Power/Hold),   `volumeUp`, `volumeDown`, `backButton`, `overviewButton`. `ringerSwitch` is not supported. - Keyboard key names: `again`, `alt`, `alterase`, `apostrophe`, `back`, `backslash`, `backspace`,   `bassboost`, `bookmarks`, `bsp`, `calc`, `camera`, `cancel`, `caps`, `capslock`, `chat`, `close`,   `closecd`, `comma`, `compose`, `computer`, `config`, `connect`, `copy`, `ctrl`, `cut`,   `cyclewindows`, `dashboard`, `del`, `delete`, `deletefile`, `dot`, `down`, `edit`, `eject`,   `ejectclose`, `email`, `end`, `enter`, `equal`, `esc`, `escape`, `exit`, `f1`–`f24`, `fastfwd`,   `file`, `finance`, `find`, `forward`, `front`, `grave`, `hangeul`, `hanja`, `help`,   `henkan`, `home`, `homepage`, `hp`, `hrgn`, `ins`, `insert`, `iso`, `k102`, `kp0`–`kp9`,   `kpasterisk`, `kpcomma`, `kpdot`, `kpenter`, `kpequal`, `kpjpcomma`, `kpleftparen`, `kpminus`,   `kpplus`, `kpplusminus`, `kprightparen`, `kpslash`, `ktkn`, `ktknhrgn`, `left`, `leftalt`,   `leftbrace`, `leftctrl`, `leftmeta`, `leftshift`, `linefeed`, `macro`, `mail`, `menu`, `meta`,   `minus`, `move`, `msdos`, `muhenkan`, `mute`, `new`, `next`, `numlock`, `open`, `pagedown`,   `pageup`, `paste`, `pause`, `pausecd`, `pgdn`, `pgup`, `phone`, `play`, `playcd`, `playpause`,   `power`, `previous`, `print`, `prog1`–`prog4`, `props`, `question`, `record`, `redo`, `refresh`,   `return`, `rewind`, `right`, `rightalt`, `rightbrace`, `rightctrl`, `rightmeta`, `rightshift`,   `ro`, `rotate`, `scale`, `screenlock`, `scrolldown`, `scrolllock`, `scrollup`, `search`,   `semicolon`, `sendfile`, `setup`, `shift`, `shop`, `slash`, `sleep`, `sound`, `space`, `sport`,   `stop`, `stopcd`, `suspend`, `sysrq`, `tab`, `undo`, `up`, `voldown`, `volup`, `wakeup`, `www`,   `xfer`, `yen`, `zkhk`.  Use `finger:1` to press the fingerprint sensor (see the `fingerprint` example).
//
input_response_t* InstancesAPI_v3PostInstanceInput(apiClient_t *apiClient, char *instanceId, list_t *instance_input_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**instance_input_body** | **[list_t](instance_input_body.md) \*** | Array of input events to send to the VM. | 

### Return type

[input_response_t](input_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InstancesAPI_v3PutInstanceImageUpload**
```c
// Upload image chunk
//
// Upload a chunk of an instance image using the resumable upload protocol. Creates the image record on the first chunk if it does not yet exist.
//
object_t* InstancesAPI_v3PutInstanceImageUpload(apiClient_t *apiClient, char *instance, char *type, char *imageId, char *name, binary_t* body, double *resumableChunkNumber, double *resumableChunkSize, double *resumableCurrentChunkSize, double *resumableTotalSize, double *resumableTotalChunks, char *corelliumChecksum, char *flavor, char *x_corellium_image_encoding, int *x_corellium_image_encapsulated, double *x_corellium_total_file_size, char *x_corellium_image_password);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instance** | **char \*** | Instance ID. | 
**type** | **char \*** | Image type. | 
**imageId** | **char \*** | Client-generated image identifier. The image record is created on the first chunk. | 
**name** | **char \*** | URL-encoded image filename. | 
**body** | **binary_t*** |  | 
**resumableChunkNumber** | **double \*** | Chunk sequence number. | [optional] 
**resumableChunkSize** | **double \*** | Size of each chunk. | [optional] 
**resumableCurrentChunkSize** | **double \*** | Size of the current chunk. | [optional] 
**resumableTotalSize** | **double \*** | Total file size. | [optional] 
**resumableTotalChunks** | **double \*** | Total number of chunks. | [optional] 
**corelliumChecksum** | **char \*** | Corellium checksum. Required for firmware uploads in airgapped deployments. | [optional] 
**flavor** | **char \*** | Flavor identifier to associate with the image. | [optional] 
**x_corellium_image_encoding** | **char \*** | How the uploaded file is stored. Set on the first chunk, when the image record is created. | [optional] 
**x_corellium_image_encapsulated** | **int \*** | Whether the uploaded file is an archive the coordinator should unpack. Set false to store the file as uploaded. Set on the first chunk, when the image record is created. | [optional] 
**x_corellium_total_file_size** | **double \*** | Total size of the whole file in bytes. Preferred over Content-Length for the pre-flight image-pool space check on on-site clusters, which is what produces the 507 response. | [optional] 
**x_corellium_image_password** | **char \*** | Password used to open a password-protected image during post-upload validation. | [optional] 

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
// Update Instance Peripherals
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

