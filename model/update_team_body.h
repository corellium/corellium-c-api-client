/*
 * update_team_body.h
 *
 * 
 */

#ifndef _update_team_body_H_
#define _update_team_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct update_team_body_t update_team_body_t;




typedef struct update_team_body_t {
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} update_team_body_t;

__attribute__((deprecated)) update_team_body_t *update_team_body_create(
    char *name
);

void update_team_body_free(update_team_body_t *update_team_body);

update_team_body_t *update_team_body_parseFromJSON(cJSON *update_team_bodyJSON);

cJSON *update_team_body_convertToJSON(update_team_body_t *update_team_body);

#endif /* _update_team_body_H_ */

