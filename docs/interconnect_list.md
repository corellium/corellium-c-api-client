# interconnect_list_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**results** | [**list_t**](interconnect.md) \* | Array of interconnects. | 
**count** | **double** | Number of results in this page. Can be less than &#x60;limit&#x60; on the last page. | 
**total** | **double** | Number of results across all pages, after any filters. | 
**limit** | **double** | The page size that was used (your &#x60;limit&#x60;, or the default 100). | 
**offset** | **double** | The offset that was used (your &#x60;offset&#x60;, or the default 0). | 
**has_more** | **int** | True if more results exist after this page. To read everything, keep requesting with &#x60;offset&#x60; increased by &#x60;limit&#x60; until this is false. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


