# instance_boot_options_fvp_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**model_binary** | **char \*** | FVP model binary path. Populated by the server from the flavor; clients should not set this. | [optional] 
**parameters** | [**object_t**](.md) \* | Key/value map of FVP model parameters. | [optional] 
**data** | **list_t \*** | Raw data to load at specified addresses (format: \&quot;file@address\&quot;). | [optional] 
**breaks** | **list_t \*** | Breakpoint addresses to set. | [optional] 
**dumps** | **list_t \*** | Memory regions to dump (format: \&quot;file@address,size\&quot;). | [optional] 
**cadi_log** | **char \*** | Log all CADI calls into an XML log file. | [optional] 
**cadi_server** | **char \*** | Start CADI server. | [optional] 
**iris_server** | **char \*** | Start Iris server. | [optional] 
**iris_log** | **char \*** | Iris log level. | [optional] 
**iris_allow_remote** | **char \*** | Allow remote connections to the Iris server. | [optional] 
**iris_port_range** | **char \*** | Port range to scan when starting the Iris server (format: \&quot;min:max\&quot;). | [optional] 
**iris_port** | **char \*** | Specific port for the Iris server. | [optional] 
**run** | **char \*** | Run the simulation immediately when a debug server is started. | [optional] 
**stat** | **char \*** | Print run statistics on simulation exit. | [optional] 
**quiet** | **char \*** | Suppress informational output. | [optional] 
**start** | **char \*** | Set initial PC to application start address. | [optional] 
**plugin** | **char \*** | Load plugin. | [optional] 
**fast_ram** | **char \*** | Enable FastRAM and load its configuration from file. | [optional] 
**save** | **char \*** | Save checkpoint to directory on simulation exit. | [optional] 
**restore** | **char \*** | Restore checkpoint from directory on simulation startup. | [optional] 
**cpi_file** | **char \*** | File to set Cycle Per Instruction class. | [optional] 
**cycle_limit** | **char \*** | Number of cycles to run. | [optional] 
**cpu_limit** | **char \*** | Number of host active CPU seconds to run. | [optional] 
**time_limit** | **char \*** | Number of wall-clock seconds to run. | [optional] 
**sim_limit** | **char \*** | Number of seconds to simulate. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


