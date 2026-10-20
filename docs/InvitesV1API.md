# InvitesV1API

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**InvitesV1API_v1CreateUserInvites**](InvitesV1API.md#InvitesV1API_v1CreateUserInvites) | **POST** /v1/invites | Create Invite
[**InvitesV1API_v1EditInvites**](InvitesV1API.md#InvitesV1API_v1EditInvites) | **POST** /v1/invites/edit | 
[**InvitesV1API_v1Invites**](InvitesV1API.md#InvitesV1API_v1Invites) | **GET** /v1/invites | Get Invites
[**InvitesV1API_v1InvitesByToken**](InvitesV1API.md#InvitesV1API_v1InvitesByToken) | **GET** /v1/invites-by-token | 
[**InvitesV1API_v1RevokeUserInvite**](InvitesV1API.md#InvitesV1API_v1RevokeUserInvite) | **POST** /v1/invites/revoke | Revoke Invite
[**InvitesV1API_v1UserCreateFromInvite**](InvitesV1API.md#InvitesV1API_v1UserCreateFromInvite) | **POST** /v1/invites/signup | 


# **InvitesV1API_v1CreateUserInvites**
```c
// Create Invite
//
// Domain Admin route to invite a new user to create an account
//
object_t* InvitesV1API_v1CreateUserInvites(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[object_t](object.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InvitesV1API_v1EditInvites**
```c
// 
//
void InvitesV1API_v1EditInvites(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InvitesV1API_v1Invites**
```c
// Get Invites
//
// Gets all invites for a user's domain
//
list_t* InvitesV1API_v1Invites(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[list_t](invitation_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InvitesV1API_v1InvitesByToken**
```c
// 
//
void InvitesV1API_v1InvitesByToken(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

void

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InvitesV1API_v1RevokeUserInvite**
```c
// Revoke Invite
//
void InvitesV1API_v1RevokeUserInvite(apiClient_t *apiClient, invite_revoke_params_t *invite_revoke_params);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**invite_revoke_params** | **[invite_revoke_params_t](invite_revoke_params.md) \*** | Invitations to revoke | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InvitesV1API_v1UserCreateFromInvite**
```c
// 
//
void InvitesV1API_v1UserCreateFromInvite(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

void

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

