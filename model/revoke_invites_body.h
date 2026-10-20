/*
 * revoke_invites_body.h
 *
 * 
 */

#ifndef _revoke_invites_body_H_
#define _revoke_invites_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct revoke_invites_body_t revoke_invites_body_t;




typedef struct revoke_invites_body_t {
    list_t *ids; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} revoke_invites_body_t;

__attribute__((deprecated)) revoke_invites_body_t *revoke_invites_body_create(
    list_t *ids
);

void revoke_invites_body_free(revoke_invites_body_t *revoke_invites_body);

revoke_invites_body_t *revoke_invites_body_parseFromJSON(cJSON *revoke_invites_bodyJSON);

cJSON *revoke_invites_body_convertToJSON(revoke_invites_body_t *revoke_invites_body);

#endif /* _revoke_invites_body_H_ */

