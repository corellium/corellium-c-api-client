/*
 * user_create.h
 *
 * 
 */

#ifndef _user_create_H_
#define _user_create_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct user_create_t user_create_t;




typedef struct user_create_t {
    char *name; // string
    char *label; // string
    char *password; // string
    char *email; // string
    int administrator; //boolean
    int cluster_administrator; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} user_create_t;

__attribute__((deprecated)) user_create_t *user_create_create(
    char *name,
    char *label,
    char *password,
    char *email,
    int administrator,
    int cluster_administrator
);

void user_create_free(user_create_t *user_create);

user_create_t *user_create_parseFromJSON(cJSON *user_createJSON);

cJSON *user_create_convertToJSON(user_create_t *user_create);

#endif /* _user_create_H_ */

