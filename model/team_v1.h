/*
 * team_v1.h
 *
 * 
 */

#ifndef _team_v1_H_
#define _team_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct team_v1_t team_v1_t;

#include "user.h"



typedef struct team_v1_t {
    char *id; // string
    char *label; // string
    list_t *users; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} team_v1_t;

__attribute__((deprecated)) team_v1_t *team_v1_create(
    char *id,
    char *label,
    list_t *users
);

void team_v1_free(team_v1_t *team_v1);

team_v1_t *team_v1_parseFromJSON(cJSON *team_v1JSON);

cJSON *team_v1_convertToJSON(team_v1_t *team_v1);

#endif /* _team_v1_H_ */

