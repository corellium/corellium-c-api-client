# patch_user_body_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**name** | **char \*** | Username. | [optional] 
**label** | **char \*** | User label (e.g. \&quot;Domain Administrator\&quot;). | [optional] 
**email** | **char \*** | User email. | [optional] 
**cluster_administrator** | **int** | Whether the user is a cluster administrator (cluster admins only). | [optional] 
**password** | **char \*** | Password (optional when using SSO). | [optional] 
**misc** | [**object_t**](.md) \* | Opaque metadata. | [optional] 
**administrator** | **int** | Whether the user is a domain administrator (domain admins only). | [optional] 
**agreed_to_terms** | **char \*** | Timestamp the terms were agreed to. | [optional] 
**totp_enabled** | **int** | Whether two-factor authentication is enabled. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


