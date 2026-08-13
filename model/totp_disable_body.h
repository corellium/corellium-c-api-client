/*
 * totp_disable_body.h
 *
 * 
 */

#ifndef _totp_disable_body_H_
#define _totp_disable_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct totp_disable_body_t totp_disable_body_t;




typedef struct totp_disable_body_t {
    char *totp_token; // string
    char *password; // string

    int _library_owned; // Is the library responsible for freeing this object?
} totp_disable_body_t;

__attribute__((deprecated)) totp_disable_body_t *totp_disable_body_create(
    char *totp_token,
    char *password
);

void totp_disable_body_free(totp_disable_body_t *totp_disable_body);

totp_disable_body_t *totp_disable_body_parseFromJSON(cJSON *totp_disable_bodyJSON);

cJSON *totp_disable_body_convertToJSON(totp_disable_body_t *totp_disable_body);

#endif /* _totp_disable_body_H_ */

