# ActivityV1API

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ActivityV1API_v1ActivityExport**](ActivityV1API.md#ActivityV1API_v1ActivityExport) | **POST** /v1/activity/export | Start activity export
[**ActivityV1API_v1ActivityList**](ActivityV1API.md#ActivityV1API_v1ActivityList) | **GET** /v1/activity | Get resource activities
[**ActivityV1API_v1DownloadActivity**](ActivityV1API.md#ActivityV1API_v1DownloadActivity) | **GET** /v1/activity/export/{taskId}/download | Download activity
[**ActivityV1API_v1GetActivityExportStatus**](ActivityV1API.md#ActivityV1API_v1GetActivityExportStatus) | **GET** /v1/activity/export/{taskId} | Get export task status
[**ActivityV1API_v1GetActivityExportTasks**](ActivityV1API.md#ActivityV1API_v1GetActivityExportTasks) | **GET** /v1/activity/export | Get all export tasks for user


# **ActivityV1API_v1ActivityExport**
```c
// Start activity export
//
activity_export_response_t* ActivityV1API_v1ActivityExport(apiClient_t *apiClient, activity_export_dto_t *activity_export_dto);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**activity_export_dto** | **[activity_export_dto_t](activity_export_dto.md) \*** |  | 

### Return type

[activity_export_response_t](activity_export_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ActivityV1API_v1ActivityList**
```c
// Get resource activities
//
activity_list_t* ActivityV1API_v1ActivityList(apiClient_t *apiClient, activity_request_t *request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**request** | **[activity_request_t](.md) \*** |  | [optional] 

### Return type

[activity_list_t](activity_list.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ActivityV1API_v1DownloadActivity**
```c
// Download activity
//
// Download activity for a given task
//
activity_list_t* ActivityV1API_v1DownloadActivity(apiClient_t *apiClient, char *taskId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**taskId** | **char \*** | Export ID | 

### Return type

[activity_list_t](activity_list.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ActivityV1API_v1GetActivityExportStatus**
```c
// Get export task status
//
activity_list_t* ActivityV1API_v1GetActivityExportStatus(apiClient_t *apiClient, char *taskId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**taskId** | **char \*** | Export ID | 

### Return type

[activity_list_t](activity_list.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **ActivityV1API_v1GetActivityExportTasks**
```c
// Get all export tasks for user
//
activity_list_t* ActivityV1API_v1GetActivityExportTasks(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[activity_list_t](activity_list.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

