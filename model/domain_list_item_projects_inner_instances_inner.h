/*
 * domain_list_item_projects_inner_instances_inner.h
 *
 * 
 */

#ifndef _domain_list_item_projects_inner_instances_inner_H_
#define _domain_list_item_projects_inner_instances_inner_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct domain_list_item_projects_inner_instances_inner_t domain_list_item_projects_inner_instances_inner_t;

#include "domain_list_item_projects_inner_instances_inner_images_inner.h"
#include "domain_list_item_projects_inner_instances_inner_usage.h"



typedef struct domain_list_item_projects_inner_instances_inner_t {
    char *identifier; // string
    char *name; // string
    char *status; // string
    char *error; // string
    char *task_state; // string
    char *user_task; // string
    char *os_version; // string
    char *os_build; // string
    char *flavor_id; // string
    char *flavor; // string
    char *compute_node; // string
    char *service_ip; // string
    char *wifi_ip; // string
    list_t *images; //nonprimitive container
    struct domain_list_item_projects_inner_instances_inner_usage_t *usage; //model

    int _library_owned; // Is the library responsible for freeing this object?
} domain_list_item_projects_inner_instances_inner_t;

__attribute__((deprecated)) domain_list_item_projects_inner_instances_inner_t *domain_list_item_projects_inner_instances_inner_create(
    char *identifier,
    char *name,
    char *status,
    char *error,
    char *task_state,
    char *user_task,
    char *os_version,
    char *os_build,
    char *flavor_id,
    char *flavor,
    char *compute_node,
    char *service_ip,
    char *wifi_ip,
    list_t *images,
    domain_list_item_projects_inner_instances_inner_usage_t *usage
);

void domain_list_item_projects_inner_instances_inner_free(domain_list_item_projects_inner_instances_inner_t *domain_list_item_projects_inner_instances_inner);

domain_list_item_projects_inner_instances_inner_t *domain_list_item_projects_inner_instances_inner_parseFromJSON(cJSON *domain_list_item_projects_inner_instances_innerJSON);

cJSON *domain_list_item_projects_inner_instances_inner_convertToJSON(domain_list_item_projects_inner_instances_inner_t *domain_list_item_projects_inner_instances_inner);

#endif /* _domain_list_item_projects_inner_instances_inner_H_ */

