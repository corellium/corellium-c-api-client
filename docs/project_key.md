# project_key_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**kind** | **corellium_api_project_key_KIND_e** | Kind of authorized key: an SSH key for SSH-based devices or an ADB key for Android. | 
**label** | **char \*** | Descriptive label for the key. | [optional] 
**key** | **char \*** | The public key authorized to access devices in the project, in OpenSSH authorized_keys format. | 
**id** | **char \*** | Project key identifier. | 
**project** | **char \*** | Identifier of the project the key belongs to. | 
**fingerprint** | **char \*** | Public key fingerprint. | [optional] 
**created_at** | **char \*** | Time the key was created. | 
**updated_at** | **char \*** | Time the key was last updated. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


