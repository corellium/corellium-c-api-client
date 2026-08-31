/*
 * cluster_config_coordinator_config.h
 *
 * 
 */

#ifndef _cluster_config_coordinator_config_H_
#define _cluster_config_coordinator_config_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cluster_config_coordinator_config_t cluster_config_coordinator_config_t;

#include "any_type.h"
#include "cluster_config_coordinator_config_auth_providers_inner.h"
#include "cluster_config_coordinator_config_aws_marketplace.h"
#include "cluster_config_coordinator_config_ensure_domain.h"
#include "cluster_config_coordinator_config_hubspot.h"
#include "cluster_config_coordinator_config_hypertune.h"
#include "cluster_config_coordinator_config_pipedrive.h"
#include "cluster_config_coordinator_config_trial.h"
#include "cluster_config_coordinator_config_webplayer.h"
#include "object.h"



typedef struct cluster_config_coordinator_config_t {
    char *bind_host; // string
    double bind_port; //numeric
    char *db_database; // string
    char *db_host; // string
    double db_port; //numeric
    char *db_password; // string
    char *db_user; // string
    int db_logging_enabled; //boolean
    char *config_db_host; // string
    double config_db_port; //numeric
    char *config_db_user; // string
    char *config_db_password; // string
    char *config_db_name; // string
    char *ip_block; // string
    char *local_ip; // string
    char *ip_block_netmask; // string
    list_t *instance_dns_servers; //primitive container
    int on_site; //boolean
    list_t *private_headers; //primitive container
    struct cluster_config_coordinator_config_trial_t *trial; //model
    char *trial_survey_id; // string
    list_t *auth_providers; //nonprimitive container
    double per_project_storage_quota; //numeric
    char *image_data_path; // string
    struct cluster_config_coordinator_config_ensure_domain_t *ensure_domain; //model
    struct cluster_config_coordinator_config_hubspot_t *hubspot; //model
    char *nexus_url; // string
    double billing_trade_credit_days; //numeric
    double jwt_token_expiration; //numeric
    struct cluster_config_coordinator_config_hypertune_t *hypertune; //model
    struct cluster_config_coordinator_config_aws_marketplace_t *aws_marketplace; //model
    struct cluster_config_coordinator_config_pipedrive_t *pipedrive; //model
    struct cluster_config_coordinator_config_webplayer_t *webplayer; //model
    char *postmark_server_token; // string
    char *postmark_email_from; // string
    char *postmark_email_template; // string
    object_t *s3; //object
    char *ofac_api_key; // string
    char *usb_media_queue_dir; // string
    int usb_media_access_enabled; //boolean
    char *intercom_id_verify_secret; // string
    char *fvp_secret; // string

    int _library_owned; // Is the library responsible for freeing this object?
} cluster_config_coordinator_config_t;

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
);

void cluster_config_coordinator_config_free(cluster_config_coordinator_config_t *cluster_config_coordinator_config);

cluster_config_coordinator_config_t *cluster_config_coordinator_config_parseFromJSON(cJSON *cluster_config_coordinator_configJSON);

cJSON *cluster_config_coordinator_config_convertToJSON(cluster_config_coordinator_config_t *cluster_config_coordinator_config);

#endif /* _cluster_config_coordinator_config_H_ */

