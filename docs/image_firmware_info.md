# image_firmware_info_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | **char \*** | Firmware type, e.g. &#39;ios&#39;. | [optional] 
**version** | **char \*** | OS version. | [optional] 
**build_id** | **char \*** | OS build ID. | [optional] 
**device_ids** | **list_t \*** | Device identifiers this firmware supports. | [optional] 
**board_config** | **char \*** | Board configuration. | [optional] 
**bdid** | **double** | Board ID. | [optional] 
**cpid** | **double** | Chip ID. | [optional] 
**platform** | **char \*** | Chip platform. | [optional] 
**boot_args** | [**image_firmware_info_boot_args_t**](image_firmware_info_boot_args.md) \* |  | [optional] 
**variants** | **list_t \*** | Firmware variants. | [optional] 
**device** | [**firmware_info_device_t**](firmware_info_device.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


