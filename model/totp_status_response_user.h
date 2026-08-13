/*
 * totp_status_response_user.h
 *
 * Authenticated user context.
 */

#ifndef _totp_status_response_user_H_
#define _totp_status_response_user_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct totp_status_response_user_t totp_status_response_user_t;




typedef struct totp_status_response_user_t {
    char *id; // string
    char *name; // string
    char *label; // string
    char *email; // string

    int _library_owned; // Is the library responsible for freeing this object?
} totp_status_response_user_t;

__attribute__((deprecated)) totp_status_response_user_t *totp_status_response_user_create(
    char *id,
    char *name,
    char *label,
    char *email
);

void totp_status_response_user_free(totp_status_response_user_t *totp_status_response_user);

totp_status_response_user_t *totp_status_response_user_parseFromJSON(cJSON *totp_status_response_userJSON);

cJSON *totp_status_response_user_convertToJSON(totp_status_response_user_t *totp_status_response_user);

#endif /* _totp_status_response_user_H_ */

