# open_vpn_network_connection_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**name** | **char \*** | User friendly name for network connection. | 
**provider** | **corellium_api_open_vpn_network_connection_PROVIDER_e** | Type of network connection. | 
**config** | [**open_vpn_config_t**](open_vpn_config.md) \* |  | [optional] 
**identifier** | **char \*** | Unique identifier for the network connection. | 
**projects** | [**object_t**](.md) \* | Network states mapped by project IDs. | [optional] 
**created_at** | **char \*** | Timestamp when the network connection was created. | 
**updated_at** | **char \*** | Timestamp when the network connection was last updated. | 
**created_by** | **char \*** | User ID of the creator. | 
**updated_by** | **char \*** | User ID of the last updater. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


