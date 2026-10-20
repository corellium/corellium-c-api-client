# domain_config_input_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**android** | **int** | Whether Android devices are enabled. | [optional] 
**billing** | **int** | Whether billing is enabled. | [optional] 
**organization_name** | **char \*** | Organization name. | [optional] 
**license_type** | **char \*** | License type identifier. | [optional] 
**signup_email** | **char \*** | Email used for domain signup. | [optional] 
**coupon_code** | **char \*** | Coupon code. | [optional] 
**trial** | [**domain_config_input_trial_t**](domain_config_input_trial.md) \* |  | [optional] 
**no_ios** | **int** | Whether iOS devices are disabled. | [optional] 
**device_dhcp_server** | **int** | Whether the device DHCP server is enabled. | [optional] 
**files** | **int** | Whether the files feature is enabled. | [optional] 
**files_only** | **int** | Whether the domain is in files-only mode. | [optional] 
**remote_gpu** | **int** | Whether remote GPU nodes are used. | [optional] 
**prioritized_nodes** | **list_t \*** | Node addresses (host:port) to prefer when placing devices. | [optional] 
**enable_netgear_devices** | **int** | Whether Netgear devices are enabled. | [optional] 
**enable_amazon_devices** | **int** | Whether Amazon devices are enabled. | [optional] 
**enable_arm_devices** | **int** | Whether ARM devices are enabled. | [optional] 
**enable_devices** | **int** | Whether devices are enabled. | [optional] 
**webplayer** | [**domain_config_input_webplayer_t**](domain_config_input_webplayer.md) \* |  | [optional] 
**snapshot_sharing_permissions** | [**domain_config_input_snapshot_sharing_permissions_t**](domain_config_input_snapshot_sharing_permissions.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


