/*
 * trial_request_detail_organization.h
 *
 * Organization info.
 */

#ifndef _trial_request_detail_organization_H_
#define _trial_request_detail_organization_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct trial_request_detail_organization_t trial_request_detail_organization_t;




typedef struct trial_request_detail_organization_t {
    char *name; // string
    char *country; // string

    int _library_owned; // Is the library responsible for freeing this object?
} trial_request_detail_organization_t;

__attribute__((deprecated)) trial_request_detail_organization_t *trial_request_detail_organization_create(
    char *name,
    char *country
);

void trial_request_detail_organization_free(trial_request_detail_organization_t *trial_request_detail_organization);

trial_request_detail_organization_t *trial_request_detail_organization_parseFromJSON(cJSON *trial_request_detail_organizationJSON);

cJSON *trial_request_detail_organization_convertToJSON(trial_request_detail_organization_t *trial_request_detail_organization);

#endif /* _trial_request_detail_organization_H_ */

