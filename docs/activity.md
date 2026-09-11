# activity_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**identifier** | **char \*** | Unique identifier for the activity entry. | 
**domain** | **char \*** | Unique identifier for the domain. | 
**actor** | **char \*** | Unique identifier for the user. | 
**event** | **char \*** | Resource associated with the activity. | 
**outcome** | **corellium_api_activity_OUTCOME_e** | The outcome of the activity. | 
**metadata** | [**object_t**](.md) \* | Related information that pertains to the activity. | [optional] 
**corellium_version** | **char \*** | The Corellium version this activity occurred in. | [optional] 
**project_id** | **char \*** | Unique identifier for project if applicable. | [optional] 
**instance_id** | **char \*** | Unique identifier for instance if applicable. | [optional] 
**created_at** | **char \*** | Timestamp of when the activity was created. | 
**updated_at** | **char \*** | Timestamp of when the activity was last updated. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


