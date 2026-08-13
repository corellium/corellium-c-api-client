# web_player_created_session_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**identifier** | **char \*** | Session identifier. | 
**token** | **char \*** | Session JWT. | 
**expiration** | **char \*** | Session expiration timestamp. | 
**domain** | [**web_player_session_domain_t**](web_player_session_domain.md) \* |  | [optional] 
**time** | **double** | Server timestamp (ms) when the session was created. | [optional] 
**disabled** | **int** | Present and set when the domain is disabled (public flag). | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


