# domain_auth_provider_config_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**identity_provider_config** | [**saml_identity_provider_config_t**](saml_identity_provider_config.md) \* |  | 
**service_provider_config** | [**saml_service_provider_config_t**](saml_service_provider_config.md) \* |  | [optional] 
**user_attribute_mapping** | [**ldap_user_attribute_mapping_t**](ldap_user_attribute_mapping.md) \* |  | [optional] 
**group_mapping** | [**list_t**](saml_group_mapping.md) \* |  | [optional] 
**discovery_url** | **char \*** | Service Discovery URL. | 
**client_id** | **char \*** | Service Client ID. | 
**client_secret** | **char \*** | Service Client Secret. | 
**invited_only** | **int** | Only accept individuals with invitations. | [optional] 
**server_connection_details** | [**ldap_server_connection_details_t**](ldap_server_connection_details.md) \* |  | 
**authentication_credentials** | [**ldap_authentication_credentials_t**](ldap_authentication_credentials.md) \* |  | 
**user_search_configuration** | [**ldap_user_search_configuration_t**](ldap_user_search_configuration.md) \* |  | 
**group_search_configuration** | [**list_t**](ldap_group_search_configuration.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


