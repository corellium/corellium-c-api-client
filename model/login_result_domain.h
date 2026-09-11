/*
 * login_result_domain.h
 *
 * The session&#39;s domain, including its feature configuration.
 */

#ifndef _login_result_domain_H_
#define _login_result_domain_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct login_result_domain_t login_result_domain_t;

#include "any_type.h"
#include "login_result_domain_device_auto_shutdown.h"
#include "login_result_domain_disabled.h"
#include "login_result_domain_snapshot_sharing_permissions.h"
#include "login_result_domain_trial.h"
#include "login_result_domain_webplayer.h"
#include "object.h"



typedef struct login_result_domain_t {
    char *name; // string
    char *label; // string
    char *terms_policy; // string
    double cores; //numeric
    int individual; //boolean
    int totp_required; //boolean
    object_t *subscription; //object
    char *license_type; // string
    int android; //boolean
    int no_ios; //boolean
    int files_only; //boolean
    int device_dhcp_server; //boolean
    int enable_arm_devices; //boolean
    int use_device_accounting; //boolean
    int single_project; //boolean
    char *terms_updated; // string
    struct login_result_domain_trial_t *trial; //model
    struct login_result_domain_webplayer_t *webplayer; //model
    struct login_result_domain_snapshot_sharing_permissions_t *snapshot_sharing_permissions; //model
    struct login_result_domain_device_auto_shutdown_t *device_auto_shutdown; //model
    struct login_result_domain_disabled_t *disabled; //model

    int _library_owned; // Is the library responsible for freeing this object?
} login_result_domain_t;

__attribute__((deprecated)) login_result_domain_t *login_result_domain_create(
    char *name,
    char *label,
    char *terms_policy,
    double cores,
    int individual,
    int totp_required,
    object_t *subscription,
    char *license_type,
    int android,
    int no_ios,
    int files_only,
    int device_dhcp_server,
    int enable_arm_devices,
    int use_device_accounting,
    int single_project,
    char *terms_updated,
    login_result_domain_trial_t *trial,
    login_result_domain_webplayer_t *webplayer,
    login_result_domain_snapshot_sharing_permissions_t *snapshot_sharing_permissions,
    login_result_domain_device_auto_shutdown_t *device_auto_shutdown,
    login_result_domain_disabled_t *disabled
);

void login_result_domain_free(login_result_domain_t *login_result_domain);

login_result_domain_t *login_result_domain_parseFromJSON(cJSON *login_result_domainJSON);

cJSON *login_result_domain_convertToJSON(login_result_domain_t *login_result_domain);

#endif /* _login_result_domain_H_ */

