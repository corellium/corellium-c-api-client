# create_web_player_session_body_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**project_id** | **char \*** | Project the device is in. | 
**instance_id** | **char \*** | The device (instance) the viewer will see and control. | 
**expires_in** | **double** | How long the session token stays valid, in seconds. At least 1800 (30 minutes). Renewing the token keeps the same length. | 
**features** | [**web_player_features_t**](web_player_features.md) \* |  | 
**client_id** | **char \*** | Optional client-supplied tracking string. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


