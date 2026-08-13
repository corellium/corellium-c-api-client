# firmware_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**model** | **list_t \*** | Device models the firmware supports. | 
**firmware_assets** | **list_t \*** | Associated firmware asset URLs. | [optional] 
**filename** | **char \*** | Firmware filename. | 
**type** | **char \*** | Firmware type. | [optional] 
**size** | **double** | Firmware size in bytes. | 
**url** | **char \*** | Firmware download URL. | 
**version** | **char \*** | Firmware version. | 
**build_id** | **char \*** | Firmware build ID. | 
**md5sum** | **char \*** | MD5 checksum. | [optional] 
**sha1sum** | **char \*** | SHA-1 checksum. | [optional] 
**sha256sum** | **char \*** | SHA-256 checksum. | [optional] 
**release_date** | **char \*** | Release date. | [optional] 
**upload_date** | **char \*** | Upload date. | [optional] 
**metadata** | [**object_t**](.md) \* | Firmware metadata. | [optional] 
**unique_id** | **char \*** | Unique identifier. | [optional] 
**installed** | **int** | Whether the firmware is installed. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


