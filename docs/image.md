# image_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**status** | **char \*** | Image status. | 
**id** | **char \*** | Image ID. | 
**name** | **char \*** | Descriptive image name. | 
**type** | **image_type_t \*** |  | 
**size** | **double** | Size in bytes; null until upload completes. | [optional] 
**checksum** | **char \*** | MD5 checksum; null until upload completes. | [optional] 
**corellium_checksum** | **char \*** | Corellium checksum of the image; null until upload completes. | [optional] 
**encoding** | **image_encoding_t \*** |  | [optional] 
**project** | **char \*** | Owning project ID; null for domain-level images. | [optional] 
**instance** | **char \*** | Owning instance ID; null for project-level images. | [optional] 
**created_at** | **char \*** | When Image was created. | [optional] 
**updated_at** | **char \*** | When Image was last updated. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


