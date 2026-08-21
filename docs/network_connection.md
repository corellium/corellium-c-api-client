# network_connection_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**identifier** | **char \*** | UUIDv4 | 
**provider** | **char \*** | One of the registered [network provider types](#get-/v1/network/providers) | 
**name** | **char \*** | User specified name for this network connection. e.g., \&quot;My Network Connection\&quot; | 
**config** | [**object_t**](.md) \* | An object containing network connection configuration data. Will vary based on network provider type. | 
**projects** | [**object_t**](.md) \* | An object where the keys are project IDs and the values are {@link ProjectNetworkState} objects representing the state of each project. | [optional] 
**created_at** | **char \*** | Created Date in ISO-8601 format e.g., \&quot;2022-05-06T02:39:23.000Z\&quot; | 
**updated_at** | **char \*** | Updated Date in ISO-8601 format e.g., \&quot;2022-05-06T02:39:23.000Z\&quot; | 
**created_by** | **char \*** | UUIDv4 of the user who created this record. | 
**updated_by** | **char \*** | UUIDv4 of the user who last updated this record. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


