# AgentAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**AgentAPI_v3DeleteFileAgent**](AgentAPI.md#AgentAPI_v3DeleteFileAgent) | **DELETE** /v3/instances/{instanceId}/agent/v1/file/device/{filePath} | Delete a file on VM
[**AgentAPI_v3GetAdbAuthAgent**](AgentAPI.md#AgentAPI_v3GetAdbAuthAgent) | **GET** /v3/instances/{instanceId}/agent/v1/system/adbauth | Get ADB auth setting
[**AgentAPI_v3GetAppReadyAgent**](AgentAPI.md#AgentAPI_v3GetAppReadyAgent) | **GET** /v3/instances/{instanceId}/agent/v1/app/ready | Check if app subsystem is ready
[**AgentAPI_v3GetContainerHealthAgent**](AgentAPI.md#AgentAPI_v3GetContainerHealthAgent) | **GET** /v3/instances/{instanceId}/agent/v1/container/containers/{containerId}/is-healthy | Get container health
[**AgentAPI_v3GetFileAgent**](AgentAPI.md#AgentAPI_v3GetFileAgent) | **GET** /v3/instances/{instanceId}/agent/v1/file/device/{filePath} | Download a file from VM
[**AgentAPI_v3GetNetworkAgent**](AgentAPI.md#AgentAPI_v3GetNetworkAgent) | **GET** /v3/instances/{instanceId}/agent/v1/system/network | Get eth0 IP address
[**AgentAPI_v3GetPropAgent**](AgentAPI.md#AgentAPI_v3GetPropAgent) | **POST** /v3/instances/{instanceId}/agent/v1/system/getprop | Get a system property
[**AgentAPI_v3GetRemoteItStatusAgent**](AgentAPI.md#AgentAPI_v3GetRemoteItStatusAgent) | **GET** /v3/instances/{instanceId}/agent/v1/remoteit/status | Get Remote.It status
[**AgentAPI_v3GetTempFileAgent**](AgentAPI.md#AgentAPI_v3GetTempFileAgent) | **POST** /v3/instances/{instanceId}/agent/v1/file/temp | Get a temp file path on VM
[**AgentAPI_v3InstallAgent**](AgentAPI.md#AgentAPI_v3InstallAgent) | **POST** /v3/instances/{instanceId}/agent/v1/app/install | Install app at path
[**AgentAPI_v3InstallOpenGappsAgent**](AgentAPI.md#AgentAPI_v3InstallOpenGappsAgent) | **POST** /v3/instances/{instanceId}/agent/v1/system/install-opengapps | Install OpenGApps
[**AgentAPI_v3InstallProfileAgent**](AgentAPI.md#AgentAPI_v3InstallProfileAgent) | **POST** /v3/instances/{instanceId}/agent/v1/profile/install | Install a profile
[**AgentAPI_v3InstallRemoteItAgent**](AgentAPI.md#AgentAPI_v3InstallRemoteItAgent) | **POST** /v3/instances/{instanceId}/agent/v1/remoteit/install | Install Remote.It
[**AgentAPI_v3KillAppAgent**](AgentAPI.md#AgentAPI_v3KillAppAgent) | **POST** /v3/instances/{instanceId}/agent/v1/app/apps/{bundleId}/kill | Kill an app
[**AgentAPI_v3KillFridaAgent**](AgentAPI.md#AgentAPI_v3KillFridaAgent) | **POST** /v3/instances/{instanceId}/agent/v1/frida/run-frida-kill | Kill Frida
[**AgentAPI_v3ListAppIconsAgent**](AgentAPI.md#AgentAPI_v3ListAppIconsAgent) | **GET** /v3/instances/{instanceId}/agent/v1/app/icons | List app icons
[**AgentAPI_v3ListAppsAgent**](AgentAPI.md#AgentAPI_v3ListAppsAgent) | **GET** /v3/instances/{instanceId}/agent/v1/app/apps | List apps
[**AgentAPI_v3ListAppsStatusAgent**](AgentAPI.md#AgentAPI_v3ListAppsStatusAgent) | **GET** /v3/instances/{instanceId}/agent/v1/app/apps/update | List apps status
[**AgentAPI_v3ListContainersAgent**](AgentAPI.md#AgentAPI_v3ListContainersAgent) | **GET** /v3/instances/{instanceId}/agent/v1/container/containers | List containers
[**AgentAPI_v3ListFridaProcessesAgent**](AgentAPI.md#AgentAPI_v3ListFridaProcessesAgent) | **POST** /v3/instances/{instanceId}/agent/v1/frida/run-frida-ps | List Frida processes
[**AgentAPI_v3ListProfilesAgent**](AgentAPI.md#AgentAPI_v3ListProfilesAgent) | **GET** /v3/instances/{instanceId}/agent/v1/profile/profiles | List profiles
[**AgentAPI_v3LockAgent**](AgentAPI.md#AgentAPI_v3LockAgent) | **POST** /v3/instances/{instanceId}/agent/v1/system/lock | Lock device
[**AgentAPI_v3PreauthorizeFileArchiveDownloadAgent**](AgentAPI.md#AgentAPI_v3PreauthorizeFileArchiveDownloadAgent) | **POST** /v3/instances/{instanceId}/agent-authorize/v1/file/download | Pre-authorize an archive download from VM
[**AgentAPI_v3PreauthorizeFileDownloadAgent**](AgentAPI.md#AgentAPI_v3PreauthorizeFileDownloadAgent) | **POST** /v3/instances/{instanceId}/agent-authorize/v1/file/device/{filePath} | Pre-authorize a file download from VM
[**AgentAPI_v3RunAppAgent**](AgentAPI.md#AgentAPI_v3RunAppAgent) | **POST** /v3/instances/{instanceId}/agent/v1/app/apps/{bundleId}/run | Run an app
[**AgentAPI_v3RunFridaAgent**](AgentAPI.md#AgentAPI_v3RunFridaAgent) | **POST** /v3/instances/{instanceId}/agent/v1/frida/run-frida | Run Frida
[**AgentAPI_v3SetAdbAuthAgent**](AgentAPI.md#AgentAPI_v3SetAdbAuthAgent) | **PUT** /v3/instances/{instanceId}/agent/v1/system/adbauth | Set ADB auth setting
[**AgentAPI_v3SetDevicePropertiesAgent**](AgentAPI.md#AgentAPI_v3SetDevicePropertiesAgent) | **POST** /v3/instances/{instanceId}/agent/v1/system/setDeviceProperties | Set device properties
[**AgentAPI_v3SetFileAttributesAgent**](AgentAPI.md#AgentAPI_v3SetFileAttributesAgent) | **PATCH** /v3/instances/{instanceId}/agent/v1/file/device/{filePath} | Change attributes of a file on VM
[**AgentAPI_v3SetHostnameAgent**](AgentAPI.md#AgentAPI_v3SetHostnameAgent) | **POST** /v3/instances/{instanceId}/agent/v1/system/setHostname | Set instance hostname
[**AgentAPI_v3ShutdownAgent**](AgentAPI.md#AgentAPI_v3ShutdownAgent) | **POST** /v3/instances/{instanceId}/agent/v1/system/shutdown | Shut down instance
[**AgentAPI_v3StartContainerAgent**](AgentAPI.md#AgentAPI_v3StartContainerAgent) | **POST** /v3/instances/{instanceId}/agent/v1/container/containers/{containerId}/start | Start a container
[**AgentAPI_v3StartContainerAppAgent**](AgentAPI.md#AgentAPI_v3StartContainerAppAgent) | **POST** /v3/instances/{instanceId}/agent/v1/container/containers/{containerId}/start-application/{packageName}/{activityName} | Start an app in a container
[**AgentAPI_v3StartContainerAppMonitoredAgent**](AgentAPI.md#AgentAPI_v3StartContainerAppMonitoredAgent) | **POST** /v3/instances/{instanceId}/agent/v1/container/containers/{containerId}/start-application-and-monitor/{packageName}/{activityName} | Start and monitor an app in a container
[**AgentAPI_v3StopContainerAgent**](AgentAPI.md#AgentAPI_v3StopContainerAgent) | **POST** /v3/instances/{instanceId}/agent/v1/container/containers/{containerId}/stop | Stop a container
[**AgentAPI_v3StopContainerAppAgent**](AgentAPI.md#AgentAPI_v3StopContainerAppAgent) | **POST** /v3/instances/{instanceId}/agent/v1/container/containers/{containerId}/stop-application-if-monitored | Stop a monitored app in a container
[**AgentAPI_v3UninstallAppAgent**](AgentAPI.md#AgentAPI_v3UninstallAppAgent) | **POST** /v3/instances/{instanceId}/agent/v1/app/apps/{bundleId}/uninstall | Uninstall an app
[**AgentAPI_v3UninstallProfileAgent**](AgentAPI.md#AgentAPI_v3UninstallProfileAgent) | **DELETE** /v3/instances/{instanceId}/agent/v1/profile/profiles/{profileId} | Uninstall a profile
[**AgentAPI_v3UninstallRemoteItAgent**](AgentAPI.md#AgentAPI_v3UninstallRemoteItAgent) | **POST** /v3/instances/{instanceId}/agent/v1/remoteit/uninstall | Uninstall Remote.It
[**AgentAPI_v3UnlockAgent**](AgentAPI.md#AgentAPI_v3UnlockAgent) | **POST** /v3/instances/{instanceId}/agent/v1/system/unlock | Unlock device
[**AgentAPI_v3UploadFileAgent**](AgentAPI.md#AgentAPI_v3UploadFileAgent) | **PUT** /v3/instances/{instanceId}/agent/v1/file/device/{filePath} | Upload a file to VM


# **AgentAPI_v3DeleteFileAgent**
```c
// Delete a file on VM
//
// Delete a file from the VM filesystem.  Deletes are idempotent: an unknown `instanceId`, or a path the on-device agent no longer has, is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing. Other agent-reported failures, and an unreachable agent, are still reported as failures.
//
void AgentAPI_v3DeleteFileAgent(apiClient_t *apiClient, char *instanceId, char *filePath);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**filePath** | **char \*** | Path to the file on the VM filesystem. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentAPI_v3GetAdbAuthAgent**
```c
// Get ADB auth setting
//
// Get the current ADB authorization setting (Android only).
//
agent_system_adb_auth_t* AgentAPI_v3GetAdbAuthAgent(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 

### Return type

[agent_system_adb_auth_t](agent_system_adb_auth.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentAPI_v3GetAppReadyAgent**
```c
// Check if app subsystem is ready
//
// Checks whether the device's agent is ready to manage apps. The agent is a helper service running inside the device that carries out the Agent calls (installing and running apps, reading and writing files, and so on). It starts after the device boots, so a device that just turned `on` may not be ready yet. Call this first and wait until it reports ready before using the other Agent endpoints.
//
agent_app_ready_response_t* AgentAPI_v3GetAppReadyAgent(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 

### Return type

[agent_app_ready_response_t](agent_app_ready_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentAPI_v3GetContainerHealthAgent**
```c
// Get container health
//
// Check whether a nested container is healthy (Android only).
//
agent_container_health_t* AgentAPI_v3GetContainerHealthAgent(apiClient_t *apiClient, char *instanceId, char *containerId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**containerId** | **char \*** | Container identifier (the numeric suffix of the container name, e.g. \&quot;1\&quot; for container1). | 

### Return type

[agent_container_health_t](agent_container_health.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentAPI_v3GetFileAgent**
```c
// Download a file from VM
//
// Downloads one file from the device's filesystem, given its full path on the device (for example `/tmp/log.txt`). The response body is the raw file. For large files, use `v3PreauthorizeFileDownloadAgent` so the download does not have to pass through your SDK client.
//
binary_t** AgentAPI_v3GetFileAgent(apiClient_t *apiClient, char *instanceId, char *filePath);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**filePath** | **char \*** | Path to the file on the VM filesystem. | 

### Return type

binary_t**



### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/octet-stream, application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentAPI_v3GetNetworkAgent**
```c
// Get eth0 IP address
//
// Get the IP address bound to eth0 (Android only).
//
agent_system_network_response_t* AgentAPI_v3GetNetworkAgent(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 

### Return type

[agent_system_network_response_t](agent_system_network_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentAPI_v3GetPropAgent**
```c
// Get a system property
//
// Get the value of a system property (Android only).
//
agent_system_get_prop_response_t* AgentAPI_v3GetPropAgent(apiClient_t *apiClient, char *instanceId, agent_system_get_prop_body_t *agent_system_get_prop_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**agent_system_get_prop_body** | **[agent_system_get_prop_body_t](agent_system_get_prop_body.md) \*** |  | 

### Return type

[agent_system_get_prop_response_t](agent_system_get_prop_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentAPI_v3GetRemoteItStatusAgent**
```c
// Get Remote.It status
//
// Get the installation status of the Remote.It package on the VM (RPi only).
//
agent_remote_it_status_t* AgentAPI_v3GetRemoteItStatusAgent(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 

### Return type

[agent_remote_it_status_t](agent_remote_it_status.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentAPI_v3GetTempFileAgent**
```c
// Get a temp file path on VM
//
// Returns an unused temporary file path on the device, free at the moment of the call. Use it as the target for `v3UploadFileAgent`, for example to stage an app package before `v3InstallAgent`.
//
agent_temp_file_response_t* AgentAPI_v3GetTempFileAgent(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 

### Return type

[agent_temp_file_response_t](agent_temp_file_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentAPI_v3InstallAgent**
```c
// Install app at path
//
// Installs an app from a package file that is already on the device, for example an `.ipa` (iOS) or `.apk` (Android). Returns 204 once installed.  **Installing an app from your computer:** 1. `v3GetAppReadyAgent`: wait until the agent is ready. 2. `v3GetTempFileAgent`: get a free temporary path on the device. 3. `v3UploadFileAgent`: upload the package to that path. 4. `v3InstallAgent` (this call) with that `path`. 5. `v3ListAppsAgent` to find the app's bundle ID, then `v3RunAppAgent` to start it.
//
void AgentAPI_v3InstallAgent(apiClient_t *apiClient, char *instanceId, agent_install_body_t *agent_install_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**agent_install_body** | **[agent_install_body_t](agent_install_body.md) \*** |  | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentAPI_v3InstallOpenGappsAgent**
```c
// Install OpenGApps
//
// Download and install OpenGApps on the instance (Android only).
//
void AgentAPI_v3InstallOpenGappsAgent(apiClient_t *apiClient, char *instanceId, agent_system_install_open_gapps_body_t *agent_system_install_open_gapps_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**agent_system_install_open_gapps_body** | **[agent_system_install_open_gapps_body_t](agent_system_install_open_gapps_body.md) \*** |  | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentAPI_v3InstallProfileAgent**
```c
// Install a profile
//
// Install a configuration profile on the VM.
//
void AgentAPI_v3InstallProfileAgent(apiClient_t *apiClient, char *instanceId, binary_t* body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**body** | **binary_t*** |  | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/octet-stream
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentAPI_v3InstallRemoteItAgent**
```c
// Install Remote.It
//
// Install the Remote.It package on the VM (RPi only). The device name and platform code are derived server-side from the instance and its flavor.
//
agent_remote_it_status_t* AgentAPI_v3InstallRemoteItAgent(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 

### Return type

[agent_remote_it_status_t](agent_remote_it_status.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentAPI_v3KillAppAgent**
```c
// Kill an app
//
// Force-quits a running app on the device, identified by its bundle ID. The app stays installed; start it again with `v3RunAppAgent`.
//
void AgentAPI_v3KillAppAgent(apiClient_t *apiClient, char *instanceId, char *bundleId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**bundleId** | **char \*** | App bundle ID. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentAPI_v3KillFridaAgent**
```c
// Kill Frida
//
// Stop the running Frida session on the VM.
//
agent_frida_response_t* AgentAPI_v3KillFridaAgent(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 

### Return type

[agent_frida_response_t](agent_frida_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentAPI_v3ListAppIconsAgent**
```c
// List app icons
//
// List app icons as base64-encoded data for the specified bundle IDs.
//
agent_icons_response_t* AgentAPI_v3ListAppIconsAgent(apiClient_t *apiClient, char *instanceId, char *bundleId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**bundleId** | **char \*** | One or more app bundle IDs to fetch icons for. | 

### Return type

[agent_icons_response_t](agent_icons_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentAPI_v3ListAppsAgent**
```c
// List apps
//
// Lists the apps installed on the device, with each app's bundle ID (for example `com.android.egg`) and name. The bundle ID is what the run, kill and uninstall calls need.
//
agent_apps_list_t* AgentAPI_v3ListAppsAgent(apiClient_t *apiClient, char *instanceId, char *loadIcons);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**loadIcons** | **char \*** | Whether to include each app icon in the response. | [optional] 

### Return type

[agent_apps_list_t](agent_apps_list.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentAPI_v3ListAppsStatusAgent**
```c
// List apps status
//
// Returns, for every installed app, whether it is currently running. Use it to check that an app started after `v3RunAppAgent`, or stopped after `v3KillAppAgent`.
//
agent_apps_status_list_t* AgentAPI_v3ListAppsStatusAgent(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 

### Return type

[agent_apps_status_list_t](agent_apps_status_list.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentAPI_v3ListContainersAgent**
```c
// List containers
//
// List the nested containers on the VM (Android only).
//
agent_container_list_t* AgentAPI_v3ListContainersAgent(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 

### Return type

[agent_container_list_t](agent_container_list.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentAPI_v3ListFridaProcessesAgent**
```c
// List Frida processes
//
// Run frida-ps on the VM and return the list of processes.
//
agent_frida_process_list_t* AgentAPI_v3ListFridaProcessesAgent(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 

### Return type

[agent_frida_process_list_t](agent_frida_process_list.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentAPI_v3ListProfilesAgent**
```c
// List profiles
//
// List the configuration profiles installed on the VM.
//
agent_profile_list_response_t* AgentAPI_v3ListProfilesAgent(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 

### Return type

[agent_profile_list_response_t](agent_profile_list_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentAPI_v3LockAgent**
```c
// Lock device
//
// Lock the device (iOS only).
//
void AgentAPI_v3LockAgent(apiClient_t *apiClient, char *instanceId);
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

# **AgentAPI_v3PreauthorizeFileArchiveDownloadAgent**
```c
// Pre-authorize an archive download from VM
//
// Returns a short-lived token for downloading several files and folders from the device as one ZIP archive, built on the server. List the paths to include in the body, then download with `GET /v1/preauthed/{token}/{filename}`. The token expires with your current session.
//
agent_file_download_token_t* AgentAPI_v3PreauthorizeFileArchiveDownloadAgent(apiClient_t *apiClient, char *instanceId, agent_file_archive_download_body_t *agent_file_archive_download_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**agent_file_archive_download_body** | **[agent_file_archive_download_body_t](agent_file_archive_download_body.md) \*** |  | 

### Return type

[agent_file_download_token_t](agent_file_download_token.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentAPI_v3PreauthorizeFileDownloadAgent**
```c
// Pre-authorize a file download from VM
//
// Returns a short-lived token for downloading one device file directly (for example from a browser or download manager) without an `Authorization` header and without buffering it in your SDK client. Download it with `GET /v1/preauthed/{token}/{filename}`. The token works only for this file and expires with your current session.
//
agent_file_download_token_t* AgentAPI_v3PreauthorizeFileDownloadAgent(apiClient_t *apiClient, char *instanceId, char *filePath);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**filePath** | **char \*** | Path to the file on the VM filesystem. | 

### Return type

[agent_file_download_token_t](agent_file_download_token.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentAPI_v3RunAppAgent**
```c
// Run an app
//
// Launches an installed app on the device, identified by its bundle ID from `v3ListAppsAgent`. Returns 204 once the launch has been requested; check `v3ListAppsStatusAgent` to confirm it is running.
//
void AgentAPI_v3RunAppAgent(apiClient_t *apiClient, char *instanceId, char *bundleId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**bundleId** | **char \*** | App bundle ID. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentAPI_v3RunFridaAgent**
```c
// Run Frida
//
// Attach Frida to a target process on the VM.
//
agent_frida_response_t* AgentAPI_v3RunFridaAgent(apiClient_t *apiClient, char *instanceId, agent_frida_run_body_t *agent_frida_run_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**agent_frida_run_body** | **[agent_frida_run_body_t](agent_frida_run_body.md) \*** |  | 

### Return type

[agent_frida_response_t](agent_frida_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentAPI_v3SetAdbAuthAgent**
```c
// Set ADB auth setting
//
// Enable or disable ADB authorization (Android only).
//
void AgentAPI_v3SetAdbAuthAgent(apiClient_t *apiClient, char *instanceId, agent_system_adb_auth_t *agent_system_adb_auth);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**agent_system_adb_auth** | **[agent_system_adb_auth_t](agent_system_adb_auth.md) \*** |  | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentAPI_v3SetDevicePropertiesAgent**
```c
// Set device properties
//
// Set device properties (model and manufacturer ID) of the instance (Android only).
//
agent_system_result_t* AgentAPI_v3SetDevicePropertiesAgent(apiClient_t *apiClient, char *instanceId, agent_system_set_device_properties_body_t *agent_system_set_device_properties_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**agent_system_set_device_properties_body** | **[agent_system_set_device_properties_body_t](agent_system_set_device_properties_body.md) \*** |  | [optional] 

### Return type

[agent_system_result_t](agent_system_result.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentAPI_v3SetFileAttributesAgent**
```c
// Change attributes of a file on VM
//
// Changes a file on the device: move or rename it (`path`), change its permissions (`mode`), or change its owner. Send only what you want to change.
//
void AgentAPI_v3SetFileAttributesAgent(apiClient_t *apiClient, char *instanceId, char *filePath, agent_file_attributes_body_t *agent_file_attributes_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**filePath** | **char \*** | Path to the file on the VM filesystem. | 
**agent_file_attributes_body** | **[agent_file_attributes_body_t](agent_file_attributes_body.md) \*** |  | [optional] 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentAPI_v3SetHostnameAgent**
```c
// Set instance hostname
//
// Set the hostname of the instance.
//
agent_system_result_t* AgentAPI_v3SetHostnameAgent(apiClient_t *apiClient, char *instanceId, agent_system_set_hostname_body_t *agent_system_set_hostname_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**agent_system_set_hostname_body** | **[agent_system_set_hostname_body_t](agent_system_set_hostname_body.md) \*** |  | 

### Return type

[agent_system_result_t](agent_system_result.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentAPI_v3ShutdownAgent**
```c
// Shut down instance
//
// Shut down the instance.
//
void AgentAPI_v3ShutdownAgent(apiClient_t *apiClient, char *instanceId);
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

# **AgentAPI_v3StartContainerAgent**
```c
// Start a container
//
// Start a nested container on the VM (Android only).
//
void AgentAPI_v3StartContainerAgent(apiClient_t *apiClient, char *instanceId, char *containerId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**containerId** | **char \*** | Container identifier (the numeric suffix of the container name, e.g. \&quot;1\&quot; for container1). | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentAPI_v3StartContainerAppAgent**
```c
// Start an app in a container
//
// Start an Android application in a nested container (Android only).
//
void AgentAPI_v3StartContainerAppAgent(apiClient_t *apiClient, char *instanceId, char *containerId, char *packageName, char *activityName);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**containerId** | **char \*** | Container identifier (the numeric suffix of the container name, e.g. \&quot;1\&quot; for container1). | 
**packageName** | **char \*** | Android package name of the application. | 
**activityName** | **char \*** | Android activity name to launch. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentAPI_v3StartContainerAppMonitoredAgent**
```c
// Start and monitor an app in a container
//
// Start an Android application in a nested container and monitor it (Android only).
//
void AgentAPI_v3StartContainerAppMonitoredAgent(apiClient_t *apiClient, char *instanceId, char *containerId, char *packageName, char *activityName);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**containerId** | **char \*** | Container identifier (the numeric suffix of the container name, e.g. \&quot;1\&quot; for container1). | 
**packageName** | **char \*** | Android package name of the application. | 
**activityName** | **char \*** | Android activity name to launch. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentAPI_v3StopContainerAgent**
```c
// Stop a container
//
// Stop a nested container on the VM (Android only).
//
void AgentAPI_v3StopContainerAgent(apiClient_t *apiClient, char *instanceId, char *containerId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**containerId** | **char \*** | Container identifier (the numeric suffix of the container name, e.g. \&quot;1\&quot; for container1). | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentAPI_v3StopContainerAppAgent**
```c
// Stop a monitored app in a container
//
// Stop the monitored Android application in a nested container, if one is monitored (Android only).
//
void AgentAPI_v3StopContainerAppAgent(apiClient_t *apiClient, char *instanceId, char *containerId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**containerId** | **char \*** | Container identifier (the numeric suffix of the container name, e.g. \&quot;1\&quot; for container1). | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentAPI_v3UninstallAppAgent**
```c
// Uninstall an app
//
// Removes an app from the device, identified by its bundle ID.
//
void AgentAPI_v3UninstallAppAgent(apiClient_t *apiClient, char *instanceId, char *bundleId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**bundleId** | **char \*** | App bundle ID. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentAPI_v3UninstallProfileAgent**
```c
// Uninstall a profile
//
// Uninstall a configuration profile from the VM.  Deletes are idempotent: an unknown `instanceId`, or a profile that is not installed, is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing. Other agent-reported failures, and an unreachable agent, are still reported as failures.
//
void AgentAPI_v3UninstallProfileAgent(apiClient_t *apiClient, char *instanceId, char *profileId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**profileId** | **char \*** | The profile identifier. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentAPI_v3UninstallRemoteItAgent**
```c
// Uninstall Remote.It
//
// Uninstall the Remote.It package from the VM (RPi only).
//
agent_remote_it_status_t* AgentAPI_v3UninstallRemoteItAgent(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 

### Return type

[agent_remote_it_status_t](agent_remote_it_status.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentAPI_v3UnlockAgent**
```c
// Unlock device
//
// Unlock the device (iOS only).
//
void AgentAPI_v3UnlockAgent(apiClient_t *apiClient, char *instanceId);
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

# **AgentAPI_v3UploadFileAgent**
```c
// Upload a file to VM
//
// Writes a file onto the device's filesystem at the given full path, replacing any file already there. Send the raw file bytes as the body. Use `v3GetTempFileAgent` first if you just need somewhere to put a file, for example an app package to install.
//
void AgentAPI_v3UploadFileAgent(apiClient_t *apiClient, char *instanceId, char *filePath, binary_t* body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 
**filePath** | **char \*** | Path to the file on the VM filesystem. | 
**body** | **binary_t*** |  | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/octet-stream
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

