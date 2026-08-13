# image_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**status** | **char \*** | Image status. | 
**id** | **char \*** | Image ID. | 
**name** | **char \*** | Descriptive image name. | 
**type** | **corellium_api_image_TYPE_e** | Image type. | 
**size** | **double** | Size in bytes; null until upload completes. Absent for generated artifacts. | [optional] 
**checksum** | **char \*** | MD5 checksum; null until upload completes. Absent for generated artifacts. | [optional] 
**corellium_checksum** | **char \*** | Corellium checksum of the image; null until upload completes. Absent for generated artifacts. | [optional] 
**encoding** | **corellium_api_image_ENCODING_e** | How the file is stored. Absent for generated artifacts. | [optional] 
**project** | **char \*** | Owning project ID; null for domain-level images. Absent for generated artifacts. | [optional] 
**instance** | **char \*** | Owning instance ID; null for project-level images. Absent for generated artifacts. | [optional] 
**created_at** | **char \*** | When Image was created. Absent for generated artifacts. | [optional] 
**updated_at** | **char \*** | When Image was last updated. Absent for generated artifacts. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


