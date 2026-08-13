/*
 * login_body.h
 *
 * 
 */

#ifndef _login_body_H_
#define _login_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct login_body_t login_body_t;




typedef struct login_body_t {
    char *username; // string
    char *password; // string
    char *totp_token; // string
    char *api_token; // string
    char *token; // string
    int revoke_old; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} login_body_t;

__attribute__((deprecated)) login_body_t *login_body_create(
    char *username,
    char *password,
    char *totp_token,
    char *api_token,
    char *token,
    int revoke_old
);

void login_body_free(login_body_t *login_body);

login_body_t *login_body_parseFromJSON(cJSON *login_bodyJSON);

cJSON *login_body_convertToJSON(login_body_t *login_body);

#endif /* _login_body_H_ */

