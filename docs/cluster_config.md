# cluster_config_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**last_config_keys** | **list_t \*** |  | 
**local_ip** | **char \*** |  | 
**ip_block_netmask** | **char \*** |  | 
**instance_gateway** | **char \*** |  | 
**instance_dns_servers** | **list_t \*** |  | [optional] 
**coordinator** | **char \*** |  | [optional] 
**on_site** | **int** |  | [optional] 
**cloud_provider** | **char \*** |  | [optional] 
**network_types** | **list_t \*** |  | 
**network_type** | **corellium_api_cluster_config_NETWORKTYPE_e** |  | [optional] 
**show_domain_settings** | **int** |  | [optional] 
**version** | **char \*** |  | [optional] 
**ipsw_url** | **char \*** |  | [optional] 
**coreimg_url** | **char \*** |  | [optional] 
**fw_service_url** | **char \*** |  | [optional] 
**service_password** | **char \*** |  | [optional] 
**invalid_build** | **int** |  | [optional] 
**sep_sim** | **int** |  | [optional] 
**installer_available** | **int** |  | [optional] 
**stripe** | [**cluster_config_stripe_t**](cluster_config_stripe.md) \* |  | [optional] 
**intercom_id** | **char \*** |  | [optional] 
**aux_webhook** | **char \*** |  | [optional] 
**gtm_id** | **char \*** |  | [optional] 
**zapier_feedback_webhook** | **char \*** |  | [optional] 
**zapier_bugs_webhook** | **char \*** |  | [optional] 
**billing_backend** | **char \*** |  | [optional] 
**maintenance** | [**cluster_config_maintenance_t**](cluster_config_maintenance.md) \* |  | [optional] 
**cloud_domain** | **char \*** |  | [optional] 
**development** | **int** |  | [optional] 
**billing_domain** | **char \*** |  | [optional] 
**app_domain** | **char \*** |  | [optional] 
**enable_firmware_image_upload** | **int** |  | [optional] 
**net_mon_ca** | [**cluster_config_net_mon_ca_t**](cluster_config_net_mon_ca.md) \* |  | [optional] 
**snapshot_limit** | **double** |  | [optional] 
**max_kernel_size** | **double** |  | 
**max_ramdisk_size** | **double** |  | 
**charm_sdk** | **int** |  | [optional] 
**sentry_url** | **char \*** |  | [optional] 
**remote_gpu** | **int** |  | [optional] 
**rate_limit** | **int** |  | [optional] 
**cert_file_data** | **char \*** |  | [optional] 
**ca_cert_file_src** | **char \*** |  | 
**vstrm_on_compute_nodes** | **int** |  | [optional] 
**charm** | [**object_t**](.md) \* |  | [optional] 
**c3po_path_prefix** | **char \*** |  | [optional] 
**branding** | **char \*** |  | 
**open_g_apps_binary** | **char \*** |  | 
**airgapped** | **int** |  | 
**node_stale_timeout** | **double** |  | [optional] 
**report_interval** | **double** |  | [optional] 
**coordinator_config** | [**cluster_config_coordinator_config_t**](cluster_config_coordinator_config.md) \* |  | [optional] 
**setup_config** | [**cluster_config_setup_config_t**](cluster_config_setup_config.md) \* |  | [optional] 
**node_specific_config** | [**cluster_config_node_specific_config_t**](cluster_config_node_specific_config.md) \* |  | [optional] 
**package_config** | [**cluster_config_package_config_t**](cluster_config_package_config.md) \* |  | [optional] 
**monitor_interval** | **double** |  | [optional] 
**csp** | **int** |  | [optional] 
**cdk** | **int** |  | [optional] 
**charm_extension_paths** | **list_t \*** |  | [optional] 
**firmware_cache** | **char \*** |  | [optional] 
**vstrm** | **char \*** |  | [optional] 
**console** | **char \*** |  | [optional] 
**fetch_firmware_assets** | **int** |  | [optional] 
**cluster_firmware_assets** | **int** |  | [optional] 
**auth_providers** | [**list_t**](cluster_config_coordinator_config_auth_providers_inner.md) \* |  | [optional] 
**domain** | **char \*** |  | [optional] 
**service_domain** | **char \*** |  | [optional] 
**service_user** | **char \*** |  | [optional] 
**domain_image_upload_quota** | **double** |  | [optional] 
**ipsw_filters** | [**list_t**](cluster_config_ipsw_filters_inner.md) \* |  | [optional] 
**firmware_service_config** | [**cluster_config_firmware_service_config_t**](cluster_config_firmware_service_config.md) \* |  | [optional] 
**ai_tools_config** | [**cluster_config_ai_tools_config_t**](cluster_config_ai_tools_config.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


