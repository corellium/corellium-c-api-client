# cluster_config_coordinator_config_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**bind_host** | **char \*** |  | 
**bind_port** | **double** |  | 
**db_database** | **char \*** |  | 
**db_host** | **char \*** |  | 
**db_port** | **double** |  | 
**db_password** | **char \*** |  | 
**db_user** | **char \*** |  | 
**db_logging_enabled** | **int** |  | 
**config_db_host** | **char \*** |  | [optional] 
**config_db_port** | **double** |  | [optional] 
**config_db_user** | **char \*** |  | [optional] 
**config_db_password** | **char \*** |  | [optional] 
**config_db_name** | **char \*** |  | [optional] 
**ip_block** | **char \*** |  | 
**local_ip** | **char \*** |  | 
**ip_block_netmask** | **char \*** |  | 
**instance_dns_servers** | **list_t \*** |  | [optional] 
**on_site** | **int** |  | 
**private_headers** | **list_t \*** |  | 
**trial** | [**cluster_config_coordinator_config_trial_t**](cluster_config_coordinator_config_trial.md) \* |  | [optional] 
**trial_survey_id** | **char \*** |  | 
**auth_providers** | [**list_t**](cluster_config_coordinator_config_auth_providers_inner.md) \* |  | [optional] 
**per_project_storage_quota** | **double** |  | [optional] 
**image_data_path** | **char \*** |  | [optional] 
**ensure_domain** | [**cluster_config_coordinator_config_ensure_domain_t**](cluster_config_coordinator_config_ensure_domain.md) \* |  | [optional] 
**hubspot** | [**cluster_config_coordinator_config_hubspot_t**](cluster_config_coordinator_config_hubspot.md) \* |  | [optional] 
**nexus_url** | **char \*** |  | [optional] 
**billing_trade_credit_days** | **double** |  | [optional] 
**jwt_token_expiration** | **double** |  | [optional] 
**hypertune** | [**cluster_config_coordinator_config_hypertune_t**](cluster_config_coordinator_config_hypertune.md) \* |  | [optional] 
**aws_marketplace** | [**cluster_config_coordinator_config_aws_marketplace_t**](cluster_config_coordinator_config_aws_marketplace.md) \* |  | [optional] 
**pipedrive** | [**cluster_config_coordinator_config_pipedrive_t**](cluster_config_coordinator_config_pipedrive.md) \* |  | [optional] 
**webplayer** | [**cluster_config_coordinator_config_webplayer_t**](cluster_config_coordinator_config_webplayer.md) \* |  | [optional] 
**postmark_server_token** | **char \*** |  | [optional] 
**postmark_email_from** | **char \*** |  | [optional] 
**postmark_email_template** | **char \*** |  | [optional] 
**s3** | [**object_t**](.md) \* |  | [optional] 
**ai_enabled** | **int** |  | [optional] 
**ofac_api_key** | **char \*** |  | [optional] 
**usb_media_queue_dir** | **char \*** |  | [optional] 
**usb_media_access_enabled** | **int** |  | [optional] 
**intercom_id_verify_secret** | **char \*** |  | [optional] 
**fvp_secret** | **char \*** |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


