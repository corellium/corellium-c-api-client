/*
 * invite_settings.h
 *
 * Invite settings.
 */

#ifndef _invite_settings_H_
#define _invite_settings_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct invite_settings_t invite_settings_t;




typedef struct invite_settings_t {
    list_t *teams; //primitive container
    list_t *projects; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} invite_settings_t;

__attribute__((deprecated)) invite_settings_t *invite_settings_create(
    list_t *teams,
    list_t *projects
);

void invite_settings_free(invite_settings_t *invite_settings);

invite_settings_t *invite_settings_parseFromJSON(cJSON *invite_settingsJSON);

cJSON *invite_settings_convertToJSON(invite_settings_t *invite_settings);

#endif /* _invite_settings_H_ */

