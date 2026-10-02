# create_interconnect_v3_body_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**name** | **char \*** | A name to recognise the interconnect by. | 
**type** | **corellium_api_create_interconnect_v3_body_TYPE_e** | How the interconnect behaves: &#x60;hub&#x60; passes every signal to every connected interface; &#x60;switch&#x60; routes traffic between endpoints. | 
**interfaces** | [**list_t**](interfaces_schema_inner.md) \* |  | 
**project_id** | **char \*** | Project the interconnect belongs to. Every device listed in &#x60;interfaces&#x60; must be in this project, otherwise the request fails with 400. Cannot be changed later. | 
**protocol** | **interconnect_protocol_t \*** |  | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


