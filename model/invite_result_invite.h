/*
 * invite_result_invite.h
 *
 * 
 */

#ifndef _invite_result_invite_H_
#define _invite_result_invite_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct invite_result_invite_t invite_result_invite_t;

#include "invite_settings.h"



typedef struct invite_result_invite_t {
    char *id; // string
    char *email; // string
    struct invite_settings_t *settings; //model

    int _library_owned; // Is the library responsible for freeing this object?
} invite_result_invite_t;

__attribute__((deprecated)) invite_result_invite_t *invite_result_invite_create(
    char *id,
    char *email,
    invite_settings_t *settings
);

void invite_result_invite_free(invite_result_invite_t *invite_result_invite);

invite_result_invite_t *invite_result_invite_parseFromJSON(cJSON *invite_result_inviteJSON);

cJSON *invite_result_invite_convertToJSON(invite_result_invite_t *invite_result_invite);

#endif /* _invite_result_invite_H_ */

