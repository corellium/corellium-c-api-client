/*
 * invite_signup_body.h
 *
 * 
 */

#ifndef _invite_signup_body_H_
#define _invite_signup_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct invite_signup_body_t invite_signup_body_t;

#include "invite_signup_body_params.h"



typedef struct invite_signup_body_t {
    char *invite_token; // string
    struct invite_signup_body_params_t *params; //model

    int _library_owned; // Is the library responsible for freeing this object?
} invite_signup_body_t;

__attribute__((deprecated)) invite_signup_body_t *invite_signup_body_create(
    char *invite_token,
    invite_signup_body_params_t *params
);

void invite_signup_body_free(invite_signup_body_t *invite_signup_body);

invite_signup_body_t *invite_signup_body_parseFromJSON(cJSON *invite_signup_bodyJSON);

cJSON *invite_signup_body_convertToJSON(invite_signup_body_t *invite_signup_body);

#endif /* _invite_signup_body_H_ */

