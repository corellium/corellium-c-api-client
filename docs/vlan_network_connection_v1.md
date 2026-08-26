# vlan_network_connection_v1_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**identifier** | **char \*** | UUIDv4 | 
**provider** | **corellium_api_vlan_network_connection_v1_PROVIDER_e** | Type of network connection. | 
**name** | **char \*** | User specified name for this network connection. e.g., \&quot;My Network Connection\&quot; | 
**config** | [**vlan_config_v1_t**](vlan_config_v1.md) \* |  | [optional] 
**projects** | [**object_t**](.md) \* | An object where the keys are project IDs and the values are {@link ProjectNetworkState} objects representing the state of each project. | [optional] 
**created_at** | **char \*** | Created Date in ISO-8601 format e.g., \&quot;2022-05-06T02:39:23.000Z\&quot; | 
**updated_at** | **char \*** | Updated Date in ISO-8601 format e.g., \&quot;2022-05-06T02:39:23.000Z\&quot; | 
**created_by** | **char \*** | UUIDv4 of the user who created this record. | 
**updated_by** | **char \*** | UUIDv4 of the user who last updated this record. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


