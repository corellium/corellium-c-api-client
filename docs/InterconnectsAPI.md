# InterconnectsAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**InterconnectsAPI_v3CreateInterconnect**](InterconnectsAPI.md#InterconnectsAPI_v3CreateInterconnect) | **POST** /v3/interconnects | Create I/O Interconnect
[**InterconnectsAPI_v3DeleteInterconnect**](InterconnectsAPI.md#InterconnectsAPI_v3DeleteInterconnect) | **DELETE** /v3/interconnects/{interconnectId} | Delete I/O Interconnect
[**InterconnectsAPI_v3GetInterconnect**](InterconnectsAPI.md#InterconnectsAPI_v3GetInterconnect) | **GET** /v3/interconnects/{interconnectId} | Get Interconnect
[**InterconnectsAPI_v3ListInterconnects**](InterconnectsAPI.md#InterconnectsAPI_v3ListInterconnects) | **GET** /v3/interconnects | List I/O Interconnects
[**InterconnectsAPI_v3PatchInterconnect**](InterconnectsAPI.md#InterconnectsAPI_v3PatchInterconnect) | **PATCH** /v3/interconnects/{interconnectId} | Patch I/O Interconnect
[**InterconnectsAPI_v3UpdateInterconnect**](InterconnectsAPI.md#InterconnectsAPI_v3UpdateInterconnect) | **PUT** /v3/interconnects/{interconnectId} | Update I/O Interconnect


# **InterconnectsAPI_v3CreateInterconnect**
```c
// Create I/O Interconnect
//
// Create an I/O Interconnect for the specified project and attach virtual device interfaces.
//
create_interconnect_response_schema_t* InterconnectsAPI_v3CreateInterconnect(apiClient_t *apiClient, create_interconnect_v3_body_t *create_interconnect_v3_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**create_interconnect_v3_body** | **[create_interconnect_v3_body_t](create_interconnect_v3_body.md) \*** |  | 

### Return type

[create_interconnect_response_schema_t](create_interconnect_response_schema.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InterconnectsAPI_v3DeleteInterconnect**
```c
// Delete I/O Interconnect
//
void InterconnectsAPI_v3DeleteInterconnect(apiClient_t *apiClient, char *interconnectId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**interconnectId** | **char \*** | The interconnect identifier. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InterconnectsAPI_v3GetInterconnect**
```c
// Get Interconnect
//
get_interconnect_response_schema_t* InterconnectsAPI_v3GetInterconnect(apiClient_t *apiClient, char *interconnectId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**interconnectId** | **char \*** | The interconnect identifier. | 

### Return type

[get_interconnect_response_schema_t](get_interconnect_response_schema.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InterconnectsAPI_v3ListInterconnects**
```c
// List I/O Interconnects
//
get_interconnects_response_schema_t* InterconnectsAPI_v3ListInterconnects(apiClient_t *apiClient, double *limit, double *offset, char *name, char *protocol, char *type, char *status, char *sort, char *projectId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**limit** | **double \*** | Maximum number of results to return. | [optional] [default to 100]
**offset** | **double \*** | Number of results to skip. | [optional] [default to 0]
**name** | **char \*** | Filter by interconnect name (case insensitive). | [optional] 
**protocol** | **char \*** | Filter by protocol (comma separated). | [optional] 
**type** | **char \*** | Filter by type (comma separated). | [optional] 
**status** | **char \*** | Filter by status (comma separated). | [optional] 
**sort** | **char \*** | Sort order (e.g. \&quot;name\&quot; for ascending, \&quot;-name\&quot; for descending, comma separated). | [optional] 
**projectId** | **char \*** | Filter by project ID (comma separated). | [optional] 

### Return type

[get_interconnects_response_schema_t](get_interconnects_response_schema.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InterconnectsAPI_v3PatchInterconnect**
```c
// Patch I/O Interconnect
//
get_interconnect_response_schema_t* InterconnectsAPI_v3PatchInterconnect(apiClient_t *apiClient, char *interconnectId, patch_interconnect_body_t *patch_interconnect_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**interconnectId** | **char \*** | The interconnect identifier. | 
**patch_interconnect_body** | **[patch_interconnect_body_t](patch_interconnect_body.md) \*** |  | [optional] 

### Return type

[get_interconnect_response_schema_t](get_interconnect_response_schema.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **InterconnectsAPI_v3UpdateInterconnect**
```c
// Update I/O Interconnect
//
get_interconnect_response_schema_t* InterconnectsAPI_v3UpdateInterconnect(apiClient_t *apiClient, char *interconnectId, update_interconnect_v3_body_t *update_interconnect_v3_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**interconnectId** | **char \*** | The interconnect identifier. | 
**update_interconnect_v3_body** | **[update_interconnect_v3_body_t](update_interconnect_v3_body.md) \*** |  | 

### Return type

[get_interconnect_response_schema_t](get_interconnect_response_schema.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

