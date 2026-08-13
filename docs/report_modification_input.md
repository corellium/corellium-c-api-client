# report_modification_input_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**check_id** | **char \*** | Identifier of the check to modify. | 
**property** | [**object_t**](.md) \* | Property of the check to modify: \&quot;outcome\&quot;, \&quot;severity\&quot;, or \&quot;evidence_&lt;index&gt;\&quot;. | 
**suppressed** | **int** | For an \&quot;evidence_&lt;index&gt;\&quot; property, whether the evidence entry is suppressed. Required for evidence modifications. | [optional] 
**value** | **char \*** | New value for the property. Required for \&quot;outcome\&quot; and \&quot;severity\&quot;; must be omitted for \&quot;evidence_&lt;index&gt;\&quot;. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


