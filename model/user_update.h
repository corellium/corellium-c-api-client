/*
 * user_update.h
 *
 * 
 */

#ifndef _user_update_H_
#define _user_update_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct user_update_t user_update_t;




typedef struct user_update_t {
    char *name; // string
    char *label; // string

    int _library_owned; // Is the library responsible for freeing this object?
} user_update_t;

__attribute__((deprecated)) user_update_t *user_update_create(
    char *name,
    char *label
);

void user_update_free(user_update_t *user_update);

user_update_t *user_update_parseFromJSON(cJSON *user_updateJSON);

cJSON *user_update_convertToJSON(user_update_t *user_update);

#endif /* _user_update_H_ */

