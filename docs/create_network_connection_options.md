# create_network_connection_options_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**identifier** | **char \*** | UUIDv4 | 
**name** | **char \*** | User specified name for this network connection. e.g. My Network Connection | 
**provider** | **char \*** | One of the registered [network provider types](#get-/v1/network/providers) | 
**config** | [**object_t**](.md) \* | An object containing network connection configuration data. Will vary based on network provider type. See examples. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


