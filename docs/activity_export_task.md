# activity_export_task_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**identifier** | **char \*** | Task identifier in the form &#x60;activity-export/&lt;UUID&gt;&#x60;. | 
**scheduled_at** | **char \*** | Timestamp of when the task is scheduled to execute. | 
**status** | **corellium_api_activity_export_task_STATUS_e** | Where the export task is. Poll until it is &#x60;complete&#x60;, then download the file. | [optional] 
**args** | [**object_t**](.md) \* | Arguments passed to the task. | 
**created_at** | **char \*** | Timestamp of when the task was created. | 
**updated_at** | **char \*** | Timestamp of when the task was last updated. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


