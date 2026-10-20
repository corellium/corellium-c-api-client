# create_project_key_body_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**kind** | **corellium_api_create_project_key_body_KIND_e** | Kind of authorized key: an SSH key for SSH-based devices or an ADB key for Android. | 
**label** | **char \*** | Descriptive label for the key. | [optional] 
**key** | **char \*** | The public key authorized to access devices in the project, in OpenSSH authorized_keys format. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


