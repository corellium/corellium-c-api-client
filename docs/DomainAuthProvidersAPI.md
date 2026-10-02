# DomainAuthProvidersAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**DomainAuthProvidersAPI_v3CreateDomainAuthProvider**](DomainAuthProvidersAPI.md#DomainAuthProvidersAPI_v3CreateDomainAuthProvider) | **POST** /v3/domain/{domainId}/auth | Create a new auth provider for a domain
[**DomainAuthProvidersAPI_v3DeleteDomainAuthProvider**](DomainAuthProvidersAPI.md#DomainAuthProvidersAPI_v3DeleteDomainAuthProvider) | **DELETE** /v3/domain/{domainId}/auth/{providerId} | Delete an auth provider from a domain
[**DomainAuthProvidersAPI_v3ListDomainAuthProviders**](DomainAuthProvidersAPI.md#DomainAuthProvidersAPI_v3ListDomainAuthProviders) | **GET** /v3/domain/{domainId}/auth | Return all configured auth providers for a domain (including globally configured providers)
[**DomainAuthProvidersAPI_v3PatchDomainAuthProvider**](DomainAuthProvidersAPI.md#DomainAuthProvidersAPI_v3PatchDomainAuthProvider) | **PATCH** /v3/domain/{domainId}/auth/{providerId} | Partially update an auth provider for a domain
[**DomainAuthProvidersAPI_v3UpdateDomainAuthProvider**](DomainAuthProvidersAPI.md#DomainAuthProvidersAPI_v3UpdateDomainAuthProvider) | **PUT** /v3/domain/{domainId}/auth/{providerId} | Update an auth provider for a domain


# **DomainAuthProvidersAPI_v3CreateDomainAuthProvider**
```c
// Create a new auth provider for a domain
//
// **Required role:** Domain administrator.  Create a new auth provider for a domain.
//
create_domain_auth_provider_response_t* DomainAuthProvidersAPI_v3CreateDomainAuthProvider(apiClient_t *apiClient, char *domainId, create_domain_auth_provider_body_t *create_domain_auth_provider_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**domainId** | **char \*** | Domain identifier. | 
**create_domain_auth_provider_body** | **[create_domain_auth_provider_body_t](create_domain_auth_provider_body.md) \*** |  | 

### Return type

[create_domain_auth_provider_response_t](create_domain_auth_provider_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DomainAuthProvidersAPI_v3DeleteDomainAuthProvider**
```c
// Delete an auth provider from a domain
//
// **Required role:** Domain administrator.  Delete an auth provider from a domain.  Deletes are idempotent: a `providerId` that is not attached to the domain, or an unknown `domainId`, is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing. The underlying provider record is only removed when no other domain still references it, and default providers are never removed.
//
void DomainAuthProvidersAPI_v3DeleteDomainAuthProvider(apiClient_t *apiClient, char *domainId, char *providerId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**domainId** | **char \*** | Domain identifier. | 
**providerId** | **char \*** | Provider identifier. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DomainAuthProvidersAPI_v3ListDomainAuthProviders**
```c
// Return all configured auth providers for a domain (including globally configured providers)
//
// **Required role:** Domain administrator.  Return all configured auth providers for a domain (including globally configured providers).
//
domain_auth_providers_list_t* DomainAuthProvidersAPI_v3ListDomainAuthProviders(apiClient_t *apiClient, char *domainId, double *limit, double *offset);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**domainId** | **char \*** | Domain identifier. | 
**limit** | **double \*** | Most results to return in one page. Whole number from 1 to 1000; defaults to 100. A value outside that range is rejected with 400. | [optional] [default to 100]
**offset** | **double \*** | How many results to skip before this page starts; defaults to 0. To get the next page, add &#x60;limit&#x60; to the previous &#x60;offset&#x60;. | [optional] [default to 0]

### Return type

[domain_auth_providers_list_t](domain_auth_providers_list.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DomainAuthProvidersAPI_v3PatchDomainAuthProvider**
```c
// Partially update an auth provider for a domain
//
// **Required role:** Domain administrator.  Partially update an auth provider for a domain.
//
domain_auth_provider_response_t* DomainAuthProvidersAPI_v3PatchDomainAuthProvider(apiClient_t *apiClient, char *domainId, char *providerId, patch_domain_auth_provider_body_t *patch_domain_auth_provider_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**domainId** | **char \*** | Domain identifier. | 
**providerId** | **char \*** | Provider identifier. | 
**patch_domain_auth_provider_body** | **[patch_domain_auth_provider_body_t](patch_domain_auth_provider_body.md) \*** |  | [optional] 

### Return type

[domain_auth_provider_response_t](domain_auth_provider_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **DomainAuthProvidersAPI_v3UpdateDomainAuthProvider**
```c
// Update an auth provider for a domain
//
// **Required role:** Domain administrator.  Update an auth provider for a domain.
//
domain_auth_provider_response_t* DomainAuthProvidersAPI_v3UpdateDomainAuthProvider(apiClient_t *apiClient, char *domainId, char *providerId, create_domain_auth_provider_body_t *create_domain_auth_provider_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**domainId** | **char \*** | Domain identifier. | 
**providerId** | **char \*** | Provider identifier. | 
**create_domain_auth_provider_body** | **[create_domain_auth_provider_body_t](create_domain_auth_provider_body.md) \*** |  | 

### Return type

[domain_auth_provider_response_t](domain_auth_provider_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

