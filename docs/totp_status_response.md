# totp_status_response_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**token** | **char \*** | Signed JWT bearer token reflecting the updated TOTP state. | 
**time** | **double** | Server time (epoch ms) the result was issued. | 
**user** | [**totp_status_response_user_t**](totp_status_response_user.md) \* |  | 
**domain** | [**totp_status_response_domain_t**](totp_status_response_domain.md) \* |  | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


