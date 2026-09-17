# model_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | **char \*** | Device type, e.g. iOS, Android or IoT. | 
**flavor** | **char \*** | Flavor identifier, for example \&quot;iphone17a\&quot;. Use this value to create an instance. | 
**description** | **char \*** | Human-readable model name, e.g. \&quot;iPhone Air\&quot;. | [optional] 
**model** | **char \*** | Marketing model identifier, e.g. \&quot;iPhone18,4\&quot;. | 
**hardware_model** | **char \*** | Hardware board model, e.g. \&quot;d23ap\&quot;. | [optional] 
**board_config** | **char \*** | Board configuration identifier. | [optional] 
**platform** | **char \*** | Device platform. | [optional] 
**cpid** | **double** | Chip ID. | [optional] 
**bdid** | **double** | Board ID. | [optional] 
**vendor** | **char \*** | Vendor gating this model, when it is vendor-restricted. | [optional] 
**hidden** | **int** | Whether this model is hidden from device pickers. | 
**is_beta** | **int** | Whether this model is a beta device. | 
**peripherals** | **int** | Whether the device supports peripherals. | 
**has_software** | **int** | Whether any software build is available for this model. | 
**supports_rapid_start** | **int** | Whether at least one software build for this model can start from a snapshot. | 
**default_firmware** | **char \*** | Filename pattern that selects the default build. It ignores case. Null if the model has no default. | [optional] 
**cores** | **double** | Default number of cores. | 
**cores_min** | **double** | Minimum number of cores. | 
**cores_max** | **double** | Maximum number of cores. | 
**cores_step** | **double** | Increment between selectable core counts. | [optional] 
**cores_allowed** | **list_t \*** | Selectable core counts, sorted. | [optional] 
**ram** | **double** | Default RAM in MiB. | 
**ram_min** | **double** | Minimum RAM in MiB. | 
**ram_max** | **double** | Maximum RAM in MiB. | 
**dynamic_hardware_changes** | **int** | Whether cores and memory can be changed while the instance is running. | 
**partitions** | [**list_t**](model_partition.md) \* | Storage partitions of this model. | 
**frame** | [**model_frame_t**](model_frame.md) \* |  | 
**product_image** | [**model_product_image_t**](model_product_image.md) \* |  | 
**has_frame_variant** | **int** | Whether this model is the bezel-framed variant of its device type. | 
**show_options** | **list_t \*** | Preset boot options this model offers. | 
**string_udid** | **int** | Whether this model takes its UDID as a free-form string. | 
**charm_boot_args** | [**list_t**](object.md) \* | Model-specific boot argument field definitions. | [optional] 
**requires_preset_boot_options** | **int** | Whether a preset boot option must be chosen when creating an instance. | 
**supports_preset_boot_options** | **int** | Whether preset boot options are supported. | 
**supports_custom_firmware** | **int** | Whether custom firmware is supported. | 
**supports_custom_firmware_image** | **int** | Whether a user-supplied firmware image can be uploaded for this model. | 
**supports_custom_kernel** | **int** | Whether a custom kernel is supported. | 
**supports_custom_devicetree** | **int** | Whether a custom device tree is supported. | 
**supports_custom_mmio** | **int** | Whether custom MMIO configuration is supported. | 
**supports_fvp** | **int** | Whether this model is an Arm Fixed Virtual Platform. | 
**mast** | **int** | Whether MATRIX is enabled. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


