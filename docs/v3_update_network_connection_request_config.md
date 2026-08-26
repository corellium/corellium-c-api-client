# v3_update_network_connection_request_config_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**username** | **char \*** | Username for OpenVPN connection. | [optional] 
**password** | **char \*** | Password for OpenVPN connection. | [optional] 
**config** | **char \*** | OpenVPN connection configuration. | 
**physical_interface** | **char \*** | Physical network interface to create VLAN on | 
**vlan_id** | **double** | VLAN ID (1-4094) | 
**dhcp_mode** | **corellium_api_v3_update_network_connection_request_config_DHCPMODE_e** | DHCP server mode | 
**gateway** | **char \*** | Gateway IP address | [optional] 
**network** | **char \*** | Network address | [optional] 
**dns_servers** | **list_t \*** | List of DNS servers | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


