# login_result_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**token** | **char \*** | Signed JWT bearer session token, newly regenerated on every successful login. | 
**expiration** | **char \*** | Token expiration timestamp. | 
**user** | [**login_result_user_t**](login_result_user.md) \* |  | [optional] 
**domain** | [**login_result_domain_t**](login_result_domain.md) \* |  | [optional] 
**time** | **double** | Server time when the session was issued, in milliseconds. | [optional] 
**identifier** | **char \*** | Webplayer session identifier. Present only on a Webplayer token renewal. | [optional] 
**disabled** | [**login_result_disabled_t**](login_result_disabled.md) \* |  | [optional] 
**missing_totp** | **int** | Present when the domain requires TOTP but the user has not enrolled. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


