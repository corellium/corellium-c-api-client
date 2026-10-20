/*
 * create_team_body.h
 *
 * 
 */

#ifndef _create_team_body_H_
#define _create_team_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_team_body_t create_team_body_t;




typedef struct create_team_body_t {
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} create_team_body_t;

__attribute__((deprecated)) create_team_body_t *create_team_body_create(
    char *name
);

void create_team_body_free(create_team_body_t *create_team_body);

create_team_body_t *create_team_body_parseFromJSON(cJSON *create_team_bodyJSON);

cJSON *create_team_body_convertToJSON(create_team_body_t *create_team_body);

#endif /* _create_team_body_H_ */

