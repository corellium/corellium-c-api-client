/*
 * create_user_body.h
 *
 * 
 */

#ifndef _create_user_body_H_
#define _create_user_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_user_body_t create_user_body_t;




typedef struct create_user_body_t {
    char *password; // string
    int administrator; //boolean
    char *name; // string
    char *label; // string
    char *email; // string
    int cluster_administrator; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} create_user_body_t;

__attribute__((deprecated)) create_user_body_t *create_user_body_create(
    char *password,
    int administrator,
    char *name,
    char *label,
    char *email,
    int cluster_administrator
);

void create_user_body_free(create_user_body_t *create_user_body);

create_user_body_t *create_user_body_parseFromJSON(cJSON *create_user_bodyJSON);

cJSON *create_user_body_convertToJSON(create_user_body_t *create_user_body);

#endif /* _create_user_body_H_ */

