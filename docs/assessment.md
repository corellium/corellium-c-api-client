# assessment_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**id** | **char \*** | Identifier of the assessment. | 
**status** | **assessment_status_t \*** |  | 
**instance_id** | **char \*** | Identifier of the instance under assessment. | 
**bundle** | [**assessment_bundle_t**](assessment_bundle.md) \* |  | 
**wordlist** | [**assessment_wordlist_t**](assessment_wordlist.md) \* |  | [optional] 
**frida_script** | [**assessment_frida_script_t**](assessment_frida_script.md) \* |  | [optional] 
**report_id** | **char \*** | Identifier of the generated report, or null if not yet available. | [optional] 
**results** | [**assessment_results_t**](assessment_results.md) \* |  | 
**metadata** | [**assessment_metadata_t**](assessment_metadata.md) \* |  | 
**severity_counts** | [**assessment_severity_counts_t**](assessment_severity_counts.md) \* |  | 
**error** | **char \*** | Failure message if the assessment failed, otherwise null. | [optional] 
**created_by** | **char \*** | Identifier of the user that created the assessment, or null. | [optional] 
**created_at** | **char \*** | Creation timestamp. | [optional] 
**updated_at** | **char \*** | Last-update timestamp. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


