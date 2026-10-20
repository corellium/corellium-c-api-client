# image_creation_options_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | **char \*** | Image type | 
**encoding** | **corellium_api_image_creation_options_ENCODING_e** | How the file is stored | 
**encapsulated** | **int** | set to false if the uploaded file is not encapsulated inside an outer zipfile | [optional] 
**name** | **char \*** | Image name | [optional] 
**full_path** | **char \*** | Full local path to image file. When specified, this file MUST exist! | [optional] 
**project** | **char \*** | Project ID | [optional] 
**instance** | **char \*** | Instance ID | [optional] 
**file** | **binary_t*** | Optionally the actual file | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


