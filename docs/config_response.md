# config_response_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**on_site** | **int** | Denotes whether it&#39;s an on-site install. | 
**network_types** | **list_t \*** | Valid network types (e.g. \&quot;nat\&quot;, \&quot;bridged\&quot;, \&quot;routed\&quot;). | [optional] 
**network_type** | **corellium_api_config_response_NETWORKTYPE_e** | Current network type setting. | 
**show_domain_settings** | **int** | Denotes whether to show domain settings. | 
**version** | **char \*** | Denotes the version. | 
**invalid_build** | **int** | Denotes whether the build is invalid. | [optional] 
**sep_sim** | **int** | Denotes whether sepSim is enabled. | 
**installer_available** | **int** | Denotes whether installer is available. | 
**stripe_public_key** | **char \*** | Stripe public key. | [optional] 
**intercom_id** | **char \*** | Intercom app ID, also known as workspace ID. | [optional] 
**gtm_id** | **char \*** | Google Tag Manager ID. | [optional] 
**billing_backend** | **char \*** | Default backend billing API name for new subscriptions (e.g. \&quot;stripe\&quot;). | [optional] 
**maintenance** | [**config_response_maintenance_t**](config_response_maintenance.md) \* |  | [optional] 
**logging** | [**logging_t**](logging.md) \* |  | [optional] 
**cloud_admin** | **char \*** | URL for cloud admin login. | 
**files_admin** | **char \*** | URL for files admin login. | 
**cloud_domain** | **char \*** | Cloud domain name (usually corellium.com or staging.corellium.com). | [optional] 
**billing_domain** | **char \*** | Billing domain name. | [optional] 
**app_domain** | **char \*** | App domain name (usually app.corellium.com or app.staging.corellium.com). | [optional] 
**max_network_monitor_file_size** | **char \*** | Maximum network monitor file size. | 
**enable_firmware_image_upload** | **int** | Denotes whether users can upload firmware images. | 
**auth_providers** | [**list_t**](config_auth_provider.md) \* | Auth providers. | 
**welcome_message** | **char \*** | Domain welcome message, when enabled. | [optional] 
**snapshot_limit** | **double** | Maximum number of snapshots to allow. | 
**max_kernel_size** | **double** | The maximum size, in bytes, (default: 100 MiB) that an uploaded kernel should be. | 
**max_ramdisk_size** | **double** | The maximum size, in bytes, (default: 500 MiB) that an uploaded ramdisk should be. | 
**charm_sdk** | **int** | Denotes whether charmSDK is enabled. | [optional] 
**trial** | [**trial_t**](trial.md) \* |  | 
**sentry_url** | **char \*** | Sentry URL. | [optional] 
**domain_authentication_providers** | **int** | If enabled, adds the default providers in their current configuration. | [optional] 
**remote_gpu** | **int** | Whether remote GPU is enabled. | [optional] 
**default_ssid** | **char \*** | The configured default SSID from /etc/corellium/setup.json. | 
**aws_marketplace** | **int** | Whether this is an AWS Marketplace deployment. | [optional] 
**open_g_apps_binary** | **char \*** | OpenGApps binary location. | [optional] 
**air_gapped** | **int** | Whether the deployment is airgapped. | [optional] 
**coordinator_config** | [**config_response_coordinator_config_t**](config_response_coordinator_config.md) \* |  | 
**ai_tools_config** | [**config_response_ai_tools_config_t**](config_response_ai_tools_config.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


