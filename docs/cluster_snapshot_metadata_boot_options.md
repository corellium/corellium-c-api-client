# cluster_snapshot_metadata_boot_options_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**boot_args** | **char \*** | Boot arguments passed to the kernel at normal boot. | [optional] 
**restore_boot_args** | **char \*** | Boot arguments passed to the kernel during restore. | [optional] 
**udid** | **char \*** | Boot UDID. | [optional] 
**ecid** | **char \*** | Assigned ECID (hex). | [optional] 
**random_seed** | **char \*** | Random seed provided to boot, if any. | [optional] 
**pac** | **int** | Enable Pointer Authentication Codes (PAC), the Apple processor feature that signs pointers to block memory-corruption attacks. | [optional] 
**aprr** | **int** | Enable APRR, the Apple processor feature that controls memory page permissions (used by kernel protections). | [optional] 
**cores** | **double** | Number of CPU cores for the device. Only models whose &#x60;dynamicHardwareChanges&#x60; is true in &#x60;GET /v3/models&#x60; honor this; others always use the model default. The value must be between the model&#39;s &#x60;coresMin&#x60; and &#x60;coresMax&#x60;; a value outside that range is silently replaced by the model default rather than rejected, so check the device afterwards. | [optional] 
**ram** | **double** | Memory for the device, in MiB (1024 MiB &#x3D; 1 GiB). Only models whose &#x60;dynamicHardwareChanges&#x60; is true honor this; others always use the model default. The value must be between the model&#39;s &#x60;ramMin&#x60; and &#x60;ramMax&#x60;, and at most 1 GiB per CPU core; otherwise the request fails with 400. | [optional] 
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


