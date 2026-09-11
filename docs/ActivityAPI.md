# ActivityAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ActivityAPI_v3CreateActivityExport**](ActivityAPI.md#ActivityAPI_v3CreateActivityExport) | **POST** /v3/activity/export | Start activity export
[**ActivityAPI_v3DownloadActivity**](ActivityAPI.md#ActivityAPI_v3DownloadActivity) | **GET** /v3/activity/export/{taskId}/download | Download activity for a given task
[**ActivityAPI_v3GetActivityExportStatus**](ActivityAPI.md#ActivityAPI_v3GetActivityExportStatus) | **GET** /v3/activity/export/{taskId} | Get export task status
[**ActivityAPI_v3GetActivityExportTasks**](ActivityAPI.md#ActivityAPI_v3GetActivityExportTasks) | **GET** /v3/activity/export | Get all export tasks for user
[**ActivityAPI_v3ListActivities**](ActivityAPI.md#ActivityAPI_v3ListActivities) | **GET** /v3/activity | Get resource activities


# **ActivityAPI_v3CreateActivityExport**
```c
// Start activity export
//
// **Required role:** Domain administrator.  Start activity export.
//
create_activity_export_response_t* ActivityAPI_v3CreateActivityExport(apiClient_t *apiClient, char *accept, create_activity_export_body_t *create_activity_export_body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**accept** | **char \*** | Specifies the activity export file format. | 
**create_activity_export_body** | **[create_activity_export_body_t](create_activity_export_body.md) \*** |  | [optional] 

### Return type

[create_activity_export_response_t](create_activity_export_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ActivityAPI_v3DownloadActivity**
```c
// Download activity for a given task
//
// **Required role:** Domain administrator.  Download activity for a given task.
//
binary_t** ActivityAPI_v3DownloadActivity(apiClient_t *apiClient, char *taskId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**taskId** | **char \*** |  | 

### Return type

binary_t**



### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, text/csv

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ActivityAPI_v3GetActivityExportStatus**
```c
// Get export task status
//
// **Required role:** Domain administrator.  Get export task status.
//
activity_export_status_t* ActivityAPI_v3GetActivityExportStatus(apiClient_t *apiClient, char *taskId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**taskId** | **char \*** |  | 

### Return type

[activity_export_status_t](activity_export_status.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ActivityAPI_v3GetActivityExportTasks**
```c
// Get all export tasks for user
//
// **Required role:** Domain administrator.  Get all export tasks for user.
//
activity_export_task_list_t* ActivityAPI_v3GetActivityExportTasks(apiClient_t *apiClient, double *limit, double *offset);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**limit** | **double \*** | Maximum number of results to return. | [optional] [default to 100]
**offset** | **double \*** | Number of results to skip. | [optional] [default to 0]

### Return type

[activity_export_task_list_t](activity_export_task_list.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ActivityAPI_v3ListActivities**
```c
// Get resource activities
//
activity_list_response_t* ActivityAPI_v3ListActivities(apiClient_t *apiClient, char *resource, double *limit, double *offset, char *orderBy, char *instanceId, char *projectId, char *actor, char *search, char to, char from);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**resource** | **char \*** | Resource equality or LHS prefix filter. Examples: &#x60;resource&#x3D;value&#x60;, &#x60;resource[startsWith]&#x3D;value&#x60;, and &#x60;resource[!startsWith]&#x3D;value&#x60;. | [optional] 
**limit** | **double \*** | Number of entries to return. | [optional] [default to 10]
**offset** | **double \*** | Number of results to skip. | [optional] [default to 0]
**orderBy** | **char \*** | Activity model attribute to sort by. | [optional] [default to &#39;-createdAt&#39;]
**instanceId** | **char \*** | Instance identifier used to filter instance resources. | [optional] 
**projectId** | **char \*** | Project identifier used to filter instance resources. | [optional] 
**actor** | **char \*** | Actor identifier used to filter actor resources. | [optional] 
**search** | **char \*** | Last filter applied and is a fuzzy match on results. | [optional] 
**to** | **char** | Date to filter to, keyed off of createdAt. | [optional] 
**from** | **char** | Date to filter from, keyed off of createdAt. | [optional] 

### Return type

[activity_list_response_t](activity_list_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

