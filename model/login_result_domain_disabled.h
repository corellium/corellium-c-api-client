/*
 * login_result_domain_disabled.h
 *
 * Disable details carried in the domain configuration. See the top-level &#x60;disabled&#x60; field.
 */

#ifndef _login_result_domain_disabled_H_
#define _login_result_domain_disabled_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct login_result_domain_disabled_t login_result_domain_disabled_t;




typedef struct login_result_domain_disabled_t {
    char *type; // string
    char *cancel_date; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} login_result_domain_disabled_t;

__attribute__((deprecated)) login_result_domain_disabled_t *login_result_domain_disabled_create(
    char *type,
    char *cancel_date
);

void login_result_domain_disabled_free(login_result_domain_disabled_t *login_result_domain_disabled);

login_result_domain_disabled_t *login_result_domain_disabled_parseFromJSON(cJSON *login_result_domain_disabledJSON);

cJSON *login_result_domain_disabled_convertToJSON(login_result_domain_disabled_t *login_result_domain_disabled);

#endif /* _login_result_domain_disabled_H_ */

