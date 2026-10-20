/*
 * user_create_return.h
 *
 * 
 */

#ifndef _user_create_return_H_
#define _user_create_return_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct user_create_return_t user_create_return_t;




typedef struct user_create_return_t {
    char *id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} user_create_return_t;

__attribute__((deprecated)) user_create_return_t *user_create_return_create(
    char *id
);

void user_create_return_free(user_create_return_t *user_create_return);

user_create_return_t *user_create_return_parseFromJSON(cJSON *user_create_returnJSON);

cJSON *user_create_return_convertToJSON(user_create_return_t *user_create_return);

#endif /* _user_create_return_H_ */

