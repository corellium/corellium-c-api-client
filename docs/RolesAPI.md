# RolesAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**RolesAPI_v3AddTeamRoleToDeployment**](RolesAPI.md#RolesAPI_v3AddTeamRoleToDeployment) | **PUT** /v3/roles/deployments/{deploymentId}/teams/{teamId}/roles/{roleId} | Add team role to deployment
[**RolesAPI_v3AddTeamRoleToProject**](RolesAPI.md#RolesAPI_v3AddTeamRoleToProject) | **PUT** /v3/roles/projects/{projectId}/teams/{teamId}/roles/{roleId} | Add team role to project
[**RolesAPI_v3AddUserRoleToDeployment**](RolesAPI.md#RolesAPI_v3AddUserRoleToDeployment) | **PUT** /v3/roles/deployments/{deploymentId}/users/{userId}/roles/{roleId} | Add user role to deployment
[**RolesAPI_v3AddUserRoleToProject**](RolesAPI.md#RolesAPI_v3AddUserRoleToProject) | **PUT** /v3/roles/projects/{projectId}/users/{userId}/roles/{roleId} | Add user role to project
[**RolesAPI_v3ListDeploymentRoles**](RolesAPI.md#RolesAPI_v3ListDeploymentRoles) | **GET** /v3/roles/deployments | List deployment role assignments
[**RolesAPI_v3ListRoles**](RolesAPI.md#RolesAPI_v3ListRoles) | **GET** /v3/roles | List all role assignments for the caller&#39;s domain
[**RolesAPI_v3RemoveTeamRoleFromDeployment**](RolesAPI.md#RolesAPI_v3RemoveTeamRoleFromDeployment) | **DELETE** /v3/roles/deployments/{deploymentId}/teams/{teamId}/roles/{roleId} | Remove team role from deployment
[**RolesAPI_v3RemoveTeamRoleFromProject**](RolesAPI.md#RolesAPI_v3RemoveTeamRoleFromProject) | **DELETE** /v3/roles/projects/{projectId}/teams/{teamId}/roles/{roleId} | Remove team role from project
[**RolesAPI_v3RemoveUserRoleFromDeployment**](RolesAPI.md#RolesAPI_v3RemoveUserRoleFromDeployment) | **DELETE** /v3/roles/deployments/{deploymentId}/users/{userId}/roles/{roleId} | Remove user role from deployment
[**RolesAPI_v3RemoveUserRoleFromProject**](RolesAPI.md#RolesAPI_v3RemoveUserRoleFromProject) | **DELETE** /v3/roles/projects/{projectId}/users/{userId}/roles/{roleId} | Remove user role from project


# **RolesAPI_v3AddTeamRoleToDeployment**
```c
// Add team role to deployment
//
// **Required role:** Domain administrator.  Grants a team a role within a deployment. Available for Enterprise accounts only.
//
void RolesAPI_v3AddTeamRoleToDeployment(apiClient_t *apiClient, char *deploymentId, char *teamId, char *roleId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**deploymentId** | **char \*** | Deployment identifier. | 
**teamId** | **char \*** | Team identifier. | 
**roleId** | **char \*** | Role identifier. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **RolesAPI_v3AddTeamRoleToProject**
```c
// Add team role to project
//
// **Required role:** Domain administrator or project administrator.  Gives every member of a team a role on a project. Pass `all-users` as `teamId` to give the role to everyone in your domain. People added to the team later get the access automatically. Requires a domain administrator, or a project administrator of that project. Available for Enterprise accounts only.
//
void RolesAPI_v3AddTeamRoleToProject(apiClient_t *apiClient, char *projectId, char *teamId, char *roleId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | Project identifier. | 
**teamId** | **char \*** | Team ID from &#x60;GET /v3/teams&#x60;, or &#x60;all-users&#x60; to grant the role to everyone in your domain at once. | 
**roleId** | **char \*** | Role to grant or remove: &#x60;admin&#x60; or &#x60;member&#x60;. See &#x60;RoleName&#x60;. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **RolesAPI_v3AddUserRoleToDeployment**
```c
// Add user role to deployment
//
// **Required role:** Domain administrator.  Grants a user a role within a deployment. Available for Enterprise accounts only.
//
void RolesAPI_v3AddUserRoleToDeployment(apiClient_t *apiClient, char *deploymentId, char *userId, char *roleId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**deploymentId** | **char \*** | Deployment identifier. | 
**userId** | **char \*** | User identifier. | 
**roleId** | **char \*** | Role identifier. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **RolesAPI_v3AddUserRoleToProject**
```c
// Add user role to project
//
// **Required role:** Domain administrator or project administrator.  Gives a user a role on a project: `member` to use the project and its devices, or `admin` to also manage it. This is how a new user gets access to a project. Requires a domain administrator, or a project administrator of that project. Returns 404 if the project, user or role does not exist. Available for Enterprise accounts only.
//
void RolesAPI_v3AddUserRoleToProject(apiClient_t *apiClient, char *projectId, char *userId, char *roleId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | Project identifier. | 
**userId** | **char \*** | User identifier. | 
**roleId** | **char \*** | Role to grant or remove: &#x60;admin&#x60; or &#x60;member&#x60;. See &#x60;RoleName&#x60;. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **RolesAPI_v3ListDeploymentRoles**
```c
// List deployment role assignments
//
// **Required role:** Domain administrator or project administrator.  Returns paginated role assignments scoped to deployments. Available for Enterprise accounts only.
//
roles_list_response_t* RolesAPI_v3ListDeploymentRoles(apiClient_t *apiClient, double *limit, double *offset);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**limit** | **double \*** | Most results to return in one page. Whole number from 1 to 1000; defaults to 100. A value outside that range is rejected with 400. | [optional] [default to 100]
**offset** | **double \*** | How many results to skip before this page starts; defaults to 0. To get the next page, add &#x60;limit&#x60; to the previous &#x60;offset&#x60;. | [optional] [default to 0]

### Return type

[roles_list_response_t](roles_list_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **RolesAPI_v3ListRoles**
```c
// List all role assignments for the caller's domain
//
// **Required role:** Domain administrator or project administrator.  Lists who has which role on which project in your domain, for both individual users and teams: each entry names a role and either a `user` or a `team`, plus the `project`. Use it to audit access. Requires a domain or project administrator. Available for Enterprise accounts only.
//
roles_list_response_t* RolesAPI_v3ListRoles(apiClient_t *apiClient, double *limit, double *offset);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**limit** | **double \*** | Most results to return in one page. Whole number from 1 to 1000; defaults to 100. A value outside that range is rejected with 400. | [optional] [default to 100]
**offset** | **double \*** | How many results to skip before this page starts; defaults to 0. To get the next page, add &#x60;limit&#x60; to the previous &#x60;offset&#x60;. | [optional] [default to 0]

### Return type

[roles_list_response_t](roles_list_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **RolesAPI_v3RemoveTeamRoleFromDeployment**
```c
// Remove team role from deployment
//
// **Required role:** Domain administrator.  Revokes a team role within a deployment. Available for Enterprise accounts only.  Revocation is idempotent: if the team does not currently hold that role in the deployment, the call is a no-op and still returns 204. Repeated calls therefore also return 204. A `deploymentId` or `teamId` that does not exist is also a successful no-op that returns 204.
//
void RolesAPI_v3RemoveTeamRoleFromDeployment(apiClient_t *apiClient, char *deploymentId, char *teamId, char *roleId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**deploymentId** | **char \*** | Deployment identifier. | 
**teamId** | **char \*** | Team identifier. | 
**roleId** | **char \*** | Role identifier. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **RolesAPI_v3RemoveTeamRoleFromProject**
```c
// Remove team role from project
//
// **Required role:** Domain administrator or project administrator.  Takes a role on a project away from a team, so its members lose the access they had through it. Requires a domain administrator, or a project administrator of that project. Available for Enterprise accounts only.  Revocation is idempotent: if the team does not currently hold that role in the project, the call is a no-op and still returns 204. Repeated calls therefore also return 204. A `projectId` or `teamId` that does not exist is also a successful no-op that returns 204. A project administrator acting on another project in their own domain receives 403. An unrecognized `roleId` returns 400.
//
void RolesAPI_v3RemoveTeamRoleFromProject(apiClient_t *apiClient, char *projectId, char *teamId, char *roleId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | Project identifier. | 
**teamId** | **char \*** | Team identifier. | 
**roleId** | **char \*** | Role to grant or remove: &#x60;admin&#x60; or &#x60;member&#x60;. See &#x60;RoleName&#x60;. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **RolesAPI_v3RemoveUserRoleFromDeployment**
```c
// Remove user role from deployment
//
// **Required role:** Domain administrator.  Revokes a user role within a deployment. Available for Enterprise accounts only.  Revocation is idempotent: if the user does not currently hold that role in the deployment, the call is a no-op and still returns 204. Repeated calls therefore also return 204. A `deploymentId` or `userId` that does not exist is also a successful no-op that returns 204.
//
void RolesAPI_v3RemoveUserRoleFromDeployment(apiClient_t *apiClient, char *deploymentId, char *userId, char *roleId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**deploymentId** | **char \*** | Deployment identifier. | 
**userId** | **char \*** | User identifier. | 
**roleId** | **char \*** | Role identifier. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **RolesAPI_v3RemoveUserRoleFromProject**
```c
// Remove user role from project
//
// **Required role:** Domain administrator or project administrator.  Takes a role on a project away from a user, so they lose that access (unless they also have it through a team). Requires a domain administrator, or a project administrator of that project. Available for Enterprise accounts only.  Revocation is idempotent: if the user does not currently hold that role in the project, the call is a no-op and still returns 204. Repeated calls therefore also return 204. A `projectId` or `userId` that does not exist is also a successful no-op that returns 204. A project administrator acting on another project in their own domain receives 403. An unrecognized `roleId` returns 400.
//
void RolesAPI_v3RemoveUserRoleFromProject(apiClient_t *apiClient, char *projectId, char *userId, char *roleId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**projectId** | **char \*** | Project identifier. | 
**userId** | **char \*** | User identifier. | 
**roleId** | **char \*** | Role to grant or remove: &#x60;admin&#x60; or &#x60;member&#x60;. See &#x60;RoleName&#x60;. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

