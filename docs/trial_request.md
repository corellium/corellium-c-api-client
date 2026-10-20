# trial_request_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**email** | **char \*** | Requester email. | 
**name** | **char \*** | Requester name. | [optional] 
**billing_type** | **char \*** | Billing type. | [optional] 
**billing_id** | **char \*** | Billing backend identifier. | [optional] 
**code** | **char \*** | Sign-up code. | [optional] 
**enterprise** | **int** | Whether an enterprise domain is requested. | 
**granted** | **int** | Whether the request was granted. | [optional] 
**phone** | **char \*** | Phone number. | [optional] 
**country** | **char \*** | Country. | [optional] 
**organization** | **char \*** | Organization. | [optional] 
**organization_type** | **char \*** | Organization type. | [optional] 
**metadata** | [**object_t**](.md) \* | Sign-up metadata. | [optional] 
**created_at** | **double** | Creation timestamp (ms). | 
**updated_at** | **double** | Update timestamp (ms). | 
**display_status** | **char \*** | Computed display status of the trial request. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


