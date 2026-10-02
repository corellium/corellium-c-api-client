# patch_domain_body_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**totp_required** | **int** | If true, every user in the domain must set up two-factor sign-in with a time-based one-time password (TOTP) authenticator app before they can use the platform. | [optional] 
**trial_extension** | [**trial_extension_t**](trial_extension.md) \* |  | [optional] 
**device_auto_shutdown** | [**device_auto_shutdown_schema_t**](device_auto_shutdown_schema.md) \* |  | [optional] 
**allowed_devices_filters** | [**list_t**](allowed_devices_filter_schema.md) \* | Device/firmware allowlist filters. | [optional] 
**webplayer** | [**patch_domain_body_webplayer_t**](patch_domain_body_webplayer.md) \* |  | [optional] 
**snapshot_sharing_permissions** | [**snapshot_sharing_permissions_request_schema_t**](snapshot_sharing_permissions_request_schema.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


