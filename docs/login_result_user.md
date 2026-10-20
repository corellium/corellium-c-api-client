# login_result_user_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**id** | **char \*** | User identifier. | 
**name** | **char \*** | Username. | [optional] 
**label** | **char \*** | Display name. | [optional] 
**email** | **char \*** | Email address. | [optional] 
**cluster_administrator** | **int** | Whether the user is a cluster administrator. | 
**agreed_to_terms** | **char \*** | When the user last agreed to the terms of service. | [optional] 
**federated_user_id** | **char \*** | Subject of the linked SSO credential, if any. | [optional] 
**intercom_hmac** | **char \*** | HMAC used for Intercom identity verification. | 
**misc** | [**object_t**](.md) \* | User metadata. API token bookkeeping only — the token itself is never returned. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


