# RolesV1API

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**RolesV1API_v1AddTeamRoleToProject**](RolesV1API.md#RolesV1API_v1AddTeamRoleToProject) | **PUT** /v1/roles/projects/{projectId}/teams/{teamId}/roles/{roleId} | Add team role to project
[**RolesV1API_v1AddUserRoleToProject**](RolesV1API.md#RolesV1API_v1AddUserRoleToProject) | **PUT** /v1/roles/projects/{projectId}/users/{userId}/roles/{roleId} | Add user role to project
[**RolesV1API_v1RemoveTeamRoleFromProject**](RolesV1API.md#RolesV1API_v1RemoveTeamRoleFromProject) | **DELETE** /v1/roles/projects/{projectId}/teams/{teamId}/roles/{roleId} | Remove team role from project
[**RolesV1API_v1RemoveUserRoleFromProject**](RolesV1API.md#RolesV1API_v1RemoveUserRoleFromProject) | **DELETE** /v1/roles/projects/{projectId}/users/{userId}/roles/{roleId} | Remove user role from project
[**RolesV1API_v1Roles**](RolesV1API.md#RolesV1API_v1Roles) | **GET** /v1/roles | Get all roles


# **RolesV1API_v1AddTeamRoleToProject**
```c
// Add team role to project
//
// This endpoint is available for Enterprise accounts only
//
void RolesV1API_v1AddTeamRoleToProject(apiClient_t *apiClient, char *projectId, char *teamId, char *roleId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | Project ID - uuid | 
**teamId** | **char \*** | Team ID - uuid | 
**roleId** | **char \*** | Role ID | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **RolesV1API_v1AddUserRoleToProject**
```c
// Add user role to project
//
// This endpoint is available for Enterprise accounts only
//
void RolesV1API_v1AddUserRoleToProject(apiClient_t *apiClient, char *projectId, char *userId, char *roleId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | Project ID - uuid | 
**userId** | **char \*** | User ID - uuid | 
**roleId** | **char \*** | Role ID | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **RolesV1API_v1RemoveTeamRoleFromProject**
```c
// Remove team role from project
//
// This endpoint is available for Enterprise accounts only
//
void RolesV1API_v1RemoveTeamRoleFromProject(apiClient_t *apiClient, char *projectId, char *teamId, char *roleId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | Project ID - uuid | 
**teamId** | **char \*** | Team ID - uuid | 
**roleId** | **char \*** | Role ID | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **RolesV1API_v1RemoveUserRoleFromProject**
```c
// Remove user role from project
//
// This endpoint is available for Enterprise accounts only
//
void RolesV1API_v1RemoveUserRoleFromProject(apiClient_t *apiClient, char *projectId, char *userId, char *roleId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | Project ID - uuid | 
**userId** | **char \*** | User ID - uuid | 
**roleId** | **char \*** | Role ID | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **RolesV1API_v1Roles**
```c
// Get all roles
//
// This endpoint is available for Enterprise accounts only
//
list_t* RolesV1API_v1Roles(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[list_t](role_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

