/*
 * get_invite_by_token_body.h
 *
 * 
 */

#ifndef _get_invite_by_token_body_H_
#define _get_invite_by_token_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_invite_by_token_body_t get_invite_by_token_body_t;




typedef struct get_invite_by_token_body_t {
    char *token; // string

    int _library_owned; // Is the library responsible for freeing this object?
} get_invite_by_token_body_t;

__attribute__((deprecated)) get_invite_by_token_body_t *get_invite_by_token_body_create(
    char *token
);

void get_invite_by_token_body_free(get_invite_by_token_body_t *get_invite_by_token_body);

get_invite_by_token_body_t *get_invite_by_token_body_parseFromJSON(cJSON *get_invite_by_token_bodyJSON);

cJSON *get_invite_by_token_body_convertToJSON(get_invite_by_token_body_t *get_invite_by_token_body);

#endif /* _get_invite_by_token_body_H_ */

