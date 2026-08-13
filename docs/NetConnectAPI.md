# NetConnectAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**NetConnectAPI_v1CreateNetworkConnection**](NetConnectAPI.md#NetConnectAPI_v1CreateNetworkConnection) | **POST** /v1/network/connections | Create a new Network Connection
[**NetConnectAPI_v1DeleteNetworkConnection**](NetConnectAPI.md#NetConnectAPI_v1DeleteNetworkConnection) | **DELETE** /v1/network/connections/{id} | Delete an existing Network Connection
[**NetConnectAPI_v1GetNetworkConnection**](NetConnectAPI.md#NetConnectAPI_v1GetNetworkConnection) | **GET** /v1/network/connections/{id} | Return the configuration and per project statuses for a single network provider.
[**NetConnectAPI_v1ListNetworkConnections**](NetConnectAPI.md#NetConnectAPI_v1ListNetworkConnections) | **GET** /v1/network/connections | List available network connections
[**NetConnectAPI_v1ListNetworkInterfaces**](NetConnectAPI.md#NetConnectAPI_v1ListNetworkInterfaces) | **GET** /v1/network/interfaces | List available physical network interfaces
[**NetConnectAPI_v1ListNetworkProviders**](NetConnectAPI.md#NetConnectAPI_v1ListNetworkProviders) | **GET** /v1/network/providers | List available network providers
[**NetConnectAPI_v1PartialUpdateNetworkConnection**](NetConnectAPI.md#NetConnectAPI_v1PartialUpdateNetworkConnection) | **PATCH** /v1/network/connections/{id} | Update Network Connection (partial)
[**NetConnectAPI_v1UpdateNetworkConnection**](NetConnectAPI.md#NetConnectAPI_v1UpdateNetworkConnection) | **PUT** /v1/network/connections/{id} | Update Network Connection


# **NetConnectAPI_v1CreateNetworkConnection**
```c
// Create a new Network Connection
//
// You must have the domain administrator role to create a network connection. VLAN networks are only supported in bridged networking mode.
//
network_connection_t* NetConnectAPI_v1CreateNetworkConnection(apiClient_t *apiClient, create_network_connection_options_t *create_network_connection_options);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**create_network_connection_options** | **[create_network_connection_options_t](create_network_connection_options.md) \*** | Network Connection Options | 

### Return type

[network_connection_t](network_connection.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **NetConnectAPI_v1DeleteNetworkConnection**
```c
// Delete an existing Network Connection
//
// You must have the domain administrator role to delete a network connection.
//
void NetConnectAPI_v1DeleteNetworkConnection(apiClient_t *apiClient, char *id, delete_network_connection_options_t *delete_network_connection_options);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** | Network Connection Identifier - uuid | 
**delete_network_connection_options** | **[delete_network_connection_options_t](delete_network_connection_options.md) \*** | Delete options | [optional] 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **NetConnectAPI_v1GetNetworkConnection**
```c
// Return the configuration and per project statuses for a single network provider.
//
// You must have the domain administrator or project administrator role to fetch a network connection.
//
network_connection_t* NetConnectAPI_v1GetNetworkConnection(apiClient_t *apiClient, char *id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** | Network Connection Identifier - uuid | 

### Return type

[network_connection_t](network_connection.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **NetConnectAPI_v1ListNetworkConnections**
```c
// List available network connections
//
// You must have the domain administrator or project administrator role to list network connections.
//
network_connection_pagination_result_t* NetConnectAPI_v1ListNetworkConnections(apiClient_t *apiClient, double limit, double offset);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**limit** | **double** | The maximum number of items to return. | [optional] 
**offset** | **double** | The starting index of the items to return. | [optional] 

### Return type

[network_connection_pagination_result_t](network_connection_pagination_result.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **NetConnectAPI_v1ListNetworkInterfaces**
```c
// List available physical network interfaces
//
// Lists available physical network interfaces that can be used for VLAN configuration. You must have the domain administrator role to list network interfaces.
//
list_t* NetConnectAPI_v1ListNetworkInterfaces(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type


[list_t](char.md) *




### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **NetConnectAPI_v1ListNetworkProviders**
```c
// List available network providers
//
// Provides a list of registered network providers to be used when [creating network connections](#post-/v1/network/connections). You must have the domain administrator role to list network providers.
//
network_connection_provider_pagination_result_t* NetConnectAPI_v1ListNetworkProviders(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[network_connection_provider_pagination_result_t](network_connection_provider_pagination_result.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **NetConnectAPI_v1PartialUpdateNetworkConnection**
```c
// Update Network Connection (partial)
//
// Only updates the specified attributes. You must have the domain administrator role to update a network connection.
//
network_connection_t* NetConnectAPI_v1PartialUpdateNetworkConnection(apiClient_t *apiClient, char *id, update_network_connection_options_t *update_network_connection_options);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** | Network Connection Identifier - uuid | 
**update_network_connection_options** | **[update_network_connection_options_t](update_network_connection_options.md) \*** | Network Connection Options | 

### Return type

[network_connection_t](network_connection.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **NetConnectAPI_v1UpdateNetworkConnection**
```c
// Update Network Connection
//
// You must have the domain administrator role to update a network connection.
//
network_connection_t* NetConnectAPI_v1UpdateNetworkConnection(apiClient_t *apiClient, char *id, update_network_connection_options_t *update_network_connection_options);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** | Network Connection Identifier - uuid | 
**update_network_connection_options** | **[update_network_connection_options_t](update_network_connection_options.md) \*** | Network Connection Options | 

### Return type

[network_connection_t](network_connection.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

