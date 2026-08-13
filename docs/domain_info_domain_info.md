# domain_info_domain_info_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**identifier** | **char \*** | Domain identifier. | 
**user_id** | **char \*** | Owner user identifier. | 
**domain_usage** | [**list_t**](domain_list_item_domain_usage_inner.md) \* | Monthly usage entries. | 
**user_count** | **double** | Number of users in the domain. | 
**users_info** | [**list_t**](domain_list_item_users_info_inner.md) \* | Users in the domain. | 
**domain** | **char \*** | Fully qualified domain name. | 
**domain_name** | **char \*** | Domain name. | 
**disabled** | [**domain_list_item_disabled_t**](domain_list_item_disabled.md) \* |  | [optional] 
**config** | [**domain_config_t**](domain_config.md) \* |  | 
**quotas** | [**domain_list_item_quotas_t**](domain_list_item_quotas.md) \* |  | 
**usage** | [**domain_list_item_usage_t**](domain_list_item_usage.md) \* |  | 
**created_at** | **double** | Domain creation timestamp (epoch ms). | 
**subscription** | [**domain_list_item_subscription_t**](domain_list_item_subscription.md) \* |  | [optional] 
**subscription_history** | [**list_t**](domain_list_item_subscription_history_inner.md) \* | Subscription history. | [optional] 
**plan_name** | **char \*** | Current plan name. | [optional] 
**projects** | [**list_t**](domain_list_item_projects_inner.md) \* | Projects in the domain. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


