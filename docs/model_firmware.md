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
**corellium_checksum** | **char \*** | Corellium checksum, in the form algorithm$chunkSize$checksum. Absent for a domain upload. | [optional] 
**installed** | **int** | Whether the build is already on this appliance. An air-gapped deployment can use only these. | [optional] 
**size** | **double** | Software size in bytes. | [optional] 
**unique_id** | **char \*** | Identifier that the customer gives to the firmware. It is not a reference to another resource. | [optional] 
**metadata** | [**object_t**](.md) \* | Software metadata. | [optional] 
**release_date** | **char \*** | Release date. | [optional] 
**upload_date** | **char \*** | Date uploaded; may be an empty string when unknown. | [optional] 
**url** | **char \*** | URL the software is available at. | [optional] 
**orig_url** | **char \*** | URL the software is available at from the vendor. | [optional] 
**filename** | **char \*** | Software filename. | [optional] 
**rooted** | **int** | Whether a device from this firmware is rooted. Android has a rooted and a not-rooted build for each version. Null for iOS. | [optional] 
**_signed** | **int** | Whether the vendor still signs this build, from the upstream ipsw data. | [optional] 
**springboard_snapshot** | [**model_firmware_springboard_snapshot_t**](model_firmware_springboard_snapshot.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


