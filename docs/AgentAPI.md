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
// Delete a file from the VM filesystem.
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
// Check if the app subsystem on the VM is ready.
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
// Download a file from the VM filesystem.
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
// Returns a unique temporary file path on the VM filesystem guaranteed to be available at the time of invocation.
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
// Installs the app located at path, which must be present on the VM filesystem.
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
// Kill a running app on the VM.
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
// List installed apps on the VM.
//
agent_apps_list_t* AgentAPI_v3ListAppsAgent(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID. | 

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
// List running status for all installed apps on the VM.
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

# **AgentAPI_v3RunAppAgent**
```c
// Run an app
//
// Run an installed app on the VM.
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
// Change attributes (path, mode, ownership) of a file on the VM filesystem.
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
// Uninstall an app from the VM.
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
// Uninstall a configuration profile from the VM.
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
// Upload a file to the VM filesystem at the specified path.
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

