# instance_boot_options_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**boot_args** | **char \*** | Boot arguments passed to the kernel at normal boot. | [optional] 
**restore_boot_args** | **char \*** | Boot arguments passed to the kernel during restore. | [optional] 
**udid** | **char \*** | Boot UDID. | [optional] 
**ecid** | **char \*** | Assigned ECID (hex). | [optional] 
**random_seed** | **char \*** | Random seed provided to boot, if any. | [optional] 
**pac** | **int** | Enable PAC. | [optional] 
**aprr** | **int** | Enable APRR. | [optional] 
**cores** | **double** | Number of CPU cores. Supported only by models with dynamic hardware changes enabled. | [optional] 
**ram** | **double** | Memory allocation in MB. Supported only by models with dynamic hardware changes enabled. | [optional] 
**additional_tags** | **list_t \*** | Additional boot tags to apply to the instance. Each value must be one of the supported charm boot tags. | [optional] 
**kernel** | [**instance_boot_options_kernel_t**](instance_boot_options_kernel.md) \* |  | [optional] 
**pongo** | [**instance_boot_options_pongo_t**](instance_boot_options_pongo.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


