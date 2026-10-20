/*
 * invites_list_response.h
 *
 * 
 */

#ifndef _invites_list_response_H_
#define _invites_list_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct invites_list_response_t invites_list_response_t;

#include "invitation.h"



typedef struct invites_list_response_t {
    list_t *results; //nonprimitive container
    double count; //numeric
    double total; //numeric
    double limit; //numeric
    double offset; //numeric
    int has_more; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} invites_list_response_t;

__attribute__((deprecated)) invites_list_response_t *invites_list_response_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
);

void invites_list_response_free(invites_list_response_t *invites_list_response);

invites_list_response_t *invites_list_response_parseFromJSON(cJSON *invites_list_responseJSON);

cJSON *invites_list_response_convertToJSON(invites_list_response_t *invites_list_response);

#endif /* _invites_list_response_H_ */

