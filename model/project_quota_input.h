/*
 * project_quota_input.h
 *
 * Initial resource quotas. When omitted the project is created with ZERO quota and cannot run instances until an administrator allocates quota to it (quotas are reservations against the domain allowance; rebalance from another project if the allowance is fully reserved).
 */

#ifndef _project_quota_input_H_
#define _project_quota_input_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct project_quota_input_t project_quota_input_t;




typedef struct project_quota_input_t {
    double cores; //numeric
    double instances; //numeric
    double ram; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} project_quota_input_t;

__attribute__((deprecated)) project_quota_input_t *project_quota_input_create(
    double cores,
    double instances,
    double ram
);

void project_quota_input_free(project_quota_input_t *project_quota_input);

project_quota_input_t *project_quota_input_parseFromJSON(cJSON *project_quota_inputJSON);

cJSON *project_quota_input_convertToJSON(project_quota_input_t *project_quota_input);

#endif /* _project_quota_input_H_ */

