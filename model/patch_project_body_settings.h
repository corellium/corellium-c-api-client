/*
 * patch_project_body_settings.h
 *
 * 
 */

#ifndef _patch_project_body_settings_H_
#define _patch_project_body_settings_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct patch_project_body_settings_t patch_project_body_settings_t;




typedef struct patch_project_body_settings_t {
    double version; //numeric
    int internet_access; //boolean
    int dhcp; //boolean
    char *connection; // string

    int _library_owned; // Is the library responsible for freeing this object?
} patch_project_body_settings_t;

__attribute__((deprecated)) patch_project_body_settings_t *patch_project_body_settings_create(
    double version,
    int internet_access,
    int dhcp,
    char *connection
);

void patch_project_body_settings_free(patch_project_body_settings_t *patch_project_body_settings);

patch_project_body_settings_t *patch_project_body_settings_parseFromJSON(cJSON *patch_project_body_settingsJSON);

cJSON *patch_project_body_settings_convertToJSON(patch_project_body_settings_t *patch_project_body_settings);

#endif /* _patch_project_body_settings_H_ */

