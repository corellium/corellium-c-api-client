# DomainAuthProviderAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**DomainAuthProviderAPI_v1CreateDomainAuthProvider**](DomainAuthProviderAPI.md#DomainAuthProviderAPI_v1CreateDomainAuthProvider) | **POST** /v1/domain/{domainId}/auth | Create a new auth provider for a domain
[**DomainAuthProviderAPI_v1DeleteDomainAuthProvider**](DomainAuthProviderAPI.md#DomainAuthProviderAPI_v1DeleteDomainAuthProvider) | **DELETE** /v1/domain/{domainId}/auth/{providerId} | Delete an auth provider from a domain
[**DomainAuthProviderAPI_v1GetDomainAuthProviders**](DomainAuthProviderAPI.md#DomainAuthProviderAPI_v1GetDomainAuthProviders) | **GET** /v1/domain/{domainId}/auth | Return all configured auth providers for a domain (including globally configured providers)
[**DomainAuthProviderAPI_v1UpdateDomainAuthProvider**](DomainAuthProviderAPI.md#DomainAuthProviderAPI_v1UpdateDomainAuthProvider) | **PUT** /v1/domain/{domainId}/auth/{providerId} | Update an auth provider for a domain


# **DomainAuthProviderAPI_v1CreateDomainAuthProvider**
```c
// Create a new auth provider for a domain
//
domain_auth_provider_response_v1_t* DomainAuthProviderAPI_v1CreateDomainAuthProvider(apiClient_t *apiClient, char *domainId, domain_auth_provider_request_t *domain_auth_provider_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**domainId** | **char \*** | Domain ID - uuid | 
**domain_auth_provider_request** | **[domain_auth_provider_request_t](domain_auth_provider_request.md) \*** | Request Data | 

### Return type

[domain_auth_provider_response_v1_t](domain_auth_provider_response_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DomainAuthProviderAPI_v1DeleteDomainAuthProvider**
```c
// Delete an auth provider from a domain
//
void DomainAuthProviderAPI_v1DeleteDomainAuthProvider(apiClient_t *apiClient, char *domainId, char *providerId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**domainId** | **char \*** | Domain ID - uuid | 
**providerId** | **char \*** | Provider ID - uuid | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DomainAuthProviderAPI_v1GetDomainAuthProviders**
```c
// Return all configured auth providers for a domain (including globally configured providers)
//
list_t* DomainAuthProviderAPI_v1GetDomainAuthProviders(apiClient_t *apiClient, char *domainId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**domainId** | **char \*** | Domain ID - uuid | 

### Return type

[list_t](domain_auth_provider_response_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DomainAuthProviderAPI_v1UpdateDomainAuthProvider**
```c
// Update an auth provider for a domain
//
domain_auth_provider_response_v1_t* DomainAuthProviderAPI_v1UpdateDomainAuthProvider(apiClient_t *apiClient, char *domainId, char *providerId, domain_auth_provider_request_t *domain_auth_provider_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**domainId** | **char \*** | Domain ID - uuid | 
**providerId** | **char \*** | Provider ID - uuid | 
**domain_auth_provider_request** | **[domain_auth_provider_request_t](domain_auth_provider_request.md) \*** | Request Data | 

### Return type

[domain_auth_provider_response_v1_t](domain_auth_provider_response_v1.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

