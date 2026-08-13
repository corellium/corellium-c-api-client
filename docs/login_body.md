# login_body_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**username** | **char \*** | Account username (with password). | [optional] 
**password** | **char \*** | Account password (with username). | [optional] 
**totp_token** | **char \*** | TOTP token when two-factor is required. | [optional] 
**api_token** | **char \*** | API token, as an alternative to username/password. | [optional] 
**token** | **char \*** | Existing bearer token to exchange for a fresh one. | [optional] 
**revoke_old** | **int** | Revoke previously issued tokens on success. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


