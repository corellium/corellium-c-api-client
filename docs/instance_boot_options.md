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
**serial** | **char \*** | Device serial number. | [optional] 
**no_snapshot_mount** | **int** | Do not mount iOS snapshot (iOS only). | [optional] 
**kernel_slide** | **char \*** | Kernel slide value (iOS only). | [optional] 
**cd_hashes** | **list_t \*** | Hashes of trusted binaries (iOS only). | [optional] 
**imei** | **char \*** | IMEI. | [optional] 
**imsi** | **char \*** | IMSI. | [optional] 
**ssid0** | **char \*** | WiFi SSID. | [optional] 
**ssid1** | **char \*** | Secondary WiFi SSID. | [optional] 
**wifi_mac** | **char \*** | WiFi MAC address. | [optional] 
**model_id** | **char \*** | Device model identifier. | [optional] 
**manufacturer_id** | **char \*** | Device manufacturer identifier. | [optional] 
**kernel_patches** | **char \*** | Kernel patches to apply. | [optional] 
**stop_on_fault** | **int** | Leaves the VM in the paused state on hypervisor vault if false. | [optional] [default to true]
**boot_addr** | **char \*** | Boot address. | [optional] 
**tzen** | **int** | Enable TrustZone security. | [optional] 
**authorized_keys** | **char \*** | SSH authorized keys to install on the instance. | [optional] 
**v_mmio** | [**list_t**](instance_boot_options_v_mmio_inner.md) \* | Parameters to export a VM address space range (and IRQ &amp; DMA functionality) over TCP to different models running on different machines or inside a different VM. | [optional] 
**fvp** | [**instance_boot_options_fvp_t**](instance_boot_options_fvp.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


