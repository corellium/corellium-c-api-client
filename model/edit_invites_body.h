/*
 * edit_invites_body.h
 *
 * 
 */

#ifndef _edit_invites_body_H_
#define _edit_invites_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct edit_invites_body_t edit_invites_body_t;

#include "edit_invites_body_changes.h"



typedef struct edit_invites_body_t {
    list_t *ids; //primitive container
    struct edit_invites_body_changes_t *changes; //model

    int _library_owned; // Is the library responsible for freeing this object?
} edit_invites_body_t;

__attribute__((deprecated)) edit_invites_body_t *edit_invites_body_create(
    list_t *ids,
    edit_invites_body_changes_t *changes
);

void edit_invites_body_free(edit_invites_body_t *edit_invites_body);

edit_invites_body_t *edit_invites_body_parseFromJSON(cJSON *edit_invites_bodyJSON);

cJSON *edit_invites_body_convertToJSON(edit_invites_body_t *edit_invites_body);

#endif /* _edit_invites_body_H_ */

