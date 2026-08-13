# network_status_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | **char \*** | Network provider type (e.g. \&quot;openvpn\&quot;). | [optional] 
**name** | **char \*** | User-defined network connection name. | [optional] 
**state** | **corellium_api_network_status_STATE_e** | Current egress network connection state. | 
**details** | [**object_t**](.md) \* | Additional state information, such as the last error. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


