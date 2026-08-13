# WebPlayerV1API

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**WebPlayerV1API_v1WebPlayerAllowedDomains**](WebPlayerV1API.md#WebPlayerV1API_v1WebPlayerAllowedDomains) | **GET** /v1/webplayer/allowedDomains | Retrieve the list of allowed domains for all Webplayer sessions
[**WebPlayerV1API_v1WebPlayerCreateSession**](WebPlayerV1API.md#WebPlayerV1API_v1WebPlayerCreateSession) | **POST** /v1/webplayer | Create a new Webplayer Session
[**WebPlayerV1API_v1WebPlayerDestroySession**](WebPlayerV1API.md#WebPlayerV1API_v1WebPlayerDestroySession) | **DELETE** /v1/webplayer/{sessionId} | Tear down a Webplayer Session
[**WebPlayerV1API_v1WebPlayerListSessions**](WebPlayerV1API.md#WebPlayerV1API_v1WebPlayerListSessions) | **GET** /v1/webplayer | List all Webplayer sessions
[**WebPlayerV1API_v1WebPlayerSessionInfo**](WebPlayerV1API.md#WebPlayerV1API_v1WebPlayerSessionInfo) | **GET** /v1/webplayer/{sessionId} | Retrieve Webplayer Session Information


# **WebPlayerV1API_v1WebPlayerAllowedDomains**
```c
// Retrieve the list of allowed domains for all Webplayer sessions
//
void WebPlayerV1API_v1WebPlayerAllowedDomains(apiClient_t *apiClient);
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

# **WebPlayerV1API_v1WebPlayerCreateSession**
```c
// Create a new Webplayer Session
//
web_player_session_v1_t* WebPlayerV1API_v1WebPlayerCreateSession(apiClient_t *apiClient, web_player_create_session_request_t *web_player_create_session_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**web_player_create_session_request** | **[web_player_create_session_request_t](web_player_create_session_request.md) \*** | Request Data | 

### Return type

[web_player_session_v1_t](web_player_session_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **WebPlayerV1API_v1WebPlayerDestroySession**
```c
// Tear down a Webplayer Session
//
list_t* WebPlayerV1API_v1WebPlayerDestroySession(apiClient_t *apiClient, char *sessionId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**sessionId** | **char \*** | Webplayer Session identifier | 

### Return type


[list_t](char.md) *




### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **WebPlayerV1API_v1WebPlayerListSessions**
```c
// List all Webplayer sessions
//
list_t* WebPlayerV1API_v1WebPlayerListSessions(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[list_t](web_player_session_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **WebPlayerV1API_v1WebPlayerSessionInfo**
```c
// Retrieve Webplayer Session Information
//
web_player_session_v1_t* WebPlayerV1API_v1WebPlayerSessionInfo(apiClient_t *apiClient, char *sessionId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**sessionId** | **char \*** | Webplayer Session identifier | 

### Return type

[web_player_session_v1_t](web_player_session_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

