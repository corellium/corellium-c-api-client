# storage_device_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**id** | **char \*** | Unique identifier for the storage device. | 
**device** | **char \*** | Device node path (e.g. /dev/sdb1). | 
**fs_type** | **char \*** | Filesystem type (e.g. ext4, vfat). | [optional] 
**fs_uuid** | **char \*** | Filesystem UUID. | [optional] 
**label** | **char \*** | Filesystem label. | [optional] 
**serial** | **char \*** | Device serial number. | [optional] 
**vendor** | **char \*** | Device vendor. | [optional] 
**model** | **char \*** | Device model. | [optional] 
**mount_policy** | **corellium_api_storage_device_MOUNTPOLICY_e** | Mount policy for the device. | 
**status** | **corellium_api_storage_device_STATUS_e** | Current mount status. | 
**created_at** | **char \*** | Timestamp when the record was created. | 
**updated_at** | **char \*** | Timestamp when the record was last updated. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


