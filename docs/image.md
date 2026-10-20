# image_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**status** | **char \*** | Image status. | 
**id** | **char \*** | Image ID. | 
**name** | **char \*** | Name of the image, usually the original filename. Names are not unique: several images can share a name. | 
**type** | **image_type_t \*** |  | 
**size** | **double** | Size in bytes; null until upload completes. | [optional] 
**checksum** | **char \*** | MD5 checksum; null until upload completes. | [optional] 
**corellium_checksum** | **char \*** | Corellium checksum of the image; null until upload completes. | [optional] 
**encoding** | **image_encoding_t \*** |  | [optional] 
**project** | **char \*** | ID of the project the image belongs to. Null for a domain-level image, which is available across your domain rather than to one project. | [optional] 
**instance** | **char \*** | ID of the instance (device) the image is attached to, or null if it is not attached to one. | [optional] 
**created_at** | **char \*** | When Image was created. | [optional] 
**updated_at** | **char \*** | When Image was last updated. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


