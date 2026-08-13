/*
 * change_password_body.h
 *
 * 
 */

#ifndef _change_password_body_H_
#define _change_password_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct change_password_body_t change_password_body_t;




typedef struct change_password_body_t {
    char *user; // string
    char *old_password; // string
    char *new_password; // string

    int _library_owned; // Is the library responsible for freeing this object?
} change_password_body_t;

__attribute__((deprecated)) change_password_body_t *change_password_body_create(
    char *user,
    char *old_password,
    char *new_password
);

void change_password_body_free(change_password_body_t *change_password_body);

change_password_body_t *change_password_body_parseFromJSON(cJSON *change_password_bodyJSON);

cJSON *change_password_body_convertToJSON(change_password_body_t *change_password_body);

#endif /* _change_password_body_H_ */

