# UsersV1API

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**UsersV1API_v1ChangePasswordUsers**](UsersV1API.md#UsersV1API_v1ChangePasswordUsers) | **POST** /v1/users/change-password | Change User Password
[**UsersV1API_v1CreateUser**](UsersV1API.md#UsersV1API_v1CreateUser) | **POST** /v1/users | Create User
[**UsersV1API_v1DeleteUser**](UsersV1API.md#UsersV1API_v1DeleteUser) | **DELETE** /v1/users/{userId} | Delete User
[**UsersV1API_v1GetResetLinkInfo**](UsersV1API.md#UsersV1API_v1GetResetLinkInfo) | **GET** /v1/users/reset-link-info | Send Password Reset Link Info
[**UsersV1API_v1ResetUserPassword**](UsersV1API.md#UsersV1API_v1ResetUserPassword) | **POST** /v1/users/reset-password | Reset User Password
[**UsersV1API_v1SendUserResetLink**](UsersV1API.md#UsersV1API_v1SendUserResetLink) | **POST** /v1/users/send-reset-link | Send Password Reset Link
[**UsersV1API_v1UpdateUser**](UsersV1API.md#UsersV1API_v1UpdateUser) | **PATCH** /v1/users/{userId} | Update User
[**UsersV1API_v1UserAgreeTerms**](UsersV1API.md#UsersV1API_v1UserAgreeTerms) | **POST** /v1/users/agree | Consent to the current terms and conditions
[**UsersV1API_v1UsersLogin**](UsersV1API.md#UsersV1API_v1UsersLogin) | **POST** /v1/users/login | Log In


# **UsersV1API_v1ChangePasswordUsers**
```c
// Change User Password
//
// Authenticated solely by the old-password.
//
void UsersV1API_v1ChangePasswordUsers(apiClient_t *apiClient, password_change_body_t *password_change_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**password_change_body** | **[password_change_body_t](password_change_body.md) \*** |  | 

### Return type

void

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UsersV1API_v1CreateUser**
```c
// Create User
//
user_create_return_t* UsersV1API_v1CreateUser(apiClient_t *apiClient, user_create_t *user_create);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**user_create** | **[user_create_t](user_create.md) \*** | User data | 

### Return type

[user_create_return_t](user_create_return.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UsersV1API_v1DeleteUser**
```c
// Delete User
//
void UsersV1API_v1DeleteUser(apiClient_t *apiClient, char *userId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**userId** | **char \*** | userId - uuid | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UsersV1API_v1GetResetLinkInfo**
```c
// Send Password Reset Link Info
//
reset_link_info_return_t* UsersV1API_v1GetResetLinkInfo(apiClient_t *apiClient, char *token);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**token** | **char \*** | Reset token | 

### Return type

[reset_link_info_return_t](reset_link_info_return.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UsersV1API_v1ResetUserPassword**
```c
// Reset User Password
//
void UsersV1API_v1ResetUserPassword(apiClient_t *apiClient, password_reset_body_t *password_reset_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**password_reset_body** | **[password_reset_body_t](password_reset_body.md) \*** | application/json | 

### Return type

void

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UsersV1API_v1SendUserResetLink**
```c
// Send Password Reset Link
//
void UsersV1API_v1SendUserResetLink(apiClient_t *apiClient, reset_link_body_t *reset_link_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**reset_link_body** | **[reset_link_body_t](reset_link_body.md) \*** | application/json | 

### Return type

void

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UsersV1API_v1UpdateUser**
```c
// Update User
//
// Update a user. Fields such as `name`, `label`, `password`, and `clusterAdministrator` can be updated.  Only users with the Cluster Administrator role can set or modify the `clusterAdministrator` flag.
//
void UsersV1API_v1UpdateUser(apiClient_t *apiClient, char *userId, user_update_t *user_update);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**userId** | **char \*** | userId - uuid | 
**user_update** | **[user_update_t](user_update.md) \*** | User data | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UsersV1API_v1UserAgreeTerms**
```c
// Consent to the current terms and conditions
//
agreed_ack_v1_t* UsersV1API_v1UserAgreeTerms(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[agreed_ack_v1_t](agreed_ack_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **UsersV1API_v1UsersLogin**
```c
// Log In
//
token_v1_t* UsersV1API_v1UsersLogin(apiClient_t *apiClient, credentials_t *credentials);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**credentials** | **[credentials_t](credentials.md) \*** | Authorization data | 

### Return type

[token_v1_t](token_v1.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

