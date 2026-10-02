# interconnect_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**name** | **char \*** | A name to recognise the interconnect by. | 
**type** | **corellium_api_interconnect_TYPE_e** | How the interconnect behaves: &#x60;hub&#x60; passes every signal to every connected interface; &#x60;switch&#x60; routes traffic between endpoints. | 
**project_id** | **char \*** | Project the interconnect belongs to. Every device listed in &#x60;interfaces&#x60; must be in this project, otherwise the request fails with 400. Cannot be changed later. | 
**interfaces** | [**list_t**](interfaces_schema_inner.md) \* |  | 
**id** | **char \*** | The interconnect identifier. | 
**protocol** | **char \*** | The protocol used by the interconnect. | 
**status** | **corellium_api_interconnect_STATUS_e** | The current status of the interconnect. | 
**instance_count** | **double** | Number of unique instances connected to this interconnect. | 
**created_at** | **char \*** | Creation timestamp. | 
**updated_at** | **char \*** | Last update timestamp. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


