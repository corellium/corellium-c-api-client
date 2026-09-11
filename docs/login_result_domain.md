# login_result_domain_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**name** | **char \*** | Domain name. | [optional] 
**label** | **char \*** | Domain description. | [optional] 
**terms_policy** | **char \*** | Terms-of-service policy for the domain. | [optional] 
**cores** | **double** | Licensed core quota. | 
**individual** | **int** | Whether this is an individual (aggregate member) domain. | 
**totp_required** | **int** | Present when the domain mandates TOTP. | [optional] 
**subscription** | [**object_t**](.md) \* | Billing summary for the domain, present when it has a billing record. Carries the billing wire fields renew_action, next_bill, billing_type and billing_backend. | [optional] 
**license_type** | **char \*** | License type identifier. | [optional] 
**android** | **int** | Whether Android devices are enabled. | [optional] 
**no_ios** | **int** | Whether iOS devices are disabled. | [optional] 
**files_only** | **int** | Whether the domain is in files-only mode. | [optional] 
**device_dhcp_server** | **int** | Whether the device DHCP server is enabled. | [optional] 
**enable_arm_devices** | **int** | Whether ARM devices are enabled. | [optional] 
**use_device_accounting** | **int** | Whether the domain is billed by device hours instead of core hours. | [optional] 
**single_project** | **int** | Whether the domain is limited to a single project. | [optional] 
**terms_updated** | **char \*** | When the domain terms were last updated; compared against the user agreement. | [optional] 
**trial** | [**login_result_domain_trial_t**](login_result_domain_trial.md) \* |  | [optional] 
**webplayer** | [**login_result_domain_webplayer_t**](login_result_domain_webplayer.md) \* |  | [optional] 
**snapshot_sharing_permissions** | [**login_result_domain_snapshot_sharing_permissions_t**](login_result_domain_snapshot_sharing_permissions.md) \* |  | [optional] 
**device_auto_shutdown** | [**login_result_domain_device_auto_shutdown_t**](login_result_domain_device_auto_shutdown.md) \* |  | [optional] 
**disabled** | [**login_result_domain_disabled_t**](login_result_domain_disabled.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


