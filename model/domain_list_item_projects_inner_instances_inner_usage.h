/*
 * domain_list_item_projects_inner_instances_inner_usage.h
 *
 * Instance usage.
 */

#ifndef _domain_list_item_projects_inner_instances_inner_usage_H_
#define _domain_list_item_projects_inner_instances_inner_usage_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct domain_list_item_projects_inner_instances_inner_usage_t domain_list_item_projects_inner_instances_inner_usage_t;




typedef struct domain_list_item_projects_inner_instances_inner_usage_t {
    double image_bytes; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} domain_list_item_projects_inner_instances_inner_usage_t;

__attribute__((deprecated)) domain_list_item_projects_inner_instances_inner_usage_t *domain_list_item_projects_inner_instances_inner_usage_create(
    double image_bytes
);

void domain_list_item_projects_inner_instances_inner_usage_free(domain_list_item_projects_inner_instances_inner_usage_t *domain_list_item_projects_inner_instances_inner_usage);

domain_list_item_projects_inner_instances_inner_usage_t *domain_list_item_projects_inner_instances_inner_usage_parseFromJSON(cJSON *domain_list_item_projects_inner_instances_inner_usageJSON);

cJSON *domain_list_item_projects_inner_instances_inner_usage_convertToJSON(domain_list_item_projects_inner_instances_inner_usage_t *domain_list_item_projects_inner_instances_inner_usage);

#endif /* _domain_list_item_projects_inner_instances_inner_usage_H_ */

