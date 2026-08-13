# agent_app_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**tags** | **list_t \*** | App tags (iOS only). | [optional] 
**running** | **int** | Whether the app is currently running. | 
**disk_usage** | **double** | Disk usage in bytes. | 
**date** | **double** | Unix timestamp (seconds) of when the app was installed. | 
**application_type** | **char \*** | Application type. | 
**name** | **char \*** | App display name (not present for all Android apps). | [optional] 
**bundle_id** | **char \*** | App bundle identifier. | 
**bundle_path** | **char \*** | Path to the app bundle. | 
**bundle_data_path** | **char \*** | Path to the app bundle data. | 
**is_launchable** | **int** | Whether the app is launchable (Android only). | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


