# web_player_created_session_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**identifier** | **char \*** | Session identifier. | 
**token** | **char \*** | Session token to hand to the Web Player in your page. It grants access only to this one device and only to the enabled features, until &#x60;expiration&#x60;. | 
**expiration** | **char \*** | Session expiration timestamp. | 
**domain** | [**web_player_session_domain_t**](web_player_session_domain.md) \* |  | [optional] 
**time** | **double** | Server timestamp (ms) when the session was created. | [optional] 
**disabled** | **int** | Present and set when the domain is disabled (public flag). | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


