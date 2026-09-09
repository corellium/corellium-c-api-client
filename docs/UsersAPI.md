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
// Consent to the current terms and conditions.
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
// Change a password, authenticated solely by the old password.
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

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UsersAPI_v3CreateUser**
```c
// Create a user
//
// **Required role:** Domain administrator.  Creates a new user in the caller's domain.
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
// **Required role:** Domain administrator.  Deletes the user identified by the given userId.
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
// Return account info associated with a password reset token.
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

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UsersAPI_v3PatchUser**
```c
// Update a user
//
// Updates a user. Only cluster administrators may set the clusterAdministrator flag.
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
// Reset a password using a reset token.
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

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UsersAPI_v3SendResetLink**
```c
// Send a password reset link
//
// Sends a password reset link to the specified user.
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

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

