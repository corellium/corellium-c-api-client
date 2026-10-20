/*
 * domain_config_input.h
 *
 * Domain configuration input (allows additional vendor device flags).
 */

#ifndef _domain_config_input_H_
#define _domain_config_input_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct domain_config_input_t domain_config_input_t;

#include "domain_config_input_snapshot_sharing_permissions.h"
#include "domain_config_input_trial.h"
#include "domain_config_input_webplayer.h"



typedef struct domain_config_input_t {
    int android; //boolean
    int billing; //boolean
    char *organization_name; // string
    char *license_type; // string
    char *signup_email; // string
    char *coupon_code; // string
    struct domain_config_input_trial_t *trial; //model
    int no_ios; //boolean
    int device_dhcp_server; //boolean
    int files; //boolean
    int files_only; //boolean
    int remote_gpu; //boolean
    list_t *prioritized_nodes; //primitive container
    int enable_netgear_devices; //boolean
    int enable_amazon_devices; //boolean
    int enable_arm_devices; //boolean
    int enable_devices; //boolean
    struct domain_config_input_webplayer_t *webplayer; //model
    struct domain_config_input_snapshot_sharing_permissions_t *snapshot_sharing_permissions; //model

    int _library_owned; // Is the library responsible for freeing this object?
} domain_config_input_t;

__attribute__((deprecated)) domain_config_input_t *domain_config_input_create(
    int android,
    int billing,
    char *organization_name,
    char *license_type,
    char *signup_email,
    char *coupon_code,
    domain_config_input_trial_t *trial,
    int no_ios,
    int device_dhcp_server,
    int files,
    int files_only,
    int remote_gpu,
    list_t *prioritized_nodes,
    int enable_netgear_devices,
    int enable_amazon_devices,
    int enable_arm_devices,
    int enable_devices,
    domain_config_input_webplayer_t *webplayer,
    domain_config_input_snapshot_sharing_permissions_t *snapshot_sharing_permissions
);

void domain_config_input_free(domain_config_input_t *domain_config_input);

domain_config_input_t *domain_config_input_parseFromJSON(cJSON *domain_config_inputJSON);

cJSON *domain_config_input_convertToJSON(domain_config_input_t *domain_config_input);

#endif /* _domain_config_input_H_ */

