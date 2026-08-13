/*
 * invite_signup_response.h
 *
 * 
 */

#ifndef _invite_signup_response_H_
#define _invite_signup_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct invite_signup_response_t invite_signup_response_t;




typedef struct invite_signup_response_t {
    char *id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} invite_signup_response_t;

__attribute__((deprecated)) invite_signup_response_t *invite_signup_response_create(
    char *id
);

void invite_signup_response_free(invite_signup_response_t *invite_signup_response);

invite_signup_response_t *invite_signup_response_parseFromJSON(cJSON *invite_signup_responseJSON);

cJSON *invite_signup_response_convertToJSON(invite_signup_response_t *invite_signup_response);

#endif /* _invite_signup_response_H_ */

