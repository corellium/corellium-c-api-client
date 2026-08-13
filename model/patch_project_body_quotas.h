/*
 * patch_project_body_quotas.h
 *
 * 
 */

#ifndef _patch_project_body_quotas_H_
#define _patch_project_body_quotas_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct patch_project_body_quotas_t patch_project_body_quotas_t;




typedef struct patch_project_body_quotas_t {
    double cores; //numeric
    double instances; //numeric
    double ram; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} patch_project_body_quotas_t;

__attribute__((deprecated)) patch_project_body_quotas_t *patch_project_body_quotas_create(
    double cores,
    double instances,
    double ram
);

void patch_project_body_quotas_free(patch_project_body_quotas_t *patch_project_body_quotas);

patch_project_body_quotas_t *patch_project_body_quotas_parseFromJSON(cJSON *patch_project_body_quotasJSON);

cJSON *patch_project_body_quotas_convertToJSON(patch_project_body_quotas_t *patch_project_body_quotas);

#endif /* _patch_project_body_quotas_H_ */

