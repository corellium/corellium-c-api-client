# TOTPAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**TOTPAPI_v3DisableTotp**](TOTPAPI.md#TOTPAPI_v3DisableTotp) | **POST** /v3/totp/disable | Disable TOTP for this user
[**TOTPAPI_v3EnableTotp**](TOTPAPI.md#TOTPAPI_v3EnableTotp) | **POST** /v3/totp/enable | Enable TOTP for this user
[**TOTPAPI_v3GenerateTotp**](TOTPAPI.md#TOTPAPI_v3GenerateTotp) | **POST** /v3/totp/generate | Generate a TOTP secret


# **TOTPAPI_v3DisableTotp**
```c
// Disable TOTP for this user
//
// Turns two-factor sign-in off for your account. Send your `password` and a current six-digit code (`totpToken`) from your authenticator app. On success a confirmation email is sent, signing in no longer needs a code, and the response is a fresh login result with a new session token. Returns 401 if the password or code is wrong.
//
totp_status_response_t* TOTPAPI_v3DisableTotp(apiClient_t *apiClient, totp_disable_body_t *totp_disable_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**totp_disable_body** | **[totp_disable_body_t](totp_disable_body.md) \*** |  | 

### Return type

[totp_status_response_t](totp_status_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **TOTPAPI_v3EnableTotp**
```c
// Enable TOTP for this user
//
// Step 2 of turning on two-factor sign-in. Send the `secret` from `v3GenerateTotp`, the current six-digit code (`totpToken`) the authenticator app shows for it, and your account `password`. If the password is right and the code matches, two-factor sign-in is turned on and a confirmation email is sent.  From then on, signing in with a username and password also needs `totpToken` (see `v3AuthLogin`). The response is a fresh login result with a new session token; use it for later requests. Returns 401 if the password or code is wrong; generate a new code and retry.
//
totp_status_response_t* TOTPAPI_v3EnableTotp(apiClient_t *apiClient, totp_enable_body_t *totp_enable_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**totp_enable_body** | **[totp_enable_body_t](totp_enable_body.md) \*** |  | 

### Return type

[totp_status_response_t](totp_status_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **TOTPAPI_v3GenerateTotp**
```c
// Generate a TOTP secret
//
// Step 1 of turning on two-factor sign-in (TOTP: six-digit codes from an authenticator app such as Google Authenticator, 1Password or Authy). Creates a new secret and returns it both as text (`secret`) and as a QR code image. Show the QR code to the user to scan with their authenticator app, or let them type the secret in.  Nothing is turned on yet, and the secret is not saved: two-factor sign-in starts only after step 2, `v3EnableTotp`, succeeds. Keep the `secret` value; step 2 needs it. Calling this again creates a different secret. Returns 403 if your deployment is not licensed for two-factor sign-in.
//
totp_generate_response_t* TOTPAPI_v3GenerateTotp(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[totp_generate_response_t](totp_generate_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

