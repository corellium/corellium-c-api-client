#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cluster_config_coordinator_config.h"



static cluster_config_coordinator_config_t *cluster_config_coordinator_config_create_internal(
    char *bind_host,
    double bind_port,
    char *db_database,
    char *db_host,
    double db_port,
    char *db_password,
    char *db_user,
    int db_logging_enabled,
    char *config_db_host,
    double config_db_port,
    char *config_db_user,
    char *config_db_password,
    char *config_db_name,
    char *ip_block,
    char *local_ip,
    char *ip_block_netmask,
    list_t *instance_dns_servers,
    int on_site,
    list_t *private_headers,
    cluster_config_coordinator_config_trial_t *trial,
    char *trial_survey_id,
    list_t *auth_providers,
    double per_project_storage_quota,
    char *image_data_path,
    cluster_config_coordinator_config_ensure_domain_t *ensure_domain,
    cluster_config_coordinator_config_hubspot_t *hubspot,
    char *nexus_url,
    double billing_trade_credit_days,
    double jwt_token_expiration,
    cluster_config_coordinator_config_hypertune_t *hypertune,
    cluster_config_coordinator_config_aws_marketplace_t *aws_marketplace,
    cluster_config_coordinator_config_pipedrive_t *pipedrive,
    cluster_config_coordinator_config_webplayer_t *webplayer,
    char *postmark_server_token,
    char *postmark_email_from,
    char *postmark_email_template,
    object_t *s3,
    char *ofac_api_key,
    char *usb_media_queue_dir,
    int usb_media_access_enabled,
    char *intercom_id_verify_secret,
    char *fvp_secret
    ) {
    cluster_config_coordinator_config_t *cluster_config_coordinator_config_local_var = malloc(sizeof(cluster_config_coordinator_config_t));
    if (!cluster_config_coordinator_config_local_var) {
        return NULL;
    }
    cluster_config_coordinator_config_local_var->bind_host = bind_host;
    cluster_config_coordinator_config_local_var->bind_port = bind_port;
    cluster_config_coordinator_config_local_var->db_database = db_database;
    cluster_config_coordinator_config_local_var->db_host = db_host;
    cluster_config_coordinator_config_local_var->db_port = db_port;
    cluster_config_coordinator_config_local_var->db_password = db_password;
    cluster_config_coordinator_config_local_var->db_user = db_user;
    cluster_config_coordinator_config_local_var->db_logging_enabled = db_logging_enabled;
    cluster_config_coordinator_config_local_var->config_db_host = config_db_host;
    cluster_config_coordinator_config_local_var->config_db_port = config_db_port;
    cluster_config_coordinator_config_local_var->config_db_user = config_db_user;
    cluster_config_coordinator_config_local_var->config_db_password = config_db_password;
    cluster_config_coordinator_config_local_var->config_db_name = config_db_name;
    cluster_config_coordinator_config_local_var->ip_block = ip_block;
    cluster_config_coordinator_config_local_var->local_ip = local_ip;
    cluster_config_coordinator_config_local_var->ip_block_netmask = ip_block_netmask;
    cluster_config_coordinator_config_local_var->instance_dns_servers = instance_dns_servers;
    cluster_config_coordinator_config_local_var->on_site = on_site;
    cluster_config_coordinator_config_local_var->private_headers = private_headers;
    cluster_config_coordinator_config_local_var->trial = trial;
    cluster_config_coordinator_config_local_var->trial_survey_id = trial_survey_id;
    cluster_config_coordinator_config_local_var->auth_providers = auth_providers;
    cluster_config_coordinator_config_local_var->per_project_storage_quota = per_project_storage_quota;
    cluster_config_coordinator_config_local_var->image_data_path = image_data_path;
    cluster_config_coordinator_config_local_var->ensure_domain = ensure_domain;
    cluster_config_coordinator_config_local_var->hubspot = hubspot;
    cluster_config_coordinator_config_local_var->nexus_url = nexus_url;
    cluster_config_coordinator_config_local_var->billing_trade_credit_days = billing_trade_credit_days;
    cluster_config_coordinator_config_local_var->jwt_token_expiration = jwt_token_expiration;
    cluster_config_coordinator_config_local_var->hypertune = hypertune;
    cluster_config_coordinator_config_local_var->aws_marketplace = aws_marketplace;
    cluster_config_coordinator_config_local_var->pipedrive = pipedrive;
    cluster_config_coordinator_config_local_var->webplayer = webplayer;
    cluster_config_coordinator_config_local_var->postmark_server_token = postmark_server_token;
    cluster_config_coordinator_config_local_var->postmark_email_from = postmark_email_from;
    cluster_config_coordinator_config_local_var->postmark_email_template = postmark_email_template;
    cluster_config_coordinator_config_local_var->s3 = s3;
    cluster_config_coordinator_config_local_var->ofac_api_key = ofac_api_key;
    cluster_config_coordinator_config_local_var->usb_media_queue_dir = usb_media_queue_dir;
    cluster_config_coordinator_config_local_var->usb_media_access_enabled = usb_media_access_enabled;
    cluster_config_coordinator_config_local_var->intercom_id_verify_secret = intercom_id_verify_secret;
    cluster_config_coordinator_config_local_var->fvp_secret = fvp_secret;

    cluster_config_coordinator_config_local_var->_library_owned = 1;
    return cluster_config_coordinator_config_local_var;
}

__attribute__((deprecated)) cluster_config_coordinator_config_t *cluster_config_coordinator_config_create(
    char *bind_host,
    double bind_port,
    char *db_database,
    char *db_host,
    double db_port,
    char *db_password,
    char *db_user,
    int db_logging_enabled,
    char *config_db_host,
    double config_db_port,
    char *config_db_user,
    char *config_db_password,
    char *config_db_name,
    char *ip_block,
    char *local_ip,
    char *ip_block_netmask,
    list_t *instance_dns_servers,
    int on_site,
    list_t *private_headers,
    cluster_config_coordinator_config_trial_t *trial,
    char *trial_survey_id,
    list_t *auth_providers,
    double per_project_storage_quota,
    char *image_data_path,
    cluster_config_coordinator_config_ensure_domain_t *ensure_domain,
    cluster_config_coordinator_config_hubspot_t *hubspot,
    char *nexus_url,
    double billing_trade_credit_days,
    double jwt_token_expiration,
    cluster_config_coordinator_config_hypertune_t *hypertune,
    cluster_config_coordinator_config_aws_marketplace_t *aws_marketplace,
    cluster_config_coordinator_config_pipedrive_t *pipedrive,
    cluster_config_coordinator_config_webplayer_t *webplayer,
    char *postmark_server_token,
    char *postmark_email_from,
    char *postmark_email_template,
    object_t *s3,
    char *ofac_api_key,
    char *usb_media_queue_dir,
    int usb_media_access_enabled,
    char *intercom_id_verify_secret,
    char *fvp_secret
    ) {
    return cluster_config_coordinator_config_create_internal (
        bind_host,
        bind_port,
        db_database,
        db_host,
        db_port,
        db_password,
        db_user,
        db_logging_enabled,
        config_db_host,
        config_db_port,
        config_db_user,
        config_db_password,
        config_db_name,
        ip_block,
        local_ip,
        ip_block_netmask,
        instance_dns_servers,
        on_site,
        private_headers,
        trial,
        trial_survey_id,
        auth_providers,
        per_project_storage_quota,
        image_data_path,
        ensure_domain,
        hubspot,
        nexus_url,
        billing_trade_credit_days,
        jwt_token_expiration,
        hypertune,
        aws_marketplace,
        pipedrive,
        webplayer,
        postmark_server_token,
        postmark_email_from,
        postmark_email_template,
        s3,
        ofac_api_key,
        usb_media_queue_dir,
        usb_media_access_enabled,
        intercom_id_verify_secret,
        fvp_secret
        );
}

void cluster_config_coordinator_config_free(cluster_config_coordinator_config_t *cluster_config_coordinator_config) {
    if(NULL == cluster_config_coordinator_config){
        return ;
    }
    if(cluster_config_coordinator_config->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cluster_config_coordinator_config_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cluster_config_coordinator_config->bind_host) {
        free(cluster_config_coordinator_config->bind_host);
        cluster_config_coordinator_config->bind_host = NULL;
    }
    if (cluster_config_coordinator_config->db_database) {
        free(cluster_config_coordinator_config->db_database);
        cluster_config_coordinator_config->db_database = NULL;
    }
    if (cluster_config_coordinator_config->db_host) {
        free(cluster_config_coordinator_config->db_host);
        cluster_config_coordinator_config->db_host = NULL;
    }
    if (cluster_config_coordinator_config->db_password) {
        free(cluster_config_coordinator_config->db_password);
        cluster_config_coordinator_config->db_password = NULL;
    }
    if (cluster_config_coordinator_config->db_user) {
        free(cluster_config_coordinator_config->db_user);
        cluster_config_coordinator_config->db_user = NULL;
    }
    if (cluster_config_coordinator_config->config_db_host) {
        free(cluster_config_coordinator_config->config_db_host);
        cluster_config_coordinator_config->config_db_host = NULL;
    }
    if (cluster_config_coordinator_config->config_db_user) {
        free(cluster_config_coordinator_config->config_db_user);
        cluster_config_coordinator_config->config_db_user = NULL;
    }
    if (cluster_config_coordinator_config->config_db_password) {
        free(cluster_config_coordinator_config->config_db_password);
        cluster_config_coordinator_config->config_db_password = NULL;
    }
    if (cluster_config_coordinator_config->config_db_name) {
        free(cluster_config_coordinator_config->config_db_name);
        cluster_config_coordinator_config->config_db_name = NULL;
    }
    if (cluster_config_coordinator_config->ip_block) {
        free(cluster_config_coordinator_config->ip_block);
        cluster_config_coordinator_config->ip_block = NULL;
    }
    if (cluster_config_coordinator_config->local_ip) {
        free(cluster_config_coordinator_config->local_ip);
        cluster_config_coordinator_config->local_ip = NULL;
    }
    if (cluster_config_coordinator_config->ip_block_netmask) {
        free(cluster_config_coordinator_config->ip_block_netmask);
        cluster_config_coordinator_config->ip_block_netmask = NULL;
    }
    if (cluster_config_coordinator_config->instance_dns_servers) {
        list_ForEach(listEntry, cluster_config_coordinator_config->instance_dns_servers) {
            free(listEntry->data);
        }
        list_freeList(cluster_config_coordinator_config->instance_dns_servers);
        cluster_config_coordinator_config->instance_dns_servers = NULL;
    }
    if (cluster_config_coordinator_config->private_headers) {
        list_ForEach(listEntry, cluster_config_coordinator_config->private_headers) {
            free(listEntry->data);
        }
        list_freeList(cluster_config_coordinator_config->private_headers);
        cluster_config_coordinator_config->private_headers = NULL;
    }
    if (cluster_config_coordinator_config->trial) {
        cluster_config_coordinator_config_trial_free(cluster_config_coordinator_config->trial);
        cluster_config_coordinator_config->trial = NULL;
    }
    if (cluster_config_coordinator_config->trial_survey_id) {
        free(cluster_config_coordinator_config->trial_survey_id);
        cluster_config_coordinator_config->trial_survey_id = NULL;
    }
    if (cluster_config_coordinator_config->auth_providers) {
        list_ForEach(listEntry, cluster_config_coordinator_config->auth_providers) {
            cluster_config_coordinator_config_auth_providers_inner_free(listEntry->data);
        }
        list_freeList(cluster_config_coordinator_config->auth_providers);
        cluster_config_coordinator_config->auth_providers = NULL;
    }
    if (cluster_config_coordinator_config->image_data_path) {
        free(cluster_config_coordinator_config->image_data_path);
        cluster_config_coordinator_config->image_data_path = NULL;
    }
    if (cluster_config_coordinator_config->ensure_domain) {
        cluster_config_coordinator_config_ensure_domain_free(cluster_config_coordinator_config->ensure_domain);
        cluster_config_coordinator_config->ensure_domain = NULL;
    }
    if (cluster_config_coordinator_config->hubspot) {
        cluster_config_coordinator_config_hubspot_free(cluster_config_coordinator_config->hubspot);
        cluster_config_coordinator_config->hubspot = NULL;
    }
    if (cluster_config_coordinator_config->nexus_url) {
        free(cluster_config_coordinator_config->nexus_url);
        cluster_config_coordinator_config->nexus_url = NULL;
    }
    if (cluster_config_coordinator_config->hypertune) {
        cluster_config_coordinator_config_hypertune_free(cluster_config_coordinator_config->hypertune);
        cluster_config_coordinator_config->hypertune = NULL;
    }
    if (cluster_config_coordinator_config->aws_marketplace) {
        cluster_config_coordinator_config_aws_marketplace_free(cluster_config_coordinator_config->aws_marketplace);
        cluster_config_coordinator_config->aws_marketplace = NULL;
    }
    if (cluster_config_coordinator_config->pipedrive) {
        cluster_config_coordinator_config_pipedrive_free(cluster_config_coordinator_config->pipedrive);
        cluster_config_coordinator_config->pipedrive = NULL;
    }
    if (cluster_config_coordinator_config->webplayer) {
        cluster_config_coordinator_config_webplayer_free(cluster_config_coordinator_config->webplayer);
        cluster_config_coordinator_config->webplayer = NULL;
    }
    if (cluster_config_coordinator_config->postmark_server_token) {
        free(cluster_config_coordinator_config->postmark_server_token);
        cluster_config_coordinator_config->postmark_server_token = NULL;
    }
    if (cluster_config_coordinator_config->postmark_email_from) {
        free(cluster_config_coordinator_config->postmark_email_from);
        cluster_config_coordinator_config->postmark_email_from = NULL;
    }
    if (cluster_config_coordinator_config->postmark_email_template) {
        free(cluster_config_coordinator_config->postmark_email_template);
        cluster_config_coordinator_config->postmark_email_template = NULL;
    }
    if (cluster_config_coordinator_config->s3) {
        object_free(cluster_config_coordinator_config->s3);
        cluster_config_coordinator_config->s3 = NULL;
    }
    if (cluster_config_coordinator_config->ofac_api_key) {
        free(cluster_config_coordinator_config->ofac_api_key);
        cluster_config_coordinator_config->ofac_api_key = NULL;
    }
    if (cluster_config_coordinator_config->usb_media_queue_dir) {
        free(cluster_config_coordinator_config->usb_media_queue_dir);
        cluster_config_coordinator_config->usb_media_queue_dir = NULL;
    }
    if (cluster_config_coordinator_config->intercom_id_verify_secret) {
        free(cluster_config_coordinator_config->intercom_id_verify_secret);
        cluster_config_coordinator_config->intercom_id_verify_secret = NULL;
    }
    if (cluster_config_coordinator_config->fvp_secret) {
        free(cluster_config_coordinator_config->fvp_secret);
        cluster_config_coordinator_config->fvp_secret = NULL;
    }
    free(cluster_config_coordinator_config);
}

cJSON *cluster_config_coordinator_config_convertToJSON(cluster_config_coordinator_config_t *cluster_config_coordinator_config) {
    cJSON *item = cJSON_CreateObject();

    // cluster_config_coordinator_config->bind_host
    if (!cluster_config_coordinator_config->bind_host) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "bindHost", cluster_config_coordinator_config->bind_host) == NULL) {
    goto fail; //String
    }


    // cluster_config_coordinator_config->bind_port
    if (!cluster_config_coordinator_config->bind_port) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "bindPort", cluster_config_coordinator_config->bind_port) == NULL) {
    goto fail; //Numeric
    }


    // cluster_config_coordinator_config->db_database
    if (!cluster_config_coordinator_config->db_database) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "dbDatabase", cluster_config_coordinator_config->db_database) == NULL) {
    goto fail; //String
    }


    // cluster_config_coordinator_config->db_host
    if (!cluster_config_coordinator_config->db_host) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "dbHost", cluster_config_coordinator_config->db_host) == NULL) {
    goto fail; //String
    }


    // cluster_config_coordinator_config->db_port
    if (!cluster_config_coordinator_config->db_port) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "dbPort", cluster_config_coordinator_config->db_port) == NULL) {
    goto fail; //Numeric
    }


    // cluster_config_coordinator_config->db_password
    if (!cluster_config_coordinator_config->db_password) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "dbPassword", cluster_config_coordinator_config->db_password) == NULL) {
    goto fail; //String
    }


    // cluster_config_coordinator_config->db_user
    if (!cluster_config_coordinator_config->db_user) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "dbUser", cluster_config_coordinator_config->db_user) == NULL) {
    goto fail; //String
    }


    // cluster_config_coordinator_config->db_logging_enabled
    if (!cluster_config_coordinator_config->db_logging_enabled) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "dbLoggingEnabled", cluster_config_coordinator_config->db_logging_enabled) == NULL) {
    goto fail; //Bool
    }


    // cluster_config_coordinator_config->config_db_host
    if(cluster_config_coordinator_config->config_db_host) {
    if(cJSON_AddStringToObject(item, "configDbHost", cluster_config_coordinator_config->config_db_host) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config_coordinator_config->config_db_port
    if(cluster_config_coordinator_config->config_db_port) {
    if(cJSON_AddNumberToObject(item, "configDbPort", cluster_config_coordinator_config->config_db_port) == NULL) {
    goto fail; //Numeric
    }
    }


    // cluster_config_coordinator_config->config_db_user
    if(cluster_config_coordinator_config->config_db_user) {
    if(cJSON_AddStringToObject(item, "configDbUser", cluster_config_coordinator_config->config_db_user) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config_coordinator_config->config_db_password
    if(cluster_config_coordinator_config->config_db_password) {
    if(cJSON_AddStringToObject(item, "configDbPassword", cluster_config_coordinator_config->config_db_password) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config_coordinator_config->config_db_name
    if(cluster_config_coordinator_config->config_db_name) {
    if(cJSON_AddStringToObject(item, "configDbName", cluster_config_coordinator_config->config_db_name) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config_coordinator_config->ip_block
    if (!cluster_config_coordinator_config->ip_block) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "ipBlock", cluster_config_coordinator_config->ip_block) == NULL) {
    goto fail; //String
    }


    // cluster_config_coordinator_config->local_ip
    if (!cluster_config_coordinator_config->local_ip) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "localIp", cluster_config_coordinator_config->local_ip) == NULL) {
    goto fail; //String
    }


    // cluster_config_coordinator_config->ip_block_netmask
    if (!cluster_config_coordinator_config->ip_block_netmask) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "ipBlockNetmask", cluster_config_coordinator_config->ip_block_netmask) == NULL) {
    goto fail; //String
    }


    // cluster_config_coordinator_config->instance_dns_servers
    if(cluster_config_coordinator_config->instance_dns_servers) {
    cJSON *instance_dns_servers = cJSON_AddArrayToObject(item, "instanceDNSServers");
    if(instance_dns_servers == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *instance_dns_serversListEntry;
    list_ForEach(instance_dns_serversListEntry, cluster_config_coordinator_config->instance_dns_servers) {
    if(cJSON_AddStringToObject(instance_dns_servers, "", instance_dns_serversListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // cluster_config_coordinator_config->on_site
    if (!cluster_config_coordinator_config->on_site) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "onSite", cluster_config_coordinator_config->on_site) == NULL) {
    goto fail; //Bool
    }


    // cluster_config_coordinator_config->private_headers
    if (!cluster_config_coordinator_config->private_headers) {
        goto fail;
    }
    cJSON *private_headers = cJSON_AddArrayToObject(item, "privateHeaders");
    if(private_headers == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *private_headersListEntry;
    list_ForEach(private_headersListEntry, cluster_config_coordinator_config->private_headers) {
    if(cJSON_AddStringToObject(private_headers, "", private_headersListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // cluster_config_coordinator_config->trial
    if(cluster_config_coordinator_config->trial) {
    cJSON *trial_local_JSON = cluster_config_coordinator_config_trial_convertToJSON(cluster_config_coordinator_config->trial);
    if(trial_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "trial", trial_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // cluster_config_coordinator_config->trial_survey_id
    if (!cluster_config_coordinator_config->trial_survey_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "trialSurveyId", cluster_config_coordinator_config->trial_survey_id) == NULL) {
    goto fail; //String
    }


    // cluster_config_coordinator_config->auth_providers
    if(cluster_config_coordinator_config->auth_providers) {
    cJSON *auth_providers = cJSON_AddArrayToObject(item, "authProviders");
    if(auth_providers == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *auth_providersListEntry;
    if (cluster_config_coordinator_config->auth_providers) {
    list_ForEach(auth_providersListEntry, cluster_config_coordinator_config->auth_providers) {
    cJSON *itemLocal = cluster_config_coordinator_config_auth_providers_inner_convertToJSON(auth_providersListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(auth_providers, itemLocal);
    }
    }
    }


    // cluster_config_coordinator_config->per_project_storage_quota
    if(cluster_config_coordinator_config->per_project_storage_quota) {
    if(cJSON_AddNumberToObject(item, "perProjectStorageQuota", cluster_config_coordinator_config->per_project_storage_quota) == NULL) {
    goto fail; //Numeric
    }
    }


    // cluster_config_coordinator_config->image_data_path
    if(cluster_config_coordinator_config->image_data_path) {
    if(cJSON_AddStringToObject(item, "imageDataPath", cluster_config_coordinator_config->image_data_path) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config_coordinator_config->ensure_domain
    if(cluster_config_coordinator_config->ensure_domain) {
    cJSON *ensure_domain_local_JSON = cluster_config_coordinator_config_ensure_domain_convertToJSON(cluster_config_coordinator_config->ensure_domain);
    if(ensure_domain_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "ensureDomain", ensure_domain_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // cluster_config_coordinator_config->hubspot
    if(cluster_config_coordinator_config->hubspot) {
    cJSON *hubspot_local_JSON = cluster_config_coordinator_config_hubspot_convertToJSON(cluster_config_coordinator_config->hubspot);
    if(hubspot_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "hubspot", hubspot_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // cluster_config_coordinator_config->nexus_url
    if(cluster_config_coordinator_config->nexus_url) {
    if(cJSON_AddStringToObject(item, "nexusUrl", cluster_config_coordinator_config->nexus_url) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config_coordinator_config->billing_trade_credit_days
    if(cluster_config_coordinator_config->billing_trade_credit_days) {
    if(cJSON_AddNumberToObject(item, "billingTradeCreditDays", cluster_config_coordinator_config->billing_trade_credit_days) == NULL) {
    goto fail; //Numeric
    }
    }


    // cluster_config_coordinator_config->jwt_token_expiration
    if(cluster_config_coordinator_config->jwt_token_expiration) {
    if(cJSON_AddNumberToObject(item, "jwtTokenExpiration", cluster_config_coordinator_config->jwt_token_expiration) == NULL) {
    goto fail; //Numeric
    }
    }


    // cluster_config_coordinator_config->hypertune
    if(cluster_config_coordinator_config->hypertune) {
    cJSON *hypertune_local_JSON = cluster_config_coordinator_config_hypertune_convertToJSON(cluster_config_coordinator_config->hypertune);
    if(hypertune_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "hypertune", hypertune_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // cluster_config_coordinator_config->aws_marketplace
    if(cluster_config_coordinator_config->aws_marketplace) {
    cJSON *aws_marketplace_local_JSON = cluster_config_coordinator_config_aws_marketplace_convertToJSON(cluster_config_coordinator_config->aws_marketplace);
    if(aws_marketplace_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "awsMarketplace", aws_marketplace_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // cluster_config_coordinator_config->pipedrive
    if(cluster_config_coordinator_config->pipedrive) {
    cJSON *pipedrive_local_JSON = cluster_config_coordinator_config_pipedrive_convertToJSON(cluster_config_coordinator_config->pipedrive);
    if(pipedrive_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "pipedrive", pipedrive_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // cluster_config_coordinator_config->webplayer
    if(cluster_config_coordinator_config->webplayer) {
    cJSON *webplayer_local_JSON = cluster_config_coordinator_config_webplayer_convertToJSON(cluster_config_coordinator_config->webplayer);
    if(webplayer_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "webplayer", webplayer_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // cluster_config_coordinator_config->postmark_server_token
    if(cluster_config_coordinator_config->postmark_server_token) {
    if(cJSON_AddStringToObject(item, "postmarkServerToken", cluster_config_coordinator_config->postmark_server_token) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config_coordinator_config->postmark_email_from
    if(cluster_config_coordinator_config->postmark_email_from) {
    if(cJSON_AddStringToObject(item, "postmarkEmailFrom", cluster_config_coordinator_config->postmark_email_from) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config_coordinator_config->postmark_email_template
    if(cluster_config_coordinator_config->postmark_email_template) {
    if(cJSON_AddStringToObject(item, "postmarkEmailTemplate", cluster_config_coordinator_config->postmark_email_template) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config_coordinator_config->s3
    if(cluster_config_coordinator_config->s3) {
    cJSON *s3_object = object_convertToJSON(cluster_config_coordinator_config->s3);
    if(s3_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "s3", s3_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // cluster_config_coordinator_config->ofac_api_key
    if(cluster_config_coordinator_config->ofac_api_key) {
    if(cJSON_AddStringToObject(item, "ofacApiKey", cluster_config_coordinator_config->ofac_api_key) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config_coordinator_config->usb_media_queue_dir
    if(cluster_config_coordinator_config->usb_media_queue_dir) {
    if(cJSON_AddStringToObject(item, "usbMediaQueueDir", cluster_config_coordinator_config->usb_media_queue_dir) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config_coordinator_config->usb_media_access_enabled
    if(cluster_config_coordinator_config->usb_media_access_enabled) {
    if(cJSON_AddBoolToObject(item, "usbMediaAccessEnabled", cluster_config_coordinator_config->usb_media_access_enabled) == NULL) {
    goto fail; //Bool
    }
    }


    // cluster_config_coordinator_config->intercom_id_verify_secret
    if(cluster_config_coordinator_config->intercom_id_verify_secret) {
    if(cJSON_AddStringToObject(item, "intercomIdVerifySecret", cluster_config_coordinator_config->intercom_id_verify_secret) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config_coordinator_config->fvp_secret
    if(cluster_config_coordinator_config->fvp_secret) {
    if(cJSON_AddStringToObject(item, "fvpSecret", cluster_config_coordinator_config->fvp_secret) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

cluster_config_coordinator_config_t *cluster_config_coordinator_config_parseFromJSON(cJSON *cluster_config_coordinator_configJSON){

    cluster_config_coordinator_config_t *cluster_config_coordinator_config_local_var = NULL;

    // define the local list for cluster_config_coordinator_config->instance_dns_servers
    list_t *instance_dns_serversList = NULL;

    // define the local list for cluster_config_coordinator_config->private_headers
    list_t *private_headersList = NULL;

    // define the local variable for cluster_config_coordinator_config->trial
    cluster_config_coordinator_config_trial_t *trial_local_nonprim = NULL;

    // define the local list for cluster_config_coordinator_config->auth_providers
    list_t *auth_providersList = NULL;

    // define the local variable for cluster_config_coordinator_config->ensure_domain
    cluster_config_coordinator_config_ensure_domain_t *ensure_domain_local_nonprim = NULL;

    // define the local variable for cluster_config_coordinator_config->hubspot
    cluster_config_coordinator_config_hubspot_t *hubspot_local_nonprim = NULL;

    // define the local variable for cluster_config_coordinator_config->hypertune
    cluster_config_coordinator_config_hypertune_t *hypertune_local_nonprim = NULL;

    // define the local variable for cluster_config_coordinator_config->aws_marketplace
    cluster_config_coordinator_config_aws_marketplace_t *aws_marketplace_local_nonprim = NULL;

    // define the local variable for cluster_config_coordinator_config->pipedrive
    cluster_config_coordinator_config_pipedrive_t *pipedrive_local_nonprim = NULL;

    // define the local variable for cluster_config_coordinator_config->webplayer
    cluster_config_coordinator_config_webplayer_t *webplayer_local_nonprim = NULL;

    // cluster_config_coordinator_config->bind_host
    cJSON *bind_host = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_configJSON, "bindHost");
    if (cJSON_IsNull(bind_host)) {
        bind_host = NULL;
    }
    if (!bind_host) {
        goto end;
    }

    
    if(!cJSON_IsString(bind_host))
    {
    goto end; //String
    }

    // cluster_config_coordinator_config->bind_port
    cJSON *bind_port = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_configJSON, "bindPort");
    if (cJSON_IsNull(bind_port)) {
        bind_port = NULL;
    }
    if (!bind_port) {
        goto end;
    }

    
    if(!cJSON_IsNumber(bind_port))
    {
    goto end; //Numeric
    }

    // cluster_config_coordinator_config->db_database
    cJSON *db_database = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_configJSON, "dbDatabase");
    if (cJSON_IsNull(db_database)) {
        db_database = NULL;
    }
    if (!db_database) {
        goto end;
    }

    
    if(!cJSON_IsString(db_database))
    {
    goto end; //String
    }

    // cluster_config_coordinator_config->db_host
    cJSON *db_host = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_configJSON, "dbHost");
    if (cJSON_IsNull(db_host)) {
        db_host = NULL;
    }
    if (!db_host) {
        goto end;
    }

    
    if(!cJSON_IsString(db_host))
    {
    goto end; //String
    }

    // cluster_config_coordinator_config->db_port
    cJSON *db_port = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_configJSON, "dbPort");
    if (cJSON_IsNull(db_port)) {
        db_port = NULL;
    }
    if (!db_port) {
        goto end;
    }

    
    if(!cJSON_IsNumber(db_port))
    {
    goto end; //Numeric
    }

    // cluster_config_coordinator_config->db_password
    cJSON *db_password = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_configJSON, "dbPassword");
    if (cJSON_IsNull(db_password)) {
        db_password = NULL;
    }
    if (!db_password) {
        goto end;
    }

    
    if(!cJSON_IsString(db_password))
    {
    goto end; //String
    }

    // cluster_config_coordinator_config->db_user
    cJSON *db_user = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_configJSON, "dbUser");
    if (cJSON_IsNull(db_user)) {
        db_user = NULL;
    }
    if (!db_user) {
        goto end;
    }

    
    if(!cJSON_IsString(db_user))
    {
    goto end; //String
    }

    // cluster_config_coordinator_config->db_logging_enabled
    cJSON *db_logging_enabled = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_configJSON, "dbLoggingEnabled");
    if (cJSON_IsNull(db_logging_enabled)) {
        db_logging_enabled = NULL;
    }
    if (!db_logging_enabled) {
        goto end;
    }

    
    if(!cJSON_IsBool(db_logging_enabled))
    {
    goto end; //Bool
    }

    // cluster_config_coordinator_config->config_db_host
    cJSON *config_db_host = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_configJSON, "configDbHost");
    if (cJSON_IsNull(config_db_host)) {
        config_db_host = NULL;
    }
    if (config_db_host) { 
    if(!cJSON_IsString(config_db_host) && !cJSON_IsNull(config_db_host))
    {
    goto end; //String
    }
    }

    // cluster_config_coordinator_config->config_db_port
    cJSON *config_db_port = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_configJSON, "configDbPort");
    if (cJSON_IsNull(config_db_port)) {
        config_db_port = NULL;
    }
    if (config_db_port) { 
    if(!cJSON_IsNumber(config_db_port))
    {
    goto end; //Numeric
    }
    }

    // cluster_config_coordinator_config->config_db_user
    cJSON *config_db_user = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_configJSON, "configDbUser");
    if (cJSON_IsNull(config_db_user)) {
        config_db_user = NULL;
    }
    if (config_db_user) { 
    if(!cJSON_IsString(config_db_user) && !cJSON_IsNull(config_db_user))
    {
    goto end; //String
    }
    }

    // cluster_config_coordinator_config->config_db_password
    cJSON *config_db_password = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_configJSON, "configDbPassword");
    if (cJSON_IsNull(config_db_password)) {
        config_db_password = NULL;
    }
    if (config_db_password) { 
    if(!cJSON_IsString(config_db_password) && !cJSON_IsNull(config_db_password))
    {
    goto end; //String
    }
    }

    // cluster_config_coordinator_config->config_db_name
    cJSON *config_db_name = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_configJSON, "configDbName");
    if (cJSON_IsNull(config_db_name)) {
        config_db_name = NULL;
    }
    if (config_db_name) { 
    if(!cJSON_IsString(config_db_name) && !cJSON_IsNull(config_db_name))
    {
    goto end; //String
    }
    }

    // cluster_config_coordinator_config->ip_block
    cJSON *ip_block = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_configJSON, "ipBlock");
    if (cJSON_IsNull(ip_block)) {
        ip_block = NULL;
    }
    if (!ip_block) {
        goto end;
    }

    
    if(!cJSON_IsString(ip_block))
    {
    goto end; //String
    }

    // cluster_config_coordinator_config->local_ip
    cJSON *local_ip = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_configJSON, "localIp");
    if (cJSON_IsNull(local_ip)) {
        local_ip = NULL;
    }
    if (!local_ip) {
        goto end;
    }

    
    if(!cJSON_IsString(local_ip))
    {
    goto end; //String
    }

    // cluster_config_coordinator_config->ip_block_netmask
    cJSON *ip_block_netmask = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_configJSON, "ipBlockNetmask");
    if (cJSON_IsNull(ip_block_netmask)) {
        ip_block_netmask = NULL;
    }
    if (!ip_block_netmask) {
        goto end;
    }

    
    if(!cJSON_IsString(ip_block_netmask))
    {
    goto end; //String
    }

    // cluster_config_coordinator_config->instance_dns_servers
    cJSON *instance_dns_servers = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_configJSON, "instanceDNSServers");
    if (cJSON_IsNull(instance_dns_servers)) {
        instance_dns_servers = NULL;
    }
    if (instance_dns_servers) { 
    cJSON *instance_dns_servers_local = NULL;
    if(!cJSON_IsArray(instance_dns_servers)) {
        goto end;//primitive container
    }
    instance_dns_serversList = list_createList();

    cJSON_ArrayForEach(instance_dns_servers_local, instance_dns_servers)
    {
        if(!cJSON_IsString(instance_dns_servers_local))
        {
            goto end;
        }
        list_addElement(instance_dns_serversList , strdup(instance_dns_servers_local->valuestring));
    }
    }

    // cluster_config_coordinator_config->on_site
    cJSON *on_site = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_configJSON, "onSite");
    if (cJSON_IsNull(on_site)) {
        on_site = NULL;
    }
    if (!on_site) {
        goto end;
    }

    
    if(!cJSON_IsBool(on_site))
    {
    goto end; //Bool
    }

    // cluster_config_coordinator_config->private_headers
    cJSON *private_headers = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_configJSON, "privateHeaders");
    if (cJSON_IsNull(private_headers)) {
        private_headers = NULL;
    }
    if (!private_headers) {
        goto end;
    }

    
    cJSON *private_headers_local = NULL;
    if(!cJSON_IsArray(private_headers)) {
        goto end;//primitive container
    }
    private_headersList = list_createList();

    cJSON_ArrayForEach(private_headers_local, private_headers)
    {
        if(!cJSON_IsString(private_headers_local))
        {
            goto end;
        }
        list_addElement(private_headersList , strdup(private_headers_local->valuestring));
    }

    // cluster_config_coordinator_config->trial
    cJSON *trial = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_configJSON, "trial");
    if (cJSON_IsNull(trial)) {
        trial = NULL;
    }
    if (trial) { 
    trial_local_nonprim = cluster_config_coordinator_config_trial_parseFromJSON(trial); //nonprimitive
    }

    // cluster_config_coordinator_config->trial_survey_id
    cJSON *trial_survey_id = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_configJSON, "trialSurveyId");
    if (cJSON_IsNull(trial_survey_id)) {
        trial_survey_id = NULL;
    }
    if (!trial_survey_id) {
        goto end;
    }

    
    if(!cJSON_IsString(trial_survey_id))
    {
    goto end; //String
    }

    // cluster_config_coordinator_config->auth_providers
    cJSON *auth_providers = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_configJSON, "authProviders");
    if (cJSON_IsNull(auth_providers)) {
        auth_providers = NULL;
    }
    if (auth_providers) { 
    cJSON *auth_providers_local_nonprimitive = NULL;
    if(!cJSON_IsArray(auth_providers)){
        goto end; //nonprimitive container
    }

    auth_providersList = list_createList();

    cJSON_ArrayForEach(auth_providers_local_nonprimitive,auth_providers )
    {
        if(!cJSON_IsObject(auth_providers_local_nonprimitive)){
            goto end;
        }
        cluster_config_coordinator_config_auth_providers_inner_t *auth_providersItem = cluster_config_coordinator_config_auth_providers_inner_parseFromJSON(auth_providers_local_nonprimitive);

        list_addElement(auth_providersList, auth_providersItem);
    }
    }

    // cluster_config_coordinator_config->per_project_storage_quota
    cJSON *per_project_storage_quota = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_configJSON, "perProjectStorageQuota");
    if (cJSON_IsNull(per_project_storage_quota)) {
        per_project_storage_quota = NULL;
    }
    if (per_project_storage_quota) { 
    if(!cJSON_IsNumber(per_project_storage_quota))
    {
    goto end; //Numeric
    }
    }

    // cluster_config_coordinator_config->image_data_path
    cJSON *image_data_path = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_configJSON, "imageDataPath");
    if (cJSON_IsNull(image_data_path)) {
        image_data_path = NULL;
    }
    if (image_data_path) { 
    if(!cJSON_IsString(image_data_path) && !cJSON_IsNull(image_data_path))
    {
    goto end; //String
    }
    }

    // cluster_config_coordinator_config->ensure_domain
    cJSON *ensure_domain = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_configJSON, "ensureDomain");
    if (cJSON_IsNull(ensure_domain)) {
        ensure_domain = NULL;
    }
    if (ensure_domain) { 
    ensure_domain_local_nonprim = cluster_config_coordinator_config_ensure_domain_parseFromJSON(ensure_domain); //nonprimitive
    }

    // cluster_config_coordinator_config->hubspot
    cJSON *hubspot = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_configJSON, "hubspot");
    if (cJSON_IsNull(hubspot)) {
        hubspot = NULL;
    }
    if (hubspot) { 
    hubspot_local_nonprim = cluster_config_coordinator_config_hubspot_parseFromJSON(hubspot); //nonprimitive
    }

    // cluster_config_coordinator_config->nexus_url
    cJSON *nexus_url = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_configJSON, "nexusUrl");
    if (cJSON_IsNull(nexus_url)) {
        nexus_url = NULL;
    }
    if (nexus_url) { 
    if(!cJSON_IsString(nexus_url) && !cJSON_IsNull(nexus_url))
    {
    goto end; //String
    }
    }

    // cluster_config_coordinator_config->billing_trade_credit_days
    cJSON *billing_trade_credit_days = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_configJSON, "billingTradeCreditDays");
    if (cJSON_IsNull(billing_trade_credit_days)) {
        billing_trade_credit_days = NULL;
    }
    if (billing_trade_credit_days) { 
    if(!cJSON_IsNumber(billing_trade_credit_days))
    {
    goto end; //Numeric
    }
    }

    // cluster_config_coordinator_config->jwt_token_expiration
    cJSON *jwt_token_expiration = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_configJSON, "jwtTokenExpiration");
    if (cJSON_IsNull(jwt_token_expiration)) {
        jwt_token_expiration = NULL;
    }
    if (jwt_token_expiration) { 
    if(!cJSON_IsNumber(jwt_token_expiration))
    {
    goto end; //Numeric
    }
    }

    // cluster_config_coordinator_config->hypertune
    cJSON *hypertune = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_configJSON, "hypertune");
    if (cJSON_IsNull(hypertune)) {
        hypertune = NULL;
    }
    if (hypertune) { 
    hypertune_local_nonprim = cluster_config_coordinator_config_hypertune_parseFromJSON(hypertune); //nonprimitive
    }

    // cluster_config_coordinator_config->aws_marketplace
    cJSON *aws_marketplace = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_configJSON, "awsMarketplace");
    if (cJSON_IsNull(aws_marketplace)) {
        aws_marketplace = NULL;
    }
    if (aws_marketplace) { 
    aws_marketplace_local_nonprim = cluster_config_coordinator_config_aws_marketplace_parseFromJSON(aws_marketplace); //nonprimitive
    }

    // cluster_config_coordinator_config->pipedrive
    cJSON *pipedrive = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_configJSON, "pipedrive");
    if (cJSON_IsNull(pipedrive)) {
        pipedrive = NULL;
    }
    if (pipedrive) { 
    pipedrive_local_nonprim = cluster_config_coordinator_config_pipedrive_parseFromJSON(pipedrive); //nonprimitive
    }

    // cluster_config_coordinator_config->webplayer
    cJSON *webplayer = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_configJSON, "webplayer");
    if (cJSON_IsNull(webplayer)) {
        webplayer = NULL;
    }
    if (webplayer) { 
    webplayer_local_nonprim = cluster_config_coordinator_config_webplayer_parseFromJSON(webplayer); //nonprimitive
    }

    // cluster_config_coordinator_config->postmark_server_token
    cJSON *postmark_server_token = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_configJSON, "postmarkServerToken");
    if (cJSON_IsNull(postmark_server_token)) {
        postmark_server_token = NULL;
    }
    if (postmark_server_token) { 
    if(!cJSON_IsString(postmark_server_token) && !cJSON_IsNull(postmark_server_token))
    {
    goto end; //String
    }
    }

    // cluster_config_coordinator_config->postmark_email_from
    cJSON *postmark_email_from = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_configJSON, "postmarkEmailFrom");
    if (cJSON_IsNull(postmark_email_from)) {
        postmark_email_from = NULL;
    }
    if (postmark_email_from) { 
    if(!cJSON_IsString(postmark_email_from) && !cJSON_IsNull(postmark_email_from))
    {
    goto end; //String
    }
    }

    // cluster_config_coordinator_config->postmark_email_template
    cJSON *postmark_email_template = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_configJSON, "postmarkEmailTemplate");
    if (cJSON_IsNull(postmark_email_template)) {
        postmark_email_template = NULL;
    }
    if (postmark_email_template) { 
    if(!cJSON_IsString(postmark_email_template) && !cJSON_IsNull(postmark_email_template))
    {
    goto end; //String
    }
    }

    // cluster_config_coordinator_config->s3
    cJSON *s3 = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_configJSON, "s3");
    if (cJSON_IsNull(s3)) {
        s3 = NULL;
    }
    object_t *s3_local_object = NULL;
    if (s3) { 
    s3_local_object = object_parseFromJSON(s3); //object
    }

    // cluster_config_coordinator_config->ofac_api_key
    cJSON *ofac_api_key = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_configJSON, "ofacApiKey");
    if (cJSON_IsNull(ofac_api_key)) {
        ofac_api_key = NULL;
    }
    if (ofac_api_key) { 
    if(!cJSON_IsString(ofac_api_key) && !cJSON_IsNull(ofac_api_key))
    {
    goto end; //String
    }
    }

    // cluster_config_coordinator_config->usb_media_queue_dir
    cJSON *usb_media_queue_dir = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_configJSON, "usbMediaQueueDir");
    if (cJSON_IsNull(usb_media_queue_dir)) {
        usb_media_queue_dir = NULL;
    }
    if (usb_media_queue_dir) { 
    if(!cJSON_IsString(usb_media_queue_dir) && !cJSON_IsNull(usb_media_queue_dir))
    {
    goto end; //String
    }
    }

    // cluster_config_coordinator_config->usb_media_access_enabled
    cJSON *usb_media_access_enabled = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_configJSON, "usbMediaAccessEnabled");
    if (cJSON_IsNull(usb_media_access_enabled)) {
        usb_media_access_enabled = NULL;
    }
    if (usb_media_access_enabled) { 
    if(!cJSON_IsBool(usb_media_access_enabled))
    {
    goto end; //Bool
    }
    }

    // cluster_config_coordinator_config->intercom_id_verify_secret
    cJSON *intercom_id_verify_secret = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_configJSON, "intercomIdVerifySecret");
    if (cJSON_IsNull(intercom_id_verify_secret)) {
        intercom_id_verify_secret = NULL;
    }
    if (intercom_id_verify_secret) { 
    if(!cJSON_IsString(intercom_id_verify_secret) && !cJSON_IsNull(intercom_id_verify_secret))
    {
    goto end; //String
    }
    }

    // cluster_config_coordinator_config->fvp_secret
    cJSON *fvp_secret = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_configJSON, "fvpSecret");
    if (cJSON_IsNull(fvp_secret)) {
        fvp_secret = NULL;
    }
    if (fvp_secret) { 
    if(!cJSON_IsString(fvp_secret) && !cJSON_IsNull(fvp_secret))
    {
    goto end; //String
    }
    }


    cluster_config_coordinator_config_local_var = cluster_config_coordinator_config_create_internal (
        strdup(bind_host->valuestring),
        bind_port->valuedouble,
        strdup(db_database->valuestring),
        strdup(db_host->valuestring),
        db_port->valuedouble,
        strdup(db_password->valuestring),
        strdup(db_user->valuestring),
        db_logging_enabled->valueint,
        config_db_host && !cJSON_IsNull(config_db_host) ? strdup(config_db_host->valuestring) : NULL,
        config_db_port ? config_db_port->valuedouble : 0,
        config_db_user && !cJSON_IsNull(config_db_user) ? strdup(config_db_user->valuestring) : NULL,
        config_db_password && !cJSON_IsNull(config_db_password) ? strdup(config_db_password->valuestring) : NULL,
        config_db_name && !cJSON_IsNull(config_db_name) ? strdup(config_db_name->valuestring) : NULL,
        strdup(ip_block->valuestring),
        strdup(local_ip->valuestring),
        strdup(ip_block_netmask->valuestring),
        instance_dns_servers ? instance_dns_serversList : NULL,
        on_site->valueint,
        private_headersList,
        trial ? trial_local_nonprim : NULL,
        strdup(trial_survey_id->valuestring),
        auth_providers ? auth_providersList : NULL,
        per_project_storage_quota ? per_project_storage_quota->valuedouble : 0,
        image_data_path && !cJSON_IsNull(image_data_path) ? strdup(image_data_path->valuestring) : NULL,
        ensure_domain ? ensure_domain_local_nonprim : NULL,
        hubspot ? hubspot_local_nonprim : NULL,
        nexus_url && !cJSON_IsNull(nexus_url) ? strdup(nexus_url->valuestring) : NULL,
        billing_trade_credit_days ? billing_trade_credit_days->valuedouble : 0,
        jwt_token_expiration ? jwt_token_expiration->valuedouble : 0,
        hypertune ? hypertune_local_nonprim : NULL,
        aws_marketplace ? aws_marketplace_local_nonprim : NULL,
        pipedrive ? pipedrive_local_nonprim : NULL,
        webplayer ? webplayer_local_nonprim : NULL,
        postmark_server_token && !cJSON_IsNull(postmark_server_token) ? strdup(postmark_server_token->valuestring) : NULL,
        postmark_email_from && !cJSON_IsNull(postmark_email_from) ? strdup(postmark_email_from->valuestring) : NULL,
        postmark_email_template && !cJSON_IsNull(postmark_email_template) ? strdup(postmark_email_template->valuestring) : NULL,
        s3 ? s3_local_object : NULL,
        ofac_api_key && !cJSON_IsNull(ofac_api_key) ? strdup(ofac_api_key->valuestring) : NULL,
        usb_media_queue_dir && !cJSON_IsNull(usb_media_queue_dir) ? strdup(usb_media_queue_dir->valuestring) : NULL,
        usb_media_access_enabled ? usb_media_access_enabled->valueint : 0,
        intercom_id_verify_secret && !cJSON_IsNull(intercom_id_verify_secret) ? strdup(intercom_id_verify_secret->valuestring) : NULL,
        fvp_secret && !cJSON_IsNull(fvp_secret) ? strdup(fvp_secret->valuestring) : NULL
        );

    return cluster_config_coordinator_config_local_var;
end:
    if (instance_dns_serversList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, instance_dns_serversList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(instance_dns_serversList);
        instance_dns_serversList = NULL;
    }
    if (private_headersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, private_headersList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(private_headersList);
        private_headersList = NULL;
    }
    if (trial_local_nonprim) {
        cluster_config_coordinator_config_trial_free(trial_local_nonprim);
        trial_local_nonprim = NULL;
    }
    if (auth_providersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, auth_providersList) {
            cluster_config_coordinator_config_auth_providers_inner_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(auth_providersList);
        auth_providersList = NULL;
    }
    if (ensure_domain_local_nonprim) {
        cluster_config_coordinator_config_ensure_domain_free(ensure_domain_local_nonprim);
        ensure_domain_local_nonprim = NULL;
    }
    if (hubspot_local_nonprim) {
        cluster_config_coordinator_config_hubspot_free(hubspot_local_nonprim);
        hubspot_local_nonprim = NULL;
    }
    if (hypertune_local_nonprim) {
        cluster_config_coordinator_config_hypertune_free(hypertune_local_nonprim);
        hypertune_local_nonprim = NULL;
    }
    if (aws_marketplace_local_nonprim) {
        cluster_config_coordinator_config_aws_marketplace_free(aws_marketplace_local_nonprim);
        aws_marketplace_local_nonprim = NULL;
    }
    if (pipedrive_local_nonprim) {
        cluster_config_coordinator_config_pipedrive_free(pipedrive_local_nonprim);
        pipedrive_local_nonprim = NULL;
    }
    if (webplayer_local_nonprim) {
        cluster_config_coordinator_config_webplayer_free(webplayer_local_nonprim);
        webplayer_local_nonprim = NULL;
    }
    return NULL;

}
