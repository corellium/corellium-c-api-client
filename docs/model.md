# model_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | **char \*** | Device type, e.g. iOS, Android or IoT. | 
**flavor** | **char \*** | The model&#39;s identifier, for example \&quot;iphone17a\&quot;. Pass this value as &#x60;flavor&#x60; when you create an instance, and as &#x60;{model}&#x60; when you list its software. | 
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
**cores** | **double** | Number of CPU cores a new instance of this model gets if you do not choose one. | 
**cores_min** | **double** | Fewest CPU cores you can give an instance of this model. | 
**cores_max** | **double** | Most CPU cores you can give an instance of this model. | 
**cores_step** | **double** | If present, core counts must go up in steps of this size between &#x60;coresMin&#x60; and &#x60;coresMax&#x60;. | [optional] 
**cores_allowed** | **list_t \*** | If present, the exact core counts you may choose, smallest first. When set, use one of these values. | [optional] 
**ram** | **double** | Memory, in MiB (1024 &#x3D; 1 GiB), that a new instance gets if you do not choose an amount. | 
**ram_min** | **double** | Smallest memory amount, in MiB, you can give an instance of this model. | 
**ram_max** | **double** | Largest memory amount, in MiB, you can give an instance of this model. | 
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
**mast** | **int** | Whether MATRIX security assessments can run on instances of this model. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


