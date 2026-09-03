/*
 * config_response.h
 *
 * Cluster configuration. Build-time feature flags may add further boolean properties beyond those listed.
 */

#ifndef _config_response_H_
#define _config_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct config_response_t config_response_t;

#include "config_auth_provider.h"
#include "config_response_ai_tools_config.h"
#include "config_response_coordinator_config.h"
#include "config_response_maintenance.h"
#include "logging.h"
#include "trial.h"

// Enum NETWORKTYPE for config_response

typedef enum  { corellium_api_config_response_NETWORKTYPE_NULL = 0, corellium_api_config_response_NETWORKTYPE_bridged, corellium_api_config_response_NETWORKTYPE_nat, corellium_api_config_response_NETWORKTYPE_routed } corellium_api_config_response_NETWORKTYPE_e;

char* config_response_network_type_ToString(corellium_api_config_response_NETWORKTYPE_e network_type);

corellium_api_config_response_NETWORKTYPE_e config_response_network_type_FromString(char* network_type);



typedef struct config_response_t {
    int on_site; //boolean
    list_t *network_types; //primitive container
    corellium_api_config_response_NETWORKTYPE_e network_type; //enum
    int show_domain_settings; //boolean
    char *version; // string
    int invalid_build; //boolean
    int sep_sim; //boolean
    int installer_available; //boolean
    char *invoiced_publishable_key; // string
    char *stripe_public_key; // string
    char *intercom_id; // string
    char *gtm_id; // string
    char *billing_backend; // string
    struct config_response_maintenance_t *maintenance; //model
    struct logging_t *logging; //model
    char *cloud_admin; // string
    char *files_admin; // string
    char *cloud_domain; // string
    char *billing_domain; // string
    char *app_domain; // string
    char *max_network_monitor_file_size; // string
    int enable_firmware_image_upload; //boolean
    list_t *auth_providers; //nonprimitive container
    char *welcome_message; // string
    double snapshot_limit; //numeric
    double max_kernel_size; //numeric
    double max_ramdisk_size; //numeric
    int charm_sdk; //boolean
    struct trial_t *trial; //model
    char *sentry_url; // string
    int domain_authentication_providers; //boolean
    int remote_gpu; //boolean
    char *default_ssid; // string
    int aws_marketplace; //boolean
    char *open_g_apps_binary; // string
    int air_gapped; //boolean
    struct config_response_coordinator_config_t *coordinator_config; //model
    struct config_response_ai_tools_config_t *ai_tools_config; //model

    int _library_owned; // Is the library responsible for freeing this object?
} config_response_t;

__attribute__((deprecated)) config_response_t *config_response_create(
    int on_site,
    list_t *network_types,
    corellium_api_config_response_NETWORKTYPE_e network_type,
    int show_domain_settings,
    char *version,
    int invalid_build,
    int sep_sim,
    int installer_available,
    char *invoiced_publishable_key,
    char *stripe_public_key,
    char *intercom_id,
    char *gtm_id,
    char *billing_backend,
    config_response_maintenance_t *maintenance,
    logging_t *logging,
    char *cloud_admin,
    char *files_admin,
    char *cloud_domain,
    char *billing_domain,
    char *app_domain,
    char *max_network_monitor_file_size,
    int enable_firmware_image_upload,
    list_t *auth_providers,
    char *welcome_message,
    double snapshot_limit,
    double max_kernel_size,
    double max_ramdisk_size,
    int charm_sdk,
    trial_t *trial,
    char *sentry_url,
    int domain_authentication_providers,
    int remote_gpu,
    char *default_ssid,
    int aws_marketplace,
    char *open_g_apps_binary,
    int air_gapped,
    config_response_coordinator_config_t *coordinator_config,
    config_response_ai_tools_config_t *ai_tools_config
);

void config_response_free(config_response_t *config_response);

config_response_t *config_response_parseFromJSON(cJSON *config_responseJSON);

cJSON *config_response_convertToJSON(config_response_t *config_response);

#endif /* _config_response_H_ */

