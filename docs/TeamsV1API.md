# TeamsV1API

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**TeamsV1API_v1AddUserToTeam**](TeamsV1API.md#TeamsV1API_v1AddUserToTeam) | **PUT** /v1/teams/{teamId}/users/{userId} | Add user to team
[**TeamsV1API_v1RemoveUserFromTeam**](TeamsV1API.md#TeamsV1API_v1RemoveUserFromTeam) | **DELETE** /v1/teams/{teamId}/users/{userId} | Remove user from team
[**TeamsV1API_v1TeamChange**](TeamsV1API.md#TeamsV1API_v1TeamChange) | **PATCH** /v1/teams/{teamId} | Update team
[**TeamsV1API_v1TeamCreate**](TeamsV1API.md#TeamsV1API_v1TeamCreate) | **POST** /v1/teams | Create team
[**TeamsV1API_v1TeamDelete**](TeamsV1API.md#TeamsV1API_v1TeamDelete) | **DELETE** /v1/teams/{teamId} | Delete team
[**TeamsV1API_v1Teams**](TeamsV1API.md#TeamsV1API_v1Teams) | **GET** /v1/teams | Get teams


# **TeamsV1API_v1AddUserToTeam**
```c
// Add user to team
//
// This endpoint is available for Enterprise accounts only
//
void TeamsV1API_v1AddUserToTeam(apiClient_t *apiClient, char *teamId, char *userId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**teamId** | **char \*** | Team ID - uuid | 
**userId** | **char \*** | User ID - uuid | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **TeamsV1API_v1RemoveUserFromTeam**
```c
// Remove user from team
//
// This endpoint is available for Enterprise accounts only
//
void TeamsV1API_v1RemoveUserFromTeam(apiClient_t *apiClient, char *teamId, char *userId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**teamId** | **char \*** | Team ID - uuid | 
**userId** | **char \*** | User ID - uuid | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **TeamsV1API_v1TeamChange**
```c
// Update team
//
// This endpoint is available for Enterprise accounts only
//
void TeamsV1API_v1TeamChange(apiClient_t *apiClient, char *teamId, create_team_t *create_team);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**teamId** | **char \*** | Team ID - uuid | 
**create_team** | **[create_team_t](create_team.md) \*** |  | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **TeamsV1API_v1TeamCreate**
```c
// Create team
//
// This endpoint is available for Enterprise accounts only
//
team_create_t* TeamsV1API_v1TeamCreate(apiClient_t *apiClient, create_team_t *create_team);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**create_team** | **[create_team_t](create_team.md) \*** |  | 

### Return type

[team_create_t](team_create.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **TeamsV1API_v1TeamDelete**
```c
// Delete team
//
// This endpoint is available for Enterprise accounts only
//
void TeamsV1API_v1TeamDelete(apiClient_t *apiClient, char *teamId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**teamId** | **char \*** | Team ID - uuid | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **TeamsV1API_v1Teams**
```c
// Get teams
//
// This endpoint is available for Enterprise accounts only
//
list_t* TeamsV1API_v1Teams(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[list_t](team_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

