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
// **Required role:** Domain administrator.  Starts building a file of activity records for download, for audits or offline analysis. Requires a domain administrator and the user-logging license feature (403 otherwise).  Choose the file format with the `Accept` header: `application/json` or `text/csv` (any other value returns 400). The body takes the same filters as `v3ListActivities`, but the export is not paginated: it contains every matching record.  **Workflow:** 1. `v3CreateActivityExport` (this call). Returns 201 with an `id` like `activity-export/<UUID>`. 2. Poll `v3GetActivityExportStatus` with the `<UUID>` part until `status` is `complete`. 3. `v3DownloadActivity` with the same UUID to get the file.
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
// **Required role:** Domain administrator.  Downloads the file produced by a finished activity export, as JSON or CSV depending on the format you asked for. Pass the UUID part of the export `id`. Returns 404 if the file is not ready or does not exist; check `v3GetActivityExportStatus` first. Requires a domain administrator and the user-logging license feature.
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
// **Required role:** Domain administrator.  Returns the status of an activity export started with `v3CreateActivityExport`. Pass the UUID part of the export `id`. Poll until `status` is `complete`, then call `v3DownloadActivity`. Finished tasks are cleaned up, so a task that no longer exists is reported as `complete`. Requires a domain administrator and the user-logging license feature.
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
// **Required role:** Domain administrator.  Lists the activity exports you have started, with each one's status and the filters it used. Requires a domain administrator and the user-logging license feature. Results are paginated with `limit` and `offset`.
//
activity_export_task_list_t* ActivityAPI_v3GetActivityExportTasks(apiClient_t *apiClient, double *limit, double *offset);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**limit** | **double \*** | Most results to return in one page. Whole number from 1 to 1000; defaults to 100. A value outside that range is rejected with 400. | [optional] [default to 100]
**offset** | **double \*** | How many results to skip before this page starts; defaults to 0. To get the next page, add &#x60;limit&#x60; to the previous &#x60;offset&#x60;. | [optional] [default to 0]

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
// Returns the activity log: a record of what happened in your domain, such as devices created, started and deleted, users signing in, and settings changed, with who did it and when. You only see events your role allows. Filter by device, project, user, time range or free text, and page with `limit` and `offset`. For a full download of many records, use `v3CreateActivityExport` instead.
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
**orderBy** | **char \*** | Field to sort by, for example &#x60;createdAt&#x60;. Prefix with &#x60;-&#x60; for newest or largest first. Defaults to &#x60;-createdAt&#x60; (newest first). | [optional] [default to &#39;-createdAt&#39;]
**instanceId** | **char \*** | Only activity about this device. | [optional] 
**projectId** | **char \*** | Only activity in this project. | [optional] 
**actor** | **char \*** | Only activity performed by this user (user ID). | [optional] 
**search** | **char \*** | Free-text search. Applied last, as a loose match on the results that pass the other filters. | [optional] 
**to** | **char** | Only activity at or before this time (ISO 8601). | [optional] 
**from** | **char** | Only activity at or after this time (ISO 8601). | [optional] 

### Return type

[activity_list_response_t](activity_list_response.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

