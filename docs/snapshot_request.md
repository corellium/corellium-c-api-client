# snapshot_request_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**limit** | **double** | Number of entries to return, defaults to 100 | [optional] 
**offset** | **double** | Number of rows to skip, defaults to 0 | [optional] 
**springboard** | **int** | Denotes whether snapshot was a springboard snapshot | [optional] 
**live** | **int** | Denotes whether snapshot was a live snapshot | [optional] 
**fresh** | **int** | Denotes whether snapshot was created immediately after the device was restored | [optional] 
**device_name** | **char \*** | Name of device | [optional] 
**task** | **char \*** | Task being executed on snapshot | [optional] 
**to** | **char \*** | Date to filter to, keyed off of createdAt | [optional] 
**from** | **char \*** | Date to filter from, keyed off of createdAt | [optional] 
**order_by** | **char \*** | Sorting order (&#39;-createdAt&#39; or &#39;createdAt&#39;), defaults to -createdAt | [optional] 
**search** | **char \*** | Last filter applied and searches on snapshot / associated instance name and snapshot / instance id | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


