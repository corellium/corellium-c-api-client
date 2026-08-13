/*
 * project_list_item.h
 *
 * 
 */

#ifndef _project_list_item_H_
#define _project_list_item_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct project_list_item_t project_list_item_t;

#include "network_status.h"
#include "project_config.h"
#include "project_quota.h"
#include "project_settings.h"
#include "project_usage.h"



typedef struct project_list_item_t {
    char *id; // string
    char *name; // string
    struct project_settings_t *settings; //model
    struct project_quota_t *quotas; //model
    struct project_usage_t *quotas_used; //model
    struct network_status_t *network_status; //model
    struct project_config_t *config; //model
    double key_count; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} project_list_item_t;

__attribute__((deprecated)) project_list_item_t *project_list_item_create(
    char *id,
    char *name,
    project_settings_t *settings,
    project_quota_t *quotas,
    project_usage_t *quotas_used,
    network_status_t *network_status,
    project_config_t *config,
    double key_count
);

void project_list_item_free(project_list_item_t *project_list_item);

project_list_item_t *project_list_item_parseFromJSON(cJSON *project_list_itemJSON);

cJSON *project_list_item_convertToJSON(project_list_item_t *project_list_item);

#endif /* _project_list_item_H_ */

