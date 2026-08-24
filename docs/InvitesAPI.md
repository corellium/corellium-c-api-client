# InvitesAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**InvitesAPI_v3CreateInvites**](InvitesAPI.md#InvitesAPI_v3CreateInvites) | **POST** /v3/invites | Create invites
[**InvitesAPI_v3EditInvites**](InvitesAPI.md#InvitesAPI_v3EditInvites) | **POST** /v3/invites/edit | Edit invites
[**InvitesAPI_v3GetInviteByToken**](InvitesAPI.md#InvitesAPI_v3GetInviteByToken) | **GET** /v3/invites-by-token | Get an invite by token
[**InvitesAPI_v3ListInvites**](InvitesAPI.md#InvitesAPI_v3ListInvites) | **GET** /v3/invites | List invites
[**InvitesAPI_v3RevokeInvites**](InvitesAPI.md#InvitesAPI_v3RevokeInvites) | **POST** /v3/invites/revoke | Revoke invites
[**InvitesAPI_v3SignupFromInvite**](InvitesAPI.md#InvitesAPI_v3SignupFromInvite) | **POST** /v3/invites/signup | Sign up from an invite


# **InvitesAPI_v3CreateInvites**
```c
// Create invites
//
// **Required role:** Domain administrator or project administrator.  Invite one or more users to create an account in the domain.
//
object_t* InvitesAPI_v3CreateInvites(apiClient_t *apiClient, create_invites_body_t *create_invites_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**create_invites_body** | **[create_invites_body_t](create_invites_body.md) \*** |  | 

### Return type

[object_t](object.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InvitesAPI_v3EditInvites**
```c
// Edit invites
//
// **Required role:** Domain administrator or project administrator.  Edit the settings of one or more existing invites.
//
invitation_t* InvitesAPI_v3EditInvites(apiClient_t *apiClient, edit_invites_body_t *edit_invites_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**edit_invites_body** | **[edit_invites_body_t](edit_invites_body.md) \*** |  | 

### Return type

[invitation_t](invitation.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InvitesAPI_v3GetInviteByToken**
```c
// Get an invite by token
//
// Look up an invitation by its token. Public endpoint used during signup.
//
invitation_by_token_t* InvitesAPI_v3GetInviteByToken(apiClient_t *apiClient, char *token);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**token** | **char \*** | Invite token. | 

### Return type

[invitation_by_token_t](invitation_by_token.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InvitesAPI_v3ListInvites**
```c
// List invites
//
// **Required role:** Domain administrator or project administrator.  List all invites for the requesting user's domain.
//
invites_list_response_t* InvitesAPI_v3ListInvites(apiClient_t *apiClient, double *limit, double *offset);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**limit** | **double \*** | Maximum number of results to return. | [optional] [default to 100]
**offset** | **double \*** | Number of results to skip. | [optional] [default to 0]

### Return type

[invites_list_response_t](invites_list_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InvitesAPI_v3RevokeInvites**
```c
// Revoke invites
//
// **Required role:** Domain administrator or project administrator.  Revoke one or more invites.
//
revoke_invites_response_t* InvitesAPI_v3RevokeInvites(apiClient_t *apiClient, revoke_invites_body_t *revoke_invites_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**revoke_invites_body** | **[revoke_invites_body_t](revoke_invites_body.md) \*** |  | 

### Return type

[revoke_invites_response_t](revoke_invites_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InvitesAPI_v3SignupFromInvite**
```c
// Sign up from an invite
//
// Create a new user account from an invitation token. Public endpoint.
//
invite_signup_response_t* InvitesAPI_v3SignupFromInvite(apiClient_t *apiClient, invite_signup_body_t *invite_signup_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**invite_signup_body** | **[invite_signup_body_t](invite_signup_body.md) \*** |  | 

### Return type

[invite_signup_response_t](invite_signup_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

