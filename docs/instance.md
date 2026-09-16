# instance_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**id** | **char \*** | Instance identifier. | 
**name** | **char \*** | Instance name. | 
**key** | **char \*** | Key used to encrypt the instance (hex). | 
**flavor** | **char \*** | The flavor identifier of this instance. | 
**flavor_name** | **char \*** | Human-readable flavor name. | [optional] 
**type** | **char \*** | Device type. | 
**project** | **char \*** | The project ID of the project this instance belongs to. | 
**domain_name** | **char \*** | Domain name associated with this instance&#39;s project. | [optional] 
**state** | **instance_state_t \*** |  | 
**state_changed** | **char \*** | Time the state of the instance last changed; null before the first transition. | [optional] 
**started_at** | **char \*** | Time the instance was started, NULL if currently SHUTOFF. | [optional] 
**user_task** | **char \*** | Currently executing user task. | [optional] 
**task_state** | **char \*** | Current task state if any (e.g. &#39;none&#39;, &#39;starting&#39;, &#39;stopping&#39;, &#39;pausing&#39;, &#39;unpausing&#39;, &#39;rebooting&#39;, &#39;building&#39;). | [optional] 
**error** | **char \*** | Current error state if any. | [optional] 
**restore_status** | [**instance_restore_status_t**](instance_restore_status.md) \* |  | [optional] 
**read_only** | [**instance_read_only_status_t**](instance_read_only_status.md) \* |  | [optional] 
**boot_options** | [**instance_boot_options_t**](instance_boot_options.md) \* |  | [optional] 
**service_ip** | **char \*** | Services IP address. | [optional] 
**wifi_ip** | **char \*** | LAN IP address. | [optional] 
**wifi_mac** | **char \*** | WiFi MAC address. | [optional] 
**secondary_ip** | **char \*** | Secondary interface LAN IP address (if supported). | [optional] 
**port_adb** | **char \*** | ADB port number. | [optional] 
**port_usb** | **char \*** | USB port number. | [optional] 
**port_gdb** | **char \*** | GDB port number. | [optional] 
**port_sep_gdb** | **char \*** | SEP GDB port number. | [optional] 
**port_cons** | **char \*** | Default console port number. | [optional] 
**port_sep_cons** | **char \*** | SEP console port number. | [optional] 
**port_sys_cons** | **char \*** | System console port number. | [optional] 
**port_usbmuxd** | **char \*** | USBMuxD port number. | [optional] 
**port_frida** | **char \*** | Frida instrumentation port number. | [optional] 
**port_sockcap** | **char \*** | Socket capture port number. | [optional] 
**port_model_gw** | **char \*** | Model gateway port number. | [optional] 
**consoles** | [**list_t**](instance_console.md) \* | Available console connections. | [optional] 
**interfaces** | [**list_t**](instance_interface_status.md) \* | Available configurable interfaces and their attachment status. | [optional] 
**services** | [**instance_services_t**](instance_services.md) \* |  | [optional] 
**panicked** | **int** | Whether the instance has panicked. | [optional] 
**created** | **char \*** | Time instance was created. | 
**model** | **char \*** | Model of virtual machine device. | [optional] 
**fw_package** | **char \*** | URL that the package used to create this instance is available at. | [optional] 
**os_version** | **char \*** | OS version. | [optional] 
**os_build** | **char \*** | OS build. | [optional] 
**agent** | [**instance_agent_state_t**](instance_agent_state.md) \* |  | [optional] 
**net_mon** | [**instance_netmon_state_t**](instance_netmon_state.md) \* |  | [optional] 
**net_dump** | [**instance_netdump_state_t**](instance_netdump_state.md) \* |  | [optional] 
**core_trace** | [**instance_trace_state_t**](instance_trace_state.md) \* |  | [optional] 
**hyper_trace** | [**instance_hyper_trace_state_t**](instance_hyper_trace_state.md) \* |  | [optional] 
**expose_port** | **char \*** | Currently exposed port, if any. | [optional] 
**fault** | **int** | Whether the instance is in a fault state. | [optional] 
**patches** | **list_t \*** | Patches applied to the instance. | [optional] 
**created_by** | [**created_by_t**](created_by.md) \* |  | [optional] 
**uefi_bootloader** | [**instance_uefi_bootloader_t**](instance_uefi_bootloader.md) \* |  | [optional] 
**orientation** | **double** | Device orientation. | [optional] 
**mast** | **int** | Whether the device has a mast. | [optional] 
**wan_access** | **int** | Whether WAN access is enabled. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


