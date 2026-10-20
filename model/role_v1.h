/*
 * role_v1.h
 *
 * 
 */

#ifndef _role_v1_H_
#define _role_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct role_v1_t role_v1_t;


// Enum ROLE for role_v1

typedef enum  { corellium_api_role_v1_ROLE_NULL = 0, corellium_api_role_v1_ROLE_admin, corellium_api_role_v1_ROLE__member_ } corellium_api_role_v1_ROLE_e;

char* role_v1_role_ToString(corellium_api_role_v1_ROLE_e role);

corellium_api_role_v1_ROLE_e role_v1_role_FromString(char* role);



typedef struct role_v1_t {
    corellium_api_role_v1_ROLE_e role; //enum
    char *project; // string
    char *user; // string
    char *team; // string

    int _library_owned; // Is the library responsible for freeing this object?
} role_v1_t;

__attribute__((deprecated)) role_v1_t *role_v1_create(
    corellium_api_role_v1_ROLE_e role,
    char *project,
    char *user,
    char *team
);

void role_v1_free(role_v1_t *role_v1);

role_v1_t *role_v1_parseFromJSON(cJSON *role_v1JSON);

cJSON *role_v1_convertToJSON(role_v1_t *role_v1);

#endif /* _role_v1_H_ */

