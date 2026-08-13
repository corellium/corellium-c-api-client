/*
 * domain_list_item_projects_inner_usage.h
 *
 * Project usage.
 */

#ifndef _domain_list_item_projects_inner_usage_H_
#define _domain_list_item_projects_inner_usage_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct domain_list_item_projects_inner_usage_t domain_list_item_projects_inner_usage_t;




typedef struct domain_list_item_projects_inner_usage_t {
    double active_instances; //numeric
    double image_bytes; //numeric
    double cores; //numeric
    double instances; //numeric
    double ram; //numeric
    double gpu; //numeric
    double reserved_cores; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} domain_list_item_projects_inner_usage_t;

__attribute__((deprecated)) domain_list_item_projects_inner_usage_t *domain_list_item_projects_inner_usage_create(
    double active_instances,
    double image_bytes,
    double cores,
    double instances,
    double ram,
    double gpu,
    double reserved_cores
);

void domain_list_item_projects_inner_usage_free(domain_list_item_projects_inner_usage_t *domain_list_item_projects_inner_usage);

domain_list_item_projects_inner_usage_t *domain_list_item_projects_inner_usage_parseFromJSON(cJSON *domain_list_item_projects_inner_usageJSON);

cJSON *domain_list_item_projects_inner_usage_convertToJSON(domain_list_item_projects_inner_usage_t *domain_list_item_projects_inner_usage);

#endif /* _domain_list_item_projects_inner_usage_H_ */

