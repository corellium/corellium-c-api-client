# model_firmware_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**os_version** | **char \*** | OS version. | 
**os_build** | **char \*** | OS build identifier. | [optional] 
**android_flavor** | **char \*** | Android-only flavor. | [optional] 
**api_version** | **char \*** | Android-only API version. | [optional] 
**sha256sum** | **char \*** | SHA-256 checksum. | [optional] 
**sha1sum** | **char \*** | SHA-1 checksum. | [optional] 
**md5sum** | **char \*** | MD5 checksum. | [optional] 
**size** | **double** | Software size in bytes. | [optional] 
**unique_id** | **char \*** | Identifier provided by the customer to uniquely identify firmware; it is not a reference to another API resource. | [optional] 
**metadata** | [**object_t**](.md) \* | Software metadata. | [optional] 
**release_date** | **char \*** | Release date. | [optional] 
**upload_date** | **char \*** | Date uploaded; may be an empty string when unknown. | [optional] 
**url** | **char \*** | URL the software is available at. | [optional] 
**orig_url** | **char \*** | URL the software is available at from the vendor. | [optional] 
**filename** | **char \*** | Software filename. | [optional] 
**rooted** | **int** | Whether a device created from this firmware is rooted. Android publishes a &#x60;&lt;rev&gt; user&#x60; (not rooted) and a &#x60;&lt;rev&gt; userdebug&#x60; (rooted) build per version. Null on iOS, where rooting is not a property of the firmware. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


