# DomainV1API

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**DomainV1API_v1CreateDomainWelcomeMessage**](DomainV1API.md#DomainV1API_v1CreateDomainWelcomeMessage) | **POST** /v1/domain/welcome | Create a welcome message for a domain
[**DomainV1API_v1DeleteDomainWelcomeMessage**](DomainV1API.md#DomainV1API_v1DeleteDomainWelcomeMessage) | **DELETE** /v1/domain/welcome | Delete the welcome message for the authenticated user&#39;s domain
[**DomainV1API_v1GetDomainWelcomeMessage**](DomainV1API.md#DomainV1API_v1GetDomainWelcomeMessage) | **GET** /v1/domain/welcome | Get the welcome message for the authenticated user&#39;s domain
[**DomainV1API_v1UpdateDomainWelcomeMessage**](DomainV1API.md#DomainV1API_v1UpdateDomainWelcomeMessage) | **PATCH** /v1/domain/welcome | Update a welcome message for a domain


# **DomainV1API_v1CreateDomainWelcomeMessage**
```c
// Create a welcome message for a domain
//
// Creates a new welcome message for the authenticated user's domain admin, or updates the existing one. The message is sanitized to prevent XSS.
//
domain_welcome_message_response_v1_t* DomainV1API_v1CreateDomainWelcomeMessage(apiClient_t *apiClient, create_domain_welcome_message_body_t *create_domain_welcome_message_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**create_domain_welcome_message_body** | **[create_domain_welcome_message_body_t](create_domain_welcome_message_body.md) \*** | application/json | 

### Return type

[domain_welcome_message_response_v1_t](domain_welcome_message_response_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DomainV1API_v1DeleteDomainWelcomeMessage**
```c
// Delete the welcome message for the authenticated user's domain
//
void DomainV1API_v1DeleteDomainWelcomeMessage(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

void

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DomainV1API_v1GetDomainWelcomeMessage**
```c
// Get the welcome message for the authenticated user's domain
//
// Retrieves the welcome message for the domain.
//
domain_welcome_message_response_v1_t* DomainV1API_v1GetDomainWelcomeMessage(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[domain_welcome_message_response_v1_t](domain_welcome_message_response_v1.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DomainV1API_v1UpdateDomainWelcomeMessage**
```c
// Update a welcome message for a domain
//
// Updates a new welcome message for the authenticated user's domain admin, or updates the existing one. The message is sanitized to prevent XSS.
//
domain_welcome_message_response_v1_t* DomainV1API_v1UpdateDomainWelcomeMessage(apiClient_t *apiClient, update_domain_welcome_message_request_t *update_domain_welcome_message_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**update_domain_welcome_message_request** | **[update_domain_welcome_message_request_t](update_domain_welcome_message_request.md) \*** | application/json | 

### Return type

[domain_welcome_message_response_v1_t](domain_welcome_message_response_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

