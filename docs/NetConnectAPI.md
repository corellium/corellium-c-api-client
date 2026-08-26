# NetConnectAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**NetConnectAPI_v3CreateNetworkConnection**](NetConnectAPI.md#NetConnectAPI_v3CreateNetworkConnection) | **POST** /v3/network/connections | Create a new Network Connection
[**NetConnectAPI_v3DeleteNetworkConnection**](NetConnectAPI.md#NetConnectAPI_v3DeleteNetworkConnection) | **DELETE** /v3/network/connections/{id} | Delete an existing Network Connection
[**NetConnectAPI_v3GetNetworkConnection**](NetConnectAPI.md#NetConnectAPI_v3GetNetworkConnection) | **GET** /v3/network/connections/{id} | Fetch an existing Network Connection
[**NetConnectAPI_v3ListNetworkConnections**](NetConnectAPI.md#NetConnectAPI_v3ListNetworkConnections) | **GET** /v3/network/connections | List available network connections
[**NetConnectAPI_v3ListNetworkInterfaces**](NetConnectAPI.md#NetConnectAPI_v3ListNetworkInterfaces) | **GET** /v3/network/interfaces | List available physical network interfaces
[**NetConnectAPI_v3ListNetworkProviders**](NetConnectAPI.md#NetConnectAPI_v3ListNetworkProviders) | **GET** /v3/network/providers | List available network providers
[**NetConnectAPI_v3PartialUpdateNetworkConnection**](NetConnectAPI.md#NetConnectAPI_v3PartialUpdateNetworkConnection) | **PATCH** /v3/network/connections/{id} | Update Network Connection (patch)
[**NetConnectAPI_v3UpdateNetworkConnection**](NetConnectAPI.md#NetConnectAPI_v3UpdateNetworkConnection) | **PUT** /v3/network/connections/{id} | Update Network Connection


# **NetConnectAPI_v3CreateNetworkConnection**
```c
// Create a new Network Connection
//
// You must have the domain administrator role to create a network connection. VLAN networks are only supported in bridged networking mode.
//
list_t* NetConnectAPI_v3CreateNetworkConnection(apiClient_t *apiClient, object_t *body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**body** | **[object_t](object.md) \*** |  | 

### Return type

[list_t](object.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **NetConnectAPI_v3DeleteNetworkConnection**
```c
// Delete an existing Network Connection
//
// Delete an existing Network Connection. You must have the domain administrator role to delete a network connection.
//
void NetConnectAPI_v3DeleteNetworkConnection(apiClient_t *apiClient, char *id, v3_delete_network_connection_request_t *v3_delete_network_connection_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** | Network Connection Identifier. | 
**v3_delete_network_connection_request** | **[v3_delete_network_connection_request_t](v3_delete_network_connection_request.md) \*** |  | [optional] 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **NetConnectAPI_v3GetNetworkConnection**
```c
// Fetch an existing Network Connection
//
// Returns the configuration and per-project statuses for a single network connection. You must have the domain administrator or project administrator role to fetch a network connection.
//
object_t* NetConnectAPI_v3GetNetworkConnection(apiClient_t *apiClient, char *id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** | Network Connection Identifier. | 

### Return type

[object_t](object.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **NetConnectAPI_v3ListNetworkConnections**
```c
// List available network connections
//
// You must have the domain administrator or project administrator role to list network connections.
//
network_connections_t* NetConnectAPI_v3ListNetworkConnections(apiClient_t *apiClient, double *limit, double *offset);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**limit** | **double \*** | Maximum number of results to return. | [optional] [default to 100]
**offset** | **double \*** | Number of results to skip. | [optional] [default to 0]

### Return type

[network_connections_t](network_connections.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **NetConnectAPI_v3ListNetworkInterfaces**
```c
// List available physical network interfaces
//
// Lists available physical network interfaces that can be used for VLAN configuration. You must have the domain administrator role to list network interfaces.
//
network_interfaces_t* NetConnectAPI_v3ListNetworkInterfaces(apiClient_t *apiClient, double *limit, double *offset);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**limit** | **double \*** | Maximum number of results to return. | [optional] [default to 100]
**offset** | **double \*** | Number of results to skip. | [optional] [default to 0]

### Return type

[network_interfaces_t](network_interfaces.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **NetConnectAPI_v3ListNetworkProviders**
```c
// List available network providers
//
// Provides a list of registered network providers to be used when creating network connections via [`createNetworkConnection`](#operation/v3CreateNetworkConnection). You must have the domain administrator role to list network providers.
//
network_connection_providers_t* NetConnectAPI_v3ListNetworkProviders(apiClient_t *apiClient, double *limit, double *offset);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**limit** | **double \*** | Maximum number of results to return. | [optional] [default to 100]
**offset** | **double \*** | Number of results to skip. | [optional] [default to 0]

### Return type

[network_connection_providers_t](network_connection_providers.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **NetConnectAPI_v3PartialUpdateNetworkConnection**
```c
// Update Network Connection (patch)
//
// Only updates the specified attributes. You must have the domain administrator role to update a network connection.
//
object_t* NetConnectAPI_v3PartialUpdateNetworkConnection(apiClient_t *apiClient, char *id, v3_partial_update_network_connection_request_t *v3_partial_update_network_connection_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** | Network Connection Identifier. | 
**v3_partial_update_network_connection_request** | **[v3_partial_update_network_connection_request_t](v3_partial_update_network_connection_request.md) \*** |  | [optional] 

### Return type

[object_t](object.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **NetConnectAPI_v3UpdateNetworkConnection**
```c
// Update Network Connection
//
// You must have the domain administrator role to update a network connection.
//
object_t* NetConnectAPI_v3UpdateNetworkConnection(apiClient_t *apiClient, char *id, v3_update_network_connection_request_t *v3_update_network_connection_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** | Network Connection Identifier. | 
**v3_update_network_connection_request** | **[v3_update_network_connection_request_t](v3_update_network_connection_request.md) \*** |  | 

### Return type

[object_t](object.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

