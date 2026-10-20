# agent_app_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**tags** | **list_t \*** | App tags (iOS only). | [optional] 
**running** | **int** | Whether the app is currently running. | [optional] 
**disk_usage** | **double** | Disk usage in bytes. | [optional] 
**date** | **double** | Unix timestamp (seconds) of when the app was installed. | [optional] 
**application_type** | **char \*** | Application type. | 
**name** | **char \*** | App display name (not present for all Android apps). | [optional] 
**bundle_id** | **char \*** | App bundle identifier. | 
**bundle_path** | **char \*** | Path to the app bundle (iOS only). | [optional] 
**bundle_data_path** | **char \*** | Path to the app bundle data (iOS only). | [optional] 
**is_launchable** | **int** | Whether the app is launchable (Android only). | [optional] 
**icon** | **char \*** | Base64-encoded app icon when loadIcons is enabled. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


