/*
 * token_v1.h
 *
 * 
 */

#ifndef _token_v1_H_
#define _token_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct token_v1_t token_v1_t;




typedef struct token_v1_t {
    char *token; // string

    int _library_owned; // Is the library responsible for freeing this object?
} token_v1_t;

__attribute__((deprecated)) token_v1_t *token_v1_create(
    char *token
);

void token_v1_free(token_v1_t *token_v1);

token_v1_t *token_v1_parseFromJSON(cJSON *token_v1JSON);

cJSON *token_v1_convertToJSON(token_v1_t *token_v1);

#endif /* _token_v1_H_ */

