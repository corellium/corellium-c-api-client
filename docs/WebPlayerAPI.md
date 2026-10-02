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
// **Required role:** Domain administrator.  Creates a Web Player session: a limited token that lets someone use one device, embedded in your own web page, without giving them a Corellium account. Requires a domain administrator.  Choose the device (`projectId`, `instanceId`), how long the session lasts (`expiresIn`, at least 1800 seconds), and which parts of the device interface the viewer may use (`features`). Pass the returned `token` to the Web Player in your page. The website domains configured for embedding are listed by `v3GetWebPlayerAllowedDomains` and set with `webplayer.allowedDomains` on `PATCH /v3/domain`. End the session early with `v3DeleteWebPlayerSession`.
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
// **Required role:** Domain administrator.  Ends a Web Player session: its token stops working, so the embedded viewer loses access to the device. Requires a domain administrator. The device itself is not affected.  Deletes are idempotent: an unknown `sessionId` is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing.
//
void WebPlayerAPI_v3DeleteWebPlayerSession(apiClient_t *apiClient, char *sessionId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**sessionId** | **char \*** | Webplayer session identifier. | 

### Return type

void

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
// Returns the website domains configured for embedding the Web Player (`webplayer.allowedDomains` in your domain settings). Change the list with `PATCH /v3/domain`.
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
// **Required role:** Domain administrator.  Returns one Web Player session, including its token and expiration. Requires a domain administrator.
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
// **Required role:** Domain administrator.  Lists the Web Player sessions in your domain, with each session's ID, token and expiration. Requires a domain administrator. Results are paginated with `limit` and `offset`.
//
web_player_session_list_response_t* WebPlayerAPI_v3ListWebPlayerSessions(apiClient_t *apiClient, double *limit, double *offset);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**limit** | **double \*** | Most results to return in one page. Whole number from 1 to 1000; defaults to 100. A value outside that range is rejected with 400. | [optional] [default to 100]
**offset** | **double \*** | How many results to skip before this page starts; defaults to 0. To get the next page, add &#x60;limit&#x60; to the previous &#x60;offset&#x60;. | [optional] [default to 0]

### Return type

[web_player_session_list_response_t](web_player_session_list_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

