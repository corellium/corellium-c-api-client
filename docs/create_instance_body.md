# create_instance_body_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**shared_snapshot** | **char \*** | Identifier of the snapshot that was shared. | [optional] 
**shared_snapshot_password** | **char \*** | Password of the shared snapshot named by sharedSnapshot, as set when it was shared. Required when that snapshot was shared with sharing type passwordPublicLink. This is the same value passed as password to POST /v3/snapshots/accept. | [optional] 
**name** | **char \*** | The name of the device. | [optional] 
**key** | **char \*** | Key used to encrypt the instance (hex). | [optional] 
**flavor** | **char \*** | Which device model to create. Use a &#x60;flavor&#x60; value from &#x60;GET /v3/models&#x60;. | [optional] 
**project_id** | **char \*** | Project the device is created in. The device uses that project&#39;s quota (cores, memory, device count). Get IDs from &#x60;GET /v3/projects&#x60;. | 
**os_version** | **char \*** | Operating-system version to install, as listed in &#x60;osVersion&#x60; by &#x60;GET /v3/models/{model}/software&#x60;. If you give only &#x60;osVersion&#x60;, the newest build of that version is used. | [optional] 
**os_build** | **char \*** | Exact build to install, as listed in &#x60;osBuild&#x60; by &#x60;GET /v3/models/{model}/software&#x60;. Give it together with &#x60;osVersion&#x60; to pin one build. You must give at least one of &#x60;osVersion&#x60; and &#x60;osBuild&#x60;. | [optional] 
**patches** | **list_t \*** | List of patches to apply. | [optional] 
**fw_package** | **char \*** | Optional. Boots a specific firmware file instead of choosing one from the model&#39;s software list. Either the &#x60;id&#x60; of an uploaded &#x60;fw&#x60; image (for example one in your project, see &#x60;POST /v3/images&#x60;) or an http(s) URL. When set, it wins over the software list; still pass &#x60;osVersion&#x60; or &#x60;osBuild&#x60;. A domain-level image is copied into your project first. Models whose &#x60;supportsCustomFirmwareImage&#x60; is false reject an image ID here. | [optional] 
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


