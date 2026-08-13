# create_image_body_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | **corellium_api_create_image_body_TYPE_e** |  | 
**encoding** | **corellium_api_create_image_body_ENCODING_e** |  | 
**encapsulated** | **int** | Set false if the uploaded file should not be unzipped. Defaults to false for direct uploads. | [optional] 
**name** | **char \*** | Image name. Defaults to the uploaded filename when omitted in multipart uploads. | [optional] 
**full_path** | **char \*** | Absolute path to an existing file on the server. | [optional] 
**project_id** | **char \*** | Owning project ID. | [optional] 
**instance** | **char \*** | Owning instance ID. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


