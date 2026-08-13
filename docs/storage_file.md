# storage_file_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**name** | **char \*** | File or directory name. | 
**ext** | **char \*** | File extension, or null for directories. | [optional] 
**type** | **corellium_api_storage_file_TYPE_e** | Entry type. | 
**size** | **double** | Size in bytes (0 for directories). | 
**last_modified_time** | **char \*** | Last modified timestamp. Null for special entries without an mtime. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


