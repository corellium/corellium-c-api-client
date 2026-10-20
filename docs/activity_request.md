# activity_request_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**resource** | **char \*** | Resource filter | [optional] 
**limit** | **double** | Number of entries to return, defaults to 10 | [optional] 
**order_by** | **char \*** | Sorting order (&#39;-createdAt&#39; or &#39;createdAt&#39;) | [optional] 
**page** | **double** | Paginated results. Must be a positive integer. If not provided, defaults to the first page. | [optional] 
**instance** | **char \*** | Instance identifier used to filter instance resources | [optional] 
**project** | **char \*** | Instance identifier used to filter instance resources | [optional] 
**actor** | **char \*** | Actor identifier used to filter actor resources | [optional] 
**search** | **char \*** | Last filter applied and is a fuzzy match on results | [optional] 
**to** | **char \*** | Date to filter to, keyed off of createdAt | [optional] 
**from** | **char \*** | Date to filter from, keyed off of createdAt | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


