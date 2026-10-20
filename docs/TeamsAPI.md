# TeamsAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**TeamsAPI_v3AddUserToTeam**](TeamsAPI.md#TeamsAPI_v3AddUserToTeam) | **PUT** /v3/teams/{teamId}/users/{userId} | Add a user to a team
[**TeamsAPI_v3CreateTeam**](TeamsAPI.md#TeamsAPI_v3CreateTeam) | **POST** /v3/teams | Create a team
[**TeamsAPI_v3DeleteTeam**](TeamsAPI.md#TeamsAPI_v3DeleteTeam) | **DELETE** /v3/teams/{teamId} | Delete a team
[**TeamsAPI_v3ListTeams**](TeamsAPI.md#TeamsAPI_v3ListTeams) | **GET** /v3/teams | List teams
[**TeamsAPI_v3RemoveUserFromTeam**](TeamsAPI.md#TeamsAPI_v3RemoveUserFromTeam) | **DELETE** /v3/teams/{teamId}/users/{userId} | Remove a user from a team
[**TeamsAPI_v3UpdateTeam**](TeamsAPI.md#TeamsAPI_v3UpdateTeam) | **PATCH** /v3/teams/{teamId} | Update a team


# **TeamsAPI_v3AddUserToTeam**
```c
// Add a user to a team
//
// **Required role:** Domain administrator.  Adds a user to a team, so the user gets every project role the team has. Requires a domain administrator. Available for Enterprise accounts only.
//
void TeamsAPI_v3AddUserToTeam(apiClient_t *apiClient, char *teamId, char *userId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**teamId** | **char \*** | Team identifier. | 
**userId** | **char \*** | User identifier. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **TeamsAPI_v3CreateTeam**
```c
// Create a team
//
// **Required role:** Domain administrator.  Creates an empty team in your domain and returns its ID. Requires a domain administrator. Next, add members with `v3AddUserToTeam` and give the team project access with `PUT /v3/roles/projects/{projectId}/teams/{teamId}/roles/{roleId}`. Available for Enterprise accounts only.
//
team_created_t* TeamsAPI_v3CreateTeam(apiClient_t *apiClient, create_team_body_t *create_team_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**create_team_body** | **[create_team_body_t](create_team_body.md) \*** |  | 

### Return type

[team_created_t](team_created.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **TeamsAPI_v3DeleteTeam**
```c
// Delete a team
//
// **Required role:** Domain administrator.  Deletes a team. Requires a domain administrator. The users in it are not deleted, but they lose any project access they had only through this team. Available for Enterprise accounts only.  Deletes are idempotent: a `teamId` that does not exist, including one that was already deleted, is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing.
//
void TeamsAPI_v3DeleteTeam(apiClient_t *apiClient, char *teamId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**teamId** | **char \*** | Team identifier. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **TeamsAPI_v3ListTeams**
```c
// List teams
//
// Lists the teams in your domain. A team is a named group of users; giving a team a role on a project (with the Roles endpoints) gives every member that access, which is easier than granting each user separately. Includes the built-in `all-users` team, which always contains everyone in the domain. Available for Enterprise accounts only.
//
teams_list_response_t* TeamsAPI_v3ListTeams(apiClient_t *apiClient, double *limit, double *offset);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**limit** | **double \*** | Most results to return in one page. Whole number from 1 to 1000; defaults to 100. A value outside that range is rejected with 400. | [optional] [default to 100]
**offset** | **double \*** | How many results to skip before this page starts; defaults to 0. To get the next page, add &#x60;limit&#x60; to the previous &#x60;offset&#x60;. | [optional] [default to 0]

### Return type

[teams_list_response_t](teams_list_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **TeamsAPI_v3RemoveUserFromTeam**
```c
// Remove a user from a team
//
// **Required role:** Domain administrator.  Removes a user from a team, so the user loses the project access they had only through this team. Requires a domain administrator. Available for Enterprise accounts only.  Removal is idempotent: if the user is not a member of the team, the call is a no-op and still returns 204. Repeated calls therefore also return 204. A `teamId` or `userId` that does not exist is also a successful no-op that returns 204.
//
void TeamsAPI_v3RemoveUserFromTeam(apiClient_t *apiClient, char *teamId, char *userId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**teamId** | **char \*** | Team identifier. | 
**userId** | **char \*** | User identifier. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **TeamsAPI_v3UpdateTeam**
```c
// Update a team
//
// **Required role:** Domain administrator.  Renames a team or changes its settings. Requires a domain administrator. Available for Enterprise accounts only.
//
void TeamsAPI_v3UpdateTeam(apiClient_t *apiClient, char *teamId, update_team_body_t *update_team_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**teamId** | **char \*** | Team identifier. | 
**update_team_body** | **[update_team_body_t](update_team_body.md) \*** |  | [optional] 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

