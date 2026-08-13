/*
 * revoke_invites_response.h
 *
 * 
 */

#ifndef _revoke_invites_response_H_
#define _revoke_invites_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct revoke_invites_response_t revoke_invites_response_t;




typedef struct revoke_invites_response_t {
    double deleted_count; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} revoke_invites_response_t;

__attribute__((deprecated)) revoke_invites_response_t *revoke_invites_response_create(
    double deleted_count
);

void revoke_invites_response_free(revoke_invites_response_t *revoke_invites_response);

revoke_invites_response_t *revoke_invites_response_parseFromJSON(cJSON *revoke_invites_responseJSON);

cJSON *revoke_invites_response_convertToJSON(revoke_invites_response_t *revoke_invites_response);

#endif /* _revoke_invites_response_H_ */

