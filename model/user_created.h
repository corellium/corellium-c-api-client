/*
 * user_created.h
 *
 * 
 */

#ifndef _user_created_H_
#define _user_created_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct user_created_t user_created_t;




typedef struct user_created_t {
    char *id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} user_created_t;

__attribute__((deprecated)) user_created_t *user_created_create(
    char *id
);

void user_created_free(user_created_t *user_created);

user_created_t *user_created_parseFromJSON(cJSON *user_createdJSON);

cJSON *user_created_convertToJSON(user_created_t *user_created);

#endif /* _user_created_H_ */

