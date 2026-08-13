# instance_restore_status_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | **char \*** | Restore type: 0&#x3D;Not Restore, 1&#x3D;Restore, 2&#x3D;CloneFromSnapshot. | [optional] 
**stage** | **char \*** | Restore stage. | [optional] 
**progress** | [**object_t**](.md) \* | Stage progress (0-100). Serialized as a string when non-zero; emitted as the number 0 at the start of a restore, and absent when no restore is in progress. | [optional] 
**total_progress** | [**object_t**](.md) \* | Total restore progress (0-100). Serialized as a string when non-zero; emitted as the number 0 at the start of a restore, and absent when no restore is in progress. | [optional] 
**heading** | **char \*** | Current heading for progress modal. | [optional] 
**description** | **char \*** | Current description for progress modal. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


