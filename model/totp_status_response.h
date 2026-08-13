/*
 * totp_status_response.h
 *
 * Login result re-issued after the TOTP state change.
 */

#ifndef _totp_status_response_H_
#define _totp_status_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct totp_status_response_t totp_status_response_t;

#include "totp_status_response_domain.h"
#include "totp_status_response_user.h"



typedef struct totp_status_response_t {
    char *token; // string
    double time; //numeric
    struct totp_status_response_user_t *user; //model
    struct totp_status_response_domain_t *domain; //model

    int _library_owned; // Is the library responsible for freeing this object?
} totp_status_response_t;

__attribute__((deprecated)) totp_status_response_t *totp_status_response_create(
    char *token,
    double time,
    totp_status_response_user_t *user,
    totp_status_response_domain_t *domain
);

void totp_status_response_free(totp_status_response_t *totp_status_response);

totp_status_response_t *totp_status_response_parseFromJSON(cJSON *totp_status_responseJSON);

cJSON *totp_status_response_convertToJSON(totp_status_response_t *totp_status_response);

#endif /* _totp_status_response_H_ */

