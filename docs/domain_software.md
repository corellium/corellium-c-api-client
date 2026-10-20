# domain_software_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**image_id** | **char \*** | Identifier of the uploaded image. Pass to &#x60;deleteImage&#x60; to remove the upload. | 
**flavor** | **char \*** | Flavor the firmware applies to. | 
**description** | **char \*** | Human-readable device name. | 
**model** | **char \*** | Device product identifier. | 
**platform** | **char \*** | Device platform, when known. | [optional] 
**has_product_image** | **int** | Whether a product image is available for this flavor. | 
**os_version** | **char \*** | OS version. | [optional] 
**os_build** | **char \*** | OS build. | [optional] 
**filename** | **char \*** | Uploaded filename. | 
**size** | **double** | Firmware size in bytes. | [optional] 
**release_date** | **char \*** | Release date. | [optional] 
**upload_date** | **char \*** | Date the firmware was uploaded. | 
**download_url** | **char \*** | Signed link the firmware can be downloaded from. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


