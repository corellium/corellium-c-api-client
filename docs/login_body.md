# login_body_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**username** | **char \*** | Account username. Send together with &#x60;password&#x60;. | [optional] 
**password** | **char \*** | Account password. Send together with &#x60;username&#x60;. | [optional] 
**totp_token** | **char \*** | One-time TOTP code. Required only when the account has two-factor authentication enabled, sent alongside &#x60;username&#x60;/&#x60;password&#x60;. | [optional] 
**api_token** | **char \*** | Persistent API key, used as an alternative to username/password for programmatic access. Created by the user (in the web UI or via &#x60;POST /v3/auth/apitoken&#x60;) rather than issued by login, and sent back verbatim as an opaque string. Also accepted directly in the &#x60;Authorization: Bearer&#x60; header, and is the value the CLI stores as &#x60;--token&#x60;. Never returned by this endpoint, and distinct from the session &#x60;token&#x60;. | [optional] 
**token** | **char \*** | An existing session token to renew. This is the signed JWT bearer token previously returned by login. Login always issues a newly-regenerated session token in the response; the supplied token is neither echoed back nor invalidated. Distinct from &#x60;apiToken&#x60;. | [optional] 
**revoke_old** | **int** | Revoke previously issued tokens on success. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


