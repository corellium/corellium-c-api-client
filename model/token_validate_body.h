/*
 * token_validate_body.h
 *
 * 
 */

#ifndef _token_validate_body_H_
#define _token_validate_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct token_validate_body_t token_validate_body_t;




typedef struct token_validate_body_t {
    char *token; // string

    int _library_owned; // Is the library responsible for freeing this object?
} token_validate_body_t;

__attribute__((deprecated)) token_validate_body_t *token_validate_body_create(
    char *token
);

void token_validate_body_free(token_validate_body_t *token_validate_body);

token_validate_body_t *token_validate_body_parseFromJSON(cJSON *token_validate_bodyJSON);

cJSON *token_validate_body_convertToJSON(token_validate_body_t *token_validate_body);

#endif /* _token_validate_body_H_ */

