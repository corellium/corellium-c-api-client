/*
 * config_response_v1.h
 *
 * 
 */

#ifndef _config_response_v1_H_
#define _config_response_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct config_response_v1_t config_response_v1_t;

#include "any_type.h"
#include "auth_provider_v1.h"
#include "coordinator_config_v1.h"
#include "logging_v1.h"
#include "object.h"
#include "trial_v1.h"



typedef struct config_response_v1_t {
    int on_site; //boolean
    list_t *network_types; //primitive container
    char *network_type; // string
    int show_domain_settings; //boolean
    char *version; // string
    int invalid_build; //boolean
    int sep_sim; //boolean
    int installer_available; //boolean
    char *invoiced_publishable_key; // string
    char *stripe_public_key; // string
    char *intercom_id; // string
    char *aux_webhook; // string
    char *gtm_id; // string
    char *zapier_feedback_webhook; // string
    char *zapier_bugs_webhook; // string
    char *billing_backend; // string
    object_t *maintenance; //object
    struct logging_v1_t *logging; //model
    char *cloud_admin; // string
    char *files_admin; // string
    char *cloud_domain; // string
    char *billing_domain; // string
    char *app_domain; // string
    char *max_network_monitor_file_size; // string
    int enable_firmware_image_upload; //boolean
    list_t *auth_providers; //nonprimitive container
    double snapshot_limit; //numeric
    double max_kernel_size; //numeric
    double max_ramdisk_size; //numeric
    int charm_sdk; //boolean
    struct trial_v1_t *trial; //model
    char *sentry_url; // string
    int domain_authentication_providers; //boolean
    char *default_ssid; // string
    struct coordinator_config_v1_t *coordinator_config; //model

    int _library_owned; // Is the library responsible for freeing this object?
} config_response_v1_t;

__attribute__((deprecated)) config_response_v1_t *config_response_v1_create(
    int on_site,
    list_t *network_types,
    char *network_type,
    int show_domain_settings,
    char *version,
    int invalid_build,
    int sep_sim,
    int installer_available,
    char *invoiced_publishable_key,
    char *stripe_public_key,
    char *intercom_id,
    char *aux_webhook,
    char *gtm_id,
    char *zapier_feedback_webhook,
    char *zapier_bugs_webhook,
    char *billing_backend,
    object_t *maintenance,
    logging_v1_t *logging,
    char *cloud_admin,
    char *files_admin,
    char *cloud_domain,
    char *billing_domain,
    char *app_domain,
    char *max_network_monitor_file_size,
    int enable_firmware_image_upload,
    list_t *auth_providers,
    double snapshot_limit,
    double max_kernel_size,
    double max_ramdisk_size,
    int charm_sdk,
    trial_v1_t *trial,
    char *sentry_url,
    int domain_authentication_providers,
    char *default_ssid,
    coordinator_config_v1_t *coordinator_config
);

void config_response_v1_free(config_response_v1_t *config_response_v1);

config_response_v1_t *config_response_v1_parseFromJSON(cJSON *config_response_v1JSON);

cJSON *config_response_v1_convertToJSON(config_response_v1_t *config_response_v1);

#endif /* _config_response_v1_H_ */

