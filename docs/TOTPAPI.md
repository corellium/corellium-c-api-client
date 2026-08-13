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
// Disables multi-factor authentication for the user after validating their password and current TOTP token, returning a refreshed login result.
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
// Confirms a previously generated TOTP secret and enables multi-factor authentication for the user, returning a refreshed login result.
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
// Generates a new TOTP secret for the user and returns it along with a QR code that can be scanned by an authenticator app.
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

