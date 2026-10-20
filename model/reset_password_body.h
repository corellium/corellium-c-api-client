/*
 * reset_password_body.h
 *
 * 
 */

#ifndef _reset_password_body_H_
#define _reset_password_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct reset_password_body_t reset_password_body_t;




typedef struct reset_password_body_t {
    char *token; // string
    char *new_password; // string
    char *totp_token; // string

    int _library_owned; // Is the library responsible for freeing this object?
} reset_password_body_t;

__attribute__((deprecated)) reset_password_body_t *reset_password_body_create(
    char *token,
    char *new_password,
    char *totp_token
);

void reset_password_body_free(reset_password_body_t *reset_password_body);

reset_password_body_t *reset_password_body_parseFromJSON(cJSON *reset_password_bodyJSON);

cJSON *reset_password_body_convertToJSON(reset_password_body_t *reset_password_body);

#endif /* _reset_password_body_H_ */

