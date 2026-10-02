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
// **Start here.** Almost every other call needs you to prove who you are by sending a token in the `Authorization` header: `Authorization: Bearer <token>`. There are two kinds of token:  - **API token (best for scripts and automation).** A long-lived key you create once, in the web interface or with `POST /v3/auth/apitoken`. It is shown only once, so store it safely. You can send it directly as the Bearer token on every request, or exchange it here for a session token by sending `apiToken`. - **Session token.** A short-lived token (a JWT) returned by this call. Send it as the Bearer token until `expiration`, then log in again or renew it by sending it back as `token`.  Supply one of three credential types; when more than one is present they are resolved in this fixed order of precedence: (1) `username` + `password` (plus `totpToken`, a six-digit code from your authenticator app, when two-factor sign-in is enabled); (2) `token`, an existing session token, renewed for a fresh one; (3) `apiToken`, a persistent API key created by the user, not issued by login. The first credential type present wins and the rest are ignored. For example, sending both username/password and an apiToken authenticates via username/password. On success the response contains a newly-regenerated session token, its `expiration` time, and the session itself: the authenticated user and their domain. The apiToken is never returned. Renewing a Webplayer token instead returns the Webplayer session `identifier` and no `user`.  A 403 means the credentials were wrong (or a required two-factor code was missing or wrong).
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
// Ends the current session: the session token you send becomes invalid, so later requests with it fail with 401. For OpenID Connect (single sign-on) users this also ends the session with the identity provider. API tokens are not affected; remove one with `v3DeleteApiToken`.
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
// Deletes your API token, so it can no longer be used to sign in. Scripts using it will get 401 until you give them a new one from `v3GenerateApiToken`.  Deletes are idempotent: a request made when no API token is saved is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing.
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
// Creates a new API token for you: a long-lived key for scripts, CI jobs and SDKs, so they do not need your password. The response contains the token; it is shown only this once and cannot be retrieved later, so store it somewhere safe (for example a secrets manager). Each user has one API token at a time: generating a new one replaces the old one, which stops working immediately. Use it as `Authorization: Bearer <apiToken>`, or exchange it for a session token with `v3AuthLogin`.
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
// Starts single sign-on with the given identity provider by redirecting the caller's browser there (302). Open this URL in a browser, not from a script: after the user signs in at the provider, the provider sends the browser back to the callback route, which finishes signing in.
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
**limit** | **double \*** | Most results to return in one page. Whole number from 1 to 1000; defaults to 100. A value outside that range is rejected with 400. | [optional] [default to 100]
**offset** | **double \*** | How many results to skip before this page starts; defaults to 0. To get the next page, add &#x60;limit&#x60; to the previous &#x60;offset&#x60;. | [optional] [default to 0]

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
// Lists the ways users can sign in to your domain, such as username and password or single sign-on (SSO) through an identity provider like Okta. Needs no sign-in, so a login page can call it to show the right buttons. To sign in with an SSO provider, send the user's browser to its `authorizationUrl`.
//
auth_providers_list_response_t* AuthenticationAPI_v3ListAuthProviders(apiClient_t *apiClient, double *limit, double *offset);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**limit** | **double \*** | Most results to return in one page. Whole number from 1 to 1000; defaults to 100. A value outside that range is rejected with 400. | [optional] [default to 100]
**offset** | **double \*** | How many results to skip before this page starts; defaults to 0. To get the next page, add &#x60;limit&#x60; to the previous &#x60;offset&#x60;. | [optional] [default to 0]

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

