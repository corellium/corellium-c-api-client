# patch_project_body_settings_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**version** | **double** | Settings schema version. | [optional] 
**internet_access** | **int** | Whether devices in the project can reach the internet. When false, devices can talk only to each other and to the project VPN. | [optional] 
**dhcp** | **int** | Whether DHCP is enabled for the project network. | [optional] 
**connection** | **char \*** | ID of a network connection that routes the project&#39;s outbound traffic through a VPN, or null to use the normal network. Cannot be changed while any device in the project is running. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


