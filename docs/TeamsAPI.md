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
// **Required role:** Domain administrator.  Add a user to a team. Available for Enterprise accounts only.
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
// **Required role:** Domain administrator.  Create a team. Available for Enterprise accounts only.
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
// **Required role:** Domain administrator.  Delete a team. Available for Enterprise accounts only.
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
// List teams for the requesting domain. Available for Enterprise accounts only.
//
teams_list_response_t* TeamsAPI_v3ListTeams(apiClient_t *apiClient, double *limit, double *offset);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**limit** | **double \*** | Maximum number of results to return. | [optional] [default to 100]
**offset** | **double \*** | Number of results to skip. | [optional] [default to 0]

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
// **Required role:** Domain administrator.  Remove a user from a team. Available for Enterprise accounts only.
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
// **Required role:** Domain administrator.  Update a team. Available for Enterprise accounts only.
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

