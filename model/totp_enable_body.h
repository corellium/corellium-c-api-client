/*
 * totp_enable_body.h
 *
 * 
 */

#ifndef _totp_enable_body_H_
#define _totp_enable_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct totp_enable_body_t totp_enable_body_t;




typedef struct totp_enable_body_t {
    char *secret; // string
    char *totp_token; // string
    char *password; // string

    int _library_owned; // Is the library responsible for freeing this object?
} totp_enable_body_t;

__attribute__((deprecated)) totp_enable_body_t *totp_enable_body_create(
    char *secret,
    char *totp_token,
    char *password
);

void totp_enable_body_free(totp_enable_body_t *totp_enable_body);

totp_enable_body_t *totp_enable_body_parseFromJSON(cJSON *totp_enable_bodyJSON);

cJSON *totp_enable_body_convertToJSON(totp_enable_body_t *totp_enable_body);

#endif /* _totp_enable_body_H_ */

