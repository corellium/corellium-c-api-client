# WebPlayerAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**WebPlayerAPI_v3CreateWebPlayerSession**](WebPlayerAPI.md#WebPlayerAPI_v3CreateWebPlayerSession) | **POST** /v3/webplayer | Create a webplayer session
[**WebPlayerAPI_v3DeleteWebPlayerSession**](WebPlayerAPI.md#WebPlayerAPI_v3DeleteWebPlayerSession) | **DELETE** /v3/webplayer/{sessionId} | Delete a webplayer session
[**WebPlayerAPI_v3GetWebPlayerAllowedDomains**](WebPlayerAPI.md#WebPlayerAPI_v3GetWebPlayerAllowedDomains) | **GET** /v3/webplayer/allowedDomains | Get allowed webplayer domains
[**WebPlayerAPI_v3GetWebPlayerSession**](WebPlayerAPI.md#WebPlayerAPI_v3GetWebPlayerSession) | **GET** /v3/webplayer/{sessionId} | Get a webplayer session
[**WebPlayerAPI_v3ListWebPlayerSessions**](WebPlayerAPI.md#WebPlayerAPI_v3ListWebPlayerSessions) | **GET** /v3/webplayer | List webplayer sessions


# **WebPlayerAPI_v3CreateWebPlayerSession**
```c
// Create a webplayer session
//
// Creates a new webplayer session for the requested instance.
//
web_player_created_session_t* WebPlayerAPI_v3CreateWebPlayerSession(apiClient_t *apiClient, create_web_player_session_body_t *create_web_player_session_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**create_web_player_session_body** | **[create_web_player_session_body_t](create_web_player_session_body.md) \*** |  | 

### Return type

[web_player_created_session_t](web_player_created_session.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **WebPlayerAPI_v3DeleteWebPlayerSession**
```c
// Delete a webplayer session
//
// Deletes the webplayer session identified by the given sessionId.
//
list_t* WebPlayerAPI_v3DeleteWebPlayerSession(apiClient_t *apiClient, char *sessionId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**sessionId** | **char \*** | Webplayer session identifier. | 

### Return type


[list_t](char.md) *




### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **WebPlayerAPI_v3GetWebPlayerAllowedDomains**
```c
// Get allowed webplayer domains
//
// Returns the list of domains that webplayer sessions are permitted to access.
//
web_player_allowed_domains_t* WebPlayerAPI_v3GetWebPlayerAllowedDomains(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[web_player_allowed_domains_t](web_player_allowed_domains.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **WebPlayerAPI_v3GetWebPlayerSession**
```c
// Get a webplayer session
//
// Returns the webplayer session identified by the given sessionId.
//
list_t* WebPlayerAPI_v3GetWebPlayerSession(apiClient_t *apiClient, char *sessionId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**sessionId** | **char \*** | Webplayer session identifier. | 

### Return type

[list_t](web_player_session.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **WebPlayerAPI_v3ListWebPlayerSessions**
```c
// List webplayer sessions
//
// Returns a paginated list of webplayer sessions for the authenticated user.
//
web_player_session_list_response_t* WebPlayerAPI_v3ListWebPlayerSessions(apiClient_t *apiClient, double *limit, double *offset);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**limit** | **double \*** | Maximum number of results to return. | [optional] [default to 100]
**offset** | **double \*** | Number of results to skip. | [optional] [default to 0]

### Return type

[web_player_session_list_response_t](web_player_session_list_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

