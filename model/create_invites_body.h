/*
 * create_invites_body.h
 *
 * 
 */

#ifndef _create_invites_body_H_
#define _create_invites_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_invites_body_t create_invites_body_t;

#include "create_invites_body_settings.h"



typedef struct create_invites_body_t {
    list_t *email; //primitive container
    int resend; //boolean
    struct create_invites_body_settings_t *settings; //model

    int _library_owned; // Is the library responsible for freeing this object?
} create_invites_body_t;

__attribute__((deprecated)) create_invites_body_t *create_invites_body_create(
    list_t *email,
    int resend,
    create_invites_body_settings_t *settings
);

void create_invites_body_free(create_invites_body_t *create_invites_body);

create_invites_body_t *create_invites_body_parseFromJSON(cJSON *create_invites_bodyJSON);

cJSON *create_invites_body_convertToJSON(create_invites_body_t *create_invites_body);

#endif /* _create_invites_body_H_ */

