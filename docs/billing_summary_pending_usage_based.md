# billing_summary_pending_usage_based_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**last_bill_date** | **double** | Last bill unix timestamp (ms). | 
**next_bill_date** | **double** | Next bill unix timestamp (ms). | 
**billing_threshold** | **double** | Dollar threshold that triggers a usage bill. | 
**total** | **char \*** | Pending total in dollars, as a fixed two-decimal string. | 
**line_items** | [**list_t**](billing_line_item.md) \* | Pending usage line items. May be empty. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


