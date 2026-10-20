/*
 * login_result.h
 *
 * 
 */

#ifndef _login_result_H_
#define _login_result_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct login_result_t login_result_t;

#include "login_result_disabled.h"
#include "login_result_domain.h"
#include "login_result_user.h"



typedef struct login_result_t {
    char *token; // string
    char *expiration; //date time
    struct login_result_user_t *user; //model
    struct login_result_domain_t *domain; //model
    double time; //numeric
    char *identifier; // string
    struct login_result_disabled_t *disabled; //model
    int missing_totp; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} login_result_t;

__attribute__((deprecated)) login_result_t *login_result_create(
    char *token,
    char *expiration,
    login_result_user_t *user,
    login_result_domain_t *domain,
    double time,
    char *identifier,
    login_result_disabled_t *disabled,
    int missing_totp
);

void login_result_free(login_result_t *login_result);

login_result_t *login_result_parseFromJSON(cJSON *login_resultJSON);

cJSON *login_result_convertToJSON(login_result_t *login_result);

#endif /* _login_result_H_ */

