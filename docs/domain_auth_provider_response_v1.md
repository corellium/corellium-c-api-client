# domain_auth_provider_response_v1_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**identifier** | **char \*** | Provider ID | 
**id** | **char \*** | Provider ID for backward compatibility with frontend | [optional] 
**provider_type** | **char \*** | Provider Type | 
**provider** | **char \*** | Provider Type for backward compatibility with frontend | [optional] 
**label** | **char \*** | Login Button Text | 
**name** | **char \*** | Title Text for the Frontend&#39;s Provider Configuration Form | [optional] 
**authorization_url** | **char \*** | Coordinator endpoint for Authorizing with this provider | [optional] 
**_default** | **int** | True: Configured in coordinator.json, False: Custom Domain Provider | 
**enabled** | **int** | Enabled/Disabled | 
**config** | [**open_id_config_v1_t**](open_id_config_v1.md) \* |  | [optional] 
**created_by** | **char \*** | Optional User ID of creator | [optional] 
**created_at** | **char \*** | Created Date in ISO-8601 format e.g. 2022-05-06T02:39:23.000Z | 
**updated_at** | **char \*** | Updated Date in ISO-8601 format e.g. 2022-05-06T02:39:23.000Z | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


