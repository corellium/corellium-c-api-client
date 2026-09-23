# storage_file_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**name** | **char \*** | File or directory name. | 
**ext** | **char \*** | File extension, or null for directories. | [optional] 
**type** | **corellium_api_storage_file_TYPE_e** | Entry type. | 
**size** | **double** | Size in bytes (0 for directories). | 
**last_modified_time** | **char \*** | Last modified timestamp, or 1970-01-01T00:00:00.000Z when the entry could not be stat&#39;d. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


