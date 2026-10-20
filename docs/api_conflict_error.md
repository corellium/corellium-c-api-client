# api_conflict_error_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**error** | **char \*** | Human-readable explanation of the conflict. | 
**error_id** | **corellium_api_api_conflict_error_ERRORID_e** | Always &#x60;Conflict&#x60;: the request clashes with the current state, for example the resource already exists or is in a state that does not allow this action. Check the current state before retrying. | 
**object** | [**object_t**](.md) \* | The existing object the request conflicted with, when there is one. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


