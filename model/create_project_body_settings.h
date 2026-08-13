/*
 * create_project_body_settings.h
 *
 * 
 */

#ifndef _create_project_body_settings_H_
#define _create_project_body_settings_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_project_body_settings_t create_project_body_settings_t;




typedef struct create_project_body_settings_t {
    double version; //numeric
    int internet_access; //boolean
    int dhcp; //boolean
    char *connection; // string

    int _library_owned; // Is the library responsible for freeing this object?
} create_project_body_settings_t;

__attribute__((deprecated)) create_project_body_settings_t *create_project_body_settings_create(
    double version,
    int internet_access,
    int dhcp,
    char *connection
);

void create_project_body_settings_free(create_project_body_settings_t *create_project_body_settings);

create_project_body_settings_t *create_project_body_settings_parseFromJSON(cJSON *create_project_body_settingsJSON);

cJSON *create_project_body_settings_convertToJSON(create_project_body_settings_t *create_project_body_settings);

#endif /* _create_project_body_settings_H_ */

