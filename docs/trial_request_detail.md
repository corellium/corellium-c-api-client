# trial_request_detail_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**identifier** | **char \*** | Trial request identifier. | 
**metadata** | [**object_t**](.md) \* | Additional metadata. | [optional] 
**organization** | [**trial_request_detail_organization_t**](trial_request_detail_organization.md) \* |  | [optional] 
**devices** | [**list_t**](object.md) \* | Devices requested (e.g. [{ ios: \&quot;iOS\&quot; }]). | [optional] 
**use_cases** | [**list_t**](object.md) \* | Use cases (e.g. [{ malware: \&quot;Malware Research\&quot; }]). | [optional] 
**email** | **char \*** | Contact email. | 
**name** | **char \*** | Contact name. | 
**billing_type** | **corellium_api_trial_request_detail_BILLINGTYPE_e** | Billing type. | 
**billing_backend** | **char \*** | Billing backend (e.g. stripe). | [optional] 
**billing_id** | **char \*** | External billing identifier. | [optional] 
**product_id** | **char \*** | Stripe product identifier. | [optional] 
**code** | **char \*** | Trial coupon code. | 
**enterprise** | **int** | Whether the request is for enterprise. | 
**granted** | **int** | Whether the trial has been granted. | 
**phone** | **char \*** | Contact phone number. | [optional] 
**country** | **char \*** | Country code. | [optional] 
**organization_type** | **corellium_api_trial_request_detail_ORGANIZATIONTYPE_e** | Organization type. | [optional] 
**industry** | **char \*** | Industry. | [optional] 
**role** | **char \*** | Job role. | [optional] 
**solution** | **char \*** | Solution of interest. | [optional] 
**domain** | **char \*** | Associated domain identifier. | [optional] 
**started_at** | **char \*** | ISO timestamp of trial start. | [optional] 
**granted_at** | **char \*** | ISO timestamp of when trial was granted. | [optional] 
**denied_at** | **char \*** | ISO timestamp of when trial was denied. | [optional] 
**plan_name** | **char \*** | Trial plan name. | [optional] 
**ends_at** | **char \*** | ISO timestamp of when trial ends. | [optional] 
**grant_method** | **corellium_api_trial_request_detail_GRANTMETHOD_e** | Method used to grant the trial. | [optional] 
**duration** | **double** | Trial duration in days (override). | [optional] 
**trial_units** | **double** | Trial usage units remaining. | [optional] 
**created_at** | **char \*** | ISO timestamp of creation. | 
**updated_at** | **char \*** | ISO timestamp of last update. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


