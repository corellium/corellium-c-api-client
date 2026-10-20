/*
 * role.h
 *
 * 
 */

#ifndef _role_H_
#define _role_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct role_t role_t;

#include "role_name.h"



typedef struct role_t {
    corellium_api_role_name__e role; //referenced enum
    char *project; // string
    char *deployment; // string
    char *user; // string
    char *team; // string

    int _library_owned; // Is the library responsible for freeing this object?
} role_t;

__attribute__((deprecated)) role_t *role_create(
    corellium_api_role_name__e role,
    char *project,
    char *deployment,
    char *user,
    char *team
);

void role_free(role_t *role);

role_t *role_parseFromJSON(cJSON *roleJSON);

cJSON *role_convertToJSON(role_t *role);

#endif /* _role_H_ */

