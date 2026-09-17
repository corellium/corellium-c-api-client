# sys_info_schema_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**numa_nodes** | **double** | Number of NUMA nodes. | [optional] [default to 0]
**cpu** | [**object_t**](.md) \* | CPU availability. | [optional] 
**cpu_avail** | [**object_t**](.md) \* | Available CPU. | [optional] 
**slot** | **double** | Slot count. | [optional] [default to 0]
**slot_avail** | **double** | Available slot count. | [optional] [default to 0]
**ram** | **double** | Total RAM in MiB. | [optional] [default to 0]
**ram_avail** | **double** | Available RAM in MiB. | [optional] [default to 0]
**vpn** | **double** | VPN count. | [optional] [default to 0]
**vpn_avail** | **double** | Available VPN count. | [optional] [default to 0]
**gpu** | **double** | GPU count. | [optional] [default to 0]
**gpu_avail** | **double** | Available GPU count. | [optional] [default to 0]
**ram_cpu** | **char \*** | RAM per CPU. | [optional] [default to '0']
**el032** | **char \*** | EL0-32 capability. | [optional] [default to '0']
**el132** | **char \*** | EL1-32 capability. | [optional] [default to '0']
**mmu_tg16k** | **char \*** | MMU 16K translation granule support. | [optional] [default to '0']
**hw_pac** | **double** | Hardware pointer authentication support. | [optional] [default to 0]
**arm_trace** | **char \*** | ARM trace capability. | [optional] [default to '0']
**cores** | **double** | Total core count. | [optional] [default to 0]
**cores_avail** | **double** | Available core count. | [optional] [default to 0]
**ram_core** | **double** | RAM per core in MiB. | [optional] [default to 0]

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


