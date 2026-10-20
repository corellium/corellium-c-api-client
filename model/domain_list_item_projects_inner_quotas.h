/*
 * domain_list_item_projects_inner_quotas.h
 *
 * Project quotas.
 */

#ifndef _domain_list_item_projects_inner_quotas_H_
#define _domain_list_item_projects_inner_quotas_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct domain_list_item_projects_inner_quotas_t domain_list_item_projects_inner_quotas_t;




typedef struct domain_list_item_projects_inner_quotas_t {
    double cores; //numeric
    double instances; //numeric
    double ram; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} domain_list_item_projects_inner_quotas_t;

__attribute__((deprecated)) domain_list_item_projects_inner_quotas_t *domain_list_item_projects_inner_quotas_create(
    double cores,
    double instances,
    double ram
);

void domain_list_item_projects_inner_quotas_free(domain_list_item_projects_inner_quotas_t *domain_list_item_projects_inner_quotas);

domain_list_item_projects_inner_quotas_t *domain_list_item_projects_inner_quotas_parseFromJSON(cJSON *domain_list_item_projects_inner_quotasJSON);

cJSON *domain_list_item_projects_inner_quotas_convertToJSON(domain_list_item_projects_inner_quotas_t *domain_list_item_projects_inner_quotas);

#endif /* _domain_list_item_projects_inner_quotas_H_ */

