# layout_schema_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**free_cpus** | [**object_t**](.md) \* | Free CPU list. | [optional] 
**free_ram** | [**object_t**](.md) \* | Free RAM. | [optional] 
**free_ranges** | **double** | Free address ranges. | [optional] [default to 0]
**numa_nodes** | **double** | Number of NUMA nodes. | [optional] [default to 0]
**ram_cpu** | **char \*** | RAM per CPU. | [optional] [default to '0']
**node_map** | [**object_t**](.md) \* | Node map. | [optional] 
**free_cores** | [**object_t**](.md) \* | Free cores list. | [optional] 
**ram_core** | **double** | RAM per core in MB. | [optional] [default to 0]

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


