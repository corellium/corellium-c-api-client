/*
 * edit_invites_body_changes.h
 *
 * Changes to apply to the invites.
 */

#ifndef _edit_invites_body_changes_H_
#define _edit_invites_body_changes_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct edit_invites_body_changes_t edit_invites_body_changes_t;

#include "invite_settings.h"



typedef struct edit_invites_body_changes_t {
    struct invite_settings_t *settings; //model

    int _library_owned; // Is the library responsible for freeing this object?
} edit_invites_body_changes_t;

__attribute__((deprecated)) edit_invites_body_changes_t *edit_invites_body_changes_create(
    invite_settings_t *settings
);

void edit_invites_body_changes_free(edit_invites_body_changes_t *edit_invites_body_changes);

edit_invites_body_changes_t *edit_invites_body_changes_parseFromJSON(cJSON *edit_invites_body_changesJSON);

cJSON *edit_invites_body_changes_convertToJSON(edit_invites_body_changes_t *edit_invites_body_changes);

#endif /* _edit_invites_body_changes_H_ */

