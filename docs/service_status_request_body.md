# service_status_request_body_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**healthy** | **int** | Whether the service is healthy. | 
**service_name** | **char \*** | Service name. | 
**address** | **char \*** | Service address (IP:Port). | 
**hostname** | **char \*** | Service hostname. | 
**node_id** | **char \*** | Node identifier. | 
**sys_info** | [**sys_info_schema_t**](sys_info_schema.md) \* |  | [optional] 
**layout** | [**layout_schema_t**](layout_schema.md) \* |  | [optional] 
**vms** | [**list_t**](service_status_request_body_vms_inner.md) \* | VM list reported by this node. | [optional] 
**pool_usage** | [**pool_usage_schema_t**](pool_usage_schema.md) \* |  | [optional] 
**az** | **char \*** | Availability zone. | [optional] 
**network** | [**network_schema_t**](network_schema.md) \* |  | [optional] 
**ec2_instance_type** | **char \*** | EC2 instance type, if applicable. | [optional] [default to '']
**op** | **char \*** | Current operation. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


