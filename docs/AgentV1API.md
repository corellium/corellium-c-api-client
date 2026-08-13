# AgentV1API

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**AgentV1API_v1AgentAppReady**](AgentV1API.md#AgentV1API_v1AgentAppReady) | **GET** /v1/instances/{instanceId}/agent/v1/app/ready | Check if App subsystem is ready
[**AgentV1API_v1AgentDeleteFile**](AgentV1API.md#AgentV1API_v1AgentDeleteFile) | **DELETE** /v1/instances/{instanceId}/agent/v1/file/device/{filePath} | Delete a File on VM
[**AgentV1API_v1AgentGetFile**](AgentV1API.md#AgentV1API_v1AgentGetFile) | **GET** /v1/instances/{instanceId}/agent/v1/file/device/{filePath} | Download a File from VM
[**AgentV1API_v1AgentGetTempFilename**](AgentV1API.md#AgentV1API_v1AgentGetTempFilename) | **POST** /v1/instances/{instanceId}/agent/v1/file/temp | Get the path for a new temp file
[**AgentV1API_v1AgentInstallApp**](AgentV1API.md#AgentV1API_v1AgentInstallApp) | **POST** /v1/instances/{instanceId}/agent/v1/app/install | Install App at path
[**AgentV1API_v1AgentInstallProfile**](AgentV1API.md#AgentV1API_v1AgentInstallProfile) | **POST** /v1/instances/{instanceId}/agent/v1/profile/install | Install a Profile to VM
[**AgentV1API_v1AgentKillApp**](AgentV1API.md#AgentV1API_v1AgentKillApp) | **POST** /v1/instances/{instanceId}/agent/v1/app/apps/{bundleId}/kill | Kill an App
[**AgentV1API_v1AgentListAppIcons**](AgentV1API.md#AgentV1API_v1AgentListAppIcons) | **GET** /v1/instances/{instanceId}/agent/v1/app/icons | List App Icons
[**AgentV1API_v1AgentListApps**](AgentV1API.md#AgentV1API_v1AgentListApps) | **GET** /v1/instances/{instanceId}/agent/v1/app/apps | List Apps
[**AgentV1API_v1AgentListAppsStatus**](AgentV1API.md#AgentV1API_v1AgentListAppsStatus) | **GET** /v1/instances/{instanceId}/agent/v1/app/apps/update | List Apps Status
[**AgentV1API_v1AgentListProfiles**](AgentV1API.md#AgentV1API_v1AgentListProfiles) | **GET** /v1/instances/{instanceId}/agent/v1/profile/profiles | List Profiles
[**AgentV1API_v1AgentRunApp**](AgentV1API.md#AgentV1API_v1AgentRunApp) | **POST** /v1/instances/{instanceId}/agent/v1/app/apps/{bundleId}/run | Run an App
[**AgentV1API_v1AgentSetFileAttributes**](AgentV1API.md#AgentV1API_v1AgentSetFileAttributes) | **PATCH** /v1/instances/{instanceId}/agent/v1/file/device/{filePath} | Change Attrs of a File on VM
[**AgentV1API_v1AgentSystemGetAdbAuth**](AgentV1API.md#AgentV1API_v1AgentSystemGetAdbAuth) | **GET** /v1/instances/{instanceId}/agent/v1/system/adbauth | Get ADB Auth Setting (AOSP only)
[**AgentV1API_v1AgentSystemGetNetwork**](AgentV1API.md#AgentV1API_v1AgentSystemGetNetwork) | **GET** /v1/instances/{instanceId}/agent/v1/system/network | Get IP of eth0 (AOSP only)
[**AgentV1API_v1AgentSystemGetProp**](AgentV1API.md#AgentV1API_v1AgentSystemGetProp) | **POST** /v1/instances/{instanceId}/agent/v1/system/getprop | Get System Property (AOSP only)
[**AgentV1API_v1AgentSystemInstallOpenGApps**](AgentV1API.md#AgentV1API_v1AgentSystemInstallOpenGApps) | **POST** /v1/instances/{instanceId}/agent/v1/system/install-opengapps | Install OpenGApps (AOSP only)
[**AgentV1API_v1AgentSystemLock**](AgentV1API.md#AgentV1API_v1AgentSystemLock) | **POST** /v1/instances/{instanceId}/agent/v1/system/lock | Lock Device (iOS Only)
[**AgentV1API_v1AgentSystemSetAdbAuth**](AgentV1API.md#AgentV1API_v1AgentSystemSetAdbAuth) | **PUT** /v1/instances/{instanceId}/agent/v1/system/adbauth | Set ADB Auth Setting (AOSP only)
[**AgentV1API_v1AgentSystemSetHostname**](AgentV1API.md#AgentV1API_v1AgentSystemSetHostname) | **POST** /v1/instances/{instanceId}/agent/v1/system/setHostname | Set Hostname of instance
[**AgentV1API_v1AgentSystemShutdown**](AgentV1API.md#AgentV1API_v1AgentSystemShutdown) | **POST** /v1/instances/{instanceId}/agent/v1/system/shutdown | Instruct VM to halt
[**AgentV1API_v1AgentSystemUnlock**](AgentV1API.md#AgentV1API_v1AgentSystemUnlock) | **POST** /v1/instances/{instanceId}/agent/v1/system/unlock | Unlock Device (iOS Only)
[**AgentV1API_v1AgentUninstallApp**](AgentV1API.md#AgentV1API_v1AgentUninstallApp) | **POST** /v1/instances/{instanceId}/agent/v1/app/apps/{bundleId}/uninstall | Uninstall an App
[**AgentV1API_v1AgentUninstallProfile**](AgentV1API.md#AgentV1API_v1AgentUninstallProfile) | **DELETE** /v1/instances/{instanceId}/agent/v1/profile/profiles/{profileId} | Uninstall a Profile from VM
[**AgentV1API_v1AgentUploadFile**](AgentV1API.md#AgentV1API_v1AgentUploadFile) | **PUT** /v1/instances/{instanceId}/agent/v1/file/device/{filePath} | Upload a file to VM


# **AgentV1API_v1AgentAppReady**
```c
// Check if App subsystem is ready
//
agent_app_ready_response_v1_t* AgentV1API_v1AgentAppReady(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 

### Return type

[agent_app_ready_response_v1_t](agent_app_ready_response_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentV1API_v1AgentDeleteFile**
```c
// Delete a File on VM
//
void AgentV1API_v1AgentDeleteFile(apiClient_t *apiClient, char *instanceId, char *filePath);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 
**filePath** | **char \*** | File Path on VM | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentV1API_v1AgentGetFile**
```c
// Download a File from VM
//
binary_t** AgentV1API_v1AgentGetFile(apiClient_t *apiClient, char *instanceId, char *filePath);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 
**filePath** | **char \*** | File Path on VM | 

### Return type

binary_t**



### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/octet-stream, application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentV1API_v1AgentGetTempFilename**
```c
// Get the path for a new temp file
//
// Returns a temporary random filename that is guranteed to be unique on the VMs filesystem at the time of invocation of this method.
//
char* AgentV1API_v1AgentGetTempFilename(apiClient_t *apiClient, char *instanceId);
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

# **AgentV1API_v1AgentInstallApp**
```c
// Install App at path
//
// Installs the app located at path which must be present on the VM filesystem
//
void AgentV1API_v1AgentInstallApp(apiClient_t *apiClient, char *instanceId, agent_install_body_v1_t *agent_install_body_v1);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 
**agent_install_body_v1** | **[agent_install_body_v1_t](agent_install_body_v1.md) \*** | App parameters | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentV1API_v1AgentInstallProfile**
```c
// Install a Profile to VM
//
void AgentV1API_v1AgentInstallProfile(apiClient_t *apiClient, char *instanceId, binary_t* body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 
**body** | **binary_t*** | Profile to Install | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/octet-stream
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentV1API_v1AgentKillApp**
```c
// Kill an App
//
object_t* AgentV1API_v1AgentKillApp(apiClient_t *apiClient, char *instanceId, char *bundleId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 
**bundleId** | **char \*** | App Bundle ID | 

### Return type

[object_t](object.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentV1API_v1AgentListAppIcons**
```c
// List App Icons
//
// List App Icons as base64 data
//
list_t* AgentV1API_v1AgentListAppIcons(apiClient_t *apiClient, char *instanceId, char *bundleID);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 
**bundleID** | **char \*** | App Bundle ID | 

### Return type

[list_t](agent_icons.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentV1API_v1AgentListApps**
```c
// List Apps
//
agent_apps_list_v1_t* AgentV1API_v1AgentListApps(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 

### Return type

[agent_apps_list_v1_t](agent_apps_list_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentV1API_v1AgentListAppsStatus**
```c
// List Apps Status
//
agent_apps_list_v1_t* AgentV1API_v1AgentListAppsStatus(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 

### Return type

[agent_apps_list_v1_t](agent_apps_list_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentV1API_v1AgentListProfiles**
```c
// List Profiles
//
agent_profiles_return_t* AgentV1API_v1AgentListProfiles(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 

### Return type

[agent_profiles_return_t](agent_profiles_return.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentV1API_v1AgentRunApp**
```c
// Run an App
//
object_t* AgentV1API_v1AgentRunApp(apiClient_t *apiClient, char *instanceId, char *bundleId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 
**bundleId** | **char \*** | App Bundle ID | 

### Return type

[object_t](object.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentV1API_v1AgentSetFileAttributes**
```c
// Change Attrs of a File on VM
//
void AgentV1API_v1AgentSetFileAttributes(apiClient_t *apiClient, char *instanceId, char *filePath, file_changes_t *file_changes);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 
**filePath** | **char \*** | File Path on VM | 
**file_changes** | **[file_changes_t](file_changes.md) \*** | New attrs | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentV1API_v1AgentSystemGetAdbAuth**
```c
// Get ADB Auth Setting (AOSP only)
//
agent_system_adb_auth_v1_t* AgentV1API_v1AgentSystemGetAdbAuth(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 

### Return type

[agent_system_adb_auth_v1_t](agent_system_adb_auth_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentV1API_v1AgentSystemGetNetwork**
```c
// Get IP of eth0 (AOSP only)
//
agent_value_return_t* AgentV1API_v1AgentSystemGetNetwork(apiClient_t *apiClient, char *instanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 

### Return type

[agent_value_return_t](agent_value_return.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentV1API_v1AgentSystemGetProp**
```c
// Get System Property (AOSP only)
//
agent_value_return_t* AgentV1API_v1AgentSystemGetProp(apiClient_t *apiClient, char *instanceId, agent_system_get_prop_body_v1_t *agent_system_get_prop_body_v1);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 
**agent_system_get_prop_body_v1** | **[agent_system_get_prop_body_v1_t](agent_system_get_prop_body_v1.md) \*** | Parameters | 

### Return type

[agent_value_return_t](agent_value_return.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentV1API_v1AgentSystemInstallOpenGApps**
```c
// Install OpenGApps (AOSP only)
//
void AgentV1API_v1AgentSystemInstallOpenGApps(apiClient_t *apiClient, char *instanceId, object_t *body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 
**body** | **[object_t](object.md) \*** | Installation parameters | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentV1API_v1AgentSystemLock**
```c
// Lock Device (iOS Only)
//
void AgentV1API_v1AgentSystemLock(apiClient_t *apiClient, char *instanceId);
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

# **AgentV1API_v1AgentSystemSetAdbAuth**
```c
// Set ADB Auth Setting (AOSP only)
//
void AgentV1API_v1AgentSystemSetAdbAuth(apiClient_t *apiClient, char *instanceId, agent_system_adb_auth_v1_t *agent_system_adb_auth_v1);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 
**agent_system_adb_auth_v1** | **[agent_system_adb_auth_v1_t](agent_system_adb_auth_v1.md) \*** | Desired ADB Auth Setting | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentV1API_v1AgentSystemSetHostname**
```c
// Set Hostname of instance
//
void AgentV1API_v1AgentSystemSetHostname(apiClient_t *apiClient, char *instanceId, agent_system_set_hostname_body_v1_t *agent_system_set_hostname_body_v1);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 
**agent_system_set_hostname_body_v1** | **[agent_system_set_hostname_body_v1_t](agent_system_set_hostname_body_v1.md) \*** | New hostname | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentV1API_v1AgentSystemShutdown**
```c
// Instruct VM to halt
//
void AgentV1API_v1AgentSystemShutdown(apiClient_t *apiClient, char *instanceId);
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

# **AgentV1API_v1AgentSystemUnlock**
```c
// Unlock Device (iOS Only)
//
void AgentV1API_v1AgentSystemUnlock(apiClient_t *apiClient, char *instanceId);
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

# **AgentV1API_v1AgentUninstallApp**
```c
// Uninstall an App
//
object_t* AgentV1API_v1AgentUninstallApp(apiClient_t *apiClient, char *instanceId, char *bundleId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 
**bundleId** | **char \*** | App Bundle ID | 

### Return type

[object_t](object.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentV1API_v1AgentUninstallProfile**
```c
// Uninstall a Profile from VM
//
void AgentV1API_v1AgentUninstallProfile(apiClient_t *apiClient, char *instanceId, char *profileId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 
**profileId** | **char \*** | Instance ID - uuid | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AgentV1API_v1AgentUploadFile**
```c
// Upload a file to VM
//
void AgentV1API_v1AgentUploadFile(apiClient_t *apiClient, char *instanceId, char *filePath, binary_t* body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Instance ID - uuid | 
**filePath** | **char \*** | File Path on VM to write to | 
**body** | **binary_t*** | Uploaded File Contents | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/octet-stream
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

