/*
 * update_own_profile_body.h
 *
 * 
 */

#ifndef _update_own_profile_body_H_
#define _update_own_profile_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct update_own_profile_body_t update_own_profile_body_t;




typedef struct update_own_profile_body_t {
    char *label; // string

    int _library_owned; // Is the library responsible for freeing this object?
} update_own_profile_body_t;

__attribute__((deprecated)) update_own_profile_body_t *update_own_profile_body_create(
    char *label
);

void update_own_profile_body_free(update_own_profile_body_t *update_own_profile_body);

update_own_profile_body_t *update_own_profile_body_parseFromJSON(cJSON *update_own_profile_bodyJSON);

cJSON *update_own_profile_body_convertToJSON(update_own_profile_body_t *update_own_profile_body);

#endif /* _update_own_profile_body_H_ */

