# domain_list_item_subscription_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**renew_action** | [**object_t**](.md) \* | Renewal action configuration (varies by billing backend). | [optional] 
**domain** | **char \*** | Domain identifier. | 
**billing_type** | **corellium_api_domain_list_item_subscription_BILLINGTYPE_e** | Billing type. | 
**billing_backend** | **char \*** | Billing backend (stripe, etc.). | 
**billing_id** | **char \*** | External billing identifier. | [optional] 
**next_bill** | **char \*** | ISO timestamp of next billing date. | [optional] 
**usage_based** | **int** | Whether billing is usage-based. | 
**last_usage_bill** | **char \*** | ISO timestamp of last usage bill. | [optional] 
**last_payment_amount** | **double** | Last payment amount, in cents. | [optional] 
**usage_bill_interval_days** | **double** | Interval in days between usage bills. | [optional] 
**usage_billing_threshold_dollars** | **double** | Dollar threshold that triggers a usage bill. | [optional] 
**past_due** | **int** | Whether the subscription is past due. | [optional] 
**payment_attempts** | **double** | Number of payment attempts. | [optional] 
**last_payment_attempt** | **char \*** | ISO timestamp of last payment attempt. | [optional] 
**created_at** | **char \*** | ISO timestamp of subscription creation. | 
**updated_at** | **char \*** | ISO timestamp of last subscription update. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


