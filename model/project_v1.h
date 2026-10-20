/*
 * project_v1.h
 *
 * 
 */

#ifndef _project_v1_H_
#define _project_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct project_v1_t project_v1_t;

#include "network_status_v1.h"
#include "project_quota_v1.h"
#include "project_settings_v1.h"
#include "project_usage_v1.h"



typedef struct project_v1_t {
    char *id; // string
    char *name; // string
    struct project_settings_v1_t *settings; //model
    struct project_quota_v1_t *quotas; //model
    struct project_usage_v1_t *quotas_used; //model
    struct network_status_v1_t *network_status; //model

    int _library_owned; // Is the library responsible for freeing this object?
} project_v1_t;

__attribute__((deprecated)) project_v1_t *project_v1_create(
    char *id,
    char *name,
    project_settings_v1_t *settings,
    project_quota_v1_t *quotas,
    project_usage_v1_t *quotas_used,
    network_status_v1_t *network_status
);

void project_v1_free(project_v1_t *project_v1);

project_v1_t *project_v1_parseFromJSON(cJSON *project_v1JSON);

cJSON *project_v1_convertToJSON(project_v1_t *project_v1);

#endif /* _project_v1_H_ */

