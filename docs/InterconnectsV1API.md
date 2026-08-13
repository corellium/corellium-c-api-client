# InterconnectsV1API

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**InterconnectsV1API_v1CreateInterconnect**](InterconnectsV1API.md#InterconnectsV1API_v1CreateInterconnect) | **POST** /v1/interconnects | Create I/O Interconnect
[**InterconnectsV1API_v1DeleteInterconnect**](InterconnectsV1API.md#InterconnectsV1API_v1DeleteInterconnect) | **DELETE** /v1/interconnects/{interconnectId} | Delete I/O Interconnect
[**InterconnectsV1API_v1GetInterconnect**](InterconnectsV1API.md#InterconnectsV1API_v1GetInterconnect) | **GET** /v1/interconnects/{interconnectId} | Get Interconnect
[**InterconnectsV1API_v1ListInterconnects**](InterconnectsV1API.md#InterconnectsV1API_v1ListInterconnects) | **GET** /v1/interconnects | Get all I/O Interconnects
[**InterconnectsV1API_v1PatchInterconnect**](InterconnectsV1API.md#InterconnectsV1API_v1PatchInterconnect) | **PATCH** /v1/interconnects/{interconnectId} | Partial Update Interconnect
[**InterconnectsV1API_v1UpdateInterconnect**](InterconnectsV1API.md#InterconnectsV1API_v1UpdateInterconnect) | **PUT** /v1/interconnects/{interconnectId} | Update Interconnect


# **InterconnectsV1API_v1CreateInterconnect**
```c
// Create I/O Interconnect
//
// Create an I/O Interconnect for the specified project and attach virtual device interfaces.
//
interconnect_response_t* InterconnectsV1API_v1CreateInterconnect(apiClient_t *apiClient, create_interconnect_body_t *create_interconnect_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**create_interconnect_body** | **[create_interconnect_body_t](create_interconnect_body.md) \*** | The interconnect details | 

### Return type

[interconnect_response_t](interconnect_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InterconnectsV1API_v1DeleteInterconnect**
```c
// Delete I/O Interconnect
//
void InterconnectsV1API_v1DeleteInterconnect(apiClient_t *apiClient, char *interconnectId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**interconnectId** | **char \*** | The interconnect identifier | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InterconnectsV1API_v1GetInterconnect**
```c
// Get Interconnect
//
interconnect_response_t* InterconnectsV1API_v1GetInterconnect(apiClient_t *apiClient, char *interconnectId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**interconnectId** | **char \*** | The interconnect identifier | 

### Return type

[interconnect_response_t](interconnect_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InterconnectsV1API_v1ListInterconnects**
```c
// Get all I/O Interconnects
//
get_interconnects_response_t* InterconnectsV1API_v1ListInterconnects(apiClient_t *apiClient, double limit, double offset, char *name, char *protocol, char *type, char *status, char *project, char *sort);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**limit** | **double** | Maximum number of results to return (1-1000, default: 100) | [optional] 
**offset** | **double** | Number of results to skip (default: 0) | [optional] 
**name** | **char \*** | Filter by interconnect name (case insensitive) | [optional] 
**protocol** | **char \*** | Filter by protocol (comma separated) | [optional] 
**type** | **char \*** | Filter by type (comma separated) | [optional] 
**status** | **char \*** | Filter by status (comma separated) | [optional] 
**project** | **char \*** | Filter by project ID (comma separated) | [optional] 
**sort** | **char \*** | Sort order (e.g. \&quot;name\&quot; for ascending, \&quot;-name\&quot; for descending, comma separated) | [optional] 

### Return type

[get_interconnects_response_t](get_interconnects_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InterconnectsV1API_v1PatchInterconnect**
```c
// Partial Update Interconnect
//
// Update some interconnect details for the specified interconnect identifier.
//
interconnect_response_t* InterconnectsV1API_v1PatchInterconnect(apiClient_t *apiClient, char *interconnectId, partial_update_interconnect_request_t *partial_update_interconnect_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**interconnectId** | **char \*** | The interconnect identifier | 
**partial_update_interconnect_request** | **[partial_update_interconnect_request_t](partial_update_interconnect_request.md) \*** | The interconnect details to update | 

### Return type

[interconnect_response_t](interconnect_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InterconnectsV1API_v1UpdateInterconnect**
```c
// Update Interconnect
//
// Update interconnect details for the specified interconnect identifier.
//
interconnect_response_t* InterconnectsV1API_v1UpdateInterconnect(apiClient_t *apiClient, char *interconnectId, update_interconnect_body_t *update_interconnect_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**interconnectId** | **char \*** | The interconnect identifier | 
**update_interconnect_body** | **[update_interconnect_body_t](update_interconnect_body.md) \*** | The interconnect details to update | 

### Return type

[interconnect_response_t](interconnect_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

