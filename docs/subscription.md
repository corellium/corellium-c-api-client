# subscription_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**trial** | [**subscription_trial_t**](subscription_trial.md) \* |  | [optional] 
**status** | **char \*** | Subscription status. Null on domains without billing. | [optional] 
**billing_type** | **char \*** | Billing type. | 
**plan_name** | **char \*** | Plan name. | [optional] 
**next_bill** | **char \*** | Next billing date. Omitted on domains without billing. | [optional] 
**use_device_accounting** | **int** | Whether device accounting is used. | [optional] 
**is_enterprise** | **int** | Whether the plan is enterprise. | [optional] 
**is_usage_based** | **int** | Whether the plan is usage based. | [optional] 
**cancel_policy** | **char \*** | Cancellation policy. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


