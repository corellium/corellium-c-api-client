/*
 * patch_project_body.h
 *
 * 
 */

#ifndef _patch_project_body_H_
#define _patch_project_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct patch_project_body_t patch_project_body_t;

#include "patch_project_body_quotas.h"
#include "patch_project_body_settings.h"



typedef struct patch_project_body_t {
    char *name; // string
    struct patch_project_body_settings_t *settings; //model
    struct patch_project_body_quotas_t *quotas; //model

    int _library_owned; // Is the library responsible for freeing this object?
} patch_project_body_t;

__attribute__((deprecated)) patch_project_body_t *patch_project_body_create(
    char *name,
    patch_project_body_settings_t *settings,
    patch_project_body_quotas_t *quotas
);

void patch_project_body_free(patch_project_body_t *patch_project_body);

patch_project_body_t *patch_project_body_parseFromJSON(cJSON *patch_project_bodyJSON);

cJSON *patch_project_body_convertToJSON(patch_project_body_t *patch_project_body);

#endif /* _patch_project_body_H_ */

