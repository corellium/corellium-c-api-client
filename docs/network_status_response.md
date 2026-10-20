# network_status_response_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | **char \*** | Network Provider. Omitted when no egress network is configured | [optional] 
**name** | **char \*** | User defined name. Omitted when no egress network is configured | [optional] 
**state** | **corellium_api_network_status_response_STATE_e** | Current state of the network connection | 
**params** | [**object_t**](.md) \* | Additional state information. Omitted when no egress network is configured | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


