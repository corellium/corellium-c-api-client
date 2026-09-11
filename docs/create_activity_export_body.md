# create_activity_export_body_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**resource** | [**object_t**](.md) \* | Resource equality or LHS prefix filter. Examples: &#x60;resource&#x3D;value&#x60;, &#x60;resource[startsWith]&#x3D;value&#x60;, and &#x60;resource[!startsWith]&#x3D;value&#x60;. | [optional] 
**offset** | **double** | Number of results to skip. | [optional] [default to 0]
**order_by** | **char \*** | Activity model attribute to sort by. | [optional] [default to '-createdAt']
**instance_id** | **char \*** | Instance identifier used to filter instance resources. | [optional] 
**project_id** | **char \*** | Project identifier used to filter instance resources. | [optional] 
**actor** | **char \*** | Actor identifier used to filter actor resources. | [optional] 
**search** | **char \*** | Last filter applied and is a fuzzy match on results. | [optional] 
**to** | **char \*** | Date to filter to, keyed off of createdAt. | [optional] 
**from** | **char \*** | Date to filter from, keyed off of createdAt. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


