# domain_list_item_projects_inner_instances_inner_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**identifier** | **char \*** | Instance identifier. | 
**name** | **char \*** | Instance name. | [optional] 
**status** | **char \*** | Instance status (ACTIVE, SHUTOFF, etc.). | 
**error** | **char \*** | Error message if any. | [optional] 
**task_state** | **char \*** | Current task state. | 
**user_task** | **char \*** | User-initiated task. | [optional] 
**os_version** | **char \*** | OS version. | 
**os_build** | **char \*** | OS build identifier. | 
**flavor_id** | **char \*** | Device flavor identifier. | 
**flavor** | **char \*** | Friendly device flavor name. | [optional] 
**compute_node** | **char \*** | Compute node address. | [optional] 
**service_ip** | **char \*** | Service IP address. | [optional] 
**wifi_ip** | **char \*** | WiFi IP address. | [optional] 
**images** | [**list_t**](domain_list_item_projects_inner_instances_inner_images_inner.md) \* | List of images. | 
**usage** | [**domain_list_item_projects_inner_instances_inner_usage_t**](domain_list_item_projects_inner_instances_inner_usage.md) \* |  | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


