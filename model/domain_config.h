/*
 * domain_config.h
 *
 * Domain configuration.
 */

#ifndef _domain_config_H_
#define _domain_config_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct domain_config_t domain_config_t;

#include "domain_config_trial.h"
#include "domain_config_webplayer.h"
#include "login_result_domain_snapshot_sharing_permissions.h"



typedef struct domain_config_t {
    int android; //boolean
    int billing; //boolean
    char *license_type; // string
    char *signup_email; // string
    struct domain_config_trial_t *trial; //model
    int usage_based; //boolean
    int enable_netgear_devices; //boolean
    int no_ios; //boolean
    int enable_amazon_devices; //boolean
    int device_dhcp_server; //boolean
    int enable_arm_devices; //boolean
    int enable_devices; //boolean
    struct domain_config_webplayer_t *webplayer; //model
    struct login_result_domain_snapshot_sharing_permissions_t *snapshot_sharing_permissions; //model

    int _library_owned; // Is the library responsible for freeing this object?
} domain_config_t;

__attribute__((deprecated)) domain_config_t *domain_config_create(
    int android,
    int billing,
    char *license_type,
    char *signup_email,
    domain_config_trial_t *trial,
    int usage_based,
    int enable_netgear_devices,
    int no_ios,
    int enable_amazon_devices,
    int device_dhcp_server,
    int enable_arm_devices,
    int enable_devices,
    domain_config_webplayer_t *webplayer,
    login_result_domain_snapshot_sharing_permissions_t *snapshot_sharing_permissions
);

void domain_config_free(domain_config_t *domain_config);

domain_config_t *domain_config_parseFromJSON(cJSON *domain_configJSON);

cJSON *domain_config_convertToJSON(domain_config_t *domain_config);

#endif /* _domain_config_H_ */

