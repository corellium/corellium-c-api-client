/*
 * create_invites_body_settings.h
 *
 * 
 */

#ifndef _create_invites_body_settings_H_
#define _create_invites_body_settings_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_invites_body_settings_t create_invites_body_settings_t;




typedef struct create_invites_body_settings_t {
    list_t *teams; //primitive container
    list_t *projects; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} create_invites_body_settings_t;

__attribute__((deprecated)) create_invites_body_settings_t *create_invites_body_settings_create(
    list_t *teams,
    list_t *projects
);

void create_invites_body_settings_free(create_invites_body_settings_t *create_invites_body_settings);

create_invites_body_settings_t *create_invites_body_settings_parseFromJSON(cJSON *create_invites_body_settingsJSON);

cJSON *create_invites_body_settings_convertToJSON(create_invites_body_settings_t *create_invites_body_settings);

#endif /* _create_invites_body_settings_H_ */

