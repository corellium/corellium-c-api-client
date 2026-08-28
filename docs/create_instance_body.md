# create_instance_body_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**shared_snapshot** | **char \*** | Identifier of the snapshot that was shared. | [optional] 
**shared_snapshot_password** | **char \*** | Password of the shared snapshot named by sharedSnapshot, as set when it was shared. Required when that snapshot was shared with sharing type passwordPublicLink. This is the same value passed as password to POST /v3/snapshots/accept. | [optional] 
**name** | **char \*** | The name of the device. | [optional] 
**key** | **char \*** | Key used to encrypt the instance (hex). | [optional] 
**flavor** | **char \*** | The flavor ID. | [optional] 
**project_id** | **char \*** | Project UUID. | 
**os_version** | **char \*** | OS version. | [optional] 
**os_build** | **char \*** | OS build. | [optional] 
**patches** | **list_t \*** | List of patches to apply. | [optional] 
**fw_package** | **char \*** | URL or image ID. | [optional] 
**original_firmware_package_url** | **char \*** | URL that the firmware package is available at. | [optional] 
**encrypt** | **int** | Whether to encrypt the instance. | [optional] 
**wifi_mac** | **char \*** | WiFi MAC address to assign to the instance. | [optional] 
**wan_access** | **int** | Manages internet access. | [optional] 
**volume** | [**volume_options_t**](volume_options.md) \* |  | [optional] 
**snapshot** | **char \*** | Snapshot ID for this instance to be cloned from if defined. | [optional] 
**boot_options** | [**instance_boot_options_t**](instance_boot_options.md) \* |  | [optional] 
**sbs** | **int** | Should attempt to create springboard snapshot. | [optional] 
**charm_boot_args** | [**list_t**](object.md) \* | Optional charm boot args. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


