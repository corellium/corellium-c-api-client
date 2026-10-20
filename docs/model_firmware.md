# model_firmware_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**os_version** | **char \*** | Operating-system version of this build. Pass it as &#x60;osVersion&#x60; when you create an instance. | 
**os_build** | **char \*** | Build identifier of this version. Pass it as &#x60;osBuild&#x60; (together with &#x60;osVersion&#x60;) when you create an instance to get exactly this build. If you pass only &#x60;osVersion&#x60;, the newest build of that version is used. | [optional] 
**android_flavor** | **char \*** | Android-only flavor. | [optional] 
**api_version** | **char \*** | Android-only API version. | [optional] 
**sha256sum** | **char \*** | SHA-256 checksum. | [optional] 
**sha1sum** | **char \*** | SHA-1 checksum. | [optional] 
**md5sum** | **char \*** | MD5 checksum. | [optional] 
**corellium_checksum** | **char \*** | Corellium checksum, in the form algorithm$chunkSize$checksum. Absent for a domain upload. | [optional] 
**installed** | **int** | Whether this build is already stored on your Corellium deployment. A build that is not installed can only be used if your deployment is allowed to fetch it from the vendor; an air-gapped deployment can use only installed builds. | [optional] 
**size** | **double** | Software size in bytes. | [optional] 
**unique_id** | **char \*** | A label chosen by whoever packaged this firmware. It is not guaranteed to be unique and cannot be used to look up an image or firmware; select a build with &#x60;osVersion&#x60; and &#x60;osBuild&#x60; instead. | [optional] 
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


