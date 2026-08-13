/*
 * team_created.h
 *
 * 
 */

#ifndef _team_created_H_
#define _team_created_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct team_created_t team_created_t;




typedef struct team_created_t {
    char *id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} team_created_t;

__attribute__((deprecated)) team_created_t *team_created_create(
    char *id
);

void team_created_free(team_created_t *team_created);

team_created_t *team_created_parseFromJSON(cJSON *team_createdJSON);

cJSON *team_created_convertToJSON(team_created_t *team_created);

#endif /* _team_created_H_ */

