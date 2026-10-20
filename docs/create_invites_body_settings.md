# create_invites_body_settings_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**teams** | **list_t \*** | Teams the new user is added to when they sign up, by team ID (from &#x60;GET /v3/teams&#x60;). IDs of teams not in your domain are dropped. | [optional] 
**projects** | **list_t \*** | Projects the new user gets access to when they sign up, as &#x60;[projectId, role]&#x60; pairs. IDs of projects not in your domain are dropped. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


