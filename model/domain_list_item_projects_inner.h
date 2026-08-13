/*
 * domain_list_item_projects_inner.h
 *
 * 
 */

#ifndef _domain_list_item_projects_inner_H_
#define _domain_list_item_projects_inner_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct domain_list_item_projects_inner_t domain_list_item_projects_inner_t;

#include "domain_list_item_projects_inner_instances_inner.h"
#include "domain_list_item_projects_inner_instances_inner_images_inner.h"
#include "domain_list_item_projects_inner_quotas.h"
#include "domain_list_item_projects_inner_usage.h"



typedef struct domain_list_item_projects_inner_t {
    char *identifier; // string
    char *name; // string
    struct domain_list_item_projects_inner_quotas_t *quotas; //model
    struct domain_list_item_projects_inner_usage_t *usage; //model
    list_t *instances; //nonprimitive container
    list_t *images; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} domain_list_item_projects_inner_t;

__attribute__((deprecated)) domain_list_item_projects_inner_t *domain_list_item_projects_inner_create(
    char *identifier,
    char *name,
    domain_list_item_projects_inner_quotas_t *quotas,
    domain_list_item_projects_inner_usage_t *usage,
    list_t *instances,
    list_t *images
);

void domain_list_item_projects_inner_free(domain_list_item_projects_inner_t *domain_list_item_projects_inner);

domain_list_item_projects_inner_t *domain_list_item_projects_inner_parseFromJSON(cJSON *domain_list_item_projects_innerJSON);

cJSON *domain_list_item_projects_inner_convertToJSON(domain_list_item_projects_inner_t *domain_list_item_projects_inner);

#endif /* _domain_list_item_projects_inner_H_ */

