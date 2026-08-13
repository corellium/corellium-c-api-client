/*
 * team_user.h
 *
 * 
 */

#ifndef _team_user_H_
#define _team_user_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct team_user_t team_user_t;




typedef struct team_user_t {
    char *id; // string
    char *label; // string
    char *name; // string
    char *email; // string
    int administrator; //boolean
    int can_edit_user_attributes; //boolean
    int cluster_administrator; //boolean
    int is_federated_user; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} team_user_t;

__attribute__((deprecated)) team_user_t *team_user_create(
    char *id,
    char *label,
    char *name,
    char *email,
    int administrator,
    int can_edit_user_attributes,
    int cluster_administrator,
    int is_federated_user
);

void team_user_free(team_user_t *team_user);

team_user_t *team_user_parseFromJSON(cJSON *team_userJSON);

cJSON *team_user_convertToJSON(team_user_t *team_user);

#endif /* _team_user_H_ */

