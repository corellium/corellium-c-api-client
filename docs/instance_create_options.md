# instance_create_options_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**shared_snapshot** | **char \*** | identifier of the snapshot that was shared. | [optional] 
**shared_snapshot_password** | **char \*** | optional password if the shared snapshot requires a password. | [optional] 
**name** | **char \*** | the name of the device | [optional] 
**key** | **char \*** | Key used to encrypt the Instance | [optional] 
**flavor** | **char \*** | the flavor id | 
**project** | **char \*** | project UUID | 
**os** | **char \*** | OS Version | 
**osbuild** | **char \*** | OS Build | [optional] 
**patches** | **list_t \*** | list of patches to apply | [optional] 
**fwpackage** | **char \*** | URL or image id | [optional] 
**orig_fw_package_url** | **char \*** | URL that firmware package used to create this instance is available at | [optional] 
**encrypt** | **int** |  | [optional] 
**wifi_mac** | **char \*** |  | [optional] 
**wan_access** | **int** | manages internet access | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


