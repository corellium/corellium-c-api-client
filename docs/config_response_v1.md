# config_response_v1_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**on_site** | **int** | Denotes whether it&#39;s an on-site install | [optional] 
**network_types** | **list_t \*** | Valid network types (e.g. \&quot;nat\&quot;, \&quot;bridged\&quot;, \&quot;routed\&quot;) | [optional] 
**network_type** | **char \*** | Current network type setting | [optional] 
**show_domain_settings** | **int** | Denotes whether to show domain settings | [optional] 
**version** | **char \*** | Denotes the version | [optional] 
**invalid_build** | **int** | Denotes whether the build is invalid | [optional] 
**sep_sim** | **int** | Denotes whether sepSim is enabled | [optional] 
**installer_available** | **int** | Denotes whether installer is available | [optional] 
**invoiced_publishable_key** | **char \*** | API publishable key to use for Invoiced | [optional] 
**stripe_public_key** | **char \*** | Stripe public key | [optional] 
**intercom_id** | **char \*** | Intercom app ID, also known as workspace ID | [optional] 
**gtm_id** | **char \*** | Google Tag Manager | [optional] 
**billing_backend** | **char \*** | Default backend billing api name for new subscriptions (e.g. \&quot;stripe\&quot;) | [optional] 
**maintenance** | [**object_t**](.md) \* | Denotes whether the server is undergoing maintenance (legacy v1 shape; v3 returns Maintenance|null) | [optional] 
**logging** | [**logging_v1_t**](logging_v1.md) \* |  | [optional] 
**cloud_admin** | **char \*** | URL for cloud admin login | [optional] 
**files_admin** | **char \*** | URL for files admin login | [optional] 
**cloud_domain** | **char \*** | Cloud domain name (usually corellium.com or staging.corellium.com) | [optional] 
**billing_domain** | **char \*** | Billing domain name | [optional] 
**app_domain** | **char \*** | App domain name (usually app.corellium.com or app.staging.corellium.com) | [optional] 
**max_network_monitor_file_size** | **char \*** | Maximum network monitor file size | [optional] 
**enable_firmware_image_upload** | **int** | Denotes whether users can upload firmware images | [optional] 
**auth_providers** | [**list_t**](auth_provider_v1.md) \* | Auth providers | [optional] 
**snapshot_limit** | **double** | Maximum number of snapshots to allow | [optional] 
**max_kernel_size** | **double** | The maximum size, in bytes, (default: 100 MB) that an uploaded kernel should be | [optional] 
**max_ramdisk_size** | **double** | The maximum size, in bytes, (default: 500 MB) that an uploaded ramdisk should be | [optional] 
**charm_sdk** | **int** | Denotes whether charmSDK is enabled | [optional] 
**trial** | [**trial_v1_t**](trial_v1.md) \* |  | [optional] 
**sentry_url** | **char \*** | Sentry URL | [optional] 
**domain_authentication_providers** | **int** | If enabled, adds the default providers in their current configuration | [optional] 
**default_ssid** | **char \*** | The configured Default SSID from /etc/corellium/setup.json | [optional] 
**coordinator_config** | [**coordinator_config_v1_t**](coordinator_config_v1.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


