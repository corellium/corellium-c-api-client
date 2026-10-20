# instance_restore_status_v1_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | **char \*** | Restore type: 0&#x3D;Not Restore, 1&#x3D;Restore, 2&#x3D;CloneFromSnapshot | [optional] 
**stage** | **char \*** | Restore stage: download-images, prepare, boot, start, extracting, asr, flashing, done | [optional] 
**progress** | **double** | Stage progress (0-100) | [optional] 
**total_progress** | **double** | Total restore progress (0-100) | [optional] 
**heading** | **char \*** | Current heading for progress modal | [optional] 
**description** | **char \*** | Current description for progress modal | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


