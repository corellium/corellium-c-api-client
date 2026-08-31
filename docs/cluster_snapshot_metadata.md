# cluster_snapshot_metadata_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**live** | **int** | Whether this was a live snapshot. | [optional] 
**fresh** | **int** | Whether the snapshot was created immediately after device restore. | [optional] 
**hw_pac** | **double** | Hardware PAC value. | [optional] 
**springboard** | **int** | Whether this is a springboard snapshot. | [optional] 
**boot_options** | [**cluster_snapshot_metadata_boot_options_t**](cluster_snapshot_metadata_boot_options.md) \* |  | [optional] 
**device** | [**object_t**](.md) \* | Device metadata. | [optional] 
**flavor** | **char \*** | Device flavor. | [optional] 
**os_version** | **char \*** | OS version. | [optional] 
**os_build** | **char \*** | OS build identifier. | [optional] 
**patches** | **char \*** | Patches applied. | [optional] 
**cpid** | **double** | Chip ID. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


