# instance_upgrade_body_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**os_version** | **char \*** | iOS version. | 
**os_build** | **char \*** | iOS build ID. | [optional] 
**image_id** | **char \*** | Image ID to upgrade from. Not currently supported: the handler rejects any non-empty imageId with a 400 (model.instanceUpdate). Supply osVersion/osBuild instead. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


