# firmware_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**model** | **list_t \*** | Device models the firmware supports. | 
**firmware_assets** | **list_t \*** | Associated firmware asset URLs; null when assets have not been checked for yet. | [optional] 
**filename** | **char \*** | Firmware filename. | 
**type** | **char \*** | Firmware type. | [optional] 
**size** | **double** | Firmware size in bytes. | 
**url** | **char \*** | Firmware download URL. | [optional] 
**version** | **char \*** | Firmware version. | 
**build_id** | **char \*** | Firmware build ID. | [optional] 
**md5sum** | **char \*** | MD5 checksum. | [optional] 
**sha1sum** | **char \*** | SHA-1 checksum. | [optional] 
**sha256sum** | **char \*** | SHA-256 checksum. | [optional] 
**corellium_checksum** | **char \*** | Corellium chunked checksum (&lt;algo&gt;$&lt;chunkSize&gt;$&lt;hash&gt;); used for upload preflight. | [optional] 
**release_date** | **char \*** | Release date; may be an empty string. | [optional] 
**upload_date** | **char \*** | Upload date; may be an empty string. | [optional] 
**metadata** | [**object_t**](.md) \* | Firmware metadata. | [optional] 
**unique_id** | **char \*** | Customer-provided identifier; an arbitrary string, not a UUID. | [optional] 
**android_flavor** | **char \*** | Android device flavor; only present for coreimg firmwares. | [optional] 
**api_version** | **char \*** | Android API version; only present for coreimg firmwares. | [optional] 
**rooted** | **int** | Whether a device created from this firmware is rooted. Android publishes a &#x60;&lt;rev&gt; user&#x60; (not rooted) and a &#x60;&lt;rev&gt; userdebug&#x60; (rooted) build per version. Null on iOS, where rooting is not a property of the firmware. | [optional] 
**installed** | **int** | Whether the firmware is installed. | [optional] 
**created_at** | **char \*** | When the record was created. | [optional] 
**updated_at** | **char \*** | When the record was last updated. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


