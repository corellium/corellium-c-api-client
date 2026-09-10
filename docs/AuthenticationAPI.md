# AuthenticationAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**AuthenticationAPI_v3AuthLogin**](AuthenticationAPI.md#AuthenticationAPI_v3AuthLogin) | **POST** /v3/auth/login | Log in
[**AuthenticationAPI_v3AuthLogout**](AuthenticationAPI.md#AuthenticationAPI_v3AuthLogout) | **POST** /v3/auth/logout | Log out
[**AuthenticationAPI_v3DeleteApiToken**](AuthenticationAPI.md#AuthenticationAPI_v3DeleteApiToken) | **DELETE** /v3/auth/apitoken | Delete API token
[**AuthenticationAPI_v3FetchAuthProviderMetadata**](AuthenticationAPI.md#AuthenticationAPI_v3FetchAuthProviderMetadata) | **GET** /v3/auth/providers/fetch-metadata | Fetch SAML metadata
[**AuthenticationAPI_v3GenerateApiToken**](AuthenticationAPI.md#AuthenticationAPI_v3GenerateApiToken) | **POST** /v3/auth/apitoken | Generate API token
[**AuthenticationAPI_v3GetAuthProviderAuthorizationUrl**](AuthenticationAPI.md#AuthenticationAPI_v3GetAuthProviderAuthorizationUrl) | **GET** /v3/auth/providers/{providerId}/authorization_url | Get provider authorization URL
[**AuthenticationAPI_v3GetAuthProviderCallback**](AuthenticationAPI.md#AuthenticationAPI_v3GetAuthProviderCallback) | **GET** /v3/auth/providers/{providerId}/callback | Authentication provider callback (GET)
[**AuthenticationAPI_v3GetAuthProviderSpMetadata**](AuthenticationAPI.md#AuthenticationAPI_v3GetAuthProviderSpMetadata) | **GET** /v3/auth/providers/{providerId}/spmetadata | Get service provider metadata
[**AuthenticationAPI_v3ListAuthProviderTypes**](AuthenticationAPI.md#AuthenticationAPI_v3ListAuthProviderTypes) | **GET** /v3/auth/providers/types | List authentication provider types
[**AuthenticationAPI_v3ListAuthProviders**](AuthenticationAPI.md#AuthenticationAPI_v3ListAuthProviders) | **GET** /v3/auth/providers | List authentication providers
[**AuthenticationAPI_v3PostAuthProviderCallback**](AuthenticationAPI.md#AuthenticationAPI_v3PostAuthProviderCallback) | **POST** /v3/auth/providers/{providerId}/callback | Authentication provider callback (POST)


# **AuthenticationAPI_v3AuthLogin**
```c
// Log in
//
// Authenticate and receive a session token. Supply one of three credential types; when more than one is present they are resolved in this fixed order of precedence: (1) `username` + `password` (plus `totpToken` when two-factor is enabled); (2) `token` — an existing session token, renewed for a fresh one; (3) `apiToken` — a persistent API key created by the user (in the web UI or via `POST /v3/auth/apitoken`), not issued by login. The first credential type present wins and the rest are ignored. For example, sending both username/password and an apiToken authenticates via username/password. On success the response always contains a newly-regenerated session token (JWT); the apiToken is never returned.
//
login_result_t* AuthenticationAPI_v3AuthLogin(apiClient_t *apiClient, login_body_t *login_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**login_body** | **[login_body_t](login_body.md) \*** |  | [optional] 

### Return type

[login_result_t](login_result.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AuthenticationAPI_v3AuthLogout**
```c
// Log out
//
// Revoke the current session. For OpenID Connect users this also revokes the upstream session.
//
void AuthenticationAPI_v3AuthLogout(apiClient_t *apiClient);
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

# **AuthenticationAPI_v3DeleteApiToken**
```c
// Delete API token
//
// Delete the authenticated user's currently saved API token.
//
void AuthenticationAPI_v3DeleteApiToken(apiClient_t *apiClient);
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

# **AuthenticationAPI_v3FetchAuthProviderMetadata**
```c
// Fetch SAML metadata
//
// Fetch SAML metadata XML from a trusted provider URL. The URL must be HTTPS and from an allowed domain.
//
char* AuthenticationAPI_v3FetchAuthProviderMetadata(apiClient_t *apiClient, char *url);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**url** | **char \*** | HTTPS URL of the SAML metadata endpoint to fetch. | 

### Return type

char*



### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/xml, application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AuthenticationAPI_v3GenerateApiToken**
```c
// Generate API token
//
// Generate a new API token for the authenticated user. The token is returned once and replaces any previously issued token.
//
api_token_result_t* AuthenticationAPI_v3GenerateApiToken(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[api_token_result_t](api_token_result.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AuthenticationAPI_v3GetAuthProviderAuthorizationUrl**
```c
// Get provider authorization URL
//
// Redirect the caller to the authorization URL of the given authentication provider.
//
void AuthenticationAPI_v3GetAuthProviderAuthorizationUrl(apiClient_t *apiClient, char *providerId, char *type, char *code, char *email, char *token);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**providerId** | **char \*** | Provider identifier. | 
**type** | **char \*** | Sign-up flow type. | [optional] 
**code** | **char \*** | Sign-up code for subscriber invites and trial requests. | [optional] 
**email** | **char \*** | Sign-up email (may differ from SSO email). | [optional] 
**token** | **char \*** | Sign-up token for a team invite. | [optional] 

### Return type

void

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AuthenticationAPI_v3GetAuthProviderCallback**
```c
// Authentication provider callback (GET)
//
// Handle the final authorization response from an SSO provider and redirect back to the client.
//
void AuthenticationAPI_v3GetAuthProviderCallback(apiClient_t *apiClient, char *providerId, char *error, char *error_description);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**providerId** | **char \*** | Provider identifier. | 
**error** | **char \*** | Error code from the provider. | [optional] 
**error_description** | **char \*** | Error description from the provider. | [optional] 

### Return type

void

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: Not defined

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AuthenticationAPI_v3GetAuthProviderSpMetadata**
```c
// Get service provider metadata
//
// Return the SAML service provider metadata XML for the given authentication provider.
//
char* AuthenticationAPI_v3GetAuthProviderSpMetadata(apiClient_t *apiClient, char *providerId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**providerId** | **char \*** | Provider identifier. | 

### Return type

char*



### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/xml, application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AuthenticationAPI_v3ListAuthProviderTypes**
```c
// List authentication provider types
//
// **Required role:** Domain administrator.  Return schemas describing the supported authentication provider types.
//
auth_provider_types_list_response_t* AuthenticationAPI_v3ListAuthProviderTypes(apiClient_t *apiClient, double *limit, double *offset);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**limit** | **double \*** | Maximum number of results to return. | [optional] [default to 100]
**offset** | **double \*** | Number of results to skip. | [optional] [default to 0]

### Return type

[auth_provider_types_list_response_t](auth_provider_types_list_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AuthenticationAPI_v3ListAuthProviders**
```c
// List authentication providers
//
// Return all configured authentication providers for the requesting domain.
//
auth_providers_list_response_t* AuthenticationAPI_v3ListAuthProviders(apiClient_t *apiClient, double *limit, double *offset);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**limit** | **double \*** | Maximum number of results to return. | [optional] [default to 100]
**offset** | **double \*** | Number of results to skip. | [optional] [default to 0]

### Return type

[auth_providers_list_response_t](auth_providers_list_response.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AuthenticationAPI_v3PostAuthProviderCallback**
```c
// Authentication provider callback (POST)
//
// Handle the final authorization response from an SSO provider (POST binding) and redirect back to the client.
//
void AuthenticationAPI_v3PostAuthProviderCallback(apiClient_t *apiClient, char *providerId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**providerId** | **char \*** | Provider identifier. | 

### Return type

void

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: Not defined

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

