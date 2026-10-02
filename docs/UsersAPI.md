# UsersAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**UsersAPI_v3AgreeToTerms**](UsersAPI.md#UsersAPI_v3AgreeToTerms) | **POST** /v3/users/agree | Agree to terms
[**UsersAPI_v3ChangePassword**](UsersAPI.md#UsersAPI_v3ChangePassword) | **POST** /v3/users/change-password | Change password
[**UsersAPI_v3CreateUser**](UsersAPI.md#UsersAPI_v3CreateUser) | **POST** /v3/users | Create a user
[**UsersAPI_v3DeleteUser**](UsersAPI.md#UsersAPI_v3DeleteUser) | **DELETE** /v3/users/{userId} | Delete a user
[**UsersAPI_v3GetResetLinkInfo**](UsersAPI.md#UsersAPI_v3GetResetLinkInfo) | **POST** /v3/users/reset-link-info | Get reset link info
[**UsersAPI_v3PatchUser**](UsersAPI.md#UsersAPI_v3PatchUser) | **PATCH** /v3/users/{userId} | Update a user
[**UsersAPI_v3ResetPassword**](UsersAPI.md#UsersAPI_v3ResetPassword) | **POST** /v3/users/reset-password | Reset password
[**UsersAPI_v3SendResetLink**](UsersAPI.md#UsersAPI_v3SendResetLink) | **POST** /v3/users/send-reset-link | Send a password reset link


# **UsersAPI_v3AgreeToTerms**
```c
// Agree to terms
//
// Records that you, the signed-in user, accept the current terms and conditions, and returns the time of agreement. The web interface calls this when it shows the terms; call it yourself if your domain requires agreement before using the platform.
//
agreed_ack_t* UsersAPI_v3AgreeToTerms(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[agreed_ack_t](agreed_ack.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UsersAPI_v3ChangePassword**
```c
// Change password
//
// Changes a password when you know the current one. Needs no sign-in: send the user's ID in `user`, the current password in `oldPassword`, and the new one in `newPassword`. Returns 204 on success and 403 if the old password is wrong. If you have forgotten the password, use the reset flow instead (`v3SendResetLink`).
//
void UsersAPI_v3ChangePassword(apiClient_t *apiClient, change_password_body_t *change_password_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**change_password_body** | **[change_password_body_t](change_password_body.md) \*** |  | [optional] 

### Return type

void

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UsersAPI_v3CreateUser**
```c
// Create a user
//
// **Required role:** Domain administrator.  Creates a user account in your domain directly, with a username and password you choose, without sending an invitation. Requires a domain administrator. Returns 201 with the new user's ID. To let people set their own password instead, invite them with `POST /v3/invites`. A new user has no project access until you grant it with the Roles endpoints or add them to a team.
//
user_created_t* UsersAPI_v3CreateUser(apiClient_t *apiClient, create_user_body_t *create_user_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**create_user_body** | **[create_user_body_t](create_user_body.md) \*** |  | 

### Return type

[user_created_t](user_created.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UsersAPI_v3DeleteUser**
```c
// Delete a user
//
// **Required role:** Domain administrator.  Deletes the user identified by the given userId.  Deletes are idempotent: a `userId` that does not exist, including one that was already deleted, is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing.
//
void UsersAPI_v3DeleteUser(apiClient_t *apiClient, char *userId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**userId** | **char \*** | User identifier. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UsersAPI_v3GetResetLinkInfo**
```c
// Get reset link info
//
// Step 2 (optional) of resetting a forgotten password: checks the token from a reset email and returns the account it belongs to (user ID, username and domain), so a reset page can show whose password is being changed. Needs no sign-in. Returns 400 or 401 if the token is missing, invalid or expired.
//
reset_link_info_t* UsersAPI_v3GetResetLinkInfo(apiClient_t *apiClient, get_reset_link_info_body_t *get_reset_link_info_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**get_reset_link_info_body** | **[get_reset_link_info_body_t](get_reset_link_info_body.md) \*** |  | 

### Return type

[reset_link_info_t](reset_link_info.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UsersAPI_v3PatchUser**
```c
// Update a user
//
// Changes a user's account details, such as their name, display label, email or password. Send only the fields you want to change. Only cluster administrators may set or change `clusterAdministrator`, which gives a user control over the whole cluster.
//
void UsersAPI_v3PatchUser(apiClient_t *apiClient, char *userId, patch_user_body_t *patch_user_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**userId** | **char \*** | User identifier. | 
**patch_user_body** | **[patch_user_body_t](patch_user_body.md) \*** |  | [optional] 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UsersAPI_v3ResetPassword**
```c
// Reset password
//
// Step 3 of resetting a forgotten password. Send the `token` from the reset email, the `newPassword`, and, if the account has two-factor sign-in turned on, a current six-digit code in `totpToken`. Returns 204 when the password has been changed; sign in with the new password.  **Reset flow:** 1. `v3SendResetLink` with the account's email address. 2. Optionally `v3GetResetLinkInfo` with the token from the email, to show which account is being reset. 3. `v3ResetPassword` (this call).  Returns 401 if the token is invalid or expired, or the two-factor code is wrong.
//
void UsersAPI_v3ResetPassword(apiClient_t *apiClient, reset_password_body_t *reset_password_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**reset_password_body** | **[reset_password_body_t](reset_password_body.md) \*** |  | 

### Return type

void

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UsersAPI_v3SendResetLink**
```c
// Send a password reset link
//
// Step 1 of resetting a forgotten password: emails a password reset link to the given address, if it belongs to an account in the domain you are calling. Needs no sign-in. Always returns 204, whether or not the address matched an account, so the response does not reveal which emails are registered. The link contains the token used by `v3ResetPassword`.
//
void UsersAPI_v3SendResetLink(apiClient_t *apiClient, send_reset_link_body_t *send_reset_link_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**send_reset_link_body** | **[send_reset_link_body_t](send_reset_link_body.md) \*** |  | [optional] 

### Return type

void

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

