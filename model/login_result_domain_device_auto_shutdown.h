/*
 * login_result_domain_device_auto_shutdown.h
 *
 * Automatic device shutdown configuration.
 */

#ifndef _login_result_domain_device_auto_shutdown_H_
#define _login_result_domain_device_auto_shutdown_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct login_result_domain_device_auto_shutdown_t login_result_domain_device_auto_shutdown_t;




typedef struct login_result_domain_device_auto_shutdown_t {
    int enabled; //boolean
    double threshold; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} login_result_domain_device_auto_shutdown_t;

__attribute__((deprecated)) login_result_domain_device_auto_shutdown_t *login_result_domain_device_auto_shutdown_create(
    int enabled,
    double threshold
);

void login_result_domain_device_auto_shutdown_free(login_result_domain_device_auto_shutdown_t *login_result_domain_device_auto_shutdown);

login_result_domain_device_auto_shutdown_t *login_result_domain_device_auto_shutdown_parseFromJSON(cJSON *login_result_domain_device_auto_shutdownJSON);

cJSON *login_result_domain_device_auto_shutdown_convertToJSON(login_result_domain_device_auto_shutdown_t *login_result_domain_device_auto_shutdown);

#endif /* _login_result_domain_device_auto_shutdown_H_ */

