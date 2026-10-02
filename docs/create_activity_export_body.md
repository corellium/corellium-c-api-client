# create_activity_export_body_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**resource** | [**object_t**](.md) \* | Resource equality or LHS prefix filter. Examples: &#x60;resource&#x3D;value&#x60;, &#x60;resource[startsWith]&#x3D;value&#x60;, and &#x60;resource[!startsWith]&#x3D;value&#x60;. | [optional] 
**offset** | **double** | Number of results to skip. | [optional] [default to 0]
**order_by** | **char \*** | Field to sort by, for example &#x60;createdAt&#x60;. Prefix with &#x60;-&#x60; for newest or largest first. Defaults to &#x60;-createdAt&#x60; (newest first). | [optional] [default to '-createdAt']
**instance_id** | **char \*** | Only activity about this device. | [optional] 
**project_id** | **char \*** | Only activity in this project. | [optional] 
**actor** | **char \*** | Only activity performed by this user (user ID). | [optional] 
**search** | **char \*** | Free-text search. Applied last, as a loose match on the results that pass the other filters. | [optional] 
**to** | **char \*** | Only activity at or before this time (ISO 8601). | [optional] 
**from** | **char \*** | Only activity at or after this time (ISO 8601). | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


