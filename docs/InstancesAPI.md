# InstancesAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**InstancesAPI_v3AttachInstanceInterface**](InstancesAPI.md#InstancesAPI_v3AttachInstanceInterface) | **POST** /v3/instances/{instanceId}/interfaces | Connect an I/O interface
[**InstancesAPI_v3ClearInstancePanics**](InstancesAPI.md#InstancesAPI_v3ClearInstancePanics) | **DELETE** /v3/instances/{instanceId}/panics | Clear kernel panics
[**InstancesAPI_v3CreateInstance**](InstancesAPI.md#InstancesAPI_v3CreateInstance) | **POST** /v3/instances | Create a device
[**InstancesAPI_v3DeleteInstance**](InstancesAPI.md#InstancesAPI_v3DeleteInstance) | **DELETE** /v3/instances/{instanceId} | Remove Instance
[**InstancesAPI_v3DetachInstanceInterface**](InstancesAPI.md#InstancesAPI_v3DetachInstanceInterface) | **DELETE** /v3/instances/{instanceId}/interfaces/{interfaceId} | Disconnect an I/O interface
[**InstancesAPI_v3DisableExposePort**](InstancesAPI.md#InstancesAPI_v3DisableExposePort) | **POST** /v3/instances/{instanceId}/exposeport/disable | Stop exposing the device port
[**InstancesAPI_v3DownloadNetdumpPcap**](InstancesAPI.md#InstancesAPI_v3DownloadNetdumpPcap) | **GET** /v3/instances/{instanceId}/netdump.pcap | Download the Enhanced Network Monitor capture
[**InstancesAPI_v3DownloadNetworkMonitorPcap**](InstancesAPI.md#InstancesAPI_v3DownloadNetworkMonitorPcap) | **GET** /v3/instances/{instanceId}/networkMonitor.pcap | Download the Network Monitor capture
[**InstancesAPI_v3EnableExposePort**](InstancesAPI.md#InstancesAPI_v3EnableExposePort) | **POST** /v3/instances/{instanceId}/exposeport/enable | Expose the device port
[**InstancesAPI_v3GetInstance**](InstancesAPI.md#InstancesAPI_v3GetInstance) | **GET** /v3/instances/{instanceId} | Get a device
[**InstancesAPI_v3GetInstanceConsole**](InstancesAPI.md#InstancesAPI_v3GetInstanceConsole) | **GET** /v3/instances/{instanceId}/console | Get console websocket URL
[**InstancesAPI_v3GetInstanceConsoleLog**](InstancesAPI.md#InstancesAPI_v3GetInstanceConsoleLog) | **GET** /v3/instances/{instanceId}/consoleLog | Read the console log
[**InstancesAPI_v3GetInstanceGpios**](InstancesAPI.md#InstancesAPI_v3GetInstanceGpios) | **GET** /v3/instances/{instanceId}/gpios | Read board LEDs, buttons and switches
[**InstancesAPI_v3GetInstanceImageUpload**](InstancesAPI.md#InstancesAPI_v3GetInstanceImageUpload) | **GET** /v3/instances/{instance}/image-upload/{type}/{imageId}/{name} | Get image upload status
[**InstancesAPI_v3GetInstancePanics**](InstancesAPI.md#InstancesAPI_v3GetInstancePanics) | **GET** /v3/instances/{instanceId}/panics | List kernel panics
[**InstancesAPI_v3GetInstancePeripherals**](InstancesAPI.md#InstancesAPI_v3GetInstancePeripherals) | **GET** /v3/instances/{instanceId}/peripherals | Read simulated sensors
[**InstancesAPI_v3GetInstanceQuickConnectCommand**](InstancesAPI.md#InstancesAPI_v3GetInstanceQuickConnectCommand) | **GET** /v3/instances/{instanceId}/quickConnectCommand | Get the SSH quick-connect command
[**InstancesAPI_v3GetInstanceScreenshot**](InstancesAPI.md#InstancesAPI_v3GetInstanceScreenshot) | **GET** /v3/instances/{instanceId}/screenshot.{format} | Take a screenshot
[**InstancesAPI_v3GetInstanceState**](InstancesAPI.md#InstancesAPI_v3GetInstanceState) | **GET** /v3/instances/{instanceId}/state | Get a device&#39;s state
[**InstancesAPI_v3InjectMessage**](InstancesAPI.md#InstancesAPI_v3InjectMessage) | **POST** /v3/instances/{instanceId}/message | Send an SMS message to an iOS device
[**InstancesAPI_v3KernelPreauthorize**](InstancesAPI.md#InstancesAPI_v3KernelPreauthorize) | **GET** /v3/instances/{instanceId}/kernel-authorize | Get a kernel download token
[**InstancesAPI_v3ListInstances**](InstancesAPI.md#InstancesAPI_v3ListInstances) | **GET** /v3/instances | List Instances
[**InstancesAPI_v3MediaPlay**](InstancesAPI.md#InstancesAPI_v3MediaPlay) | **POST** /v3/instances/{instanceId}/media/play | Play a video or audio file into the device
[**InstancesAPI_v3MediaStop**](InstancesAPI.md#InstancesAPI_v3MediaStop) | **POST** /v3/instances/{instanceId}/media/stop | Stop playing media
[**InstancesAPI_v3PatchInstance**](InstancesAPI.md#InstancesAPI_v3PatchInstance) | **PATCH** /v3/instances/{instanceId} | Change device settings
[**InstancesAPI_v3PatchInstanceReadOnly**](InstancesAPI.md#InstancesAPI_v3PatchInstanceReadOnly) | **PATCH** /v3/instances/{instanceId}/read-only | Update Instance Read Only
[**InstancesAPI_v3PauseInstance**](InstancesAPI.md#InstancesAPI_v3PauseInstance) | **POST** /v3/instances/{instanceId}/pause | Pause a device
[**InstancesAPI_v3PostInstanceInput**](InstancesAPI.md#InstancesAPI_v3PostInstanceInput) | **POST** /v3/instances/{instanceId}/input | Provide Instance Input
[**InstancesAPI_v3PutInstanceImageUpload**](InstancesAPI.md#InstancesAPI_v3PutInstanceImageUpload) | **PUT** /v3/instances/{instance}/image-upload/{type}/{imageId}/{name} | Upload image chunk
[**InstancesAPI_v3RebootInstance**](InstancesAPI.md#InstancesAPI_v3RebootInstance) | **POST** /v3/instances/{instanceId}/reboot | Restart a device
[**InstancesAPI_v3RestoreBackup**](InstancesAPI.md#InstancesAPI_v3RestoreBackup) | **POST** /v3/instances/{instanceId}/restoreBackup | Restore a backup onto a device
[**InstancesAPI_v3RotateInstance**](InstancesAPI.md#InstancesAPI_v3RotateInstance) | **POST** /v3/instances/{instanceId}/rotate | Rotate the device
[**InstancesAPI_v3SetInstanceGpios**](InstancesAPI.md#InstancesAPI_v3SetInstanceGpios) | **PUT** /v3/instances/{instanceId}/gpios | Press board buttons or flip switches
[**InstancesAPI_v3SetInstancePeripherals**](InstancesAPI.md#InstancesAPI_v3SetInstancePeripherals) | **PUT** /v3/instances/{instanceId}/peripherals | Change simulated sensors
[**InstancesAPI_v3StartInstance**](InstancesAPI.md#InstancesAPI_v3StartInstance) | **POST** /v3/instances/{instanceId}/start | Turn a device on
[**InstancesAPI_v3StartNetdump**](InstancesAPI.md#InstancesAPI_v3StartNetdump) | **POST** /v3/instances/{instanceId}/netdump/enable | Start Enhanced Network Monitor
[**InstancesAPI_v3StartNetworkMonitor**](InstancesAPI.md#InstancesAPI_v3StartNetworkMonitor) | **POST** /v3/instances/{instanceId}/sslsplit/enable | Start Network Monitor
[**InstancesAPI_v3StopInstance**](InstancesAPI.md#InstancesAPI_v3StopInstance) | **POST** /v3/instances/{instanceId}/stop | Turn a device off
[**InstancesAPI_v3StopNetdump**](InstancesAPI.md#InstancesAPI_v3StopNetdump) | **POST** /v3/instances/{instanceId}/netdump/disable | Stop Enhanced Network Monitor
[**InstancesAPI_v3StopNetworkMonitor**](InstancesAPI.md#InstancesAPI_v3StopNetworkMonitor) | **POST** /v3/instances/{instanceId}/sslsplit/disable | Stop Network Monitor
[**InstancesAPI_v3UnpauseInstance**](InstancesAPI.md#InstancesAPI_v3UnpauseInstance) | **POST** /v3/instances/{instanceId}/unpause | Resume a paused device
[**InstancesAPI_v3UpgradeInstance**](InstancesAPI.md#InstancesAPI_v3UpgradeInstance) | **POST** /v3/instances/{instanceId}/upgrade | Upgrade the iOS version
[**InstancesAPI_v3ValidateInstanceToken**](InstancesAPI.md#InstancesAPI_v3ValidateInstanceToken) | **POST** /v3/instances/{instanceId}/token/validate | Check a device connection token


# **InstancesAPI_v3AttachInstanceInterface**
```c
// Connect an I/O interface
//
// Connects one of this device's I/O interfaces (for example a GPIO bank, `gpio/0`) to an I/O interconnect, a virtual wire that links interfaces on different devices so they can signal each other. Create the interconnect first with the Interconnects endpoints. Requires the configurable I/O license feature (403 otherwise).
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
// Clear kernel panics
//
// Deletes the recorded kernel panics for this device, so the next `v3GetInstancePanics` shows only new ones. An unknown `instanceId` is a successful no-op that returns 204.
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
// Create a device
//
// Creates a new virtual device (instance) in a project. This returns quickly with the new `id` and `state: \"creating\"`; the device is then built in the background, which can take several minutes. Poll `v3GetInstanceState` (or `v3GetInstance`) until the state is `on` before using it. If it becomes `error`, read the instance's `error` field.  **Minimum request:** `projectId`, `flavor`, and `osVersion` and/or `osBuild`.  **Typical steps:** 1. `GET /v3/models`: pick a model and note its `flavor`, allowed cores, and memory. 2. `GET /v3/models/{model}/software`: pick a build and note its `osVersion` and `osBuild`. 3. `POST /v3/instances` with `{ \"projectId\", \"flavor\", \"osVersion\", \"osBuild\" }`. Add `name` so you can find it later, and `bootOptions` (for example `cores`, `ram`) to change the defaults. 4. Poll the state until `on`.  **How the operating system is chosen.** With both `osVersion` and `osBuild`, that exact build is used. With only `osBuild`, the build with that ID is used. With only `osVersion`, the newest build of that version is used. To boot your own firmware file instead, set `fwPackage`.  Some options need license features (for example creating devices from custom firmware, or custom model definitions via `charmBootArgs`); using one your license lacks returns 403.
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
// Disconnect an I/O interface
//
// Disconnects one of this device's I/O interfaces from an I/O interconnect. Requires the configurable I/O license feature.  Deletes are idempotent: an unknown instance, interconnect or interface, including one that was already detached, is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing.
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
// Stop exposing the device port
//
// Turns off the exposed port enabled with `v3EnableExposePort`. Runs as a background task on the device; returns 204 once it is scheduled.
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
// Download the Enhanced Network Monitor capture
//
// Downloads the packets recorded by Enhanced Network Monitor (see `v3StartNetdump`) as a pcapng file, which packet analyzers such as Wireshark open directly. Requires the Enhanced Network Monitor feature (403 otherwise).
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
// Download the Network Monitor capture
//
// Downloads the traffic recorded by Network Monitor (see `v3StartNetworkMonitor`) as a pcap file. Save it with a `.pcap` extension and open it in a packet analyzer such as Wireshark. Download while monitoring runs or after stopping it.
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
// Expose the device port
//
// Turns on the exposed port for this device, for device access. This runs as a background task on the device; returns 204 once it is scheduled. Undo with `v3DisableExposePort`.
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
// Get a device
//
// Returns everything about one device: its name, model, operating system, state, boot options, network details and consoles. Use `state` to see whether it is ready, and `error` to see why it failed. Pass `returnAttr` to get only some fields.
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
// Get console WebSocket URL.  Instances can have more than one console. To connect to a specific console: 1. Call Get Instance and read the `consoles` array. 2. Take the `id` of the console you want and remove the `port-` prefix (e.g. `port-uart7-cons` becomes `uart7-cons`). 3. Pass that value as the `type` query parameter (e.g. `?type=uart7-cons`).  If `type` is omitted, the default console (`cons`) is used. Some models have no default console and require `type`.
//
instance_console_endpoint_t* InstancesAPI_v3GetInstanceConsole(apiClient_t *apiClient, char *instanceId, char *type);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**type** | **char \*** | Console to connect to: a &#x60;consoles[].id&#x60; from Get Instance with the &#x60;port-&#x60; prefix removed. Defaults to &#x60;cons&#x60;. | [optional] 

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
// Read the console log
//
// Returns the text output of the device's main console (serial output from boot messages, the kernel and system services) as plain text. Useful for seeing why a device will not boot. For a live, interactive console, use `v3GetInstanceConsole` instead.
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
// Read board LEDs, buttons and switches
//
// Returns the current state of the simulated LEDs, buttons and switches (GPIO pins) on an IoT or embedded board model, for example whether an LED your firmware drives is lit. The device must be running. Phone models do not have these, and the request fails for them. See `GpiosState` for the format.
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
// Checks the progress of a chunked upload made with `v3PutInstanceImageUpload`, or downloads the finished file. With chunk parameters (`resumableChunkNumber` and friends) it returns 200 if that chunk is already stored and 204 if it still needs to be sent; without them it downloads the image file.
//
binary_t** InstancesAPI_v3GetInstanceImageUpload(apiClient_t *apiClient, char *instance, char *type, char *imageId, char *name, double *resumableChunkNumber);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instance** | **char \*** | Instance ID. | 
**type** | **char \*** | What kind of file this is, for example &#x60;fw&#x60; for firmware or &#x60;kernel&#x60;. Uses the same values as &#x60;type&#x60; on &#x60;POST /v3/images&#x60;; see &#x60;ImageType&#x60; for what each means. Types that need a license feature your license lacks are rejected with 403. | 
**imageId** | **char \*** | An ID you choose for the new image: generate a random UUID once per file and use the same value for every chunk of that file. The image record is created with this ID when the first chunk arrives. Use a new UUID for each new upload. | 
**name** | **char \*** | The file name to store, URL-encoded (for example &#x60;my%20firmware.ipsw&#x60;). Becomes the image &#x60;name&#x60;. | 
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
// List kernel panics
//
// Returns the kernel panics (crashes of the operating system itself) recorded on this device, as a list of panic records. An empty list means none have happened since the last clear. Clear them with `v3ClearInstancePanics`.
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
// Read simulated sensors
//
// Returns the current values of the device's simulated sensors and hardware: motion (accelerometer, gyroscope, compass), environment (temperature, light, pressure, humidity, proximity), GPS location, battery, and biometric bypass. Only values the device reports are included; a missing field does not mean zero. See `PeripheralsData`.
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
// Get the SSH quick-connect command
//
// Returns a ready-to-paste SSH command for connecting to this device, as a JSON string. Run it in a terminal on a computer that can reach the device, for example one connected with the project VPN (`GET /v3/projects/{projectId}/vpnconfig/{format}`).
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
// Take a screenshot
//
// Captures what the device's screen shows right now and returns it as an image. Choose the file type in the path: `screenshot.png` or `screenshot.jpeg`. Use `scale` to shrink it: `scale=2` returns half the width and height, `scale=4` a quarter; the default 1 is full size. The device must be running.
//
binary_t** InstancesAPI_v3GetInstanceScreenshot(apiClient_t *apiClient, char *instanceId, char *format, double *scale);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**format** | **char \*** | Image file type: &#x60;png&#x60; (lossless, larger) or &#x60;jpeg&#x60; (smaller). | 
**scale** | **double \*** | Shrink factor. The image is 1/N of full size in each direction. Whole number; defaults to 1 (full size). | [optional] 

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
// Get a device's state
//
// Returns only the device's current state (for example `creating`, `on`, `off`), as a bare JSON string. This is the call to poll while waiting for a device to finish creating, starting, stopping or rebooting. See `InstanceState` for what each value means.
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
// Send an SMS message to an iOS device
//
// Delivers a text message to an iOS device as if it arrived over the cellular network, so apps see a normal incoming SMS. Useful for testing one-time-password and verification-code flows. Send either `number` (the sender's phone number) and `message` (the text), or `raw` with the message bytes in hexadecimal for low-level testing. The device must be running.
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
// Get a kernel download token
//
// Returns a short-lived token that authorizes downloading this device's kernel file without an `Authorization` header, for loading into a disassembler or debugger. Download with `GET /v1/preauthed/{token}/{filename}`. The token works only for this device's kernel and expires when your current session token expires.
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
// Lists the devices (instances) you can access across your projects. Results are paginated with `limit` and `offset`; use `name` to find a device by name. To list only one project's devices, use `GET /v3/projects/{projectId}/instances`.
//
instance_list_t* InstancesAPI_v3ListInstances(apiClient_t *apiClient, double *limit, double *offset, char *name, char *returnAttr);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**limit** | **double \*** | Most results to return in one page. Whole number from 1 to 1000; defaults to 100. A value outside that range is rejected with 400. | [optional] [default to 100]
**offset** | **double \*** | How many results to skip before this page starts; defaults to 0. To get the next page, add &#x60;limit&#x60; to the previous &#x60;offset&#x60;. | [optional] [default to 0]
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
// Play a video or audio file into the device
//
// Plays a media file into the device, so apps receive it as if it came from the device's camera (video) and microphone (audio). Use it to test camera or scanning features, for example feeding a QR code video to an app. Open the camera app on the device to see it.  Give exactly one source: `imageId` of a `media` image you uploaded with `POST /v3/images`, or a `url` the platform can download the file from. Returns 204 once playback starts. Call `v3MediaStop` to stop it.
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
// Stops media started with `v3MediaPlay`.
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
// Change device settings
//
// Changes a device's settings. Send only the fields you want to change: `name` (the label shown in lists), `bootOptions` (for example `cores`, `ram`, boot arguments), `proxy` (which device ports are forwarded, and whether they are reachable from outside the project), and `straceFilter` (which processes CoreTrace records, by name, process ID or thread ID; see `v3ListThreads`). Returns the updated device. This call does not turn the device on or off; use `v3StartInstance`, `v3StopInstance`, `v3RebootInstance`, `v3PauseInstance` and `v3UnpauseInstance` for that.
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
// Turns read-only mode on or off for the device. Returns the updated device.
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
// Pause a device
//
// Freezes a running device in place without shutting it down: it stops executing but keeps its memory and state, so `v3UnpauseInstance` resumes it exactly where it stopped. The state becomes `paused`.
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
// Uploads one chunk of a file attached to this device, using the same resumable protocol as `PUT /v3/images/{imageId}/file`. You choose the image ID (a new random UUID) and the image record is created on the first chunk; `type` and `name` in the path set the image type and name. Because the image is attached to the device, it replaces any image of the same `type` already attached (for `partition`, only the one with the same `name`), and it is deleted when the device is deleted. The web interface uses this route, for example to replace a kernel. For your own code, `POST /v3/images` with `instanceId` followed by `PUT /v3/images/{imageId}/file` is easier to follow. Returns 200 with an empty object for each stored chunk.
//
object_t* InstancesAPI_v3PutInstanceImageUpload(apiClient_t *apiClient, char *instance, char *type, char *imageId, char *name, binary_t* body, double *resumableChunkNumber, double *resumableChunkSize, double *resumableCurrentChunkSize, double *resumableTotalSize, double *resumableTotalChunks, char *corelliumChecksum, char *flavor, char *x_corellium_image_encoding, int *x_corellium_image_encapsulated, double *x_corellium_total_file_size, char *x_corellium_image_password);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instance** | **char \*** | Instance ID. | 
**type** | **char \*** | What kind of file this is, for example &#x60;fw&#x60; for firmware or &#x60;kernel&#x60;. Uses the same values as &#x60;type&#x60; on &#x60;POST /v3/images&#x60;; see &#x60;ImageType&#x60; for what each means. Types that need a license feature your license lacks are rejected with 403. | 
**imageId** | **char \*** | An ID you choose for the new image: generate a random UUID once per file and use the same value for every chunk of that file. The image record is created with this ID when the first chunk arrives. Use a new UUID for each new upload. | 
**name** | **char \*** | The file name to store, URL-encoded (for example &#x60;my%20firmware.ipsw&#x60;). Becomes the image &#x60;name&#x60;. | 
**body** | **binary_t*** |  | 
**resumableChunkNumber** | **double \*** | Which chunk this is, counting from 1. | [optional] 
**resumableChunkSize** | **double \*** | The size, in bytes, you split the file into. Use the same value for every chunk; only the last chunk may be smaller. If you send &#x60;corelliumChecksum&#x60;, this must equal the block size inside it. | [optional] 
**resumableCurrentChunkSize** | **double \*** | Actual size in bytes of this chunk&#39;s body. | [optional] 
**resumableTotalSize** | **double \*** | Size of the whole file in bytes. | [optional] 
**resumableTotalChunks** | **double \*** | How many chunks the whole file is split into. The upload completes when the last one arrives. | [optional] 
**corelliumChecksum** | **char \*** | Optional expected checksum of the whole file, formatted &#x60;algorithm$blockSize$hash&#x60;. When given, the finished upload is checked and rejected (and the image removed) if it does not match. Required for firmware (&#x60;fw&#x60;) uploads on air-gapped deployments. | [optional] 
**flavor** | **char \*** | Device model (&#x60;flavor&#x60; from &#x60;GET /v3/models&#x60;) the image is for. Needed for &#x60;partition&#x60; uploads when the image is not attached to a device, so the partition name can be checked against that model. | [optional] 
**x_corellium_image_encoding** | **char \*** | How the file is stored: &#x60;plain&#x60; (normal) or &#x60;encrypted&#x60;. Only read on the first chunk, when the image record is created; later chunks cannot change it. | [optional] 
**x_corellium_image_encapsulated** | **int \*** | Whether the uploaded file is a ZIP wrapper the platform should unpack. Send false to store the file exactly as uploaded. Only read on the first chunk, when the image record is created. | [optional] 
**x_corellium_total_file_size** | **double \*** | Size of the whole file in bytes. Send it on every chunk: the platform uses it to check up front that there is room for the entire file, and answers 507 if there is not, before storing any data. | [optional] 
**x_corellium_image_password** | **char \*** | Password of a password-protected file (for example encrypted firmware), used to check the file after upload. Leave out for normal files. | [optional] 

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
// Restart a device
//
// Restarts a running device. Returns 204 once the reboot is accepted; the state becomes `rebooting` and then `on`. Poll `v3GetInstanceState` to see when it is back.
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
// Restore a backup onto a device
//
// Restores the backup attached to this device, replacing the device's data with the backup's contents. First attach the backup file by uploading it with `POST /v3/images` using `type: \"backup\"` and `instanceId` set to this device. Returns 204 once the restore has been scheduled; it runs in the background, so poll `v3GetInstanceState` until the device settles.  Supply `password` if the backup is encrypted. Fails with 404 if no backup is attached. Requires the backup-restore license feature (403 otherwise).
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
// Rotate the device
//
// Turns the device to a new orientation, as if you rotated the phone in your hand; apps receive the rotation event. `orientation` is 1 = portrait, 2 = portrait upside down, 3 = landscape (top of device on the left), 4 = landscape (top of device on the right).
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
// Press board buttons or flip switches
//
// Sets the state of the simulated buttons and switches (GPIO pins) on an IoT or embedded board model, as if you pressed a button or flipped a switch on real hardware; your firmware sees the change. Send the full bank layout you got from `v3GetInstanceGpios`, with the bits you want changed. Returns the state after the change. The device must be running.
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
// Change simulated sensors
//
// Changes what the device's simulated sensors report to apps, for example to fake a GPS location, a low battery, or a tilt. Send only the fields you want to change. The new values are saved with the device and then the current readings are returned.  A field is applied only if its feature is enabled for the device (motion, environment, location, battery, biometric bypass); values for disabled features are ignored silently, so check the response. `biometricPass: 1` makes fingerprint and face checks succeed.
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
// Turn a device on
//
// Turns on a device that is `off`. Returns 204 as soon as the start is accepted; the device then boots in the background. Poll `v3GetInstanceState` until it is `on`. Returns 409 if the device is already on.  **Starting paused (`paused: true`).** The device is powered on but no code runs until you call `v3UnpauseInstance` or resume it from a debugger. This is the standard way to debug a device from its very first instruction, for example custom or IoT firmware, or code that runs early in boot: 1. Upload your firmware and create the device (or stop an existing one). 2. `v3StartInstance` with `{ \"paused\": true }`. 3. Connect your debugger (for example GDB) to the device's debug port, shown in the device's connection details. 4. Load symbols from your firmware or kernel file, set breakpoints, or load code into memory. 5. Continue execution from the debugger (`c` in GDB).  Once a debugger is attached, pause and resume from the debugger rather than with `v3PauseInstance` / `v3UnpauseInstance`: GDB expects to control pausing itself, and pausing through the API can confuse its session.  **Network monitoring (`sockCap: true`).** Starts the device with process network monitoring enabled, so network activity can be attributed to the processes that made it.
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
// Start Enhanced Network Monitor
//
// Starts Enhanced Network Monitor on this device. It captures raw network packets, and every filter in the body is optional: limit the capture to certain ports, protocols, hosts, or process names to keep it small. Download it with `v3DownloadNetdumpPcap`. Requires the Enhanced Network Monitor feature (403 otherwise).
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
// Start Network Monitor
//
// Starts Network Monitor on this device. It records the device's network traffic, including HTTPS traffic decrypted by intercepting its encryption, so you can see what apps send and receive. Download the capture as a pcap file (open it with Wireshark) with `v3DownloadNetworkMonitorPcap`. Apps that pin their certificates may refuse the intercepted connections. Requires the Network Monitor license feature (403 otherwise).
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
// Turn a device off
//
// Turns a running device off. By default (`soft: true`) the operating system is asked to shut down cleanly. Send `{ \"soft\": false }` to force an immediate stop instead; use it when a clean shutdown does not finish. Returns 204 once the stop is accepted; poll `v3GetInstanceState` until it is `off`. Returns 409 if the device is already off. A stopped device keeps its storage and can be turned on again with `v3StartInstance`.
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
// Stop Enhanced Network Monitor
//
// Stops Enhanced Network Monitor on this device. The capture so far can still be downloaded with `v3DownloadNetdumpPcap`.
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
// Stop Network Monitor
//
// Stops Network Monitor on this device. The capture so far can still be downloaded with `v3DownloadNetworkMonitorPcap`. Requires the Network Monitor license feature.
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
// Resume a paused device
//
// Resumes a device that was paused with `v3PauseInstance`, or started with `paused: true`. It continues from exactly where it stopped.
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
// Upgrade the iOS version
//
// Upgrades an iOS device to a newer iOS version while keeping it as the same device. Returns 202 with `state: \"updating\"` once accepted; the upgrade runs in the background, so poll `v3GetInstanceState` until it is `on`. Pick the version from `GET /v3/models/{model}/software`. Use `osVersion`; the old `os` field is rejected. Requires the OS update license feature (403 otherwise).
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
// Check a device connection token
//
// Checks whether a connection token issued for this device is still valid. Returns 204 if it is. This call needs no `Authorization` header; the token in the body is what is checked.
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

