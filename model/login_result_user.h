/*
 * login_result_user.h
 *
 * The authenticated user. Absent on a Webplayer token renewal.
 */

#ifndef _login_result_user_H_
#define _login_result_user_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct login_result_user_t login_result_user_t;

#include "any_type.h"
#include "object.h"



typedef struct login_result_user_t {
    char *id; // string
    char *name; // string
    char *label; // string
    char *email; // string
    int cluster_administrator; //boolean
    char *agreed_to_terms; // string
    char *federated_user_id; // string
    char *intercom_hmac; // string
    object_t *misc; //object

    int _library_owned; // Is the library responsible for freeing this object?
} login_result_user_t;

__attribute__((deprecated)) login_result_user_t *login_result_user_create(
    char *id,
    char *name,
    char *label,
    char *email,
    int cluster_administrator,
    char *agreed_to_terms,
    char *federated_user_id,
    char *intercom_hmac,
    object_t *misc
);

void login_result_user_free(login_result_user_t *login_result_user);

login_result_user_t *login_result_user_parseFromJSON(cJSON *login_result_userJSON);

cJSON *login_result_user_convertToJSON(login_result_user_t *login_result_user);

#endif /* _login_result_user_H_ */

