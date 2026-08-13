/*
 * create_project_body.h
 *
 * 
 */

#ifndef _create_project_body_H_
#define _create_project_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_project_body_t create_project_body_t;

#include "create_project_body_settings.h"
#include "project_quota_input.h"



typedef struct create_project_body_t {
    char *name; // string
    double color; //numeric
    struct create_project_body_settings_t *settings; //model
    struct project_quota_input_t *quotas; //model

    int _library_owned; // Is the library responsible for freeing this object?
} create_project_body_t;

__attribute__((deprecated)) create_project_body_t *create_project_body_create(
    char *name,
    double color,
    create_project_body_settings_t *settings,
    project_quota_input_t *quotas
);

void create_project_body_free(create_project_body_t *create_project_body);

create_project_body_t *create_project_body_parseFromJSON(cJSON *create_project_bodyJSON);

cJSON *create_project_body_convertToJSON(create_project_body_t *create_project_body);

#endif /* _create_project_body_H_ */

