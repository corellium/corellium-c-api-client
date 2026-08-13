# domain_list_item_subscription_history_inner_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**plan_name** | **char \*** | Name of the subscription plan. | 
**plan_start** | **char \*** | Plan start date. | 
**plan_end** | **char \*** | Plan end date (null if still active). | [optional] 
**status** | **char \*** | Display status (e.g. Active, Ended, Past Due). | 
**administrator** | [**domain_list_item_subscription_history_inner_administrator_t**](domain_list_item_subscription_history_inner_administrator.md) \* |  | 
**stripe_link** | **char \*** | Link to Stripe subscription. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


