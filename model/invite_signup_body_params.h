/*
 * invite_signup_body_params.h
 *
 * New account parameters.
 */

#ifndef _invite_signup_body_params_H_
#define _invite_signup_body_params_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct invite_signup_body_params_t invite_signup_body_params_t;




typedef struct invite_signup_body_params_t {
    char *email; // string
    char *password; // string
    char *label; // string
    int agreed; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} invite_signup_body_params_t;

__attribute__((deprecated)) invite_signup_body_params_t *invite_signup_body_params_create(
    char *email,
    char *password,
    char *label,
    int agreed
);

void invite_signup_body_params_free(invite_signup_body_params_t *invite_signup_body_params);

invite_signup_body_params_t *invite_signup_body_params_parseFromJSON(cJSON *invite_signup_body_paramsJSON);

cJSON *invite_signup_body_params_convertToJSON(invite_signup_body_params_t *invite_signup_body_params);

#endif /* _invite_signup_body_params_H_ */

