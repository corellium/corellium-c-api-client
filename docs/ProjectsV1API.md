# ProjectsV1API

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ProjectsV1API_v1AddProjectKey**](ProjectsV1API.md#ProjectsV1API_v1AddProjectKey) | **POST** /v1/projects/{projectId}/keys | Add Project Authorized Key
[**ProjectsV1API_v1CreateProject**](ProjectsV1API.md#ProjectsV1API_v1CreateProject) | **POST** /v1/projects | Create a Project
[**ProjectsV1API_v1DeleteProject**](ProjectsV1API.md#ProjectsV1API_v1DeleteProject) | **DELETE** /v1/projects/{projectId} | Delete a Project
[**ProjectsV1API_v1GetProject**](ProjectsV1API.md#ProjectsV1API_v1GetProject) | **GET** /v1/projects/{projectId} | Get a Project
[**ProjectsV1API_v1GetProjectInstances**](ProjectsV1API.md#ProjectsV1API_v1GetProjectInstances) | **GET** /v1/projects/{projectId}/instances | Get Instances in Project
[**ProjectsV1API_v1GetProjectKeys**](ProjectsV1API.md#ProjectsV1API_v1GetProjectKeys) | **GET** /v1/projects/{projectId}/keys | Get Project Authorized Keys
[**ProjectsV1API_v1GetProjectNetworkLog**](ProjectsV1API.md#ProjectsV1API_v1GetProjectNetworkLog) | **GET** /v1/projects/{projectId}/network/log | Retrieve the network connection log for a project
[**ProjectsV1API_v1GetProjectNetworkStatus**](ProjectsV1API.md#ProjectsV1API_v1GetProjectNetworkStatus) | **GET** /v1/projects/{projectId}/network/status | Retrieve the network connection status for a project
[**ProjectsV1API_v1GetProjectVpnConfig**](ProjectsV1API.md#ProjectsV1API_v1GetProjectVpnConfig) | **GET** /v1/projects/{projectId}/vpnconfig/{format} | Get Project VPN Configuration
[**ProjectsV1API_v1GetProjects**](ProjectsV1API.md#ProjectsV1API_v1GetProjects) | **GET** /v1/projects | Get Projects
[**ProjectsV1API_v1RemoveProjectKey**](ProjectsV1API.md#ProjectsV1API_v1RemoveProjectKey) | **DELETE** /v1/projects/{projectId}/keys/{keyId} | Delete Project Authorized Key
[**ProjectsV1API_v1UpdateProject**](ProjectsV1API.md#ProjectsV1API_v1UpdateProject) | **PATCH** /v1/projects/{projectId} | Update a Project
[**ProjectsV1API_v1UpdateProjectSettings**](ProjectsV1API.md#ProjectsV1API_v1UpdateProjectSettings) | **PATCH** /v1/projects/{projectId}/settings | Change Project Settings


# **ProjectsV1API_v1AddProjectKey**
```c
// Add Project Authorized Key
//
project_key_v1_t* ProjectsV1API_v1AddProjectKey(apiClient_t *apiClient, char *projectId, project_key_v1_t *project_key_v1);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | Project ID - uuid | 
**project_key_v1** | **[project_key_v1_t](project_key_v1.md) \*** | Key to add | 

### Return type

[project_key_v1_t](project_key_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProjectsV1API_v1CreateProject**
```c
// Create a Project
//
project_v1_t* ProjectsV1API_v1CreateProject(apiClient_t *apiClient, project_v1_t *project_v1);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**project_v1** | **[project_v1_t](project_v1.md) \*** | Project | 

### Return type

[project_v1_t](project_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProjectsV1API_v1DeleteProject**
```c
// Delete a Project
//
void ProjectsV1API_v1DeleteProject(apiClient_t *apiClient, char *projectId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | Project ID - uuid | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProjectsV1API_v1GetProject**
```c
// Get a Project
//
project_with_keys_v1_t* ProjectsV1API_v1GetProject(apiClient_t *apiClient, char *projectId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | Project ID - uuid | 

### Return type

[project_with_keys_v1_t](project_with_keys_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProjectsV1API_v1GetProjectInstances**
```c
// Get Instances in Project
//
list_t* ProjectsV1API_v1GetProjectInstances(apiClient_t *apiClient, char *projectId, char *name, char *returnAttr);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | Project ID - uuid | 
**name** | **char \*** | Filter by project name | [optional] 
**returnAttr** | **char \*** | Attributes to include in instance return | [optional] 

### Return type

[list_t](instance_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProjectsV1API_v1GetProjectKeys**
```c
// Get Project Authorized Keys
//
list_t* ProjectsV1API_v1GetProjectKeys(apiClient_t *apiClient, char *projectId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | Project ID - uuid | 

### Return type

[list_t](project_key_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProjectsV1API_v1GetProjectNetworkLog**
```c
// Retrieve the network connection log for a project
//
char* ProjectsV1API_v1GetProjectNetworkLog(apiClient_t *apiClient, char *projectId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | Project ID (must be a valid UUID) | 

### Return type

char*



### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProjectsV1API_v1GetProjectNetworkStatus**
```c
// Retrieve the network connection status for a project
//
network_status_response_t* ProjectsV1API_v1GetProjectNetworkStatus(apiClient_t *apiClient, char *projectId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | Project ID - uuid | 

### Return type

[network_status_response_t](network_status_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProjectsV1API_v1GetProjectVpnConfig**
```c
// Get Project VPN Configuration
//
// A Project VPN allows connection _into_ virtual devices in the project (e.g., connecting a researcher's computer as a VPN client to a virtual device within the project). If a Project VPN has been defined, this will return the configuration.
//
char* ProjectsV1API_v1GetProjectVpnConfig(apiClient_t *apiClient, char *projectId, char *format);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | Project ID - uuid | 
**format** | **char \*** | VPN Config format | 

### Return type

char*



### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProjectsV1API_v1GetProjects**
```c
// Get Projects
//
list_t* ProjectsV1API_v1GetProjects(apiClient_t *apiClient, char *name, int *ids_only);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**name** | **char \*** | Filter by project name | [optional] 
**ids_only** | **int \*** | Only include id of project in results | [optional] 

### Return type

[list_t](project_with_keys_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProjectsV1API_v1RemoveProjectKey**
```c
// Delete Project Authorized Key
//
void ProjectsV1API_v1RemoveProjectKey(apiClient_t *apiClient, char *projectId, char *keyId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | Project ID - uuid | 
**keyId** | **char \*** | Key ID - uuid | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProjectsV1API_v1UpdateProject**
```c
// Update a Project
//
project_v1_t* ProjectsV1API_v1UpdateProject(apiClient_t *apiClient, char *projectId, project_v1_t *project_v1);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | Project ID - uuid | 
**project_v1** | **[project_v1_t](project_v1.md) \*** | Updated Project Settings | 

### Return type

[project_v1_t](project_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ProjectsV1API_v1UpdateProjectSettings**
```c
// Change Project Settings
//
void ProjectsV1API_v1UpdateProjectSettings(apiClient_t *apiClient, char *projectId, project_settings_v1_t *project_settings_v1);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | Project ID - uuid | 
**project_settings_v1** | **[project_settings_v1_t](project_settings_v1.md) \*** | New settings | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

